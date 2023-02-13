/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * DCA_TMO.c
 *
 * Code generation for function 'DCA_TMO'
 *
 */

/* Include files */
#include "DCA_TMO.h"
#include "DCA_TMO_data.h"
#include "DCA_TMO_emxutil.h"
#include "DCA_TMO_initialize.h"
#include "DCA_TMO_rtwutil.h"
#include "DCA_TMO_types.h"
#include "imfilter.h"
#include "interp1.h"
#include "ixfun.h"
#include "mean.h"
#include "median.h"
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "tvi.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Declarations */
static void binary_expand_op(emxArray_real_T *in1, const emxArray_real_T *in2);

static void c_binary_expand_op(emxArray_real_T *in1,
                               const emxArray_real_T *in2);

static void d_binary_expand_op(emxArray_real_T *in1, double in2, double in3,
                               double in4, const emxArray_real_T *in5);

static double rt_roundd_snf(double u);

/* Function Definitions */
static void binary_expand_op(emxArray_real_T *in1, const emxArray_real_T *in2)
{
  emxArray_real_T *b_in1;
  const double *in2_data;
  double *b_in1_data;
  double *in1_data;
  int aux_0_1;
  int aux_1_1;
  int i;
  int i1;
  int i2;
  int in2_idx_0;
  int in2_idx_1;
  int loop_ub;
  int stride_0_0;
  int stride_0_1;
  int stride_1_0;
  int stride_1_1;
  in2_data = in2->data;
  in1_data = in1->data;
  in2_idx_0 = in2->size[0];
  in2_idx_1 = in2->size[1];
  emxInit_real_T(&b_in1, 3);
  i = b_in1->size[0] * b_in1->size[1] * b_in1->size[2];
  if (in2_idx_0 == 1) {
    b_in1->size[0] = in1->size[0];
  } else {
    b_in1->size[0] = in2_idx_0;
  }
  if (in2_idx_1 == 1) {
    b_in1->size[1] = in1->size[1];
  } else {
    b_in1->size[1] = in2_idx_1;
  }
  b_in1->size[2] = 3;
  emxEnsureCapacity_real_T(b_in1, i);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_1 = (in1->size[1] != 1);
  stride_1_0 = (in2_idx_0 != 1);
  stride_1_1 = (in2_idx_1 != 1);
  if (in2_idx_1 == 1) {
    in2_idx_1 = in1->size[1];
  }
  for (i = 0; i < 3; i++) {
    aux_0_1 = 0;
    aux_1_1 = 0;
    for (i1 = 0; i1 < in2_idx_1; i1++) {
      if (in2_idx_0 == 1) {
        loop_ub = in1->size[0];
      } else {
        loop_ub = in2_idx_0;
      }
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_in1_data[(i2 + b_in1->size[0] * i1) +
                   b_in1->size[0] * b_in1->size[1] * i] =
            in1_data[(i2 * stride_0_0 + in1->size[0] * aux_0_1) +
                     in1->size[0] * in1->size[1] * i] *
            in2_data[i2 * stride_1_0 + in2_idx_0 * aux_1_1];
      }
      aux_1_1 += stride_1_1;
      aux_0_1 += stride_0_1;
    }
  }
  i = in1->size[0] * in1->size[1] * in1->size[2];
  in1->size[0] = b_in1->size[0];
  in1->size[1] = b_in1->size[1];
  in1->size[2] = 3;
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  in2_idx_1 = b_in1->size[1];
  for (i = 0; i < 3; i++) {
    for (i1 = 0; i1 < in2_idx_1; i1++) {
      loop_ub = b_in1->size[0];
      for (i2 = 0; i2 < loop_ub; i2++) {
        in1_data[(i2 + in1->size[0] * i1) + in1->size[0] * in1->size[1] * i] =
            b_in1_data[(i2 + b_in1->size[0] * i1) +
                       b_in1->size[0] * b_in1->size[1] * i];
      }
    }
  }
  emxFree_real_T(&b_in1);
}

static void c_binary_expand_op(emxArray_real_T *in1, const emxArray_real_T *in2)
{
  emxArray_real_T *b_in1;
  const double *in2_data;
  double *b_in1_data;
  double *in1_data;
  int aux_0_1;
  int aux_1_1;
  int b_loop_ub;
  int i;
  int i1;
  int loop_ub;
  int stride_0_0;
  int stride_0_1;
  int stride_1_0;
  int stride_1_1;
  in2_data = in2->data;
  in1_data = in1->data;
  emxInit_real_T(&b_in1, 2);
  i = b_in1->size[0] * b_in1->size[1];
  if (in2->size[0] == 1) {
    b_in1->size[0] = in1->size[0];
  } else {
    b_in1->size[0] = in2->size[0];
  }
  if (in2->size[1] == 1) {
    b_in1->size[1] = in1->size[1];
  } else {
    b_in1->size[1] = in2->size[1];
  }
  emxEnsureCapacity_real_T(b_in1, i);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_1 = (in1->size[1] != 1);
  stride_1_0 = (in2->size[0] != 1);
  stride_1_1 = (in2->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  if (in2->size[1] == 1) {
    loop_ub = in1->size[1];
  } else {
    loop_ub = in2->size[1];
  }
  for (i = 0; i < loop_ub; i++) {
    i1 = in2->size[0];
    if (i1 == 1) {
      b_loop_ub = in1->size[0];
    } else {
      b_loop_ub = i1;
    }
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_in1_data[i1 + b_in1->size[0] * i] =
          in1_data[i1 * stride_0_0 + in1->size[0] * aux_0_1] +
          3.0 * in2_data[i1 * stride_1_0 + in2->size[0] * aux_1_1];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = b_in1->size[0];
  in1->size[1] = b_in1->size[1];
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  loop_ub = b_in1->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = b_in1->size[0];
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] = b_in1_data[i1 + b_in1->size[0] * i];
    }
  }
  emxFree_real_T(&b_in1);
}

static void d_binary_expand_op(emxArray_real_T *in1, double in2, double in3,
                               double in4, const emxArray_real_T *in5)
{
  emxArray_real_T *r;
  const double *in5_data;
  double b_in3;
  double *in1_data;
  double *r1;
  int aux_0_1;
  int aux_1_1;
  int b_loop_ub;
  int i;
  int i1;
  int loop_ub;
  int stride_0_0;
  int stride_0_1;
  int stride_1_0;
  int stride_1_1;
  in5_data = in5->data;
  in1_data = in1->data;
  b_in3 = in3 - in4;
  emxInit_real_T(&r, 2);
  i = r->size[0] * r->size[1];
  if (in5->size[0] == 1) {
    r->size[0] = in1->size[0];
  } else {
    r->size[0] = in5->size[0];
  }
  if (in5->size[1] == 1) {
    r->size[1] = in1->size[1];
  } else {
    r->size[1] = in5->size[1];
  }
  emxEnsureCapacity_real_T(r, i);
  r1 = r->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_1 = (in1->size[1] != 1);
  stride_1_0 = (in5->size[0] != 1);
  stride_1_1 = (in5->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  if (in5->size[1] == 1) {
    loop_ub = in1->size[1];
  } else {
    loop_ub = in5->size[1];
  }
  for (i = 0; i < loop_ub; i++) {
    i1 = in5->size[0];
    if (i1 == 1) {
      b_loop_ub = in1->size[0];
    } else {
      b_loop_ub = i1;
    }
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      r1[i1 + r->size[0] * i] =
          (255.0 * (in1_data[i1 * stride_0_0 + in1->size[0] * aux_0_1] - in2) /
               b_in3 +
           1.0) *
              0.35 +
          in5_data[i1 * stride_1_0 + in5->size[0] * aux_1_1] * 0.65;
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = r->size[0];
  in1->size[1] = r->size[1];
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  loop_ub = r->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = r->size[0];
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] = r1[i1 + r->size[0] * i];
    }
  }
  emxFree_real_T(&r);
}

static double rt_roundd_snf(double u)
{
  double y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }
  return y;
}

void DCA_TMO(emxArray_real_T *hdrImg, emxArray_real_T *ldrImg)
{
  emxArray_boolean_T *ind;
  emxArray_int32_T *r;
  emxArray_int32_T *r2;
  emxArray_int32_T *r3;
  emxArray_int32_T *r4;
  emxArray_int32_T *r5;
  emxArray_int32_T *r6;
  emxArray_real_T b_hdrImg;
  emxArray_real_T *b_lum;
  emxArray_real_T *hdrLum;
  emxArray_real_T *hdrPQ;
  emxArray_real_T *l_hdrImg;
  emxArray_real_T *labels_DoG;
  emxArray_real_T *lum;
  emxArray_real_T *matrix;
  emxArray_real_T *s_data;
  emxArray_real_T *varargin_1;
  emxArray_real_T *y;
  double a__1[55];
  double e1;
  double e2;
  double m;
  double minn;
  double *hdrImg_data;
  double *hdrLum_data;
  double *hdrPQ_data;
  double *labels_DoG_data;
  double *lum_data;
  double *s_data_data;
  double *varargin_1_data;
  double *y_data;
  int edgesRes[3];
  int b_i;
  int c_hdrImg;
  unsigned int d;
  int d_hdrImg;
  int e_hdrImg;
  int exitg1;
  int f_hdrImg;
  int g_hdrImg;
  int h_hdrImg;
  int i;
  int i1;
  int i_hdrImg;
  int j_hdrImg;
  int k;
  int k_hdrImg;
  int last;
  int loop_ub;
  int m_hdrImg;
  int n;
  int n_hdrImg;
  int nx;
  int o_hdrImg;
  int p_hdrImg;
  unsigned int varargin_1_idx_1;
  int *r1;
  boolean_T exitg2;
  boolean_T *ind_data;
  if (!isInitialized_DCA_TMO) {
    DCA_TMO_initialize();
  }
  hdrImg_data = hdrImg->data;
  /*  set parameters */
  /*  pre-processing */
  /*  [N, M, C] = size(hdrImg); */
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
  emxInit_real_T(&matrix, 1);
  i = matrix->size[0];
  matrix->size[0] = hdrImg->size[0] * hdrImg->size[1] * 3;
  emxEnsureCapacity_real_T(matrix, i);
  s_data_data = matrix->data;
  loop_ub = hdrImg->size[0] * hdrImg->size[1] * 3;
  for (i = 0; i < loop_ub; i++) {
    s_data_data[i] = hdrImg_data[i];
  }
  sort(matrix);
  s_data_data = matrix->data;
  i = (int)rt_roundd_snf((double)(hdrImg->size[0] * hdrImg->size[1] * 3) *
                         0.99);
  if (i < 1) {
    i = 1;
  }
  e2 = s_data_data[i - 1];
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
  i = matrix->size[0];
  matrix->size[0] = hdrImg->size[0] * hdrImg->size[1] * 3;
  emxEnsureCapacity_real_T(matrix, i);
  s_data_data = matrix->data;
  loop_ub = hdrImg->size[0] * hdrImg->size[1] * 3;
  for (i = 0; i < loop_ub; i++) {
    s_data_data[i] = hdrImg_data[i];
  }
  sort(matrix);
  s_data_data = matrix->data;
  i = (int)rt_roundd_snf((double)(hdrImg->size[0] * hdrImg->size[1] * 3) *
                         0.01);
  if (i < 1) {
    i = 1;
  }
  minn = s_data_data[i - 1];
  last = hdrImg->size[0] * (hdrImg->size[1] * 3) - 1;
  nx = 0;
  for (b_i = 0; b_i <= last; b_i++) {
    if (hdrImg_data[b_i] > e2) {
      nx++;
    }
  }
  emxInit_int32_T(&r, 1);
  i = r->size[0];
  r->size[0] = nx;
  emxEnsureCapacity_int32_T(r, i);
  r1 = r->data;
  nx = 0;
  for (b_i = 0; b_i <= last; b_i++) {
    if (hdrImg_data[b_i] > e2) {
      r1[nx] = b_i + 1;
      nx++;
    }
  }
  loop_ub = r->size[0];
  for (i = 0; i < loop_ub; i++) {
    hdrImg_data[r1[i] - 1] = e2;
  }
  emxFree_int32_T(&r);
  last = hdrImg->size[0] * (hdrImg->size[1] * 3) - 1;
  nx = 0;
  for (b_i = 0; b_i <= last; b_i++) {
    if (hdrImg_data[b_i] < minn) {
      nx++;
    }
  }
  emxInit_int32_T(&r2, 1);
  i = r2->size[0];
  r2->size[0] = nx;
  emxEnsureCapacity_int32_T(r2, i);
  r1 = r2->data;
  nx = 0;
  for (b_i = 0; b_i <= last; b_i++) {
    if (hdrImg_data[b_i] < minn) {
      r1[nx] = b_i + 1;
      nx++;
    }
  }
  loop_ub = r2->size[0];
  for (i = 0; i < loop_ub; i++) {
    hdrImg_data[r1[i] - 1] = minn;
  }
  emxFree_int32_T(&r2);
  /*  tone map using clustering method */
  emxInit_real_T(&hdrLum, 2);
  i = hdrLum->size[0] * hdrLum->size[1];
  hdrLum->size[0] = hdrImg->size[0];
  hdrLum->size[1] = hdrImg->size[1];
  emxEnsureCapacity_real_T(hdrLum, i);
  hdrLum_data = hdrLum->data;
  loop_ub = hdrImg->size[1];
  for (i = 0; i < loop_ub; i++) {
    nx = hdrImg->size[0];
    for (k = 0; k < nx; k++) {
      hdrLum_data[k + hdrLum->size[0] * i] =
          (0.2126 * hdrImg_data[k + hdrImg->size[0] * i] +
           0.7152 * hdrImg_data[(k + hdrImg->size[0] * i) +
                                hdrImg->size[0] * hdrImg->size[1]]) +
          0.0722 * hdrImg_data[(k + hdrImg->size[0] * i) +
                               hdrImg->size[0] * hdrImg->size[1] * 2];
    }
  }
  nx = hdrImg->size[0] * hdrImg->size[1] * 3;
  b_hdrImg = *hdrImg;
  c_hdrImg = nx;
  b_hdrImg.size = &c_hdrImg;
  b_hdrImg.numDimensions = 1;
  m = maximum(&b_hdrImg);
  emxInit_real_T(&hdrPQ, 2);
  i = hdrPQ->size[0] * hdrPQ->size[1];
  hdrPQ->size[0] = hdrLum->size[0];
  hdrPQ->size[1] = hdrLum->size[1];
  emxEnsureCapacity_real_T(hdrPQ, i);
  hdrPQ_data = hdrPQ->data;
  loop_ub = hdrLum->size[0] * hdrLum->size[1];
  for (i = 0; i < loop_ub; i++) {
    e2 = hdrLum_data[i] / m;
    hdrPQ_data[i] = rt_powd_snf(e2, 0.1593017578125);
  }
  loop_ub = hdrPQ->size[0] * hdrPQ->size[1];
  for (i = 0; i < loop_ub; i++) {
    e2 = (18.8515625 * hdrPQ_data[i] + 0.8359375) /
         (18.6875 * hdrPQ_data[i] + 1.0);
    hdrPQ_data[i] = rt_powd_snf(e2, 78.84375);
  }
  /*  y is input data */
  /*  nclust is the number of clusters or quantization levels. If you want to */
  /*  quantize data with b bits then nclust <= 2^b (256 if b=8) */
  /*  labels are the quantization intervals in [1, nclust] range assigned to y
   */
  /*  mdata is the mean value of each cluster */
  emxInit_real_T(&lum, 2);
  i = lum->size[0] * lum->size[1];
  lum->size[0] = 1;
  lum->size[1] = hdrLum->size[0] * hdrLum->size[1];
  emxEnsureCapacity_real_T(lum, i);
  lum_data = lum->data;
  loop_ub = hdrLum->size[0] * hdrLum->size[1];
  for (i = 0; i < loop_ub; i++) {
    lum_data[i] = hdrLum_data[i];
  }
  b_sort(lum);
  lum_data = lum->data;
  emxInit_real_T(&y, 2);
  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = hdrPQ->size[0] * hdrPQ->size[1];
  emxEnsureCapacity_real_T(y, i);
  y_data = y->data;
  loop_ub = hdrPQ->size[0] * hdrPQ->size[1];
  for (i = 0; i < loop_ub; i++) {
    y_data[i] = hdrPQ_data[i];
  }
  b_sort(y);
  y_data = y->data;
  varargin_1_idx_1 = (unsigned int)y->size[1];
  emxInit_real_T(&s_data, 2);
  i = s_data->size[0] * s_data->size[1];
  s_data->size[0] = 1;
  s_data->size[1] = y->size[1];
  emxEnsureCapacity_real_T(s_data, i);
  s_data_data = s_data->data;
  loop_ub = y->size[1];
  for (i = 0; i < loop_ub; i++) {
    s_data_data[i] = y_data[i];
  }
  if ((y->size[1] != 0) && (y->size[1] != 1)) {
    i = y->size[1];
    for (k = 0; k <= i - 2; k++) {
      s_data_data[k + 1] += s_data_data[k];
    }
  }
  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  emxEnsureCapacity_real_T(y, i);
  y_data = y->data;
  loop_ub = y->size[1] - 1;
  for (i = 0; i <= loop_ub; i++) {
    e2 = y_data[i];
    y_data[i] = e2 * e2;
  }
  if ((y->size[1] != 0) && (y->size[1] != 1)) {
    i = y->size[1];
    for (k = 0; k <= i - 2; k++) {
      y_data[k + 1] += y_data[k];
    }
  }
  n = y->size[1];
  loop_ub = y->size[1];
  edgesRes[0] = 0;
  edgesRes[2] = y->size[1];
  emxInit_real_T(&varargin_1, 2);
  emxInit_real_T(&b_lum, 2);
  for (b_i = 0; b_i < 54; b_i++) {
    d = 2U;
    m = floor((double)varargin_1_idx_1 / 2.0);
    do {
      exitg1 = 0;
      minn = s_data_data[(int)m - 1];
      e2 = y_data[(int)m - 1];
      e1 = e2 - minn * minn / m;
      minn = s_data_data[n - 1] - minn;
      e2 = (y_data[n - 1] - e2) - minn * minn / ((double)n - m);
      d <<= 1;
      if ((fabs(e1 - e2) < 0.001) || (d >= (unsigned int)n)) {
        exitg1 = 1;
      } else if (e1 > e2) {
        m -= floor((double)n / (double)d);
      } else if (e1 < e2) {
        m += floor((double)n / (double)d);
      }
    } while (exitg1 == 0);
    if ((unsigned int)m + 1U > varargin_1_idx_1) {
      i = 0;
      k = 0;
    } else {
      i = (int)(unsigned int)m;
      k = (int)varargin_1_idx_1;
    }
    i1 = b_lum->size[0] * b_lum->size[1];
    b_lum->size[0] = 1;
    b_lum->size[1] = (int)m;
    emxEnsureCapacity_real_T(b_lum, i1);
    labels_DoG_data = b_lum->data;
    nx = (int)m;
    for (i1 = 0; i1 < nx; i1++) {
      labels_DoG_data[i1] = lum_data[i1];
    }
    e2 = rt_powd_snf(10.0, tvi(log10(median(b_lum))));
    i1 = b_lum->size[0] * b_lum->size[1];
    b_lum->size[0] = 1;
    nx = k - i;
    b_lum->size[1] = nx;
    emxEnsureCapacity_real_T(b_lum, i1);
    labels_DoG_data = b_lum->data;
    for (k = 0; k < nx; k++) {
      labels_DoG_data[k] = lum_data[i + k];
    }
    e2 = e2 / (e2 + rt_powd_snf(10.0, tvi(log10(median(b_lum))))) *
             (lum_data[(int)varargin_1_idx_1 - 1] - lum_data[0]) +
         lum_data[0];
    i = b_lum->size[0] * b_lum->size[1];
    b_lum->size[0] = 1;
    b_lum->size[1] = loop_ub;
    emxEnsureCapacity_real_T(b_lum, i);
    labels_DoG_data = b_lum->data;
    for (i = 0; i < loop_ub; i++) {
      labels_DoG_data[i] = e2 - lum_data[i];
    }
    nx = b_lum->size[1];
    i = varargin_1->size[0] * varargin_1->size[1];
    varargin_1->size[0] = 1;
    varargin_1->size[1] = b_lum->size[1];
    emxEnsureCapacity_real_T(varargin_1, i);
    varargin_1_data = varargin_1->data;
    for (k = 0; k < nx; k++) {
      varargin_1_data[k] = fabs(labels_DoG_data[k]);
    }
    last = varargin_1->size[1];
    if (varargin_1->size[1] <= 2) {
      if (varargin_1->size[1] == 1) {
        nx = 1;
      } else if ((varargin_1_data[0] >
                  varargin_1_data[varargin_1->size[1] - 1]) ||
                 (rtIsNaN(varargin_1_data[0]) &&
                  (!rtIsNaN(varargin_1_data[varargin_1->size[1] - 1])))) {
        nx = varargin_1->size[1];
      } else {
        nx = 1;
      }
    } else {
      if (!rtIsNaN(varargin_1_data[0])) {
        nx = 1;
      } else {
        nx = 0;
        k = 2;
        exitg2 = false;
        while ((!exitg2) && (k <= last)) {
          if (!rtIsNaN(varargin_1_data[k - 1])) {
            nx = k;
            exitg2 = true;
          } else {
            k++;
          }
        }
      }
      if (nx == 0) {
        nx = 1;
      } else {
        e2 = varargin_1_data[nx - 1];
        i = nx + 1;
        for (k = i; k <= last; k++) {
          minn = varargin_1_data[k - 1];
          if (e2 > minn) {
            e2 = minn;
            nx = k;
          }
        }
      }
    }
    edgesRes[1] = nx;
  }
  emxFree_real_T(&b_lum);
  emxFree_real_T(&varargin_1);
  emxFree_real_T(&y);
  emxFree_real_T(&s_data);
  memset(&a__1[0], 0, 55U * sizeof(double));
  nx = hdrLum->size[0] * hdrLum->size[1];
  b_hdrImg = *hdrLum;
  d_hdrImg = nx;
  b_hdrImg.size = &d_hdrImg;
  b_hdrImg.numDimensions = 1;
  a__1[0] = minimum(&b_hdrImg);
  nx = hdrLum->size[0] * hdrLum->size[1];
  b_hdrImg = *hdrLum;
  e_hdrImg = nx;
  b_hdrImg.size = &e_hdrImg;
  b_hdrImg.numDimensions = 1;
  a__1[54] = maximum(&b_hdrImg);
  emxInit_boolean_T(&ind);
  emxInit_int32_T(&r3, 1);
  emxInit_int32_T(&r4, 1);
  for (b_i = 0; b_i < 53; b_i++) {
    e2 = lum_data[edgesRes[b_i + 1] - 1];
    minn = lum_data[edgesRes[2] - 1];
    if (e2 == minn) {
      i = ind->size[0] * ind->size[1];
      ind->size[0] = hdrLum->size[0];
      ind->size[1] = hdrLum->size[1];
      emxEnsureCapacity_boolean_T(ind, i);
      ind_data = ind->data;
      loop_ub = hdrLum->size[0] * hdrLum->size[1];
      for (i = 0; i < loop_ub; i++) {
        ind_data[i] = (hdrLum_data[i] == e2);
      }
      last = ind->size[0] * ind->size[1] - 1;
      nx = 0;
      for (n = 0; n <= last; n++) {
        if (ind_data[n]) {
          nx++;
        }
      }
      i = r3->size[0];
      r3->size[0] = nx;
      emxEnsureCapacity_int32_T(r3, i);
      r1 = r3->data;
      nx = 0;
      for (n = 0; n <= last; n++) {
        if (ind_data[n]) {
          r1[nx] = n + 1;
          nx++;
        }
      }
      loop_ub = r3->size[0];
      i = matrix->size[0];
      matrix->size[0] = r3->size[0];
      emxEnsureCapacity_real_T(matrix, i);
      s_data_data = matrix->data;
      for (i = 0; i < loop_ub; i++) {
        s_data_data[i] = hdrLum_data[r1[i] - 1];
      }
      a__1[b_i + 1] =
          mean(matrix) + 2.2204460492503131E-16 * ((double)b_i + 2.0);
    } else {
      i = ind->size[0] * ind->size[1];
      ind->size[0] = hdrLum->size[0];
      ind->size[1] = hdrLum->size[1];
      emxEnsureCapacity_boolean_T(ind, i);
      ind_data = ind->data;
      loop_ub = hdrLum->size[0] * hdrLum->size[1];
      for (i = 0; i < loop_ub; i++) {
        ind_data[i] = ((hdrLum_data[i] > e2) && (hdrLum_data[i] <= minn));
      }
      last = ind->size[0] * ind->size[1] - 1;
      nx = 0;
      for (n = 0; n <= last; n++) {
        if (ind_data[n]) {
          nx++;
        }
      }
      i = r4->size[0];
      r4->size[0] = nx;
      emxEnsureCapacity_int32_T(r4, i);
      r1 = r4->data;
      nx = 0;
      for (n = 0; n <= last; n++) {
        if (ind_data[n]) {
          r1[nx] = n + 1;
          nx++;
        }
      }
      loop_ub = r4->size[0];
      i = matrix->size[0];
      matrix->size[0] = r4->size[0];
      emxEnsureCapacity_real_T(matrix, i);
      s_data_data = matrix->data;
      for (i = 0; i < loop_ub; i++) {
        s_data_data[i] = hdrLum_data[r1[i] - 1];
      }
      a__1[b_i + 1] = mean(matrix);
    }
  }
  emxFree_int32_T(&r4);
  emxFree_int32_T(&r3);
  emxFree_real_T(&lum);
  emxFree_boolean_T(&ind);
  emxInit_real_T(&labels_DoG, 2);
  interp1(a__1, hdrLum, labels_DoG);
  labels_DoG_data = labels_DoG->data;
  /*  local enhancemant using DoG */
  nx = hdrPQ->size[0] * hdrPQ->size[1];
  b_hdrImg = *hdrPQ;
  f_hdrImg = nx;
  b_hdrImg.size = &f_hdrImg;
  b_hdrImg.numDimensions = 1;
  minn = minimum(&b_hdrImg);
  nx = hdrPQ->size[0] * hdrPQ->size[1];
  b_hdrImg = *hdrPQ;
  g_hdrImg = nx;
  b_hdrImg.size = &g_hdrImg;
  b_hdrImg.numDimensions = 1;
  m = maximum(&b_hdrImg);
  nx = hdrPQ->size[0] * hdrPQ->size[1];
  b_hdrImg = *hdrPQ;
  h_hdrImg = nx;
  b_hdrImg.size = &h_hdrImg;
  b_hdrImg.numDimensions = 1;
  e2 = minimum(&b_hdrImg);
  if ((hdrPQ->size[0] == labels_DoG->size[0]) &&
      (hdrPQ->size[1] == labels_DoG->size[1])) {
    m -= e2;
    loop_ub = hdrPQ->size[0] * hdrPQ->size[1];
    for (i = 0; i < loop_ub; i++) {
      hdrPQ_data[i] = (255.0 * (hdrPQ_data[i] - minn) / m + 1.0) * 0.35 +
                      labels_DoG_data[i] * 0.65;
    }
  } else {
    d_binary_expand_op(hdrPQ, minn, m, e2, labels_DoG);
  }
  imfilter(hdrPQ);
  hdrPQ_data = hdrPQ->data;
  if ((labels_DoG->size[0] == hdrPQ->size[0]) &&
      (labels_DoG->size[1] == hdrPQ->size[1])) {
    loop_ub = labels_DoG->size[0] * labels_DoG->size[1];
    for (i = 0; i < loop_ub; i++) {
      labels_DoG_data[i] += 3.0 * hdrPQ_data[i];
    }
  } else {
    c_binary_expand_op(labels_DoG, hdrPQ);
    labels_DoG_data = labels_DoG->data;
  }
  /*  color restoration */
  nx = labels_DoG->size[0] * labels_DoG->size[1];
  b_hdrImg = *labels_DoG;
  i_hdrImg = nx;
  b_hdrImg.size = &i_hdrImg;
  b_hdrImg.numDimensions = 1;
  minn = minimum(&b_hdrImg);
  nx = labels_DoG->size[0] * labels_DoG->size[1];
  b_hdrImg = *labels_DoG;
  j_hdrImg = nx;
  b_hdrImg.size = &j_hdrImg;
  b_hdrImg.numDimensions = 1;
  m = maximum(&b_hdrImg);
  nx = labels_DoG->size[0] * labels_DoG->size[1];
  i = hdrPQ->size[0] * hdrPQ->size[1];
  hdrPQ->size[0] = labels_DoG->size[0];
  hdrPQ->size[1] = labels_DoG->size[1];
  emxEnsureCapacity_real_T(hdrPQ, i);
  hdrPQ_data = hdrPQ->data;
  b_hdrImg = *labels_DoG;
  k_hdrImg = nx;
  b_hdrImg.size = &k_hdrImg;
  b_hdrImg.numDimensions = 1;
  m -= minimum(&b_hdrImg);
  loop_ub = labels_DoG->size[0] * labels_DoG->size[1];
  for (i = 0; i < loop_ub; i++) {
    hdrPQ_data[i] = (labels_DoG_data[i] - minn) / m;
  }
  nx = hdrPQ->size[0] * hdrPQ->size[1];
  for (k = 0; k < nx; k++) {
    hdrPQ_data[k] = atan(hdrPQ_data[k]);
  }
  loop_ub = hdrPQ->size[0] * hdrPQ->size[1];
  for (i = 0; i < loop_ub; i++) {
    e2 = 1.0 - hdrPQ_data[i];
    if (e2 <= 0.5) {
      hdrPQ_data[i] = e2;
    } else {
      hdrPQ_data[i] = 0.5;
    }
  }
  emxInit_real_T(&l_hdrImg, 3);
  if ((hdrImg->size[0] == hdrLum->size[0]) &&
      (hdrImg->size[1] == hdrLum->size[1])) {
    last = hdrLum->size[0];
    i = l_hdrImg->size[0] * l_hdrImg->size[1] * l_hdrImg->size[2];
    l_hdrImg->size[0] = hdrImg->size[0];
    l_hdrImg->size[1] = hdrImg->size[1];
    l_hdrImg->size[2] = 3;
    emxEnsureCapacity_real_T(l_hdrImg, i);
    s_data_data = l_hdrImg->data;
    loop_ub = hdrImg->size[1];
    for (i = 0; i < 3; i++) {
      for (k = 0; k < loop_ub; k++) {
        nx = hdrImg->size[0];
        for (i1 = 0; i1 < nx; i1++) {
          s_data_data[(i1 + l_hdrImg->size[0] * k) +
                      l_hdrImg->size[0] * l_hdrImg->size[1] * i] =
              hdrImg_data[(i1 + hdrImg->size[0] * k) +
                          hdrImg->size[0] * hdrImg->size[1] * i] /
              hdrLum_data[i1 + last * k];
        }
      }
    }
    expand_power(l_hdrImg, hdrPQ, ldrImg);
    y_data = ldrImg->data;
  } else {
    b_binary_expand_op(ldrImg, hdrImg, hdrLum, hdrPQ);
    y_data = ldrImg->data;
  }
  emxFree_real_T(&hdrPQ);
  emxFree_real_T(&hdrLum);
  if ((ldrImg->size[0] == labels_DoG->size[0]) &&
      (ldrImg->size[1] == labels_DoG->size[1])) {
    last = labels_DoG->size[0];
    i = l_hdrImg->size[0] * l_hdrImg->size[1] * l_hdrImg->size[2];
    l_hdrImg->size[0] = ldrImg->size[0];
    l_hdrImg->size[1] = ldrImg->size[1];
    l_hdrImg->size[2] = 3;
    emxEnsureCapacity_real_T(l_hdrImg, i);
    s_data_data = l_hdrImg->data;
    loop_ub = ldrImg->size[1];
    for (i = 0; i < 3; i++) {
      for (k = 0; k < loop_ub; k++) {
        nx = ldrImg->size[0];
        for (i1 = 0; i1 < nx; i1++) {
          s_data_data[(i1 + l_hdrImg->size[0] * k) +
                      l_hdrImg->size[0] * l_hdrImg->size[1] * i] =
              y_data[(i1 + ldrImg->size[0] * k) +
                     ldrImg->size[0] * ldrImg->size[1] * i] *
              labels_DoG_data[i1 + last * k];
        }
      }
    }
    i = ldrImg->size[0] * ldrImg->size[1] * ldrImg->size[2];
    ldrImg->size[0] = l_hdrImg->size[0];
    ldrImg->size[1] = l_hdrImg->size[1];
    ldrImg->size[2] = 3;
    emxEnsureCapacity_real_T(ldrImg, i);
    y_data = ldrImg->data;
    loop_ub = l_hdrImg->size[0] * l_hdrImg->size[1] * 3;
    for (i = 0; i < loop_ub; i++) {
      y_data[i] = s_data_data[i];
    }
  } else {
    binary_expand_op(ldrImg, labels_DoG);
    y_data = ldrImg->data;
  }
  emxFree_real_T(&l_hdrImg);
  emxFree_real_T(&labels_DoG);
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
  i = matrix->size[0];
  matrix->size[0] = ldrImg->size[0] * ldrImg->size[1] * 3;
  emxEnsureCapacity_real_T(matrix, i);
  s_data_data = matrix->data;
  loop_ub = ldrImg->size[0] * ldrImg->size[1] * 3;
  for (i = 0; i < loop_ub; i++) {
    s_data_data[i] = y_data[i];
  }
  sort(matrix);
  s_data_data = matrix->data;
  i = (int)rt_roundd_snf((double)(ldrImg->size[0] * ldrImg->size[1] * 3) *
                         0.99);
  if (i < 1) {
    i = 1;
  }
  e2 = s_data_data[i - 1];
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
  i = matrix->size[0];
  matrix->size[0] = ldrImg->size[0] * ldrImg->size[1] * 3;
  emxEnsureCapacity_real_T(matrix, i);
  s_data_data = matrix->data;
  loop_ub = ldrImg->size[0] * ldrImg->size[1] * 3;
  for (i = 0; i < loop_ub; i++) {
    s_data_data[i] = y_data[i];
  }
  sort(matrix);
  s_data_data = matrix->data;
  i = (int)rt_roundd_snf((double)(ldrImg->size[0] * ldrImg->size[1] * 3) *
                         0.01);
  if (i < 1) {
    i = 1;
  }
  minn = s_data_data[i - 1];
  emxFree_real_T(&matrix);
  if (e2 < 255.0) {
    nx = ldrImg->size[0] * ldrImg->size[1] * 3;
    b_hdrImg = *ldrImg;
    m_hdrImg = nx;
    b_hdrImg.size = &m_hdrImg;
    b_hdrImg.numDimensions = 1;
    if (maximum(&b_hdrImg) < 255.0) {
      nx = ldrImg->size[0] * ldrImg->size[1] * 3;
      b_hdrImg = *ldrImg;
      o_hdrImg = nx;
      b_hdrImg.size = &o_hdrImg;
      b_hdrImg.numDimensions = 1;
      e2 = maximum(&b_hdrImg);
    } else {
      e2 = 255.0;
    }
  }
  if (minn > 0.0) {
    nx = ldrImg->size[0] * ldrImg->size[1] * 3;
    b_hdrImg = *ldrImg;
    n_hdrImg = nx;
    b_hdrImg.size = &n_hdrImg;
    b_hdrImg.numDimensions = 1;
    if (minimum(&b_hdrImg) > 0.0) {
      nx = ldrImg->size[0] * ldrImg->size[1] * 3;
      b_hdrImg = *ldrImg;
      p_hdrImg = nx;
      b_hdrImg.size = &p_hdrImg;
      b_hdrImg.numDimensions = 1;
      minn = minimum(&b_hdrImg);
    } else {
      minn = 0.0;
    }
  }
  last = ldrImg->size[0] * (ldrImg->size[1] * 3) - 1;
  nx = 0;
  for (b_i = 0; b_i <= last; b_i++) {
    if (y_data[b_i] > e2) {
      nx++;
    }
  }
  emxInit_int32_T(&r5, 1);
  i = r5->size[0];
  r5->size[0] = nx;
  emxEnsureCapacity_int32_T(r5, i);
  r1 = r5->data;
  nx = 0;
  for (b_i = 0; b_i <= last; b_i++) {
    if (y_data[b_i] > e2) {
      r1[nx] = b_i + 1;
      nx++;
    }
  }
  loop_ub = r5->size[0];
  for (i = 0; i < loop_ub; i++) {
    y_data[r1[i] - 1] = e2;
  }
  emxFree_int32_T(&r5);
  last = ldrImg->size[0] * (ldrImg->size[1] * 3) - 1;
  nx = 0;
  for (b_i = 0; b_i <= last; b_i++) {
    if (y_data[b_i] < minn) {
      nx++;
    }
  }
  emxInit_int32_T(&r6, 1);
  i = r6->size[0];
  r6->size[0] = nx;
  emxEnsureCapacity_int32_T(r6, i);
  r1 = r6->data;
  nx = 0;
  for (b_i = 0; b_i <= last; b_i++) {
    if (y_data[b_i] < minn) {
      r1[nx] = b_i + 1;
      nx++;
    }
  }
  loop_ub = r6->size[0];
  for (i = 0; i < loop_ub; i++) {
    y_data[r1[i] - 1] = minn;
  }
  emxFree_int32_T(&r6);
  loop_ub = ldrImg->size[0] * ldrImg->size[1] * 3;
  i = ldrImg->size[0] * ldrImg->size[1] * ldrImg->size[2];
  ldrImg->size[2] = 3;
  emxEnsureCapacity_real_T(ldrImg, i);
  y_data = ldrImg->data;
  e2 -= minn;
  for (i = 0; i < loop_ub; i++) {
    y_data[i] = 255.0 * ((y_data[i] - minn) / e2);
  }
}

/* End of code generation (DCA_TMO.c) */
