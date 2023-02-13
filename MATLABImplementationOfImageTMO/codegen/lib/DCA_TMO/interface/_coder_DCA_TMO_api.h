//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_DCA_TMO_api.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 17-Jan-2023 23:47:54
//

#ifndef _CODER_DCA_TMO_API_H
#define _CODER_DCA_TMO_API_H

// Include Files
#include "coder_array_mex.h"
#include "emlrt.h"
#include "tmwtypes.h"
#include <algorithm>
#include <cstring>

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

// Function Declarations
void DCA_TMO(coder::array<real_T, 3U> *hdrImg,
             coder::array<real_T, 3U> *ldrImg);

void DCA_TMO_api(const mxArray *prhs, const mxArray **plhs);

void DCA_TMO_atexit();

void DCA_TMO_initialize();

void DCA_TMO_terminate();

void DCA_TMO_xil_shutdown();

void DCA_TMO_xil_terminate();

#endif
//
// File trailer for _coder_DCA_TMO_api.h
//
// [EOF]
//
