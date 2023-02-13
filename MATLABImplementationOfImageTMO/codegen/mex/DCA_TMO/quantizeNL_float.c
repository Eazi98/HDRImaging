/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * quantizeNL_float.c
 *
 * Code generation for function 'quantizeNL_float'
 *
 */

/* Include files */
#include "quantizeNL_float.h"
#include "DCA_TMO_data.h"
#include "DCA_TMO_emxutil.h"
#include "DCA_TMO_types.h"
#include "abs.h"
#include "eml_int_forloop_overflow_check.h"
#include "indexShapeCheck.h"
#include "interp1.h"
#include "mean.h"
#include "median.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "sum.h"
#include "tvi.h"
#include "useConstantDim.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo r_emlrtRSI = {
    51,                  /* lineNo */
    "reshapeSizeChecks", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" /* pathName */
};

static emlrtRSInfo s_emlrtRSI = {
    119,               /* lineNo */
    "computeDimsData", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" /* pathName */
};

static emlrtRSInfo mc_emlrtRSI = {
    92,                 /* lineNo */
    "quantizeNL_float", /* fcnName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m" /* pathName */
};

static emlrtRSInfo nc_emlrtRSI = {
    87,                 /* lineNo */
    "quantizeNL_float", /* fcnName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m" /* pathName */
};

static emlrtRSInfo oc_emlrtRSI = {
    84,                 /* lineNo */
    "quantizeNL_float", /* fcnName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m" /* pathName */
};

static emlrtRSInfo pc_emlrtRSI = {
    80,                 /* lineNo */
    "quantizeNL_float", /* fcnName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m" /* pathName */
};

static emlrtRSInfo qc_emlrtRSI = {
    79,                 /* lineNo */
    "quantizeNL_float", /* fcnName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m" /* pathName */
};

static emlrtRSInfo rc_emlrtRSI = {
    63,                 /* lineNo */
    "quantizeNL_float", /* fcnName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m" /* pathName */
};

static emlrtRSInfo sc_emlrtRSI = {
    62,                 /* lineNo */
    "quantizeNL_float", /* fcnName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m" /* pathName */
};

static emlrtRSInfo tc_emlrtRSI = {
    52,                 /* lineNo */
    "quantizeNL_float", /* fcnName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m" /* pathName */
};

static emlrtRSInfo uc_emlrtRSI = {
    51,                 /* lineNo */
    "quantizeNL_float", /* fcnName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m" /* pathName */
};

static emlrtRSInfo vc_emlrtRSI = {
    50,                 /* lineNo */
    "quantizeNL_float", /* fcnName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m" /* pathName */
};

static emlrtRSInfo wc_emlrtRSI = {
    47,                 /* lineNo */
    "quantizeNL_float", /* fcnName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m" /* pathName */
};

static emlrtRSInfo xc_emlrtRSI = {
    46,                 /* lineNo */
    "quantizeNL_float", /* fcnName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m" /* pathName */
};

static emlrtRSInfo yc_emlrtRSI = {
    26,                 /* lineNo */
    "quantizeNL_float", /* fcnName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m" /* pathName */
};

static emlrtRSInfo ad_emlrtRSI = {
    23,                 /* lineNo */
    "quantizeNL_float", /* fcnName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m" /* pathName */
};

static emlrtRSInfo bd_emlrtRSI = {
    22,                 /* lineNo */
    "quantizeNL_float", /* fcnName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m" /* pathName */
};

static emlrtRSInfo cd_emlrtRSI = {
    20,                 /* lineNo */
    "quantizeNL_float", /* fcnName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m" /* pathName */
};

static emlrtRSInfo dd_emlrtRSI = {
    15,                 /* lineNo */
    "quantizeNL_float", /* fcnName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m" /* pathName */
};

static emlrtRSInfo ed_emlrtRSI = {
    14,                 /* lineNo */
    "quantizeNL_float", /* fcnName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m" /* pathName */
};

static emlrtRSInfo fd_emlrtRSI = {
    11,                 /* lineNo */
    "quantizeNL_float", /* fcnName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m" /* pathName */
};

static emlrtRSInfo gd_emlrtRSI = {
    10,                 /* lineNo */
    "quantizeNL_float", /* fcnName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m" /* pathName */
};

static emlrtRSInfo vd_emlrtRSI = {
    14,       /* lineNo */
    "cumsum", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\datafun\\cumsum.m" /* pathName
                                                                           */
};

static emlrtRSInfo wd_emlrtRSI = {
    16,      /* lineNo */
    "cumop", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\cumop."
    "m" /* pathName */
};

static emlrtRSInfo ce_emlrtRSI = {
    17,    /* lineNo */
    "max", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\datafun\\max.m" /* pathName
                                                                        */
};

static emlrtRSInfo de_emlrtRSI =
    {
        38,         /* lineNo */
        "minOrMax", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" /* pathName */
};

static emlrtRSInfo ee_emlrtRSI =
    {
        77,        /* lineNo */
        "maximum", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" /* pathName */
};

static emlrtRSInfo fe_emlrtRSI = {
    173,             /* lineNo */
    "unaryMinOrMax", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" /* pathName */
};

static emlrtRSInfo ge_emlrtRSI = {
    44,       /* lineNo */
    "mpower", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\matfun\\mpower.m" /* pathName
                                                                          */
};

static emlrtRSInfo ue_emlrtRSI = {
    17,    /* lineNo */
    "min", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\datafun\\min.m" /* pathName
                                                                        */
};

static emlrtRSInfo ve_emlrtRSI =
    {
        40,         /* lineNo */
        "minOrMax", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" /* pathName */
};

static emlrtRSInfo we_emlrtRSI =
    {
        90,        /* lineNo */
        "minimum", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" /* pathName */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    60,                 /* lineNo */
    37,                 /* colNo */
    "ss_data",          /* aName */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    56,                 /* lineNo */
    34,                 /* colNo */
    "s_data",           /* aName */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    58,                 /* lineNo */
    27,                 /* colNo */
    "ss_data",          /* aName */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    54,                 /* lineNo */
    25,                 /* colNo */
    "s_data",           /* aName */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    52,                 /* lineNo */
    100,                /* colNo */
    "lum",              /* aName */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    52,                 /* lineNo */
    89,                 /* colNo */
    "lum",              /* aName */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    52,                 /* lineNo */
    68,                 /* colNo */
    "lum",              /* aName */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    87,                 /* lineNo */
    30,                 /* colNo */
    "lum0",             /* aName */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    84,                 /* lineNo */
    30,                 /* colNo */
    "lum0",             /* aName */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    86,                 /* lineNo */
    53,                 /* colNo */
    "edges",            /* aName */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    86,                 /* lineNo */
    47,                 /* colNo */
    "lum",              /* aName */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    50,                 /* lineNo */
    31,                 /* colNo */
    "lum",              /* aName */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    83,                 /* lineNo */
    32,                 /* colNo */
    "edges",            /* aName */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    83,                 /* lineNo */
    26,                 /* colNo */
    "lum",              /* aName */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    86,                 /* lineNo */
    31,                 /* colNo */
    "edges",            /* aName */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    86,                 /* lineNo */
    25,                 /* colNo */
    "lum",              /* aName */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    82,                 /* lineNo */
    33,                 /* colNo */
    "edges",            /* aName */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    82,                 /* lineNo */
    27,                 /* colNo */
    "lum",              /* aName */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    82,                 /* lineNo */
    18,                 /* colNo */
    "edges",            /* aName */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    82,                 /* lineNo */
    12,                 /* colNo */
    "lum",              /* aName */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    44,                 /* lineNo */
    33,                 /* colNo */
    "ss_data",          /* aName */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    40,                 /* lineNo */
    30,                 /* colNo */
    "s_data",           /* aName */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    42,                 /* lineNo */
    23,                 /* colNo */
    "ss_data",          /* aName */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    38,                 /* lineNo */
    21,                 /* colNo */
    "s_data",           /* aName */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    34,                 /* lineNo */
    29,                 /* colNo */
    "ss_data",          /* aName */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    30,                 /* lineNo */
    26,                 /* colNo */
    "s_data",           /* aName */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    32,                 /* lineNo */
    19,                 /* colNo */
    "ss_data",          /* aName */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    28,                 /* lineNo */
    17,                 /* colNo */
    "s_data",           /* aName */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    27,                 /* lineNo */
    31,                 /* colNo */
    "edges",            /* aName */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    27,                 /* lineNo */
    15,                 /* colNo */
    "edges",            /* aName */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m", /* pName */
    0                                       /* checkKind */
};

static emlrtRTEInfo f_emlrtRTEI = {
    81,                  /* lineNo */
    23,                  /* colNo */
    "reshapeSizeChecks", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" /* pName */
};

static emlrtBCInfo kb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    50,                 /* lineNo */
    60,                 /* colNo */
    "lum",              /* aName */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    50,                 /* lineNo */
    66,                 /* colNo */
    "lum",              /* aName */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    65,                 /* lineNo */
    30,                 /* colNo */
    "edges",            /* aName */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo nb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    65,                 /* lineNo */
    45,                 /* colNo */
    "edges",            /* aName */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    65,                 /* lineNo */
    51,                 /* colNo */
    "edges",            /* aName */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo pb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    66,                 /* lineNo */
    32,                 /* colNo */
    "errors",           /* aName */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo qb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    66,                 /* lineNo */
    52,                 /* colNo */
    "errors",           /* aName */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo rb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    66,                 /* lineNo */
    58,                 /* colNo */
    "errors",           /* aName */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m", /* pName */
    0                                       /* checkKind */
};

static emlrtECInfo i_emlrtECI = {
    2,                  /* nDims */
    86,                 /* lineNo */
    16,                 /* colNo */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m" /* pName */
};

static emlrtRTEInfo v_emlrtRTEI = {
    14,      /* lineNo */
    9,       /* colNo */
    "log10", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\elfun\\log10.m" /* pName
                                                                        */
};

static emlrtRTEInfo vb_emlrtRTEI = {
    11,                 /* lineNo */
    1,                  /* colNo */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m" /* pName */
};

static emlrtRTEInfo wb_emlrtRTEI = {
    15,                 /* lineNo */
    1,                  /* colNo */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m" /* pName */
};

static emlrtRTEInfo xb_emlrtRTEI = {
    19,                 /* lineNo */
    1,                  /* colNo */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m" /* pName */
};

static emlrtRTEInfo yb_emlrtRTEI = {
    20,                 /* lineNo */
    15,                 /* colNo */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m" /* pName */
};

static emlrtRTEInfo ac_emlrtRTEI = {
    20,                 /* lineNo */
    1,                  /* colNo */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m" /* pName */
};

static emlrtRTEInfo bc_emlrtRTEI = {
    14,       /* lineNo */
    5,        /* colNo */
    "cumsum", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\datafun\\cumsum.m" /* pName
                                                                           */
};

static emlrtRTEInfo cc_emlrtRTEI =
    {
        31,            /* lineNo */
        30,            /* colNo */
        "unsafeSxfun", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\unsafeSxfun.m" /* pName */
};

static emlrtRTEInfo dc_emlrtRTEI = {
    86,                 /* lineNo */
    16,                 /* colNo */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m" /* pName */
};

static emlrtRTEInfo ec_emlrtRTEI = {
    83,                 /* lineNo */
    9,                  /* colNo */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m" /* pName */
};

static emlrtRTEInfo fc_emlrtRTEI = {
    50,                 /* lineNo */
    27,                 /* colNo */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m" /* pName */
};

static emlrtRTEInfo gc_emlrtRTEI = {
    86,                 /* lineNo */
    37,                 /* colNo */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m" /* pName */
};

static emlrtRTEInfo hc_emlrtRTEI = {
    1,                  /* lineNo */
    37,                 /* colNo */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m" /* pName */
};

static emlrtRTEInfo ic_emlrtRTEI = {
    84,                 /* lineNo */
    25,                 /* colNo */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m" /* pName */
};

static emlrtRTEInfo jc_emlrtRTEI = {
    50,                 /* lineNo */
    56,                 /* colNo */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m" /* pName */
};

static emlrtRTEInfo kc_emlrtRTEI = {
    87,                 /* lineNo */
    25,                 /* colNo */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m" /* pName */
};

static emlrtRTEInfo lc_emlrtRTEI = {
    52,                 /* lineNo */
    36,                 /* colNo */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m" /* pName */
};

static emlrtRTEInfo mc_emlrtRTEI = {
    65,                 /* lineNo */
    21,                 /* colNo */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m" /* pName */
};

static emlrtRTEInfo nc_emlrtRTEI = {
    65,                 /* lineNo */
    13,                 /* colNo */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m" /* pName */
};

static emlrtRTEInfo oc_emlrtRTEI = {
    66,                 /* lineNo */
    22,                 /* colNo */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m" /* pName */
};

static emlrtRTEInfo pc_emlrtRTEI = {
    66,                 /* lineNo */
    13,                 /* colNo */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m" /* pName */
};

static emlrtRTEInfo qc_emlrtRTEI = {
    22,                 /* lineNo */
    1,                  /* colNo */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m" /* pName */
};

static emlrtRTEInfo rc_emlrtRTEI = {
    23,                 /* lineNo */
    1,                  /* colNo */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m" /* pName */
};

static emlrtRTEInfo sc_emlrtRTEI = {
    1,                  /* lineNo */
    66,                 /* colNo */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m" /* pName */
};

static emlrtRTEInfo tc_emlrtRTEI = {
    1,                  /* lineNo */
    55,                 /* colNo */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m" /* pName */
};

static emlrtRTEInfo uc_emlrtRTEI = {
    18,                 /* lineNo */
    1,                  /* colNo */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m" /* pName */
};

static emlrtRTEInfo vc_emlrtRTEI = {
    84,                 /* lineNo */
    30,                 /* colNo */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m" /* pName */
};

static emlrtRTEInfo wc_emlrtRTEI = {
    87,                 /* lineNo */
    30,                 /* colNo */
    "quantizeNL_float", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\quantizeNL_float.m" /* pName */
};

/* Function Definitions */
void quantizeNL_float(const emlrtStack *sp, const emxArray_real_T *y,
                      const emxArray_real_T *lum, emxArray_real_T *labels,
                      real_T mdata[55], emxArray_real_T *edges)
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
  emxArray_boolean_T *ind;
  emxArray_boolean_T *r1;
  emxArray_int32_T *r2;
  emxArray_int32_T *r3;
  emxArray_real_T *b_lum;
  emxArray_real_T *b_y;
  emxArray_real_T *c_lum;
  emxArray_real_T *delta1;
  emxArray_real_T *errors;
  emxArray_real_T *s_data;
  emxArray_real_T *ss_data;
  const real_T *lum_data;
  const real_T *y_data;
  real_T d;
  real_T e2;
  real_T *b_lum_data;
  real_T *b_y_data;
  real_T *edges_data;
  real_T *errors_data;
  real_T *s_data_data;
  real_T *ss_data_data;
  int32_T b_i;
  int32_T i;
  int32_T k;
  int32_T maxdimlen;
  int32_T nx;
  int32_T varargin_2;
  int32_T *r5;
  boolean_T exitg1;
  boolean_T *ind_data;
  boolean_T *r4;
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
  lum_data = lum->data;
  y_data = y->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  covrtLogFcn(&emlrtCoverageInstance, 2U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 0U);
  /*  y is input data */
  /*  nclust is the number of clusters or quantization levels. If you want to */
  /*  quantize data with b bits then nclust <= 2^b (256 if b=8) */
  /*  labels are the quantization intervals in [1, nclust] range assigned to y
   */
  /*  mdata is the mean value of each cluster */
  varargin_2 = lum->size[0] * lum->size[1];
  st.site = &gd_emlrtRSI;
  nx = lum->size[0] * lum->size[1];
  b_st.site = &r_emlrtRSI;
  c_st.site = &s_emlrtRSI;
  maxdimlen = lum->size[0];
  if (lum->size[1] > lum->size[0]) {
    maxdimlen = lum->size[1];
  }
  maxdimlen = muIntScalarMax_sint32(nx, maxdimlen);
  if (maxdimlen < 1) {
    emlrtErrorWithMessageIdR2018a(&st, &d_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (varargin_2 > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &d_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (varargin_2 != nx) {
    emlrtErrorWithMessageIdR2018a(
        &st, &f_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }
  st.site = &fd_emlrtRSI;
  emxInit_real_T(&st, &b_lum, 2, &sc_emlrtRTEI);
  i = b_lum->size[0] * b_lum->size[1];
  b_lum->size[0] = 1;
  b_lum->size[1] = varargin_2;
  emxEnsureCapacity_real_T(&st, b_lum, i, &vb_emlrtRTEI);
  b_lum_data = b_lum->data;
  for (i = 0; i < varargin_2; i++) {
    b_lum_data[i] = lum_data[i];
  }
  b_st.site = &t_emlrtRSI;
  b_sort(&b_st, b_lum);
  b_lum_data = b_lum->data;
  varargin_2 = y->size[0] * y->size[1];
  st.site = &ed_emlrtRSI;
  nx = y->size[0] * y->size[1];
  b_st.site = &r_emlrtRSI;
  c_st.site = &s_emlrtRSI;
  maxdimlen = y->size[0];
  if (y->size[1] > y->size[0]) {
    maxdimlen = y->size[1];
  }
  maxdimlen = muIntScalarMax_sint32(nx, maxdimlen);
  if (maxdimlen < 1) {
    emlrtErrorWithMessageIdR2018a(&st, &d_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (varargin_2 > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &d_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (varargin_2 != nx) {
    emlrtErrorWithMessageIdR2018a(
        &st, &f_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }
  st.site = &dd_emlrtRSI;
  emxInit_real_T(&st, &b_y, 2, &tc_emlrtRTEI);
  i = b_y->size[0] * b_y->size[1];
  b_y->size[0] = 1;
  b_y->size[1] = varargin_2;
  emxEnsureCapacity_real_T(&st, b_y, i, &wb_emlrtRTEI);
  b_y_data = b_y->data;
  for (i = 0; i < varargin_2; i++) {
    b_y_data[i] = y_data[i];
  }
  b_st.site = &t_emlrtRSI;
  b_sort(&b_st, b_y);
  b_y_data = b_y->data;
  /*  Added initialization to ensure left and right data matches */
  i = edges->size[0] * edges->size[1];
  edges->size[0] = 1;
  edges->size[1] = 2;
  emxEnsureCapacity_real_T(sp, edges, i, &xb_emlrtRTEI);
  edges_data = edges->data;
  edges_data[0] = 0.0;
  edges_data[1] = b_y->size[1];
  emxInit_real_T(sp, &ss_data, 2, &rc_emlrtRTEI);
  st.site = &cd_emlrtRSI;
  i = ss_data->size[0] * ss_data->size[1];
  ss_data->size[0] = 1;
  ss_data->size[1] = b_y->size[1];
  emxEnsureCapacity_real_T(&st, ss_data, i, &yb_emlrtRTEI);
  ss_data_data = ss_data->data;
  b_st.site = &cd_emlrtRSI;
  d = mean(&b_st, b_y);
  nx = b_y->size[1];
  for (i = 0; i < nx; i++) {
    ss_data_data[i] = b_y_data[i] - d;
  }
  b_st.site = &fc_emlrtRSI;
  i = ss_data->size[0] * ss_data->size[1];
  ss_data->size[0] = 1;
  emxEnsureCapacity_real_T(&b_st, ss_data, i, &ub_emlrtRTEI);
  ss_data_data = ss_data->data;
  nx = ss_data->size[1] - 1;
  for (i = 0; i <= nx; i++) {
    e2 = ss_data_data[i];
    ss_data_data[i] = e2 * e2;
  }
  emlrtStack *r;
  emxInit_real_T(sp, &errors, 2, &uc_emlrtRTEI);
  i = errors->size[0] * errors->size[1];
  errors->size[0] = 1;
  errors->size[1] = 1;
  emxEnsureCapacity_real_T(sp, errors, i, &ac_emlrtRTEI);
  errors_data = errors->data;
  st.site = &cd_emlrtRSI;
  r = &st;
  d = sum(r, ss_data);
  errors_data[0] = d;
  b_st.site = &bd_emlrtRSI;
  c_st.site = &vd_emlrtRSI;
  emxInit_real_T(&c_st, &s_data, 2, &qc_emlrtRTEI);
  i = s_data->size[0] * s_data->size[1];
  s_data->size[0] = 1;
  s_data->size[1] = b_y->size[1];
  emxEnsureCapacity_real_T(&c_st, s_data, i, &bc_emlrtRTEI);
  s_data_data = s_data->data;
  nx = b_y->size[1];
  for (i = 0; i < nx; i++) {
    s_data_data[i] = b_y_data[i];
  }
  d_st.site = &wd_emlrtRSI;
  useConstantDim(s_data);
  s_data_data = s_data->data;
  b_st.site = &ad_emlrtRSI;
  c_st.site = &ad_emlrtRSI;
  d_st.site = &fc_emlrtRSI;
  c_st.site = &vd_emlrtRSI;
  i = ss_data->size[0] * ss_data->size[1];
  ss_data->size[0] = 1;
  ss_data->size[1] = b_y->size[1];
  emxEnsureCapacity_real_T(&c_st, ss_data, i, &cc_emlrtRTEI);
  ss_data_data = ss_data->data;
  nx = b_y->size[1];
  for (i = 0; i < nx; i++) {
    e2 = b_y_data[i];
    ss_data_data[i] = e2 * e2;
  }
  d_st.site = &wd_emlrtRSI;
  useConstantDim(ss_data);
  ss_data_data = ss_data->data;
  emxInit_real_T(&st, &delta1, 2, &lc_emlrtRTEI);
  for (b_i = 0; b_i < 54; b_i++) {
    real_T b_d;
    real_T b_k;
    real_T m;
    real_T n;
    real_T sm;
    real_T sn;
    real_T ssm;
    real_T ssn;
    int32_T iindx;
    covrtLogFor(&emlrtCoverageInstance, 2U, 0U, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 1U);
    b_st.site = &yc_emlrtRSI;
    c_st.site = &ce_emlrtRSI;
    d_st.site = &de_emlrtRSI;
    e_st.site = &ee_emlrtRSI;
    f_st.site = &fe_emlrtRSI;
    maxdimlen = errors->size[1];
    if (errors->size[1] <= 2) {
      if (errors->size[1] == 1) {
        iindx = 0;
      } else if ((errors_data[0] < errors_data[1]) ||
                 (muDoubleScalarIsNaN(errors_data[0]) &&
                  (!muDoubleScalarIsNaN(errors_data[1])))) {
        iindx = 1;
      } else {
        iindx = 0;
      }
    } else {
      g_st.site = &bc_emlrtRSI;
      if (!muDoubleScalarIsNaN(errors_data[0])) {
        varargin_2 = 1;
      } else {
        varargin_2 = 0;
        h_st.site = &dc_emlrtRSI;
        if (errors->size[1] > 2147483646) {
          i_st.site = &cb_emlrtRSI;
          check_forloop_overflow_error(&i_st);
        }
        k = 2;
        exitg1 = false;
        while ((!exitg1) && (k <= maxdimlen)) {
          if (!muDoubleScalarIsNaN(errors_data[k - 1])) {
            varargin_2 = k;
            exitg1 = true;
          } else {
            k++;
          }
        }
      }
      if (varargin_2 == 0) {
        iindx = 0;
      } else {
        g_st.site = &cc_emlrtRSI;
        e2 = errors_data[varargin_2 - 1];
        iindx = varargin_2 - 1;
        nx = varargin_2 + 1;
        h_st.site = &ec_emlrtRSI;
        if ((varargin_2 + 1 <= errors->size[1]) &&
            (errors->size[1] > 2147483646)) {
          i_st.site = &cb_emlrtRSI;
          check_forloop_overflow_error(&i_st);
        }
        for (k = nx; k <= maxdimlen; k++) {
          d = errors_data[k - 1];
          if (e2 < d) {
            e2 = d;
            iindx = k - 1;
          }
        }
      }
    }
    if ((iindx + 1 < 1) || (iindx + 1 > edges->size[1])) {
      emlrtDynamicBoundsCheckR2012b(iindx + 1, 1, edges->size[1], &jb_emlrtBCI,
                                    &st);
    }
    b_k = edges_data[iindx];
    if ((iindx + 2 < 1) || (iindx + 2 > edges->size[1])) {
      emlrtDynamicBoundsCheckR2012b(iindx + 2, 1, edges->size[1], &ib_emlrtBCI,
                                    &st);
    }
    n = edges_data[iindx + 1] - edges_data[iindx];
    d = edges_data[iindx] + n;
    if (((int32_T)d < 1) || ((int32_T)d > s_data->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, s_data->size[1],
                                    &hb_emlrtBCI, &st);
    }
    sn = s_data_data[(int32_T)d - 1];
    if (covrtLogIf(&emlrtCoverageInstance, 2U, 0U, 0,
                   edges_data[iindx] >= 1.0)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 2U);
      i = (int32_T)edges_data[iindx];
      if ((i < 1) || (i > s_data->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)edges_data[iindx], 1,
                                      s_data->size[1], &fb_emlrtBCI, &st);
      }
      sn -= s_data_data[i - 1];
    }
    covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 3U);
    if (((int32_T)d < 1) || ((int32_T)d > ss_data->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, ss_data->size[1],
                                    &gb_emlrtBCI, &st);
    }
    ssn = ss_data_data[(int32_T)d - 1];
    if (covrtLogIf(&emlrtCoverageInstance, 2U, 0U, 1,
                   edges_data[iindx] >= 1.0)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 4U);
      i = (int32_T)edges_data[iindx];
      if ((i < 1) || (i > ss_data->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)edges_data[iindx], 1,
                                      ss_data->size[1], &eb_emlrtBCI, &st);
      }
      ssn -= ss_data_data[(int32_T)edges_data[iindx] - 1];
    }
    covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 5U);
    b_d = 2.0;
    m = muDoubleScalarFloor(n / 2.0);
    int32_T exitg2;
    do {
      real_T e1;
      exitg2 = 0;
      covrtLogWhile(&emlrtCoverageInstance, 2U, 0U, 0, true);
      covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 6U);
      i = (int32_T)(b_k + m);
      if ((i < 1) || (i > s_data->size[1])) {
        emlrtDynamicBoundsCheckR2012b(i, 1, s_data->size[1], &db_emlrtBCI, &st);
      }
      sm = s_data_data[i - 1];
      if (covrtLogIf(&emlrtCoverageInstance, 2U, 0U, 2, b_k >= 1.0)) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 7U);
        if (((int32_T)b_k < 1) || ((int32_T)b_k > s_data->size[1])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)b_k, 1, s_data->size[1],
                                        &bb_emlrtBCI, &st);
        }
        sm -= s_data_data[(int32_T)b_k - 1];
      }
      covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 8U);
      if (i > ss_data->size[1]) {
        emlrtDynamicBoundsCheckR2012b(i, 1, ss_data->size[1], &cb_emlrtBCI,
                                      &st);
      }
      ssm = ss_data_data[i - 1];
      if (covrtLogIf(&emlrtCoverageInstance, 2U, 0U, 3, b_k >= 1.0)) {
        covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 9U);
        if (((int32_T)b_k < 1) || ((int32_T)b_k > ss_data->size[1])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)b_k, 1, ss_data->size[1],
                                        &ab_emlrtBCI, &st);
        }
        ssm -= ss_data_data[(int32_T)b_k - 1];
      }
      covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 10U);
      b_st.site = &xc_emlrtRSI;
      c_st.site = &ge_emlrtRSI;
      d_st.site = &fc_emlrtRSI;
      e1 = ssm - sm * sm / m;
      b_st.site = &wc_emlrtRSI;
      e2 = sn - sm;
      c_st.site = &ge_emlrtRSI;
      d_st.site = &fc_emlrtRSI;
      e2 = (ssn - ssm) - e2 * e2 / (n - m);
      b_d *= 2.0;
      if (covrtLogCond(&emlrtCoverageInstance, 2U, 0U, 0,
                       muDoubleScalarAbs(e1 - e2) < 0.001) ||
          covrtLogCond(&emlrtCoverageInstance, 2U, 0U, 1, b_d >= n)) {
        exitg2 = 1;
      } else {
        covrtLogMcdc(&emlrtCoverageInstance, 2U, 0U, 0, false);
        covrtLogIf(&emlrtCoverageInstance, 2U, 0U, 4, false);
        if (covrtLogIf(&emlrtCoverageInstance, 2U, 0U, 7, e1 > e2)) {
          covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 16U);
          m -= muDoubleScalarFloor(n / b_d);
        } else if (covrtLogIf(&emlrtCoverageInstance, 2U, 0U, 8, e1 < e2)) {
          covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 17U);
          m += muDoubleScalarFloor(n / b_d);
        }
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }
    } while (exitg2 == 0);
    covrtLogMcdc(&emlrtCoverageInstance, 2U, 0U, 0, true);
    covrtLogIf(&emlrtCoverageInstance, 2U, 0U, 4, true);
    covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 11U);
    e2 = edges_data[iindx];
    i = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = (int32_T)(m - 1.0) + 1;
    emxEnsureCapacity_real_T(&st, b_y, i, &fc_emlrtRTEI);
    b_y_data = b_y->data;
    nx = (int32_T)(m - 1.0);
    for (i = 0; i <= nx; i++) {
      k = (int32_T)(e2 + (real_T)(i + 1));
      if ((k < 1) || (k > b_lum->size[1])) {
        emlrtDynamicBoundsCheckR2012b(k, 1, b_lum->size[1], &q_emlrtBCI, &st);
      }
      b_y_data[i] = b_lum_data[k - 1];
    }
    b_st.site = &vc_emlrtRSI;
    e2 = median(&b_st, b_y);
    sm = (edges_data[iindx] + m) + 1.0;
    if (sm > d) {
      i = 0;
      k = 0;
    } else {
      if (((int32_T)sm < 1) || ((int32_T)sm > b_lum->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)sm, 1, b_lum->size[1],
                                      &kb_emlrtBCI, &st);
      }
      i = (int32_T)sm - 1;
      if (((int32_T)d < 1) || ((int32_T)d > b_lum->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, b_lum->size[1],
                                      &lb_emlrtBCI, &st);
      }
      k = (int32_T)d;
    }
    maxdimlen = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    nx = k - i;
    b_y->size[1] = nx;
    emxEnsureCapacity_real_T(&st, b_y, maxdimlen, &jc_emlrtRTEI);
    b_y_data = b_y->data;
    for (k = 0; k < nx; k++) {
      b_y_data[k] = b_lum_data[i + k];
    }
    b_st.site = &vc_emlrtRSI;
    sm = median(&b_st, b_y);
    b_st.site = &uc_emlrtRSI;
    c_st.site = &uc_emlrtRSI;
    if (e2 < 0.0) {
      emlrtErrorWithMessageIdR2018a(
          &c_st, &v_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
          "Coder:toolbox:ElFunDomainError", 3, 4, 5, "log10");
    }
    e2 = muDoubleScalarLog10(e2);
    c_st.site = &uc_emlrtRSI;
    e2 = tvi(&c_st, e2);
    c_st.site = &fc_emlrtRSI;
    ssm = muDoubleScalarPower(10.0, e2);
    b_st.site = &uc_emlrtRSI;
    c_st.site = &uc_emlrtRSI;
    if (sm < 0.0) {
      emlrtErrorWithMessageIdR2018a(
          &c_st, &v_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
          "Coder:toolbox:ElFunDomainError", 3, 4, 5, "log10");
    }
    sm = muDoubleScalarLog10(sm);
    c_st.site = &uc_emlrtRSI;
    e2 = tvi(&c_st, sm);
    c_st.site = &fc_emlrtRSI;
    b_st.site = &tc_emlrtRSI;
    i = (int32_T)(edges_data[iindx] + 1.0);
    if ((i < 1) || (i > b_lum->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i, 1, b_lum->size[1], &k_emlrtBCI, &b_st);
    }
    if (((int32_T)d < 1) || ((int32_T)d > b_lum->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, b_lum->size[1], &l_emlrtBCI,
                                    &b_st);
    }
    ssm = ssm / (ssm + muDoubleScalarPower(10.0, e2)) *
              (b_lum_data[(int32_T)d - 1] - b_lum_data[i - 1]) +
          b_lum_data[i - 1];
    e2 = edges_data[iindx];
    i = delta1->size[0] * delta1->size[1];
    delta1->size[0] = 1;
    delta1->size[1] = (int32_T)(n - 1.0) + 1;
    emxEnsureCapacity_real_T(&b_st, delta1, i, &lc_emlrtRTEI);
    b_y_data = delta1->data;
    nx = (int32_T)(n - 1.0);
    for (i = 0; i <= nx; i++) {
      k = (int32_T)(e2 + (real_T)(i + 1));
      if ((k < 1) || (k > b_lum->size[1])) {
        emlrtDynamicBoundsCheckR2012b(k, 1, b_lum->size[1], &j_emlrtBCI, &b_st);
      }
      b_y_data[i] = ssm - b_lum_data[k - 1];
    }
    c_st.site = &tc_emlrtRSI;
    b_abs(&c_st, delta1, b_y);
    b_y_data = b_y->data;
    c_st.site = &ue_emlrtRSI;
    d_st.site = &ve_emlrtRSI;
    e_st.site = &we_emlrtRSI;
    if (b_y->size[1] < 1) {
      emlrtErrorWithMessageIdR2018a(
          &e_st, &b_emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
          "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }
    f_st.site = &fe_emlrtRSI;
    maxdimlen = b_y->size[1];
    if (b_y->size[1] <= 2) {
      if (b_y->size[1] == 1) {
        varargin_2 = 1;
      } else if ((b_y_data[0] > b_y_data[1]) ||
                 (muDoubleScalarIsNaN(b_y_data[0]) &&
                  (!muDoubleScalarIsNaN(b_y_data[1])))) {
        varargin_2 = 2;
      } else {
        varargin_2 = 1;
      }
    } else {
      g_st.site = &bc_emlrtRSI;
      if (!muDoubleScalarIsNaN(b_y_data[0])) {
        varargin_2 = 1;
      } else {
        varargin_2 = 0;
        h_st.site = &dc_emlrtRSI;
        if (b_y->size[1] > 2147483646) {
          i_st.site = &cb_emlrtRSI;
          check_forloop_overflow_error(&i_st);
        }
        k = 2;
        exitg1 = false;
        while ((!exitg1) && (k <= maxdimlen)) {
          if (!muDoubleScalarIsNaN(b_y_data[k - 1])) {
            varargin_2 = k;
            exitg1 = true;
          } else {
            k++;
          }
        }
      }
      if (varargin_2 == 0) {
        varargin_2 = 1;
      } else {
        g_st.site = &cc_emlrtRSI;
        e2 = b_y_data[varargin_2 - 1];
        nx = varargin_2 + 1;
        h_st.site = &ec_emlrtRSI;
        if ((varargin_2 + 1 <= b_y->size[1]) && (b_y->size[1] > 2147483646)) {
          i_st.site = &cb_emlrtRSI;
          check_forloop_overflow_error(&i_st);
        }
        for (k = nx; k <= maxdimlen; k++) {
          d = b_y_data[k - 1];
          if (e2 > d) {
            e2 = d;
            varargin_2 = k;
          }
        }
      }
    }
    d = edges_data[iindx] + (real_T)varargin_2;
    if (((int32_T)d < 1) || ((int32_T)d > s_data->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, s_data->size[1], &i_emlrtBCI,
                                    &st);
    }
    sm = s_data_data[(int32_T)d - 1];
    if (covrtLogIf(&emlrtCoverageInstance, 2U, 0U, 5,
                   edges_data[iindx] >= 1.0)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 12U);
      i = (int32_T)edges_data[iindx];
      if ((i < 1) || (i > s_data->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)edges_data[iindx], 1,
                                      s_data->size[1], &g_emlrtBCI, &st);
      }
      sm -= s_data_data[(int32_T)edges_data[iindx] - 1];
    }
    covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 13U);
    if (((int32_T)d < 1) || ((int32_T)d > ss_data->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, ss_data->size[1],
                                    &h_emlrtBCI, &st);
    }
    ssm = ss_data_data[(int32_T)d - 1];
    if (covrtLogIf(&emlrtCoverageInstance, 2U, 0U, 6,
                   edges_data[iindx] >= 1.0)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 14U);
      i = (int32_T)edges_data[iindx];
      if ((i < 1) || (i > ss_data->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)edges_data[iindx], 1,
                                      ss_data->size[1], &f_emlrtBCI, &st);
      }
      ssm -= ss_data_data[(int32_T)edges_data[iindx] - 1];
    }
    covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 15U);
    b_st.site = &sc_emlrtRSI;
    c_st.site = &ge_emlrtRSI;
    d_st.site = &fc_emlrtRSI;
    b_st.site = &rc_emlrtRSI;
    e2 = sn - sm;
    c_st.site = &ge_emlrtRSI;
    d_st.site = &fc_emlrtRSI;
    if ((iindx + 1 < 1) || (iindx + 1 > edges->size[1])) {
      emlrtDynamicBoundsCheckR2012b(iindx + 1, 1, edges->size[1], &mb_emlrtBCI,
                                    &st);
    }
    if ((real_T)(iindx + 1) + 1.0 > edges->size[1]) {
      i = 0;
      k = 0;
    } else {
      if ((iindx + 2 < 1) || (iindx + 2 > edges->size[1])) {
        emlrtDynamicBoundsCheckR2012b(iindx + 2, 1, edges->size[1],
                                      &nb_emlrtBCI, &st);
      }
      i = iindx + 1;
      if (edges->size[1] < 1) {
        emlrtDynamicBoundsCheckR2012b(edges->size[1], 1, edges->size[1],
                                      &ob_emlrtBCI, &st);
      }
      k = edges->size[1];
    }
    maxdimlen = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = ((iindx + k) - i) + 2;
    emxEnsureCapacity_real_T(&st, b_y, maxdimlen, &mc_emlrtRTEI);
    b_y_data = b_y->data;
    for (maxdimlen = 0; maxdimlen <= iindx; maxdimlen++) {
      b_y_data[maxdimlen] = edges_data[maxdimlen];
    }
    b_y_data[iindx + 1] = d;
    nx = k - i;
    for (k = 0; k < nx; k++) {
      b_y_data[(k + iindx) + 2] = edges_data[i + k];
    }
    i = edges->size[0] * edges->size[1];
    edges->size[0] = 1;
    edges->size[1] = b_y->size[1];
    emxEnsureCapacity_real_T(&st, edges, i, &nc_emlrtRTEI);
    edges_data = edges->data;
    nx = b_y->size[1];
    for (i = 0; i < nx; i++) {
      edges_data[i] = b_y_data[i];
    }
    if ((real_T)(iindx + 1) - 1.0 < 1.0) {
      nx = 0;
    } else {
      if ((iindx < 1) || (iindx > errors->size[1])) {
        emlrtDynamicBoundsCheckR2012b(iindx, 1, errors->size[1], &pb_emlrtBCI,
                                      &st);
      }
      nx = iindx;
    }
    if ((real_T)(iindx + 1) + 1.0 > errors->size[1]) {
      i = 0;
      k = 0;
    } else {
      if ((iindx + 2 < 1) || (iindx + 2 > errors->size[1])) {
        emlrtDynamicBoundsCheckR2012b(iindx + 2, 1, errors->size[1],
                                      &qb_emlrtBCI, &st);
      }
      i = iindx + 1;
      if (errors->size[1] < 1) {
        emlrtDynamicBoundsCheckR2012b(errors->size[1], 1, errors->size[1],
                                      &rb_emlrtBCI, &st);
      }
      k = errors->size[1];
    }
    maxdimlen = b_y->size[0] * b_y->size[1];
    b_y->size[0] = 1;
    b_y->size[1] = ((nx + k) - i) + 2;
    emxEnsureCapacity_real_T(&st, b_y, maxdimlen, &oc_emlrtRTEI);
    b_y_data = b_y->data;
    for (maxdimlen = 0; maxdimlen < nx; maxdimlen++) {
      b_y_data[maxdimlen] = errors_data[maxdimlen];
    }
    b_y_data[nx] = ssm - sm * sm / (real_T)varargin_2;
    b_y_data[nx + 1] = (ssn - ssm) - e2 * e2 / (n - (real_T)varargin_2);
    maxdimlen = k - i;
    for (k = 0; k < maxdimlen; k++) {
      b_y_data[(k + nx) + 2] = errors_data[i + k];
    }
    i = errors->size[0] * errors->size[1];
    errors->size[0] = 1;
    errors->size[1] = b_y->size[1];
    emxEnsureCapacity_real_T(&st, errors, i, &pc_emlrtRTEI);
    errors_data = errors->data;
    nx = b_y->size[1];
    for (i = 0; i < nx; i++) {
      errors_data[i] = b_y_data[i];
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
  emxFree_real_T(&st, &delta1);
  emxFree_real_T(&st, &errors);
  emxFree_real_T(&st, &b_y);
  emxFree_real_T(&st, &ss_data);
  emxFree_real_T(&st, &s_data);
  covrtLogFor(&emlrtCoverageInstance, 2U, 0U, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 18U);
  memset(&mdata[0], 0, 55U * sizeof(real_T));
  b_st.site = &qc_emlrtRSI;
  c_st.site = &xe_emlrtRSI;
  d_st.site = &ye_emlrtRSI;
  e_st.site = &af_emlrtRSI;
  if (lum->size[0] * lum->size[1] < 1) {
    emlrtErrorWithMessageIdR2018a(&e_st, &b_emlrtRTEI,
                                  "Coder:toolbox:eml_min_or_max_varDimZero",
                                  "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }
  f_st.site = &bf_emlrtRSI;
  g_st.site = &cf_emlrtRSI;
  maxdimlen = lum->size[0] * lum->size[1];
  if (lum->size[0] * lum->size[1] <= 2) {
    if (lum->size[0] * lum->size[1] == 1) {
      mdata[0] = lum_data[0];
    } else if ((lum_data[0] > lum_data[lum->size[0] * lum->size[1] - 1]) ||
               (muDoubleScalarIsNaN(lum_data[0]) &&
                (!muDoubleScalarIsNaN(
                    lum_data[lum->size[0] * lum->size[1] - 1])))) {
      mdata[0] = lum_data[lum->size[0] * lum->size[1] - 1];
    } else {
      mdata[0] = lum_data[0];
    }
  } else {
    h_st.site = &bc_emlrtRSI;
    if (!muDoubleScalarIsNaN(lum_data[0])) {
      varargin_2 = 1;
    } else {
      varargin_2 = 0;
      i_st.site = &dc_emlrtRSI;
      if (lum->size[0] * lum->size[1] > 2147483646) {
        j_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&j_st);
      }
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= maxdimlen)) {
        if (!muDoubleScalarIsNaN(lum_data[k - 1])) {
          varargin_2 = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (varargin_2 == 0) {
      mdata[0] = lum_data[0];
    } else {
      h_st.site = &cc_emlrtRSI;
      e2 = lum_data[varargin_2 - 1];
      nx = varargin_2 + 1;
      i_st.site = &ec_emlrtRSI;
      if ((varargin_2 + 1 <= lum->size[0] * lum->size[1]) &&
          (lum->size[0] * lum->size[1] > 2147483646)) {
        j_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&j_st);
      }
      for (k = nx; k <= maxdimlen; k++) {
        if (e2 > lum_data[k - 1]) {
          e2 = lum_data[k - 1];
        }
      }
      mdata[0] = e2;
    }
  }
  b_st.site = &pc_emlrtRSI;
  c_st.site = &vb_emlrtRSI;
  d_st.site = &wb_emlrtRSI;
  e_st.site = &xb_emlrtRSI;
  if (lum->size[0] * lum->size[1] < 1) {
    emlrtErrorWithMessageIdR2018a(&e_st, &b_emlrtRTEI,
                                  "Coder:toolbox:eml_min_or_max_varDimZero",
                                  "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }
  f_st.site = &yb_emlrtRSI;
  g_st.site = &ac_emlrtRSI;
  maxdimlen = lum->size[0] * lum->size[1];
  if (lum->size[0] * lum->size[1] <= 2) {
    if (lum->size[0] * lum->size[1] == 1) {
      mdata[54] = lum_data[0];
    } else if ((lum_data[0] < lum_data[lum->size[0] * lum->size[1] - 1]) ||
               (muDoubleScalarIsNaN(lum_data[0]) &&
                (!muDoubleScalarIsNaN(
                    lum_data[lum->size[0] * lum->size[1] - 1])))) {
      mdata[54] = lum_data[lum->size[0] * lum->size[1] - 1];
    } else {
      mdata[54] = lum_data[0];
    }
  } else {
    h_st.site = &bc_emlrtRSI;
    if (!muDoubleScalarIsNaN(lum_data[0])) {
      varargin_2 = 1;
    } else {
      varargin_2 = 0;
      i_st.site = &dc_emlrtRSI;
      if (lum->size[0] * lum->size[1] > 2147483646) {
        j_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&j_st);
      }
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= maxdimlen)) {
        if (!muDoubleScalarIsNaN(lum_data[k - 1])) {
          varargin_2 = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (varargin_2 == 0) {
      mdata[54] = lum_data[0];
    } else {
      h_st.site = &cc_emlrtRSI;
      e2 = lum_data[varargin_2 - 1];
      nx = varargin_2 + 1;
      i_st.site = &ec_emlrtRSI;
      if ((varargin_2 + 1 <= lum->size[0] * lum->size[1]) &&
          (lum->size[0] * lum->size[1] > 2147483646)) {
        j_st.site = &cb_emlrtRSI;
        check_forloop_overflow_error(&j_st);
      }
      for (k = nx; k <= maxdimlen; k++) {
        if (e2 < lum_data[k - 1]) {
          e2 = lum_data[k - 1];
        }
      }
      mdata[54] = e2;
    }
  }
  emxInit_boolean_T(&st, &ind, 2, &ec_emlrtRTEI);
  emxInit_boolean_T(&st, &r1, 2, &hc_emlrtRTEI);
  emxInit_int32_T(&st, &r2, 1, &vc_emlrtRTEI);
  emxInit_int32_T(&st, &r3, 1, &wc_emlrtRTEI);
  emxInit_real_T(&st, &c_lum, 1, &kc_emlrtRTEI);
  for (b_i = 0; b_i < 53; b_i++) {
    covrtLogFor(&emlrtCoverageInstance, 2U, 0U, 1, 1);
    if (b_i + 3 > edges->size[1]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 3, 1, edges->size[1], &v_emlrtBCI,
                                    &st);
    }
    i = (int32_T)edges_data[b_i + 2];
    if ((i < 1) || (i > b_lum->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)edges_data[b_i + 2], 1,
                                    b_lum->size[1], &w_emlrtBCI, &st);
    }
    if (b_i + 2 > edges->size[1]) {
      emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, edges->size[1], &x_emlrtBCI,
                                    &st);
    }
    k = (int32_T)edges_data[b_i + 1];
    if ((k < 1) || (k > b_lum->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)edges_data[b_i + 1], 1,
                                    b_lum->size[1], &y_emlrtBCI, &st);
    }
    if (covrtLogIf(&emlrtCoverageInstance, 2U, 0U, 9,
                   b_lum_data[k - 1] == b_lum_data[i - 1])) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 19U);
      i = ind->size[0] * ind->size[1];
      ind->size[0] = lum->size[0];
      ind->size[1] = lum->size[1];
      emxEnsureCapacity_boolean_T(&st, ind, i, &ec_emlrtRTEI);
      ind_data = ind->data;
      if (b_i + 2 > edges->size[1]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, edges->size[1], &r_emlrtBCI,
                                      &st);
      }
      i = (int32_T)edges_data[b_i + 1];
      if ((i < 1) || (i > b_lum->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)edges_data[b_i + 1], 1,
                                      b_lum->size[1], &s_emlrtBCI, &st);
      }
      e2 = b_lum_data[i - 1];
      nx = lum->size[0] * lum->size[1];
      for (i = 0; i < nx; i++) {
        ind_data[i] = (lum_data[i] == e2);
      }
      b_st.site = &oc_emlrtRSI;
      indexShapeCheck(&b_st, lum->size, ind->size);
      nx = ind->size[0] * ind->size[1] - 1;
      maxdimlen = 0;
      for (varargin_2 = 0; varargin_2 <= nx; varargin_2++) {
        if (ind_data[varargin_2]) {
          maxdimlen++;
        }
      }
      i = r2->size[0];
      r2->size[0] = maxdimlen;
      emxEnsureCapacity_int32_T(&st, r2, i, &hc_emlrtRTEI);
      r5 = r2->data;
      maxdimlen = 0;
      for (varargin_2 = 0; varargin_2 <= nx; varargin_2++) {
        if (ind_data[varargin_2]) {
          r5[maxdimlen] = varargin_2 + 1;
          maxdimlen++;
        }
      }
      maxdimlen = lum->size[0] * lum->size[1];
      nx = r2->size[0];
      i = c_lum->size[0];
      c_lum->size[0] = r2->size[0];
      emxEnsureCapacity_real_T(&st, c_lum, i, &ic_emlrtRTEI);
      b_y_data = c_lum->data;
      for (i = 0; i < nx; i++) {
        if ((r5[i] < 1) || (r5[i] > maxdimlen)) {
          emlrtDynamicBoundsCheckR2012b(r5[i], 1, maxdimlen, &n_emlrtBCI, &st);
        }
        b_y_data[i] = lum_data[r5[i] - 1];
      }
      b_st.site = &oc_emlrtRSI;
      mdata[b_i + 1] =
          b_mean(&b_st, c_lum) + 2.2204460492503131E-16 * ((real_T)b_i + 2.0);
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 20U);
      i = ind->size[0] * ind->size[1];
      ind->size[0] = lum->size[0];
      ind->size[1] = lum->size[1];
      emxEnsureCapacity_boolean_T(&st, ind, i, &dc_emlrtRTEI);
      ind_data = ind->data;
      if (b_i + 2 > edges->size[1]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, edges->size[1], &t_emlrtBCI,
                                      &st);
      }
      i = (int32_T)edges_data[b_i + 1];
      if ((i < 1) || (i > b_lum->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)edges_data[b_i + 1], 1,
                                      b_lum->size[1], &u_emlrtBCI, &st);
      }
      e2 = b_lum_data[i - 1];
      nx = lum->size[0] * lum->size[1];
      for (i = 0; i < nx; i++) {
        ind_data[i] = (lum_data[i] > e2);
      }
      i = r1->size[0] * r1->size[1];
      r1->size[0] = lum->size[0];
      r1->size[1] = lum->size[1];
      emxEnsureCapacity_boolean_T(&st, r1, i, &gc_emlrtRTEI);
      r4 = r1->data;
      if (b_i + 3 > edges->size[1]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 3, 1, edges->size[1], &o_emlrtBCI,
                                      &st);
      }
      i = (int32_T)edges_data[b_i + 2];
      if ((i < 1) || (i > b_lum->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)edges_data[b_i + 2], 1,
                                      b_lum->size[1], &p_emlrtBCI, &st);
      }
      e2 = b_lum_data[i - 1];
      nx = lum->size[0] * lum->size[1];
      for (i = 0; i < nx; i++) {
        r4[i] = (lum_data[i] <= e2);
      }
      if ((ind->size[0] != r1->size[0]) || (ind->size[1] != r1->size[1])) {
        emlrtSizeEqCheckNDErrorR2021b(&ind->size[0], &r1->size[0], &i_emlrtECI,
                                      &st);
      }
      nx = ind->size[0] * ind->size[1];
      for (i = 0; i < nx; i++) {
        ind_data[i] = (ind_data[i] && r4[i]);
      }
      b_st.site = &nc_emlrtRSI;
      indexShapeCheck(&b_st, lum->size, ind->size);
      nx = ind->size[0] * ind->size[1] - 1;
      maxdimlen = 0;
      for (varargin_2 = 0; varargin_2 <= nx; varargin_2++) {
        if (ind_data[varargin_2]) {
          maxdimlen++;
        }
      }
      i = r3->size[0];
      r3->size[0] = maxdimlen;
      emxEnsureCapacity_int32_T(&st, r3, i, &hc_emlrtRTEI);
      r5 = r3->data;
      maxdimlen = 0;
      for (varargin_2 = 0; varargin_2 <= nx; varargin_2++) {
        if (ind_data[varargin_2]) {
          r5[maxdimlen] = varargin_2 + 1;
          maxdimlen++;
        }
      }
      maxdimlen = lum->size[0] * lum->size[1];
      nx = r3->size[0];
      i = c_lum->size[0];
      c_lum->size[0] = r3->size[0];
      emxEnsureCapacity_real_T(&st, c_lum, i, &kc_emlrtRTEI);
      b_y_data = c_lum->data;
      for (i = 0; i < nx; i++) {
        if ((r5[i] < 1) || (r5[i] > maxdimlen)) {
          emlrtDynamicBoundsCheckR2012b(r5[i], 1, maxdimlen, &m_emlrtBCI, &st);
        }
        b_y_data[i] = lum_data[r5[i] - 1];
      }
      b_st.site = &nc_emlrtRSI;
      mdata[b_i + 1] = b_mean(&b_st, c_lum);
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
  emxFree_real_T(&st, &c_lum);
  emxFree_int32_T(&st, &r3);
  emxFree_int32_T(&st, &r2);
  emxFree_boolean_T(&st, &r1);
  emxFree_real_T(&st, &b_lum);
  emxFree_boolean_T(&st, &ind);
  covrtLogFor(&emlrtCoverageInstance, 2U, 0U, 1, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 21U);
  b_st.site = &mc_emlrtRSI;
  interp1(&b_st, mdata, lum, labels);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (quantizeNL_float.c) */
