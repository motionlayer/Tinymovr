
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

#include "src/watchdog/watchdog.h"
#include "src/common.h"

static TimeoutWatchdog watchdog = {
    .triggered = false
};


void Watchdog_init(void)
{
    // Allow WWDT config editing
    PAC55XX_WWDT->WWDTLOCK = WWDTLOCK_REGS_WRITE_AVALABLE;

    // Set the clock divider
    PAC55XX_WWDT->WWDTCTL.CLKDIV = WWDT_CLKDIV_DIV32768;
    // Select FRCLK
    PAC55XX_WWDT->WWDTCTL.CLKSEL = WWDTCTL_CLKSEL_FRCLK;

    // Enable interrupt but not reset ("interval mode")
    PAC55XX_WWDT->WWDTCTL.INTEN = 1;
    PAC55XX_WWDT->WWDTCDCTL.WINDOW = 0;

    // Set WWDT interrupt priority
    NVIC_SetPriority(Wdt_IRQn, 4);

    // Set initial 1s timeout
    Watchdog_set_timeout_cycles(wwdt_freq);
}

TM_RAMFUNC bool Watchdog_triggered(void)
{
    return watchdog.triggered;
}

TM_RAMFUNC void Watchdog_reset(void)
{
    watchdog.triggered = false;
    PAC55XX_WWDT->WWDTLOCK = WWDTLOCK_REGS_WRITE_AVALABLE;
    // Clear the counter
    PAC55XX_WWDT->WWDTCLEAR = 1;

}

uint16_t Watchdog_get_timeout_cycles(void)
{
    return PAC55XX_WWDT->WWDTCDCTL.CDV;
}

float Watchdog_get_timeout_seconds(void)
{
    return ((float)(PAC55XX_WWDT->WWDTCDCTL.CDV)) / wwdt_freq;
}


void Watchdog_set_timeout_cycles(uint16_t cycles)
{
    PAC55XX_WWDT->WWDTLOCK = WWDTLOCK_REGS_WRITE_AVALABLE;
    // Set the counter start value
    PAC55XX_WWDT->WWDTCDCTL.CDV = cycles;
}

void Watchdog_set_timeout_seconds(float seconds)
{
    uint16_t cycles;
    // If the timeout requested is greater than the maximum possible, cap it to the maximum instead of overflowing
    if (seconds > max_watchdog_seconds)
    {
        cycles = 0xFFFF;
    }
    else
    {
        cycles = (uint16_t)(seconds * wwdt_freq);
    }
    Watchdog_set_timeout_cycles(cycles);
}

bool Watchdog_get_enabled(void)
{
    return (bool)(PAC55XX_WWDT->WWDTCTL.EN);
}

void Watchdog_set_enabled(bool enabled)
{
    PAC55XX_WWDT->WWDTLOCK = WWDTLOCK_REGS_WRITE_AVALABLE;
    if (enabled)
    {
         watchdog.triggered = false;
        // The WWDTCTR is automatically reset on enabling
        PAC55XX_WWDT->WWDTCTL.EN = 1;
        // Enable WWDT interrupt in the NVIC
        NVIC_EnableIRQ(Wdt_IRQn);
    }
    else
    {
        PAC55XX_WWDT->WWDTCTL.EN = 0;
        // Disable WWDT interrupt in the NVIC - crashes without this
        NVIC_DisableIRQ(Wdt_IRQn);
    }    
}

void WWDT_process_interrupt(void)
{
    watchdog.triggered = true;
}