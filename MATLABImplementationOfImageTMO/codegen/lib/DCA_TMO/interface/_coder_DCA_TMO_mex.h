//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_DCA_TMO_mex.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 17-Jan-2023 23:47:54
//

#ifndef _CODER_DCA_TMO_MEX_H
#define _CODER_DCA_TMO_MEX_H

// Include Files
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"

// Function Declarations
MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[],
                                     int32_T nrhs, const mxArray *prhs[]);

emlrtCTX mexFunctionCreateRootTLS();

void unsafe_DCA_TMO_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                                const mxArray *prhs[1]);

#endif
//
// File trailer for _coder_DCA_TMO_mex.h
//
// [EOF]
//
