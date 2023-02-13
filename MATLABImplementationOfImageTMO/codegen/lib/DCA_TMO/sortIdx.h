//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sortIdx.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 17-Jan-2023 23:47:54
//

#ifndef SORTIDX_H
#define SORTIDX_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
void merge_block(::coder::array<int32_T, 2U> &idx,
                 ::coder::array<real_T, 2U> &x, int32_T offset, int32_T n,
                 int32_T preSortLevel, ::coder::array<int32_T, 1U> &iwork,
                 ::coder::array<real_T, 1U> &xwork);

void merge_block(::coder::array<int32_T, 1U> &idx,
                 ::coder::array<real_T, 1U> &x, int32_T offset, int32_T n,
                 int32_T preSortLevel, ::coder::array<int32_T, 1U> &iwork,
                 ::coder::array<real_T, 1U> &xwork);

} // namespace internal
} // namespace coder

#endif
//
// File trailer for sortIdx.h
//
// [EOF]
//
