//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ixfun.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 17-Jan-2023 23:47:54
//

#ifndef IXFUN_H
#define IXFUN_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
void binary_expand_op(coder::array<real_T, 3U> &in1,
                      const coder::array<real_T, 3U> &in2,
                      const coder::array<real_T, 2U> &in3,
                      const coder::array<real_T, 2U> &in4);

namespace coder {
namespace internal {
void expand_power(const ::coder::array<real_T, 3U> &a,
                  const ::coder::array<real_T, 2U> &b,
                  ::coder::array<real_T, 3U> &c);

}
} // namespace coder

#endif
//
// File trailer for ixfun.h
//
// [EOF]
//
