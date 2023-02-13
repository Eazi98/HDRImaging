//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: tvi.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 17-Jan-2023 23:47:54
//

// Include Files
#include "tvi.h"
#include "DCA_TMO_rtwutil.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// ---------------------------------------
//  The output is the sensitivity of HVS measured as just noticeable
//  difference in the ambient intensity defined by the input parameter.
//
//  intensity: real luminance in log10 domain
//  threshold: in log10 domain, delta(lum)=10.^(threshold)
//
// Arguments    : real_T intensity
// Return Type  : real_T
//
real_T tvi(real_T intensity)
{
  real_T d;
  real_T tmp_data;
  int32_T ii_size_idx_0;
  int32_T ii_size_idx_1;
  int32_T loop_ub;
  if (intensity < -3.94) {
    ii_size_idx_0 = 1;
    ii_size_idx_1 = 1;
  } else {
    ii_size_idx_0 = 0;
    ii_size_idx_1 = 0;
  }
  d = 0.0;
  loop_ub = ii_size_idx_0 * ii_size_idx_1;
  for (int32_T i{0}; i < loop_ub; i++) {
    d = -2.86;
  }
  if ((intensity >= -3.94) && (intensity < -1.44)) {
    ii_size_idx_0 = 1;
    ii_size_idx_1 = 1;
  } else {
    ii_size_idx_0 = 0;
    ii_size_idx_1 = 0;
  }
  loop_ub = ii_size_idx_0 * ii_size_idx_1;
  for (int32_T i{0}; i < loop_ub; i++) {
    tmp_data = rt_powd_snf(0.405 * intensity + 1.6, 2.18);
  }
  loop_ub = ii_size_idx_0 * ii_size_idx_1;
  for (int32_T i{0}; i < loop_ub; i++) {
    d = tmp_data - 2.86;
  }
  if ((intensity >= -1.44) && (intensity < -0.0184)) {
    ii_size_idx_0 = 1;
    ii_size_idx_1 = 1;
  } else {
    ii_size_idx_0 = 0;
    ii_size_idx_1 = 0;
  }
  loop_ub = ii_size_idx_0 * ii_size_idx_1;
  for (int32_T i{0}; i < loop_ub; i++) {
    d = intensity - 0.395;
  }
  if ((intensity >= -0.0184) && (intensity < 1.9)) {
    ii_size_idx_0 = 1;
    ii_size_idx_1 = 1;
  } else {
    ii_size_idx_0 = 0;
    ii_size_idx_1 = 0;
  }
  loop_ub = ii_size_idx_0 * ii_size_idx_1;
  for (int32_T i{0}; i < loop_ub; i++) {
    tmp_data = rt_powd_snf(0.249 * intensity + 0.65, 2.7);
  }
  loop_ub = ii_size_idx_0 * ii_size_idx_1;
  for (int32_T i{0}; i < loop_ub; i++) {
    d = tmp_data - 0.72;
  }
  if (intensity >= 1.9) {
    ii_size_idx_0 = 1;
    ii_size_idx_1 = 1;
  } else {
    ii_size_idx_0 = 0;
    ii_size_idx_1 = 0;
  }
  loop_ub = ii_size_idx_0 * ii_size_idx_1;
  for (int32_T i{0}; i < loop_ub; i++) {
    d = intensity - 1.255;
  }
  return d - 0.95;
}

//
// File trailer for tvi.cpp
//
// [EOF]
//
