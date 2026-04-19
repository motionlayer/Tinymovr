
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

#pragma once

#define RED_DEATH_TIMET                 250         //Set rising edge death-time, if TACTL.DTGCLK is 0b, 50--> 1us
#define FED_DEATH_TIMET                 250         //Set failling edge death-time, if TACTL.DTGCLK is 0b, 50--> 1us

typedef enum
{
    BEFORE_ACLK_DIVIDER                 = 0,        // The DTGCLK is the clock before the TACTL.CLKDIV clock divider
    AFTER_ACLK_DIVIDER                  = 1,        // The DTGCLK is the clock after the TACTL.CLKDIV clock divider
}TXCTL_DTCLK_Type;

typedef enum
{
    TIMER_SLAVE_SYNC_DISABLE            = 0,        // The timer auto reload
    TIMER_SLAVE_SYNC_ENABLE             = 1,        // The timer single shot
}TXCTL_SSYNC_Type;

typedef enum
{
    AUTO_RELOAD                         = 0,        // The timer auto reload
    SINGLE_SHOT                         = 1,        // The timer single shot
}TXCTL_SINGLE_Type;

void timers_init(void);
