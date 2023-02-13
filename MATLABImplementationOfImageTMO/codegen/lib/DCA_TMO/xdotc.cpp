//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xdotc.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 17-Jan-2023 23:47:54
//

// Include Files
#include "xdotc.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : int32_T n
//                const real_T x[81]
//                int32_T ix0
//                const real_T y[81]
//                int32_T iy0
// Return Type  : real_T
//
namespace coder {
namespace internal {
namespace blas {
real_T xdotc(int32_T n, const real_T x[81], int32_T ix0, const real_T y[81],
             int32_T iy0)
{
  real_T d;
  int32_T i;
  d = 0.0;
  i = static_cast<uint8_T>(n);
  for (int32_T k{0}; k < i; k++) {
    d += x[(ix0 + k) - 1] * y[(iy0 + k) - 1];
  }
  return d;
}

} // namespace blas
} // namespace internal
} // namespace coder

//
// File trailer for xdotc.cpp
//
// [EOF]
//
