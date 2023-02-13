//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xswap.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 17-Jan-2023 23:47:54
//

// Include Files
#include "xswap.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : real_T x[81]
//                int32_T ix0
//                int32_T iy0
// Return Type  : void
//
namespace coder {
namespace internal {
namespace blas {
void xswap(real_T x[81], int32_T ix0, int32_T iy0)
{
  for (int32_T k{0}; k < 9; k++) {
    real_T temp;
    int32_T i;
    int32_T temp_tmp;
    temp_tmp = (ix0 + k) - 1;
    temp = x[temp_tmp];
    i = (iy0 + k) - 1;
    x[temp_tmp] = x[i];
    x[i] = temp;
  }
}

} // namespace blas
} // namespace internal
} // namespace coder

//
// File trailer for xswap.cpp
//
// [EOF]
//
