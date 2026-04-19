
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
#include "src/system/system.h"
#include "src/uart/uart_lowlevel.h"
#include <src/sensor/sensor.h>
#include "src/observer/observer.h"
#include "src/adc/adc.h"
#include "src/motor/motor.h"
#include "src/controller/controller.h"
#include "src/gatedriver/gatedriver.h"
#include "src/timer/timer.h"
#include "src/can/can.h"
#include "src/nvm/nvm.h"
#include "src/watchdog/watchdog.h"

int main(void)
{
  	__disable_irq();
    system_init();
    UART_Init(); // Keep UART init before config load for now
    if (!nvm_load_config())
    {
        sensors_init_with_defaults();
        observers_init_with_defaults();
    }
    ADC_init();
    CAN_init();
    timers_init();
    Watchdog_init();
    __enable_irq();

    Controller_ControlLoop();
}

