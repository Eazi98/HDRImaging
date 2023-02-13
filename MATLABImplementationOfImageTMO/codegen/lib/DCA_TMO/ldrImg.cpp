//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ldrImg.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 17-Jan-2023 23:47:54
//

// Include Files
#include "ldrImg.h"
#include "DCA_TMO_data.h"
#include "DCA_TMO_rtwutil.h"
#include "combineVectorElements.h"
#include "imfilter.h"
#include "interp1.h"
#include "ixfun.h"
#include "mean.h"
#include "median.h"
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "tvi.h"
#include "coder_array.h"
#include "omp.h"
#include <cmath>
#include <cstring>

// Function Declarations
static void binary_expand_op(coder::array<real_T, 2U> &in1, real_T in2,
                             real_T in3, real_T in4,
                             const coder::array<real_T, 2U> &in5);

static void binary_expand_op(coder::array<real_T, 2U> &in1,
                             const coder::array<real_T, 2U> &in2);

static void binary_expand_op(coder::array<real_T, 3U> &in1,
                             const coder::array<real_T, 2U> &in2);

// Function Definitions
//
// Arguments    : coder::array<real_T, 2U> &in1
//                real_T in2
//                real_T in3
//                real_T in4
//                const coder::array<real_T, 2U> &in5
// Return Type  : void
//
static void binary_expand_op(coder::array<real_T, 2U> &in1, real_T in2,
                             real_T in3, real_T in4,
                             const coder::array<real_T, 2U> &in5)
{
  coder::array<real_T, 2U> r;
  real_T b_in3;
  int32_T aux_0_1;
  int32_T aux_1_1;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_1;
  int32_T stride_1_0;
  int32_T stride_1_1;
  b_in3 = in3 - in4;
  if (in5.size(0) == 1) {
    i = in1.size(0);
  } else {
    i = in5.size(0);
  }
  if (in5.size(1) == 1) {
    i1 = in1.size(1);
  } else {
    i1 = in5.size(1);
  }
  r.set_size(i, i1);
  stride_0_0 = (in1.size(0) != 1);
  stride_0_1 = (in1.size(1) != 1);
  stride_1_0 = (in5.size(0) != 1);
  stride_1_1 = (in5.size(1) != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  if (in5.size(1) == 1) {
    loop_ub = in1.size(1);
  } else {
    loop_ub = in5.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    i1 = in5.size(0);
    if (i1 == 1) {
      b_loop_ub = in1.size(0);
    } else {
      b_loop_ub = i1;
    }
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      r[i1 + r.size(0) * i] =
          (255.0 * (in1[i1 * stride_0_0 + in1.size(0) * aux_0_1] - in2) /
               b_in3 +
           1.0) *
              0.35 +
          in5[i1 * stride_1_0 + in5.size(0) * aux_1_1] * 0.65;
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  in1.set_size(r.size(0), r.size(1));
  loop_ub = r.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = r.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      in1[i1 + in1.size(0) * i] = r[i1 + r.size(0) * i];
    }
  }
}

//
// Arguments    : coder::array<real_T, 2U> &in1
//                const coder::array<real_T, 2U> &in2
// Return Type  : void
//
static void binary_expand_op(coder::array<real_T, 2U> &in1,
                             const coder::array<real_T, 2U> &in2)
{
  coder::array<real_T, 2U> b_in1;
  int32_T aux_0_1;
  int32_T aux_1_1;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_1;
  int32_T stride_1_0;
  int32_T stride_1_1;
  if (in2.size(0) == 1) {
    i = in1.size(0);
  } else {
    i = in2.size(0);
  }
  if (in2.size(1) == 1) {
    i1 = in1.size(1);
  } else {
    i1 = in2.size(1);
  }
  b_in1.set_size(i, i1);
  stride_0_0 = (in1.size(0) != 1);
  stride_0_1 = (in1.size(1) != 1);
  stride_1_0 = (in2.size(0) != 1);
  stride_1_1 = (in2.size(1) != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  if (in2.size(1) == 1) {
    loop_ub = in1.size(1);
  } else {
    loop_ub = in2.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    i1 = in2.size(0);
    if (i1 == 1) {
      b_loop_ub = in1.size(0);
    } else {
      b_loop_ub = i1;
    }
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_in1[i1 + b_in1.size(0) * i] =
          in1[i1 * stride_0_0 + in1.size(0) * aux_0_1] +
          3.0 * in2[i1 * stride_1_0 + in2.size(0) * aux_1_1];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  in1.set_size(b_in1.size(0), b_in1.size(1));
  loop_ub = b_in1.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = b_in1.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      in1[i1 + in1.size(0) * i] = b_in1[i1 + b_in1.size(0) * i];
    }
  }
}

//
// Arguments    : coder::array<real_T, 3U> &in1
//                const coder::array<real_T, 2U> &in2
// Return Type  : void
//
static void binary_expand_op(coder::array<real_T, 3U> &in1,
                             const coder::array<real_T, 2U> &in2)
{
  coder::array<real_T, 3U> b_in1;
  int32_T i;
  int32_T i1;
  int32_T in2_idx_0;
  int32_T in2_idx_1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_1;
  int32_T stride_1_0;
  int32_T stride_1_1;
  in2_idx_0 = in2.size(0);
  in2_idx_1 = in2.size(1);
  if (in2_idx_0 == 1) {
    i = in1.size(0);
  } else {
    i = in2_idx_0;
  }
  if (in2_idx_1 == 1) {
    i1 = in1.size(1);
  } else {
    i1 = in2_idx_1;
  }
  b_in1.set_size(i, i1, 3);
  stride_0_0 = (in1.size(0) != 1);
  stride_0_1 = (in1.size(1) != 1);
  stride_1_0 = (in2_idx_0 != 1);
  stride_1_1 = (in2_idx_1 != 1);
  if (in2_idx_1 == 1) {
    in2_idx_1 = in1.size(1);
  }
  for (i = 0; i < 3; i++) {
    int32_T aux_0_1;
    int32_T aux_1_1;
    aux_0_1 = 0;
    aux_1_1 = 0;
    for (i1 = 0; i1 < in2_idx_1; i1++) {
      if (in2_idx_0 == 1) {
        loop_ub = in1.size(0);
      } else {
        loop_ub = in2_idx_0;
      }
      for (int32_T i2{0}; i2 < loop_ub; i2++) {
        b_in1[(i2 + b_in1.size(0) * i1) + b_in1.size(0) * b_in1.size(1) * i] =
            in1[(i2 * stride_0_0 + in1.size(0) * aux_0_1) +
                in1.size(0) * in1.size(1) * i] *
            in2[i2 * stride_1_0 + in2_idx_0 * aux_1_1];
      }
      aux_1_1 += stride_1_1;
      aux_0_1 += stride_0_1;
    }
  }
  in1.set_size(b_in1.size(0), b_in1.size(1), 3);
  in2_idx_1 = b_in1.size(1);
  for (i = 0; i < 3; i++) {
    for (i1 = 0; i1 < in2_idx_1; i1++) {
      loop_ub = b_in1.size(0);
      for (int32_T i2{0}; i2 < loop_ub; i2++) {
        in1[(i2 + in1.size(0) * i1) + in1.size(0) * in1.size(1) * i] =
            b_in1[(i2 + b_in1.size(0) * i1) +
                  b_in1.size(0) * b_in1.size(1) * i];
      }
    }
  }
}

//
// set parameters
//
// Arguments    : coder::array<real_T, 3U> &hdrImg
//                coder::array<real_T, 3U> &b_ldrImg
// Return Type  : void
//
void ldrImg::DCA_TMO(coder::array<real_T, 3U> &hdrImg,
                     coder::array<real_T, 3U> &b_ldrImg)
{
  coder::array<real_T, 3U> c_hdrImg;
  coder::array<real_T, 2U> a__2;
  coder::array<real_T, 2U> errors;
  coder::array<real_T, 2U> hdrLum;
  coder::array<real_T, 2U> hdrPQ;
  coder::array<real_T, 2U> labels_DoG;
  coder::array<real_T, 2U> lum;
  coder::array<real_T, 2U> s_data;
  coder::array<real_T, 2U> ss_data;
  coder::array<real_T, 2U> varargin_1;
  coder::array<real_T, 2U> y;
  coder::array<real_T, 1U> b_hdrImg;
  coder::array<real_T, 1U> matrix;
  coder::array<int32_T, 1U> r;
  coder::array<int32_T, 1U> r1;
  coder::array<int32_T, 1U> r2;
  coder::array<int32_T, 1U> r3;
  coder::array<int32_T, 1U> r4;
  coder::array<int32_T, 1U> r5;
  coder::array<boolean_T, 2U> ind;
  real_T a__1[55];
  real_T d;
  real_T e2;
  real_T m;
  int32_T end;
  int32_T i;
  int32_T i1;
  int32_T iindx;
  int32_T loop_ub;
  int32_T nx;
  //  pre-processing
  //  [N, M, C] = size(hdrImg);
  //
  //        ret = MaxQuart(matrix, percentile)
  //
  //        Input:
  //            -matrix: a matrix
  //            -percentile: a value in the range [0,1]
  //
  //        Output:
  //            -ret: the percentile of the input matrix
  //
  //      Copyright (C) 2011-2015  Francesco Banterle
  //
  //      This program is free software: you can redistribute it and/or modify
  //      it under the terms of the GNU General Public License as published by
  //      the Free Software Foundation, either version 3 of the License, or
  //      (at your option) any later version.
  //
  //      This program is distributed in the hope that it will be useful,
  //      but WITHOUT ANY WARRANTY; without even the implied warranty of
  //      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  //      GNU General Public License for more details.
  //
  //      You should have received a copy of the GNU General Public License
  //      along with this program.  If not, see <http://www.gnu.org/licenses/>.
  //
  matrix.set_size(hdrImg.size(0) * hdrImg.size(1) * 3);
  loop_ub = hdrImg.size(0) * hdrImg.size(1) * 3;
  for (i = 0; i < loop_ub; i++) {
    matrix[i] = hdrImg[i];
  }
  coder::internal::sort(matrix);
  i = static_cast<int32_T>(std::round(
      static_cast<real_T>(hdrImg.size(0) * hdrImg.size(1) * 3) * 0.99));
  if (i < 1) {
    i = 1;
  }
  m = matrix[i - 1];
  //
  //        ret = MaxQuart(matrix, percentile)
  //
  //        Input:
  //            -matrix: a matrix
  //            -percentile: a value in the range [0,1]
  //
  //        Output:
  //            -ret: the percentile of the input matrix
  //
  //      Copyright (C) 2011-2015  Francesco Banterle
  //
  //      This program is free software: you can redistribute it and/or modify
  //      it under the terms of the GNU General Public License as published by
  //      the Free Software Foundation, either version 3 of the License, or
  //      (at your option) any later version.
  //
  //      This program is distributed in the hope that it will be useful,
  //      but WITHOUT ANY WARRANTY; without even the implied warranty of
  //      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  //      GNU General Public License for more details.
  //
  //      You should have received a copy of the GNU General Public License
  //      along with this program.  If not, see <http://www.gnu.org/licenses/>.
  //
  matrix.set_size(hdrImg.size(0) * hdrImg.size(1) * 3);
  loop_ub = hdrImg.size(0) * hdrImg.size(1) * 3;
  for (i = 0; i < loop_ub; i++) {
    matrix[i] = hdrImg[i];
  }
  coder::internal::sort(matrix);
  i = static_cast<int32_T>(std::round(
      static_cast<real_T>(hdrImg.size(0) * hdrImg.size(1) * 3) * 0.01));
  if (i < 1) {
    i = 1;
  }
  e2 = matrix[i - 1];
  end = hdrImg.size(0) * (hdrImg.size(1) * 3) - 1;
  nx = 0;
  for (int32_T b_i{0}; b_i <= end; b_i++) {
    if (hdrImg[b_i] > m) {
      nx++;
    }
  }
  r.set_size(nx);
  nx = 0;
  for (int32_T b_i{0}; b_i <= end; b_i++) {
    if (hdrImg[b_i] > m) {
      r[nx] = b_i + 1;
      nx++;
    }
  }
  loop_ub = r.size(0);
  for (i = 0; i < loop_ub; i++) {
    hdrImg[r[i] - 1] = m;
  }
  end = hdrImg.size(0) * (hdrImg.size(1) * 3) - 1;
  nx = 0;
  for (int32_T b_i{0}; b_i <= end; b_i++) {
    if (hdrImg[b_i] < e2) {
      nx++;
    }
  }
  r1.set_size(nx);
  nx = 0;
  for (int32_T b_i{0}; b_i <= end; b_i++) {
    if (hdrImg[b_i] < e2) {
      r1[nx] = b_i + 1;
      nx++;
    }
  }
  loop_ub = r1.size(0);
  for (i = 0; i < loop_ub; i++) {
    hdrImg[r1[i] - 1] = e2;
  }
  //  tone map using clustering method
  hdrLum.set_size(hdrImg.size(0), hdrImg.size(1));
  loop_ub = hdrImg.size(1);
  for (i = 0; i < loop_ub; i++) {
    end = hdrImg.size(0);
    for (i1 = 0; i1 < end; i1++) {
      hdrLum[i1 + hdrLum.size(0) * i] =
          (0.2126 * hdrImg[i1 + hdrImg.size(0) * i] +
           0.7152 * hdrImg[(i1 + hdrImg.size(0) * i) +
                           hdrImg.size(0) * hdrImg.size(1)]) +
          0.0722 * hdrImg[(i1 + hdrImg.size(0) * i) +
                          hdrImg.size(0) * hdrImg.size(1) * 2];
    }
  }
  nx = hdrImg.size(0) * hdrImg.size(1) * 3;
  b_hdrImg = hdrImg.reshape(nx);
  d = coder::internal::maximum(b_hdrImg);
  hdrPQ.set_size(hdrLum.size(0), hdrLum.size(1));
  loop_ub = hdrLum.size(0) * hdrLum.size(1);
  for (i = 0; i < loop_ub; i++) {
    e2 = hdrLum[i] / d;
    hdrPQ[i] = rt_powd_snf(e2, 0.1593017578125);
  }
  loop_ub = hdrPQ.size(0) * hdrPQ.size(1);
  for (i = 0; i < loop_ub; i++) {
    e2 = (18.8515625 * hdrPQ[i] + 0.8359375) / (18.6875 * hdrPQ[i] + 1.0);
    hdrPQ[i] = rt_powd_snf(e2, 78.84375);
  }
  //  y is input data
  //  nclust is the number of clusters or quantization levels. If you want to
  //  quantize data with b bits then nclust <= 2^b (256 if b=8)
  //  labels are the quantization intervals in [1, nclust] range assigned to y
  //  mdata is the mean value of each cluster
  lum.set_size(1, hdrLum.size(0) * hdrLum.size(1));
  loop_ub = hdrLum.size(0) * hdrLum.size(1);
  for (i = 0; i < loop_ub; i++) {
    lum[i] = hdrLum[i];
  }
  coder::internal::sort(lum);
  y.set_size(1, hdrPQ.size(0) * hdrPQ.size(1));
  loop_ub = hdrPQ.size(0) * hdrPQ.size(1);
  for (i = 0; i < loop_ub; i++) {
    y[i] = hdrPQ[i];
  }
  coder::internal::sort(y);
  //  Added initialization to ensure left and right data matches
  a__2.set_size(1, 2);
  a__2[0] = 0.0;
  a__2[1] = y.size(1);
  m = coder::combineVectorElements(y) / static_cast<real_T>(y.size(1));
  ss_data.set_size(1, y.size(1));
  loop_ub = y.size(1);
  for (i = 0; i < loop_ub; i++) {
    e2 = y[i] - m;
    ss_data[i] = e2 * e2;
  }
  errors.set_size(1, 1);
  errors[0] = coder::combineVectorElements(ss_data);
  s_data.set_size(1, y.size(1));
  loop_ub = y.size(1);
  for (i = 0; i < loop_ub; i++) {
    s_data[i] = y[i];
  }
  if ((y.size(1) != 0) && (y.size(1) != 1)) {
    i = y.size(1);
    for (end = 0; end <= i - 2; end++) {
      s_data[end + 1] = s_data[end] + s_data[end + 1];
    }
  }
  ss_data.set_size(1, y.size(1));
  loop_ub = y.size(1);
  for (i = 0; i < loop_ub; i++) {
    e2 = y[i];
    ss_data[i] = e2 * e2;
  }
  if ((ss_data.size(1) != 0) && (ss_data.size(1) != 1)) {
    i = ss_data.size(1);
    for (end = 0; end <= i - 2; end++) {
      ss_data[end + 1] = ss_data[end] + ss_data[end + 1];
    }
  }
  for (int32_T b_i{0}; b_i < 54; b_i++) {
    real_T a;
    real_T k_tmp;
    real_T n;
    real_T sm;
    real_T sn;
    real_T sn_tmp_tmp;
    real_T ssm;
    real_T ssn;
    coder::internal::maximum(errors, &m, &iindx);
    k_tmp = a__2[iindx - 1];
    n = a__2[iindx] - k_tmp;
    sn_tmp_tmp = k_tmp + n;
    sn = s_data[static_cast<int32_T>(sn_tmp_tmp) - 1];
    ssn = ss_data[static_cast<int32_T>(sn_tmp_tmp) - 1];
    if (k_tmp >= 1.0) {
      sn -= s_data[static_cast<int32_T>(k_tmp) - 1];
      ssn -= ss_data[static_cast<int32_T>(a__2[iindx - 1]) - 1];
    }
    d = 2.0;
    m = std::floor(n / 2.0);
    int32_T exitg1;
    do {
      real_T e1;
      exitg1 = 0;
      nx = static_cast<int32_T>(k_tmp + m) - 1;
      sm = s_data[nx];
      ssm = ss_data[nx];
      if (k_tmp >= 1.0) {
        sm -= s_data[static_cast<int32_T>(k_tmp) - 1];
        ssm -= ss_data[static_cast<int32_T>(k_tmp) - 1];
      }
      e1 = ssm - sm * sm / m;
      a = sn - sm;
      e2 = (ssn - ssm) - a * a / (n - m);
      d *= 2.0;
      if ((std::abs(e1 - e2) < 0.001) || (d >= n)) {
        exitg1 = 1;
      } else if (e1 > e2) {
        m -= std::floor(n / d);
      } else if (e1 < e2) {
        m += std::floor(n / d);
      }
    } while (exitg1 == 0);
    y.set_size(1, static_cast<int32_T>(m - 1.0) + 1);
    loop_ub = static_cast<int32_T>(m - 1.0);
    for (i = 0; i <= loop_ub; i++) {
      y[i] = lum[static_cast<int32_T>(k_tmp + static_cast<real_T>(i + 1)) - 1];
    }
    m = (a__2[iindx - 1] + m) + 1.0;
    if (m > sn_tmp_tmp) {
      i = 0;
      i1 = 0;
    } else {
      i = static_cast<int32_T>(m) - 1;
      i1 = static_cast<int32_T>(sn_tmp_tmp);
    }
    m = rt_powd_snf(10.0, tvi(std::log10(coder::median(y))));
    loop_ub = i1 - i;
    y.set_size(1, loop_ub);
    for (i1 = 0; i1 < loop_ub; i1++) {
      y[i1] = lum[i + i1];
    }
    e2 = lum[static_cast<int32_T>(k_tmp + 1.0) - 1];
    m = m / (m + rt_powd_snf(10.0, tvi(std::log10(coder::median(y))))) *
            (lum[static_cast<int32_T>(sn_tmp_tmp) - 1] - e2) +
        e2;
    y.set_size(1, static_cast<int32_T>(n - 1.0) + 1);
    loop_ub = static_cast<int32_T>(n - 1.0);
    for (i = 0; i <= loop_ub; i++) {
      y[i] =
          m - lum[static_cast<int32_T>(k_tmp + static_cast<real_T>(i + 1)) - 1];
    }
    nx = y.size(1);
    varargin_1.set_size(1, y.size(1));
    for (end = 0; end < nx; end++) {
      varargin_1[end] = std::abs(y[end]);
    }
    coder::internal::minimum(varargin_1, &m, &nx);
    e2 = k_tmp + static_cast<real_T>(nx);
    sm = s_data[static_cast<int32_T>(e2) - 1];
    ssm = ss_data[static_cast<int32_T>(e2) - 1];
    if (k_tmp >= 1.0) {
      sm -= s_data[static_cast<int32_T>(a__2[iindx - 1]) - 1];
      ssm -= ss_data[static_cast<int32_T>(a__2[iindx - 1]) - 1];
    }
    a = sn - sm;
    if (static_cast<real_T>(iindx) + 1.0 > a__2.size(1)) {
      i = 0;
      i1 = 0;
    } else {
      i = iindx;
      i1 = a__2.size(1);
    }
    y.set_size(1, ((iindx + i1) - i) + 1);
    for (int32_T i2{0}; i2 < iindx; i2++) {
      y[i2] = a__2[i2];
    }
    y[iindx] = e2;
    loop_ub = i1 - i;
    for (i1 = 0; i1 < loop_ub; i1++) {
      y[(i1 + iindx) + 1] = a__2[i + i1];
    }
    a__2.set_size(1, y.size(1));
    loop_ub = y.size(1);
    for (i = 0; i < loop_ub; i++) {
      a__2[i] = y[i];
    }
    if (static_cast<real_T>(iindx) - 1.0 < 1.0) {
      loop_ub = 0;
    } else {
      loop_ub = iindx - 1;
    }
    if (static_cast<real_T>(iindx) + 1.0 > errors.size(1)) {
      iindx = 0;
      i = 0;
    } else {
      i = errors.size(1);
    }
    y.set_size(1, ((loop_ub + i) - iindx) + 2);
    for (i1 = 0; i1 < loop_ub; i1++) {
      y[i1] = errors[i1];
    }
    y[loop_ub] = ssm - sm * sm / static_cast<real_T>(nx);
    y[loop_ub + 1] = (ssn - ssm) - a * a / (n - static_cast<real_T>(nx));
    end = i - iindx;
    for (i = 0; i < end; i++) {
      y[(i + loop_ub) + 2] = errors[iindx + i];
    }
    errors.set_size(1, y.size(1));
    loop_ub = y.size(1);
    for (i = 0; i < loop_ub; i++) {
      errors[i] = y[i];
    }
  }
  std::memset(&a__1[0], 0, 55U * sizeof(real_T));
  nx = hdrLum.size(0) * hdrLum.size(1);
  b_hdrImg = hdrLum.reshape(nx);
  a__1[0] = coder::internal::minimum(b_hdrImg);
  nx = hdrLum.size(0) * hdrLum.size(1);
  b_hdrImg = hdrLum.reshape(nx);
  a__1[54] = coder::internal::maximum(b_hdrImg);
  for (int32_T b_i{0}; b_i < 53; b_i++) {
    m = lum[static_cast<int32_T>(a__2[b_i + 1]) - 1];
    e2 = lum[static_cast<int32_T>(a__2[b_i + 2]) - 1];
    if (m == e2) {
      ind.set_size(hdrLum.size(0), hdrLum.size(1));
      loop_ub = hdrLum.size(0) * hdrLum.size(1);
      for (i = 0; i < loop_ub; i++) {
        ind[i] = (hdrLum[i] == m);
      }
      end = ind.size(0) * ind.size(1) - 1;
      nx = 0;
      for (loop_ub = 0; loop_ub <= end; loop_ub++) {
        if (ind[loop_ub]) {
          nx++;
        }
      }
      r2.set_size(nx);
      nx = 0;
      for (loop_ub = 0; loop_ub <= end; loop_ub++) {
        if (ind[loop_ub]) {
          r2[nx] = loop_ub + 1;
          nx++;
        }
      }
      loop_ub = r2.size(0);
      matrix.set_size(r2.size(0));
      for (i = 0; i < loop_ub; i++) {
        matrix[i] = hdrLum[r2[i] - 1];
      }
      a__1[b_i + 1] = coder::mean(matrix) +
                      2.2204460492503131E-16 * (static_cast<real_T>(b_i) + 2.0);
    } else {
      ind.set_size(hdrLum.size(0), hdrLum.size(1));
      loop_ub = hdrLum.size(0) * hdrLum.size(1);
      for (i = 0; i < loop_ub; i++) {
        ind[i] = ((hdrLum[i] > m) && (hdrLum[i] <= e2));
      }
      end = ind.size(0) * ind.size(1) - 1;
      nx = 0;
      for (loop_ub = 0; loop_ub <= end; loop_ub++) {
        if (ind[loop_ub]) {
          nx++;
        }
      }
      r3.set_size(nx);
      nx = 0;
      for (loop_ub = 0; loop_ub <= end; loop_ub++) {
        if (ind[loop_ub]) {
          r3[nx] = loop_ub + 1;
          nx++;
        }
      }
      loop_ub = r3.size(0);
      matrix.set_size(r3.size(0));
      for (i = 0; i < loop_ub; i++) {
        matrix[i] = hdrLum[r3[i] - 1];
      }
      a__1[b_i + 1] = coder::mean(matrix);
    }
  }
  coder::interp1(a__1, hdrLum, labels_DoG);
  //  local enhancemant using DoG
  nx = hdrPQ.size(0) * hdrPQ.size(1);
  b_hdrImg = hdrPQ.reshape(nx);
  m = coder::internal::minimum(b_hdrImg);
  nx = hdrPQ.size(0) * hdrPQ.size(1);
  b_hdrImg = hdrPQ.reshape(nx);
  d = coder::internal::maximum(b_hdrImg);
  nx = hdrPQ.size(0) * hdrPQ.size(1);
  b_hdrImg = hdrPQ.reshape(nx);
  e2 = coder::internal::minimum(b_hdrImg);
  if ((hdrPQ.size(0) == labels_DoG.size(0)) &&
      (hdrPQ.size(1) == labels_DoG.size(1))) {
    d -= e2;
    loop_ub = hdrPQ.size(0) * hdrPQ.size(1);
    for (i = 0; i < loop_ub; i++) {
      hdrPQ[i] =
          (255.0 * (hdrPQ[i] - m) / d + 1.0) * 0.35 + labels_DoG[i] * 0.65;
    }
  } else {
    binary_expand_op(hdrPQ, m, d, e2, labels_DoG);
  }
  coder::imfilter(hdrPQ);
  if ((labels_DoG.size(0) == hdrPQ.size(0)) &&
      (labels_DoG.size(1) == hdrPQ.size(1))) {
    loop_ub = labels_DoG.size(0) * labels_DoG.size(1);
    for (i = 0; i < loop_ub; i++) {
      labels_DoG[i] = labels_DoG[i] + 3.0 * hdrPQ[i];
    }
  } else {
    binary_expand_op(labels_DoG, hdrPQ);
  }
  //  color restoration
  nx = labels_DoG.size(0) * labels_DoG.size(1);
  b_hdrImg = labels_DoG.reshape(nx);
  m = coder::internal::minimum(b_hdrImg);
  nx = labels_DoG.size(0) * labels_DoG.size(1);
  b_hdrImg = labels_DoG.reshape(nx);
  d = coder::internal::maximum(b_hdrImg);
  nx = labels_DoG.size(0) * labels_DoG.size(1);
  hdrPQ.set_size(labels_DoG.size(0), labels_DoG.size(1));
  b_hdrImg = labels_DoG.reshape(nx);
  d -= coder::internal::minimum(b_hdrImg);
  loop_ub = labels_DoG.size(0) * labels_DoG.size(1);
  for (i = 0; i < loop_ub; i++) {
    hdrPQ[i] = (labels_DoG[i] - m) / d;
  }
  nx = hdrPQ.size(0) * hdrPQ.size(1);
  for (end = 0; end < nx; end++) {
    hdrPQ[end] = std::atan(hdrPQ[end]);
  }
  loop_ub = hdrPQ.size(0) * hdrPQ.size(1);
  for (i = 0; i < loop_ub; i++) {
    e2 = 1.0 - hdrPQ[i];
    hdrPQ[i] = std::fmin(e2, 0.5);
  }
  if ((hdrImg.size(0) == hdrLum.size(0)) &&
      (hdrImg.size(1) == hdrLum.size(1))) {
    nx = hdrLum.size(0);
    c_hdrImg.set_size(hdrImg.size(0), hdrImg.size(1), 3);
    loop_ub = hdrImg.size(1);
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        end = hdrImg.size(0);
        for (int32_T i2{0}; i2 < end; i2++) {
          c_hdrImg[(i2 + c_hdrImg.size(0) * i1) +
                   c_hdrImg.size(0) * c_hdrImg.size(1) * i] =
              hdrImg[(i2 + hdrImg.size(0) * i1) +
                     hdrImg.size(0) * hdrImg.size(1) * i] /
              hdrLum[i2 + nx * i1];
        }
      }
    }
    coder::internal::expand_power(c_hdrImg, hdrPQ, b_ldrImg);
  } else {
    binary_expand_op(b_ldrImg, hdrImg, hdrLum, hdrPQ);
  }
  if ((b_ldrImg.size(0) == labels_DoG.size(0)) &&
      (b_ldrImg.size(1) == labels_DoG.size(1))) {
    nx = labels_DoG.size(0);
    c_hdrImg.set_size(b_ldrImg.size(0), b_ldrImg.size(1), 3);
    loop_ub = b_ldrImg.size(1);
    for (i = 0; i < 3; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        end = b_ldrImg.size(0);
        for (int32_T i2{0}; i2 < end; i2++) {
          c_hdrImg[(i2 + c_hdrImg.size(0) * i1) +
                   c_hdrImg.size(0) * c_hdrImg.size(1) * i] =
              b_ldrImg[(i2 + b_ldrImg.size(0) * i1) +
                       b_ldrImg.size(0) * b_ldrImg.size(1) * i] *
              labels_DoG[i2 + nx * i1];
        }
      }
    }
    b_ldrImg.set_size(c_hdrImg.size(0), c_hdrImg.size(1), 3);
    loop_ub = c_hdrImg.size(0) * c_hdrImg.size(1) * 3;
    for (i = 0; i < loop_ub; i++) {
      b_ldrImg[i] = c_hdrImg[i];
    }
  } else {
    binary_expand_op(b_ldrImg, labels_DoG);
  }
  //
  //        ret = MaxQuart(matrix, percentile)
  //
  //        Input:
  //            -matrix: a matrix
  //            -percentile: a value in the range [0,1]
  //
  //        Output:
  //            -ret: the percentile of the input matrix
  //
  //      Copyright (C) 2011-2015  Francesco Banterle
  //
  //      This program is free software: you can redistribute it and/or modify
  //      it under the terms of the GNU General Public License as published by
  //      the Free Software Foundation, either version 3 of the License, or
  //      (at your option) any later version.
  //
  //      This program is distributed in the hope that it will be useful,
  //      but WITHOUT ANY WARRANTY; without even the implied warranty of
  //      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  //      GNU General Public License for more details.
  //
  //      You should have received a copy of the GNU General Public License
  //      along with this program.  If not, see <http://www.gnu.org/licenses/>.
  //
  matrix.set_size(b_ldrImg.size(0) * b_ldrImg.size(1) * 3);
  loop_ub = b_ldrImg.size(0) * b_ldrImg.size(1) * 3;
  for (i = 0; i < loop_ub; i++) {
    matrix[i] = b_ldrImg[i];
  }
  coder::internal::sort(matrix);
  i = static_cast<int32_T>(std::round(
      static_cast<real_T>(b_ldrImg.size(0) * b_ldrImg.size(1) * 3) * 0.99));
  if (i < 1) {
    i = 1;
  }
  m = matrix[i - 1];
  //
  //        ret = MaxQuart(matrix, percentile)
  //
  //        Input:
  //            -matrix: a matrix
  //            -percentile: a value in the range [0,1]
  //
  //        Output:
  //            -ret: the percentile of the input matrix
  //
  //      Copyright (C) 2011-2015  Francesco Banterle
  //
  //      This program is free software: you can redistribute it and/or modify
  //      it under the terms of the GNU General Public License as published by
  //      the Free Software Foundation, either version 3 of the License, or
  //      (at your option) any later version.
  //
  //      This program is distributed in the hope that it will be useful,
  //      but WITHOUT ANY WARRANTY; without even the implied warranty of
  //      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  //      GNU General Public License for more details.
  //
  //      You should have received a copy of the GNU General Public License
  //      along with this program.  If not, see <http://www.gnu.org/licenses/>.
  //
  matrix.set_size(b_ldrImg.size(0) * b_ldrImg.size(1) * 3);
  loop_ub = b_ldrImg.size(0) * b_ldrImg.size(1) * 3;
  for (i = 0; i < loop_ub; i++) {
    matrix[i] = b_ldrImg[i];
  }
  coder::internal::sort(matrix);
  i = static_cast<int32_T>(std::round(
      static_cast<real_T>(b_ldrImg.size(0) * b_ldrImg.size(1) * 3) * 0.01));
  if (i < 1) {
    i = 1;
  }
  e2 = matrix[i - 1];
  if (m < 255.0) {
    nx = b_ldrImg.size(0) * b_ldrImg.size(1) * 3;
    b_hdrImg = b_ldrImg.reshape(nx);
    if (coder::internal::maximum(b_hdrImg) < 255.0) {
      nx = b_ldrImg.size(0) * b_ldrImg.size(1) * 3;
      b_hdrImg = b_ldrImg.reshape(nx);
      m = coder::internal::maximum(b_hdrImg);
    } else {
      m = 255.0;
    }
  }
  if (e2 > 0.0) {
    nx = b_ldrImg.size(0) * b_ldrImg.size(1) * 3;
    b_hdrImg = b_ldrImg.reshape(nx);
    if (coder::internal::minimum(b_hdrImg) > 0.0) {
      nx = b_ldrImg.size(0) * b_ldrImg.size(1) * 3;
      b_hdrImg = b_ldrImg.reshape(nx);
      e2 = coder::internal::minimum(b_hdrImg);
    } else {
      e2 = 0.0;
    }
  }
  end = b_ldrImg.size(0) * (b_ldrImg.size(1) * 3) - 1;
  nx = 0;
  for (int32_T b_i{0}; b_i <= end; b_i++) {
    if (b_ldrImg[b_i] > m) {
      nx++;
    }
  }
  r4.set_size(nx);
  nx = 0;
  for (int32_T b_i{0}; b_i <= end; b_i++) {
    if (b_ldrImg[b_i] > m) {
      r4[nx] = b_i + 1;
      nx++;
    }
  }
  loop_ub = r4.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_ldrImg[r4[i] - 1] = m;
  }
  end = b_ldrImg.size(0) * (b_ldrImg.size(1) * 3) - 1;
  nx = 0;
  for (int32_T b_i{0}; b_i <= end; b_i++) {
    if (b_ldrImg[b_i] < e2) {
      nx++;
    }
  }
  r5.set_size(nx);
  nx = 0;
  for (int32_T b_i{0}; b_i <= end; b_i++) {
    if (b_ldrImg[b_i] < e2) {
      r5[nx] = b_i + 1;
      nx++;
    }
  }
  loop_ub = r5.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_ldrImg[r5[i] - 1] = e2;
  }
  loop_ub = b_ldrImg.size(0) * b_ldrImg.size(1) * 3;
  b_ldrImg.set_size(b_ldrImg.size(0), b_ldrImg.size(1), 3);
  m -= e2;
  for (i = 0; i < loop_ub; i++) {
    b_ldrImg[i] = 255.0 * ((b_ldrImg[i] - e2) / m);
  }
}

//
// Arguments    : void
// Return Type  : void
//
ldrImg::ldrImg()
{
  omp_init_nest_lock(&DCA_TMO_nestLockGlobal);
}

//
// Arguments    : void
// Return Type  : void
//
ldrImg::~ldrImg()
{
  omp_destroy_nest_lock(&DCA_TMO_nestLockGlobal);
}

//
// File trailer for ldrImg.cpp
//
// [EOF]
//
