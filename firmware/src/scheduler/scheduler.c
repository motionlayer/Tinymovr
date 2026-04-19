
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

#include <src/common.h>
#include <src/system/system.h>
#include <src/gatedriver/gatedriver.h>
#include <src/adc/adc.h>
#include <src/can/can.h>
#include <src/uart/uart_interface.h>
#include <src/uart/uart_lowlevel.h>
#include <src/sensor/sensor.h>
#include <src/sensor/ma7xx.h>
#include <src/observer/observer.h>
#include <src/can/can_endpoints.h>
#include <src/scheduler/scheduler.h>
#include <src/watchdog/watchdog.h>

volatile uint32_t msTicks = 0;

volatile SchedulerState scheduler_state = {0};

TM_RAMFUNC __attribute__((noinline)) static void control_loop_service(void)
{
	sensor_invalidate(commutation_sensor_p);
	sensor_invalidate(position_sensor_p);
	observer_invalidate(&commutation_observer);
	observer_invalidate(&position_observer);
	sensor_prepare(commutation_sensor_p);
	sensor_prepare(position_sensor_p);
	ADC_update();
	sensor_update(commutation_sensor_p, true);
	sensor_update(position_sensor_p, true);
	observer_update(&commutation_observer);
	observer_update(&position_observer);
}

void wait_for_control_loop_interrupt(void)
{
	while (!scheduler_state.adc_interrupt)
	{
		
		if (scheduler_state.can_interrupt)
		{
			// Handle CAN
			CAN_process_interrupt();
			// Only clear the flag if all messages in the CAN RX buffer have been processed
			if (PAC55XX_CAN->SR.RBS == 0)
			{
				scheduler_state.can_interrupt = false;
			}
		}
		else if (scheduler_state.uart_message_interrupt)
		{
			// Handle UART
			scheduler_state.uart_message_interrupt = false;
			UART_process_message();
		}
		else if (scheduler_state.wwdt_interrupt)
		{
			scheduler_state.wwdt_interrupt = false;
			WWDT_process_interrupt();
		}
		else
		{
			scheduler_state.busy = false;
			scheduler_state.load = DWT->CYCCNT;
			// Go back to sleep
			__DSB();
			__ISB();
			__WFI();
		}
	}
	scheduler_state.busy = true;
	scheduler_state.adc_interrupt = false;
	DWT->CYCCNT = 0;
	control_loop_service();
	// At this point control is returned to main loop.
}

void wait_for_control_loop_interrupt_cal(void)
{
	while (!scheduler_state.adc_interrupt)
	{
		if (scheduler_state.can_interrupt)
		{
			CAN_process_interrupt();
			if (PAC55XX_CAN->SR.RBS == 0)
			{
				scheduler_state.can_interrupt = false;
			}
		}
		else
		{
			__DSB();
			__ISB();
			__WFI();
		}
	}
	scheduler_state.adc_interrupt = false;
	ADC_update();
}

void ADC_IRQHandler(void)
{
	PAC55XX_ADC->ADCINT.ADCIRQ0IF = 1;
	scheduler_state.adc_interrupt = true;
	// Only in case the gate driver is enabled, raise a
	// warning if the control loop is about to be
	// reentered
	if (gate_driver_is_enabled() && scheduler_state.busy)
	{
		scheduler_state.warnings |= SCHEDULER_WARNINGS_CONTROL_BLOCK_REENTERED;
	}
}

void CAN_IRQHandler(void)
{
	pac5xxx_can_int_clear_RI();
	scheduler_state.can_interrupt = true;
}

void SysTick_Handler(void)
{                               
    msTicks = msTicks + 1; 
    CAN_update();
	system_update();
	ADC_update_temp();
}

void UART_ReceiveMessageHandler(void)
{
	scheduler_state.uart_message_interrupt = true;
}

void Wdt_IRQHandler(void)
{
	scheduler_state.wwdt_interrupt = true;
	PAC55XX_WWDT->WWDTLOCK = WWDTLOCK_REGS_WRITE_AVALABLE;
    // Interrupt flag needs to be cleared here
    PAC55XX_WWDT->WWDTFLAG.IF = 1;
}

