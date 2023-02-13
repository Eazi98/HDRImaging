//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: combineVectorElements.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 17-Jan-2023 23:47:54
//

// Include Files
#include "combineVectorElements.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<real_T, 2U> &x
// Return Type  : real_T
//
namespace coder {
real_T combineVectorElements(const ::coder::array<real_T, 2U> &x)
{
  real_T y;
  if (x.size(1) == 0) {
    y = 0.0;
  } else {
    int32_T firstBlockLength;
    int32_T lastBlockLength;
    int32_T nblocks;
    if (x.size(1) <= 1024) {
      firstBlockLength = x.size(1);
      lastBlockLength = 0;
      nblocks = 1;
    } else {
      firstBlockLength = 1024;
      nblocks = static_cast<int32_T>(static_cast<uint32_T>(x.size(1)) >> 10);
      lastBlockLength = x.size(1) - (nblocks << 10);
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
  return y;
}

} // namespace coder

//
// File trailer for combineVectorElements.cpp
//
// [EOF]
//
