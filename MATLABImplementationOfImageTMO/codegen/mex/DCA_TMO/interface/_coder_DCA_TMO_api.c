/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_DCA_TMO_api.c
 *
 * Code generation for function '_coder_DCA_TMO_api'
 *
 */

/* Include files */
#include "_coder_DCA_TMO_api.h"
#include "DCA_TMO.h"
#include "DCA_TMO_data.h"
#include "DCA_TMO_emxutil.h"
#include "DCA_TMO_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo nd_emlrtRTEI = {
    1,                    /* lineNo */
    1,                    /* colNo */
    "_coder_DCA_TMO_api", /* fName */
    ""                    /* pName */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *hdrImg,
                             const char_T *identifier, emxArray_real_T *y);

static const mxArray *emlrt_marshallOut(const emxArray_real_T *u);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  c_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret)
{
  static const int32_T dims[3] = {-1, -1, 3};
  int32_T iv[3];
  int32_T i;
  const boolean_T bv[3] = {true, true, false};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 3U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret->allocatedSize = iv[0] * iv[1] * iv[2];
  i = ret->size[0] * ret->size[1] * ret->size[2];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  ret->size[2] = iv[2];
  emxEnsureCapacity_real_T(sp, ret, i, (emlrtRTEInfo *)NULL);
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *hdrImg,
                             const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(hdrImg), &thisId, y);
  emlrtDestroyArray(&hdrImg);
}

static const mxArray *emlrt_marshallOut(const emxArray_real_T *u)
{
  static const int32_T iv[3] = {0, 0, 0};
  const mxArray *m;
  const mxArray *y;
  const real_T *u_data;
  u_data = u->data;
  y = NULL;
  m = emlrtCreateNumericArray(3, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u_data[0]);
  emlrtSetDimensions((mxArray *)m, &u->size[0], 3);
  emlrtAssign(&y, m);
  return y;
}

void DCA_TMO_api(const mxArray *prhs, const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_real_T *hdrImg;
  emxArray_real_T *ldrImg;
  const mxArray *prhs_copy_idx_0;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  prhs_copy_idx_0 = emlrtProtectR2012b(prhs, 0, false, -1);
  /* Marshall function inputs */
  emxInit_real_T(&st, &hdrImg, 3, &nd_emlrtRTEI);
  hdrImg->canFreeData = false;
  emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_0), "hdrImg", hdrImg);
  /* Invoke the target function */
  emxInit_real_T(&st, &ldrImg, 3, &nd_emlrtRTEI);
  DCA_TMO(&st, hdrImg, ldrImg);
  emxFree_real_T(&st, &hdrImg);
  /* Marshall function outputs */
  ldrImg->canFreeData = false;
  *plhs = emlrt_marshallOut(ldrImg);
  emxFree_real_T(&st, &ldrImg);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_DCA_TMO_api.c) */
