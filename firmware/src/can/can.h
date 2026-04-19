
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

typedef struct 
{
    uint8_t id;
    uint8_t kbaud_rate;
    uint16_t heartbeat_period;
} CANConfig;

typedef struct 
{
    uint8_t faults;
    uint32_t last_msg_ms;
    bool send_heartbeat;
} CANState;

void CAN_init(void);
uint16_t CAN_get_kbit_rate(void);
void CAN_set_kbit_rate(uint16_t rate);
uint8_t CAN_get_ID(void);
void CAN_set_ID(uint8_t id);
void CAN_process_interrupt(void);

bool CAN_get_send_heartbeat(void);
void CAN_set_send_heartbeat(bool value);

CANConfig *CAN_get_config(void);
void CAN_restore_config(CANConfig *config_);
void CAN_restore_id(uint8_t id);

void CAN_update(void);
