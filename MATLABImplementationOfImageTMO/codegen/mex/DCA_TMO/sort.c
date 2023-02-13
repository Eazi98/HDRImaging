/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sort.c
 *
 * Code generation for function 'sort'
 *
 */

/* Include files */
#include "sort.h"
#include "DCA_TMO_data.h"
#include "DCA_TMO_emxutil.h"
#include "DCA_TMO_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "sortIdx.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo u_emlrtRSI = {
    76,     /* lineNo */
    "sort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" /* pathName
                                                                           */
};

static emlrtRSInfo v_emlrtRSI = {
    79,     /* lineNo */
    "sort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" /* pathName
                                                                           */
};

static emlrtRSInfo w_emlrtRSI = {
    81,     /* lineNo */
    "sort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" /* pathName
                                                                           */
};

static emlrtRSInfo x_emlrtRSI = {
    84,     /* lineNo */
    "sort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" /* pathName
                                                                           */
};

static emlrtRSInfo y_emlrtRSI = {
    87,     /* lineNo */
    "sort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" /* pathName
                                                                           */
};

static emlrtRSInfo ab_emlrtRSI = {
    90,     /* lineNo */
    "sort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" /* pathName
                                                                           */
};

static emlrtRSInfo hd_emlrtRSI = {
    72,     /* lineNo */
    "sort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" /* pathName
                                                                           */
};

static emlrtRTEInfo od_emlrtRTEI = {
    56,     /* lineNo */
    24,     /* colNo */
    "sort", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" /* pName
                                                                           */
};

static emlrtRTEInfo pd_emlrtRTEI = {
    56,     /* lineNo */
    1,      /* colNo */
    "sort", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" /* pName
                                                                           */
};

static emlrtRTEInfo qd_emlrtRTEI = {
    1,      /* lineNo */
    20,     /* colNo */
    "sort", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" /* pName
                                                                           */
};

static emlrtRTEInfo
    wd_emlrtRTEI =
        {
            56,        /* lineNo */
            5,         /* colNo */
            "sortIdx", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\sortIdx.m" /* pName */
};

/* Function Definitions */
void b_sort(const emlrtStack *sp, emxArray_real_T *x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  emxArray_int32_T *idx;
  emxArray_int32_T *iwork;
  emxArray_real_T *xwork;
  real_T *x_data;
  real_T *xwork_data;
  int32_T b;
  int32_T b_b;
  int32_T i;
  int32_T ib;
  int32_T k;
  int32_T quartetOffset;
  int32_T *idx_data;
  int32_T *iwork_data;
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
  x_data = x->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &hd_emlrtRSI;
  emxInit_int32_T(&st, &idx, 2, &qd_emlrtRTEI);
  i = idx->size[0] * idx->size[1];
  idx->size[0] = 1;
  idx->size[1] = x->size[1];
  emxEnsureCapacity_int32_T(&st, idx, i, &wd_emlrtRTEI);
  idx_data = idx->data;
  ib = x->size[1];
  for (i = 0; i < ib; i++) {
    idx_data[i] = 0;
  }
  if (x->size[1] != 0) {
    real_T x4[4];
    int32_T idx4[4];
    int32_T bLen;
    int32_T i2;
    int32_T i3;
    int32_T i4;
    int32_T idx_tmp;
    int32_T n;
    int32_T nNonNaN;
    b_st.site = &db_emlrtRSI;
    c_st.site = &eb_emlrtRSI;
    n = x->size[1];
    x4[0] = 0.0;
    idx4[0] = 0;
    x4[1] = 0.0;
    idx4[1] = 0;
    x4[2] = 0.0;
    idx4[2] = 0;
    x4[3] = 0.0;
    idx4[3] = 0;
    ib = x->size[1];
    emxInit_int32_T(&c_st, &iwork, 1, &ud_emlrtRTEI);
    i = iwork->size[0];
    iwork->size[0] = ib;
    emxEnsureCapacity_int32_T(&c_st, iwork, i, &sd_emlrtRTEI);
    iwork_data = iwork->data;
    for (i = 0; i < ib; i++) {
      iwork_data[i] = 0;
    }
    ib = x->size[1];
    emxInit_real_T(&c_st, &xwork, 1, &vd_emlrtRTEI);
    i = xwork->size[0];
    xwork->size[0] = ib;
    emxEnsureCapacity_real_T(&c_st, xwork, i, &td_emlrtRTEI);
    xwork_data = xwork->data;
    for (i = 0; i < ib; i++) {
      xwork_data[i] = 0.0;
    }
    bLen = 0;
    ib = 0;
    d_st.site = &jb_emlrtRSI;
    if (x->size[1] > 2147483646) {
      e_st.site = &cb_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }
    for (k = 0; k < n; k++) {
      if (muDoubleScalarIsNaN(x_data[k])) {
        idx_tmp = (n - bLen) - 1;
        idx_data[idx_tmp] = k + 1;
        xwork_data[idx_tmp] = x_data[k];
        bLen++;
      } else {
        ib++;
        idx4[ib - 1] = k + 1;
        x4[ib - 1] = x_data[k];
        if (ib == 4) {
          real_T d;
          real_T d1;
          int8_T b_i2;
          int8_T b_i3;
          int8_T b_i4;
          int8_T i1;
          quartetOffset = k - bLen;
          if (x4[0] <= x4[1]) {
            ib = 1;
            i2 = 2;
          } else {
            ib = 2;
            i2 = 1;
          }
          if (x4[2] <= x4[3]) {
            i3 = 3;
            i4 = 4;
          } else {
            i3 = 4;
            i4 = 3;
          }
          d = x4[ib - 1];
          d1 = x4[i3 - 1];
          if (d <= d1) {
            d = x4[i2 - 1];
            if (d <= d1) {
              i1 = (int8_T)ib;
              b_i2 = (int8_T)i2;
              b_i3 = (int8_T)i3;
              b_i4 = (int8_T)i4;
            } else if (d <= x4[i4 - 1]) {
              i1 = (int8_T)ib;
              b_i2 = (int8_T)i3;
              b_i3 = (int8_T)i2;
              b_i4 = (int8_T)i4;
            } else {
              i1 = (int8_T)ib;
              b_i2 = (int8_T)i3;
              b_i3 = (int8_T)i4;
              b_i4 = (int8_T)i2;
            }
          } else {
            d1 = x4[i4 - 1];
            if (d <= d1) {
              if (x4[i2 - 1] <= d1) {
                i1 = (int8_T)i3;
                b_i2 = (int8_T)ib;
                b_i3 = (int8_T)i2;
                b_i4 = (int8_T)i4;
              } else {
                i1 = (int8_T)i3;
                b_i2 = (int8_T)ib;
                b_i3 = (int8_T)i4;
                b_i4 = (int8_T)i2;
              }
            } else {
              i1 = (int8_T)i3;
              b_i2 = (int8_T)i4;
              b_i3 = (int8_T)ib;
              b_i4 = (int8_T)i2;
            }
          }
          idx_data[quartetOffset - 3] = idx4[i1 - 1];
          idx_data[quartetOffset - 2] = idx4[b_i2 - 1];
          idx_data[quartetOffset - 1] = idx4[b_i3 - 1];
          idx_data[quartetOffset] = idx4[b_i4 - 1];
          x_data[quartetOffset - 3] = x4[i1 - 1];
          x_data[quartetOffset - 2] = x4[b_i2 - 1];
          x_data[quartetOffset - 1] = x4[b_i3 - 1];
          x_data[quartetOffset] = x4[b_i4 - 1];
          ib = 0;
        }
      }
    }
    i3 = x->size[1] - bLen;
    if (ib > 0) {
      int8_T perm[4];
      perm[1] = 0;
      perm[2] = 0;
      perm[3] = 0;
      if (ib == 1) {
        perm[0] = 1;
      } else if (ib == 2) {
        if (x4[0] <= x4[1]) {
          perm[0] = 1;
          perm[1] = 2;
        } else {
          perm[0] = 2;
          perm[1] = 1;
        }
      } else if (x4[0] <= x4[1]) {
        if (x4[1] <= x4[2]) {
          perm[0] = 1;
          perm[1] = 2;
          perm[2] = 3;
        } else if (x4[0] <= x4[2]) {
          perm[0] = 1;
          perm[1] = 3;
          perm[2] = 2;
        } else {
          perm[0] = 3;
          perm[1] = 1;
          perm[2] = 2;
        }
      } else if (x4[0] <= x4[2]) {
        perm[0] = 2;
        perm[1] = 1;
        perm[2] = 3;
      } else if (x4[1] <= x4[2]) {
        perm[0] = 2;
        perm[1] = 3;
        perm[2] = 1;
      } else {
        perm[0] = 3;
        perm[1] = 2;
        perm[2] = 1;
      }
      d_st.site = &kb_emlrtRSI;
      if (ib > 2147483646) {
        e_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&e_st);
      }
      i = (uint8_T)ib;
      for (k = 0; k < i; k++) {
        idx_tmp = perm[k] - 1;
        quartetOffset = (i3 - ib) + k;
        idx_data[quartetOffset] = idx4[idx_tmp];
        x_data[quartetOffset] = x4[idx_tmp];
      }
    }
    ib = bLen >> 1;
    d_st.site = &lb_emlrtRSI;
    for (k = 0; k < ib; k++) {
      quartetOffset = i3 + k;
      i2 = idx_data[quartetOffset];
      idx_tmp = (n - k) - 1;
      idx_data[quartetOffset] = idx_data[idx_tmp];
      idx_data[idx_tmp] = i2;
      x_data[quartetOffset] = xwork_data[idx_tmp];
      x_data[idx_tmp] = xwork_data[quartetOffset];
    }
    if ((bLen & 1) != 0) {
      i = i3 + ib;
      x_data[i] = xwork_data[i];
    }
    nNonNaN = x->size[1] - bLen;
    ib = 2;
    if (nNonNaN > 1) {
      if (x->size[1] >= 256) {
        int32_T nBlocks;
        nBlocks = nNonNaN >> 8;
        if (nBlocks > 0) {
          c_st.site = &fb_emlrtRSI;
          for (b = 0; b < nBlocks; b++) {
            real_T b_xwork[256];
            int32_T b_iwork[256];
            c_st.site = &gb_emlrtRSI;
            i4 = (b << 8) - 1;
            for (b_b = 0; b_b < 6; b_b++) {
              bLen = 1 << (b_b + 2);
              n = bLen << 1;
              i = 256 >> (b_b + 3);
              d_st.site = &mb_emlrtRSI;
              for (k = 0; k < i; k++) {
                i2 = (i4 + k * n) + 1;
                d_st.site = &nb_emlrtRSI;
                for (quartetOffset = 0; quartetOffset < n; quartetOffset++) {
                  ib = i2 + quartetOffset;
                  b_iwork[quartetOffset] = idx_data[ib];
                  b_xwork[quartetOffset] = x_data[ib];
                }
                i3 = 0;
                quartetOffset = bLen;
                ib = i2 - 1;
                int32_T exitg1;
                do {
                  exitg1 = 0;
                  ib++;
                  if (b_xwork[i3] <= b_xwork[quartetOffset]) {
                    idx_data[ib] = b_iwork[i3];
                    x_data[ib] = b_xwork[i3];
                    if (i3 + 1 < bLen) {
                      i3++;
                    } else {
                      exitg1 = 1;
                    }
                  } else {
                    idx_data[ib] = b_iwork[quartetOffset];
                    x_data[ib] = b_xwork[quartetOffset];
                    if (quartetOffset + 1 < n) {
                      quartetOffset++;
                    } else {
                      ib -= i3;
                      d_st.site = &ob_emlrtRSI;
                      for (quartetOffset = i3 + 1; quartetOffset <= bLen;
                           quartetOffset++) {
                        idx_tmp = ib + quartetOffset;
                        idx_data[idx_tmp] = b_iwork[quartetOffset - 1];
                        x_data[idx_tmp] = b_xwork[quartetOffset - 1];
                      }
                      exitg1 = 1;
                    }
                  }
                } while (exitg1 == 0);
              }
            }
          }
          ib = nBlocks << 8;
          quartetOffset = nNonNaN - ib;
          if (quartetOffset > 0) {
            c_st.site = &hb_emlrtRSI;
            merge_block(&c_st, idx, x, ib, quartetOffset, 2, iwork, xwork);
          }
          ib = 8;
        }
      }
      c_st.site = &ib_emlrtRSI;
      merge_block(&c_st, idx, x, 0, nNonNaN, ib, iwork, xwork);
    }
    emxFree_real_T(&b_st, &xwork);
    emxFree_int32_T(&b_st, &iwork);
  }
  emxFree_int32_T(&st, &idx);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void sort(const emlrtStack *sp, emxArray_real_T *x)
{
  emlrtStack b_st;
  emlrtStack st;
  emxArray_int32_T *bh_emlrtRSI;
  emxArray_real_T *vwork;
  real_T *vwork_data;
  real_T *x_data;
  int32_T dim;
  int32_T i;
  int32_T k;
  int32_T vlen;
  int32_T vstride;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  x_data = x->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  dim = 0;
  if (x->size[0] != 1) {
    dim = -1;
  }
  if (dim + 2 <= 1) {
    i = x->size[0];
  } else {
    i = 1;
  }
  vlen = i - 1;
  emxInit_real_T(sp, &vwork, 1, &pd_emlrtRTEI);
  vstride = vwork->size[0];
  vwork->size[0] = i;
  emxEnsureCapacity_real_T(sp, vwork, vstride, &od_emlrtRTEI);
  vwork_data = vwork->data;
  st.site = &u_emlrtRSI;
  vstride = 1;
  for (k = 0; k <= dim; k++) {
    vstride *= x->size[0];
  }
  st.site = &v_emlrtRSI;
  st.site = &w_emlrtRSI;
  if (vstride > 2147483646) {
    b_st.site = &cb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  emxInit_int32_T(sp, &bh_emlrtRSI, 1, &qd_emlrtRTEI);
  for (dim = 0; dim < vstride; dim++) {
    st.site = &x_emlrtRSI;
    if (i > 2147483646) {
      b_st.site = &cb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (k = 0; k <= vlen; k++) {
      vwork_data[k] = x_data[dim + k * vstride];
    }
    st.site = &y_emlrtRSI;
    sortIdx(&st, vwork, bh_emlrtRSI);
    vwork_data = vwork->data;
    st.site = &ab_emlrtRSI;
    for (k = 0; k <= vlen; k++) {
      x_data[dim + k * vstride] = vwork_data[k];
    }
  }
  emxFree_int32_T(sp, &bh_emlrtRSI);
  emxFree_real_T(sp, &vwork);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (sort.c) */
