/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_DCA_TMO_api.h
 *
 * Code generation for function 'DCA_TMO'
 *
 */

#ifndef _CODER_DCA_TMO_API_H
#define _CODER_DCA_TMO_API_H

/* Include files */
#include "emlrt.h"
#include "tmwtypes.h"
#include <string.h>

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real_T */
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /* typedef_emxArray_real_T */

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void DCA_TMO(emxArray_real_T *hdrImg, emxArray_real_T *ldrImg);

void DCA_TMO_api(const mxArray *prhs, const mxArray **plhs);

void DCA_TMO_atexit(void);

void DCA_TMO_initialize(void);

void DCA_TMO_terminate(void);

void DCA_TMO_xil_shutdown(void);

void DCA_TMO_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_DCA_TMO_api.h) */
