//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mean.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 17-Jan-2023 23:47:54
//

// Include Files
#include "mean.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<real_T, 1U> &x
// Return Type  : real_T
//
namespace coder {
real_T mean(const ::coder::array<real_T, 1U> &x)
{
  real_T y;
  if (x.size(0) == 0) {
    y = 0.0;
  } else {
    int32_T firstBlockLength;
    int32_T lastBlockLength;
    int32_T nblocks;
    if (x.size(0) <= 1024) {
      firstBlockLength = x.size(0);
      lastBlockLength = 0;
      nblocks = 1;
    } else {
      firstBlockLength = 1024;
      nblocks = static_cast<int32_T>(static_cast<uint32_T>(x.size(0)) >> 10);
      lastBlockLength = x.size(0) - (nblocks << 10);
      if (lastBlockLength > 0) {
        nblocks++;
      } else {
        lastBlockLength = 1024;
      }
    }
    y = x[0];
    for (int32_T k{2}; k <= firstBlockLength; k++) {
      y += x[k - 1];
    }
    for (int32_T ib{2}; ib <= nblocks; ib++) {
      real_T bsum;
      int32_T hi;
      firstBlockLength = (ib - 1) << 10;
      bsum = x[firstBlockLength];
      if (ib == nblocks) {
        hi = lastBlockLength;
      } else {
        hi = 1024;
      }
      for (int32_T k{2}; k <= hi; k++) {
        bsum += x[(firstBlockLength + k) - 1];
      }
      y += bsum;
    }
  }
  y /= static_cast<real_T>(x.size(0));
  return y;
}

} // namespace coder

//
// File trailer for mean.cpp
//
// [EOF]
//
