
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

#ifndef SYSTEM_SYSTEM_H_
#define SYSTEM_SYSTEM_H_

#include <string.h>
#include <src/common.h>
#define CLKREF_FREQ_HZ              (4000000)
#define FRCLK_FREQ_HZ               CLKREF_FREQ_HZ

typedef struct {
    float Vbus;
    uint8_t errors;
} SystemState;

typedef struct {
    float Vbus_tau;
    float Vbus_D;
} SystemConfig;

void system_init(void);
void system_update(void);
void system_reset(void);
void system_enter_dfu(void);
void system_reset_calibration(void);

extern const uint32_t config_size;

static inline uint8_t system_get_fw_version_string(char *buffer)
{
    const uint8_t size = fminf(sizeof(GIT_VERSION), 8);
    memcpy(buffer, GIT_VERSION, size);
    return size;
}

static inline uint32_t system_get_uid(void)
{
    return PAC55XX_INFO1->UNIQUEID[0] ^ PAC55XX_INFO1->UNIQUEID[1] ^ PAC55XX_INFO1->UNIQUEID[2];
}

static inline uint32_t system_get_hw_revision(void)
{
    return BOARD_REV_IDX;
}

static inline uint32_t system_get_config_size(void)
{
    return config_size;
}

void system_reset_calibration(void);
float system_get_Vbus(void);
bool system_get_calibrated(void);
uint8_t system_get_errors(void);
uint8_t system_get_warnings(void);
bool errors_exist(void);

#endif /* SYSTEM_SYSTEM_H_ */
