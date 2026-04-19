
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

#include <src/common.h>

void gate_driver_enable(void);
void gate_driver_disable(void);

typedef struct {
    bool enabled;
} GateDriverState;

extern GateDriverState gate_driver_state;

static inline void m1_u_set_duty(const float duty)
{
    uint16_t val = ((uint16_t)(duty * (TIMER_FREQ_HZ/PWM_FREQ_HZ) )) >>1;
    PAC55XX_TIMERA->CCTR4.CTR = val;
}

static inline void m1_v_set_duty(const float duty)
{
    uint16_t val = ((uint16_t)(duty * (TIMER_FREQ_HZ/PWM_FREQ_HZ) )) >>1;
    PAC55XX_TIMERA->CCTR5.CTR = val;
}

static inline void m1_w_set_duty(const float duty)
{
    uint16_t val = ((uint16_t)(duty * (TIMER_FREQ_HZ/PWM_FREQ_HZ) )) >>1;
    PAC55XX_TIMERA->CCTR6.CTR = val;
}

static inline void gate_driver_set_duty_cycle(const FloatTriplet *dutycycles)
{
	m1_u_set_duty(dutycycles->A);
	m1_v_set_duty(dutycycles->B);
	m1_w_set_duty(dutycycles->C);
}

static inline bool gate_driver_is_enabled(void)
{
    return gate_driver_state.enabled;
}
