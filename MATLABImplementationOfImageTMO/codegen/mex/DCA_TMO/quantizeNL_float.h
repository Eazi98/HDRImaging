/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * quantizeNL_float.h
 *
 * Code generation for function 'quantizeNL_float'
 *
 */

#pragma once

/* Include files */
#include "DCA_TMO_types.h"
#include "rtwtypes.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void quantizeNL_float(const emlrtStack *sp, const emxArray_real_T *y,
                      const emxArray_real_T *lum, emxArray_real_T *labels,
                      real_T mdata[55], emxArray_real_T *edges);

/* End of code generation (quantizeNL_float.h) */
