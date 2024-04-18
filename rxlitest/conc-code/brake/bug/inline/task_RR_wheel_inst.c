  //brake_acc_nodiv_ctrl_step1 // the following code is from this function

  /* local block i/o variables */
__VERIFIER_atomic_TRANS_atomic_assume_task_RR_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_RR_Wheel();
  real_T rtb_to_int;
TRANS_atomic_assume_task_RR_Wheel();
__CPROVER_atomic_end();


  /* RateTransition: '<Root>/RT' */
__VERIFIER_atomic_TRANS_atomic_assume_task_RR_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_RR_Wheel();
  brake_acc_nodiv_ctrl_B_local.RT_h = RT_Buffer0;
TRANS_atomic_assume_task_RR_Wheel();
__CPROVER_atomic_end();


  /* RateTransition: '<Root>/RT4' */
__VERIFIER_atomic_TRANS_atomic_assume_task_RR_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_RR_Wheel();
  brake_acc_nodiv_ctrl_B_local.RT4 = RT4_Buffer0;
TRANS_atomic_assume_task_RR_Wheel();
__CPROVER_atomic_end();


  /* Rounding: '<S15>/to_int' incorporates:
   *  Inport: '<Root>/In_RRRotation'
   */
__VERIFIER_atomic_TRANS_atomic_assume_task_RR_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_RR_Wheel();
  rtb_to_int = rt_roundd_snf(brake_acc_nodiv_ctrl_U.In_RRRotation);
TRANS_atomic_assume_task_RR_Wheel();
__CPROVER_atomic_end();


  // inline
  /* S-Function (fcncallgen): '<Root>/10ms_1' incorporates:
   *  SubSystem: '<Root>/ABS_RR_Wheel'
   */
  //brake_acc_nodiv_ct_ABS_RR_Wheel(brake_acc_nodiv_ctrl_B_local.RT4,
  //  brake_acc_nodiv_ctrl_B_local.RT_h, rtb_to_int,
  //  &brake_acc_nodiv_ctrl_B_local.ABS_RR_Wheel, //(P_ABS_RR_Wheel_brake_acc_nodi_T *)
  //  brake_acc_nodiv_ctrl_P.ABS_RR_Wheel);

  /* local block i/o variables */
__VERIFIER_atomic_TRANS_atomic_assume_task_RR_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_RR_Wheel();
  boolean_T rtb_RelationalOperator;
TRANS_atomic_assume_task_RR_Wheel();
__CPROVER_atomic_end();

__VERIFIER_atomic_TRANS_atomic_assume_task_RR_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_RR_Wheel();
  real_T rtb_vms;
TRANS_atomic_assume_task_RR_Wheel();
__CPROVER_atomic_end();

__VERIFIER_atomic_TRANS_atomic_assume_task_RR_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_RR_Wheel();
  real_T u;
TRANS_atomic_assume_task_RR_Wheel();
__CPROVER_atomic_end();


  /* Outputs for Atomic SubSystem: '<S4>/If v>=10 km//h' */
  /* Gain: '<S29>/v (m//s)' */
__VERIFIER_atomic_TRANS_atomic_assume_task_RR_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_RR_Wheel();
  rtb_vms = brake_acc_nodiv_ctrl_P.ABS_RR_Wheel.vms_Gain * brake_acc_nodiv_ctrl_B_local.RT4;
TRANS_atomic_assume_task_RR_Wheel();
__CPROVER_atomic_end();


  /* Sum: '<S29>/Subtract' incorporates:
   *  Gain: '<S29>/wheSpd (m//s)'
   */
__VERIFIER_atomic_TRANS_atomic_assume_task_RR_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_RR_Wheel();
  u = rtb_vms - brake_acc_nodiv_ctrl_P.ABS_RR_Wheel.wheSpdms_Gain * rtb_to_int;
TRANS_atomic_assume_task_RR_Wheel();
__CPROVER_atomic_end();


  /* Saturate: '<S29>/positive' */
  // Lihao: lift
__VERIFIER_atomic_TRANS_atomic_assume_task_RR_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_RR_Wheel();
  real_T positive_UpperSat_local = brake_acc_nodiv_ctrl_P.ABS_RR_Wheel.positive_UpperSat;
TRANS_atomic_assume_task_RR_Wheel();
__CPROVER_atomic_end();

__VERIFIER_atomic_TRANS_atomic_assume_task_RR_Wheel();
  if (u >= positive_UpperSat_local) {
__VERIFIER_atomic_TRANS_atomic_assume_task_RR_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_RR_Wheel();
    u = brake_acc_nodiv_ctrl_P.ABS_RR_Wheel.positive_UpperSat;
TRANS_atomic_assume_task_RR_Wheel();
__CPROVER_atomic_end();

__VERIFIER_atomic_TRANS_atomic_assume_task_RR_Wheel();
  } else {
    // Lihao: lift
__VERIFIER_atomic_TRANS_atomic_assume_task_RR_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_RR_Wheel();
    real_T positive_LowerSat_local = brake_acc_nodiv_ctrl_P.ABS_RR_Wheel.positive_LowerSat;
TRANS_atomic_assume_task_RR_Wheel();
__CPROVER_atomic_end();

__VERIFIER_atomic_TRANS_atomic_assume_task_RR_Wheel();
    if (u <= positive_LowerSat_local) {
__VERIFIER_atomic_TRANS_atomic_assume_task_RR_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_RR_Wheel();
      u = brake_acc_nodiv_ctrl_P.ABS_RR_Wheel.positive_LowerSat;
TRANS_atomic_assume_task_RR_Wheel();
__CPROVER_atomic_end();

__VERIFIER_atomic_TRANS_atomic_assume_task_RR_Wheel();
    }
__VERIFIER_atomic_TRANS_atomic_assume_task_RR_Wheel();
  }

  /* RelationalOperator: '<S29>/Relational Operator' incorporates:
   *  Gain: '<S29>/slip_abs_on_times_10'
   *  Gain: '<S29>/times_10'
   *  Saturate: '<S29>/positive'
   */
__VERIFIER_atomic_TRANS_atomic_assume_task_RR_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_RR_Wheel();
  rtb_RelationalOperator = (brake_acc_nodiv_ctrl_P.ABS_RR_Wheel.times_10_Gain * u >
    brake_acc_nodiv_ctrl_P.ABS_RR_Wheel.slip_abs_on_times_10_Gain * rtb_vms);
TRANS_atomic_assume_task_RR_Wheel();
__CPROVER_atomic_end();


  /* Switch: '<S4>/Threshold_10km//h' */
  // Lihao: lift
__VERIFIER_atomic_TRANS_atomic_assume_task_RR_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_RR_Wheel();
  real_T Threshold_10kmh_Threshold_local = brake_acc_nodiv_ctrl_P.ABS_RR_Wheel.Threshold_10kmh_Threshold;
TRANS_atomic_assume_task_RR_Wheel();
__CPROVER_atomic_end();

__VERIFIER_atomic_TRANS_atomic_assume_task_RR_Wheel();
  if (brake_acc_nodiv_ctrl_B_local.RT4 >= Threshold_10kmh_Threshold_local) {
    /* Outputs for Atomic SubSystem: '<S4>/If v>=10 km//h' */
    /* Switch: '<S29>/LockDetect' incorporates:
     *  Constant: '<S29>/ReleaseBrake'
     */
__VERIFIER_atomic_TRANS_atomic_assume_task_RR_Wheel();
    if (rtb_RelationalOperator) {
__VERIFIER_atomic_TRANS_atomic_assume_task_RR_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_RR_Wheel();
      brake_acc_nodiv_ctrl_B_local.ABS_RR_Wheel.Threshold_10kmh = brake_acc_nodiv_ctrl_P.ABS_RR_Wheel.ReleaseBrake_Value;
TRANS_atomic_assume_task_RR_Wheel();
__CPROVER_atomic_end();

__VERIFIER_atomic_TRANS_atomic_assume_task_RR_Wheel();
    } else {
__VERIFIER_atomic_TRANS_atomic_assume_task_RR_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_RR_Wheel();
      brake_acc_nodiv_ctrl_B_local.ABS_RR_Wheel.Threshold_10kmh = brake_acc_nodiv_ctrl_B_local.RT_h;
TRANS_atomic_assume_task_RR_Wheel();
__CPROVER_atomic_end();

__VERIFIER_atomic_TRANS_atomic_assume_task_RR_Wheel();
    }

    /* End of Outputs for SubSystem: '<S4>/If v>=10 km//h' */
__VERIFIER_atomic_TRANS_atomic_assume_task_RR_Wheel();
  } else {
    /* Outputs for Atomic SubSystem: '<S4>/If v>=10 km//h' */
    /* Switch: '<S29>/LockDetect' */
__VERIFIER_atomic_TRANS_atomic_assume_task_RR_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_RR_Wheel();
    brake_acc_nodiv_ctrl_B_local.ABS_RR_Wheel.Threshold_10kmh = brake_acc_nodiv_ctrl_B_local.RT_h;
TRANS_atomic_assume_task_RR_Wheel();
__CPROVER_atomic_end();


    /* End of Outputs for SubSystem: '<S4>/If v>=10 km//h' */
__VERIFIER_atomic_TRANS_atomic_assume_task_RR_Wheel();
  }
  /* End of Switch: '<S4>/Threshold_10km//h' */
  // end of inline

  /* Outport: '<Root>/Out_TQ_RRBrake' */
  //brake_acc_nodiv_ctrl_Y.Out_TQ_RRBrake =
  //  brake_acc_nodiv_ctrl_B_local.ABS_RR_Wheel.Threshold_10kmh;

  /* RateTransition: '<Root>/RT1' */
__VERIFIER_atomic_TRANS_atomic_assume_task_RR_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_RR_Wheel();
  brake_acc_nodiv_ctrl_B_local.RT1 = RT1_Buffer0;
TRANS_atomic_assume_task_RR_Wheel();
__CPROVER_atomic_end();


  /* End of RateTransition: '<Root>/RT1' */

  /* RateTransition: '<Root>/RT9' incorporates:
     *  Gain: '<S5>/Gain1'
     *  Rounding: '<S16>/round_to_int'
     *  Saturate: '<S7>/Pedal_map'
   */
__VERIFIER_atomic_TRANS_atomic_assume_task_RR_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_RR_Wheel();
  RT9 = rtb_to_int;
TRANS_atomic_assume_task_RR_Wheel();
__CPROVER_atomic_end();


