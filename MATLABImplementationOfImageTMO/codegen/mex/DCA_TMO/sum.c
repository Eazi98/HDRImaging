/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sum.c
 *
 * Code generation for function 'sum'
 *
 */

/* Include files */
#include "sum.h"
#include "DCA_TMO_data.h"
#include "DCA_TMO_types.h"
#include "rt_nonfinite.h"
#include "sumMatrixIncludeNaN.h"

/* Variable Definitions */
static emlrtRSInfo td_emlrtRSI = {
    20,    /* lineNo */
    "sum", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m" /* pathName
                                                                        */
};

static emlrtRSInfo ud_emlrtRSI = {
    99,        /* lineNo */
    "sumprod", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumpro"
    "d.m" /* pathName */
};

/* Function Definitions */
real_T sum(const emlrtStack *sp, const emxArray_real_T *x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  emxArray_real_T c_x;
  real_T y;
  int32_T d_x;
  int32_T e_x;
  int32_T f_x;
  int32_T g_x;
  int32_T ib;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &td_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  b_st.site = &ud_emlrtRSI;
  c_st.site = &jd_emlrtRSI;
  if (x->size[1] == 0) {
    y = 0.0;
  } else {
    d_st.site = &kd_emlrtRSI;
    e_st.site = &ld_emlrtRSI;
    if (x->size[1] < 4096) {
      int32_T b_x;
      b_x = x->size[1];
      c_x = *x;
      d_x = b_x;
      c_x.size = &d_x;
      c_x.numDimensions = 1;
      f_st.site = &md_emlrtRSI;
      y = sumColumnB(&f_st, &c_x, x->size[1]);
    } else {
      int32_T b_x;
      int32_T inb;
      int32_T nfb;
      int32_T nleft;
      nfb = (int32_T)((uint32_T)x->size[1] >> 12);
      inb = nfb << 12;
      nleft = x->size[1] - inb;
      b_x = x->size[1];
      c_x = *x;
      e_x = b_x;
      c_x.size = &e_x;
      c_x.numDimensions = 1;
      y = sumColumnB4(&c_x, 1);
      if (nfb >= 2) {
        b_x = x->size[1];
      }
      for (ib = 2; ib <= nfb; ib++) {
        c_x = *x;
        f_x = b_x;
        c_x.size = &f_x;
        c_x.numDimensions = 1;
        y += sumColumnB4(&c_x, ((ib - 1) << 12) + 1);
      }
      if (nleft > 0) {
        b_x = x->size[1];
        c_x = *x;
        g_x = b_x;
        c_x.size = &g_x;
        c_x.numDimensions = 1;
        f_st.site = &nd_emlrtRSI;
        y += b_sumColumnB(&f_st, &c_x, nleft, inb + 1);
      }
    }
  }
  return y;
}

/* End of code generation (sum.c) */
