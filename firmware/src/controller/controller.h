
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
#include <src/tm_enums.h>
#include <src/controller/trajectory_planner.h>
#include <src/controller/homing_planner.h>

typedef struct
{
    controller_state_options state;
    controller_mode_options mode;
    uint8_t warnings;
    uint8_t errors;
    bool is_calibrating;
    FloatTriplet modulation_values;
    float Iq_estimate;
    float Id_estimate;
    float Ibus_est;
    float power_est;
    float pos_setpoint; // expressed in position frame
    float vel_setpoint; // expressed in position frame
    float vel_ramp_setpoint;
    float Iq_setpoint; // expressed in commutation frame
    float Id_setpoint; // expressed in commutation frame
    float Vq_setpoint; // expressed in commutation frame
    float vel_integrator;
    float Iq_integrator;
    float Id_integrator;
    float t_plan;
} ControllerState;

typedef struct
{
    float vel_limit;
    float vel_ramp_limit;
    float I_limit;
    float pos_gain;
    float vel_gain;
    float vel_integral_gain;
    float vel_integral_deadband;
    float I_bw;
    float I_gain;
    float Iq_integral_gain;
    float Id_integral_gain;
    float I_k;
    float vel_increment;
    float max_Ibus_regen;
    float max_Ibrake;
} ControllerConfig;

void Controller_ControlLoop(void);

controller_state_options controller_get_state(void);
void controller_set_state(controller_state_options new_state);

controller_mode_options controller_get_mode(void);
void controller_set_mode(controller_mode_options mode);

inline void controller_calibrate(void) {controller_set_state(CONTROLLER_STATE_CALIBRATE);}
inline void controller_idle(void) {controller_set_state(CONTROLLER_STATE_IDLE);}
inline void controller_position_mode(void) {controller_set_mode(CONTROLLER_MODE_POSITION);controller_set_state(CONTROLLER_STATE_CL_CONTROL);}
inline void controller_velocity_mode(void) {controller_set_mode(CONTROLLER_MODE_VELOCITY);controller_set_state(CONTROLLER_STATE_CL_CONTROL);}
inline void controller_current_mode(void) {controller_set_mode(CONTROLLER_MODE_CURRENT);controller_set_state(CONTROLLER_STATE_CL_CONTROL);}

float controller_get_Iq_estimate_user_frame(void);

float controller_get_pos_setpoint_user_frame(void);
float controller_get_vel_setpoint_user_frame(void);
float controller_get_Iq_setpoint_user_frame(void);
float controller_get_Id_setpoint_user_frame(void);

void controller_set_pos_setpoint_user_frame(float value);
void controller_set_vel_setpoint_user_frame(float value);
void controller_set_Iq_setpoint_user_frame(float value);

float controller_set_pos_vel_setpoints_user_frame(float pos_setpoint, float vel_setpoint);

float controller_get_Iq_estimate(void);

float controller_get_Vq_setpoint_user_frame(void);

float controller_set_pos_vel_setpoints(float pos_setpoint, float vel_setpoint);

float controller_get_pos_gain(void);
void controller_set_pos_gain(float gain);
float controller_get_vel_gain(void);
void controller_set_vel_gain(float gain);
float controller_get_vel_integral_gain(void);
void controller_set_vel_integral_gain(float gain);
float controller_get_vel_integral_deadband(void);
void controller_set_vel_integral_deadband(float gain);
float controller_get_Iq_gain(void);
float controller_get_I_bw(void);
void controller_set_I_bw(float bw);

float controller_get_Ibus_est(void);
float controller_get_power_est(void);

float controller_get_vel_limit(void);
void controller_set_vel_limit(float limit);
float controller_get_Iq_limit(void);
void controller_set_Iq_limit(float limit);
float controller_get_vel_increment(void);
void controller_set_vel_increment(float inc);

float controller_get_max_Ibus_regen(void);
void controller_set_max_Ibus_regen(float value);
float controller_get_max_Ibrake(void);
void controller_set_max_Ibrake(float value);

void controller_set_motion_plan(MotionPlan mp);

void controller_update_I_gains(void);

uint8_t controller_get_warnings(void);
uint8_t controller_get_errors(void);

ControllerConfig *controller_get_config(void);
void controller_restore_config(ControllerConfig *config_);

