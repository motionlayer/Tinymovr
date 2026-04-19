
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

#include <string.h>
#include <src/system/system.h>
#include <src/utils/utils.h>
#include <src/can/can_endpoints.h>
#include <src/sensor/sensor.h>
#include <src/sensor/ma7xx.h>

void ma7xx_make_blank_sensor(Sensor *s)
{
    MA7xxSensor *as = (MA7xxSensor *)s;
    as->config.rate = SENSORS_SETUP_EXTERNAL_SPI_RATE_3Mbps;
    s->config.type = SENSOR_TYPE_MA7XX;
    s->bits = MA7XX_BITS;
    s->ticks = MA7XX_TICKS;
    s->normalization_factor = SENSOR_COMMON_RES_TICKS_FLOAT / s->ticks;
    s->is_calibrated_func = ma7xx_rec_is_calibrated;
    s->get_raw_angle_func = ma7xx_get_raw_angle;
    s->init_func = ma7xx_init;
    s->deinit_func = ma7xx_deinit;
    s->reset_func = ma7xx_reset;
    s->update_func = ma7xx_update;
    s->prepare_func = ma7xx_send_angle_cmd;
    s->get_errors_func = ma7xx_get_errors;
    s->get_ss_config_func = ma7xx_get_ss_config;
}

bool ma7xx_init_with_port_and_rate(Sensor *s, const SSP_TYPE port, PAC55XX_SSP_TYPEDEF *ssp_struct, sensors_setup_external_spi_rate_options rate)
{
    MA7xxSensorConfig c = {0};
    c.ssp_port = port;
    c.ssp_struct = ssp_struct;
    c.rate = rate;
    return ma7xx_init_with_config(s, &c);
}

 bool ma7xx_init_with_config(Sensor *s, const MA7xxSensorConfig *c)
{
    MA7xxSensor *ms = (MA7xxSensor *)s;
    ms->config = *c;
    return ma7xx_init(s);
}

 bool ma7xx_init(Sensor *s)
{
    MA7xxSensor *ms = (MA7xxSensor *)s;
    ssp_init(ms->config.ssp_port, SSP_MS_MASTER, 4, SSP_DATA_SIZE_16, SWSEL_SPI, 0, 0);
    delay_us(16000); // ensure 16ms sensor startup time as per the datasheet
    ma7xx_send_angle_cmd(s);
    ma7xx_update(s, false);
    s->initialized = true;
    return true;
}

void ma7xx_deinit(Sensor *s)
{
    ssp_deinit(((MA7xxSensor *)s)->config.ssp_port);
    s->initialized = false;
}

void ma7xx_reset(Sensor *s)
{
    sensor_reset(s);
}

void ma7xx_get_ss_config(Sensor *s, void* buffer)
{
    const MA7xxSensor *ss = ((const MA7xxSensor *)s);
    memcpy(buffer, &(ss->config), sizeof(ss->config));
}
