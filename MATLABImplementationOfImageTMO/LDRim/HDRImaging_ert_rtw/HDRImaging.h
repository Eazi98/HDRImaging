/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: HDRImaging.h
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

#ifndef RTW_HEADER_HDRImaging_h_
#define RTW_HEADER_HDRImaging_h_
#ifndef HDRImaging_COMMON_INCLUDES_
#define HDRImaging_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "driver_android_fromapp.h"
#include "driver_android_toapp.h"
#endif                                 /* HDRImaging_COMMON_INCLUDES_ */

#include "HDRImaging_types.h"
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
  real_T unusedExpr[74649600];
} B_HDRImaging_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_internal_androidF_T obj; /* '<S1>/FromApp' */
} DW_HDRImaging_T;

/* Real-time Model Data Structure */
struct tag_RTM_HDRImaging_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_HDRImaging_T HDRImaging_B;

/* Block states (default storage) */
extern DW_HDRImaging_T HDRImaging_DW;

/* Model entry point functions */
extern void HDRImaging_initialize(void);
extern void HDRImaging_step(void);
extern void HDRImaging_terminate(void);

/* Real-time Model object */
extern RT_MODEL_HDRImaging_T *const HDRImaging_M;
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
 * '<Root>' : 'HDRImaging'
 * '<S1>'   : 'HDRImaging/FromApp'
 * '<S2>'   : 'HDRImaging/MATLAB Function3'
 */
#endif                                 /* RTW_HEADER_HDRImaging_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
