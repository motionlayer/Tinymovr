
// Copyright (c) 2022 Eugene Frizza
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

/*
The watchdog is used as a timer for inactivity on the CAN bus.
When it times out, it sets the control state back to idle as a failsafe if the ESC becomes disconnected.
It can be enabled/disabled via the set_watchdog can endpoint.
Timing works via the PAC55 Watchdog timer (WWDT)
*/

#pragma once

#include "src/system/system.h"

// 4MHz CLKREF >>> FRCLK (set in system.h) >>> /32768 WWDT = 122.07 Hz
// 2^16 / 122.07 = 536.87s maximum
#define WWDT_CLKDIV 32768
static const float wwdt_freq = FRCLK_FREQ_HZ / WWDT_CLKDIV;
static const float max_watchdog_seconds = 0xFFFF * WWDT_CLKDIV / FRCLK_FREQ_HZ;

typedef struct
{
    bool triggered;
} TimeoutWatchdog;

void Watchdog_init(void);
void Watchdog_reset(void);
bool Watchdog_triggered(void);
uint16_t Watchdog_get_timeout_cycles(void);
float Watchdog_get_timeout_seconds(void);
void Watchdog_set_timeout_cycles(uint16_t cycles);
void Watchdog_set_timeout_seconds(float s);

bool Watchdog_get_enabled(void);
void Watchdog_set_enabled(bool enabled);
void WWDT_process_interrupt(void);