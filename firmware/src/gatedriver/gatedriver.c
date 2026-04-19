
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

#include <src/motor/motor.h>
#include <src/gatedriver/gatedriver.h>

GateDriverState gate_driver_state = {0};

TM_RAMFUNC void gate_driver_enable(void)
{
    // Select PWMA peripheral for Port B
    PAC55XX_SCC->PBMUXSEL.w =  0x01110111;

    // Select GPIO mode for Port B
    PAC55XX_GPIOB->MODE.w = 0x1515;

    // Turn on output enables
    PAC55XX_GPIOB->OUTMASK.w = 0x00;

    // Set slew rate
    // 01000101: push: 750mA pull: 750mA
    pac5xxx_tile_register_write(ADDR_DRVILIMLS, 0x45);
    pac5xxx_tile_register_write(ADDR_DRVILIMHS, 0x45);

    // Enable driver manager and verify active - need to enable even in PAC5210 to get ENHS pin to work
    pac5xxx_tile_register_write(ADDR_ENDRV, 1);

    pac5xxx_tile_register_write(ADDR_CFGDRV4,
            pac5xxx_tile_register_read(ADDR_CFGDRV4) | 0x1); // BBM is bit 0

    gate_driver_state.enabled = ((pac5xxx_tile_register_read(ADDR_ENDRV) & 0x1) == 1);
}

TM_RAMFUNC void gate_driver_disable(void)
{
    // Disable driver manager and verify active - need to enable even in PAC5210 to get ENHS pin to work
    pac5xxx_tile_register_write(ADDR_ENDRV, 0);

    // Set IO state of all pins to 0
    PAC55XX_GPIOB->OUT.w = 0x00;

    // Select GPIO peripheral for Port B
    PAC55XX_SCC->PBMUXSEL.w =  0x00000000;

    // Select GPIO mode for Port B
    PAC55XX_GPIOB->MODE.w = 0x1515;

    // Turn on output enables
    PAC55XX_GPIOB->OUTMASK.w = 0x00;

    gate_driver_state.enabled = ((pac5xxx_tile_register_read(ADDR_ENDRV) & 0x1) == 1);
}

