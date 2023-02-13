/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: testSimulink.c
 *
 * Code generated for Simulink model 'testSimulink'.
 *
 * Model version                  : 1.94
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Feb 13 21:51:36 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "testSimulink.h"
#include "rtwtypes.h"

const real_T testSimulink_RGND = 0.0;  /* real_T ground */

/* Block signals (default storage) */
B_testSimulink_T testSimulink_B;

/* Block states (default storage) */
DW_testSimulink_T testSimulink_DW;

/* Real-time model */
static RT_MODEL_testSimulink_T testSimulink_M_;
RT_MODEL_testSimulink_T *const testSimulink_M = &testSimulink_M_;

/* Forward declaration for local functions */
static void testSim_androidFromApp_stepImpl(real_T Data[268435455]);
static void testSimulink_SystemCore_step(real_T varargout_1[268435455]);
static void testSim_androidFromApp_stepImpl(real_T Data[268435455])
{
  int32_T i;
  char_T b_functionNameTerminated[14];
  static const char_T tmp[13] = { 'F', 'r', 'o', 'm', 'A', 'p', 'p', 'M', 'e',
    't', 'h', 'o', 'd' };

  for (i = 0; i < 13; i++) {
    b_functionNameTerminated[i] = tmp[i];
  }

  b_functionNameTerminated[13] = '\x00';
  GET_FROMAPP_DATA(&Data[0], &b_functionNameTerminated[0], 8, 268435455);
}

static void testSimulink_SystemCore_step(real_T varargout_1[268435455])
{
  testSim_androidFromApp_stepImpl(varargout_1);
}

/* Model step function */
void testSimulink_step(void)
{
  real_T u0[3];
  int32_T i;
  char_T b_functionNameTerminated[13];
  static const char_T tmp[12] = { 'T', 'o', 'A', 'p', 'p', 'M', 'e', 't', 'h',
    'o', 'd', 'R' };

  /* MATLABSystem: '<S1>/FromApp' */
  testSimulink_SystemCore_step(testSimulink_B.unusedExpr);

  /* MATLABSystem: '<Root>/ToApp' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function3'
   */
  u0[0] = 9.0;
  u0[1] = 9.0;
  u0[2] = 9.0;
  for (i = 0; i < 12; i++) {
    b_functionNameTerminated[i] = tmp[i];
  }

  b_functionNameTerminated[12] = '\x00';
  PUT_TOAPP_DATA(&b_functionNameTerminated[0], 1, &u0[0], 8, 3);

  /* End of MATLABSystem: '<Root>/ToApp' */

  /* MATLABSystem: '<S3>/Video Display' */
  PUT_VIDEO_DISPLAY_DATA(((const real_T*) &testSimulink_RGND), ((const real_T*)
    &testSimulink_RGND), ((const real_T*) &testSimulink_RGND));
}

/* Model initialize function */
void testSimulink_initialize(void)
{
  /* Start for MATLABSystem: '<S1>/FromApp' */
  testSimulink_DW.obj.isInitialized = 1;
  INITIALIZE_FROMAPP();

  /* Start for MATLABSystem: '<Root>/ToApp' */
  INITIALIZE_TOAPP();

  /* Start for MATLABSystem: '<S3>/Video Display' */
  INITIALIZE_VIDEO_DISPLAY(1, 1);
}

/* Model terminate function */
void testSimulink_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
