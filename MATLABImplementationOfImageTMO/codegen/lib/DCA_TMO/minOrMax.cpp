//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: minOrMax.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 17-Jan-2023 23:47:54
//

// Include Files
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const ::coder::array<real_T, 2U> &x
//                real_T *ex
//                int32_T *idx
// Return Type  : void
//
namespace coder {
namespace internal {
void maximum(const ::coder::array<real_T, 2U> &x, real_T *ex, int32_T *idx)
{
  int32_T last;
  last = x.size(1);
  if (x.size(1) <= 2) {
    if (x.size(1) == 0) {
      *ex = rtNaN;
      *idx = 1;
    } else if (x.size(1) == 1) {
      *ex = x[0];
      *idx = 1;
    } else if ((x[0] < x[1]) || (std::isnan(x[0]) && (!std::isnan(x[1])))) {
      *ex = x[1];
      *idx = 2;
    } else {
      *ex = x[0];
      *idx = 1;
    }
  } else {
    int32_T k;
    if (!std::isnan(x[0])) {
      *idx = 1;
    } else {
      boolean_T exitg1;
      *idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!std::isnan(x[k - 1])) {
          *idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (*idx == 0) {
      *ex = x[0];
      *idx = 1;
    } else {
      int32_T i;
      *ex = x[*idx - 1];
      i = *idx + 1;
      for (k = i; k <= last; k++) {
        real_T d;
        d = x[k - 1];
        if (*ex < d) {
          *ex = d;
          *idx = k;
        }
      }
    }
  }
}

//
// Arguments    : const ::coder::array<real_T, 1U> &x
// Return Type  : real_T
//
real_T maximum(const ::coder::array<real_T, 1U> &x)
{
  real_T ex;
  int32_T last;
  last = x.size(0);
  if (x.size(0) <= 2) {
    if (x.size(0) == 1) {
      ex = x[0];
    } else if ((x[0] < x[x.size(0) - 1]) ||
               (std::isnan(x[0]) && (!std::isnan(x[x.size(0) - 1])))) {
      ex = x[x.size(0) - 1];
    } else {
      ex = x[0];
    }
  } else {
    int32_T idx;
    int32_T k;
    if (!std::isnan(x[0])) {
      idx = 1;
    } else {
      boolean_T exitg1;
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!std::isnan(x[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      ex = x[0];
    } else {
      ex = x[idx - 1];
      idx++;
      for (k = idx; k <= last; k++) {
        real_T d;
        d = x[k - 1];
        if (ex < d) {
          ex = d;
        }
      }
    }
  }
  return ex;
}

//
// Arguments    : const ::coder::array<real_T, 2U> &x
//                real_T *ex
//                int32_T *idx
// Return Type  : void
//
void minimum(const ::coder::array<real_T, 2U> &x, real_T *ex, int32_T *idx)
{
  int32_T last;
  last = x.size(1);
  if (x.size(1) <= 2) {
    if (x.size(1) == 1) {
      *ex = x[0];
      *idx = 1;
    } else if ((x[0] > x[x.size(1) - 1]) ||
               (std::isnan(x[0]) && (!std::isnan(x[x.size(1) - 1])))) {
      *ex = x[x.size(1) - 1];
      *idx = x.size(1);
    } else {
      *ex = x[0];
      *idx = 1;
    }
  } else {
    int32_T k;
    if (!std::isnan(x[0])) {
      *idx = 1;
    } else {
      boolean_T exitg1;
      *idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!std::isnan(x[k - 1])) {
          *idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (*idx == 0) {
      *ex = x[0];
      *idx = 1;
    } else {
      int32_T i;
      *ex = x[*idx - 1];
      i = *idx + 1;
      for (k = i; k <= last; k++) {
        real_T d;
        d = x[k - 1];
        if (*ex > d) {
          *ex = d;
          *idx = k;
        }
      }
    }
  }
}

//
// Arguments    : const ::coder::array<real_T, 1U> &x
// Return Type  : real_T
//
real_T minimum(const ::coder::array<real_T, 1U> &x)
{
  real_T ex;
  int32_T last;
  last = x.size(0);
  if (x.size(0) <= 2) {
    if (x.size(0) == 1) {
      ex = x[0];
    } else if ((x[0] > x[x.size(0) - 1]) ||
               (std::isnan(x[0]) && (!std::isnan(x[x.size(0) - 1])))) {
      ex = x[x.size(0) - 1];
    } else {
      ex = x[0];
    }
  } else {
    int32_T idx;
    int32_T k;
    if (!std::isnan(x[0])) {
      idx = 1;
    } else {
      boolean_T exitg1;
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!std::isnan(x[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      ex = x[0];
    } else {
      ex = x[idx - 1];
      idx++;
      for (k = idx; k <= last; k++) {
        real_T d;
        d = x[k - 1];
        if (ex > d) {
          ex = d;
        }
      }
    }
  }
  return ex;
}

} // namespace internal
} // namespace coder

//
// File trailer for minOrMax.cpp
//
// [EOF]
//
