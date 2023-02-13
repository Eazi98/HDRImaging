//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xaxpy.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 17-Jan-2023 23:47:54
//

#ifndef XAXPY_H
#define XAXPY_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
namespace blas {
void b_xaxpy(int32_T n, real_T a, const real_T x[9], int32_T ix0, real_T y[81],
             int32_T iy0);

void xaxpy(int32_T n, real_T a, const real_T x[81], int32_T ix0, real_T y[9],
           int32_T iy0);

void xaxpy(int32_T n, real_T a, int32_T ix0, real_T y[81], int32_T iy0);

} // namespace blas
} // namespace internal
} // namespace coder

#endif
//
// File trailer for xaxpy.h
//
// [EOF]
//
