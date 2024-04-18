  brake_acc_nodiv_ct_ABS_RR_Wheel(brake_acc_nodiv_ctrl_B_local.RT4,
    brake_acc_nodiv_ctrl_B_local.RT_h, rtb_to_int,
    &brake_acc_nodiv_ctrl_B_local.ABS_RR_Wheel, //(P_ABS_RR_Wheel_brake_acc_nodi_T *)
    brake_acc_nodiv_ctrl_P.ABS_RR_Wheel);

  brake_acc_nodiv_ct_ABS_RR_Wheel(brake_acc_nodiv_ctrl_B_local.RT4,
    brake_acc_nodiv_ctrl_B_local.RT3, rtb_to_int1,
    &brake_acc_nodiv_ctrl_B_local.ABS_FL_Wheel, //(P_ABS_RR_Wheel_brake_acc_nodi_T *)
    brake_acc_nodiv_ctrl_P.ABS_FL_Wheel);

  brake_acc_nodiv_ct_ABS_RR_Wheel(brake_acc_nodiv_ctrl_B_local.RT4,
    brake_acc_nodiv_ctrl_B_local.RT2, rtb_to_int_k,
    &brake_acc_nodiv_ctrl_B_local.ABS_FR_Wheel, //(P_ABS_RR_Wheel_brake_acc_nodi_T *)
    brake_acc_nodiv_ctrl_P.ABS_FR_Wheel);

  brake_acc_nodiv_ct_ABS_RR_Wheel(brake_acc_nodiv_ctrl_B_local.RT4,
    brake_acc_nodiv_ctrl_B_local.RT1, rtb_to_int_g,
    &brake_acc_nodiv_ctrl_B_local.ABS_RL_Wheel, //(P_ABS_RR_Wheel_brake_acc_nodi_T *)
    brake_acc_nodiv_ctrl_P.ABS_RL_Wheel);


{

  /* local block i/o variables */
  boolean_T rtb_RelationalOperator;
  real_T rtb_vms;
  real_T u;

  /* Outputs for Atomic SubSystem: '<S4>/If v>=10 km//h' */
  /* Gain: '<S29>/v (m//s)' */
  rtb_vms = brake_acc_nodiv_ctrl_P.ABS_RL_Wheel.vms_Gain * brake_acc_nodiv_ctrl_B_local.RT4;

  /* Sum: '<S29>/Subtract' incorporates:
   *  Gain: '<S29>/wheSpd (m//s)'
   */
  u = rtb_vms - brake_acc_nodiv_ctrl_P.ABS_RL_Wheel.wheSpdms_Gain * rtb_to_int_g;

  /* Saturate: '<S29>/positive' */
  // Lihao: lift
  real_T positive_UpperSat_local = brake_acc_nodiv_ctrl_P.ABS_RL_Wheel.positive_UpperSat;
  if (u >= positive_UpperSat_local) {
    u = brake_acc_nodiv_ctrl_P.ABS_RL_Wheel.positive_UpperSat;
  } else {
    // Lihao: lift
    real_T positive_LowerSat_local = brake_acc_nodiv_ctrl_P.ABS_RL_Wheel.positive_LowerSat;
    if (u <= positive_LowerSat_local) {
      u = brake_acc_nodiv_ctrl_P.ABS_RL_Wheel.positive_LowerSat;
    }
  }

  /* RelationalOperator: '<S29>/Relational Operator' incorporates:
   *  Gain: '<S29>/slip_abs_on_times_10'
   *  Gain: '<S29>/times_10'
   *  Saturate: '<S29>/positive'
   */
  rtb_RelationalOperator = (brake_acc_nodiv_ctrl_P.ABS_RL_Wheel.times_10_Gain * u >
    brake_acc_nodiv_ctrl_P.ABS_RL_Wheel.slip_abs_on_times_10_Gain * rtb_vms);

  /* Switch: '<S4>/Threshold_10km//h' */
  // Lihao: lift
  real_T Threshold_10kmh_Threshold_local = brake_acc_nodiv_ctrl_P.ABS_RL_Wheel.Threshold_10kmh_Threshold;
  if (brake_acc_nodiv_ctrl_B_local.RT4 >= Threshold_10kmh_Threshold_local) {
    /* Outputs for Atomic SubSystem: '<S4>/If v>=10 km//h' */
    /* Switch: '<S29>/LockDetect' incorporates:
     *  Constant: '<S29>/ReleaseBrake'
     */
    if (rtb_RelationalOperator) {
      brake_acc_nodiv_ctrl_B_local.ABS_RL_Wheel.Threshold_10kmh = brake_acc_nodiv_ctrl_P.ABS_RL_Wheel.ReleaseBrake_Value;
    } else {
      brake_acc_nodiv_ctrl_B_local.ABS_RL_Wheel.Threshold_10kmh = brake_acc_nodiv_ctrl_B_local.RT1;
    }

    /* End of Outputs for SubSystem: '<S4>/If v>=10 km//h' */
  } else {
    /* Outputs for Atomic SubSystem: '<S4>/If v>=10 km//h' */
    /* Switch: '<S29>/LockDetect' */
    brake_acc_nodiv_ctrl_B_local.ABS_RL_Wheel.Threshold_10kmh = brake_acc_nodiv_ctrl_B_local.RT1;

    /* End of Outputs for SubSystem: '<S4>/If v>=10 km//h' */
  }

  /* End of Switch: '<S4>/Threshold_10km//h' */

}

