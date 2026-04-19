
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

#include "src/common.h"
#include "timer.h"

void timers_init(void)
{
    // Timer A -- PWM

    // Timer clock input for ACLK, divider
    pac5xxx_timer_clock_config(TimerA, TXCTL_CS_ACLK, TXCTL_PS_DIV);       
    // Timer frequency and count mode            
    pac5xxx_timer_base_config(TimerA, (TIMER_FREQ_HZ/(2*PWM_FREQ_HZ)), AUTO_RELOAD,
            TxCTL_MODE_UPDOWN, TIMER_SLAVE_SYNC_DISABLE);                               

    // Configure Dead time generators
    // 0--> The DTGCLK is the clock before the TACTL.CLKDIV clock divider.
    // 1--> The DTGCLK is the clock after the TACTL.CLKDIV clock divider.
    PAC55XX_TIMERA->CTL.DTGCLK = BEFORE_ACLK_DIVIDER;                                   
                                                                                        
    // Configure DTGA0, 1, 2 for phase U, V, W
    pac5xxx_dtg_config2(&(PAC55XX_TIMERA->DTGCTL0), RED_DEATH_TIMET, FED_DEATH_TIMET);  
    pac5xxx_dtg_config2(&(PAC55XX_TIMERA->DTGCTL1), RED_DEATH_TIMET, FED_DEATH_TIMET); 
    pac5xxx_dtg_config2(&(PAC55XX_TIMERA->DTGCTL2), RED_DEATH_TIMET, FED_DEATH_TIMET);

    PAC55XX_TIMERA->CCTR4.CTR = 0;
    PAC55XX_TIMERA->CCTR5.CTR = 0;
    PAC55XX_TIMERA->CCTR6.CTR = 0;

}
