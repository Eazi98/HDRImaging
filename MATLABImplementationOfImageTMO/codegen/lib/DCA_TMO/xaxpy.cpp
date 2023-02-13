//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xaxpy.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 17-Jan-2023 23:47:54
//

// Include Files
#include "xaxpy.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : int32_T n
//                real_T a
//                const real_T x[9]
//                int32_T ix0
//                real_T y[81]
//                int32_T iy0
// Return Type  : void
//
namespace coder {
namespace internal {
namespace blas {
void b_xaxpy(int32_T n, real_T a, const real_T x[9], int32_T ix0, real_T y[81],
             int32_T iy0)
{
  if (!(a == 0.0)) {
    int32_T i;
    i = n - 1;
    for (int32_T k{0}; k <= i; k++) {
      int32_T i1;
      i1 = (iy0 + k) - 1;
      y[i1] += a * x[(ix0 + k) - 1];
    }
  }
}

//
// Arguments    : int32_T n
//                real_T a
//                const real_T x[81]
//                int32_T ix0
//                real_T y[9]
//                int32_T iy0
// Return Type  : void
//
void xaxpy(int32_T n, real_T a, const real_T x[81], int32_T ix0, real_T y[9],
           int32_T iy0)
{
  if (!(a == 0.0)) {
    int32_T i;
    i = n - 1;
    for (int32_T k{0}; k <= i; k++) {
      int32_T i1;
      i1 = (iy0 + k) - 1;
      y[i1] += a * x[(ix0 + k) - 1];
    }
  }
}

//
// Arguments    : int32_T n
//                real_T a
//                int32_T ix0
//                real_T y[81]
//                int32_T iy0
// Return Type  : void
//
void xaxpy(int32_T n, real_T a, int32_T ix0, real_T y[81], int32_T iy0)
{
  if (!(a == 0.0)) {
    int32_T i;
    i = n - 1;
    for (int32_T k{0}; k <= i; k++) {
      int32_T i1;
      i1 = (iy0 + k) - 1;
      y[i1] += a * y[(ix0 + k) - 1];
    }
  }
}

} // namespace blas
} // namespace internal
} // namespace coder

//
// File trailer for xaxpy.cpp
//
// [EOF]
//
