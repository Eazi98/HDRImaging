//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: svd.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 17-Jan-2023 23:47:54
//

// Include Files
#include "svd.h"
#include "rt_nonfinite.h"
#include "svd1.h"
#include <cmath>
#include <cstring>

// Function Definitions
//
// Arguments    : const real_T A[81]
//                real_T U[81]
//                real_T S[81]
//                real_T V[81]
// Return Type  : void
//
namespace coder {
void svd(const real_T A[81], real_T U[81], real_T S[81], real_T V[81])
{
  real_T s[9];
  boolean_T p;
  p = true;
  for (int32_T i{0}; i < 81; i++) {
    if (p) {
      real_T d;
      d = A[i];
      if (std::isinf(d) || std::isnan(d)) {
        p = false;
      }
    } else {
      p = false;
    }
  }
  if (p) {
    internal::b_svd(A, U, s, V);
  } else {
    for (int32_T i{0}; i < 81; i++) {
      U[i] = rtNaN;
    }
    for (int32_T i{0}; i < 9; i++) {
      s[i] = rtNaN;
    }
    for (int32_T i{0}; i < 81; i++) {
      V[i] = rtNaN;
    }
  }
  std::memset(&S[0], 0, 81U * sizeof(real_T));
  for (int32_T i{0}; i < 9; i++) {
    S[i + 9 * i] = s[i];
  }
}

} // namespace coder

//
// File trailer for svd.cpp
//
// [EOF]
//
