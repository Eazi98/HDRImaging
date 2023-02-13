//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xrot.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 17-Jan-2023 23:47:54
//

// Include Files
#include "xrot.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : real_T x[81]
//                int32_T ix0
//                int32_T iy0
//                real_T c
//                real_T s
// Return Type  : void
//
namespace coder {
namespace internal {
namespace blas {
void xrot(real_T x[81], int32_T ix0, int32_T iy0, real_T c, real_T s)
{
  for (int32_T k{0}; k < 9; k++) {
    real_T b_temp_tmp;
    real_T d_temp_tmp;
    int32_T c_temp_tmp;
    int32_T temp_tmp;
    temp_tmp = (iy0 + k) - 1;
    b_temp_tmp = x[temp_tmp];
    c_temp_tmp = (ix0 + k) - 1;
    d_temp_tmp = x[c_temp_tmp];
    x[temp_tmp] = c * b_temp_tmp - s * d_temp_tmp;
    x[c_temp_tmp] = c * d_temp_tmp + s * b_temp_tmp;
  }
}

} // namespace blas
} // namespace internal
} // namespace coder

//
// File trailer for xrot.cpp
//
// [EOF]
//
