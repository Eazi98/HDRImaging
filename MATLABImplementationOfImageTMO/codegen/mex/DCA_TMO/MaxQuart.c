/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * MaxQuart.c
 *
 * Code generation for function 'MaxQuart'
 *
 */

/* Include files */
#include "MaxQuart.h"
#include "DCA_TMO_data.h"
#include "DCA_TMO_types.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo q_emlrtRSI = {
    40,         /* lineNo */
    "MaxQuart", /* fcnName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\MaxQuart.m" /* pathName */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    43,         /* lineNo */
    14,         /* colNo */
    "matrix",   /* aName */
    "MaxQuart", /* fName */
    "C:\\Users\\xuezh\\OneDrive - Singapore Institute Of "
    "Technology\\Desktop\\Y3 Trimester 1\\Capstone\\Files for Capstone\\MATLAB "
    "implementa"
    "tion of imageTMO\\MaxQuart.m", /* pName */
    0                               /* checkKind */
};

/* Function Definitions */
real_T MaxQuart(const emlrtStack *sp, emxArray_real_T *matrix)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T *matrix_data;
  int32_T n;
  int32_T nx;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  covrtLogFcn(&emlrtCoverageInstance, 1U, 0U);
  /*  */
  /*        ret = MaxQuart(matrix, percentile) */
  /*  */
  /*        Input: */
  /*            -matrix: a matrix */
  /*            -percentile: a value in the range [0,1] */
  /*  */
  /*        Output: */
  /*            -ret: the percentile of the input matrix */
  /*  */
  /*      Copyright (C) 2011-2015  Francesco Banterle */
  /*   */
  /*      This program is free software: you can redistribute it and/or modify
   */
  /*      it under the terms of the GNU General Public License as published by
   */
  /*      the Free Software Foundation, either version 3 of the License, or */
  /*      (at your option) any later version. */
  /*   */
  /*      This program is distributed in the hope that it will be useful, */
  /*      but WITHOUT ANY WARRANTY; without even the implied warranty of */
  /*      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
  /*      GNU General Public License for more details. */
  /*   */
  /*      You should have received a copy of the GNU General Public License */
  /*      along with this program.  If not, see <http://www.gnu.org/licenses/>.
   */
  /*  */
  covrtLogIf(&emlrtCoverageInstance, 1U, 0U, 0, false);
  covrtLogIf(&emlrtCoverageInstance, 1U, 0U, 1, false);
  covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 2U);
  st.site = &q_emlrtRSI;
  nx = matrix->size[0];
  n = matrix->size[0];
  if (matrix->size[0] < 1) {
    n = 1;
  }
  if (matrix->size[0] > muIntScalarMax_sint32(nx, n)) {
    emlrtErrorWithMessageIdR2018a(&st, &d_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  st.site = &q_emlrtRSI;
  b_st.site = &t_emlrtRSI;
  sort(&b_st, matrix);
  matrix_data = matrix->data;
  nx = (int32_T)muDoubleScalarRound((real_T)matrix->size[0] * 0.99);
  if (nx < 1) {
    nx = 1;
  }
  if ((nx < 1) || (nx > matrix->size[0])) {
    emlrtDynamicBoundsCheckR2012b(nx, 1, matrix->size[0], &e_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  return matrix_data[nx - 1];
}

real_T b_MaxQuart(const emlrtStack *sp, emxArray_real_T *matrix)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T *matrix_data;
  int32_T n;
  int32_T nx;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  covrtLogFcn(&emlrtCoverageInstance, 1U, 0U);
  /*  */
  /*        ret = MaxQuart(matrix, percentile) */
  /*  */
  /*        Input: */
  /*            -matrix: a matrix */
  /*            -percentile: a value in the range [0,1] */
  /*  */
  /*        Output: */
  /*            -ret: the percentile of the input matrix */
  /*  */
  /*      Copyright (C) 2011-2015  Francesco Banterle */
  /*   */
  /*      This program is free software: you can redistribute it and/or modify
   */
  /*      it under the terms of the GNU General Public License as published by
   */
  /*      the Free Software Foundation, either version 3 of the License, or */
  /*      (at your option) any later version. */
  /*   */
  /*      This program is distributed in the hope that it will be useful, */
  /*      but WITHOUT ANY WARRANTY; without even the implied warranty of */
  /*      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
  /*      GNU General Public License for more details. */
  /*   */
  /*      You should have received a copy of the GNU General Public License */
  /*      along with this program.  If not, see <http://www.gnu.org/licenses/>.
   */
  /*  */
  covrtLogIf(&emlrtCoverageInstance, 1U, 0U, 0, false);
  covrtLogIf(&emlrtCoverageInstance, 1U, 0U, 1, false);
  covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 2U);
  st.site = &q_emlrtRSI;
  nx = matrix->size[0];
  n = matrix->size[0];
  if (matrix->size[0] < 1) {
    n = 1;
  }
  if (matrix->size[0] > muIntScalarMax_sint32(nx, n)) {
    emlrtErrorWithMessageIdR2018a(&st, &d_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  st.site = &q_emlrtRSI;
  b_st.site = &t_emlrtRSI;
  sort(&b_st, matrix);
  matrix_data = matrix->data;
  nx = (int32_T)muDoubleScalarRound((real_T)matrix->size[0] * 0.01);
  if (nx < 1) {
    nx = 1;
  }
  if ((nx < 1) || (nx > matrix->size[0])) {
    emlrtDynamicBoundsCheckR2012b(nx, 1, matrix->size[0], &e_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  return matrix_data[nx - 1];
}

/* End of code generation (MaxQuart.c) */
