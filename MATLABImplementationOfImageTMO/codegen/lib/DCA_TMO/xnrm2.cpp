//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xnrm2.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 17-Jan-2023 23:47:54
//

// Include Files
#include "xnrm2.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
// Arguments    : int32_T n
//                const real_T x[9]
//                int32_T ix0
// Return Type  : real_T
//
namespace coder {
namespace internal {
namespace blas {
real_T b_xnrm2(int32_T n, const real_T x[9], int32_T ix0)
{
  real_T scale;
  real_T y;
  int32_T kend;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  kend = (ix0 + n) - 1;
  for (int32_T k{ix0}; k <= kend; k++) {
    real_T absxk;
    absxk = std::abs(x[k - 1]);
    if (absxk > scale) {
      real_T t;
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      real_T t;
      t = absxk / scale;
      y += t * t;
    }
  }
  return scale * std::sqrt(y);
}

//
// Arguments    : int32_T n
//                const real_T x[81]
//                int32_T ix0
// Return Type  : real_T
//
real_T xnrm2(int32_T n, const real_T x[81], int32_T ix0)
{
  real_T scale;
  real_T y;
  int32_T kend;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  kend = (ix0 + n) - 1;
  for (int32_T k{ix0}; k <= kend; k++) {
    real_T absxk;
    absxk = std::abs(x[k - 1]);
    if (absxk > scale) {
      real_T t;
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      real_T t;
      t = absxk / scale;
      y += t * t;
    }
  }
  return scale * std::sqrt(y);
}

} // namespace blas
} // namespace internal
} // namespace coder

//
// File trailer for xnrm2.cpp
//
// [EOF]
//
