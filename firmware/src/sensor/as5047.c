
// Copyright 2020-2026 MotionLayer P.C.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <string.h>
#include <src/system/system.h>
#include <src/utils/utils.h>
#include <src/can/can_endpoints.h>
#include <src/sensor/sensor.h>
#include <src/sensor/as5047.h>

void as5047p_make_blank_sensor(Sensor *s)
{
    AS5047PSensor *as = (AS5047PSensor *)s;
    as->config.rate = SENSORS_SETUP_EXTERNAL_SPI_RATE_3Mbps;
    s->config.type = SENSOR_TYPE_AS5047;
    s->bits = AS5047_BITS;
    s->ticks = AS5047_TICKS;
    s->normalization_factor = SENSOR_COMMON_RES_TICKS_FLOAT / s->ticks;
    s->get_raw_angle_func = as5047p_get_raw_angle;
    s->update_func = as5047p_update; 
    s->prepare_func = as5047p_send_angle_cmd; 
    s->reset_func = as5047p_reset;
    s->init_func = as5047p_init; 
    s->deinit_func = as5047p_deinit; 
    s->get_errors_func = as5047p_get_errors; 
    s->is_calibrated_func = as5047p_is_calibrated; 
    s->get_ss_config_func = as5047p_get_ss_config;
}

bool as5047p_init_with_port_and_rate(Sensor *s, const SSP_TYPE port, PAC55XX_SSP_TYPEDEF *ssp_struct, sensors_setup_external_spi_rate_options rate)
{
    AS5047PSensorConfig c = {0};
    c.ssp_port = port;
    c.ssp_struct = ssp_struct;
    c.rate = rate;
    return as5047p_init_with_config(s, &c);
}

bool as5047p_init_with_config(Sensor *s, const AS5047PSensorConfig *c)
{
    AS5047PSensor *as = (AS5047PSensor *)s;
    as->config = *c;
    return as5047p_init(s);
}

bool as5047p_init(Sensor *s)
{
    AS5047PSensor *as = (AS5047PSensor *)s;
    ssp_init(as->config.ssp_port, SSP_MS_MASTER, 16, SSP_DATA_SIZE_16, SWSEL_SPI, 1, 0);
    delay_us(10000); // Example delay, adjust based on AS5047P datasheet

    as5047p_send_angle_cmd(s); 
    as5047p_update(s, false); 
    s->initialized = true;
    return true;
}

void as5047p_deinit(Sensor *s)
{
    ssp_deinit(((AS5047PSensor *)s)->config.ssp_port);
    s->initialized = false;
}

void as5047p_reset(Sensor *s)
{
    sensor_reset(s);
}

void as5047p_get_ss_config(Sensor *s, void* buffer)
{
    const AS5047PSensor *ss = ((const AS5047PSensor *)s);
    memcpy(buffer, &(ss->config), sizeof(ss->config));
}