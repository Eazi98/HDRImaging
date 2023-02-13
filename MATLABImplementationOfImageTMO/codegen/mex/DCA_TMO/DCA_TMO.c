/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * DCA_TMO.c
 *
 * Code generation for function 'DCA_TMO'
 *
 */

/* Include files */
#include "DCA_TMO.h"
#include "DCA_TMO_data.h"
#include "DCA_TMO_emxutil.h"
#include "DCA_TMO_types.h"
#include "MaxQuart.h"
#include "assertCompatibleDims.h"
#include "atan.h"
#include "eml_int_forloop_overflow_check.h"
#include "imfilter.h"
#include "power.h"
#include "quantizeNL_float.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    8,         /* lineNo */
    "DCA_TMO", /* fcnName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pathName */
};

static emlrtRSInfo b_emlrtRSI = {
    9,         /* lineNo */
    "DCA_TMO", /* fcnName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pathName */
};

static emlrtRSInfo c_emlrtRSI = {
    15,        /* lineNo */
    "DCA_TMO", /* fcnName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pathName */
};

static emlrtRSInfo d_emlrtRSI = {
    16,        /* lineNo */
    "DCA_TMO", /* fcnName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pathName */
};

static emlrtRSInfo e_emlrtRSI = {
    17,        /* lineNo */
    "DCA_TMO", /* fcnName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pathName */
};

static emlrtRSInfo f_emlrtRSI = {
    26,        /* lineNo */
    "DCA_TMO", /* fcnName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pathName */
};

static emlrtRSInfo g_emlrtRSI = {
    28,        /* lineNo */
    "DCA_TMO", /* fcnName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pathName */
};

static emlrtRSInfo h_emlrtRSI = {
    31,        /* lineNo */
    "DCA_TMO", /* fcnName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pathName */
};

static emlrtRSInfo i_emlrtRSI = {
    32,        /* lineNo */
    "DCA_TMO", /* fcnName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pathName */
};

static emlrtRSInfo j_emlrtRSI = {
    34,        /* lineNo */
    "DCA_TMO", /* fcnName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pathName */
};

static emlrtRSInfo k_emlrtRSI = {
    35,        /* lineNo */
    "DCA_TMO", /* fcnName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pathName */
};

static emlrtRSInfo l_emlrtRSI = {
    36,        /* lineNo */
    "DCA_TMO", /* fcnName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pathName */
};

static emlrtRSInfo m_emlrtRSI = {
    38,        /* lineNo */
    "DCA_TMO", /* fcnName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pathName */
};

static emlrtRSInfo n_emlrtRSI = {
    39,        /* lineNo */
    "DCA_TMO", /* fcnName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pathName */
};

static emlrtRSInfo o_emlrtRSI = {
    45,        /* lineNo */
    "DCA_TMO", /* fcnName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pathName */
};

static emlrtRSInfo p_emlrtRSI = {
    46,        /* lineNo */
    "DCA_TMO", /* fcnName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pathName */
};

static emlrtRSInfo kc_emlrtRSI = {
    34,               /* lineNo */
    "rdivide_helper", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\rdivide_"
    "helper.m" /* pathName */
};

static emlrtRSInfo lc_emlrtRSI = {
    51,    /* lineNo */
    "div", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\div.m" /* pathName
                                                                          */
};

static emlrtRTEInfo emlrtRTEI = {
    15,                     /* lineNo */
    27,                     /* colNo */
    "assertCompatibleDims", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\assertCompatibleDims.m" /* pName */
};

static emlrtECInfo emlrtECI = {
    2,         /* nDims */
    34,        /* lineNo */
    14,        /* colNo */
    "DCA_TMO", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pName */
};

static emlrtECInfo b_emlrtECI = {
    1,         /* nDims */
    34,        /* lineNo */
    14,        /* colNo */
    "DCA_TMO", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pName */
};

static emlrtECInfo c_emlrtECI = {
    2,         /* nDims */
    28,        /* lineNo */
    14,        /* colNo */
    "DCA_TMO", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pName */
};

static emlrtECInfo d_emlrtECI = {
    1,         /* nDims */
    28,        /* lineNo */
    14,        /* colNo */
    "DCA_TMO", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pName */
};

static emlrtECInfo e_emlrtECI = {
    2,         /* nDims */
    27,        /* lineNo */
    12,        /* colNo */
    "DCA_TMO", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pName */
};

static emlrtECInfo f_emlrtECI = {
    1,         /* nDims */
    27,        /* lineNo */
    12,        /* colNo */
    "DCA_TMO", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pName */
};

static emlrtECInfo g_emlrtECI = {
    2,         /* nDims */
    14,        /* lineNo */
    10,        /* colNo */
    "DCA_TMO", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pName */
};

static emlrtECInfo h_emlrtECI = {
    1,         /* nDims */
    14,        /* lineNo */
    10,        /* colNo */
    "DCA_TMO", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pName */
};

static emlrtBCInfo emlrtBCI = {
    -1,        /* iFirst */
    -1,        /* iLast */
    10,        /* lineNo */
    1,         /* colNo */
    "hdrImg",  /* aName */
    "DCA_TMO", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,        /* iFirst */
    -1,        /* iLast */
    11,        /* lineNo */
    1,         /* colNo */
    "hdrImg",  /* aName */
    "DCA_TMO", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    51,           /* lineNo */
    1,            /* colNo */
    "ldrImg_DoG", /* aName */
    "DCA_TMO",    /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m", /* pName */
    0                              /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    52,           /* lineNo */
    1,            /* colNo */
    "ldrImg_DoG", /* aName */
    "DCA_TMO",    /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m", /* pName */
    0                              /* checkKind */
};

static emlrtRTEInfo x_emlrtRTEI = {
    8,         /* lineNo */
    19,        /* colNo */
    "DCA_TMO", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pName */
};

static emlrtRTEInfo y_emlrtRTEI = {
    9,         /* lineNo */
    19,        /* colNo */
    "DCA_TMO", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = {
    1,         /* lineNo */
    19,        /* colNo */
    "DCA_TMO", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = {
    14,        /* lineNo */
    10,        /* colNo */
    "DCA_TMO", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = {
    14,        /* lineNo */
    35,        /* colNo */
    "DCA_TMO", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pName */
};

static emlrtRTEInfo db_emlrtRTEI = {
    14,        /* lineNo */
    60,        /* colNo */
    "DCA_TMO", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pName */
};

static emlrtRTEInfo eb_emlrtRTEI = {
    15,        /* lineNo */
    1,         /* colNo */
    "DCA_TMO", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pName */
};

static emlrtRTEInfo fb_emlrtRTEI = {
    52,    /* lineNo */
    9,     /* colNo */
    "div", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\div.m" /* pName
                                                                          */
};

static emlrtRTEInfo gb_emlrtRTEI = {
    27,        /* lineNo */
    31,        /* colNo */
    "DCA_TMO", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pName */
};

static emlrtRTEInfo hb_emlrtRTEI = {
    32,        /* lineNo */
    9,         /* colNo */
    "DCA_TMO", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pName */
};

static emlrtRTEInfo ib_emlrtRTEI = {
    35,        /* lineNo */
    17,        /* colNo */
    "DCA_TMO", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pName */
};

static emlrtRTEInfo jb_emlrtRTEI = {
    34,        /* lineNo */
    14,        /* colNo */
    "DCA_TMO", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pName */
};

static emlrtRTEInfo kb_emlrtRTEI = {
    36,        /* lineNo */
    17,        /* colNo */
    "DCA_TMO", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pName */
};

static emlrtRTEInfo lb_emlrtRTEI = {
    34,        /* lineNo */
    1,         /* colNo */
    "DCA_TMO", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pName */
};

static emlrtRTEInfo mb_emlrtRTEI = {
    53,        /* lineNo */
    1,         /* colNo */
    "DCA_TMO", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pName */
};

static emlrtRTEInfo nb_emlrtRTEI = {
    14,        /* lineNo */
    1,         /* colNo */
    "DCA_TMO", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pName */
};

static emlrtRTEInfo ob_emlrtRTEI = {
    28,        /* lineNo */
    1,         /* colNo */
    "DCA_TMO", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pName */
};

static emlrtRTEInfo pb_emlrtRTEI = {
    10,        /* lineNo */
    8,         /* colNo */
    "DCA_TMO", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pName */
};

static emlrtRTEInfo qb_emlrtRTEI = {
    11,        /* lineNo */
    8,         /* colNo */
    "DCA_TMO", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pName */
};

static emlrtRTEInfo rb_emlrtRTEI = {
    51,        /* lineNo */
    12,        /* colNo */
    "DCA_TMO", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pName */
};

static emlrtRTEInfo sb_emlrtRTEI = {
    52,        /* lineNo */
    12,        /* colNo */
    "DCA_TMO", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pName */
};

static emlrtRTEInfo tb_emlrtRTEI = {
    16,        /* lineNo */
    30,        /* colNo */
    "DCA_TMO", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pName */
};

static emlrtRTEInfo be_emlrtRTEI = {
    28,        /* lineNo */
    14,        /* colNo */
    "DCA_TMO", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pName */
};

static emlrtRSInfo ah_emlrtRSI = {
    14,        /* lineNo */
    "DCA_TMO", /* fcnName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\DCA_TMO.m" /* pathName */
};

/* Function Declarations */
static void b_binary_expand_op(const emlrtStack *sp, emxArray_real_T *in1,
                               const emlrtRSInfo in2,
                               const emxArray_real_T *in3,
                               const emxArray_real_T *in4,
                               const emxArray_real_T *in5);

static void binary_expand_op(const emlrtStack *sp, emxArray_real_T *in1,
                             const emxArray_real_T *in2);

static void c_binary_expand_op(const emlrtStack *sp, emxArray_real_T *in1,
                               const emxArray_real_T *in2,
                               const emxArray_real_T *in3);

static void plus(const emlrtStack *sp, emxArray_real_T *in1,
                 const emxArray_real_T *in2);

/* Function Definitions */
static void b_binary_expand_op(const emlrtStack *sp, emxArray_real_T *in1,
                               const emlrtRSInfo in2,
                               const emxArray_real_T *in3,
                               const emxArray_real_T *in4,
                               const emxArray_real_T *in5)
{
  emlrtStack st;
  emxArray_real_T *b_in3;
  const real_T *in3_data;
  const real_T *in4_data;
  real_T *b_in3_data;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T in4_idx_0;
  int32_T in4_idx_1;
  int32_T stride_0_0;
  int32_T stride_0_1;
  int32_T stride_1_0;
  int32_T stride_1_1;
  st.prev = sp;
  st.tls = sp->tls;
  in4_data = in4->data;
  in3_data = in3->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  in4_idx_0 = in4->size[0];
  in4_idx_1 = in4->size[1];
  emxInit_real_T(sp, &b_in3, 3, &fb_emlrtRTEI);
  i = b_in3->size[0] * b_in3->size[1] * b_in3->size[2];
  if (in4_idx_0 == 1) {
    b_in3->size[0] = in3->size[0];
  } else {
    b_in3->size[0] = in4_idx_0;
  }
  if (in4_idx_1 == 1) {
    b_in3->size[1] = in3->size[1];
  } else {
    b_in3->size[1] = in4_idx_1;
  }
  b_in3->size[2] = 3;
  emxEnsureCapacity_real_T(sp, b_in3, i, &fb_emlrtRTEI);
  b_in3_data = b_in3->data;
  stride_0_0 = (in3->size[0] != 1);
  stride_0_1 = (in3->size[1] != 1);
  stride_1_0 = (in4_idx_0 != 1);
  stride_1_1 = (in4_idx_1 != 1);
  if (in4_idx_1 == 1) {
    in4_idx_1 = in3->size[1];
  }
  for (i = 0; i < 3; i++) {
    int32_T aux_0_1;
    int32_T aux_1_1;
    aux_0_1 = 0;
    aux_1_1 = 0;
    for (i1 = 0; i1 < in4_idx_1; i1++) {
      int32_T loop_ub;
      if (in4_idx_0 == 1) {
        loop_ub = in3->size[0];
      } else {
        loop_ub = in4_idx_0;
      }
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_in3_data[(i2 + b_in3->size[0] * i1) +
                   b_in3->size[0] * b_in3->size[1] * i] =
            in3_data[(i2 * stride_0_0 + in3->size[0] * aux_0_1) +
                     in3->size[0] * in3->size[1] * i] /
            in4_data[i2 * stride_1_0 + in4_idx_0 * aux_1_1];
      }
      aux_1_1 += stride_1_1;
      aux_0_1 += stride_0_1;
    }
  }
  st.site = (emlrtRSInfo *)&in2;
  c_power(&st, b_in3, in5, in1);
  emxFree_real_T(sp, &b_in3);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void binary_expand_op(const emlrtStack *sp, emxArray_real_T *in1,
                             const emxArray_real_T *in2)
{
  emxArray_real_T *b_in1;
  const real_T *in2_data;
  real_T *b_in1_data;
  real_T *in1_data;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T in2_idx_0;
  int32_T in2_idx_1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_1;
  int32_T stride_1_0;
  int32_T stride_1_1;
  in2_data = in2->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  in2_idx_0 = in2->size[0];
  in2_idx_1 = in2->size[1];
  emxInit_real_T(sp, &b_in1, 3, &jb_emlrtRTEI);
  i = b_in1->size[0] * b_in1->size[1] * b_in1->size[2];
  if (in2_idx_0 == 1) {
    b_in1->size[0] = in1->size[0];
  } else {
    b_in1->size[0] = in2_idx_0;
  }
  if (in2_idx_1 == 1) {
    b_in1->size[1] = in1->size[1];
  } else {
    b_in1->size[1] = in2_idx_1;
  }
  b_in1->size[2] = 3;
  emxEnsureCapacity_real_T(sp, b_in1, i, &jb_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_1 = (in1->size[1] != 1);
  stride_1_0 = (in2_idx_0 != 1);
  stride_1_1 = (in2_idx_1 != 1);
  if (in2_idx_1 == 1) {
    in2_idx_1 = in1->size[1];
  }
  for (i = 0; i < 3; i++) {
    int32_T aux_0_1;
    int32_T aux_1_1;
    aux_0_1 = 0;
    aux_1_1 = 0;
    for (i1 = 0; i1 < in2_idx_1; i1++) {
      if (in2_idx_0 == 1) {
        loop_ub = in1->size[0];
      } else {
        loop_ub = in2_idx_0;
      }
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_in1_data[(i2 + b_in1->size[0] * i1) +
                   b_in1->size[0] * b_in1->size[1] * i] =
            in1_data[(i2 * stride_0_0 + in1->size[0] * aux_0_1) +
                     in1->size[0] * in1->size[1] * i] *
            in2_data[i2 * stride_1_0 + in2_idx_0 * aux_1_1];
      }
      aux_1_1 += stride_1_1;
      aux_0_1 += stride_0_1;
    }
  }
  i = in1->size[0] * in1->size[1] * in1->size[2];
  in1->size[0] = b_in1->size[0];
  in1->size[1] = b_in1->size[1];
  in1->size[2] = 3;
  emxEnsureCapacity_real_T(sp, in1, i, &jb_emlrtRTEI);
  in1_data = in1->data;
  in2_idx_1 = b_in1->size[1];
  for (i = 0; i < 3; i++) {
    for (i1 = 0; i1 < in2_idx_1; i1++) {
      loop_ub = b_in1->size[0];
      for (i2 = 0; i2 < loop_ub; i2++) {
        in1_data[(i2 + in1->size[0] * i1) + in1->size[0] * in1->size[1] * i] =
            b_in1_data[(i2 + b_in1->size[0] * i1) +
                       b_in1->size[0] * b_in1->size[1] * i];
      }
    }
  }
  emxFree_real_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void c_binary_expand_op(const emlrtStack *sp, emxArray_real_T *in1,
                               const emxArray_real_T *in2,
                               const emxArray_real_T *in3)
{
  emxArray_real_T *b_in1;
  const real_T *in2_data;
  const real_T *in3_data;
  real_T *b_in1_data;
  real_T *in1_data;
  int32_T aux_0_1;
  int32_T aux_1_1;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_1;
  int32_T stride_1_0;
  int32_T stride_1_1;
  in3_data = in3->data;
  in2_data = in2->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in1, 2, &bb_emlrtRTEI);
  i = b_in1->size[0] * b_in1->size[1];
  if (in3->size[0] == 1) {
    b_in1->size[0] = in1->size[0];
  } else {
    b_in1->size[0] = in3->size[0];
  }
  if (in3->size[1] == 1) {
    b_in1->size[1] = in1->size[1];
  } else {
    b_in1->size[1] = in3->size[1];
  }
  emxEnsureCapacity_real_T(sp, b_in1, i, &bb_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_1 = (in1->size[1] != 1);
  stride_1_0 = (in3->size[0] != 1);
  stride_1_1 = (in3->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  if (in3->size[1] == 1) {
    loop_ub = in1->size[1];
  } else {
    loop_ub = in3->size[1];
  }
  for (i = 0; i < loop_ub; i++) {
    i1 = in3->size[0];
    if (i1 == 1) {
      b_loop_ub = in1->size[0];
    } else {
      b_loop_ub = i1;
    }
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_in1_data[i1 + b_in1->size[0] * i] =
          (in1_data[i1 * stride_0_0 + in1->size[0] * aux_0_1] +
           in2_data[i1 * stride_0_0 + in2->size[0] * aux_0_1]) +
          in3_data[i1 * stride_1_0 + in3->size[0] * aux_1_1];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = b_in1->size[0];
  in1->size[1] = b_in1->size[1];
  emxEnsureCapacity_real_T(sp, in1, i, &bb_emlrtRTEI);
  in1_data = in1->data;
  loop_ub = b_in1->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = b_in1->size[0];
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] = b_in1_data[i1 + b_in1->size[0] * i];
    }
  }
  emxFree_real_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void plus(const emlrtStack *sp, emxArray_real_T *in1,
                 const emxArray_real_T *in2)
{
  emxArray_real_T *b_in1;
  const real_T *in2_data;
  real_T *b_in1_data;
  real_T *in1_data;
  int32_T aux_0_1;
  int32_T aux_1_1;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_1;
  int32_T stride_1_0;
  int32_T stride_1_1;
  in2_data = in2->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in1, 2, &be_emlrtRTEI);
  i = b_in1->size[0] * b_in1->size[1];
  if (in2->size[0] == 1) {
    b_in1->size[0] = in1->size[0];
  } else {
    b_in1->size[0] = in2->size[0];
  }
  if (in2->size[1] == 1) {
    b_in1->size[1] = in1->size[1];
  } else {
    b_in1->size[1] = in2->size[1];
  }
  emxEnsureCapacity_real_T(sp, b_in1, i, &be_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_1 = (in1->size[1] != 1);
  stride_1_0 = (in2->size[0] != 1);
  stride_1_1 = (in2->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  if (in2->size[1] == 1) {
    loop_ub = in1->size[1];
  } else {
    loop_ub = in2->size[1];
  }
  for (i = 0; i < loop_ub; i++) {
    i1 = in2->size[0];
    if (i1 == 1) {
      b_loop_ub = in1->size[0];
    } else {
      b_loop_ub = i1;
    }
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_in1_data[i1 + b_in1->size[0] * i] =
          in1_data[i1 * stride_0_0 + in1->size[0] * aux_0_1] +
          in2_data[i1 * stride_1_0 + in2->size[0] * aux_1_1];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = b_in1->size[0];
  in1->size[1] = b_in1->size[1];
  emxEnsureCapacity_real_T(sp, in1, i, &be_emlrtRTEI);
  in1_data = in1->data;
  loop_ub = b_in1->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = b_in1->size[0];
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] = b_in1_data[i1 + b_in1->size[0] * i];
    }
  }
  emxFree_real_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void DCA_TMO(const emlrtStack *sp, emxArray_real_T *hdrImg,
             emxArray_real_T *ldrImg)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack st;
  emxArray_int32_T *r;
  emxArray_int32_T *r2;
  emxArray_int32_T *r3;
  emxArray_int32_T *r4;
  emxArray_real_T *a__2;
  emxArray_real_T *b;
  emxArray_real_T *b_b;
  emxArray_real_T *b_hdrImg;
  emxArray_real_T *c_hdrImg;
  emxArray_real_T *hdrLum;
  emxArray_real_T *hdrLum1;
  emxArray_real_T *labels_DoG;
  real_T a__1[55];
  real_T ex;
  real_T maxhdr;
  real_T minhdr;
  real_T *b_data;
  real_T *b_hdrImg_data;
  real_T *hdrImg_data;
  real_T *hdrLum1_data;
  real_T *hdrLum_data;
  real_T *labels_DoG_data;
  int32_T i;
  int32_T i1;
  int32_T idx;
  int32_T k;
  int32_T last;
  int32_T loop_ub;
  int32_T *r1;
  boolean_T exitg1;
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
  hdrImg_data = hdrImg->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  covrtLogFcn(&emlrtCoverageInstance, 0U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 0U);
  /*  set parameters */
  /*  pre-processing */
  /*  [N, M, C] = size(hdrImg); */
  last = hdrImg->size[0] * hdrImg->size[1] * 3;
  emxInit_real_T(sp, &b_hdrImg, 1, &x_emlrtRTEI);
  i = b_hdrImg->size[0];
  b_hdrImg->size[0] = last;
  emxEnsureCapacity_real_T(sp, b_hdrImg, i, &x_emlrtRTEI);
  b_hdrImg_data = b_hdrImg->data;
  loop_ub = last - 1;
  for (i = 0; i <= loop_ub; i++) {
    b_hdrImg_data[i] = hdrImg_data[i];
  }
  st.site = &emlrtRSI;
  maxhdr = MaxQuart(&st, b_hdrImg);
  last = hdrImg->size[0] * hdrImg->size[1] * 3;
  i = b_hdrImg->size[0];
  b_hdrImg->size[0] = last;
  emxEnsureCapacity_real_T(sp, b_hdrImg, i, &y_emlrtRTEI);
  b_hdrImg_data = b_hdrImg->data;
  loop_ub = last - 1;
  for (i = 0; i <= loop_ub; i++) {
    b_hdrImg_data[i] = hdrImg_data[i];
  }
  st.site = &b_emlrtRSI;
  minhdr = b_MaxQuart(&st, b_hdrImg);
  idx = hdrImg->size[0] * (hdrImg->size[1] * 3) - 1;
  last = 0;
  for (loop_ub = 0; loop_ub <= idx; loop_ub++) {
    if (hdrImg_data[loop_ub] > maxhdr) {
      last++;
    }
  }
  emxInit_int32_T(sp, &r, 1, &pb_emlrtRTEI);
  i = r->size[0];
  r->size[0] = last;
  emxEnsureCapacity_int32_T(sp, r, i, &ab_emlrtRTEI);
  r1 = r->data;
  last = 0;
  for (loop_ub = 0; loop_ub <= idx; loop_ub++) {
    if (hdrImg_data[loop_ub] > maxhdr) {
      r1[last] = loop_ub + 1;
      last++;
    }
  }
  last = hdrImg->size[0] * hdrImg->size[1] * 3;
  loop_ub = r->size[0];
  for (i = 0; i < loop_ub; i++) {
    if ((r1[i] < 1) || (r1[i] > last)) {
      emlrtDynamicBoundsCheckR2012b(r1[i], 1, last, &emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    hdrImg_data[r1[i] - 1] = maxhdr;
  }
  emxFree_int32_T(sp, &r);
  idx = hdrImg->size[0] * (hdrImg->size[1] * 3) - 1;
  last = 0;
  for (loop_ub = 0; loop_ub <= idx; loop_ub++) {
    if (hdrImg_data[loop_ub] < minhdr) {
      last++;
    }
  }
  emxInit_int32_T(sp, &r2, 1, &qb_emlrtRTEI);
  i = r2->size[0];
  r2->size[0] = last;
  emxEnsureCapacity_int32_T(sp, r2, i, &ab_emlrtRTEI);
  r1 = r2->data;
  last = 0;
  for (loop_ub = 0; loop_ub <= idx; loop_ub++) {
    if (hdrImg_data[loop_ub] < minhdr) {
      r1[last] = loop_ub + 1;
      last++;
    }
  }
  last = hdrImg->size[0] * hdrImg->size[1] * 3;
  loop_ub = r2->size[0];
  for (i = 0; i < loop_ub; i++) {
    if ((r1[i] < 1) || (r1[i] > last)) {
      emlrtDynamicBoundsCheckR2012b(r1[i], 1, last, &b_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    hdrImg_data[r1[i] - 1] = minhdr;
  }
  emxFree_int32_T(sp, &r2);
  /*  tone map using clustering method */
  emxInit_real_T(sp, &hdrLum, 2, &nb_emlrtRTEI);
  i = hdrLum->size[0] * hdrLum->size[1];
  hdrLum->size[0] = hdrImg->size[0];
  hdrLum->size[1] = hdrImg->size[1];
  emxEnsureCapacity_real_T(sp, hdrLum, i, &bb_emlrtRTEI);
  hdrLum_data = hdrLum->data;
  loop_ub = hdrImg->size[1];
  for (i = 0; i < loop_ub; i++) {
    last = hdrImg->size[0];
    for (k = 0; k < last; k++) {
      hdrLum_data[k + hdrLum->size[0] * i] =
          0.2126 * hdrImg_data[k + hdrImg->size[0] * i];
    }
  }
  emxInit_real_T(sp, &b, 2, &tb_emlrtRTEI);
  i = b->size[0] * b->size[1];
  b->size[0] = hdrImg->size[0];
  b->size[1] = hdrImg->size[1];
  emxEnsureCapacity_real_T(sp, b, i, &cb_emlrtRTEI);
  b_data = b->data;
  loop_ub = hdrImg->size[1];
  for (i = 0; i < loop_ub; i++) {
    last = hdrImg->size[0];
    for (k = 0; k < last; k++) {
      b_data[k + b->size[0] * i] =
          0.7152 * hdrImg_data[(k + hdrImg->size[0] * i) +
                               hdrImg->size[0] * hdrImg->size[1]];
    }
  }
  if ((hdrLum->size[0] != b->size[0]) || (hdrLum->size[1] != b->size[1])) {
    emlrtSizeEqCheckNDErrorR2021b(&hdrLum->size[0], &b->size[0], &g_emlrtECI,
                                  (emlrtCTX)sp);
  }
  emxInit_real_T(sp, &hdrLum1, 2, &eb_emlrtRTEI);
  i = hdrLum1->size[0] * hdrLum1->size[1];
  hdrLum1->size[0] = hdrImg->size[0];
  hdrLum1->size[1] = hdrImg->size[1];
  emxEnsureCapacity_real_T(sp, hdrLum1, i, &db_emlrtRTEI);
  hdrLum1_data = hdrLum1->data;
  loop_ub = hdrImg->size[1];
  for (i = 0; i < loop_ub; i++) {
    last = hdrImg->size[0];
    for (k = 0; k < last; k++) {
      hdrLum1_data[k + hdrLum1->size[0] * i] =
          0.0722 * hdrImg_data[(k + hdrImg->size[0] * i) +
                               hdrImg->size[0] * hdrImg->size[1] * 2];
    }
  }
  if ((hdrLum->size[0] != hdrLum1->size[0]) &&
      ((hdrLum->size[0] != 1) && (hdrLum1->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(hdrLum->size[0], hdrLum1->size[0], &h_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  if ((hdrLum->size[1] != hdrLum1->size[1]) &&
      ((hdrLum->size[1] != 1) && (hdrLum1->size[1] != 1))) {
    emlrtDimSizeImpxCheckR2021b(hdrLum->size[1], hdrLum1->size[1], &g_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  if ((hdrLum->size[0] == hdrLum1->size[0]) &&
      (hdrLum->size[1] == hdrLum1->size[1])) {
    loop_ub = hdrLum->size[0] * hdrLum->size[1];
    for (i = 0; i < loop_ub; i++) {
      hdrLum_data[i] = (hdrLum_data[i] + b_data[i]) + hdrLum1_data[i];
    }
  } else {
    st.site = &ah_emlrtRSI;
    c_binary_expand_op(&st, hdrLum, b, hdrLum1);
    hdrLum_data = hdrLum->data;
  }
  st.site = &c_emlrtRSI;
  b_st.site = &vb_emlrtRSI;
  c_st.site = &wb_emlrtRSI;
  d_st.site = &xb_emlrtRSI;
  if (hdrImg->size[0] * hdrImg->size[1] * 3 < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &b_emlrtRTEI,
                                  "Coder:toolbox:eml_min_or_max_varDimZero",
                                  "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }
  e_st.site = &yb_emlrtRSI;
  f_st.site = &ac_emlrtRSI;
  last = hdrImg->size[0] * hdrImg->size[1] * 3;
  if (hdrImg->size[0] * hdrImg->size[1] * 3 <= 2) {
    if (hdrImg->size[0] * hdrImg->size[1] * 3 == 1) {
      ex = hdrImg_data[0];
    } else if ((hdrImg_data[0] <
                hdrImg_data[hdrImg->size[0] * hdrImg->size[1] * 3 - 1]) ||
               (muDoubleScalarIsNaN(hdrImg_data[0]) &&
                (!muDoubleScalarIsNaN(
                    hdrImg_data[hdrImg->size[0] * hdrImg->size[1] * 3 - 1])))) {
      ex = hdrImg_data[hdrImg->size[0] * hdrImg->size[1] * 3 - 1];
    } else {
      ex = hdrImg_data[0];
    }
  } else {
    g_st.site = &bc_emlrtRSI;
    if (!muDoubleScalarIsNaN(hdrImg_data[0])) {
      idx = 1;
    } else {
      idx = 0;
      h_st.site = &dc_emlrtRSI;
      if (hdrImg->size[0] * hdrImg->size[1] * 3 > 2147483646) {
        i_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!muDoubleScalarIsNaN(hdrImg_data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      ex = hdrImg_data[0];
    } else {
      g_st.site = &cc_emlrtRSI;
      ex = hdrImg_data[idx - 1];
      loop_ub = idx + 1;
      h_st.site = &ec_emlrtRSI;
      if ((idx + 1 <= hdrImg->size[0] * hdrImg->size[1] * 3) &&
          (hdrImg->size[0] * hdrImg->size[1] * 3 > 2147483646)) {
        i_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }
      for (k = loop_ub; k <= last; k++) {
        if (ex < hdrImg_data[k - 1]) {
          ex = hdrImg_data[k - 1];
        }
      }
    }
  }
  i = hdrLum1->size[0] * hdrLum1->size[1];
  hdrLum1->size[0] = hdrLum->size[0];
  hdrLum1->size[1] = hdrLum->size[1];
  emxEnsureCapacity_real_T(sp, hdrLum1, i, &eb_emlrtRTEI);
  hdrLum1_data = hdrLum1->data;
  loop_ub = hdrLum->size[0] * hdrLum->size[1];
  for (i = 0; i < loop_ub; i++) {
    hdrLum1_data[i] = hdrLum_data[i] / ex;
  }
  st.site = &d_emlrtRSI;
  power(&st, hdrLum1, b);
  b_data = b->data;
  emxInit_real_T(sp, &labels_DoG, 2, &ob_emlrtRTEI);
  st.site = &d_emlrtRSI;
  power(&st, hdrLum1, labels_DoG);
  labels_DoG_data = labels_DoG->data;
  st.site = &d_emlrtRSI;
  loop_ub = b->size[0] * b->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_data[i] = 18.8515625 * b_data[i] + 0.8359375;
  }
  loop_ub = labels_DoG->size[0] * labels_DoG->size[1];
  for (i = 0; i < loop_ub; i++) {
    labels_DoG_data[i] = 18.6875 * labels_DoG_data[i] + 1.0;
  }
  b_st.site = &kc_emlrtRSI;
  c_st.site = &lc_emlrtRSI;
  if ((b->size[0] != labels_DoG->size[0]) ||
      (b->size[1] != labels_DoG->size[1])) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI, "MATLAB:dimagree",
                                  "MATLAB:dimagree", 0);
  }
  emxInit_real_T(sp, &b_b, 2, &fb_emlrtRTEI);
  i = b_b->size[0] * b_b->size[1];
  b_b->size[0] = b->size[0];
  b_b->size[1] = b->size[1];
  emxEnsureCapacity_real_T(sp, b_b, i, &fb_emlrtRTEI);
  b_hdrImg_data = b_b->data;
  loop_ub = b->size[0] * b->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_hdrImg_data[i] = b_data[i] / labels_DoG_data[i];
  }
  st.site = &d_emlrtRSI;
  b_power(&st, b_b, hdrLum1);
  hdrLum1_data = hdrLum1->data;
  emxFree_real_T(sp, &b_b);
  emxInit_real_T(sp, &a__2, 2, &ab_emlrtRTEI);
  st.site = &e_emlrtRSI;
  quantizeNL_float(&st, hdrLum1, hdrLum, labels_DoG, a__1, a__2);
  labels_DoG_data = labels_DoG->data;
  emxFree_real_T(sp, &a__2);
  /*  local enhancemant using DoG */
  st.site = &f_emlrtRSI;
  b_st.site = &xe_emlrtRSI;
  c_st.site = &ye_emlrtRSI;
  d_st.site = &af_emlrtRSI;
  if (hdrLum1->size[0] * hdrLum1->size[1] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &b_emlrtRTEI,
                                  "Coder:toolbox:eml_min_or_max_varDimZero",
                                  "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }
  e_st.site = &bf_emlrtRSI;
  f_st.site = &cf_emlrtRSI;
  last = hdrLum1->size[0] * hdrLum1->size[1];
  if (hdrLum1->size[0] * hdrLum1->size[1] <= 2) {
    if (hdrLum1->size[0] * hdrLum1->size[1] == 1) {
      ex = hdrLum1_data[0];
    } else if ((hdrLum1_data[0] >
                hdrLum1_data[hdrLum1->size[0] * hdrLum1->size[1] - 1]) ||
               (muDoubleScalarIsNaN(hdrLum1_data[0]) &&
                (!muDoubleScalarIsNaN(
                    hdrLum1_data[hdrLum1->size[0] * hdrLum1->size[1] - 1])))) {
      ex = hdrLum1_data[hdrLum1->size[0] * hdrLum1->size[1] - 1];
    } else {
      ex = hdrLum1_data[0];
    }
  } else {
    g_st.site = &bc_emlrtRSI;
    if (!muDoubleScalarIsNaN(hdrLum1_data[0])) {
      idx = 1;
    } else {
      idx = 0;
      h_st.site = &dc_emlrtRSI;
      if (hdrLum1->size[0] * hdrLum1->size[1] > 2147483646) {
        i_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!muDoubleScalarIsNaN(hdrLum1_data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      ex = hdrLum1_data[0];
    } else {
      g_st.site = &cc_emlrtRSI;
      ex = hdrLum1_data[idx - 1];
      loop_ub = idx + 1;
      h_st.site = &ec_emlrtRSI;
      if ((idx + 1 <= hdrLum1->size[0] * hdrLum1->size[1]) &&
          (hdrLum1->size[0] * hdrLum1->size[1] > 2147483646)) {
        i_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }
      for (k = loop_ub; k <= last; k++) {
        if (ex > hdrLum1_data[k - 1]) {
          ex = hdrLum1_data[k - 1];
        }
      }
    }
  }
  st.site = &f_emlrtRSI;
  b_st.site = &vb_emlrtRSI;
  c_st.site = &wb_emlrtRSI;
  d_st.site = &xb_emlrtRSI;
  if (hdrLum1->size[0] * hdrLum1->size[1] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &b_emlrtRTEI,
                                  "Coder:toolbox:eml_min_or_max_varDimZero",
                                  "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }
  e_st.site = &yb_emlrtRSI;
  f_st.site = &ac_emlrtRSI;
  last = hdrLum1->size[0] * hdrLum1->size[1];
  if (hdrLum1->size[0] * hdrLum1->size[1] <= 2) {
    if (hdrLum1->size[0] * hdrLum1->size[1] == 1) {
      maxhdr = hdrLum1_data[0];
    } else if ((hdrLum1_data[0] <
                hdrLum1_data[hdrLum1->size[0] * hdrLum1->size[1] - 1]) ||
               (muDoubleScalarIsNaN(hdrLum1_data[0]) &&
                (!muDoubleScalarIsNaN(
                    hdrLum1_data[hdrLum1->size[0] * hdrLum1->size[1] - 1])))) {
      maxhdr = hdrLum1_data[hdrLum1->size[0] * hdrLum1->size[1] - 1];
    } else {
      maxhdr = hdrLum1_data[0];
    }
  } else {
    g_st.site = &bc_emlrtRSI;
    if (!muDoubleScalarIsNaN(hdrLum1_data[0])) {
      idx = 1;
    } else {
      idx = 0;
      h_st.site = &dc_emlrtRSI;
      if (hdrLum1->size[0] * hdrLum1->size[1] > 2147483646) {
        i_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!muDoubleScalarIsNaN(hdrLum1_data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      maxhdr = hdrLum1_data[0];
    } else {
      g_st.site = &cc_emlrtRSI;
      maxhdr = hdrLum1_data[idx - 1];
      loop_ub = idx + 1;
      h_st.site = &ec_emlrtRSI;
      if ((idx + 1 <= hdrLum1->size[0] * hdrLum1->size[1]) &&
          (hdrLum1->size[0] * hdrLum1->size[1] > 2147483646)) {
        i_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }
      for (k = loop_ub; k <= last; k++) {
        if (maxhdr < hdrLum1_data[k - 1]) {
          maxhdr = hdrLum1_data[k - 1];
        }
      }
    }
  }
  st.site = &f_emlrtRSI;
  b_st.site = &xe_emlrtRSI;
  c_st.site = &ye_emlrtRSI;
  d_st.site = &af_emlrtRSI;
  if (hdrLum1->size[0] * hdrLum1->size[1] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &b_emlrtRTEI,
                                  "Coder:toolbox:eml_min_or_max_varDimZero",
                                  "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }
  e_st.site = &bf_emlrtRSI;
  f_st.site = &cf_emlrtRSI;
  last = hdrLum1->size[0] * hdrLum1->size[1];
  if (hdrLum1->size[0] * hdrLum1->size[1] <= 2) {
    if (hdrLum1->size[0] * hdrLum1->size[1] == 1) {
      minhdr = hdrLum1_data[0];
    } else if ((hdrLum1_data[0] >
                hdrLum1_data[hdrLum1->size[0] * hdrLum1->size[1] - 1]) ||
               (muDoubleScalarIsNaN(hdrLum1_data[0]) &&
                (!muDoubleScalarIsNaN(
                    hdrLum1_data[hdrLum1->size[0] * hdrLum1->size[1] - 1])))) {
      minhdr = hdrLum1_data[hdrLum1->size[0] * hdrLum1->size[1] - 1];
    } else {
      minhdr = hdrLum1_data[0];
    }
  } else {
    g_st.site = &bc_emlrtRSI;
    if (!muDoubleScalarIsNaN(hdrLum1_data[0])) {
      idx = 1;
    } else {
      idx = 0;
      h_st.site = &dc_emlrtRSI;
      if (hdrLum1->size[0] * hdrLum1->size[1] > 2147483646) {
        i_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!muDoubleScalarIsNaN(hdrLum1_data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      minhdr = hdrLum1_data[0];
    } else {
      g_st.site = &cc_emlrtRSI;
      minhdr = hdrLum1_data[idx - 1];
      loop_ub = idx + 1;
      h_st.site = &ec_emlrtRSI;
      if ((idx + 1 <= hdrLum1->size[0] * hdrLum1->size[1]) &&
          (hdrLum1->size[0] * hdrLum1->size[1] > 2147483646)) {
        i_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }
      for (k = loop_ub; k <= last; k++) {
        if (minhdr > hdrLum1_data[k - 1]) {
          minhdr = hdrLum1_data[k - 1];
        }
      }
    }
  }
  loop_ub = hdrLum1->size[0] * hdrLum1->size[1];
  maxhdr -= minhdr;
  for (i = 0; i < loop_ub; i++) {
    hdrLum1_data[i] = (255.0 * (hdrLum1_data[i] - ex) / maxhdr + 1.0) * 0.35;
  }
  i = b->size[0] * b->size[1];
  b->size[0] = labels_DoG->size[0];
  b->size[1] = labels_DoG->size[1];
  emxEnsureCapacity_real_T(sp, b, i, &gb_emlrtRTEI);
  b_data = b->data;
  loop_ub = labels_DoG->size[0] * labels_DoG->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_data[i] = labels_DoG_data[i] * 0.65;
  }
  if ((hdrLum1->size[0] != b->size[0]) &&
      ((hdrLum1->size[0] != 1) && (b->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(hdrLum1->size[0], b->size[0], &f_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  if ((hdrLum1->size[1] != b->size[1]) &&
      ((hdrLum1->size[1] != 1) && (b->size[1] != 1))) {
    emlrtDimSizeImpxCheckR2021b(hdrLum1->size[1], b->size[1], &e_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  if ((hdrLum1->size[0] == b->size[0]) && (hdrLum1->size[1] == b->size[1])) {
    loop_ub = hdrLum1->size[0] * hdrLum1->size[1];
    for (i = 0; i < loop_ub; i++) {
      hdrLum1_data[i] += b_data[i];
    }
  } else {
    plus(sp, hdrLum1, b);
  }
  emxFree_real_T(sp, &b);
  st.site = &g_emlrtRSI;
  imfilter(&st, hdrLum1);
  hdrLum1_data = hdrLum1->data;
  loop_ub = hdrLum1->size[0] * hdrLum1->size[1];
  for (i = 0; i < loop_ub; i++) {
    hdrLum1_data[i] *= 3.0;
  }
  if ((labels_DoG->size[0] != hdrLum1->size[0]) &&
      ((labels_DoG->size[0] != 1) && (hdrLum1->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(labels_DoG->size[0], hdrLum1->size[0],
                                &d_emlrtECI, (emlrtConstCTX)sp);
  }
  if ((labels_DoG->size[1] != hdrLum1->size[1]) &&
      ((labels_DoG->size[1] != 1) && (hdrLum1->size[1] != 1))) {
    emlrtDimSizeImpxCheckR2021b(labels_DoG->size[1], hdrLum1->size[1],
                                &c_emlrtECI, (emlrtConstCTX)sp);
  }
  if ((labels_DoG->size[0] == hdrLum1->size[0]) &&
      (labels_DoG->size[1] == hdrLum1->size[1])) {
    loop_ub = labels_DoG->size[0] * labels_DoG->size[1];
    for (i = 0; i < loop_ub; i++) {
      labels_DoG_data[i] += hdrLum1_data[i];
    }
  } else {
    st.site = &g_emlrtRSI;
    plus(&st, labels_DoG, hdrLum1);
    labels_DoG_data = labels_DoG->data;
  }
  /*  color restoration */
  st.site = &h_emlrtRSI;
  b_st.site = &xe_emlrtRSI;
  c_st.site = &ye_emlrtRSI;
  d_st.site = &af_emlrtRSI;
  if (labels_DoG->size[0] * labels_DoG->size[1] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &b_emlrtRTEI,
                                  "Coder:toolbox:eml_min_or_max_varDimZero",
                                  "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }
  e_st.site = &bf_emlrtRSI;
  f_st.site = &cf_emlrtRSI;
  last = labels_DoG->size[0] * labels_DoG->size[1];
  if (labels_DoG->size[0] * labels_DoG->size[1] <= 2) {
    if (labels_DoG->size[0] * labels_DoG->size[1] == 1) {
      ex = labels_DoG_data[0];
    } else if ((labels_DoG_data[0] >
                labels_DoG_data[labels_DoG->size[0] * labels_DoG->size[1] -
                                1]) ||
               (muDoubleScalarIsNaN(labels_DoG_data[0]) &&
                (!muDoubleScalarIsNaN(
                    labels_DoG_data[labels_DoG->size[0] * labels_DoG->size[1] -
                                    1])))) {
      ex = labels_DoG_data[labels_DoG->size[0] * labels_DoG->size[1] - 1];
    } else {
      ex = labels_DoG_data[0];
    }
  } else {
    g_st.site = &bc_emlrtRSI;
    if (!muDoubleScalarIsNaN(labels_DoG_data[0])) {
      idx = 1;
    } else {
      idx = 0;
      h_st.site = &dc_emlrtRSI;
      if (labels_DoG->size[0] * labels_DoG->size[1] > 2147483646) {
        i_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!muDoubleScalarIsNaN(labels_DoG_data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      ex = labels_DoG_data[0];
    } else {
      g_st.site = &cc_emlrtRSI;
      ex = labels_DoG_data[idx - 1];
      loop_ub = idx + 1;
      h_st.site = &ec_emlrtRSI;
      if ((idx + 1 <= labels_DoG->size[0] * labels_DoG->size[1]) &&
          (labels_DoG->size[0] * labels_DoG->size[1] > 2147483646)) {
        i_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }
      for (k = loop_ub; k <= last; k++) {
        if (ex > labels_DoG_data[k - 1]) {
          ex = labels_DoG_data[k - 1];
        }
      }
    }
  }
  st.site = &h_emlrtRSI;
  b_st.site = &vb_emlrtRSI;
  c_st.site = &wb_emlrtRSI;
  d_st.site = &xb_emlrtRSI;
  if (labels_DoG->size[0] * labels_DoG->size[1] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &b_emlrtRTEI,
                                  "Coder:toolbox:eml_min_or_max_varDimZero",
                                  "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }
  e_st.site = &yb_emlrtRSI;
  f_st.site = &ac_emlrtRSI;
  last = labels_DoG->size[0] * labels_DoG->size[1];
  if (labels_DoG->size[0] * labels_DoG->size[1] <= 2) {
    if (labels_DoG->size[0] * labels_DoG->size[1] == 1) {
      maxhdr = labels_DoG_data[0];
    } else if ((labels_DoG_data[0] <
                labels_DoG_data[labels_DoG->size[0] * labels_DoG->size[1] -
                                1]) ||
               (muDoubleScalarIsNaN(labels_DoG_data[0]) &&
                (!muDoubleScalarIsNaN(
                    labels_DoG_data[labels_DoG->size[0] * labels_DoG->size[1] -
                                    1])))) {
      maxhdr = labels_DoG_data[labels_DoG->size[0] * labels_DoG->size[1] - 1];
    } else {
      maxhdr = labels_DoG_data[0];
    }
  } else {
    g_st.site = &bc_emlrtRSI;
    if (!muDoubleScalarIsNaN(labels_DoG_data[0])) {
      idx = 1;
    } else {
      idx = 0;
      h_st.site = &dc_emlrtRSI;
      if (labels_DoG->size[0] * labels_DoG->size[1] > 2147483646) {
        i_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!muDoubleScalarIsNaN(labels_DoG_data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      maxhdr = labels_DoG_data[0];
    } else {
      g_st.site = &cc_emlrtRSI;
      maxhdr = labels_DoG_data[idx - 1];
      loop_ub = idx + 1;
      h_st.site = &ec_emlrtRSI;
      if ((idx + 1 <= labels_DoG->size[0] * labels_DoG->size[1]) &&
          (labels_DoG->size[0] * labels_DoG->size[1] > 2147483646)) {
        i_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }
      for (k = loop_ub; k <= last; k++) {
        if (maxhdr < labels_DoG_data[k - 1]) {
          maxhdr = labels_DoG_data[k - 1];
        }
      }
    }
  }
  st.site = &h_emlrtRSI;
  b_st.site = &xe_emlrtRSI;
  c_st.site = &ye_emlrtRSI;
  d_st.site = &af_emlrtRSI;
  if (labels_DoG->size[0] * labels_DoG->size[1] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &b_emlrtRTEI,
                                  "Coder:toolbox:eml_min_or_max_varDimZero",
                                  "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }
  e_st.site = &bf_emlrtRSI;
  f_st.site = &cf_emlrtRSI;
  last = labels_DoG->size[0] * labels_DoG->size[1];
  if (labels_DoG->size[0] * labels_DoG->size[1] <= 2) {
    if (labels_DoG->size[0] * labels_DoG->size[1] == 1) {
      minhdr = labels_DoG_data[0];
    } else if ((labels_DoG_data[0] >
                labels_DoG_data[labels_DoG->size[0] * labels_DoG->size[1] -
                                1]) ||
               (muDoubleScalarIsNaN(labels_DoG_data[0]) &&
                (!muDoubleScalarIsNaN(
                    labels_DoG_data[labels_DoG->size[0] * labels_DoG->size[1] -
                                    1])))) {
      minhdr = labels_DoG_data[labels_DoG->size[0] * labels_DoG->size[1] - 1];
    } else {
      minhdr = labels_DoG_data[0];
    }
  } else {
    g_st.site = &bc_emlrtRSI;
    if (!muDoubleScalarIsNaN(labels_DoG_data[0])) {
      idx = 1;
    } else {
      idx = 0;
      h_st.site = &dc_emlrtRSI;
      if (labels_DoG->size[0] * labels_DoG->size[1] > 2147483646) {
        i_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!muDoubleScalarIsNaN(labels_DoG_data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      minhdr = labels_DoG_data[0];
    } else {
      g_st.site = &cc_emlrtRSI;
      minhdr = labels_DoG_data[idx - 1];
      loop_ub = idx + 1;
      h_st.site = &ec_emlrtRSI;
      if ((idx + 1 <= labels_DoG->size[0] * labels_DoG->size[1]) &&
          (labels_DoG->size[0] * labels_DoG->size[1] > 2147483646)) {
        i_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }
      for (k = loop_ub; k <= last; k++) {
        if (minhdr > labels_DoG_data[k - 1]) {
          minhdr = labels_DoG_data[k - 1];
        }
      }
    }
  }
  i = hdrLum1->size[0] * hdrLum1->size[1];
  hdrLum1->size[0] = labels_DoG->size[0];
  hdrLum1->size[1] = labels_DoG->size[1];
  emxEnsureCapacity_real_T(sp, hdrLum1, i, &hb_emlrtRTEI);
  hdrLum1_data = hdrLum1->data;
  maxhdr -= minhdr;
  loop_ub = labels_DoG->size[0] * labels_DoG->size[1];
  for (i = 0; i < loop_ub; i++) {
    hdrLum1_data[i] = (labels_DoG_data[i] - ex) / maxhdr;
  }
  st.site = &i_emlrtRSI;
  b_atan(&st, hdrLum1);
  hdrLum1_data = hdrLum1->data;
  loop_ub = hdrLum1->size[0] * hdrLum1->size[1];
  for (i = 0; i < loop_ub; i++) {
    hdrLum1_data[i] = 1.0 - hdrLum1_data[i];
  }
  loop_ub = hdrLum1->size[0] * hdrLum1->size[1];
  for (i = 0; i < loop_ub; i++) {
    maxhdr = hdrLum1_data[i];
    hdrLum1_data[i] = muDoubleScalarMin(maxhdr, 0.5);
  }
  st.site = &j_emlrtRSI;
  b_st.site = &kc_emlrtRSI;
  c_st.site = &lc_emlrtRSI;
  assertCompatibleDims(&c_st, hdrImg, hdrLum);
  emxInit_real_T(sp, &c_hdrImg, 3, &fb_emlrtRTEI);
  if ((hdrImg->size[0] == hdrLum->size[0]) &&
      (hdrImg->size[1] == hdrLum->size[1])) {
    idx = hdrLum->size[0];
    i = c_hdrImg->size[0] * c_hdrImg->size[1] * c_hdrImg->size[2];
    c_hdrImg->size[0] = hdrImg->size[0];
    c_hdrImg->size[1] = hdrImg->size[1];
    c_hdrImg->size[2] = 3;
    emxEnsureCapacity_real_T(sp, c_hdrImg, i, &fb_emlrtRTEI);
    b_hdrImg_data = c_hdrImg->data;
    loop_ub = hdrImg->size[1];
    for (i = 0; i < 3; i++) {
      for (k = 0; k < loop_ub; k++) {
        last = hdrImg->size[0];
        for (i1 = 0; i1 < last; i1++) {
          b_hdrImg_data[(i1 + c_hdrImg->size[0] * k) +
                        c_hdrImg->size[0] * c_hdrImg->size[1] * i] =
              hdrImg_data[(i1 + hdrImg->size[0] * k) +
                          hdrImg->size[0] * hdrImg->size[1] * i] /
              hdrLum_data[i1 + idx * k];
        }
      }
    }
    st.site = &j_emlrtRSI;
    c_power(&st, c_hdrImg, hdrLum1, ldrImg);
    hdrLum1_data = ldrImg->data;
  } else {
    st.site = &j_emlrtRSI;
    b_binary_expand_op(&st, ldrImg, j_emlrtRSI, hdrImg, hdrLum, hdrLum1);
    hdrLum1_data = ldrImg->data;
  }
  emxFree_real_T(sp, &hdrLum1);
  emxFree_real_T(sp, &hdrLum);
  if ((ldrImg->size[0] != labels_DoG->size[0]) &&
      ((ldrImg->size[0] != 1) && (labels_DoG->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(ldrImg->size[0], labels_DoG->size[0],
                                &b_emlrtECI, (emlrtConstCTX)sp);
  }
  if ((ldrImg->size[1] != labels_DoG->size[1]) &&
      ((ldrImg->size[1] != 1) && (labels_DoG->size[1] != 1))) {
    emlrtDimSizeImpxCheckR2021b(ldrImg->size[1], labels_DoG->size[1], &emlrtECI,
                                (emlrtConstCTX)sp);
  }
  if ((ldrImg->size[0] == labels_DoG->size[0]) &&
      (ldrImg->size[1] == labels_DoG->size[1])) {
    idx = labels_DoG->size[0];
    i = c_hdrImg->size[0] * c_hdrImg->size[1] * c_hdrImg->size[2];
    c_hdrImg->size[0] = ldrImg->size[0];
    c_hdrImg->size[1] = ldrImg->size[1];
    c_hdrImg->size[2] = 3;
    emxEnsureCapacity_real_T(sp, c_hdrImg, i, &jb_emlrtRTEI);
    b_hdrImg_data = c_hdrImg->data;
    loop_ub = ldrImg->size[1];
    for (i = 0; i < 3; i++) {
      for (k = 0; k < loop_ub; k++) {
        last = ldrImg->size[0];
        for (i1 = 0; i1 < last; i1++) {
          b_hdrImg_data[(i1 + c_hdrImg->size[0] * k) +
                        c_hdrImg->size[0] * c_hdrImg->size[1] * i] =
              hdrLum1_data[(i1 + ldrImg->size[0] * k) +
                           ldrImg->size[0] * ldrImg->size[1] * i] *
              labels_DoG_data[i1 + idx * k];
        }
      }
    }
    i = ldrImg->size[0] * ldrImg->size[1] * ldrImg->size[2];
    ldrImg->size[0] = c_hdrImg->size[0];
    ldrImg->size[1] = c_hdrImg->size[1];
    ldrImg->size[2] = 3;
    emxEnsureCapacity_real_T(sp, ldrImg, i, &lb_emlrtRTEI);
    hdrLum1_data = ldrImg->data;
    loop_ub = c_hdrImg->size[0] * c_hdrImg->size[1] * 3;
    for (i = 0; i < loop_ub; i++) {
      hdrLum1_data[i] = b_hdrImg_data[i];
    }
  } else {
    st.site = &j_emlrtRSI;
    binary_expand_op(&st, ldrImg, labels_DoG);
    hdrLum1_data = ldrImg->data;
  }
  emxFree_real_T(sp, &c_hdrImg);
  emxFree_real_T(sp, &labels_DoG);
  last = ldrImg->size[0] * ldrImg->size[1] * 3;
  i = b_hdrImg->size[0];
  b_hdrImg->size[0] = last;
  emxEnsureCapacity_real_T(sp, b_hdrImg, i, &ib_emlrtRTEI);
  b_hdrImg_data = b_hdrImg->data;
  loop_ub = last - 1;
  for (i = 0; i <= loop_ub; i++) {
    b_hdrImg_data[i] = hdrLum1_data[i];
  }
  st.site = &k_emlrtRSI;
  maxhdr = MaxQuart(&st, b_hdrImg);
  last = ldrImg->size[0] * ldrImg->size[1] * 3;
  i = b_hdrImg->size[0];
  b_hdrImg->size[0] = last;
  emxEnsureCapacity_real_T(sp, b_hdrImg, i, &kb_emlrtRTEI);
  b_hdrImg_data = b_hdrImg->data;
  loop_ub = last - 1;
  for (i = 0; i <= loop_ub; i++) {
    b_hdrImg_data[i] = hdrLum1_data[i];
  }
  st.site = &l_emlrtRSI;
  minhdr = b_MaxQuart(&st, b_hdrImg);
  emxFree_real_T(sp, &b_hdrImg);
  if (covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 0, maxhdr < 255.0)) {
    st.site = &m_emlrtRSI;
    b_st.site = &vb_emlrtRSI;
    c_st.site = &wb_emlrtRSI;
    d_st.site = &xb_emlrtRSI;
    if (ldrImg->size[0] * ldrImg->size[1] * 3 < 1) {
      emlrtErrorWithMessageIdR2018a(
          &d_st, &b_emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
          "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }
    e_st.site = &yb_emlrtRSI;
    f_st.site = &ac_emlrtRSI;
    last = ldrImg->size[0] * ldrImg->size[1] * 3;
    if (ldrImg->size[0] * ldrImg->size[1] * 3 <= 2) {
      if (ldrImg->size[0] * ldrImg->size[1] * 3 == 1) {
        ex = hdrLum1_data[0];
      } else if ((hdrLum1_data[0] <
                  hdrLum1_data[ldrImg->size[0] * ldrImg->size[1] * 3 - 1]) ||
                 (muDoubleScalarIsNaN(hdrLum1_data[0]) &&
                  (!muDoubleScalarIsNaN(
                      hdrLum1_data[ldrImg->size[0] * ldrImg->size[1] * 3 -
                                   1])))) {
        ex = hdrLum1_data[ldrImg->size[0] * ldrImg->size[1] * 3 - 1];
      } else {
        ex = hdrLum1_data[0];
      }
    } else {
      g_st.site = &bc_emlrtRSI;
      if (!muDoubleScalarIsNaN(hdrLum1_data[0])) {
        idx = 1;
      } else {
        idx = 0;
        h_st.site = &dc_emlrtRSI;
        if (ldrImg->size[0] * ldrImg->size[1] * 3 > 2147483646) {
          i_st.site = &cb_emlrtRSI;
          check_forloop_overflow_error(&i_st);
        }
        k = 2;
        exitg1 = false;
        while ((!exitg1) && (k <= last)) {
          if (!muDoubleScalarIsNaN(hdrLum1_data[k - 1])) {
            idx = k;
            exitg1 = true;
          } else {
            k++;
          }
        }
      }
      if (idx == 0) {
        ex = hdrLum1_data[0];
      } else {
        g_st.site = &cc_emlrtRSI;
        ex = hdrLum1_data[idx - 1];
        loop_ub = idx + 1;
        h_st.site = &ec_emlrtRSI;
        if ((idx + 1 <= ldrImg->size[0] * ldrImg->size[1] * 3) &&
            (ldrImg->size[0] * ldrImg->size[1] * 3 > 2147483646)) {
          i_st.site = &cb_emlrtRSI;
          check_forloop_overflow_error(&i_st);
        }
        for (k = loop_ub; k <= last; k++) {
          if (ex < hdrLum1_data[k - 1]) {
            ex = hdrLum1_data[k - 1];
          }
        }
      }
    }
    if (covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 1, ex < 255.0)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 1U);
      st.site = &n_emlrtRSI;
      b_st.site = &vb_emlrtRSI;
      c_st.site = &wb_emlrtRSI;
      d_st.site = &xb_emlrtRSI;
      if (ldrImg->size[0] * ldrImg->size[1] * 3 < 1) {
        emlrtErrorWithMessageIdR2018a(
            &d_st, &b_emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
            "Coder:toolbox:eml_min_or_max_varDimZero", 0);
      }
      e_st.site = &yb_emlrtRSI;
      f_st.site = &ac_emlrtRSI;
      last = ldrImg->size[0] * ldrImg->size[1] * 3;
      if (ldrImg->size[0] * ldrImg->size[1] * 3 <= 2) {
        if (ldrImg->size[0] * ldrImg->size[1] * 3 == 1) {
          maxhdr = hdrLum1_data[0];
        } else if ((hdrLum1_data[0] <
                    hdrLum1_data[ldrImg->size[0] * ldrImg->size[1] * 3 - 1]) ||
                   (muDoubleScalarIsNaN(hdrLum1_data[0]) &&
                    (!muDoubleScalarIsNaN(
                        hdrLum1_data[ldrImg->size[0] * ldrImg->size[1] * 3 -
                                     1])))) {
          maxhdr = hdrLum1_data[ldrImg->size[0] * ldrImg->size[1] * 3 - 1];
        } else {
          maxhdr = hdrLum1_data[0];
        }
      } else {
        g_st.site = &bc_emlrtRSI;
        if (!muDoubleScalarIsNaN(hdrLum1_data[0])) {
          idx = 1;
        } else {
          idx = 0;
          h_st.site = &dc_emlrtRSI;
          if (ldrImg->size[0] * ldrImg->size[1] * 3 > 2147483646) {
            i_st.site = &cb_emlrtRSI;
            check_forloop_overflow_error(&i_st);
          }
          k = 2;
          exitg1 = false;
          while ((!exitg1) && (k <= last)) {
            if (!muDoubleScalarIsNaN(hdrLum1_data[k - 1])) {
              idx = k;
              exitg1 = true;
            } else {
              k++;
            }
          }
        }
        if (idx == 0) {
          maxhdr = hdrLum1_data[0];
        } else {
          g_st.site = &cc_emlrtRSI;
          maxhdr = hdrLum1_data[idx - 1];
          loop_ub = idx + 1;
          h_st.site = &ec_emlrtRSI;
          if ((idx + 1 <= ldrImg->size[0] * ldrImg->size[1] * 3) &&
              (ldrImg->size[0] * ldrImg->size[1] * 3 > 2147483646)) {
            i_st.site = &cb_emlrtRSI;
            check_forloop_overflow_error(&i_st);
          }
          for (k = loop_ub; k <= last; k++) {
            if (maxhdr < hdrLum1_data[k - 1]) {
              maxhdr = hdrLum1_data[k - 1];
            }
          }
        }
      }
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 2U);
      maxhdr = 255.0;
    }
  }
  if (covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 2, minhdr > 0.0)) {
    st.site = &o_emlrtRSI;
    b_st.site = &xe_emlrtRSI;
    c_st.site = &ye_emlrtRSI;
    d_st.site = &af_emlrtRSI;
    if (ldrImg->size[0] * ldrImg->size[1] * 3 < 1) {
      emlrtErrorWithMessageIdR2018a(
          &d_st, &b_emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
          "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }
    e_st.site = &bf_emlrtRSI;
    f_st.site = &cf_emlrtRSI;
    last = ldrImg->size[0] * ldrImg->size[1] * 3;
    if (ldrImg->size[0] * ldrImg->size[1] * 3 <= 2) {
      if (ldrImg->size[0] * ldrImg->size[1] * 3 == 1) {
        ex = hdrLum1_data[0];
      } else if ((hdrLum1_data[0] >
                  hdrLum1_data[ldrImg->size[0] * ldrImg->size[1] * 3 - 1]) ||
                 (muDoubleScalarIsNaN(hdrLum1_data[0]) &&
                  (!muDoubleScalarIsNaN(
                      hdrLum1_data[ldrImg->size[0] * ldrImg->size[1] * 3 -
                                   1])))) {
        ex = hdrLum1_data[ldrImg->size[0] * ldrImg->size[1] * 3 - 1];
      } else {
        ex = hdrLum1_data[0];
      }
    } else {
      g_st.site = &bc_emlrtRSI;
      if (!muDoubleScalarIsNaN(hdrLum1_data[0])) {
        idx = 1;
      } else {
        idx = 0;
        h_st.site = &dc_emlrtRSI;
        if (ldrImg->size[0] * ldrImg->size[1] * 3 > 2147483646) {
          i_st.site = &cb_emlrtRSI;
          check_forloop_overflow_error(&i_st);
        }
        k = 2;
        exitg1 = false;
        while ((!exitg1) && (k <= last)) {
          if (!muDoubleScalarIsNaN(hdrLum1_data[k - 1])) {
            idx = k;
            exitg1 = true;
          } else {
            k++;
          }
        }
      }
      if (idx == 0) {
        ex = hdrLum1_data[0];
      } else {
        g_st.site = &cc_emlrtRSI;
        ex = hdrLum1_data[idx - 1];
        loop_ub = idx + 1;
        h_st.site = &ec_emlrtRSI;
        if ((idx + 1 <= ldrImg->size[0] * ldrImg->size[1] * 3) &&
            (ldrImg->size[0] * ldrImg->size[1] * 3 > 2147483646)) {
          i_st.site = &cb_emlrtRSI;
          check_forloop_overflow_error(&i_st);
        }
        for (k = loop_ub; k <= last; k++) {
          if (ex > hdrLum1_data[k - 1]) {
            ex = hdrLum1_data[k - 1];
          }
        }
      }
    }
    if (covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 3, ex > 0.0)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 3U);
      st.site = &p_emlrtRSI;
      b_st.site = &xe_emlrtRSI;
      c_st.site = &ye_emlrtRSI;
      d_st.site = &af_emlrtRSI;
      if (ldrImg->size[0] * ldrImg->size[1] * 3 < 1) {
        emlrtErrorWithMessageIdR2018a(
            &d_st, &b_emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
            "Coder:toolbox:eml_min_or_max_varDimZero", 0);
      }
      e_st.site = &bf_emlrtRSI;
      f_st.site = &cf_emlrtRSI;
      last = ldrImg->size[0] * ldrImg->size[1] * 3;
      if (ldrImg->size[0] * ldrImg->size[1] * 3 <= 2) {
        if (ldrImg->size[0] * ldrImg->size[1] * 3 == 1) {
          minhdr = hdrLum1_data[0];
        } else if ((hdrLum1_data[0] >
                    hdrLum1_data[ldrImg->size[0] * ldrImg->size[1] * 3 - 1]) ||
                   (muDoubleScalarIsNaN(hdrLum1_data[0]) &&
                    (!muDoubleScalarIsNaN(
                        hdrLum1_data[ldrImg->size[0] * ldrImg->size[1] * 3 -
                                     1])))) {
          minhdr = hdrLum1_data[ldrImg->size[0] * ldrImg->size[1] * 3 - 1];
        } else {
          minhdr = hdrLum1_data[0];
        }
      } else {
        g_st.site = &bc_emlrtRSI;
        if (!muDoubleScalarIsNaN(hdrLum1_data[0])) {
          idx = 1;
        } else {
          idx = 0;
          h_st.site = &dc_emlrtRSI;
          if (ldrImg->size[0] * ldrImg->size[1] * 3 > 2147483646) {
            i_st.site = &cb_emlrtRSI;
            check_forloop_overflow_error(&i_st);
          }
          k = 2;
          exitg1 = false;
          while ((!exitg1) && (k <= last)) {
            if (!muDoubleScalarIsNaN(hdrLum1_data[k - 1])) {
              idx = k;
              exitg1 = true;
            } else {
              k++;
            }
          }
        }
        if (idx == 0) {
          minhdr = hdrLum1_data[0];
        } else {
          g_st.site = &cc_emlrtRSI;
          minhdr = hdrLum1_data[idx - 1];
          loop_ub = idx + 1;
          h_st.site = &ec_emlrtRSI;
          if ((idx + 1 <= ldrImg->size[0] * ldrImg->size[1] * 3) &&
              (ldrImg->size[0] * ldrImg->size[1] * 3 > 2147483646)) {
            i_st.site = &cb_emlrtRSI;
            check_forloop_overflow_error(&i_st);
          }
          for (k = loop_ub; k <= last; k++) {
            if (minhdr > hdrLum1_data[k - 1]) {
              minhdr = hdrLum1_data[k - 1];
            }
          }
        }
      }
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 4U);
      minhdr = 0.0;
    }
  }
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 5U);
  idx = ldrImg->size[0] * (ldrImg->size[1] * 3) - 1;
  last = 0;
  for (loop_ub = 0; loop_ub <= idx; loop_ub++) {
    if (hdrLum1_data[loop_ub] > maxhdr) {
      last++;
    }
  }
  emxInit_int32_T(sp, &r3, 1, &rb_emlrtRTEI);
  i = r3->size[0];
  r3->size[0] = last;
  emxEnsureCapacity_int32_T(sp, r3, i, &ab_emlrtRTEI);
  r1 = r3->data;
  last = 0;
  for (loop_ub = 0; loop_ub <= idx; loop_ub++) {
    if (hdrLum1_data[loop_ub] > maxhdr) {
      r1[last] = loop_ub + 1;
      last++;
    }
  }
  last = ldrImg->size[0] * ldrImg->size[1] * 3;
  loop_ub = r3->size[0];
  for (i = 0; i < loop_ub; i++) {
    if ((r1[i] < 1) || (r1[i] > last)) {
      emlrtDynamicBoundsCheckR2012b(r1[i], 1, last, &c_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    hdrLum1_data[r1[i] - 1] = maxhdr;
  }
  emxFree_int32_T(sp, &r3);
  idx = ldrImg->size[0] * (ldrImg->size[1] * 3) - 1;
  last = 0;
  for (loop_ub = 0; loop_ub <= idx; loop_ub++) {
    if (hdrLum1_data[loop_ub] < minhdr) {
      last++;
    }
  }
  emxInit_int32_T(sp, &r4, 1, &sb_emlrtRTEI);
  i = r4->size[0];
  r4->size[0] = last;
  emxEnsureCapacity_int32_T(sp, r4, i, &ab_emlrtRTEI);
  r1 = r4->data;
  last = 0;
  for (loop_ub = 0; loop_ub <= idx; loop_ub++) {
    if (hdrLum1_data[loop_ub] < minhdr) {
      r1[last] = loop_ub + 1;
      last++;
    }
  }
  last = ldrImg->size[0] * ldrImg->size[1] * 3;
  loop_ub = r4->size[0];
  for (i = 0; i < loop_ub; i++) {
    if ((r1[i] < 1) || (r1[i] > last)) {
      emlrtDynamicBoundsCheckR2012b(r1[i], 1, last, &d_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    hdrLum1_data[r1[i] - 1] = minhdr;
  }
  emxFree_int32_T(sp, &r4);
  loop_ub = ldrImg->size[0] * ldrImg->size[1] * 3;
  i = ldrImg->size[0] * ldrImg->size[1] * ldrImg->size[2];
  ldrImg->size[2] = 3;
  emxEnsureCapacity_real_T(sp, ldrImg, i, &mb_emlrtRTEI);
  hdrLum1_data = ldrImg->data;
  maxhdr -= minhdr;
  for (i = 0; i < loop_ub; i++) {
    hdrLum1_data[i] = 255.0 * ((hdrLum1_data[i] - minhdr) / maxhdr);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (DCA_TMO.c) */
