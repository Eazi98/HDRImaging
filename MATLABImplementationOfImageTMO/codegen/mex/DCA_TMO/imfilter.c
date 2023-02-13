/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * imfilter.c
 *
 * Code generation for function 'imfilter'
 *
 */

/* Include files */
#include "imfilter.h"
#include "DCA_TMO_data.h"
#include "DCA_TMO_emxutil.h"
#include "DCA_TMO_types.h"
#include "rt_nonfinite.h"
#include "svd.h"
#include "libmwimfilter.h"
#include "libmwippfilter.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo jf_emlrtRSI = {
    55,         /* lineNo */
    "imfilter", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\images\\images\\eml\\imfilter.m" /* pathName
                                                                       */
};

static emlrtRSInfo kf_emlrtRSI = {
    59,         /* lineNo */
    "imfilter", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\images\\images\\eml\\imfilter.m" /* pathName
                                                                       */
};

static emlrtRSInfo lf_emlrtRSI = {
    64,         /* lineNo */
    "imfilter", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\images\\images\\eml\\imfilter.m" /* pathName
                                                                       */
};

static emlrtRSInfo mf_emlrtRSI = {
    67,         /* lineNo */
    "imfilter", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\images\\images\\eml\\imfilter.m" /* pathName
                                                                       */
};

static emlrtRSInfo nf_emlrtRSI = {
    68,         /* lineNo */
    "imfilter", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\images\\images\\eml\\imfilter.m" /* pathName
                                                                       */
};

static emlrtRSInfo of_emlrtRSI = {
    84,         /* lineNo */
    "imfilter", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\images\\images\\eml\\imfilter.m" /* pathName
                                                                       */
};

static emlrtRSInfo pf_emlrtRSI = {
    88,         /* lineNo */
    "imfilter", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\images\\images\\eml\\imfilter.m" /* pathName
                                                                       */
};

static emlrtRSInfo qf_emlrtRSI = {
    106,        /* lineNo */
    "imfilter", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\images\\images\\eml\\imfilter.m" /* pathName
                                                                       */
};

static emlrtRSInfo rf_emlrtRSI = {
    110,        /* lineNo */
    "imfilter", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\images\\images\\eml\\imfilter.m" /* pathName
                                                                       */
};

static emlrtRSInfo sf_emlrtRSI = {
    688,           /* lineNo */
    "isSeparable", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\images\\images\\eml\\imfilter.m" /* pathName
                                                                       */
};

static emlrtRSInfo tf_emlrtRSI = {
    692,           /* lineNo */
    "isSeparable", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\images\\images\\eml\\imfilter.m" /* pathName
                                                                       */
};

static emlrtRSInfo cg_emlrtRSI = {
    854,        /* lineNo */
    "padImage", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\images\\images\\eml\\imfilter.m" /* pathName
                                                                       */
};

static emlrtRSInfo dg_emlrtRSI = {
    20,         /* lineNo */
    "padarray", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\images\\images\\eml\\padarray.m" /* pathName
                                                                       */
};

static emlrtRSInfo eg_emlrtRSI = {
    66,         /* lineNo */
    "padarray", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\images\\images\\eml\\padarray.m" /* pathName
                                                                       */
};

static emlrtRSInfo fg_emlrtRSI = {
    80,         /* lineNo */
    "padarray", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\images\\images\\eml\\padarray.m" /* pathName
                                                                       */
};

static emlrtRSInfo hg_emlrtRSI = {
    28,       /* lineNo */
    "repmat", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" /* pathName
                                                                         */
};

static emlrtRSInfo ig_emlrtRSI = {
    733,                 /* lineNo */
    "getPaddingIndices", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\images\\images\\eml\\padarray.m" /* pathName
                                                                       */
};

static emlrtRSInfo jg_emlrtRSI = {
    928,                 /* lineNo */
    "filterPartOrWhole", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\images\\images\\eml\\imfilter.m" /* pathName
                                                                       */
};

static emlrtRSInfo kg_emlrtRSI = {
    1002,           /* lineNo */
    "imfiltercore", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\images\\images\\eml\\imfilter.m" /* pathName
                                                                       */
};

static emlrtRTEInfo p_emlrtRTEI = {
    64,                   /* lineNo */
    15,                   /* colNo */
    "assertValidSizeArg", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\assertValidSizeArg.m" /* pName */
};

static emlrtRTEInfo q_emlrtRTEI = {
    49,                   /* lineNo */
    19,                   /* colNo */
    "assertValidSizeArg", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\assertValidSizeArg.m" /* pName */
};

static emlrtBCInfo sb_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    843,            /* lineNo */
    16,             /* colNo */
    "",             /* aName */
    "ReplicatePad", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\images\\images\\eml\\padarray.m", /* pName
                                                                        */
    0 /* checkKind */
};

static emlrtECInfo n_emlrtECI = {
    -1,             /* nDims */
    843,            /* lineNo */
    9,              /* colNo */
    "ReplicatePad", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\images\\images\\eml\\padarray.m" /* pName
                                                                       */
};

static emlrtDCInfo emlrtDCI = {
    827,            /* lineNo */
    33,             /* colNo */
    "ReplicatePad", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\images\\images\\eml\\padarray.m", /* pName
                                                                        */
    1 /* checkKind */
};

static emlrtBCInfo tb_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    100,        /* lineNo */
    32,         /* colNo */
    "",         /* aName */
    "padarray", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\images\\images\\eml\\padarray.m", /* pName
                                                                        */
    0 /* checkKind */
};

static emlrtBCInfo ub_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    100,        /* lineNo */
    37,         /* colNo */
    "",         /* aName */
    "padarray", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\images\\images\\eml\\padarray.m", /* pName
                                                                        */
    0 /* checkKind */
};

static emlrtBCInfo vb_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    100,        /* lineNo */
    42,         /* colNo */
    "",         /* aName */
    "padarray", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\images\\images\\eml\\padarray.m", /* pName
                                                                        */
    0 /* checkKind */
};

static emlrtBCInfo wb_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    100,        /* lineNo */
    47,         /* colNo */
    "",         /* aName */
    "padarray", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\images\\images\\eml\\padarray.m", /* pName
                                                                        */
    0 /* checkKind */
};

static emlrtBCInfo xb_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    100,        /* lineNo */
    23,         /* colNo */
    "",         /* aName */
    "padarray", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\images\\images\\eml\\padarray.m", /* pName
                                                                        */
    0 /* checkKind */
};

static emlrtBCInfo yb_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    100,        /* lineNo */
    25,         /* colNo */
    "",         /* aName */
    "padarray", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\images\\images\\eml\\padarray.m", /* pName
                                                                        */
    0 /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    83,         /* lineNo */
    56,         /* colNo */
    "padarray", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\images\\images\\eml\\padarray.m", /* pName
                                                                        */
    1 /* checkKind */
};

static emlrtRTEInfo w_emlrtRTEI = {
    13,     /* lineNo */
    9,      /* colNo */
    "sqrt", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m" /* pName
                                                                       */
};

static emlrtRTEInfo dd_emlrtRTEI = {
    827,        /* lineNo */
    27,         /* colNo */
    "padarray", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\images\\images\\eml\\padarray.m" /* pName
                                                                       */
};

static emlrtRTEInfo ed_emlrtRTEI =
    {
        28,      /* lineNo */
        9,       /* colNo */
        "colon", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" /* pName
                                                                          */
};

static emlrtRTEInfo fd_emlrtRTEI = {
    842,        /* lineNo */
    9,          /* colNo */
    "padarray", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\images\\images\\eml\\padarray.m" /* pName
                                                                       */
};

static emlrtRTEInfo gd_emlrtRTEI = {
    854,        /* lineNo */
    5,          /* colNo */
    "imfilter", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\images\\images\\eml\\imfilter.m" /* pName
                                                                       */
};

static emlrtRTEInfo hd_emlrtRTEI = {
    83,         /* lineNo */
    28,         /* colNo */
    "padarray", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\images\\images\\eml\\padarray.m" /* pName
                                                                       */
};

static emlrtRTEInfo id_emlrtRTEI = {
    80,         /* lineNo */
    5,          /* colNo */
    "padarray", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\images\\images\\eml\\padarray.m" /* pName
                                                                       */
};

static emlrtRTEInfo jd_emlrtRTEI = {
    836,        /* lineNo */
    9,          /* colNo */
    "padarray", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\images\\images\\eml\\padarray.m" /* pName
                                                                       */
};

static emlrtRTEInfo kd_emlrtRTEI = {
    842,        /* lineNo */
    30,         /* colNo */
    "padarray", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\images\\images\\eml\\padarray.m" /* pName
                                                                       */
};

static emlrtRTEInfo xd_emlrtRTEI = {
    1024,       /* lineNo */
    26,         /* colNo */
    "imfilter", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\images\\images\\eml\\imfilter.m" /* pName
                                                                       */
};

static emlrtRTEInfo yd_emlrtRTEI = {
    1002,       /* lineNo */
    28,         /* colNo */
    "imfilter", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\images\\images\\eml\\imfilter.m" /* pName
                                                                       */
};

static emlrtRTEInfo ae_emlrtRTEI = {
    59,         /* lineNo */
    9,          /* colNo */
    "imfilter", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\images\\images\\eml\\imfilter.m" /* pName
                                                                       */
};

/* Function Declarations */
static void padImage(const emlrtStack *sp, const emxArray_real_T *a_tmp,
                     const real_T pad[2], emxArray_real_T *a);

/* Function Definitions */
static void padImage(const emlrtStack *sp, const emxArray_real_T *a_tmp,
                     const real_T pad[2], emxArray_real_T *a)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_int32_T *idxA;
  emxArray_uint32_T *idxDir;
  emxArray_uint32_T *y;
  const real_T *a_tmp_data;
  real_T *a_data;
  int32_T b_i;
  int32_T i;
  int32_T j;
  int32_T *idxA_data;
  uint32_T *idxDir_data;
  uint32_T *y_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  a_tmp_data = a_tmp->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &cg_emlrtRSI;
  b_st.site = &dg_emlrtRSI;
  if ((a_tmp->size[0] == 0) || (a_tmp->size[1] == 0)) {
    real_T varargin_1[2];
    real_T sizeA_idx_0;
    real_T sizeA_idx_1;
    int32_T exitg2;
    int32_T loop_ub;
    boolean_T guard1 = false;
    sizeA_idx_0 = (real_T)a_tmp->size[0] + 2.0 * pad[0];
    sizeA_idx_1 = (real_T)a_tmp->size[1] + 2.0 * pad[1];
    b_st.site = &eg_emlrtRSI;
    varargin_1[0] = sizeA_idx_0;
    varargin_1[1] = sizeA_idx_1;
    c_st.site = &hg_emlrtRSI;
    loop_ub = 0;
    guard1 = false;
    do {
      exitg2 = 0;
      if (loop_ub < 2) {
        if ((varargin_1[loop_ub] != varargin_1[loop_ub]) ||
            muDoubleScalarIsInf(varargin_1[loop_ub])) {
          guard1 = true;
          exitg2 = 1;
        } else {
          loop_ub++;
          guard1 = false;
        }
      } else {
        loop_ub = 0;
        exitg2 = 2;
      }
    } while (exitg2 == 0);
    if (exitg2 != 1) {
      boolean_T exitg1;
      exitg1 = false;
      while ((!exitg1) && (loop_ub < 2)) {
        if (varargin_1[loop_ub] > 2.147483647E+9) {
          guard1 = true;
          exitg1 = true;
        } else {
          loop_ub++;
        }
      }
    }
    if (guard1) {
      emlrtErrorWithMessageIdR2018a(
          &c_st, &q_emlrtRTEI,
          "Coder:toolbox:eml_assert_valid_size_arg_invalidSizeVector",
          "Coder:toolbox:eml_assert_valid_size_arg_invalidSizeVector", 4, 12,
          MIN_int32_T, 12, MAX_int32_T);
    }
    if (!(sizeA_idx_0 * sizeA_idx_1 <= 2.147483647E+9)) {
      emlrtErrorWithMessageIdR2018a(&c_st, &p_emlrtRTEI,
                                    "Coder:MATLAB:pmaxsize",
                                    "Coder:MATLAB:pmaxsize", 0);
    }
    i = a->size[0] * a->size[1];
    a->size[0] = (int32_T)sizeA_idx_0;
    a->size[1] = (int32_T)sizeA_idx_1;
    emxEnsureCapacity_real_T(&b_st, a, i, &gd_emlrtRTEI);
    a_data = a->data;
    loop_ub = (int32_T)sizeA_idx_0 * (int32_T)sizeA_idx_1;
    for (i = 0; i < loop_ub; i++) {
      a_data[i] = 0.0;
    }
  } else {
    real_T sizeA_idx_0;
    real_T sizeA_idx_1;
    int32_T loop_ub;
    uint32_T u;
    b_st.site = &fg_emlrtRSI;
    c_st.site = &ig_emlrtRSI;
    if ((uint32_T)a_tmp->size[0] + 8U < (uint32_T)a_tmp->size[1] + 8U) {
      u = (uint32_T)a_tmp->size[1] + 8U;
    } else {
      u = (uint32_T)a_tmp->size[0] + 8U;
    }
    if ((real_T)u != (int32_T)u) {
      emlrtIntegerCheckR2012b(u, &emlrtDCI, &c_st);
    }
    emxInit_int32_T(&c_st, &idxA, 2, &id_emlrtRTEI);
    i = idxA->size[0] * idxA->size[1];
    idxA->size[0] = (int32_T)u;
    idxA->size[1] = 2;
    emxEnsureCapacity_int32_T(&c_st, idxA, i, &dd_emlrtRTEI);
    idxA_data = idxA->data;
    emxInit_uint32_T(&c_st, &y, &kd_emlrtRTEI);
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    loop_ub = a_tmp->size[0];
    y->size[1] = loop_ub;
    emxEnsureCapacity_uint32_T(&c_st, y, i, &ed_emlrtRTEI);
    y_data = y->data;
    loop_ub--;
    for (i = 0; i <= loop_ub; i++) {
      y_data[i] = (uint32_T)i + 1U;
    }
    emxInit_uint32_T(&c_st, &idxDir, &jd_emlrtRTEI);
    i = idxDir->size[0] * idxDir->size[1];
    idxDir->size[0] = 1;
    idxDir->size[1] = y->size[1] + 8;
    emxEnsureCapacity_uint32_T(&c_st, idxDir, i, &fd_emlrtRTEI);
    idxDir_data = idxDir->data;
    idxDir_data[0] = 1U;
    idxDir_data[1] = 1U;
    idxDir_data[2] = 1U;
    idxDir_data[3] = 1U;
    loop_ub = y->size[1];
    for (i = 0; i < loop_ub; i++) {
      idxDir_data[i + 4] = y_data[i];
    }
    idxDir_data[y->size[1] + 4] = (uint32_T)a_tmp->size[0];
    idxDir_data[y->size[1] + 5] = (uint32_T)a_tmp->size[0];
    idxDir_data[y->size[1] + 6] = (uint32_T)a_tmp->size[0];
    idxDir_data[y->size[1] + 7] = (uint32_T)a_tmp->size[0];
    if ((uint32_T)a_tmp->size[0] + 8U < (uint32_T)a_tmp->size[1] + 8U) {
      i = (int32_T)((uint32_T)a_tmp->size[1] + 8U);
    } else {
      i = (int32_T)((uint32_T)a_tmp->size[0] + 8U);
    }
    if ((idxDir->size[1] < 1) || (idxDir->size[1] > i)) {
      emlrtDynamicBoundsCheckR2012b(idxDir->size[1], 1, i, &sb_emlrtBCI, &c_st);
    }
    emlrtSubAssignSizeCheckR2012b(&idxDir->size[1], 1, &idxDir->size[0], 2,
                                  &n_emlrtECI, &c_st);
    loop_ub = idxDir->size[1];
    for (i = 0; i < loop_ub; i++) {
      idxA_data[i] = (int32_T)idxDir_data[i];
    }
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = a_tmp->size[1];
    emxEnsureCapacity_uint32_T(&c_st, y, i, &ed_emlrtRTEI);
    y_data = y->data;
    loop_ub = a_tmp->size[1] - 1;
    for (i = 0; i <= loop_ub; i++) {
      y_data[i] = (uint32_T)i + 1U;
    }
    i = idxDir->size[0] * idxDir->size[1];
    idxDir->size[0] = 1;
    idxDir->size[1] = y->size[1] + 8;
    emxEnsureCapacity_uint32_T(&c_st, idxDir, i, &fd_emlrtRTEI);
    idxDir_data = idxDir->data;
    idxDir_data[0] = 1U;
    idxDir_data[1] = 1U;
    idxDir_data[2] = 1U;
    idxDir_data[3] = 1U;
    loop_ub = y->size[1];
    for (i = 0; i < loop_ub; i++) {
      idxDir_data[i + 4] = y_data[i];
    }
    idxDir_data[y->size[1] + 4] = (uint32_T)a_tmp->size[1];
    idxDir_data[y->size[1] + 5] = (uint32_T)a_tmp->size[1];
    idxDir_data[y->size[1] + 6] = (uint32_T)a_tmp->size[1];
    idxDir_data[y->size[1] + 7] = (uint32_T)a_tmp->size[1];
    emxFree_uint32_T(&c_st, &y);
    if ((idxDir->size[1] < 1) || (idxDir->size[1] > idxA->size[0])) {
      emlrtDynamicBoundsCheckR2012b(idxDir->size[1], 1, idxA->size[0],
                                    &sb_emlrtBCI, &c_st);
    }
    emlrtSubAssignSizeCheckR2012b(&idxDir->size[1], 1, &idxDir->size[0], 2,
                                  &n_emlrtECI, &c_st);
    loop_ub = idxDir->size[1];
    for (i = 0; i < loop_ub; i++) {
      idxA_data[i + idxA->size[0]] = (int32_T)idxDir_data[i];
    }
    emxFree_uint32_T(&c_st, &idxDir);
    sizeA_idx_0 = (real_T)a_tmp->size[0] + 2.0 * pad[0];
    if (sizeA_idx_0 != (int32_T)muDoubleScalarFloor(sizeA_idx_0)) {
      emlrtIntegerCheckR2012b(sizeA_idx_0, &b_emlrtDCI, &st);
    }
    sizeA_idx_1 = (real_T)a_tmp->size[1] + 2.0 * pad[1];
    if (sizeA_idx_1 != (int32_T)muDoubleScalarFloor(sizeA_idx_1)) {
      emlrtIntegerCheckR2012b(sizeA_idx_1, &b_emlrtDCI, &st);
    }
    i = a->size[0] * a->size[1];
    a->size[0] = (int32_T)sizeA_idx_0;
    loop_ub = (int32_T)sizeA_idx_1;
    a->size[1] = (int32_T)sizeA_idx_1;
    emxEnsureCapacity_real_T(&st, a, i, &hd_emlrtRTEI);
    a_data = a->data;
    for (j = 0; j < loop_ub; j++) {
      i = a->size[0];
      for (b_i = 0; b_i < i; b_i++) {
        int32_T i1;
        int32_T i2;
        if (b_i + 1 > idxA->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, idxA->size[0], &ub_emlrtBCI,
                                        &st);
        }
        i1 = idxA_data[b_i];
        if (i1 > a_tmp->size[0]) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, a_tmp->size[0], &tb_emlrtBCI,
                                        &st);
        }
        if ((j + 1 < 1) || (j + 1 > idxA->size[0])) {
          emlrtDynamicBoundsCheckR2012b(j + 1, 1, idxA->size[0], &wb_emlrtBCI,
                                        &st);
        }
        i2 = idxA_data[j + idxA->size[0]];
        if (i2 > a_tmp->size[1]) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, a_tmp->size[1], &vb_emlrtBCI,
                                        &st);
        }
        if (b_i + 1 > a->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, a->size[0], &xb_emlrtBCI,
                                        &st);
        }
        if ((j + 1 < 1) || (j + 1 > a->size[1])) {
          emlrtDynamicBoundsCheckR2012b(j + 1, 1, a->size[1], &yb_emlrtBCI,
                                        &st);
        }
        a_data[b_i + a->size[0] * j] =
            a_tmp_data[(i1 + a_tmp->size[0] * (i2 - 1)) - 1];
      }
    }
    emxFree_int32_T(&st, &idxA);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void imfilter(const emlrtStack *sp, emxArray_real_T *varargin_1)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_real_T *a;
  real_T outSizeT[2];
  real_T startT[2];
  real_T *a_data;
  real_T *varargin_1_data;
  int32_T i;
  int32_T k;
  int8_T b_tmp_data[9];
  int8_T tmp_data[9];
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  outSizeT[0] = varargin_1->size[0];
  startT[0] = 4.0;
  outSizeT[1] = varargin_1->size[1];
  startT[1] = 4.0;
  if ((varargin_1->size[0] != 0) && (varargin_1->size[1] != 0)) {
    real_T a__1[81];
    real_T a__2[81];
    real_T s[81];
    real_T b_s[9];
    real_T tol;
    int32_T idx;
    boolean_T x[9];
    st.site = &jf_emlrtRSI;
    b_st.site = &sf_emlrtRSI;
    svd(&b_st, a__1, s, a__2);
    for (k = 0; k < 9; k++) {
      b_s[k] = s[k + 9 * k];
    }
    b_st.site = &tf_emlrtRSI;
    if (!muDoubleScalarIsNaN(b_s[0])) {
      idx = 1;
    } else {
      boolean_T exitg1;
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 10)) {
        if (!muDoubleScalarIsNaN(b_s[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      tol = b_s[0];
    } else {
      tol = b_s[idx - 1];
      i = idx + 1;
      for (k = i; k < 10; k++) {
        real_T d;
        d = b_s[k - 1];
        if (tol < d) {
          tol = d;
        }
      }
    }
    tol = 9.0 * tol * 2.2204460492503131E-16;
    for (i = 0; i < 9; i++) {
      x[i] = (b_s[i] > tol);
    }
    idx = x[0];
    for (k = 0; k < 8; k++) {
      idx += x[k + 1];
    }
    emxInit_real_T(sp, &a, 2, &ae_emlrtRTEI);
    if (idx == 1) {
      real_T hcol[9];
      real_T nonzero_h_data[9];
      real_T connDimsT[2];
      real_T out_size_row[2];
      real_T padSizeT[2];
      boolean_T tooBig;
      st.site = &kf_emlrtRSI;
      padImage(&st, varargin_1, startT, a);
      a_data = a->data;
      st.site = &lf_emlrtRSI;
      svd(&st, a__1, s, a__2);
      for (k = 0; k < 9; k++) {
        b_s[k] = s[k + 9 * k];
      }
      st.site = &mf_emlrtRSI;
      if (b_s[0] < 0.0) {
        emlrtErrorWithMessageIdR2018a(
            &st, &w_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
            "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
      }
      tol = muDoubleScalarSqrt(b_s[0]);
      for (i = 0; i < 9; i++) {
        hcol[i] = a__1[i] * tol;
      }
      st.site = &nf_emlrtRSI;
      for (i = 0; i < 9; i++) {
        b_s[i] = a__2[i] * tol;
      }
      out_size_row[0] = a->size[0];
      out_size_row[1] = varargin_1->size[1];
      st.site = &of_emlrtRSI;
      k = 0;
      idx = 0;
      for (i = 0; i < 9; i++) {
        if (b_s[i] != 0.0) {
          k++;
          tmp_data[idx] = (int8_T)(i + 1);
          idx++;
        }
      }
      b_st.site = &jg_emlrtRSI;
      for (i = 0; i < k; i++) {
        nonzero_h_data[i] = b_s[tmp_data[i] - 1];
      }
      for (i = 0; i < 9; i++) {
        x[i] = (b_s[i] != 0.0);
      }
      tooBig = true;
      if ((a->size[0] <= 65500) || (!(out_size_row[1] > 65500.0))) {
        tooBig = false;
      }
      if (((real_T)k / 9.0 > 0.05) && (!tooBig)) {
        tooBig = true;
      } else {
        tooBig = false;
      }
      c_st.site = &kg_emlrtRSI;
      i = varargin_1->size[0] * varargin_1->size[1];
      varargin_1->size[0] = a->size[0];
      varargin_1->size[1] = (int32_T)out_size_row[1];
      emxEnsureCapacity_real_T(&c_st, varargin_1, i, &xd_emlrtRTEI);
      varargin_1_data = varargin_1->data;
      if (tooBig) {
        padSizeT[0] = a->size[0];
        startT[0] = 1.0;
        padSizeT[1] = a->size[1];
        startT[1] = 9.0;
        ippfilter_real64(&a_data[0], &varargin_1_data[0], &out_size_row[0], 2.0,
                         &padSizeT[0], &b_s[0], &startT[0], false);
      } else {
        padSizeT[0] = a->size[0];
        connDimsT[0] = 1.0;
        startT[0] = 0.0;
        padSizeT[1] = a->size[1];
        connDimsT[1] = 9.0;
        startT[1] = 4.0;
        imfilter_real64(&a_data[0], &varargin_1_data[0], 2.0, &out_size_row[0],
                        2.0, &padSizeT[0], &nonzero_h_data[0], (real_T)k, &x[0],
                        2.0, &connDimsT[0], &startT[0], 2.0, true, false);
      }
      st.site = &pf_emlrtRSI;
      k = 0;
      idx = 0;
      for (i = 0; i < 9; i++) {
        if (hcol[i] != 0.0) {
          k++;
          b_tmp_data[idx] = (int8_T)(i + 1);
          idx++;
        }
      }
      b_st.site = &jg_emlrtRSI;
      for (i = 0; i < k; i++) {
        nonzero_h_data[i] = hcol[b_tmp_data[i] - 1];
      }
      for (i = 0; i < 9; i++) {
        x[i] = (hcol[i] != 0.0);
      }
      tooBig = true;
      if ((outSizeT[0] <= 65500.0) || (!(outSizeT[1] > 65500.0))) {
        tooBig = false;
      }
      if (((real_T)k / 9.0 > 0.05) && (!tooBig)) {
        tooBig = true;
      } else {
        tooBig = false;
      }
      c_st.site = &kg_emlrtRSI;
      i = a->size[0] * a->size[1];
      a->size[0] = varargin_1->size[0];
      a->size[1] = varargin_1->size[1];
      emxEnsureCapacity_real_T(&c_st, a, i, &yd_emlrtRTEI);
      a_data = a->data;
      idx = varargin_1->size[0] * varargin_1->size[1];
      for (i = 0; i < idx; i++) {
        a_data[i] = varargin_1_data[i];
      }
      i = varargin_1->size[0] * varargin_1->size[1];
      varargin_1->size[0] = (int32_T)outSizeT[0];
      varargin_1->size[1] = (int32_T)outSizeT[1];
      emxEnsureCapacity_real_T(&c_st, varargin_1, i, &xd_emlrtRTEI);
      varargin_1_data = varargin_1->data;
      if (tooBig) {
        padSizeT[0] = a->size[0];
        startT[0] = 9.0;
        padSizeT[1] = a->size[1];
        startT[1] = 1.0;
        ippfilter_real64(&a_data[0], &varargin_1_data[0], &outSizeT[0], 2.0,
                         &padSizeT[0], &hcol[0], &startT[0], false);
      } else {
        padSizeT[0] = a->size[0];
        connDimsT[0] = 9.0;
        startT[0] = 4.0;
        padSizeT[1] = a->size[1];
        connDimsT[1] = 1.0;
        startT[1] = 0.0;
        imfilter_real64(&a_data[0], &varargin_1_data[0], 2.0, &outSizeT[0], 2.0,
                        &padSizeT[0], &nonzero_h_data[0], (real_T)k, &x[0], 2.0,
                        &connDimsT[0], &startT[0], 2.0, true, false);
      }
    } else {
      boolean_T tooBig;
      st.site = &qf_emlrtRSI;
      padImage(&st, varargin_1, startT, a);
      a_data = a->data;
      st.site = &rf_emlrtRSI;
      b_st.site = &jg_emlrtRSI;
      tooBig = true;
      if ((outSizeT[0] <= 65500.0) || (!(outSizeT[1] > 65500.0))) {
        tooBig = false;
      }
      c_st.site = &kg_emlrtRSI;
      i = varargin_1->size[0] * varargin_1->size[1];
      varargin_1->size[0] = (int32_T)outSizeT[0];
      varargin_1->size[1] = (int32_T)outSizeT[1];
      emxEnsureCapacity_real_T(&c_st, varargin_1, i, &xd_emlrtRTEI);
      varargin_1_data = varargin_1->data;
      if (!tooBig) {
        real_T padSizeT[2];
        padSizeT[0] = a->size[0];
        startT[0] = 9.0;
        padSizeT[1] = a->size[1];
        startT[1] = 9.0;
        ippfilter_real64(&a_data[0], &varargin_1_data[0], &outSizeT[0], 2.0,
                         &padSizeT[0], &dv[0], &startT[0], false);
      } else {
        real_T padSizeT[2];
        boolean_T conn[81];
        padSizeT[0] = a->size[0];
        padSizeT[1] = a->size[1];
        for (i = 0; i < 81; i++) {
          conn[i] = true;
        }
        real_T connDimsT[2];
        connDimsT[0] = 9.0;
        connDimsT[1] = 9.0;
        imfilter_real64(&a_data[0], &varargin_1_data[0], 2.0, &outSizeT[0], 2.0,
                        &padSizeT[0], &dv[0], 81.0, &conn[0], 2.0,
                        &connDimsT[0], &startT[0], 2.0, true, false);
      }
    }
    emxFree_real_T(sp, &a);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (imfilter.c) */
