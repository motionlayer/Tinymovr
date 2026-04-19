
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

#ifndef ADC_ADC_H_
#define ADC_ADC_H_

#include <src/common.h>

#ifdef CAFE_ARCH2
typedef enum
{
#if defined(PAC5527)
    PWRCTL_PWRMON_VCORE0 = 0u << 3,      // 0<<3 --> VCORE
    PWRCTL_PWRMON_VP = 1u << 3,          // 1<<3 --> VP * 1/10
    PWRCTL_PWRMON_VCC33 = 2u << 3,       // 2<<3 --> VCC33 * 4/10
    PWRCTL_PWRMON_VCCIO = 3u << 3,       // 3<<3 --> VCCIO * 4/10
    PWRCTL_PWRMON_VSYS = 4u << 3,        // 4<<3 --> VSYS * 4/10
    PWRCTL_PWRMON_VREFDIV2 = 5u << 3,    // 5<<3 --> VREF/2
    PWRCTL_PWRMON_VPTAT = 6u << 3,       // 6<<3 --> VPTAT
    PWRCTL_PWRMON_VCP_MINUS_VM = 7u << 3 // 7<<3 --> (VCP-VM) * 5/10
#endif                                   // #if defined(PAC5527)
} ADC_PWRCTL_PWRMON_Type;
#endif // #ifdef CAFE_ARCH2

#ifdef CAFE_ARCH2
// MODULE MISC CAFE REGISTER
#define HIB_BIT_DEFAULT 0u      // 0 = Normal; 1 = Hibernate
#define PBEN_BIT_DEFAULT 0u     // 0 = Push Button Disabled; 1 = Push Button Enabled (AIO6)
#define VREFSET_BIT_DEFAULT 0u  // 0 = ADC VREF is 2.5V; 1 = ADC VREF is 3.0V
#define CLKOUTEN_BIT_DEFAULT 0u // 0 = Disabled; 1 = Enabled
#define MCUALIVE_BIT_DEFAULT 1u // 0 = Disabled; 1 = Enabled
#define TPBD_BIT_DEFAULT 1u     // 0 = Disabled; 1 = Enabled
#define RFU_BIT_DEFAULT 0u      // 0 = Disabled; 1 = Enabled
#define ENSIG_BIT_DEFAULT 1u    // 0 = Disabled; 1 = Enabled
#define MODULE_MISC_BITS_DEFAULT ((HIB_BIT_DEFAULT << 7) + (PBEN_BIT_DEFAULT << 6) + (VREFSET_BIT_DEFAULT << 5) + (CLKOUTEN_BIT_DEFAULT << 4) + (MCUALIVE_BIT_DEFAULT << 3) + (TPBD_BIT_DEFAULT << 2) + (RFU_BIT_DEFAULT << 1) + (ENSIG_BIT_DEFAULT << 0))
#endif

#define GAINx1                          (0x01 << 3)
#define GAINx2                          (0x02 << 3)
#define GAINx4                          (0x03 << 3)
#define GAINx8                          (0x04 << 3)
#define GAINx16                         (0x05 << 3)
#define GAINx32                         (0x06 << 3)
#define GAINx64                         (0x07 << 3)

// Current sensing multipler defined as follows:
// meas * ONE_OVER_ADC_RES * VREF / R * ONE_OVER_ADC_GAIN

// Tinymovr R3.3 (alpha2) and later have 2mOhm shunts, ADC gain x16
// 1/2^12 * 2.5 / 0.002 / 16 ~= 0.0190734
#if defined BOARD_REV_R33 || defined BOARD_REV_R5
#define SHUNT_SCALING_FACTOR ( 0.0190734f )
#define ADC_GAIN_VAL GAINx16

// Tinymovr R3.2 (alpha1) and earlier have 1mOhm shunts, ADC gain x16
// 1/2^12 * 2.5 / 0.001 / 16 ~= 0.0381469
#elif defined BOARD_REV_R32
#define SHUNT_SCALING_FACTOR (0.0381469f)
#define ADC_GAIN_VAL GAINx16

// Tinymovr M5 have 50mOhm shunts, ADC gain x2
// 1/2^12 * 2.5 / 0.05 / 2 ~= 0.0061035
#elif defined BOARD_REV_M5
#define SHUNT_SCALING_FACTOR (0.0061035f)
#define ADC_GAIN_VAL GAINx2
#endif

// Inverse of sensing multiplier
#define ONE_OVER_SHUNT_SCALING_FACTOR (1.0f / SHUNT_SCALING_FACTOR)

// VBus scaling factor
#define VBUS_SCALING_FACTOR (0.0128f)

#define I_FILTER_K (0.6f)

typedef struct 
{
    float temp;
    float temp_cal_const;
    float temp_cal_factor;
    float temp_D;
    float I_phase_offset_D;
    FloatTriplet I_phase_meas;
} ADCState;

typedef struct
{
    FloatTriplet I_phase_offset;
    float Iphase_limit;
    float I_phase_offset_tau;
    float temp_tau;
} ADCConfig;

void ADC_init(void);
void ADC_reset(void);
bool ADC_calibrate_offset(void);
float ADC_get_mcu_temp(void);
void ADC_get_phase_currents(FloatTriplet *phc);
const FloatTriplet *ADC_get_phase_currents_ptr(void);
void ADC_update(void);
void ADC_update_temp(void);

ADCConfig *ADC_get_config(void);
void ADC_restore_config(ADCConfig *config_);

#endif /* ADC_ADC_H_ */
