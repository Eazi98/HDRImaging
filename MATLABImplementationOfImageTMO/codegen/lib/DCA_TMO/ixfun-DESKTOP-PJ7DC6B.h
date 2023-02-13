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

#ifndef IXFUN_H
#define IXFUN_H

/* Include files */
#include "DCA_TMO_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_binary_expand_op(emxArray_real_T *in1, const emxArray_real_T *in2,
                        const emxArray_real_T *in3, const emxArray_real_T *in4);

void expand_power(const emxArray_real_T *a, const emxArray_real_T *b,
                  emxArray_real_T *c);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (ixfun.h) */
