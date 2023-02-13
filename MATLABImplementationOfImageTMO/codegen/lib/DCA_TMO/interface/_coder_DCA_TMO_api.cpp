//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_DCA_TMO_api.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 17-Jan-2023 23:47:54
//

// Include Files
#include "_coder_DCA_TMO_api.h"
#include "_coder_DCA_TMO_mex.h"
#include "coder_array_mex.h"

// Variable Definitions
emlrtCTX emlrtRootTLSGlobal{nullptr};

emlrtContext emlrtContextGlobal{
    true,                                                 // bFirstTime
    false,                                                // bInitialized
    131627U,                                              // fVersionInfo
    nullptr,                                              // fErrorFunction
    "DCA_TMO",                                            // fFunctionName
    nullptr,                                              // fRTCallStack
    false,                                                // bDebugMode
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, // fSigWrd
    nullptr                                               // fSigMem
};

// Function Declarations
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 3U> &ret);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *hdrImg,
                             const char_T *identifier,
                             coder::array<real_T, 3U> &y);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<real_T, 3U> &y);

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 3U> &u);

// Function Definitions
//
// Arguments    : const emlrtStack *sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
//                coder::array<real_T, 3U> &ret
// Return Type  : void
//
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 3U> &ret)
{
  static const int32_T dims[3]{-1, -1, 3};
  int32_T iv[3];
  const boolean_T bv[3]{true, true, false};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 3U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret.prealloc(iv[0] * iv[1] * iv[2]);
  ret.set_size(iv[0], iv[1], iv[2]);
  ret.set(static_cast<real_T *>(emlrtMxGetData(src)), ret.size(0), ret.size(1),
          ret.size(2));
  emlrtDestroyArray(&src);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *hdrImg
//                const char_T *identifier
//                coder::array<real_T, 3U> &y
// Return Type  : void
//
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *hdrImg,
                             const char_T *identifier,
                             coder::array<real_T, 3U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(sp, emlrtAlias(hdrImg), &thisId, y);
  emlrtDestroyArray(&hdrImg);
}

//
// Arguments    : const emlrtStack *sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
//                coder::array<real_T, 3U> &y
// Return Type  : void
//
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<real_T, 3U> &y)
{
  b_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

//
// Arguments    : const coder::array<real_T, 3U> &u
// Return Type  : const mxArray *
//
static const mxArray *emlrt_marshallOut(const coder::array<real_T, 3U> &u)
{
  static const int32_T iv[3]{0, 0, 0};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(3, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &(((coder::array<real_T, 3U> *)&u)->data())[0]);
  emlrtSetDimensions((mxArray *)m, ((coder::array<real_T, 3U> *)&u)->size(), 3);
  emlrtAssign(&y, m);
  return y;
}

//
// Arguments    : const mxArray *prhs
//                const mxArray **plhs
// Return Type  : void
//
void DCA_TMO_api(const mxArray *prhs, const mxArray **plhs)
{
  coder::array<real_T, 3U> hdrImg;
  coder::array<real_T, 3U> ldrImg;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  const mxArray *prhs_copy_idx_0;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  prhs_copy_idx_0 = emlrtProtectR2012b(prhs, 0, false, -1);
  // Marshall function inputs
  hdrImg.no_free();
  emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_0), "hdrImg", hdrImg);
  // Invoke the target function
  DCA_TMO(hdrImg, ldrImg);
  // Marshall function outputs
  ldrImg.no_free();
  *plhs = emlrt_marshallOut(ldrImg);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

//
// Arguments    : void
// Return Type  : void
//
void DCA_TMO_atexit()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  DCA_TMO_xil_terminate();
  DCA_TMO_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

//
// Arguments    : void
// Return Type  : void
//
void DCA_TMO_initialize()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, nullptr);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

//
// Arguments    : void
// Return Type  : void
//
void DCA_TMO_terminate()
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

//
// File trailer for _coder_DCA_TMO_api.cpp
//
// [EOF]
//
