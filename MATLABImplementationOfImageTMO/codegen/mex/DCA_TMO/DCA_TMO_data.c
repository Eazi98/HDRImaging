/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * DCA_TMO_data.c
 *
 * Code generation for function 'DCA_TMO_data'
 *
 */

/* Include files */
#include "DCA_TMO_data.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                                 /* bFirstTime */
    false,                                                /* bInitialized */
    131627U,                                              /* fVersionInfo */
    NULL,                                                 /* fErrorFunction */
    "DCA_TMO",                                            /* fFunctionName */
    NULL,                                                 /* fRTCallStack */
    false,                                                /* bDebugMode */
    {3334497894U, 1318968193U, 3466680636U, 2802620837U}, /* fSigWrd */
    NULL                                                  /* fSigMem */
};

emlrtRSInfo t_emlrtRSI = {
    32,     /* lineNo */
    "sort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m" /* pathName
                                                                         */
};

emlrtRSInfo cb_emlrtRSI = {
    20,                               /* lineNo */
    "eml_int_forloop_overflow_check", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_"
    "overflow_check.m" /* pathName */
};

emlrtRSInfo
    db_emlrtRSI =
        {
            105,       /* lineNo */
            "sortIdx", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\sortIdx.m" /* pathName */
};

emlrtRSInfo
    eb_emlrtRSI =
        {
            308,                /* lineNo */
            "block_merge_sort", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\sortIdx.m" /* pathName */
};

emlrtRSInfo
    fb_emlrtRSI =
        {
            316,                /* lineNo */
            "block_merge_sort", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\sortIdx.m" /* pathName */
};

emlrtRSInfo
    gb_emlrtRSI =
        {
            317,                /* lineNo */
            "block_merge_sort", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\sortIdx.m" /* pathName */
};

emlrtRSInfo
    hb_emlrtRSI =
        {
            325,                /* lineNo */
            "block_merge_sort", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\sortIdx.m" /* pathName */
};

emlrtRSInfo
    ib_emlrtRSI =
        {
            333,                /* lineNo */
            "block_merge_sort", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\sortIdx.m" /* pathName */
};

emlrtRSInfo
    jb_emlrtRSI =
        {
            392,                      /* lineNo */
            "initialize_vector_sort", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\sortIdx.m" /* pathName */
};

emlrtRSInfo
    kb_emlrtRSI =
        {
            420,                      /* lineNo */
            "initialize_vector_sort", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\sortIdx.m" /* pathName */
};

emlrtRSInfo
    lb_emlrtRSI =
        {
            427,                      /* lineNo */
            "initialize_vector_sort", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\sortIdx.m" /* pathName */
};

emlrtRSInfo
    mb_emlrtRSI =
        {
            587,                /* lineNo */
            "merge_pow2_block", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\sortIdx.m" /* pathName */
};

emlrtRSInfo
    nb_emlrtRSI =
        {
            589,                /* lineNo */
            "merge_pow2_block", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\sortIdx.m" /* pathName */
};

emlrtRSInfo
    ob_emlrtRSI =
        {
            617,                /* lineNo */
            "merge_pow2_block", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\sortIdx.m" /* pathName */
};

emlrtRSInfo vb_emlrtRSI = {
    15,    /* lineNo */
    "max", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\datafun\\max.m" /* pathName
                                                                        */
};

emlrtRSInfo wb_emlrtRSI =
    {
        44,         /* lineNo */
        "minOrMax", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" /* pathName */
};

emlrtRSInfo xb_emlrtRSI =
    {
        79,        /* lineNo */
        "maximum", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" /* pathName */
};

emlrtRSInfo yb_emlrtRSI = {
    190,             /* lineNo */
    "unaryMinOrMax", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" /* pathName */
};

emlrtRSInfo ac_emlrtRSI = {
    901,                    /* lineNo */
    "maxRealVectorOmitNaN", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" /* pathName */
};

emlrtRSInfo bc_emlrtRSI = {
    64,                      /* lineNo */
    "vectorMinOrMaxInPlace", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\vectorMinOrMaxInPlace.m" /* pathName */
};

emlrtRSInfo cc_emlrtRSI = {
    72,                      /* lineNo */
    "vectorMinOrMaxInPlace", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\vectorMinOrMaxInPlace.m" /* pathName */
};

emlrtRSInfo dc_emlrtRSI = {
    113,         /* lineNo */
    "findFirst", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\vectorMinOrMaxInPlace.m" /* pathName */
};

emlrtRSInfo ec_emlrtRSI = {
    130,                        /* lineNo */
    "minOrMaxRealVectorKernel", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\vectorMinOrMaxInPlace.m" /* pathName */
};

emlrtRSInfo fc_emlrtRSI =
    {
        71,      /* lineNo */
        "power", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\ops\\power.m" /* pathName
                                                                          */
};

emlrtRSInfo gc_emlrtRSI =
    {
        81,         /* lineNo */
        "fltpower", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\ops\\power.m" /* pathName
                                                                          */
};

emlrtRSInfo hc_emlrtRSI =
    {
        102,                     /* lineNo */
        "fltpower_domain_error", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\ops\\power.m" /* pathName
                                                                          */
};

emlrtRSInfo ic_emlrtRSI =
    {
        44,          /* lineNo */
        "vAllOrAny", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\vAllOrAny.m" /* pathName */
};

emlrtRSInfo jc_emlrtRSI =
    {
        103,                  /* lineNo */
        "flatVectorAllOrAny", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\vAllOrAny.m" /* pathName */
};

emlrtRSInfo jd_emlrtRSI = {
    74,                      /* lineNo */
    "combineVectorElements", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combin"
    "eVectorElements.m" /* pathName */
};

emlrtRSInfo kd_emlrtRSI = {
    99,                 /* lineNo */
    "blockedSummation", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\blocke"
    "dSummation.m" /* pathName */
};

emlrtRSInfo ld_emlrtRSI = {
    22,                    /* lineNo */
    "sumMatrixIncludeNaN", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMat"
    "rixIncludeNaN.m" /* pathName */
};

emlrtRSInfo md_emlrtRSI = {
    42,                 /* lineNo */
    "sumMatrixColumns", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMat"
    "rixIncludeNaN.m" /* pathName */
};

emlrtRSInfo nd_emlrtRSI = {
    57,                 /* lineNo */
    "sumMatrixColumns", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMat"
    "rixIncludeNaN.m" /* pathName */
};

emlrtRSInfo xe_emlrtRSI = {
    15,    /* lineNo */
    "min", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\datafun\\min.m" /* pathName
                                                                        */
};

emlrtRSInfo ye_emlrtRSI =
    {
        46,         /* lineNo */
        "minOrMax", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" /* pathName */
};

emlrtRSInfo af_emlrtRSI =
    {
        92,        /* lineNo */
        "minimum", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" /* pathName */
};

emlrtRSInfo bf_emlrtRSI = {
    208,             /* lineNo */
    "unaryMinOrMax", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" /* pathName */
};

emlrtRSInfo cf_emlrtRSI = {
    897,                    /* lineNo */
    "minRealVectorOmitNaN", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" /* pathName */
};

emlrtRTEInfo b_emlrtRTEI = {
    134,             /* lineNo */
    27,              /* colNo */
    "unaryMinOrMax", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" /* pName */
};

emlrtRTEInfo d_emlrtRTEI = {
    74,                  /* lineNo */
    13,                  /* colNo */
    "reshapeSizeChecks", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" /* pName */
};

emlrtRTEInfo e_emlrtRTEI =
    {
        82,         /* lineNo */
        5,          /* colNo */
        "fltpower", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\ops\\power.m" /* pName
                                                                          */
};

emlrtRTEInfo ub_emlrtRTEI =
    {
        71,      /* lineNo */
        5,       /* colNo */
        "power", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\ops\\power.m" /* pName
                                                                          */
};

emlrtRTEInfo
    sd_emlrtRTEI =
        {
            386,       /* lineNo */
            1,         /* colNo */
            "sortIdx", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\sortIdx.m" /* pName */
};

emlrtRTEInfo
    td_emlrtRTEI =
        {
            388,       /* lineNo */
            1,         /* colNo */
            "sortIdx", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\sortIdx.m" /* pName */
};

emlrtRTEInfo
    ud_emlrtRTEI =
        {
            308,       /* lineNo */
            14,        /* colNo */
            "sortIdx", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\sortIdx.m" /* pName */
};

emlrtRTEInfo
    vd_emlrtRTEI =
        {
            308,       /* lineNo */
            20,        /* colNo */
            "sortIdx", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2022b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\sortIdx.m" /* pName */
};

const real_T dv[81] = {
    -3.4536032619442708E-12, -8.1906882011251731E-10, -4.0717697696829158E-8,
    -4.2428815204386648E-7,  -9.2673052019452823E-7,  -4.2428815204386648E-7,
    -4.0717697696829158E-8,  -8.1906882011251731E-10, -3.4536032619442708E-12,
    -8.1906882011251731E-10, -1.9425327135208133E-7,  -9.65675069311889E-6,
    -0.00010062441064619439, -0.00021977728197372114, -0.00010062441064619439,
    -9.65675069311889E-6,    -1.9425327135208133E-7,  -8.1906882011251731E-10,
    -4.0717697696829158E-8,  -9.65675069311889E-6,    -0.00047998867375253048,
    -0.00497423370067001,    -0.0107185279736246,     -0.00497423370067001,
    -0.00047998867375253048, -9.65675069311889E-6,    -4.0717697696829158E-8,
    -4.2428815204386648E-7,  -0.00010062441064619439, -0.00497423370067001,
    -0.040793629460149305,   -0.030121274736625389,   -0.040793629460149305,
    -0.00497423370067001,    -0.00010062441064619439, -4.2428815204386648E-7,
    -9.2673052019452823E-7,  -0.00021977728197372114, -0.0107185279736246,
    -0.030121274736625389,   0.370017121948906,       -0.030121274736625389,
    -0.0107185279736246,     -0.00021977728197372114, -9.2673052019452823E-7,
    -4.2428815204386648E-7,  -0.00010062441064619439, -0.00497423370067001,
    -0.040793629460149305,   -0.030121274736625389,   -0.040793629460149305,
    -0.00497423370067001,    -0.00010062441064619439, -4.2428815204386648E-7,
    -4.0717697696829158E-8,  -9.65675069311889E-6,    -0.00047998867375253048,
    -0.00497423370067001,    -0.0107185279736246,     -0.00497423370067001,
    -0.00047998867375253048, -9.65675069311889E-6,    -4.0717697696829158E-8,
    -8.1906882011251731E-10, -1.9425327135208133E-7,  -9.65675069311889E-6,
    -0.00010062441064619439, -0.00021977728197372114, -0.00010062441064619439,
    -9.65675069311889E-6,    -1.9425327135208133E-7,  -8.1906882011251731E-10,
    -3.4536032619442708E-12, -8.1906882011251731E-10, -4.0717697696829158E-8,
    -4.2428815204386648E-7,  -9.2673052019452823E-7,  -4.2428815204386648E-7,
    -4.0717697696829158E-8,  -8.1906882011251731E-10, -3.4536032619442708E-12};

covrtInstance emlrtCoverageInstance;

/* End of code generation (DCA_TMO_data.c) */
