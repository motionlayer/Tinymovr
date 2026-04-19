
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

typedef struct {
    float homing_velocity;
    float max_homing_t;
    float max_stay_vel;
    float max_stay_dpos;
    float max_stay_t;
    float retract_distance;

} HomingPlannerConfig;

typedef struct {
    float home_t_current;
    float stay_t_current;
    uint8_t warnings;
} HomingPlannerState;

bool homing_planner_home(void);
bool homing_planner_evaluate(void);

uint8_t homing_planner_get_warnings(void);

float homing_planner_get_homing_velocity(void);
float homing_planner_get_max_homing_t(void);
float homing_planner_get_max_stall_vel(void);
float homing_planner_get_max_stall_delta_pos(void);
float homing_planner_get_max_stall_t(void);
float homing_planner_get_retract_distance(void);

void homing_planner_set_homing_velocity(float vel);
void homing_planner_set_max_homing_t(float t);
void homing_planner_set_max_stall_vel(float vel);
void homing_planner_set_max_stall_delta_pos(float dpos);
void homing_planner_set_max_stall_t(float t);
void homing_planner_set_retract_distance(float dist);

HomingPlannerConfig *homing_planner_get_config(void);
void homing_planner_restore_config(HomingPlannerConfig *config_);