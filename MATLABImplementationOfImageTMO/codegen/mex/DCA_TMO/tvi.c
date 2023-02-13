/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * tvi.c
 *
 * Code generation for function 'tvi'
 *
 */

/* Include files */
#include "tvi.h"
#include "DCA_TMO_data.h"
#include "DCA_TMO_types.h"
#include "rt_nonfinite.h"
#include "vAllOrAny.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo qe_emlrtRSI = {
    15,    /* lineNo */
    "tvi", /* fcnName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\tvi.m" /* pathName */
};

static emlrtRSInfo re_emlrtRSI = {
    21,    /* lineNo */
    "tvi", /* fcnName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\tvi.m" /* pathName */
};

static emlrtECInfo j_emlrtECI = {
    -1,    /* nDims */
    15,    /* lineNo */
    1,     /* colNo */
    "tvi", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\tvi.m" /* pName */
};

static emlrtECInfo k_emlrtECI = {
    -1,    /* nDims */
    18,    /* lineNo */
    1,     /* colNo */
    "tvi", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\tvi.m" /* pName */
};

static emlrtECInfo l_emlrtECI = {
    -1,    /* nDims */
    21,    /* lineNo */
    1,     /* colNo */
    "tvi", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\tvi.m" /* pName */
};

static emlrtECInfo m_emlrtECI = {
    -1,    /* nDims */
    24,    /* lineNo */
    1,     /* colNo */
    "tvi", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\tvi.m" /* pName */
};

/* Function Definitions */
real_T tvi(const emlrtStack *sp, real_T intensity)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_real_T b_idx_data;
  emxArray_real_T c_idx_data;
  real_T d;
  real_T idx_data;
  real_T varargin_1;
  int32_T idx_size[2];
  int32_T i;
  int32_T ii_size_idx_0;
  int32_T ii_size_idx_1;
  int32_T loop_ub;
  int8_T size_tmp_idx_0;
  int8_T size_tmp_idx_1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  covrtLogFcn(&emlrtCoverageInstance, 3U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 3U, 0U);
  /* --------------------------------------- */
  /*  The output is the sensitivity of HVS measured as just noticeable */
  /*  difference in the ambient intensity defined by the input parameter. */
  /*  */
  /*  intensity: real luminance in log10 domain */
  /*  threshold: in log10 domain, delta(lum)=10.^(threshold) */
  if (intensity < -3.94) {
    ii_size_idx_0 = 1;
    ii_size_idx_1 = 1;
  } else {
    ii_size_idx_0 = 0;
    ii_size_idx_1 = 0;
  }
  d = 0.0;
  loop_ub = ii_size_idx_0 * ii_size_idx_1;
  for (i = 0; i < loop_ub; i++) {
    d = -2.86;
  }
  if ((intensity >= -3.94) && (intensity < -1.44)) {
    ii_size_idx_0 = 1;
    ii_size_idx_1 = 1;
  } else {
    ii_size_idx_0 = 0;
    ii_size_idx_1 = 0;
  }
  idx_size[0] = ii_size_idx_0;
  idx_size[1] = ii_size_idx_1;
  loop_ub = ii_size_idx_0 * ii_size_idx_1;
  for (i = 0; i < loop_ub; i++) {
    idx_data = 1.0;
  }
  size_tmp_idx_0 = (int8_T)idx_size[0];
  size_tmp_idx_1 = (int8_T)idx_size[1];
  ii_size_idx_0 = idx_size[0];
  ii_size_idx_1 = idx_size[1];
  st.site = &qe_emlrtRSI;
  idx_size[0] = size_tmp_idx_0;
  idx_size[1] = size_tmp_idx_1;
  loop_ub = size_tmp_idx_0 * size_tmp_idx_1;
  for (i = 0; i < loop_ub; i++) {
    idx_data = 0.405 * intensity + 1.6;
  }
  b_st.site = &fc_emlrtRSI;
  c_st.site = &gc_emlrtRSI;
  if ((idx_size[0] == 1) && (idx_size[1] == 1)) {
    p = (idx_data < 0.0);
  } else {
    b_idx_data.data = &idx_data;
    b_idx_data.size = &idx_size[0];
    b_idx_data.allocatedSize = 1;
    b_idx_data.numDimensions = 2;
    b_idx_data.canFreeData = false;
    d_st.site = &hc_emlrtRSI;
    p = vAllOrAny(&d_st, &b_idx_data);
  }
  if (p) {
    emlrtErrorWithMessageIdR2018a(&b_st, &e_emlrtRTEI,
                                  "Coder:toolbox:power_domainError",
                                  "Coder:toolbox:power_domainError", 0);
  }
  loop_ub = idx_size[0] * idx_size[1];
  for (i = 0; i < loop_ub; i++) {
    varargin_1 = idx_data;
    idx_data = muDoubleScalarPower(varargin_1, 2.18);
  }
  i = ii_size_idx_0 * ii_size_idx_1;
  ii_size_idx_0 = idx_size[0] * idx_size[1];
  if (i != ii_size_idx_0) {
    emlrtSubAssignSizeCheck1dR2017a(i, ii_size_idx_0, &j_emlrtECI,
                                    (emlrtConstCTX)sp);
  }
  loop_ub = idx_size[0] * idx_size[1];
  for (i = 0; i < loop_ub; i++) {
    d = idx_data - 2.86;
  }
  if ((intensity >= -1.44) && (intensity < -0.0184)) {
    ii_size_idx_0 = 1;
    ii_size_idx_1 = 1;
  } else {
    ii_size_idx_0 = 0;
    ii_size_idx_1 = 0;
  }
  idx_size[0] = ii_size_idx_0;
  idx_size[1] = ii_size_idx_1;
  loop_ub = ii_size_idx_0 * ii_size_idx_1;
  for (i = 0; i < loop_ub; i++) {
    idx_data = 1.0;
  }
  ii_size_idx_0 = idx_size[0];
  ii_size_idx_1 = idx_size[1];
  i = ii_size_idx_0 * ii_size_idx_1;
  ii_size_idx_0 = idx_size[0] * idx_size[1];
  if (i != ii_size_idx_0) {
    emlrtSubAssignSizeCheck1dR2017a(i, ii_size_idx_0, &k_emlrtECI,
                                    (emlrtConstCTX)sp);
  }
  loop_ub = idx_size[0] * idx_size[1];
  for (i = 0; i < loop_ub; i++) {
    d = intensity - 0.395;
  }
  if ((intensity >= -0.0184) && (intensity < 1.9)) {
    ii_size_idx_0 = 1;
    ii_size_idx_1 = 1;
  } else {
    ii_size_idx_0 = 0;
    ii_size_idx_1 = 0;
  }
  idx_size[0] = ii_size_idx_0;
  idx_size[1] = ii_size_idx_1;
  loop_ub = ii_size_idx_0 * ii_size_idx_1;
  for (i = 0; i < loop_ub; i++) {
    idx_data = 1.0;
  }
  size_tmp_idx_0 = (int8_T)idx_size[0];
  size_tmp_idx_1 = (int8_T)idx_size[1];
  ii_size_idx_0 = idx_size[0];
  ii_size_idx_1 = idx_size[1];
  st.site = &re_emlrtRSI;
  idx_size[0] = size_tmp_idx_0;
  idx_size[1] = size_tmp_idx_1;
  loop_ub = size_tmp_idx_0 * size_tmp_idx_1;
  for (i = 0; i < loop_ub; i++) {
    idx_data = 0.249 * intensity + 0.65;
  }
  b_st.site = &fc_emlrtRSI;
  c_st.site = &gc_emlrtRSI;
  if ((idx_size[0] == 1) && (idx_size[1] == 1)) {
    p = (idx_data < 0.0);
  } else {
    c_idx_data.data = &idx_data;
    c_idx_data.size = &idx_size[0];
    c_idx_data.allocatedSize = 1;
    c_idx_data.numDimensions = 2;
    c_idx_data.canFreeData = false;
    d_st.site = &hc_emlrtRSI;
    p = vAllOrAny(&d_st, &c_idx_data);
  }
  if (p) {
    emlrtErrorWithMessageIdR2018a(&b_st, &e_emlrtRTEI,
                                  "Coder:toolbox:power_domainError",
                                  "Coder:toolbox:power_domainError", 0);
  }
  loop_ub = idx_size[0] * idx_size[1];
  for (i = 0; i < loop_ub; i++) {
    varargin_1 = idx_data;
    idx_data = muDoubleScalarPower(varargin_1, 2.7);
  }
  i = ii_size_idx_0 * ii_size_idx_1;
  ii_size_idx_0 = idx_size[0] * idx_size[1];
  if (i != ii_size_idx_0) {
    emlrtSubAssignSizeCheck1dR2017a(i, ii_size_idx_0, &l_emlrtECI,
                                    (emlrtConstCTX)sp);
  }
  loop_ub = idx_size[0] * idx_size[1];
  for (i = 0; i < loop_ub; i++) {
    d = idx_data - 0.72;
  }
  if (intensity >= 1.9) {
    ii_size_idx_0 = 1;
    ii_size_idx_1 = 1;
  } else {
    ii_size_idx_0 = 0;
    ii_size_idx_1 = 0;
  }
  idx_size[0] = ii_size_idx_0;
  idx_size[1] = ii_size_idx_1;
  loop_ub = ii_size_idx_0 * ii_size_idx_1;
  for (i = 0; i < loop_ub; i++) {
    idx_data = 1.0;
  }
  ii_size_idx_0 = idx_size[0];
  ii_size_idx_1 = idx_size[1];
  i = ii_size_idx_0 * ii_size_idx_1;
  ii_size_idx_0 = idx_size[0] * idx_size[1];
  if (i != ii_size_idx_0) {
    emlrtSubAssignSizeCheck1dR2017a(i, ii_size_idx_0, &m_emlrtECI,
                                    (emlrtConstCTX)sp);
  }
  loop_ub = idx_size[0] * idx_size[1];
  for (i = 0; i < loop_ub; i++) {
    d = intensity - 1.255;
  }
  return d - 0.95;
}

/* End of code generation (tvi.c) */
