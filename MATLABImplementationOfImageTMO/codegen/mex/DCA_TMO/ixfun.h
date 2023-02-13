/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ixfun.h
 *
 * Code generation for function 'ixfun'
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
void expand_fltpower_domain_error(const emlrtStack *sp,
                                  const emxArray_real_T *a,
                                  const emxArray_real_T *b,
                                  emxArray_boolean_T *c);

void expand_power(const emlrtStack *sp, const emxArray_real_T *a,
                  const emxArray_real_T *b, emxArray_real_T *c);

/* End of code generation (ixfun.h) */
