/*
 * This file is part of the Tinymovr-Firmware distribution
 * (https://github.com/yconst/tinymovr-firmware).
 * Copyright (c) 2020-2023 Ioannis Chatzikonstantinou.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <string.h>
#include <stdlib.h>
#include "src/can/can_endpoints.h"
#include "src/can/avlos_endpoint_metadata.h"
#include "src/tm_enums.h"
#include "src/uart/uart_lowlevel.h"
#include "src/uart/uart_interface.h"

static void uart_send_line(const char *str)
{
    size_t i = 0;
    while (i < (size_t)(UART_BYTE_LIMIT - 1) && str[i] != '\0')
    {
        uart_tx_msg[i] = (char)str[i];
        i++;
    }
    uart_tx_msg[i] = (char)UART_LINEFEED;
    if (i + 1 < (size_t)UART_BYTE_LIMIT)
    {
        uart_tx_msg[i + 1] = '\0';
    }
    pac5xxx_uart_int_enable_THREI2(UART_REF, 1);
}

/* Parse one token from *p (space or \0 terminated); advance *p past token. Return 0 on parse error. */
static int parse_token_float(const char **p, float *out)
{
    const char *s = *p;
    const char *start = s;
    float sign = 1.0f;
    if (*s == '-')
    {
        sign = -1.0f;
        s++;
    }
    else if (*s == '+')
    {
        s++;
    }
    unsigned long int_part = 0;
    while (*s >= '0' && *s <= '9')
    {
        int_part = int_part * 10u + (unsigned long)(*s - '0');
        s++;
    }
    float v = (float)int_part;
    if (*s == '.' || *s == ',')
    {
        s++;
        float frac = 0.1f;
        while (*s >= '0' && *s <= '9')
        {
            v += frac * (float)(*s - '0');
            frac *= 0.1f;
            s++;
        }
    }
    *p = s;
    *out = v * sign;
    return (s > start);
}

static int parse_token_uint32(const char **p, uint32_t *out)
{
    char *end;
    unsigned long v = strtoul(*p, &end, 10);
    if (end == *p || v > 0xFFFFFFFFUL)
    {
        return 0;
    }
    *p = end;
    *out = (uint32_t)v;
    return 1;
}

static int parse_token_int32(const char **p, int32_t *out)
{
    char *end;
    long v = strtol(*p, &end, 10);
    if (end == *p)
    {
        return 0;
    }
    *p = end;
    *out = (int32_t)v;
    return 1;
}

static int parse_token_uint8(const char **p, uint8_t *out)
{
    uint32_t v;
    if (!parse_token_uint32(p, &v) || v > 0xFF)
    {
        return 0;
    }
    *out = (uint8_t)v;
    return 1;
}

static int parse_token_bool(const char **p, uint8_t *out)
{
    while (**p == ' ' || **p == '\t')
    {
        (*p)++;
    }
    if (**p == '1' || (**p == 't' && (*p)[1] == 'r' && (*p)[2] == 'u' && (*p)[3] == 'e'))
    {
        *out = 1;
        if ((*p)[0] == 't')
        {
            *p += 4;
        }
        else
        {
            (*p)++;
        }
        return 1;
    }
    if (**p == '0' || (**p == 'f' && (*p)[1] == 'a' && (*p)[2] == 'l' && (*p)[3] == 's' && (*p)[4] == 'e'))
    {
        *out = 0;
        if ((*p)[0] == 'f')
        {
            *p += 5;
        }
        else
        {
            (*p)++;
        }
        return 1;
    }
    return 0;
}

/* Fill buf from tokens according to meta; return 0 on error. */
static int uart_parse_args_into_buf(const char **p, uint8_t *buf, const Avlos_EndpointMeta *meta)
{
    uint8_t offset = 0;
    for (uint8_t i = 0; i < meta->num_args && offset < 8; i++)
    {
        switch (meta->arg_dtypes[i])
        {
        case AVLOS_DTYPE_FLOAT:
        {
            float v;
            if (!parse_token_float(p, &v))
            {
                return 0;
            }
            memcpy(buf + offset, &v, sizeof(float));
            offset += sizeof(float);
            break;
        }
        case AVLOS_DTYPE_UINT8:
        {
            uint8_t v;
            if (!parse_token_uint8(p, &v))
            {
                return 0;
            }
            buf[offset++] = v;
            break;
        }
        case AVLOS_DTYPE_UINT32:
        {
            uint32_t v;
            if (!parse_token_uint32(p, &v))
            {
                return 0;
            }
            memcpy(buf + offset, &v, sizeof(uint32_t));
            offset += sizeof(uint32_t);
            break;
        }
        case AVLOS_DTYPE_INT32:
        {
            int32_t v;
            if (!parse_token_int32(p, &v))
            {
                return 0;
            }
            memcpy(buf + offset, &v, sizeof(int32_t));
            offset += sizeof(int32_t);
            break;
        }
        case AVLOS_DTYPE_BOOL:
        {
            uint8_t v;
            if (!parse_token_bool(p, &v))
            {
                return 0;
            }
            buf[offset++] = v;
            break;
        }
        default:
            return 0;
        }
    }
    return 1;
}

/* For single-value SET: parse one token into buf by value_dtype. */
static int uart_parse_value_into_buf(const char **p, uint8_t *buf, Avlos_Dtype dtype)
{
    switch (dtype)
    {
    case AVLOS_DTYPE_FLOAT:
    {
        float v;
        return parse_token_float(p, &v) ? (memcpy(buf, &v, sizeof(float)), 1) : 0;
    }
    case AVLOS_DTYPE_UINT8:
    {
        uint8_t v;
        return parse_token_uint8(p, &v) ? (buf[0] = v, 1) : 0;
    }
    case AVLOS_DTYPE_UINT32:
    {
        uint32_t v;
        return parse_token_uint32(p, &v) ? (memcpy(buf, &v, sizeof(uint32_t)), 1) : 0;
    }
    case AVLOS_DTYPE_INT32:
    {
        int32_t v;
        return parse_token_int32(p, &v) ? (memcpy(buf, &v, sizeof(int32_t)), 1) : 0;
    }
    case AVLOS_DTYPE_BOOL:
    {
        uint8_t v;
        return parse_token_bool(p, &v) ? (buf[0] = v, 1) : 0;
    }
    default:
        return 0;
    }
}

/* Append unsigned decimal to line at *i; ensure room in max. */
static void append_uint32(char *line, size_t max, size_t *i, uint32_t v)
{
    char tmp[12];
    size_t n = 0;
    if (v == 0)
    {
        tmp[n++] = '0';
    }
    else
    {
        while (v > 0 && n < sizeof(tmp) - 1)
        {
            tmp[n++] = (char)('0' + (v % 10));
            v /= 10;
        }
    }
    while (n > 0 && *i < max - 1)
    {
        line[(*i)++] = tmp[--n];
    }
}

/* Append int32 to line. */
static void append_int32(char *line, size_t max, size_t *i, int32_t v)
{
    if (v < 0)
    {
        if (*i < max - 1)
        {
            line[(*i)++] = '-';
        }
        append_uint32(line, max, i, (uint32_t)(-(int64_t)v));
    }
    else
    {
        append_uint32(line, max, i, (uint32_t)v);
    }
}

/* Append float to line (simple form: integer part and 6 decimal places). */
static void append_float(char *line, size_t max, size_t *i, float v)
{
    if (v < 0.0f)
    {
        if (*i < max - 1)
        {
            line[(*i)++] = '-';
        }
        v = -v;
    }
    int32_t ip = (int32_t)v;
    append_int32(line, max, i, ip);
    if (*i < max - 1)
    {
        line[(*i)++] = '.';
    }
    float frac = v - (float)ip;
    for (int d = 0; d < 6 && *i < max - 1; d++)
    {
        frac *= 10.0f;
        int digit = (int)frac;
        if (digit > 9)
        {
            digit = 9;
        }
        line[(*i)++] = (char)('0' + digit);
        frac -= (float)digit;
    }
}

/* Format buffer to ASCII by dtype/len and send. */
static void uart_format_and_send(uint8_t *buf, uint8_t len, Avlos_Dtype dtype)
{
    char line[UART_BYTE_LIMIT];
    size_t idx = 0;
    switch (dtype)
    {
    case AVLOS_DTYPE_UINT8:
        append_uint32(line, sizeof(line), &idx, len >= 1 ? buf[0] : 0);
        break;
    case AVLOS_DTYPE_UINT32:
    {
        uint32_t v = 0;
        if (len >= sizeof(uint32_t))
        {
            memcpy(&v, buf, sizeof(uint32_t));
        }
        append_uint32(line, sizeof(line), &idx, v);
        break;
    }
    case AVLOS_DTYPE_INT32:
    {
        int32_t v = 0;
        if (len >= sizeof(int32_t))
        {
            memcpy(&v, buf, sizeof(int32_t));
        }
        append_int32(line, sizeof(line), &idx, v);
        break;
    }
    case AVLOS_DTYPE_FLOAT:
    {
        float v = 0.0f;
        if (len >= sizeof(float))
        {
            memcpy(&v, buf, sizeof(float));
        }
        append_float(line, sizeof(line), &idx, v);
        break;
    }
    case AVLOS_DTYPE_BOOL:
        if (len >= 1 && buf[0])
        {
            const char *t = "true";
            while (*t && idx < sizeof(line) - 1)
            {
                line[idx++] = *t++;
            }
        }
        else
        {
            const char *f = "false";
            while (*f && idx < sizeof(line) - 1)
            {
                line[idx++] = *f++;
            }
        }
        break;
    case AVLOS_DTYPE_STRING:
        if (len > 0 && len < UART_BYTE_LIMIT - 2)
        {
            memcpy(line, buf, len);
            idx = len;
        }
        break;
    default:
        append_uint32(line, sizeof(line), &idx, 0);
        break;
    }
    line[idx] = '\0';
    uart_send_line(line);
}

void UART_process_message(void)
{
    uint8_t buf[8];
    uint8_t buf_len = 0;
    const char *p;
    unsigned long ep_id_u;
    char *end;

    if (uart_rx_msg_len < 2)
    {
        uart_send_line("error: bad format");
        return;
    }
    uart_rx_msg[uart_rx_msg_len] = '\0';

    if (uart_rx_msg[0] != (char)UART_ASCII_PROT_START_BYTE)
    {
        return;
    }

    p = &uart_rx_msg[1];
    while (*p == ' ' || *p == '\t')
    {
        p++;
    }
    ep_id_u = strtoul(p, &end, 10);
    if (end == p || ep_id_u >= avlos_endpoint_meta_count)
    {
        uart_send_line("error: invalid endpoint");
        return;
    }
    p = end;

    uint32_t ep_id = (uint32_t)ep_id_u;
    const Avlos_EndpointMeta *meta = &avlos_endpoint_meta[ep_id];

    Avlos_Command cmd = AVLOS_CMD_READ;
    memset(buf, 0, sizeof(buf));

    while (*p == ' ' || *p == '\t')
    {
        p++;
    }

    if (*p != '\0' && *p != '\r' && *p != '\n')
    {
        cmd = AVLOS_CMD_WRITE;
        if (meta->kind == AVLOS_EP_KIND_CALL_WITH_ARGS)
        {
            if (!uart_parse_args_into_buf(&p, buf, meta))
            {
                uart_send_line("error: bad value");
                return;
            }
            buf_len = 8;
        }
        else if (meta->kind == AVLOS_EP_KIND_READ_WRITE || meta->kind == AVLOS_EP_KIND_WRITE_ONLY)
        {
            if (!uart_parse_value_into_buf(&p, buf, meta->value_dtype))
            {
                uart_send_line("error: bad value");
                return;
            }
            if (meta->value_dtype == AVLOS_DTYPE_FLOAT || meta->value_dtype == AVLOS_DTYPE_UINT32 ||
                meta->value_dtype == AVLOS_DTYPE_INT32)
            {
                buf_len = 4;
            }
            else
            {
                buf_len = 1;
            }
        }
        else
        {
            uart_send_line("error: endpoint not writable");
            return;
        }
    }

    uint8_t (*callback)(uint8_t *, uint8_t *, Avlos_Command) = avlos_endpoints[ep_id];
    uint8_t ret = callback(buf, &buf_len, cmd);

    if (ret == AVLOS_RET_READ || ret == AVLOS_RET_CALL)
    {
        if (buf_len > 0)
        {
            uart_format_and_send(buf, buf_len, meta->value_dtype);
        }
        else
        {
            uart_send_line("ok");
        }
    }
    else if (ret == AVLOS_RET_WRITE || ret == AVLOS_RET_NOACTION)
    {
        uart_send_line("ok");
    }
    else
    {
        uart_send_line("ok");
    }
}
