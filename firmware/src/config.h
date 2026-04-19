
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

/// TINYMOVR CONFIGURATION OPTIONS ///

#define ACLK_FREQ_HZ                (300000000)
#define HCLK_FREQ_HZ                (150000000)
#define CLKREF_FREQ_HZ              (4000000)
#define FRCLK_FREQ_HZ               CLKREF_FREQ_HZ

// Timer clock divider
#define TXCTL_PS_DIV                TXCTL_PS_DIV2

// PWM and Systick frequency
#define PWM_FREQ_HZ              (20000)
#define SYSTICK_FREQ_HZ          (1000)

// Control parameters
#define PWM_LIMIT                   (0.8f)
#define I_INTEGRATOR_DECAY_FACTOR   (0.995f)
#define I_TRIP_MARGIN               (1.5f)
#define VBUS_LOW_THRESHOLD          (10.4f)   // V
#define VEL_HARD_LIMIT              (600000.0f)  // ticks/s
#define I_HARD_LIMIT                (60.0f)    // A
#define MAX_CL_INIT_STEPS           (200)
#define PRE_CL_I_SD_MAX            (0.4f)

// Encoder rectification lookup table size
#define ECN_BITS (6)
#define ECN_SIZE (1 << ECN_BITS)

// UART
#define UART_ENUM UARTB
#define UART_REF PAC55XX_UARTB
#define UART_BAUD_RATE (115200)

#define UART_I_SCALING_FACTOR ( 1000.0f )
#define ONE_OVER_UART_I_SCALING_FACTOR ( 0.001f )

#define UART_R_SCALING_FACTOR ( 1000.0f )
#define ONE_OVER_UART_R_SCALING_FACTOR ( 0.001f )

#define UART_L_SCALING_FACTOR ( 1000.0f )
#define ONE_OVER_UART_L_SCALING_FACTOR ( 0.001f )

#define UART_VEL_GAIN_SCALING_FACTOR ( 1000000.0f )
#define ONE_OVER_UART_VEL_GAIN_SCALING_FACTOR ( 0.000001f )

#define UART_VEL_INT_SCALING_FACTOR ( 1000.0f )
#define ONE_OVER_UART_VEL_INT_SCALING_FACTOR ( 0.001f )

#define UART_IQ_LIMIT_SCALING_FACTOR ( 1000.f )
#define ONE_OVER_UART_IQ_LIMIT_SCALING_FACTOR ( 0.001f )

#define UART_V_SCALING_FACTOR ( 1000.0f )
