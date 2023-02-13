/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * vAllOrAny.c
 *
 * Code generation for function 'vAllOrAny'
 *
 */

/* Include files */
#include "vAllOrAny.h"
#include "DCA_TMO_data.h"
#include "DCA_TMO_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"

/* Function Definitions */
boolean_T vAllOrAny(const emlrtStack *sp, const emxArray_real_T *x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  const real_T *x_data;
  int32_T k;
  int32_T nx;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  x_data = x->data;
  st.site = &ic_emlrtRSI;
  nx = x->size[0] * x->size[1];
  p = false;
  b_st.site = &jc_emlrtRSI;
  if (nx > 2147483646) {
    c_st.site = &cb_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (k = 0; k < nx; k++) {
    if (p || (x_data[k] < 0.0)) {
      p = true;
    }
  }
  return p;
}

/* End of code generation (vAllOrAny.c) */
