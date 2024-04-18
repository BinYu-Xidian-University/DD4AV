int __TRANS_thread_running[] = {0, 0, 0, 0};

void __VERIFIER_atomic_TRANS_atomic_assume_task_compute(void) {
__CPROVER_assume(__TRANS_thread_running[1]==0 && __TRANS_thread_running[2]==0 && __TRANS_thread_running[3]==0);
}

void TRANS_atomic_assume_task_compute(void) {
__CPROVER_assume(__TRANS_thread_running[1]==0 && __TRANS_thread_running[2]==0 && __TRANS_thread_running[3]==0);
}

void __VERIFIER_atomic_TRANS_task_compute_enter_thread() {
__CPROVER_assume(__TRANS_thread_running[1]==0 && __TRANS_thread_running[2]==0 && __TRANS_thread_running[3]==0);
__TRANS_thread_running[0]=1;
__CPROVER_assume(__TRANS_thread_running[1]==0 && __TRANS_thread_running[2]==0 && __TRANS_thread_running[3]==0);
}

void __VERIFIER_atomic_TRANS_task_compute_leave_thread() {
__CPROVER_assume(__TRANS_thread_running[1]==0 && __TRANS_thread_running[2]==0 && __TRANS_thread_running[3]==0);
__TRANS_thread_running[0]=0;
__CPROVER_assume(__TRANS_thread_running[1]==0 && __TRANS_thread_running[2]==0 && __TRANS_thread_running[3]==0);
}


void __VERIFIER_atomic_TRANS_atomic_assume_task_RR_Wheel(void) {
__CPROVER_assume(__TRANS_thread_running[2]==0 && __TRANS_thread_running[3]==0);
}

void TRANS_atomic_assume_task_RR_Wheel(void) {
__CPROVER_assume(__TRANS_thread_running[2]==0 && __TRANS_thread_running[3]==0);
}

void __VERIFIER_atomic_TRANS_task_RR_Wheel_enter_thread() {
__CPROVER_assume(__TRANS_thread_running[2]==0 && __TRANS_thread_running[3]==0);
__TRANS_thread_running[1]=1;
__CPROVER_assume(__TRANS_thread_running[2]==0 && __TRANS_thread_running[3]==0);
}

void __VERIFIER_atomic_TRANS_task_RR_Wheel_leave_thread() {
__CPROVER_assume(__TRANS_thread_running[2]==0 && __TRANS_thread_running[3]==0);
__TRANS_thread_running[1]=0;
__CPROVER_assume(__TRANS_thread_running[2]==0 && __TRANS_thread_running[3]==0);
}


void __VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel(void) {
__CPROVER_assume(__TRANS_thread_running[1]==0 && __TRANS_thread_running[3]==0);
}

void TRANS_atomic_assume_task_FL_Wheel(void) {
__CPROVER_assume(__TRANS_thread_running[1]==0 && __TRANS_thread_running[3]==0);
}

void __VERIFIER_atomic_TRANS_task_FL_Wheel_enter_thread() {
__CPROVER_assume(__TRANS_thread_running[1]==0 && __TRANS_thread_running[3]==0);
__TRANS_thread_running[2]=1;
__CPROVER_assume(__TRANS_thread_running[1]==0 && __TRANS_thread_running[3]==0);
}

void __VERIFIER_atomic_TRANS_task_FL_Wheel_leave_thread() {
__CPROVER_assume(__TRANS_thread_running[1]==0 && __TRANS_thread_running[3]==0);
__TRANS_thread_running[2]=0;
__CPROVER_assume(__TRANS_thread_running[1]==0 && __TRANS_thread_running[3]==0);
}


void __VERIFIER_atomic_TRANS_atomic_assume_task_FR_Wheel(void) {
__CPROVER_assume(__TRANS_thread_running[1]==0 && __TRANS_thread_running[2]==0);
}

void TRANS_atomic_assume_task_FR_Wheel(void) {
__CPROVER_assume(__TRANS_thread_running[1]==0 && __TRANS_thread_running[2]==0);
}

void __VERIFIER_atomic_TRANS_task_FR_Wheel_enter_thread() {
__CPROVER_assume(__TRANS_thread_running[1]==0 && __TRANS_thread_running[2]==0);
__TRANS_thread_running[3]=1;
__CPROVER_assume(__TRANS_thread_running[1]==0 && __TRANS_thread_running[2]==0);
}

void __VERIFIER_atomic_TRANS_task_FR_Wheel_leave_thread() {
__CPROVER_assume(__TRANS_thread_running[1]==0 && __TRANS_thread_running[2]==0);
__TRANS_thread_running[3]=0;
__CPROVER_assume(__TRANS_thread_running[1]==0 && __TRANS_thread_running[2]==0);
}


/* 
 * Copyright 2012 The MathWorks, Inc.
 *
 * File: rt_main.c
 *
 * Abstract:
 *
 *   A real-time main that runs generated Simulink Coder code under most 
 *   operating systems.  Based on the definition of MULTITASKING, a single-task 
 *   or multitask step function is employed.
 *
 *   This file is a useful starting point for creating a custom main when 
 *   targeting a custom floating point processor or integer micro-controller.
 *
 *   Alternatively for ERT targets, you can generate a sample ert_main.c file 
 *   with the generated code by selecting the "Generate an example main program"
 *   option.  In this case, ert_main.c is precisely customized to the
 *   model requirements.  
 *
 * Required Defines:
 *
 *   MODEL - Model name
 *   NUMST - Number of sample times
 *
 */

#include <stdio.h>
#include <assert.h>

//#ifdef CBMC
#include "brake_acc_nodiv_ctrl.c"
#include "brake_acc_nodiv_ctrl_data.c"
#include "rtGetNaN.c"
#include "rtGetInf.c"
#include "rt_nonfinite.c"
#include "cbmc-math.c"
//#else
//#include "brake_acc_nodiv_ctrl.h"
//#endif

// Lihao
//int test;

#define MODEL brake_acc_nodiv_ctrl
#define NUMST 4

/*==================*
 * Required defines *
 *==================*/

#ifndef MODEL
# error Must specify a model name.  Define MODEL=name.
#else
/* create generic macros that work with any model */
# define EXPAND_CONCAT(name1,name2) name1 ## name2
# define CONCAT(name1,name2) EXPAND_CONCAT(name1,name2)
# define MODEL_INITIALIZE CONCAT(MODEL,_initialize)
# define MODEL_STEP       CONCAT(MODEL,_step)
# define MODEL_TERMINATE  CONCAT(MODEL,_terminate)
# define RT_MDL           CONCAT(MODEL,_M)
#endif

#if defined(TID01EQ) && TID01EQ == 1
#define FIRST_TID 1
#else 
#define FIRST_TID 0
#endif

/*====================*
 * External functions *
 *====================*/

extern void MODEL_INITIALIZE(void);
extern void MODEL_TERMINATE(void);
extern void MODEL_STEP(int_T tid);  /* multirate step function */


/*===================*
 * Visible functions *
 *===================*/

/* Function: rtOneStep ========================================================
 *
 * Abstract:
 *   Perform one step of the model.  This function is modeled such that
 *   it could be called from an interrupt service routine (ISR) with minor
 *   modifications.
 *
 *   Note that error checking is only necessary when this routine is
 *   attached to an interrupt.
 *
 *   Also, you may wish to unroll any or all of for and while loops to
 *   improve the real-time performance of this function.
 */
static void rt_OneStep(void)
{
    int_T i;

    /*******************************************
     * Step the model for the base sample time *
     *******************************************/
    MODEL_STEP(0);

    /*********************************************************
     * Step the model for any other sample times (subrates) *
     *********************************************************/
    for (i = FIRST_TID+1; i < NUMST; i++) {

      /******************************************
       * Step the model for sample time "i" *
       ******************************************/
      MODEL_STEP(i);
    }

} /* end rtOneStep */

/* Function: rt_InitModel ====================================================
 * 
 * Abstract: 
 *   Initialized the model and the overrun flags
 *
 */
void rt_InitModel(void)
{
    MODEL_INITIALIZE();
}

/* Function: rt_TermModel ====================================================
 * 
 * Abstract:
 *   Terminates the model and prints the error status
 *
 */
int_T rt_TermModel(void)
{
    MODEL_TERMINATE();
    return(0);
}

#if 0
void printState() {
  printf("state = {\n");
  printf("  RT2_Buffer0 = %f\n",brake_acc_nodiv_ctrl_DW.RT2_Buffer0);
  printf("  RT4_Buffer0 = %f\n",brake_acc_nodiv_ctrl_DW.RT4_Buffer0);
  printf("  RT1_Buffer0 = %f\n",brake_acc_nodiv_ctrl_DW.RT1_Buffer0);
  printf("  RT3_Buffer0 = %f\n",brake_acc_nodiv_ctrl_DW.RT3_Buffer0);
  printf("}\n");
}

void printOutputs() {
  printf("outputs = {\n");
  printf("  Out_TQ_RRBrake = %f\n",brake_acc_nodiv_ctrl_Y.Out_TQ_RRBrake);
  printf("  Out_TQ_RLBrake = %f\n",brake_acc_nodiv_ctrl_Y.Out_TQ_RLBrake);
  printf("  Out_TQ_FRBrake = %f\n",brake_acc_nodiv_ctrl_Y.Out_TQ_FRBrake);
  printf("  Out_TQ_FLBrake = %f\n",brake_acc_nodiv_ctrl_Y.Out_TQ_FLBrake);
  printf("}\n");
}

void printInputs() {
  printf("inputs = {\n");
  printf("  In_BrakePedal = %f\n",brake_acc_nodiv_ctrl_U.In_BrakePedal);
  printf("  In_RRRotation = %f\n",brake_acc_nodiv_ctrl_U.In_RRRotation);
  printf("  In_RLRotation = %f\n",brake_acc_nodiv_ctrl_U.In_RLRotation);
  printf("  In_FRRotation = %f\n",brake_acc_nodiv_ctrl_U.In_FRRotation);
  printf("  In_FLRotation = %f\n",brake_acc_nodiv_ctrl_U.In_FLRotation);
  printf("}\n");
}
#endif

void havocInputs(ExtU_brake_acc_nodiv_ctrl_T *_inputs) {
  ExtU_brake_acc_nodiv_ctrl_T inputs; 

//#ifdef CBMC
  __CPROVER_assume(0<=inputs.In_BrakePedal && inputs.In_BrakePedal<=100 &&
              -10000<=inputs.In_RRRotation && inputs.In_RRRotation <= 10000 &&
              -10000<=inputs.In_RLRotation && inputs.In_RLRotation <= 10000 &&
              -10000<=inputs.In_FRRotation && inputs.In_FRRotation <= 10000 &&
              -10000<=inputs.In_FLRotation && inputs.In_FLRotation <= 10000);
//#endif

  *_inputs = inputs;
}

/* Split in separate tasks
   Lihao
*/

//Lihao
const int __CPROVER_thread_priorities[] = {5, 5, 5, 5, 22};
const char* __CPROVER_threads[] = {"c::task_RR_Wheel", "c::task_FR_Wheel",
  "c::task_FL_Wheel", "c::task_RL_Wheel", "c::task_compute"};

void task_RR_Wheel(void);
void task_RL_Wheel(void);
void task_FR_Wheel(void);
void task_FL_Wheel(void);

void task_compute(void) {
__VERIFIER_atomic_TRANS_task_compute_enter_thread();

//#if 0
__CPROVER_atomic_begin();
  B_brake_acc_nodiv_ctrl_T brake_acc_nodiv_ctrl_B_local;

  /* Start for RateTransition: '<Root>/RT' */
  brake_acc_nodiv_ctrl_B_local.RT_h = brake_acc_nodiv_ctrl_P.RT_X0;

  /* Start for RateTransition: '<Root>/RT4' */
  brake_acc_nodiv_ctrl_B_local.RT4 = brake_acc_nodiv_ctrl_P.RT4_X0;

  /* Start for RateTransition: '<Root>/RT1' */
  brake_acc_nodiv_ctrl_B_local.RT1 = brake_acc_nodiv_ctrl_P.RT1_X0;

  /* Start for RateTransition: '<Root>/RT2' */
  brake_acc_nodiv_ctrl_B_local.RT2 = brake_acc_nodiv_ctrl_P.RT2_X0;

  /* Start for RateTransition: '<Root>/RT3' */
  brake_acc_nodiv_ctrl_B_local.RT3 = brake_acc_nodiv_ctrl_P.RT3_X0;

  //B_brake_acc_nodiv_ctrl_T brake_acc_nodiv_ctrl_B_local = brake_acc_nodiv_ctrl_B;

__CPROVER_atomic_end();
//#endif

  //test = 0;

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
__VERIFIER_atomic_TRANS_task_compute_leave_thread();
}

void task_RR_Wheel(void) {  
__VERIFIER_atomic_TRANS_atomic_assume_task_RR_Wheel();
__VERIFIER_atomic_TRANS_task_RR_Wheel_enter_thread();


//#if 0
__VERIFIER_atomic_TRANS_atomic_assume_task_RR_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_RR_Wheel();
  B_brake_acc_nodiv_ctrl_T brake_acc_nodiv_ctrl_B_local;

  /* Start for RateTransition: '<Root>/RT' */
  brake_acc_nodiv_ctrl_B_local.RT_h = brake_acc_nodiv_ctrl_P.RT_X0;

  /* Start for RateTransition: '<Root>/RT4' */
  brake_acc_nodiv_ctrl_B_local.RT4 = brake_acc_nodiv_ctrl_P.RT4_X0;

  /* Start for RateTransition: '<Root>/RT1' */
  brake_acc_nodiv_ctrl_B_local.RT1 = brake_acc_nodiv_ctrl_P.RT1_X0;

  /* Start for RateTransition: '<Root>/RT2' */
  brake_acc_nodiv_ctrl_B_local.RT2 = brake_acc_nodiv_ctrl_P.RT2_X0;

  /* Start for RateTransition: '<Root>/RT3' */
  brake_acc_nodiv_ctrl_B_local.RT3 = brake_acc_nodiv_ctrl_P.RT3_X0;

  //B_brake_acc_nodiv_ctrl_T brake_acc_nodiv_ctrl_B_local = brake_acc_nodiv_ctrl_B;
TRANS_atomic_assume_task_RR_Wheel();
__CPROVER_atomic_end();
//#endif

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

__VERIFIER_atomic_TRANS_atomic_assume_task_RR_Wheel();
__VERIFIER_atomic_TRANS_task_RR_Wheel_leave_thread();
}

void task_FL_Wheel(void) {  
__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
__VERIFIER_atomic_TRANS_task_FL_Wheel_enter_thread();

//#if 0
__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FL_Wheel();
  B_brake_acc_nodiv_ctrl_T brake_acc_nodiv_ctrl_B_local;

  /* Start for RateTransition: '<Root>/RT' */
  brake_acc_nodiv_ctrl_B_local.RT_h = brake_acc_nodiv_ctrl_P.RT_X0;

  /* Start for RateTransition: '<Root>/RT4' */
  brake_acc_nodiv_ctrl_B_local.RT4 = brake_acc_nodiv_ctrl_P.RT4_X0;

  /* Start for RateTransition: '<Root>/RT1' */
  brake_acc_nodiv_ctrl_B_local.RT1 = brake_acc_nodiv_ctrl_P.RT1_X0;

  /* Start for RateTransition: '<Root>/RT2' */
  brake_acc_nodiv_ctrl_B_local.RT2 = brake_acc_nodiv_ctrl_P.RT2_X0;

  /* Start for RateTransition: '<Root>/RT3' */
  brake_acc_nodiv_ctrl_B_local.RT3 = brake_acc_nodiv_ctrl_P.RT3_X0;

  //B_brake_acc_nodiv_ctrl_T brake_acc_nodiv_ctrl_B_local = brake_acc_nodiv_ctrl_B;
TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_end();

//#endif

  //brake_acc_nodiv_ctrl_step1 // the following code is from this function

__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FL_Wheel();
  real_T rtb_to_int1;
TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_end();

__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FL_Wheel();
  real_T tmp;
TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_end();


  /* Rounding: '<S9>/to_int1' incorporates:
   *  Inport: '<Root>/In_FLRotation'
   */
__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FL_Wheel();
  rtb_to_int1 = rt_roundd_snf(brake_acc_nodiv_ctrl_U.In_FLRotation);
TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_end();


  /* RateTransition: '<Root>/RT' */
__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FL_Wheel();
  brake_acc_nodiv_ctrl_B_local.RT_h = RT_Buffer0;
TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_end();


  /* RateTransition: '<Root>/RT4' */
__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FL_Wheel();
  brake_acc_nodiv_ctrl_B_local.RT4 = RT4_Buffer0;
TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_end();


  // inline
  /* S-Function (fcncallgen): '<Root>/10ms_4' incorporates:
   *  SubSystem: '<Root>/ABS_FL_Wheel'
   */
  //brake_acc_nodiv_ct_ABS_RR_Wheel(brake_acc_nodiv_ctrl_B_local.RT4,
  //  brake_acc_nodiv_ctrl_B_local.RT3, rtb_to_int1,
  //  &brake_acc_nodiv_ctrl_B_local.ABS_FL_Wheel, //(P_ABS_RR_Wheel_brake_acc_nodi_T *)
  //  brake_acc_nodiv_ctrl_P.ABS_FL_Wheel);

  /* local block i/o variables */
__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FL_Wheel();
  boolean_T rtb_RelationalOperator;
TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_end();

__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FL_Wheel();
  real_T rtb_vms;
TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_end();

__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FL_Wheel();
  real_T u;
TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_end();


  /* Outputs for Atomic SubSystem: '<S4>/If v>=10 km//h' */
  /* Gain: '<S29>/v (m//s)' */
__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FL_Wheel();
  rtb_vms = brake_acc_nodiv_ctrl_P.ABS_FL_Wheel.vms_Gain * brake_acc_nodiv_ctrl_B_local.RT4;
TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_end();


  /* Sum: '<S29>/Subtract' incorporates:
   *  Gain: '<S29>/wheSpd (m//s)'
   */
__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FL_Wheel();
  u = rtb_vms - brake_acc_nodiv_ctrl_P.ABS_FL_Wheel.wheSpdms_Gain * rtb_to_int1;
TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_end();


  /* Saturate: '<S29>/positive' */
  // Lihao: lift
__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FL_Wheel();
  real_T positive_UpperSat_local = brake_acc_nodiv_ctrl_P.ABS_FL_Wheel.positive_UpperSat;
TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_end();

__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
  if (u >= positive_UpperSat_local) {
__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FL_Wheel();
    u = brake_acc_nodiv_ctrl_P.ABS_FL_Wheel.positive_UpperSat;
TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_end();

__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
  } else {
    // Lihao: lift
__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FL_Wheel();
    real_T positive_LowerSat_local = brake_acc_nodiv_ctrl_P.ABS_FL_Wheel.positive_LowerSat;
TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_end();

__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
    if (u <= positive_LowerSat_local) {
__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FL_Wheel();
      u = brake_acc_nodiv_ctrl_P.ABS_FL_Wheel.positive_LowerSat;
TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_end();

__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
    }
__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
  }

  /* RelationalOperator: '<S29>/Relational Operator' incorporates:
   *  Gain: '<S29>/slip_abs_on_times_10'
   *  Gain: '<S29>/times_10'
   *  Saturate: '<S29>/positive'
   */
__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FL_Wheel();
  rtb_RelationalOperator = (brake_acc_nodiv_ctrl_P.ABS_FL_Wheel.times_10_Gain * u >
   brake_acc_nodiv_ctrl_P.ABS_FL_Wheel.slip_abs_on_times_10_Gain * rtb_vms);
TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_end();


  /* Switch: '<S4>/Threshold_10km//h' */
  // Lihao: lift
__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FL_Wheel();
  real_T Threshold_10kmh_Threshold_local = brake_acc_nodiv_ctrl_P.ABS_FL_Wheel.Threshold_10kmh_Threshold;
TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_end();

__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
  if (brake_acc_nodiv_ctrl_B_local.RT4 >= Threshold_10kmh_Threshold_local) {
    /* Outputs for Atomic SubSystem: '<S4>/If v>=10 km//h' */
    /* Switch: '<S29>/LockDetect' incorporates:
     *  Constant: '<S29>/ReleaseBrake'
     */
__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
    if (rtb_RelationalOperator) {
__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FL_Wheel();
      brake_acc_nodiv_ctrl_B_local.ABS_FL_Wheel.Threshold_10kmh = brake_acc_nodiv_ctrl_P.ABS_FL_Wheel.ReleaseBrake_Value;
TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_end();

__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
    } else {
__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FL_Wheel();
      brake_acc_nodiv_ctrl_B_local.ABS_FL_Wheel.Threshold_10kmh = brake_acc_nodiv_ctrl_B_local.RT3;
TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_end();

__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
    }

    /* End of Outputs for SubSystem: '<S4>/If v>=10 km//h' */
__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
  } else {
    /* Outputs for Atomic SubSystem: '<S4>/If v>=10 km//h' */
    /* Switch: '<S29>/LockDetect' */
__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FL_Wheel();
    brake_acc_nodiv_ctrl_B_local.ABS_FL_Wheel.Threshold_10kmh = brake_acc_nodiv_ctrl_B_local.RT3;
TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_end();


    /* End of Outputs for SubSystem: '<S4>/If v>=10 km//h' */
__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
  }

  /* End of Switch: '<S4>/Threshold_10km//h' */
  // end of inline

  /* Outport: '<Root>/Out_TQ_FLBrake' */
  //brake_acc_nodiv_ctrl_Y.Out_TQ_FLBrake =
  //  brake_acc_nodiv_ctrl_B_local.ABS_FL_Wheel.Threshold_10kmh;

  /* Saturate: '<S7>/Pedal_map' incorporates:
   *  Inport: '<Root>/In_BrakePedal'
   */
  // Lihao: lift
__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FL_Wheel();
  real_T In_BrakePedal = brake_acc_nodiv_ctrl_U.In_BrakePedal;
TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_end();

__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FL_Wheel();
  real_T Pedal_map_UpperSat = brake_acc_nodiv_ctrl_P.Pedal_map_UpperSat;
TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_end();

__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
  if (In_BrakePedal >= Pedal_map_UpperSat) {
__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FL_Wheel();
    tmp = brake_acc_nodiv_ctrl_P.Pedal_map_UpperSat;
TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_end();

__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
  } else {
    // Lihao: lift
__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FL_Wheel();
    In_BrakePedal = brake_acc_nodiv_ctrl_U.In_BrakePedal;
TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_end();

__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FL_Wheel();
    real_T Pedal_map_LowerSat = brake_acc_nodiv_ctrl_P.Pedal_map_LowerSat;
TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_end();

__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
    if (In_BrakePedal <= Pedal_map_LowerSat) {
__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FL_Wheel();
      tmp = brake_acc_nodiv_ctrl_P.Pedal_map_LowerSat;
TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_end();

__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
    } else {
__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FL_Wheel();
      tmp = brake_acc_nodiv_ctrl_U.In_BrakePedal;
TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_end();

__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
    }
__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
  }

  /* S-Function (fcncallgen): '<Root>/10ms' incorporates:
   *  SubSystem: '<Root>/Brake_Torq_Calculation'
   */
__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FL_Wheel();
  RT14 = brake_acc_nodiv_ctrl_P.Gain1_Gain *
   rt_roundd_snf(tmp);
TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_end();


  /* RateTransition: '<Root>/RT12' */
__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FL_Wheel();
  RT12 = rtb_to_int1;
TRANS_atomic_assume_task_FL_Wheel();
__CPROVER_atomic_end();

__VERIFIER_atomic_TRANS_atomic_assume_task_FL_Wheel();
__VERIFIER_atomic_TRANS_task_FL_Wheel_leave_thread();
}

void task_FR_Wheel(void)
{  
__VERIFIER_atomic_TRANS_atomic_assume_task_FR_Wheel();
__VERIFIER_atomic_TRANS_task_FR_Wheel_enter_thread();

//#if 0 
__VERIFIER_atomic_TRANS_atomic_assume_task_FR_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FR_Wheel();
  B_brake_acc_nodiv_ctrl_T brake_acc_nodiv_ctrl_B_local;

  /* Start for RateTransition: '<Root>/RT' */
  brake_acc_nodiv_ctrl_B_local.RT_h = brake_acc_nodiv_ctrl_P.RT_X0;

  /* Start for RateTransition: '<Root>/RT4' */
  brake_acc_nodiv_ctrl_B_local.RT4 = brake_acc_nodiv_ctrl_P.RT4_X0;

  /* Start for RateTransition: '<Root>/RT1' */
  brake_acc_nodiv_ctrl_B_local.RT1 = brake_acc_nodiv_ctrl_P.RT1_X0;

  /* Start for RateTransition: '<Root>/RT2' */
  brake_acc_nodiv_ctrl_B_local.RT2 = brake_acc_nodiv_ctrl_P.RT2_X0;

  /* Start for RateTransition: '<Root>/RT3' */
  brake_acc_nodiv_ctrl_B_local.RT3 = brake_acc_nodiv_ctrl_P.RT3_X0;

  //B_brake_acc_nodiv_ctrl_T brake_acc_nodiv_ctrl_B_local = brake_acc_nodiv_ctrl_B;
TRANS_atomic_assume_task_FR_Wheel();
__CPROVER_atomic_end();
//#endif

  //brake_acc_nodiv_ctrl_step1 // the following code is from this function

__VERIFIER_atomic_TRANS_atomic_assume_task_FR_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FR_Wheel();
  real_T rtb_to_int_k;
TRANS_atomic_assume_task_FR_Wheel();
__CPROVER_atomic_end();


  /* RateTransition: '<Root>/RT4' */
__VERIFIER_atomic_TRANS_atomic_assume_task_FR_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FR_Wheel();
  brake_acc_nodiv_ctrl_B_local.RT4 = RT4_Buffer0;
TRANS_atomic_assume_task_FR_Wheel();
__CPROVER_atomic_end();


  /* Rounding: '<S11>/to_int' incorporates:
   *  Inport: '<Root>/In_FRRotation'
   */
__VERIFIER_atomic_TRANS_atomic_assume_task_FR_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FR_Wheel();
  rtb_to_int_k = rt_roundd_snf(brake_acc_nodiv_ctrl_U.In_FRRotation);
TRANS_atomic_assume_task_FR_Wheel();
__CPROVER_atomic_end();


  // inline
  /* S-Function (fcncallgen): '<Root>/10ms_3' incorporates:
   *  SubSystem: '<Root>/ABS_FR_Wheel'
   */
  //brake_acc_nodiv_ct_ABS_RR_Wheel(brake_acc_nodiv_ctrl_B_local.RT4,
  //  brake_acc_nodiv_ctrl_B_local.RT2, rtb_to_int_k,
  //  &brake_acc_nodiv_ctrl_B_local.ABS_FR_Wheel, //(P_ABS_RR_Wheel_brake_acc_nodi_T *)
  //  brake_acc_nodiv_ctrl_P.ABS_FR_Wheel);

  /* local block i/o variables */
__VERIFIER_atomic_TRANS_atomic_assume_task_FR_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FR_Wheel();
  boolean_T rtb_RelationalOperator;
TRANS_atomic_assume_task_FR_Wheel();
__CPROVER_atomic_end();

__VERIFIER_atomic_TRANS_atomic_assume_task_FR_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FR_Wheel();
  real_T rtb_vms;
TRANS_atomic_assume_task_FR_Wheel();
__CPROVER_atomic_end();

__VERIFIER_atomic_TRANS_atomic_assume_task_FR_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FR_Wheel();
  real_T u;
TRANS_atomic_assume_task_FR_Wheel();
__CPROVER_atomic_end();


  /* Outputs for Atomic SubSystem: '<S4>/If v>=10 km//h' */
  /* Gain: '<S29>/v (m//s)' */
__VERIFIER_atomic_TRANS_atomic_assume_task_FR_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FR_Wheel();
  rtb_vms = brake_acc_nodiv_ctrl_P.ABS_FR_Wheel.vms_Gain * brake_acc_nodiv_ctrl_B_local.RT4;
TRANS_atomic_assume_task_FR_Wheel();
__CPROVER_atomic_end();


  /* Sum: '<S29>/Subtract' incorporates:
   *  Gain: '<S29>/wheSpd (m//s)'
   */
__VERIFIER_atomic_TRANS_atomic_assume_task_FR_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FR_Wheel();
  u = rtb_vms - brake_acc_nodiv_ctrl_P.ABS_FR_Wheel.wheSpdms_Gain * rtb_to_int_k;
TRANS_atomic_assume_task_FR_Wheel();
__CPROVER_atomic_end();


  /* Saturate: '<S29>/positive' */
  // Lihao: lift
__VERIFIER_atomic_TRANS_atomic_assume_task_FR_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FR_Wheel();
  real_T positive_UpperSat_local = brake_acc_nodiv_ctrl_P.ABS_FR_Wheel.positive_UpperSat;
TRANS_atomic_assume_task_FR_Wheel();
__CPROVER_atomic_end();

__VERIFIER_atomic_TRANS_atomic_assume_task_FR_Wheel();
  if (u >= positive_UpperSat_local) {
__VERIFIER_atomic_TRANS_atomic_assume_task_FR_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FR_Wheel();
    u = brake_acc_nodiv_ctrl_P.ABS_FR_Wheel.positive_UpperSat;
TRANS_atomic_assume_task_FR_Wheel();
__CPROVER_atomic_end();

__VERIFIER_atomic_TRANS_atomic_assume_task_FR_Wheel();
  } else {
    // Lihao: lift
__VERIFIER_atomic_TRANS_atomic_assume_task_FR_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FR_Wheel();
    real_T positive_LowerSat_local = brake_acc_nodiv_ctrl_P.ABS_FR_Wheel.positive_LowerSat;
TRANS_atomic_assume_task_FR_Wheel();
__CPROVER_atomic_end();

__VERIFIER_atomic_TRANS_atomic_assume_task_FR_Wheel();
    if (u <= positive_LowerSat_local) {
__VERIFIER_atomic_TRANS_atomic_assume_task_FR_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FR_Wheel();
      u = brake_acc_nodiv_ctrl_P.ABS_FR_Wheel.positive_LowerSat;
TRANS_atomic_assume_task_FR_Wheel();
__CPROVER_atomic_end();

__VERIFIER_atomic_TRANS_atomic_assume_task_FR_Wheel();
    }
__VERIFIER_atomic_TRANS_atomic_assume_task_FR_Wheel();
  }

  /* RelationalOperator: '<S29>/Relational Operator' incorporates:
   *  Gain: '<S29>/slip_abs_on_times_10'
   *  Gain: '<S29>/times_10'
   *  Saturate: '<S29>/positive'
   */
__VERIFIER_atomic_TRANS_atomic_assume_task_FR_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FR_Wheel();
  rtb_RelationalOperator = (brake_acc_nodiv_ctrl_P.ABS_FR_Wheel.times_10_Gain * u >
   brake_acc_nodiv_ctrl_P.ABS_FR_Wheel.slip_abs_on_times_10_Gain * rtb_vms);
TRANS_atomic_assume_task_FR_Wheel();
__CPROVER_atomic_end();


  /* Switch: '<S4>/Threshold_10km//h' */
  // Lihao: lift
__VERIFIER_atomic_TRANS_atomic_assume_task_FR_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FR_Wheel();
  real_T Threshold_10kmh_Threshold_local = brake_acc_nodiv_ctrl_P.ABS_FR_Wheel.Threshold_10kmh_Threshold;
TRANS_atomic_assume_task_FR_Wheel();
__CPROVER_atomic_end();

__VERIFIER_atomic_TRANS_atomic_assume_task_FR_Wheel();
  if (brake_acc_nodiv_ctrl_B_local.RT4 >= Threshold_10kmh_Threshold_local) {
    /* Outputs for Atomic SubSystem: '<S4>/If v>=10 km//h' */
    /* Switch: '<S29>/LockDetect' incorporates:
     *  Constant: '<S29>/ReleaseBrake'
     */
__VERIFIER_atomic_TRANS_atomic_assume_task_FR_Wheel();
    if (rtb_RelationalOperator) {
__VERIFIER_atomic_TRANS_atomic_assume_task_FR_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FR_Wheel();
      brake_acc_nodiv_ctrl_B_local.ABS_FR_Wheel.Threshold_10kmh = brake_acc_nodiv_ctrl_P.ABS_FR_Wheel.ReleaseBrake_Value;
TRANS_atomic_assume_task_FR_Wheel();
__CPROVER_atomic_end();

__VERIFIER_atomic_TRANS_atomic_assume_task_FR_Wheel();
    } else {
__VERIFIER_atomic_TRANS_atomic_assume_task_FR_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FR_Wheel();
      brake_acc_nodiv_ctrl_B_local.ABS_FR_Wheel.Threshold_10kmh = brake_acc_nodiv_ctrl_B_local.RT2;
TRANS_atomic_assume_task_FR_Wheel();
__CPROVER_atomic_end();

__VERIFIER_atomic_TRANS_atomic_assume_task_FR_Wheel();
    }

    /* End of Outputs for SubSystem: '<S4>/If v>=10 km//h' */
__VERIFIER_atomic_TRANS_atomic_assume_task_FR_Wheel();
  } else {
    /* Outputs for Atomic SubSystem: '<S4>/If v>=10 km//h' */
    /* Switch: '<S29>/LockDetect' */
__VERIFIER_atomic_TRANS_atomic_assume_task_FR_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FR_Wheel();
    brake_acc_nodiv_ctrl_B_local.ABS_FR_Wheel.Threshold_10kmh = brake_acc_nodiv_ctrl_B_local.RT2;
TRANS_atomic_assume_task_FR_Wheel();
__CPROVER_atomic_end();


    /* End of Outputs for SubSystem: '<S4>/If v>=10 km//h' */
__VERIFIER_atomic_TRANS_atomic_assume_task_FR_Wheel();
  }

  /* End of Switch: '<S4>/Threshold_10km//h' */
  // end of inline

  /* Outport: '<Root>/Out_TQ_FRBrake' */
  //brake_acc_nodiv_ctrl_Y.Out_TQ_FRBrake =
  //  brake_acc_nodiv_ctrl_B_local.ABS_FR_Wheel.Threshold_10kmh;

  /* RateTransition: '<Root>/RT3' */
__VERIFIER_atomic_TRANS_atomic_assume_task_FR_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FR_Wheel();
  brake_acc_nodiv_ctrl_B_local.RT3 = RT3_Buffer0;
TRANS_atomic_assume_task_FR_Wheel();
__CPROVER_atomic_end();


  /* End of RateTransition: '<Root>/RT3' */

  /* RateTransition: '<Root>/RT11' */
__VERIFIER_atomic_TRANS_atomic_assume_task_FR_Wheel();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_FR_Wheel();
  RT11 = rtb_to_int_k;
TRANS_atomic_assume_task_FR_Wheel();
__CPROVER_atomic_end();

__VERIFIER_atomic_TRANS_atomic_assume_task_FR_Wheel();
__VERIFIER_atomic_TRANS_task_FR_Wheel_leave_thread();
}

void task_RL_Wheel(void)
{  
//#if 0
  B_brake_acc_nodiv_ctrl_T brake_acc_nodiv_ctrl_B_local;

  /* Start for RateTransition: '<Root>/RT' */
  brake_acc_nodiv_ctrl_B_local.RT_h = brake_acc_nodiv_ctrl_P.RT_X0;

  /* Start for RateTransition: '<Root>/RT4' */
  brake_acc_nodiv_ctrl_B_local.RT4 = brake_acc_nodiv_ctrl_P.RT4_X0;

  /* Start for RateTransition: '<Root>/RT1' */
  brake_acc_nodiv_ctrl_B_local.RT1 = brake_acc_nodiv_ctrl_P.RT1_X0;

  /* Start for RateTransition: '<Root>/RT2' */
  brake_acc_nodiv_ctrl_B_local.RT2 = brake_acc_nodiv_ctrl_P.RT2_X0;

  /* Start for RateTransition: '<Root>/RT3' */
  brake_acc_nodiv_ctrl_B_local.RT3 = brake_acc_nodiv_ctrl_P.RT3_X0;

  //B_brake_acc_nodiv_ctrl_T brake_acc_nodiv_ctrl_B_local = brake_acc_nodiv_ctrl_B;
//#endif

  //brake_acc_nodiv_ctrl_step1 // the following code is from this function

  real_T rtb_to_int_g;

  /* RateTransition: '<Root>/RT4' */
  brake_acc_nodiv_ctrl_B_local.RT4 = RT4_Buffer0;

  // inline
  /* S-Function (fcncallgen): '<Root>/10ms_2' incorporates:
   *  SubSystem: '<Root>/ABS_RL_Wheel'
   */
  //brake_acc_nodiv_ct_ABS_RR_Wheel(brake_acc_nodiv_ctrl_B_local.RT4,
  //  brake_acc_nodiv_ctrl_B_local.RT1, rtb_to_int_g,
  //  &brake_acc_nodiv_ctrl_B_local.ABS_RL_Wheel, //(P_ABS_RR_Wheel_brake_acc_nodi_T *)
  //  brake_acc_nodiv_ctrl_P.ABS_RL_Wheel);

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
  // end of inline

  /* Outport: '<Root>/Out_TQ_RLBrake' */
  //brake_acc_nodiv_ctrl_Y.Out_TQ_RLBrake =
  //  brake_acc_nodiv_ctrl_B_local.ABS_RL_Wheel.Threshold_10kmh;

  /* RateTransition: '<Root>/RT2' */
  brake_acc_nodiv_ctrl_B_local.RT2 = RT2_Buffer0;

  /* End of RateTransition: '<Root>/RT2' */

  /* RateTransition: '<Root>/RT10' */
  RT10 = rtb_to_int_g;
}


/* Function: main =============================================================
 *
 * Abstract:
 *   Execute model on a generic target such as a workstation.
 */
int_T main(int_T argc, const char *argv[])
{
  rt_InitModel();

#if 0
  while (1) 
  {
#endif

    havocInputs(&brake_acc_nodiv_ctrl_U);

    //Lihao
    __CPROVER_ASYNC_1:
    task_compute();
    __CPROVER_ASYNC_1:
    task_RR_Wheel();
    __CPROVER_ASYNC_1:
    task_FL_Wheel();
    __CPROVER_ASYNC_1:
    task_FR_Wheel();
    //__CPROVER_ASYNC_1:
    //task_RL_Wheel();

#if 0
    printInputs();

    rt_OneStep();

    printState();
    printOutputs();
  }
#endif

  const int_T result = rt_TermModel();
  return result;
}

/* [EOF] rt_main.c */
