//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: interp1.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 17-Jan-2023 23:47:54
//

// Include Files
#include "interp1.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "omp.h"
#include <cmath>

// Function Declarations
namespace coder {
static void interp1Linear(const real_T y[55],
                          const ::coder::array<real_T, 2U> &xi,
                          ::coder::array<real_T, 2U> &yi,
                          const real_T varargin_1[55]);

}

// Function Definitions
//
// Arguments    : const real_T y[55]
//                const ::coder::array<real_T, 2U> &xi
//                ::coder::array<real_T, 2U> &yi
//                const real_T varargin_1[55]
// Return Type  : void
//
namespace coder {
static void interp1Linear(const real_T y[55],
                          const ::coder::array<real_T, 2U> &xi,
                          ::coder::array<real_T, 2U> &yi,
                          const real_T varargin_1[55])
{
  real_T d;
  real_T maxx;
  real_T minx;
  real_T r;
  int32_T high_i;
  int32_T low_i;
  int32_T low_ip1;
  int32_T mid_i;
  int32_T ub_loop;
  minx = varargin_1[0];
  maxx = varargin_1[54];
  ub_loop = xi.size(0) * xi.size(1) - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    low_i, low_ip1, high_i, r, mid_i, d)

  for (int32_T k = 0; k <= ub_loop; k++) {
    if (std::isnan(xi[k])) {
      yi[k] = rtNaN;
    } else if ((!(xi[k] > maxx)) && (!(xi[k] < minx))) {
      low_i = 1;
      low_ip1 = 2;
      high_i = 55;
      while (high_i > low_ip1) {
        mid_i = (low_i + high_i) >> 1;
        if (xi[k] >= varargin_1[mid_i - 1]) {
          low_i = mid_i;
          low_ip1 = mid_i + 1;
        } else {
          high_i = mid_i;
        }
      }
      r = varargin_1[low_i - 1];
      r = (xi[k] - r) / (varargin_1[low_i] - r);
      if (r == 0.0) {
        yi[k] = y[low_i - 1];
      } else if (r == 1.0) {
        yi[k] = y[low_i];
      } else {
        d = y[low_i - 1];
        if (d == y[low_i]) {
          yi[k] = d;
        } else {
          yi[k] = (1.0 - r) * d + r * y[low_i];
        }
      }
    }
  }
}

//
// Arguments    : const real_T varargin_1[55]
//                const ::coder::array<real_T, 2U> &varargin_3
//                ::coder::array<real_T, 2U> &Vq
// Return Type  : void
//
void interp1(const real_T varargin_1[55],
             const ::coder::array<real_T, 2U> &varargin_3,
             ::coder::array<real_T, 2U> &Vq)
{
  real_T x[55];
  real_T y[55];
  int32_T loop_ub;
  boolean_T b;
  boolean_T b1;
  for (int32_T i{0}; i < 55; i++) {
    x[i] = varargin_1[i];
    y[i] = 4.7222222222222223 * static_cast<real_T>(i) + 1.0;
  }
  Vq.set_size(varargin_3.size(0), varargin_3.size(1));
  loop_ub = varargin_3.size(0) * varargin_3.size(1);
  for (int32_T i{0}; i < loop_ub; i++) {
    Vq[i] = rtNaN;
  }
  b = (varargin_3.size(0) == 0);
  b1 = (varargin_3.size(1) == 0);
  if ((!b) && (!b1)) {
    loop_ub = 0;
    int32_T exitg1;
    do {
      exitg1 = 0;
      if (loop_ub < 55) {
        if (std::isnan(varargin_1[loop_ub])) {
          exitg1 = 1;
        } else {
          loop_ub++;
        }
      } else {
        if (varargin_1[1] < varargin_1[0]) {
          for (loop_ub = 0; loop_ub < 27; loop_ub++) {
            real_T xtmp;
            xtmp = x[loop_ub];
            x[loop_ub] = x[54 - loop_ub];
            x[54 - loop_ub] = xtmp;
            xtmp = y[loop_ub];
            y[loop_ub] = y[54 - loop_ub];
            y[54 - loop_ub] = xtmp;
          }
        }
        interp1Linear(y, varargin_3, Vq, x);
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
}

} // namespace coder

//
// File trailer for interp1.cpp
//
// [EOF]
//
