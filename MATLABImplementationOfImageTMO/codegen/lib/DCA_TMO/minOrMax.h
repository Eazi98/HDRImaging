//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: minOrMax.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 17-Jan-2023 23:47:54
//

#ifndef MINORMAX_H
#define MINORMAX_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
void maximum(const ::coder::array<real_T, 2U> &x, real_T *ex, int32_T *idx);

real_T maximum(const ::coder::array<real_T, 1U> &x);

void minimum(const ::coder::array<real_T, 2U> &x, real_T *ex, int32_T *idx);

real_T minimum(const ::coder::array<real_T, 1U> &x);

} // namespace internal
} // namespace coder

#endif
//
// File trailer for minOrMax.h
//
// [EOF]
//
