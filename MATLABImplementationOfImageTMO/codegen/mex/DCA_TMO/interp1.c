/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * interp1.c
 *
 * Code generation for function 'interp1'
 *
 */

/* Include files */
#include "interp1.h"
#include "DCA_TMO_data.h"
#include "DCA_TMO_emxutil.h"
#include "DCA_TMO_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo gf_emlrtRSI = {
    49,        /* lineNo */
    "interp1", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" /* pathName
                                                                            */
};

static emlrtRSInfo hf_emlrtRSI = {
    309,            /* lineNo */
    "interp1_work", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" /* pathName
                                                                            */
};

static emlrtRSInfo if_emlrtRSI = {
    343,             /* lineNo */
    "interp1Linear", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" /* pathName
                                                                            */
};

static emlrtRTEInfo k_emlrtRTEI = {
    166,            /* lineNo */
    13,             /* colNo */
    "interp1_work", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" /* pName
                                                                            */
};

static emlrtRTEInfo l_emlrtRTEI = {
    208,            /* lineNo */
    13,             /* colNo */
    "interp1_work", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" /* pName
                                                                            */
};

static emlrtRTEInfo cd_emlrtRTEI = {
    49,        /* lineNo */
    9,         /* colNo */
    "interp1", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\polyfun\\interp1.m" /* pName
                                                                            */
};

/* Function Definitions */
void interp1(const emlrtStack *sp, const real_T varargin_1[55],
             const emxArray_real_T *varargin_3, emxArray_real_T *Vq)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T x[55];
  real_T y[55];
  const real_T *varargin_3_data;
  real_T *Vq_data;
  int32_T k;
  int32_T low_i;
  int32_T nxi;
  boolean_T b;
  boolean_T b1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  varargin_3_data = varargin_3->data;
  st.site = &gf_emlrtRSI;
  for (low_i = 0; low_i < 55; low_i++) {
    x[low_i] = varargin_1[low_i];
    y[low_i] = 4.7222222222222223 * (real_T)low_i + 1.0;
  }
  low_i = Vq->size[0] * Vq->size[1];
  Vq->size[0] = varargin_3->size[0];
  Vq->size[1] = varargin_3->size[1];
  emxEnsureCapacity_real_T(&st, Vq, low_i, &cd_emlrtRTEI);
  Vq_data = Vq->data;
  nxi = varargin_3->size[0] * varargin_3->size[1];
  for (low_i = 0; low_i < nxi; low_i++) {
    Vq_data[low_i] = rtNaN;
  }
  b = (varargin_3->size[0] == 0);
  b1 = (varargin_3->size[1] == 0);
  if ((!b) && (!b1)) {
    k = 0;
    int32_T exitg1;
    do {
      exitg1 = 0;
      if (k < 55) {
        if (muDoubleScalarIsNaN(varargin_1[k])) {
          emlrtErrorWithMessageIdR2018a(&st, &k_emlrtRTEI,
                                        "MATLAB:interp1:NaNinX",
                                        "MATLAB:interp1:NaNinX", 0);
        } else {
          k++;
        }
      } else {
        real_T xtmp;
        if (varargin_1[1] < varargin_1[0]) {
          for (nxi = 0; nxi < 27; nxi++) {
            xtmp = x[nxi];
            x[nxi] = x[54 - nxi];
            x[54 - nxi] = xtmp;
            xtmp = y[nxi];
            y[nxi] = y[54 - nxi];
            y[54 - nxi] = xtmp;
          }
        }
        for (k = 0; k < 54; k++) {
          if (x[k + 1] <= x[k]) {
            emlrtErrorWithMessageIdR2018a(
                &st, &l_emlrtRTEI, "Coder:toolbox:interp1_nonMonotonicX",
                "Coder:toolbox:interp1_nonMonotonicX", 0);
          }
        }
        b_st.site = &hf_emlrtRSI;
        nxi = varargin_3->size[0] * varargin_3->size[1];
        c_st.site = &if_emlrtRSI;
        if (nxi > 2147483646) {
          d_st.site = &cb_emlrtRSI;
          check_forloop_overflow_error(&d_st);
        }
        for (k = 0; k < nxi; k++) {
          if (muDoubleScalarIsNaN(varargin_3_data[k])) {
            Vq_data[k] = rtNaN;
          } else if ((!(varargin_3_data[k] > x[54])) &&
                     (!(varargin_3_data[k] < x[0]))) {
            int32_T high_i;
            int32_T low_ip1;
            low_i = 1;
            low_ip1 = 2;
            high_i = 55;
            while (high_i > low_ip1) {
              int32_T mid_i;
              mid_i = (low_i + high_i) >> 1;
              if (varargin_3_data[k] >= x[mid_i - 1]) {
                low_i = mid_i;
                low_ip1 = mid_i + 1;
              } else {
                high_i = mid_i;
              }
            }
            xtmp = x[low_i - 1];
            xtmp = (varargin_3_data[k] - xtmp) / (x[low_i] - xtmp);
            if (xtmp == 0.0) {
              Vq_data[k] = y[low_i - 1];
            } else if (xtmp == 1.0) {
              Vq_data[k] = y[low_i];
            } else if (y[low_i - 1] == y[low_i]) {
              Vq_data[k] = y[low_i - 1];
            } else {
              Vq_data[k] = (1.0 - xtmp) * y[low_i - 1] + xtmp * y[low_i];
            }
          }
        }
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
}

/* End of code generation (interp1.c) */
