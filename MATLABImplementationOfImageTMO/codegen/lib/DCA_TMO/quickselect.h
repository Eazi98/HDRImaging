//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: quickselect.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 17-Jan-2023 23:47:54
//

#ifndef QUICKSELECT_H
#define QUICKSELECT_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
void quickselect(::coder::array<real_T, 2U> &v, int32_T n, int32_T vlen,
                 real_T *vn, int32_T *nfirst, int32_T *nlast);

}
} // namespace coder

#endif
//
// File trailer for quickselect.h
//
// [EOF]
//
