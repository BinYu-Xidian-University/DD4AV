  //brake_acc_nodiv_ctrl_step1 // the following code is from this function

  /* local block i/o variables */
  real_T rtb_to_int;

  /* RateTransition: '<Root>/RT' */
  brake_acc_nodiv_ctrl_B_local.RT_h = RT_Buffer0;

  /* RateTransition: '<Root>/RT4' */
  brake_acc_nodiv_ctrl_B_local.RT4 = RT4_Buffer0;

  /* Rounding: '<S15>/to_int' incorporates:
   *  Inport: '<Root>/In_RRRotation'
   */
  rtb_to_int = rt_roundd_snf(brake_acc_nodiv_ctrl_U.In_RRRotation);

  // inline
  /* S-Function (fcncallgen): '<Root>/10ms_1' incorporates:
   *  SubSystem: '<Root>/ABS_RR_Wheel'
   */
  //brake_acc_nodiv_ct_ABS_RR_Wheel(brake_acc_nodiv_ctrl_B_local.RT4,
  //  brake_acc_nodiv_ctrl_B_local.RT_h, rtb_to_int,
  //  &brake_acc_nodiv_ctrl_B_local.ABS_RR_Wheel, //(P_ABS_RR_Wheel_brake_acc_nodi_T *)
  //  brake_acc_nodiv_ctrl_P.ABS_RR_Wheel);

  /* local block i/o variables */
  boolean_T rtb_RelationalOperator;
  real_T rtb_vms;
  real_T u;

  /* Outputs for Atomic SubSystem: '<S4>/If v>=10 km//h' */
  /* Gain: '<S29>/v (m//s)' */
  rtb_vms = brake_acc_nodiv_ctrl_P.ABS_RR_Wheel.vms_Gain * brake_acc_nodiv_ctrl_B_local.RT4;

  /* Sum: '<S29>/Subtract' incorporates:
   *  Gain: '<S29>/wheSpd (m//s)'
   */
  u = rtb_vms - brake_acc_nodiv_ctrl_P.ABS_RR_Wheel.wheSpdms_Gain * rtb_to_int;

  /* Saturate: '<S29>/positive' */
  // Lihao: lift
  real_T positive_UpperSat_local = brake_acc_nodiv_ctrl_P.ABS_RR_Wheel.positive_UpperSat;
  if (u >= positive_UpperSat_local) {
    u = brake_acc_nodiv_ctrl_P.ABS_RR_Wheel.positive_UpperSat;
  } else {
    // Lihao: lift
    real_T positive_LowerSat_local = brake_acc_nodiv_ctrl_P.ABS_RR_Wheel.positive_LowerSat;
    if (u <= positive_LowerSat_local) {
      u = brake_acc_nodiv_ctrl_P.ABS_RR_Wheel.positive_LowerSat;
    }
  }

  /* RelationalOperator: '<S29>/Relational Operator' incorporates:
   *  Gain: '<S29>/slip_abs_on_times_10'
   *  Gain: '<S29>/times_10'
   *  Saturate: '<S29>/positive'
   */
  rtb_RelationalOperator = (brake_acc_nodiv_ctrl_P.ABS_RR_Wheel.times_10_Gain * u >
    brake_acc_nodiv_ctrl_P.ABS_RR_Wheel.slip_abs_on_times_10_Gain * rtb_vms);

  /* Switch: '<S4>/Threshold_10km//h' */
  // Lihao: lift
  real_T Threshold_10kmh_Threshold_local = brake_acc_nodiv_ctrl_P.ABS_RR_Wheel.Threshold_10kmh_Threshold;
  if (brake_acc_nodiv_ctrl_B_local.RT4 >= Threshold_10kmh_Threshold_local) {
    /* Outputs for Atomic SubSystem: '<S4>/If v>=10 km//h' */
    /* Switch: '<S29>/LockDetect' incorporates:
     *  Constant: '<S29>/ReleaseBrake'
     */
    if (rtb_RelationalOperator) {
      brake_acc_nodiv_ctrl_B_local.ABS_RR_Wheel.Threshold_10kmh = brake_acc_nodiv_ctrl_P.ABS_RR_Wheel.ReleaseBrake_Value;
    } else {
      brake_acc_nodiv_ctrl_B_local.ABS_RR_Wheel.Threshold_10kmh = brake_acc_nodiv_ctrl_B_local.RT_h;
    }

    /* End of Outputs for SubSystem: '<S4>/If v>=10 km//h' */
  } else {
    /* Outputs for Atomic SubSystem: '<S4>/If v>=10 km//h' */
    /* Switch: '<S29>/LockDetect' */
    brake_acc_nodiv_ctrl_B_local.ABS_RR_Wheel.Threshold_10kmh = brake_acc_nodiv_ctrl_B_local.RT_h;

    /* End of Outputs for SubSystem: '<S4>/If v>=10 km//h' */
  }
  /* End of Switch: '<S4>/Threshold_10km//h' */
  // end of inline

  /* Outport: '<Root>/Out_TQ_RRBrake' */
  //brake_acc_nodiv_ctrl_Y.Out_TQ_RRBrake =
  //  brake_acc_nodiv_ctrl_B_local.ABS_RR_Wheel.Threshold_10kmh;

  /* RateTransition: '<Root>/RT1' */
  brake_acc_nodiv_ctrl_B_local.RT1 = RT1_Buffer0;

  /* End of RateTransition: '<Root>/RT1' */

  /* RateTransition: '<Root>/RT9' incorporates:
     *  Gain: '<S5>/Gain1'
     *  Rounding: '<S16>/round_to_int'
     *  Saturate: '<S7>/Pedal_map'
   */
  RT9 = rtb_to_int;

