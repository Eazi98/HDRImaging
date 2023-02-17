/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: HDRImaging.c
 *
 * Code generated for Simulink model 'HDRImaging'.
 *
 * Model version                  : 1.99
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Feb 17 10:39:38 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "HDRImaging.h"
#include "rtwtypes.h"
#include "HDRImaging_private.h"
#include "HDRImaging_dt.h"

/* Block signals (default storage) */
B_HDRImaging_T HDRImaging_B;

/* Block states (default storage) */
DW_HDRImaging_T HDRImaging_DW;

/* Real-time model */
static RT_MODEL_HDRImaging_T HDRImaging_M_;
RT_MODEL_HDRImaging_T *const HDRImaging_M = &HDRImaging_M_;

/* Forward declaration for local functions */
static void HDRImag_androidFromApp_stepImpl(real_T Data[268435455]);
static void HDRImaging_SystemCore_step(real_T varargout_1[268435455]);
static void HDRImag_androidFromApp_stepImpl(real_T Data[268435455])
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

static void HDRImaging_SystemCore_step(real_T varargout_1[268435455])
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

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.1s, 0.0s] */
    rtExtModeUpload(0, (real_T)HDRImaging_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.1s, 0.0s] */
    if ((rtmGetTFinal(HDRImaging_M)!=-1) &&
        !((rtmGetTFinal(HDRImaging_M)-HDRImaging_M->Timing.taskTime0) >
          HDRImaging_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(HDRImaging_M, "Simulation finished");
    }

    if (rtmGetStopRequested(HDRImaging_M)) {
      rtmSetErrorStatus(HDRImaging_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  HDRImaging_M->Timing.taskTime0 =
    ((time_T)(++HDRImaging_M->Timing.clockTick0)) *
    HDRImaging_M->Timing.stepSize0;
}

/* Model initialize function */
void HDRImaging_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(HDRImaging_M, 10.0);
  HDRImaging_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  HDRImaging_M->Sizes.checksums[0] = (1554514001U);
  HDRImaging_M->Sizes.checksums[1] = (1768178964U);
  HDRImaging_M->Sizes.checksums[2] = (2663794637U);
  HDRImaging_M->Sizes.checksums[3] = (2852121085U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    HDRImaging_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(HDRImaging_M->extModeInfo,
      &HDRImaging_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(HDRImaging_M->extModeInfo, HDRImaging_M->Sizes.checksums);
    rteiSetTPtr(HDRImaging_M->extModeInfo, rtmGetTPtr(HDRImaging_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    HDRImaging_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 21;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;
  }

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
