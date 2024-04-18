
  //  brake_acc_nodiv_ctrl_step2(); //the following code is from this function
  real_T vkmh;
  real_T Distribution_idx;
  real_T Distribution_idx_0;
  real_T Distribution_idx_1;

  /* S-Function (fcncallgen): '<Root>/20ms' incorporates:
   *  SubSystem: '<Root>/Global Brake Controller'
   */
  /* Gain: '<S6>/Distribution' */
  Distribution_idx = brake_acc_nodiv_ctrl_P.Distribution_Gain[1] *
    brake_acc_nodiv_ctrl_B_local.RT14;
  Distribution_idx_0 = brake_acc_nodiv_ctrl_P.Distribution_Gain[2] *
    brake_acc_nodiv_ctrl_B_local.RT14;
  Distribution_idx_1 = brake_acc_nodiv_ctrl_P.Distribution_Gain[3] *
    brake_acc_nodiv_ctrl_B_local.RT14;

  /* S-Function (fcncallgen): '<Root>/20ms1' incorporates:
   *  SubSystem: '<Root>/Veh_Speed_Estimator'
   */
  /* Gain: '<S25>/v (km//h)' incorporates:
   *  Gain: '<S25>/average_rpm'
   *  Gain: '<S25>/w (grad//s)'
   *  Sum: '<S25>/Add'
   */

  vkmh = (((RT9 + RT10) + RT11) + RT12) * brake_acc_nodiv_ctrl_P.average_rpm_Gain * 
    brake_acc_nodiv_ctrl_P.wgrads_Gain * brake_acc_nodiv_ctrl_P.vkmh_Gain;

  // Lihao
    real_T tmp = (((RT9 + RT10) + RT11) + RT12) * brake_acc_nodiv_ctrl_P.average_rpm_Gain * 
      brake_acc_nodiv_ctrl_P.wgrads_Gain * brake_acc_nodiv_ctrl_P.vkmh_Gain;

    assert(fabs(vkmh-tmp)<=0.001);
    //assert(test == 0);

  /* S-Function (fcncallgen): '<Root>/20ms' incorporates:
   *  SubSystem: '<Root>/Global Brake Controller'
   */
  /* Update for RateTransition: '<Root>/RT' incorporates:
   *  Gain: '<S6>/Distribution'
   */
  RT_Buffer0 = brake_acc_nodiv_ctrl_P.Distribution_Gain[0] * brake_acc_nodiv_ctrl_B_local.RT14;

  /* Update for RateTransition: '<Root>/RT4' */
  RT4_Buffer0 = vkmh;

  /* Update for RateTransition: '<Root>/RT1' */
  RT1_Buffer0 = Distribution_idx;

  /* Update for RateTransition: '<Root>/RT2' */
  RT2_Buffer0 = Distribution_idx_0;

  /* Update for RateTransition: '<Root>/RT3' */
  RT3_Buffer0 = Distribution_idx_1;
}

