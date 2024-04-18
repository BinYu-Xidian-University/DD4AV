
  //  brake_acc_nodiv_ctrl_step2(); //the following code is from this function
__VERIFIER_atomic_TRANS_atomic_assume_task_compute();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_compute();
  real_T vkmh;
TRANS_atomic_assume_task_compute();
__CPROVER_atomic_end();

__VERIFIER_atomic_TRANS_atomic_assume_task_compute();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_compute();
  real_T Distribution_idx;
TRANS_atomic_assume_task_compute();
__CPROVER_atomic_end();

__VERIFIER_atomic_TRANS_atomic_assume_task_compute();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_compute();
  real_T Distribution_idx_0;
TRANS_atomic_assume_task_compute();
__CPROVER_atomic_end();

__VERIFIER_atomic_TRANS_atomic_assume_task_compute();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_compute();
  real_T Distribution_idx_1;
TRANS_atomic_assume_task_compute();
__CPROVER_atomic_end();


  /* S-Function (fcncallgen): '<Root>/20ms' incorporates:
   *  SubSystem: '<Root>/Global Brake Controller'
   */
  /* Gain: '<S6>/Distribution' */
__VERIFIER_atomic_TRANS_atomic_assume_task_compute();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_compute();
  Distribution_idx = brake_acc_nodiv_ctrl_P.Distribution_Gain[1] *
    brake_acc_nodiv_ctrl_B_local.RT14;
TRANS_atomic_assume_task_compute();
__CPROVER_atomic_end();

__VERIFIER_atomic_TRANS_atomic_assume_task_compute();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_compute();
  Distribution_idx_0 = brake_acc_nodiv_ctrl_P.Distribution_Gain[2] *
    brake_acc_nodiv_ctrl_B_local.RT14;
TRANS_atomic_assume_task_compute();
__CPROVER_atomic_end();

__VERIFIER_atomic_TRANS_atomic_assume_task_compute();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_compute();
  Distribution_idx_1 = brake_acc_nodiv_ctrl_P.Distribution_Gain[3] *
    brake_acc_nodiv_ctrl_B_local.RT14;
TRANS_atomic_assume_task_compute();
__CPROVER_atomic_end();


  /* S-Function (fcncallgen): '<Root>/20ms1' incorporates:
   *  SubSystem: '<Root>/Veh_Speed_Estimator'
   */
  /* Gain: '<S25>/v (km//h)' incorporates:
   *  Gain: '<S25>/average_rpm'
   *  Gain: '<S25>/w (grad//s)'
   *  Sum: '<S25>/Add'
   */

__VERIFIER_atomic_TRANS_atomic_assume_task_compute();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_compute();
  vkmh = (((RT9 + RT10) + RT11) + RT12) * brake_acc_nodiv_ctrl_P.average_rpm_Gain * 
    brake_acc_nodiv_ctrl_P.wgrads_Gain * brake_acc_nodiv_ctrl_P.vkmh_Gain;
TRANS_atomic_assume_task_compute();
__CPROVER_atomic_end();


  // Lihao
__VERIFIER_atomic_TRANS_atomic_assume_task_compute();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_compute();
    real_T tmp = (((RT9 + RT10) + RT11) + RT12) * brake_acc_nodiv_ctrl_P.average_rpm_Gain * 
      brake_acc_nodiv_ctrl_P.wgrads_Gain * brake_acc_nodiv_ctrl_P.vkmh_Gain;
TRANS_atomic_assume_task_compute();
__CPROVER_atomic_end();


__VERIFIER_atomic_TRANS_atomic_assume_task_compute();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_compute();
    assert(fabs(vkmh-tmp)<=0.001);
TRANS_atomic_assume_task_compute();
__CPROVER_atomic_end();

    //assert(test == 0);

  /* S-Function (fcncallgen): '<Root>/20ms' incorporates:
   *  SubSystem: '<Root>/Global Brake Controller'
   */
  /* Update for RateTransition: '<Root>/RT' incorporates:
   *  Gain: '<S6>/Distribution'
   */
__VERIFIER_atomic_TRANS_atomic_assume_task_compute();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_compute();
  RT_Buffer0 = brake_acc_nodiv_ctrl_P.Distribution_Gain[0] * brake_acc_nodiv_ctrl_B_local.RT14;
TRANS_atomic_assume_task_compute();
__CPROVER_atomic_end();


  /* Update for RateTransition: '<Root>/RT4' */
__VERIFIER_atomic_TRANS_atomic_assume_task_compute();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_compute();
  RT4_Buffer0 = vkmh;
TRANS_atomic_assume_task_compute();
__CPROVER_atomic_end();


  /* Update for RateTransition: '<Root>/RT1' */
__VERIFIER_atomic_TRANS_atomic_assume_task_compute();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_compute();
  RT1_Buffer0 = Distribution_idx;
TRANS_atomic_assume_task_compute();
__CPROVER_atomic_end();


  /* Update for RateTransition: '<Root>/RT2' */
__VERIFIER_atomic_TRANS_atomic_assume_task_compute();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_compute();
  RT2_Buffer0 = Distribution_idx_0;
TRANS_atomic_assume_task_compute();
__CPROVER_atomic_end();


  /* Update for RateTransition: '<Root>/RT3' */
__VERIFIER_atomic_TRANS_atomic_assume_task_compute();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_compute();
  RT3_Buffer0 = Distribution_idx_1;
TRANS_atomic_assume_task_compute();
__CPROVER_atomic_end();

__VERIFIER_atomic_TRANS_atomic_assume_task_compute();
}

