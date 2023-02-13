//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ixfun.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 17-Jan-2023 23:47:54
//

// Include Files
#include "ixfun.h"
#include "DCA_TMO_rtwutil.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : coder::array<real_T, 3U> &in1
//                const coder::array<real_T, 3U> &in2
//                const coder::array<real_T, 2U> &in3
//                const coder::array<real_T, 2U> &in4
// Return Type  : void
//
void binary_expand_op(coder::array<real_T, 3U> &in1,
                      const coder::array<real_T, 3U> &in2,
                      const coder::array<real_T, 2U> &in3,
                      const coder::array<real_T, 2U> &in4)
{
  coder::array<real_T, 3U> b_in2;
  int32_T i;
  int32_T i1;
  int32_T in3_idx_0;
  int32_T in3_idx_1;
  int32_T stride_0_0;
  int32_T stride_0_1;
  int32_T stride_1_0;
  int32_T stride_1_1;
  in3_idx_0 = in3.size(0);
  in3_idx_1 = in3.size(1);
  if (in3_idx_0 == 1) {
    i = in2.size(0);
  } else {
    i = in3_idx_0;
  }
  if (in3_idx_1 == 1) {
    i1 = in2.size(1);
  } else {
    i1 = in3_idx_1;
  }
  b_in2.set_size(i, i1, 3);
  stride_0_0 = (in2.size(0) != 1);
  stride_0_1 = (in2.size(1) != 1);
  stride_1_0 = (in3_idx_0 != 1);
  stride_1_1 = (in3_idx_1 != 1);
  if (in3_idx_1 == 1) {
    in3_idx_1 = in2.size(1);
  }
  for (i = 0; i < 3; i++) {
    int32_T aux_0_1;
    int32_T aux_1_1;
    aux_0_1 = 0;
    aux_1_1 = 0;
    for (i1 = 0; i1 < in3_idx_1; i1++) {
      int32_T loop_ub;
      if (in3_idx_0 == 1) {
        loop_ub = in2.size(0);
      } else {
        loop_ub = in3_idx_0;
      }
      for (int32_T i2{0}; i2 < loop_ub; i2++) {
        b_in2[(i2 + b_in2.size(0) * i1) + b_in2.size(0) * b_in2.size(1) * i] =
            in2[(i2 * stride_0_0 + in2.size(0) * aux_0_1) +
                in2.size(0) * in2.size(1) * i] /
            in3[i2 * stride_1_0 + in3_idx_0 * aux_1_1];
      }
      aux_1_1 += stride_1_1;
      aux_0_1 += stride_0_1;
    }
  }
  coder::internal::expand_power(b_in2, in4, in1);
}

//
// Arguments    : const ::coder::array<real_T, 3U> &a
//                const ::coder::array<real_T, 2U> &b
//                ::coder::array<real_T, 3U> &c
// Return Type  : void
//
namespace coder {
namespace internal {
void expand_power(const ::coder::array<real_T, 3U> &a,
                  const ::coder::array<real_T, 2U> &b,
                  ::coder::array<real_T, 3U> &c)
{
  int32_T b_u1;
  int32_T u0;
  int32_T u1;
  u0 = a.size(0);
  u1 = b.size(0);
  if (u0 <= u1) {
    u1 = u0;
  }
  u0 = a.size(1);
  b_u1 = b.size(1);
  if (u0 <= b_u1) {
    b_u1 = u0;
  }
  if (b.size(0) == 1) {
    u1 = a.size(0);
  } else if (a.size(0) == 1) {
    u1 = b.size(0);
  }
  if (b.size(1) == 1) {
    b_u1 = a.size(1);
  } else if (a.size(1) == 1) {
    b_u1 = b.size(1);
  }
  c.set_size(u1, b_u1, 3);
  u0 = a.size(0);
  u1 = b.size(0);
  if (u0 <= u1) {
    u1 = u0;
  }
  u0 = a.size(1);
  b_u1 = b.size(1);
  if (u0 <= b_u1) {
    b_u1 = u0;
  }
  if (b.size(0) == 1) {
    u1 = a.size(0);
  } else if (a.size(0) == 1) {
    u1 = b.size(0);
  }
  if (b.size(1) == 1) {
    b_u1 = a.size(1);
  } else if (a.size(1) == 1) {
    b_u1 = b.size(1);
  }
  if ((u1 != 0) && (b_u1 != 0)) {
    boolean_T b1;
    boolean_T b2;
    boolean_T b3;
    boolean_T b_b;
    b_b = (a.size(1) != 1);
    b1 = (b.size(1) != 1);
    b2 = (a.size(0) != 1);
    b3 = (b.size(0) != 1);
    for (int32_T k{0}; k < 3; k++) {
      u0 = c.size(1) - 1;
      for (int32_T b_k{0}; b_k <= u0; b_k++) {
        int32_T i;
        u1 = b_b * b_k;
        b_u1 = b1 * b_k;
        i = c.size(0) - 1;
        for (int32_T c_k{0}; c_k <= i; c_k++) {
          c[(c_k + c.size(0) * b_k) + c.size(0) * c.size(1) * k] = rt_powd_snf(
              a[(b2 * c_k + a.size(0) * u1) + a.size(0) * a.size(1) * k],
              b[b3 * c_k + b.size(0) * b_u1]);
        }
      }
    }
  }
}

} // namespace internal
} // namespace coder

//
// File trailer for ixfun.cpp
//
// [EOF]
//
