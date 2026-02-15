/*
* This file was automatically generated using Avlos.
* https://github.com/tinymovr/avlos
*
* Any changes to this file will be overwritten when
* content is regenerated.
*/

#include "avlos_endpoint_metadata.h"


const Avlos_EndpointMeta avlos_endpoint_meta[] = {

    /* avlos_protocol_hash */
    [0] = {
        .kind = AVLOS_EP_KIND_READ_ONLY,
        .value_dtype = AVLOS_DTYPE_UINT32,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_uid */
    [1] = {
        .kind = AVLOS_EP_KIND_READ_ONLY,
        .value_dtype = AVLOS_DTYPE_UINT32,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_fw_version */
    [2] = {
        .kind = AVLOS_EP_KIND_READ_ONLY,
        .value_dtype = AVLOS_DTYPE_STRING,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_hw_revision */
    [3] = {
        .kind = AVLOS_EP_KIND_READ_ONLY,
        .value_dtype = AVLOS_DTYPE_UINT32,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_Vbus */
    [4] = {
        .kind = AVLOS_EP_KIND_READ_ONLY,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_Ibus */
    [5] = {
        .kind = AVLOS_EP_KIND_READ_ONLY,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_power */
    [6] = {
        .kind = AVLOS_EP_KIND_READ_ONLY,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_temp */
    [7] = {
        .kind = AVLOS_EP_KIND_READ_ONLY,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_calibrated */
    [8] = {
        .kind = AVLOS_EP_KIND_READ_ONLY,
        .value_dtype = AVLOS_DTYPE_BOOL,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_errors */
    [9] = {
        .kind = AVLOS_EP_KIND_READ_ONLY,
        .value_dtype = AVLOS_DTYPE_UINT8,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_warnings */
    [10] = {
        .kind = AVLOS_EP_KIND_READ_ONLY,
        .value_dtype = AVLOS_DTYPE_UINT8,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_save_config */
    [11] = {
        .kind = AVLOS_EP_KIND_CALL_NO_ARGS,
        .value_dtype = AVLOS_DTYPE_VOID,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_erase_config */
    [12] = {
        .kind = AVLOS_EP_KIND_CALL_NO_ARGS,
        .value_dtype = AVLOS_DTYPE_VOID,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_nvm_num_slots */
    [13] = {
        .kind = AVLOS_EP_KIND_READ_ONLY,
        .value_dtype = AVLOS_DTYPE_UINT8,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_nvm_current_slot */
    [14] = {
        .kind = AVLOS_EP_KIND_READ_ONLY,
        .value_dtype = AVLOS_DTYPE_UINT8,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_nvm_write_count */
    [15] = {
        .kind = AVLOS_EP_KIND_READ_ONLY,
        .value_dtype = AVLOS_DTYPE_UINT32,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_reset */
    [16] = {
        .kind = AVLOS_EP_KIND_CALL_NO_ARGS,
        .value_dtype = AVLOS_DTYPE_VOID,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_enter_dfu */
    [17] = {
        .kind = AVLOS_EP_KIND_CALL_NO_ARGS,
        .value_dtype = AVLOS_DTYPE_VOID,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_config_size */
    [18] = {
        .kind = AVLOS_EP_KIND_READ_ONLY,
        .value_dtype = AVLOS_DTYPE_UINT32,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_scheduler_load */
    [19] = {
        .kind = AVLOS_EP_KIND_READ_ONLY,
        .value_dtype = AVLOS_DTYPE_UINT32,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_scheduler_warnings */
    [20] = {
        .kind = AVLOS_EP_KIND_READ_ONLY,
        .value_dtype = AVLOS_DTYPE_UINT8,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_controller_state */
    [21] = {
        .kind = AVLOS_EP_KIND_READ_WRITE,
        .value_dtype = AVLOS_DTYPE_UINT8,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_controller_mode */
    [22] = {
        .kind = AVLOS_EP_KIND_READ_WRITE,
        .value_dtype = AVLOS_DTYPE_UINT8,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_controller_warnings */
    [23] = {
        .kind = AVLOS_EP_KIND_READ_ONLY,
        .value_dtype = AVLOS_DTYPE_UINT8,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_controller_errors */
    [24] = {
        .kind = AVLOS_EP_KIND_READ_ONLY,
        .value_dtype = AVLOS_DTYPE_UINT8,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_controller_position_setpoint */
    [25] = {
        .kind = AVLOS_EP_KIND_READ_WRITE,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_controller_position_p_gain */
    [26] = {
        .kind = AVLOS_EP_KIND_READ_WRITE,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_controller_velocity_setpoint */
    [27] = {
        .kind = AVLOS_EP_KIND_READ_WRITE,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_controller_velocity_limit */
    [28] = {
        .kind = AVLOS_EP_KIND_READ_WRITE,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_controller_velocity_p_gain */
    [29] = {
        .kind = AVLOS_EP_KIND_READ_WRITE,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_controller_velocity_i_gain */
    [30] = {
        .kind = AVLOS_EP_KIND_READ_WRITE,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_controller_velocity_deadband */
    [31] = {
        .kind = AVLOS_EP_KIND_READ_WRITE,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_controller_velocity_increment */
    [32] = {
        .kind = AVLOS_EP_KIND_READ_WRITE,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_controller_current_Iq_setpoint */
    [33] = {
        .kind = AVLOS_EP_KIND_READ_WRITE,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_controller_current_Id_setpoint */
    [34] = {
        .kind = AVLOS_EP_KIND_READ_ONLY,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_controller_current_Iq_limit */
    [35] = {
        .kind = AVLOS_EP_KIND_READ_WRITE,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_controller_current_Iq_estimate */
    [36] = {
        .kind = AVLOS_EP_KIND_READ_ONLY,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_controller_current_bandwidth */
    [37] = {
        .kind = AVLOS_EP_KIND_READ_WRITE,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_controller_current_Iq_p_gain */
    [38] = {
        .kind = AVLOS_EP_KIND_READ_ONLY,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_controller_current_max_Ibus_regen */
    [39] = {
        .kind = AVLOS_EP_KIND_READ_WRITE,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_controller_current_max_Ibrake */
    [40] = {
        .kind = AVLOS_EP_KIND_READ_WRITE,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_controller_voltage_Vq_setpoint */
    [41] = {
        .kind = AVLOS_EP_KIND_READ_ONLY,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_controller_calibrate */
    [42] = {
        .kind = AVLOS_EP_KIND_CALL_NO_ARGS,
        .value_dtype = AVLOS_DTYPE_VOID,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_controller_idle */
    [43] = {
        .kind = AVLOS_EP_KIND_CALL_NO_ARGS,
        .value_dtype = AVLOS_DTYPE_VOID,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_controller_position_mode */
    [44] = {
        .kind = AVLOS_EP_KIND_CALL_NO_ARGS,
        .value_dtype = AVLOS_DTYPE_VOID,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_controller_velocity_mode */
    [45] = {
        .kind = AVLOS_EP_KIND_CALL_NO_ARGS,
        .value_dtype = AVLOS_DTYPE_VOID,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_controller_current_mode */
    [46] = {
        .kind = AVLOS_EP_KIND_CALL_NO_ARGS,
        .value_dtype = AVLOS_DTYPE_VOID,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_controller_set_pos_vel_setpoints */
    [47] = {
        .kind = AVLOS_EP_KIND_CALL_WITH_ARGS,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 2,
        .arg_dtypes = {
            AVLOS_DTYPE_FLOAT, 
            AVLOS_DTYPE_FLOAT, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_comms_can_rate */
    [48] = {
        .kind = AVLOS_EP_KIND_READ_WRITE,
        .value_dtype = AVLOS_DTYPE_UINT32,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_comms_can_id */
    [49] = {
        .kind = AVLOS_EP_KIND_READ_WRITE,
        .value_dtype = AVLOS_DTYPE_UINT32,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_comms_can_heartbeat */
    [50] = {
        .kind = AVLOS_EP_KIND_READ_WRITE,
        .value_dtype = AVLOS_DTYPE_BOOL,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_motor_R */
    [51] = {
        .kind = AVLOS_EP_KIND_READ_WRITE,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_motor_L */
    [52] = {
        .kind = AVLOS_EP_KIND_READ_WRITE,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_motor_pole_pairs */
    [53] = {
        .kind = AVLOS_EP_KIND_READ_WRITE,
        .value_dtype = AVLOS_DTYPE_UINT8,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_motor_type */
    [54] = {
        .kind = AVLOS_EP_KIND_READ_WRITE,
        .value_dtype = AVLOS_DTYPE_UINT8,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_motor_calibrated */
    [55] = {
        .kind = AVLOS_EP_KIND_READ_ONLY,
        .value_dtype = AVLOS_DTYPE_BOOL,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_motor_I_cal */
    [56] = {
        .kind = AVLOS_EP_KIND_READ_WRITE,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_motor_errors */
    [57] = {
        .kind = AVLOS_EP_KIND_READ_ONLY,
        .value_dtype = AVLOS_DTYPE_UINT8,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_sensors_user_frame_position_estimate */
    [58] = {
        .kind = AVLOS_EP_KIND_READ_ONLY,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_sensors_user_frame_velocity_estimate */
    [59] = {
        .kind = AVLOS_EP_KIND_READ_ONLY,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_sensors_user_frame_offset */
    [60] = {
        .kind = AVLOS_EP_KIND_READ_WRITE,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_sensors_user_frame_multiplier */
    [61] = {
        .kind = AVLOS_EP_KIND_READ_WRITE,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_sensors_setup_onboard_calibrated */
    [62] = {
        .kind = AVLOS_EP_KIND_READ_ONLY,
        .value_dtype = AVLOS_DTYPE_BOOL,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_sensors_setup_onboard_errors */
    [63] = {
        .kind = AVLOS_EP_KIND_READ_ONLY,
        .value_dtype = AVLOS_DTYPE_UINT8,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_sensors_setup_external_spi_type */
    [64] = {
        .kind = AVLOS_EP_KIND_READ_WRITE,
        .value_dtype = AVLOS_DTYPE_UINT8,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_sensors_setup_external_spi_rate */
    [65] = {
        .kind = AVLOS_EP_KIND_READ_WRITE,
        .value_dtype = AVLOS_DTYPE_UINT8,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_sensors_setup_external_spi_calibrated */
    [66] = {
        .kind = AVLOS_EP_KIND_READ_ONLY,
        .value_dtype = AVLOS_DTYPE_BOOL,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_sensors_setup_external_spi_errors */
    [67] = {
        .kind = AVLOS_EP_KIND_READ_ONLY,
        .value_dtype = AVLOS_DTYPE_UINT8,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_sensors_setup_hall_calibrated */
    [68] = {
        .kind = AVLOS_EP_KIND_READ_ONLY,
        .value_dtype = AVLOS_DTYPE_BOOL,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_sensors_setup_hall_errors */
    [69] = {
        .kind = AVLOS_EP_KIND_READ_ONLY,
        .value_dtype = AVLOS_DTYPE_UINT8,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_sensors_select_position_sensor_connection */
    [70] = {
        .kind = AVLOS_EP_KIND_READ_WRITE,
        .value_dtype = AVLOS_DTYPE_UINT8,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_sensors_select_position_sensor_bandwidth */
    [71] = {
        .kind = AVLOS_EP_KIND_READ_WRITE,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_sensors_select_position_sensor_raw_angle */
    [72] = {
        .kind = AVLOS_EP_KIND_READ_ONLY,
        .value_dtype = AVLOS_DTYPE_INT32,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_sensors_select_position_sensor_position_estimate */
    [73] = {
        .kind = AVLOS_EP_KIND_READ_ONLY,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_sensors_select_position_sensor_velocity_estimate */
    [74] = {
        .kind = AVLOS_EP_KIND_READ_ONLY,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_sensors_select_commutation_sensor_connection */
    [75] = {
        .kind = AVLOS_EP_KIND_READ_WRITE,
        .value_dtype = AVLOS_DTYPE_UINT8,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_sensors_select_commutation_sensor_bandwidth */
    [76] = {
        .kind = AVLOS_EP_KIND_READ_WRITE,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_sensors_select_commutation_sensor_raw_angle */
    [77] = {
        .kind = AVLOS_EP_KIND_READ_ONLY,
        .value_dtype = AVLOS_DTYPE_INT32,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_sensors_select_commutation_sensor_position_estimate */
    [78] = {
        .kind = AVLOS_EP_KIND_READ_ONLY,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_sensors_select_commutation_sensor_velocity_estimate */
    [79] = {
        .kind = AVLOS_EP_KIND_READ_ONLY,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_traj_planner_max_accel */
    [80] = {
        .kind = AVLOS_EP_KIND_READ_WRITE,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_traj_planner_max_decel */
    [81] = {
        .kind = AVLOS_EP_KIND_READ_WRITE,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_traj_planner_max_vel */
    [82] = {
        .kind = AVLOS_EP_KIND_READ_WRITE,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_traj_planner_t_accel */
    [83] = {
        .kind = AVLOS_EP_KIND_READ_WRITE,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_traj_planner_t_decel */
    [84] = {
        .kind = AVLOS_EP_KIND_READ_WRITE,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_traj_planner_t_total */
    [85] = {
        .kind = AVLOS_EP_KIND_READ_WRITE,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_traj_planner_move_to */
    [86] = {
        .kind = AVLOS_EP_KIND_CALL_WITH_ARGS,
        .value_dtype = AVLOS_DTYPE_VOID,
        .num_args = 1,
        .arg_dtypes = {
            AVLOS_DTYPE_FLOAT, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_traj_planner_move_to_tlimit */
    [87] = {
        .kind = AVLOS_EP_KIND_CALL_WITH_ARGS,
        .value_dtype = AVLOS_DTYPE_VOID,
        .num_args = 1,
        .arg_dtypes = {
            AVLOS_DTYPE_FLOAT, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_traj_planner_errors */
    [88] = {
        .kind = AVLOS_EP_KIND_READ_ONLY,
        .value_dtype = AVLOS_DTYPE_UINT8,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_homing_velocity */
    [89] = {
        .kind = AVLOS_EP_KIND_READ_WRITE,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_homing_max_homing_t */
    [90] = {
        .kind = AVLOS_EP_KIND_READ_WRITE,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_homing_retract_dist */
    [91] = {
        .kind = AVLOS_EP_KIND_READ_WRITE,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_homing_warnings */
    [92] = {
        .kind = AVLOS_EP_KIND_READ_ONLY,
        .value_dtype = AVLOS_DTYPE_UINT8,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_homing_stall_detect_velocity */
    [93] = {
        .kind = AVLOS_EP_KIND_READ_WRITE,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_homing_stall_detect_delta_pos */
    [94] = {
        .kind = AVLOS_EP_KIND_READ_WRITE,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_homing_stall_detect_t */
    [95] = {
        .kind = AVLOS_EP_KIND_READ_WRITE,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_homing_home */
    [96] = {
        .kind = AVLOS_EP_KIND_CALL_NO_ARGS,
        .value_dtype = AVLOS_DTYPE_VOID,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_watchdog_enabled */
    [97] = {
        .kind = AVLOS_EP_KIND_READ_WRITE,
        .value_dtype = AVLOS_DTYPE_BOOL,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_watchdog_triggered */
    [98] = {
        .kind = AVLOS_EP_KIND_READ_ONLY,
        .value_dtype = AVLOS_DTYPE_BOOL,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    },


    /* avlos_watchdog_timeout */
    [99] = {
        .kind = AVLOS_EP_KIND_READ_WRITE,
        .value_dtype = AVLOS_DTYPE_FLOAT,
        .num_args = 0,
        .arg_dtypes = {
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID, 
            AVLOS_DTYPE_VOID
        }
    }


};

const uint8_t avlos_endpoint_meta_count = sizeof(avlos_endpoint_meta) / sizeof(avlos_endpoint_meta[0]);
