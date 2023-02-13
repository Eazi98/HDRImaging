/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * DCA_TMO_initialize.c
 *
 * Code generation for function 'DCA_TMO_initialize'
 *
 */

/* Include files */
#include "DCA_TMO_initialize.h"
#include "DCA_TMO_data.h"
#include "_coder_DCA_TMO_mex.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void DCA_TMO_once(void);

/* Function Definitions */
static void DCA_TMO_once(void)
{
  const int32_T postfix_exprs_2_0[3] = {0, 1, -2};
  const int32_T cond_ends_2_0[2] = {1329, 1339};
  const int32_T cond_starts_2_0[2] = {1311, 1333};
  mex_InitInfAndNan();
  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
                  "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for "
                  "Capstone\\MATLAB implementa"
                  "tion of imageTMO\\DCA_TMO.m",
                  0U, 1U, 6U, 4U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 0U, 0U, "DCA_TMO", 0, -1, 1585);
  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 5U, 1455, -1, 1581);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 4U, 1433, -1, 1442);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 3U, 1389, -1, 1415);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 2U, 1319, -1, 1330);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 1U, 1275, -1, 1301);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 0U, 53, -1, 1224);
  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 0U, 0U, 1225, 1236, -1, 1342);
  covrtIfInit(&emlrtCoverageInstance, 0U, 1U, 1241, 1266, 1306, 1338);
  covrtIfInit(&emlrtCoverageInstance, 0U, 2U, 1343, 1352, -1, 1454);
  covrtIfInit(&emlrtCoverageInstance, 0U, 3U, 1357, 1380, 1420, 1450);
  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 0U);
  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
                  "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for "
                  "Capstone\\MATLAB implementa"
                  "tion of imageTMO\\MaxQuart.m",
                  1U, 1U, 3U, 2U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 1U, 0U, "MaxQuart", 0, -1, 1243);
  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 2U, 1093, -1, 1238);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 1U, 1070, -1, 1087);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 0U, 1022, -1, 1039);
  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 1U, 0U, 997, 1017, -1, 1043);
  covrtIfInit(&emlrtCoverageInstance, 1U, 1U, 1045, 1065, -1, 1091);
  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 1U);
  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
                  "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for "
                  "Capstone\\MATLAB implementa"
                  "tion of imageTMO\\quantizeNL_float.m",
                  2U, 1U, 22U, 10U, 0U, 0U, 0U, 2U, 1U, 2U, 1U);
  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 2U, 0U, "quantizeNL_float", 0, -1, 2680);
  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 21U, 2580, -1, 2675);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 20U, 2479, -1, 2566);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 19U, 2391, -1, 2461);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 18U, 2250, -1, 2327);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 15U, 1854, -1, 2071);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 14U, 1801, -1, 1824);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 13U, 1742, -1, 1761);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 12U, 1692, -1, 1712);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 11U, 1353, -1, 1652);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 17U, 2190, -1, 2207);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 16U, 2126, -1, 2143);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 10U, 1220, -1, 1299);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 9U, 1175, -1, 1198);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 8U, 1124, -1, 1143);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 7U, 1082, -1, 1102);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 6U, 1033, -1, 1050);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 5U, 989, -1, 1011);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 4U, 952, -1, 975);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 3U, 909, -1, 928);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 2U, 875, -1, 895);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 1U, 767, -1, 851);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 0U, 341, -1, 740);
  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 2U, 0U, 857, 865, -1, 904);
  covrtIfInit(&emlrtCoverageInstance, 2U, 1U, 934, 942, -1, 984);
  covrtIfInit(&emlrtCoverageInstance, 2U, 2U, 1060, 1068, -1, 1115);
  covrtIfInit(&emlrtCoverageInstance, 2U, 3U, 1153, 1161, -1, 1211);
  covrtIfInit(&emlrtCoverageInstance, 2U, 4U, 1308, 1340, 2080, 2236);
  covrtIfInit(&emlrtCoverageInstance, 2U, 5U, 1666, 1674, -1, 1729);
  covrtIfInit(&emlrtCoverageInstance, 2U, 6U, 1775, 1783, -1, 1841);
  covrtIfInit(&emlrtCoverageInstance, 2U, 7U, 2097, 2108, 2157, 2209);
  covrtIfInit(&emlrtCoverageInstance, 2U, 8U, 2157, 2172, -1, 2209);
  covrtIfInit(&emlrtCoverageInstance, 2U, 9U, 2349, 2382, 2466, 2574);
  /* Initialize MCDC Information */
  covrtMcdcInit(&emlrtCoverageInstance, 2U, 0U, 1311, 1339, 2, 0,
                &cond_starts_2_0[0], &cond_ends_2_0[0], 3,
                &postfix_exprs_2_0[0]);
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 2U, 0U, 742, 762, 2248);
  covrtForInit(&emlrtCoverageInstance, 2U, 1U, 2328, 2344, 2578);
  /* Initialize While Information */
  covrtWhileInit(&emlrtCoverageInstance, 2U, 0U, 1016, 1024, 2244);
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 2U);
  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
                  "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for "
                  "Capstone\\MATLAB implementa"
                  "tion of imageTMO\\tvi.m",
                  3U, 1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 3U, 0U, "tvi", 0, -1, 850);
  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 3U, 0U, 318, -1, 846);
  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 3U);
}

void DCA_TMO_initialize(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2022b(&st);
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  emlrtLicenseCheckR2022a(&st, "EMLRT:runTime:MexFunctionNeedsLicense",
                          "image_toolbox", 2);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    DCA_TMO_once();
  }
}

/* End of code generation (DCA_TMO_initialize.c) */
