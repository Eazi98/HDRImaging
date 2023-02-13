/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ixfun.c
 *
 * Code generation for function 'ixfun'
 *
 */

/* Include files */
#include "ixfun.h"
#include "DCA_TMO_data.h"
#include "DCA_TMO_emxutil.h"
#include "DCA_TMO_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRTEInfo s_emlrtRTEI = {
    225,                            /* lineNo */
    23,                             /* colNo */
    "expand_fltpower_domain_error", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\ixfun.m" /* pName
                                                                            */
};

static emlrtRTEInfo t_emlrtRTEI = {
    225,            /* lineNo */
    23,             /* colNo */
    "expand_power", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\ixfun.m" /* pName
                                                                            */
};

static emlrtRTEInfo md_emlrtRTEI = {
    234,     /* lineNo */
    20,      /* colNo */
    "ixfun", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\ixfun.m" /* pName
                                                                            */
};

/* Function Definitions */
void expand_fltpower_domain_error(const emlrtStack *sp,
                                  const emxArray_real_T *a,
                                  const emxArray_real_T *b,
                                  emxArray_boolean_T *c)
{
  const real_T *a_data;
  const real_T *b_data;
  int32_T b_k;
  int32_T c_k;
  int32_T csz_idx_0;
  int32_T i;
  int32_T k;
  int32_T sak;
  int32_T sbk;
  boolean_T dimagree;
  boolean_T *c_data;
  b_data = b->data;
  a_data = a->data;
  dimagree = true;
  sak = a->size[0];
  sbk = b->size[0];
  if (b->size[0] == 1) {
    csz_idx_0 = a->size[0];
  } else if (a->size[0] == 1) {
    csz_idx_0 = b->size[0];
  } else {
    csz_idx_0 = muIntScalarMin_sint32(sak, sbk);
    dimagree = (a->size[0] == b->size[0]);
  }
  sak = a->size[1];
  sbk = b->size[1];
  if (b->size[1] == 1) {
    sak = a->size[1];
  } else if (a->size[1] == 1) {
    sak = b->size[1];
  } else {
    sak = muIntScalarMin_sint32(sak, sbk);
    if ((!dimagree) || (a->size[1] != b->size[1])) {
      dimagree = false;
    }
  }
  if (!dimagree) {
    emlrtErrorWithMessageIdR2018a(sp, &s_emlrtRTEI,
                                  "MATLAB:sizeDimensionsMustMatch",
                                  "MATLAB:sizeDimensionsMustMatch", 0);
  }
  i = c->size[0] * c->size[1] * c->size[2];
  c->size[0] = csz_idx_0;
  c->size[1] = sak;
  c->size[2] = 3;
  emxEnsureCapacity_boolean_T(sp, c, i, &md_emlrtRTEI);
  c_data = c->data;
  if ((csz_idx_0 != 0) && (sak != 0)) {
    boolean_T b1;
    boolean_T b2;
    boolean_T b_b;
    dimagree = (a->size[1] != 1);
    b_b = (b->size[1] != 1);
    b1 = (a->size[0] != 1);
    b2 = (b->size[0] != 1);
    for (k = 0; k < 3; k++) {
      i = c->size[1] - 1;
      for (b_k = 0; b_k <= i; b_k++) {
        sak = dimagree * b_k;
        sbk = b_b * b_k;
        csz_idx_0 = c->size[0] - 1;
        for (c_k = 0; c_k <= csz_idx_0; c_k++) {
          real_T c_b;
          c_b = b_data[b2 * c_k + b->size[0] * sbk];
          if ((a_data[(b1 * c_k + a->size[0] * sak) +
                      a->size[0] * a->size[1] * k] < 0.0) &&
              (!muDoubleScalarIsNaN(c_b)) &&
              (muDoubleScalarFloor(c_b) != c_b)) {
            c_data[(c_k + c->size[0] * b_k) + c->size[0] * c->size[1] * k] =
                true;
          } else {
            c_data[(c_k + c->size[0] * b_k) + c->size[0] * c->size[1] * k] =
                false;
          }
        }
      }
    }
  }
}

void expand_power(const emlrtStack *sp, const emxArray_real_T *a,
                  const emxArray_real_T *b, emxArray_real_T *c)
{
  const real_T *a_data;
  const real_T *b_data;
  real_T *c_data;
  int32_T b_k;
  int32_T c_k;
  int32_T csz_idx_0;
  int32_T i;
  int32_T k;
  int32_T sak;
  int32_T sbk;
  boolean_T dimagree;
  b_data = b->data;
  a_data = a->data;
  dimagree = true;
  sak = a->size[0];
  sbk = b->size[0];
  if (b->size[0] == 1) {
    csz_idx_0 = a->size[0];
  } else if (a->size[0] == 1) {
    csz_idx_0 = b->size[0];
  } else {
    csz_idx_0 = muIntScalarMin_sint32(sak, sbk);
    dimagree = (a->size[0] == b->size[0]);
  }
  sak = a->size[1];
  sbk = b->size[1];
  if (b->size[1] == 1) {
    sak = a->size[1];
  } else if (a->size[1] == 1) {
    sak = b->size[1];
  } else {
    sak = muIntScalarMin_sint32(sak, sbk);
    if ((!dimagree) || (a->size[1] != b->size[1])) {
      dimagree = false;
    }
  }
  if (!dimagree) {
    emlrtErrorWithMessageIdR2018a(sp, &t_emlrtRTEI,
                                  "MATLAB:sizeDimensionsMustMatch",
                                  "MATLAB:sizeDimensionsMustMatch", 0);
  }
  i = c->size[0] * c->size[1] * c->size[2];
  c->size[0] = csz_idx_0;
  c->size[1] = sak;
  c->size[2] = 3;
  emxEnsureCapacity_real_T(sp, c, i, &md_emlrtRTEI);
  c_data = c->data;
  if ((csz_idx_0 != 0) && (sak != 0)) {
    boolean_T b1;
    boolean_T b2;
    boolean_T b_b;
    dimagree = (a->size[1] != 1);
    b_b = (b->size[1] != 1);
    b1 = (a->size[0] != 1);
    b2 = (b->size[0] != 1);
    for (k = 0; k < 3; k++) {
      i = c->size[1] - 1;
      for (b_k = 0; b_k <= i; b_k++) {
        sak = dimagree * b_k;
        sbk = b_b * b_k;
        csz_idx_0 = c->size[0] - 1;
        for (c_k = 0; c_k <= csz_idx_0; c_k++) {
          c_data[(c_k + c->size[0] * b_k) + c->size[0] * c->size[1] * k] =
              muDoubleScalarPower(a_data[(b1 * c_k + a->size[0] * sak) +
                                         a->size[0] * a->size[1] * k],
                                  b_data[b2 * c_k + b->size[0] * sbk]);
        }
      }
    }
  }
}

/* End of code generation (ixfun.c) */
