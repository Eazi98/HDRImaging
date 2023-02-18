/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: HDRImaging.c
 *
 * Code generated for Simulink model 'HDRImaging'.
 *
 * Model version                  : 1.106
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sat Feb 18 15:27:52 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "HDRImaging.h"
#include "rtwtypes.h"

/* Block signals (default storage) */
B_HDRImaging_T HDRImaging_B;

/* Block states (default storage) */
DW_HDRImaging_T HDRImaging_DW;

/* Real-time model */
static RT_MODEL_HDRImaging_T HDRImaging_M_;
RT_MODEL_HDRImaging_T *const HDRImaging_M = &HDRImaging_M_;

/* Forward declaration for local functions */
static void HDRImag_androidFromApp_stepImpl(real_T Data[74649600]);
static void HDRImaging_SystemCore_step(real_T varargout_1[74649600]);
static void HDRImag_androidFromApp_stepImpl(real_T Data[74649600])
{
  int32_T i;
  char_T b_functionNameTerminated[14];
  static const char_T tmp[13] = { 'F', 'r', 'o', 'm', 'A', 'p', 'p', 'M', 'e',
    't', 'h', 'o', 'd' };

  for (i = 0; i < 13; i++) {
    b_functionNameTerminated[i] = tmp[i];
  }

  b_functionNameTerminated[13] = '\x00';
  GET_FROMAPP_DATA(&Data[0], &b_functionNameTerminated[0], 8, 74649600);
}

static void HDRImaging_SystemCore_step(real_T varargout_1[74649600])
{
  HDRImag_androidFromApp_stepImpl(varargout_1);
}

/* Model step function */
void HDRImaging_step(void)
{
  real_T u0[3];
  int32_T i;
  char_T b_functionNameTerminated[15];
  static const char_T tmp[14] = { 'C', 'o', 'n', 'v', 'e', 'r', 't', 'e', 'd',
    'A', 'r', 'r', 'a', 'y' };

  /* MATLABSystem: '<S1>/FromApp' */
  HDRImaging_SystemCore_step(HDRImaging_B.unusedExpr);

  /* MATLABSystem: '<Root>/ToApp' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function3'
   */
  u0[0] = 9.0;
  u0[1] = 9.0;
  u0[2] = 9.0;
  for (i = 0; i < 14; i++) {
    b_functionNameTerminated[i] = tmp[i];
  }

  b_functionNameTerminated[14] = '\x00';
  PUT_TOAPP_DATA(&b_functionNameTerminated[0], 1, &u0[0], 8, 3);

  /* End of MATLABSystem: '<Root>/ToApp' */
}

/* Model initialize function */
void HDRImaging_initialize(void)
{
  /* Start for MATLABSystem: '<S1>/FromApp' */
  HDRImaging_DW.obj.isInitialized = 1;
  INITIALIZE_FROMAPP();

  /* Start for MATLABSystem: '<Root>/ToApp' */
  INITIALIZE_TOAPP();
}

/* Model terminate function */
void HDRImaging_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
