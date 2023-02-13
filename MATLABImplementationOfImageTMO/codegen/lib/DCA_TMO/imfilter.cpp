//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: imfilter.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 17-Jan-2023 23:47:54
//

// Include Files
#include "imfilter.h"
#include "rt_nonfinite.h"
#include "svd.h"
#include "coder_array.h"
#include "libmwimfilter.h"
#include "libmwippfilter.h"
#include <cmath>

// Function Declarations
namespace coder {
static void padImage(const ::coder::array<real_T, 2U> &a_tmp,
                     const real_T pad[2], ::coder::array<real_T, 2U> &a);

}

// Function Definitions
//
// Arguments    : const ::coder::array<real_T, 2U> &a_tmp
//                const real_T pad[2]
//                ::coder::array<real_T, 2U> &a
// Return Type  : void
//
namespace coder {
static void padImage(const ::coder::array<real_T, 2U> &a_tmp,
                     const real_T pad[2], ::coder::array<real_T, 2U> &a)
{
  array<int32_T, 2U> idxA;
  array<uint32_T, 2U> idxDir;
  array<uint32_T, 2U> y;
  if ((a_tmp.size(0) == 0) || (a_tmp.size(1) == 0)) {
    real_T sizeA_idx_0;
    real_T sizeA_idx_1;
    int32_T loop_ub;
    sizeA_idx_0 = static_cast<real_T>(a_tmp.size(0)) + 2.0 * pad[0];
    sizeA_idx_1 = static_cast<real_T>(a_tmp.size(1)) + 2.0 * pad[1];
    a.set_size(static_cast<int32_T>(sizeA_idx_0),
               static_cast<int32_T>(sizeA_idx_1));
    loop_ub =
        static_cast<int32_T>(sizeA_idx_0) * static_cast<int32_T>(sizeA_idx_1);
    for (int32_T i{0}; i < loop_ub; i++) {
      a[i] = 0.0;
    }
  } else {
    int32_T i;
    int32_T loop_ub;
    uint32_T u;
    if (static_cast<uint32_T>(a_tmp.size(0)) + 8U <
        static_cast<uint32_T>(a_tmp.size(1)) + 8U) {
      u = static_cast<uint32_T>(a_tmp.size(1)) + 8U;
    } else {
      u = static_cast<uint32_T>(a_tmp.size(0)) + 8U;
    }
    idxA.set_size(static_cast<int32_T>(u), 2);
    y.set_size(1, a_tmp.size(0));
    loop_ub = a_tmp.size(0) - 1;
    for (i = 0; i <= loop_ub; i++) {
      y[i] = static_cast<uint32_T>(i) + 1U;
    }
    idxDir.set_size(1, y.size(1) + 8);
    idxDir[0] = 1U;
    idxDir[1] = 1U;
    idxDir[2] = 1U;
    idxDir[3] = 1U;
    loop_ub = y.size(1);
    for (i = 0; i < loop_ub; i++) {
      idxDir[i + 4] = y[i];
    }
    idxDir[y.size(1) + 4] = static_cast<uint32_T>(a_tmp.size(0));
    idxDir[y.size(1) + 5] = static_cast<uint32_T>(a_tmp.size(0));
    idxDir[y.size(1) + 6] = static_cast<uint32_T>(a_tmp.size(0));
    idxDir[y.size(1) + 7] = static_cast<uint32_T>(a_tmp.size(0));
    loop_ub = idxDir.size(1);
    for (i = 0; i < loop_ub; i++) {
      idxA[i] = static_cast<int32_T>(idxDir[i]);
    }
    y.set_size(1, a_tmp.size(1));
    loop_ub = a_tmp.size(1) - 1;
    for (i = 0; i <= loop_ub; i++) {
      y[i] = static_cast<uint32_T>(i) + 1U;
    }
    idxDir.set_size(1, y.size(1) + 8);
    idxDir[0] = 1U;
    idxDir[1] = 1U;
    idxDir[2] = 1U;
    idxDir[3] = 1U;
    loop_ub = y.size(1);
    for (i = 0; i < loop_ub; i++) {
      idxDir[i + 4] = y[i];
    }
    idxDir[y.size(1) + 4] = static_cast<uint32_T>(a_tmp.size(1));
    idxDir[y.size(1) + 5] = static_cast<uint32_T>(a_tmp.size(1));
    idxDir[y.size(1) + 6] = static_cast<uint32_T>(a_tmp.size(1));
    idxDir[y.size(1) + 7] = static_cast<uint32_T>(a_tmp.size(1));
    loop_ub = idxDir.size(1);
    for (i = 0; i < loop_ub; i++) {
      idxA[i + idxA.size(0)] = static_cast<int32_T>(idxDir[i]);
    }
    i = static_cast<int32_T>(static_cast<real_T>(a_tmp.size(1)) + 2.0 * pad[1]);
    a.set_size(
        static_cast<int32_T>(static_cast<real_T>(a_tmp.size(0)) + 2.0 * pad[0]),
        static_cast<int32_T>(static_cast<real_T>(a_tmp.size(1)) +
                             2.0 * pad[1]));
    for (int32_T j{0}; j < i; j++) {
      loop_ub = a.size(0);
      for (int32_T b_i{0}; b_i < loop_ub; b_i++) {
        a[b_i + a.size(0) * j] =
            a_tmp[(idxA[b_i] + a_tmp.size(0) * (idxA[j + idxA.size(0)] - 1)) -
                  1];
      }
    }
  }
}

//
// Arguments    : ::coder::array<real_T, 2U> &varargin_1
// Return Type  : void
//
void imfilter(::coder::array<real_T, 2U> &varargin_1)
{
  static const real_T b_x[81]{-3.4536032619442708E-12, -8.1906882011251731E-10,
                              -4.0717697696829158E-8,  -4.2428815204386648E-7,
                              -9.2673052019452823E-7,  -4.2428815204386648E-7,
                              -4.0717697696829158E-8,  -8.1906882011251731E-10,
                              -3.4536032619442708E-12, -8.1906882011251731E-10,
                              -1.9425327135208133E-7,  -9.65675069311889E-6,
                              -0.00010062441064619439, -0.00021977728197372114,
                              -0.00010062441064619439, -9.65675069311889E-6,
                              -1.9425327135208133E-7,  -8.1906882011251731E-10,
                              -4.0717697696829158E-8,  -9.65675069311889E-6,
                              -0.00047998867375253048, -0.00497423370067001,
                              -0.0107185279736246,     -0.00497423370067001,
                              -0.00047998867375253048, -9.65675069311889E-6,
                              -4.0717697696829158E-8,  -4.2428815204386648E-7,
                              -0.00010062441064619439, -0.00497423370067001,
                              -0.040793629460149305,   -0.030121274736625389,
                              -0.040793629460149305,   -0.00497423370067001,
                              -0.00010062441064619439, -4.2428815204386648E-7,
                              -9.2673052019452823E-7,  -0.00021977728197372114,
                              -0.0107185279736246,     -0.030121274736625389,
                              0.370017121948906,       -0.030121274736625389,
                              -0.0107185279736246,     -0.00021977728197372114,
                              -9.2673052019452823E-7,  -4.2428815204386648E-7,
                              -0.00010062441064619439, -0.00497423370067001,
                              -0.040793629460149305,   -0.030121274736625389,
                              -0.040793629460149305,   -0.00497423370067001,
                              -0.00010062441064619439, -4.2428815204386648E-7,
                              -4.0717697696829158E-8,  -9.65675069311889E-6,
                              -0.00047998867375253048, -0.00497423370067001,
                              -0.0107185279736246,     -0.00497423370067001,
                              -0.00047998867375253048, -9.65675069311889E-6,
                              -4.0717697696829158E-8,  -8.1906882011251731E-10,
                              -1.9425327135208133E-7,  -9.65675069311889E-6,
                              -0.00010062441064619439, -0.00021977728197372114,
                              -0.00010062441064619439, -9.65675069311889E-6,
                              -1.9425327135208133E-7,  -8.1906882011251731E-10,
                              -3.4536032619442708E-12, -8.1906882011251731E-10,
                              -4.0717697696829158E-8,  -4.2428815204386648E-7,
                              -9.2673052019452823E-7,  -4.2428815204386648E-7,
                              -4.0717697696829158E-8,  -8.1906882011251731E-10,
                              -3.4536032619442708E-12};
  static const real_T h[81]{-3.4536032619442708E-12, -8.1906882011251731E-10,
                            -4.0717697696829158E-8,  -4.2428815204386648E-7,
                            -9.2673052019452823E-7,  -4.2428815204386648E-7,
                            -4.0717697696829158E-8,  -8.1906882011251731E-10,
                            -3.4536032619442708E-12, -8.1906882011251731E-10,
                            -1.9425327135208133E-7,  -9.65675069311889E-6,
                            -0.00010062441064619439, -0.00021977728197372114,
                            -0.00010062441064619439, -9.65675069311889E-6,
                            -1.9425327135208133E-7,  -8.1906882011251731E-10,
                            -4.0717697696829158E-8,  -9.65675069311889E-6,
                            -0.00047998867375253048, -0.00497423370067001,
                            -0.0107185279736246,     -0.00497423370067001,
                            -0.00047998867375253048, -9.65675069311889E-6,
                            -4.0717697696829158E-8,  -4.2428815204386648E-7,
                            -0.00010062441064619439, -0.00497423370067001,
                            -0.040793629460149305,   -0.030121274736625389,
                            -0.040793629460149305,   -0.00497423370067001,
                            -0.00010062441064619439, -4.2428815204386648E-7,
                            -9.2673052019452823E-7,  -0.00021977728197372114,
                            -0.0107185279736246,     -0.030121274736625389,
                            0.370017121948906,       -0.030121274736625389,
                            -0.0107185279736246,     -0.00021977728197372114,
                            -9.2673052019452823E-7,  -4.2428815204386648E-7,
                            -0.00010062441064619439, -0.00497423370067001,
                            -0.040793629460149305,   -0.030121274736625389,
                            -0.040793629460149305,   -0.00497423370067001,
                            -0.00010062441064619439, -4.2428815204386648E-7,
                            -4.0717697696829158E-8,  -9.65675069311889E-6,
                            -0.00047998867375253048, -0.00497423370067001,
                            -0.0107185279736246,     -0.00497423370067001,
                            -0.00047998867375253048, -9.65675069311889E-6,
                            -4.0717697696829158E-8,  -8.1906882011251731E-10,
                            -1.9425327135208133E-7,  -9.65675069311889E-6,
                            -0.00010062441064619439, -0.00021977728197372114,
                            -0.00010062441064619439, -9.65675069311889E-6,
                            -1.9425327135208133E-7,  -8.1906882011251731E-10,
                            -3.4536032619442708E-12, -8.1906882011251731E-10,
                            -4.0717697696829158E-8,  -4.2428815204386648E-7,
                            -9.2673052019452823E-7,  -4.2428815204386648E-7,
                            -4.0717697696829158E-8,  -8.1906882011251731E-10,
                            -3.4536032619442708E-12};
  array<real_T, 2U> a;
  real_T outSizeT[2];
  real_T startT[2];
  int8_T b_tmp_data[9];
  int8_T tmp_data[9];
  outSizeT[0] = varargin_1.size(0);
  startT[0] = 4.0;
  outSizeT[1] = varargin_1.size(1);
  startT[1] = 4.0;
  if ((varargin_1.size(0) != 0) && (varargin_1.size(1) != 0)) {
    real_T a__1[81];
    real_T a__2[81];
    real_T s[81];
    real_T b_s[9];
    real_T d;
    real_T tol;
    int32_T b_i;
    int32_T i;
    int32_T idx;
    boolean_T x[9];
    svd(h, a__1, s, a__2);
    for (i = 0; i < 9; i++) {
      b_s[i] = s[i + 9 * i];
    }
    if (!std::isnan(b_s[0])) {
      idx = 1;
    } else {
      boolean_T exitg1;
      idx = 0;
      i = 2;
      exitg1 = false;
      while ((!exitg1) && (i <= 9)) {
        if (!std::isnan(b_s[i - 1])) {
          idx = i;
          exitg1 = true;
        } else {
          i++;
        }
      }
    }
    if (idx == 0) {
      tol = b_s[0];
    } else {
      tol = b_s[idx - 1];
      b_i = idx + 1;
      for (i = b_i; i < 10; i++) {
        d = b_s[i - 1];
        if (tol < d) {
          tol = d;
        }
      }
    }
    tol = 9.0 * tol * 2.2204460492503131E-16;
    for (i = 0; i < 9; i++) {
      x[i] = (b_s[i] > tol);
    }
    idx = x[0];
    for (i = 0; i < 8; i++) {
      idx += x[i + 1];
    }
    if (idx == 1) {
      real_T hcol[9];
      real_T nonzero_h_data[9];
      real_T connDimsT[2];
      real_T out_size_row[2];
      real_T padSizeT[2];
      int32_T trueCount;
      boolean_T tooBig;
      padImage(varargin_1, startT, a);
      svd(h, a__1, s, a__2);
      for (i = 0; i < 9; i++) {
        b_s[i] = s[i + 9 * i];
      }
      tol = std::sqrt(b_s[0]);
      out_size_row[0] = a.size(0);
      out_size_row[1] = varargin_1.size(1);
      trueCount = 0;
      idx = 0;
      for (i = 0; i < 9; i++) {
        hcol[i] = a__1[i] * tol;
        d = a__2[i] * tol;
        b_s[i] = d;
        if (d != 0.0) {
          trueCount++;
          tmp_data[idx] = static_cast<int8_T>(i + 1);
          idx++;
        }
      }
      for (b_i = 0; b_i < trueCount; b_i++) {
        nonzero_h_data[b_i] = b_s[tmp_data[b_i] - 1];
      }
      for (i = 0; i < 9; i++) {
        x[i] = (b_s[i] != 0.0);
      }
      tooBig = true;
      if ((a.size(0) <= 65500) || (!(out_size_row[1] > 65500.0))) {
        tooBig = false;
      }
      if ((static_cast<real_T>(trueCount) / 9.0 > 0.05) && (!tooBig)) {
        tooBig = true;
      } else {
        tooBig = false;
      }
      varargin_1.set_size(a.size(0), static_cast<int32_T>(out_size_row[1]));
      if (tooBig) {
        padSizeT[0] = a.size(0);
        startT[0] = 1.0;
        padSizeT[1] = a.size(1);
        startT[1] = 9.0;
        ippfilter_real64(&a[0], &varargin_1[0], &out_size_row[0], 2.0,
                         &padSizeT[0], &b_s[0], &startT[0], false);
      } else {
        padSizeT[0] = a.size(0);
        connDimsT[0] = 1.0;
        startT[0] = 0.0;
        padSizeT[1] = a.size(1);
        connDimsT[1] = 9.0;
        startT[1] = 4.0;
        imfilter_real64(&a[0], &varargin_1[0], 2.0, &out_size_row[0], 2.0,
                        &padSizeT[0], &nonzero_h_data[0],
                        static_cast<real_T>(trueCount), &x[0], 2.0,
                        &connDimsT[0], &startT[0], 2.0, true, false);
      }
      trueCount = 0;
      idx = 0;
      for (i = 0; i < 9; i++) {
        if (hcol[i] != 0.0) {
          trueCount++;
          b_tmp_data[idx] = static_cast<int8_T>(i + 1);
          idx++;
        }
      }
      for (b_i = 0; b_i < trueCount; b_i++) {
        nonzero_h_data[b_i] = hcol[b_tmp_data[b_i] - 1];
      }
      for (i = 0; i < 9; i++) {
        x[i] = (hcol[i] != 0.0);
      }
      tooBig = true;
      if ((outSizeT[0] <= 65500.0) || (!(outSizeT[1] > 65500.0))) {
        tooBig = false;
      }
      if ((static_cast<real_T>(trueCount) / 9.0 > 0.05) && (!tooBig)) {
        tooBig = true;
      } else {
        tooBig = false;
      }
      a.set_size(varargin_1.size(0), varargin_1.size(1));
      idx = varargin_1.size(0) * varargin_1.size(1);
      for (b_i = 0; b_i < idx; b_i++) {
        a[b_i] = varargin_1[b_i];
      }
      varargin_1.set_size(static_cast<int32_T>(outSizeT[0]),
                          static_cast<int32_T>(outSizeT[1]));
      if (tooBig) {
        padSizeT[0] = a.size(0);
        startT[0] = 9.0;
        padSizeT[1] = a.size(1);
        startT[1] = 1.0;
        ippfilter_real64(&a[0], &varargin_1[0], &outSizeT[0], 2.0, &padSizeT[0],
                         &hcol[0], &startT[0], false);
      } else {
        padSizeT[0] = a.size(0);
        connDimsT[0] = 9.0;
        startT[0] = 4.0;
        padSizeT[1] = a.size(1);
        connDimsT[1] = 1.0;
        startT[1] = 0.0;
        imfilter_real64(&a[0], &varargin_1[0], 2.0, &outSizeT[0], 2.0,
                        &padSizeT[0], &nonzero_h_data[0],
                        static_cast<real_T>(trueCount), &x[0], 2.0,
                        &connDimsT[0], &startT[0], 2.0, true, false);
      }
    } else {
      boolean_T tooBig;
      padImage(varargin_1, startT, a);
      tooBig = true;
      if ((outSizeT[0] <= 65500.0) || (!(outSizeT[1] > 65500.0))) {
        tooBig = false;
      }
      varargin_1.set_size(static_cast<int32_T>(outSizeT[0]),
                          static_cast<int32_T>(outSizeT[1]));
      if (!tooBig) {
        real_T padSizeT[2];
        padSizeT[0] = a.size(0);
        startT[0] = 9.0;
        padSizeT[1] = a.size(1);
        startT[1] = 9.0;
        ippfilter_real64(&a[0], &varargin_1[0], &outSizeT[0], 2.0, &padSizeT[0],
                         &h[0], &startT[0], false);
      } else {
        real_T padSizeT[2];
        boolean_T conn[81];
        padSizeT[0] = a.size(0);
        padSizeT[1] = a.size(1);
        for (b_i = 0; b_i < 81; b_i++) {
          conn[b_i] = true;
        }
        real_T connDimsT[2];
        connDimsT[0] = 9.0;
        connDimsT[1] = 9.0;
        imfilter_real64(&a[0], &varargin_1[0], 2.0, &outSizeT[0], 2.0,
                        &padSizeT[0], &b_x[0], 81.0, &conn[0], 2.0,
                        &connDimsT[0], &startT[0], 2.0, true, false);
      }
    }
  }
}

} // namespace coder

//
// File trailer for imfilter.cpp
//
// [EOF]
//
