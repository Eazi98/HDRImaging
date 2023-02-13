/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * svd.c
 *
 * Code generation for function 'svd'
 *
 */

/* Include files */
#include "svd.h"
#include "DCA_TMO_data.h"
#include "rt_nonfinite.h"
#include "lapacke.h"
#include <stddef.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo uf_emlrtRSI = {
    36,    /* lineNo */
    "svd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\matfun\\svd.m" /* pathName
                                                                       */
};

static emlrtRSInfo vf_emlrtRSI = {
    52,    /* lineNo */
    "svd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" /* pathName
                                                                          */
};

static emlrtRSInfo wf_emlrtRSI = {
    89,           /* lineNo */
    "callLAPACK", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" /* pathName
                                                                          */
};

static emlrtRSInfo xf_emlrtRSI = {
    81,           /* lineNo */
    "callLAPACK", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" /* pathName
                                                                          */
};

static emlrtRSInfo yf_emlrtRSI = {
    209,      /* lineNo */
    "xgesdd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesdd.m" /* pathName */
};

static emlrtRSInfo ag_emlrtRSI = {
    31,       /* lineNo */
    "xgesvd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" /* pathName */
};

static emlrtRSInfo bg_emlrtRSI = {
    197,            /* lineNo */
    "ceval_xgesvd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" /* pathName */
};

static emlrtRTEInfo m_emlrtRTEI = {
    111,          /* lineNo */
    5,            /* colNo */
    "callLAPACK", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" /* pName
                                                                          */
};

static emlrtRTEInfo n_emlrtRTEI = {
    44,          /* lineNo */
    13,          /* colNo */
    "infocheck", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\infocheck.m" /* pName */
};

static emlrtRTEInfo o_emlrtRTEI = {
    47,          /* lineNo */
    13,          /* colNo */
    "infocheck", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\infocheck.m" /* pName */
};

/* Function Definitions */
void svd(const emlrtStack *sp, real_T U[81], real_T S[81], real_T V[81])
{
  static const char_T b_fname[14] = {'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                     '_', 'd', 'g', 'e', 's', 'v', 'd'};
  static const char_T fname[14] = {'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                   '_', 'd', 'g', 'e', 's', 'd', 'd'};
  ptrdiff_t info_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T A[81];
  real_T Vt[81];
  real_T b_S[9];
  real_T superb[8];
  int32_T i;
  int32_T i1;
  int32_T info;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &uf_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &vf_emlrtRSI;
  c_st.site = &xf_emlrtRSI;
  memcpy(&A[0], &dv[0], 81U * sizeof(real_T));
  info_t =
      LAPACKE_dgesdd(102, 'A', (ptrdiff_t)9, (ptrdiff_t)9, &A[0], (ptrdiff_t)9,
                     &b_S[0], &U[0], (ptrdiff_t)9, &Vt[0], (ptrdiff_t)9);
  d_st.site = &yf_emlrtRSI;
  if ((int32_T)info_t < 0) {
    if ((int32_T)info_t == -1010) {
      emlrtErrorWithMessageIdR2018a(&d_st, &n_emlrtRTEI, "MATLAB:nomem",
                                    "MATLAB:nomem", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(&d_st, &o_emlrtRTEI,
                                    "Coder:toolbox:LAPACKCallErrorInfo",
                                    "Coder:toolbox:LAPACKCallErrorInfo", 5, 4,
                                    14, &fname[0], 12, (int32_T)info_t);
    }
  }
  info = (int32_T)info_t;
  if ((int32_T)info_t > 0) {
    c_st.site = &wf_emlrtRSI;
    memcpy(&A[0], &dv[0], 81U * sizeof(real_T));
    d_st.site = &ag_emlrtRSI;
    info_t = LAPACKE_dgesvd(102, 'A', 'A', (ptrdiff_t)9, (ptrdiff_t)9, &A[0],
                            (ptrdiff_t)9, &b_S[0], &U[0], (ptrdiff_t)9, &Vt[0],
                            (ptrdiff_t)9, &superb[0]);
    for (i = 0; i < 9; i++) {
      for (i1 = 0; i1 < 9; i1++) {
        V[i1 + 9 * i] = Vt[i + 9 * i1];
      }
    }
    e_st.site = &bg_emlrtRSI;
    if ((int32_T)info_t < 0) {
      if ((int32_T)info_t == -1010) {
        emlrtErrorWithMessageIdR2018a(&e_st, &n_emlrtRTEI, "MATLAB:nomem",
                                      "MATLAB:nomem", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&e_st, &o_emlrtRTEI,
                                      "Coder:toolbox:LAPACKCallErrorInfo",
                                      "Coder:toolbox:LAPACKCallErrorInfo", 5, 4,
                                      14, &b_fname[0], 12, (int32_T)info_t);
      }
    }
    info = (int32_T)info_t;
  } else {
    for (i = 0; i < 9; i++) {
      for (i1 = 0; i1 < 9; i1++) {
        V[i1 + 9 * i] = Vt[i + 9 * i1];
      }
    }
  }
  if (info > 0) {
    emlrtErrorWithMessageIdR2018a(&b_st, &m_emlrtRTEI,
                                  "Coder:MATLAB:svd_NoConvergence",
                                  "Coder:MATLAB:svd_NoConvergence", 0);
  }
  memset(&S[0], 0, 81U * sizeof(real_T));
  for (info = 0; info < 9; info++) {
    S[info + 9 * info] = b_S[info];
  }
}

/* End of code generation (svd.c) */
