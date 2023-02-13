/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * DCA_TMO_terminate.c
 *
 * Code generation for function 'DCA_TMO_terminate'
 *
 */

/* Include files */
#include "DCA_TMO_terminate.h"
#include "DCA_TMO_data.h"
#include "_coder_DCA_TMO_mex.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void DCA_TMO_atexit(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);
  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);
  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);
  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void DCA_TMO_terminate(void)
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (DCA_TMO_terminate.c) */
