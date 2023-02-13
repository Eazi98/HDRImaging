/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: testSimulink.h
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

#ifndef RTW_HEADER_testSimulink_h_
#define RTW_HEADER_testSimulink_h_
#ifndef testSimulink_COMMON_INCLUDES_
#define testSimulink_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "driver_android_fromapp.h"
#include "driver_android_toapp.h"
#include "driver_android_videodisplay.h"
#endif                                 /* testSimulink_COMMON_INCLUDES_ */

#include "testSimulink_types.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T unusedExpr[268435455];
} B_testSimulink_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_internal_androidF_T obj; /* '<S1>/FromApp' */
} DW_testSimulink_T;

/* Real-time Model Data Structure */
struct tag_RTM_testSimulink_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_testSimulink_T testSimulink_B;

/* Block states (default storage) */
extern DW_testSimulink_T testSimulink_DW;

/* External data declarations for dependent source files */
extern const real_T testSimulink_RGND; /* real_T ground */

/* Model entry point functions */
extern void testSimulink_initialize(void);
extern void testSimulink_step(void);
extern void testSimulink_terminate(void);

/* Real-time Model object */
extern RT_MODEL_testSimulink_T *const testSimulink_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'testSimulink'
 * '<S1>'   : 'testSimulink/FromApp'
 * '<S2>'   : 'testSimulink/MATLAB Function3'
 * '<S3>'   : 'testSimulink/Video Display'
 */
#endif                                 /* RTW_HEADER_testSimulink_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
