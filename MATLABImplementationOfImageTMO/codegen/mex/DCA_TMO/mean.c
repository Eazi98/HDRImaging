/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mean.c
 *
 * Code generation for function 'mean'
 *
 */

/* Include files */
#include "mean.h"
#include "DCA_TMO_data.h"
#include "DCA_TMO_types.h"
#include "rt_nonfinite.h"
#include "sumMatrixIncludeNaN.h"

/* Variable Definitions */
static emlrtRSInfo id_emlrtRSI = {
    49,     /* lineNo */
    "mean", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m" /* pathName
                                                                         */
};

static emlrtRSInfo ff_emlrtRSI = {
    107,                /* lineNo */
    "blockedSummation", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\blocke"
    "dSummation.m" /* pathName */
};

/* Function Definitions */
real_T b_mean(const emlrtStack *sp, const emxArray_real_T *x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T s;
  int32_T ib;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &id_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &jd_emlrtRSI;
  if (x->size[0] == 0) {
    s = 0.0;
  } else {
    c_st.site = &ff_emlrtRSI;
    d_st.site = &ld_emlrtRSI;
    if (x->size[0] < 4096) {
      e_st.site = &md_emlrtRSI;
      s = sumColumnB(&e_st, x, x->size[0]);
    } else {
      int32_T inb;
      int32_T nfb;
      int32_T nleft;
      nfb = (int32_T)((uint32_T)x->size[0] >> 12);
      inb = nfb << 12;
      nleft = x->size[0] - inb;
      s = sumColumnB4(x, 1);
      for (ib = 2; ib <= nfb; ib++) {
        s += sumColumnB4(x, ((ib - 1) << 12) + 1);
      }
      if (nleft > 0) {
        e_st.site = &nd_emlrtRSI;
        s += b_sumColumnB(&e_st, x, nleft, inb + 1);
      }
    }
  }
  return s / (real_T)x->size[0];
}

real_T mean(const emlrtStack *sp, const emxArray_real_T *x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  emxArray_real_T c_x;
  real_T s;
  int32_T d_x;
  int32_T e_x;
  int32_T f_x;
  int32_T g_x;
  int32_T ib;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &id_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &jd_emlrtRSI;
  if (x->size[1] == 0) {
    s = 0.0;
  } else {
    c_st.site = &kd_emlrtRSI;
    d_st.site = &ld_emlrtRSI;
    if (x->size[1] < 4096) {
      int32_T b_x;
      b_x = x->size[1];
      c_x = *x;
      d_x = b_x;
      c_x.size = &d_x;
      c_x.numDimensions = 1;
      e_st.site = &md_emlrtRSI;
      s = sumColumnB(&e_st, &c_x, x->size[1]);
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
      s = sumColumnB4(&c_x, 1);
      if (nfb >= 2) {
        b_x = x->size[1];
      }
      for (ib = 2; ib <= nfb; ib++) {
        c_x = *x;
        f_x = b_x;
        c_x.size = &f_x;
        c_x.numDimensions = 1;
        s += sumColumnB4(&c_x, ((ib - 1) << 12) + 1);
      }
      if (nleft > 0) {
        b_x = x->size[1];
        c_x = *x;
        g_x = b_x;
        c_x.size = &g_x;
        c_x.numDimensions = 1;
        e_st.site = &nd_emlrtRSI;
        s += b_sumColumnB(&e_st, &c_x, nleft, inb + 1);
      }
    }
  }
  return s / (real_T)x->size[1];
}

/* End of code generation (mean.c) */
