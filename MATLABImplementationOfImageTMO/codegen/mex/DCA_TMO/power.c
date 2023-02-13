/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * power.c
 *
 * Code generation for function 'power'
 *
 */

/* Include files */
#include "power.h"
#include "DCA_TMO_data.h"
#include "DCA_TMO_emxutil.h"
#include "DCA_TMO_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "ixfun.h"
#include "rt_nonfinite.h"
#include "vAllOrAny.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo pg_emlrtRSI =
    {
        84,         /* lineNo */
        "fltpower", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\ops\\power.m" /* pathName
                                                                          */
};

static emlrtRSInfo qg_emlrtRSI =
    {
        112,                     /* lineNo */
        "fltpower_domain_error", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\ops\\power.m" /* pathName
                                                                          */
};

static emlrtRSInfo rg_emlrtRSI = {
    57,      /* lineNo */
    "ixfun", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\ixfun.m" /* pathName
                                                                            */
};

static emlrtRSInfo sg_emlrtRSI = {
    102,                          /* lineNo */
    "binaryImplicitExpansionFun", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\ixfun.m" /* pathName
                                                                            */
};

static emlrtRSInfo tg_emlrtRSI =
    {
        16,    /* lineNo */
        "any", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\ops\\any.m" /* pathName
                                                                        */
};

static emlrtRSInfo ug_emlrtRSI =
    {
        57,         /* lineNo */
        "allOrAny", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny."
        "m" /* pathName */
};

static emlrtRSInfo vg_emlrtRSI = {
    106,                   /* lineNo */
    "applyToMultipleDims", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\applyToMultipleDims.m" /* pathName */
};

static emlrtRSInfo wg_emlrtRSI = {
    63,                               /* lineNo */
    "function_handle/parenReference", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\function_"
    "handle.m" /* pathName */
};

static emlrtRSInfo xg_emlrtRSI =
    {
        56, /* lineNo */
        "@(x)coder.internal.allOrAny(op,x,coder.internal.indexInt(1))", /* fcnName
                                                                         */
        "C:\\Program "
        "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny."
        "m" /* pathName */
};

static emlrtRSInfo yg_emlrtRSI =
    {
        143,        /* lineNo */
        "allOrAny", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny."
        "m" /* pathName */
};

static emlrtRTEInfo ld_emlrtRTEI =
    {
        112,     /* lineNo */
        13,      /* colNo */
        "power", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\ops\\power.m" /* pName
                                                                          */
};

/* Function Definitions */
void b_power(const emlrtStack *sp, const emxArray_real_T *a, emxArray_real_T *y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  const real_T *a_data;
  real_T *y_data;
  int32_T i;
  int32_T loop_ub;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  a_data = a->data;
  st.site = &fc_emlrtRSI;
  b_st.site = &gc_emlrtRSI;
  if ((a->size[0] == 1) && (a->size[1] == 1)) {
    p = (a_data[0] < 0.0);
  } else {
    c_st.site = &hc_emlrtRSI;
    p = vAllOrAny(&c_st, a);
  }
  if (p) {
    emlrtErrorWithMessageIdR2018a(&st, &e_emlrtRTEI,
                                  "Coder:toolbox:power_domainError",
                                  "Coder:toolbox:power_domainError", 0);
  }
  i = y->size[0] * y->size[1];
  y->size[0] = a->size[0];
  y->size[1] = a->size[1];
  emxEnsureCapacity_real_T(&st, y, i, &ub_emlrtRTEI);
  y_data = y->data;
  loop_ub = a->size[0] * a->size[1];
  for (i = 0; i < loop_ub; i++) {
    real_T varargin_1;
    varargin_1 = a_data[i];
    y_data[i] = muDoubleScalarPower(varargin_1, 78.84375);
  }
}

void c_power(const emlrtStack *sp, const emxArray_real_T *a,
             const emxArray_real_T *b, emxArray_real_T *y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack j_st;
  emlrtStack st;
  emxArray_boolean_T *c;
  const real_T *a_data;
  const real_T *b_data;
  int32_T k;
  boolean_T p;
  boolean_T *c_data;
  st.prev = sp;
  st.tls = sp->tls;
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
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  j_st.prev = &i_st;
  j_st.tls = i_st.tls;
  b_data = b->data;
  a_data = a->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &fc_emlrtRSI;
  b_st.site = &gc_emlrtRSI;
  if ((b->size[0] == 1) && (b->size[1] == 1)) {
    if ((!muDoubleScalarIsNaN(b_data[0])) &&
        (muDoubleScalarFloor(b_data[0]) != b_data[0])) {
      int32_T nx;
      c_st.site = &hc_emlrtRSI;
      d_st.site = &ic_emlrtRSI;
      nx = a->size[0] * a->size[1] * 3;
      p = false;
      e_st.site = &jc_emlrtRSI;
      if (nx > 2147483646) {
        f_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }
      for (k = 0; k < nx; k++) {
        if (p || (a_data[k] < 0.0)) {
          p = true;
        }
      }
    } else {
      p = false;
    }
  } else {
    int32_T nx;
    boolean_T exitg1;
    emxInit_boolean_T(&b_st, &c, 3, &ld_emlrtRTEI);
    c_st.site = &qg_emlrtRSI;
    d_st.site = &rg_emlrtRSI;
    e_st.site = &sg_emlrtRSI;
    expand_fltpower_domain_error(&e_st, a, b, c);
    c_data = c->data;
    c_st.site = &qg_emlrtRSI;
    d_st.site = &tg_emlrtRSI;
    e_st.site = &ug_emlrtRSI;
    f_st.site = &vg_emlrtRSI;
    g_st.site = &wg_emlrtRSI;
    h_st.site = &xg_emlrtRSI;
    p = false;
    i_st.site = &yg_emlrtRSI;
    if (c->size[0] * c->size[1] * 3 > 2147483646) {
      j_st.site = &cb_emlrtRSI;
      check_forloop_overflow_error(&j_st);
    }
    nx = 1;
    exitg1 = false;
    while ((!exitg1) && (nx <= c->size[0] * c->size[1] * 3)) {
      if (c_data[nx - 1]) {
        p = true;
        exitg1 = true;
      } else {
        nx++;
      }
    }
    emxFree_boolean_T(&h_st, &c);
  }
  if (p) {
    emlrtErrorWithMessageIdR2018a(&st, &e_emlrtRTEI,
                                  "Coder:toolbox:power_domainError",
                                  "Coder:toolbox:power_domainError", 0);
  }
  b_st.site = &pg_emlrtRSI;
  c_st.site = &rg_emlrtRSI;
  d_st.site = &sg_emlrtRSI;
  expand_power(&d_st, a, b, y);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void power(const emlrtStack *sp, const emxArray_real_T *a, emxArray_real_T *y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  const real_T *a_data;
  real_T *y_data;
  int32_T i;
  int32_T loop_ub;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  a_data = a->data;
  st.site = &fc_emlrtRSI;
  b_st.site = &gc_emlrtRSI;
  if ((a->size[0] == 1) && (a->size[1] == 1)) {
    p = (a_data[0] < 0.0);
  } else {
    c_st.site = &hc_emlrtRSI;
    p = vAllOrAny(&c_st, a);
  }
  if (p) {
    emlrtErrorWithMessageIdR2018a(&st, &e_emlrtRTEI,
                                  "Coder:toolbox:power_domainError",
                                  "Coder:toolbox:power_domainError", 0);
  }
  i = y->size[0] * y->size[1];
  y->size[0] = a->size[0];
  y->size[1] = a->size[1];
  emxEnsureCapacity_real_T(&st, y, i, &ub_emlrtRTEI);
  y_data = y->data;
  loop_ub = a->size[0] * a->size[1];
  for (i = 0; i < loop_ub; i++) {
    real_T varargin_1;
    varargin_1 = a_data[i];
    y_data[i] = muDoubleScalarPower(varargin_1, 0.1593017578125);
  }
}

/* End of code generation (power.c) */
