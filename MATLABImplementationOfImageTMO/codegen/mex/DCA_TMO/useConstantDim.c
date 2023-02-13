/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * useConstantDim.c
 *
 * Code generation for function 'useConstantDim'
 *
 */

/* Include files */
#include "useConstantDim.h"
#include "DCA_TMO_data.h"
#include "DCA_TMO_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void useConstantDim(emxArray_real_T *varargin_2)
{
  real_T *varargin_2_data;
  int32_T k;
  varargin_2_data = varargin_2->data;
  if ((varargin_2->size[1] != 0) &&
      ((varargin_2->size[1] != 0) && (varargin_2->size[1] != 1))) {
    int32_T i;
    i = varargin_2->size[1];
    for (k = 0; k <= i - 2; k++) {
      varargin_2_data[k + 1] += varargin_2_data[k];
    }
  }
}

/* End of code generation (useConstantDim.c) */
