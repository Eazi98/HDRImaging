//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ldrImg.h
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 17-Jan-2023 23:47:54
//

#ifndef LDRIMG_H
#define LDRIMG_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
class ldrImg {
public:
  ldrImg();
  ~ldrImg();
  void DCA_TMO(coder::array<real_T, 3U> &hdrImg,
               coder::array<real_T, 3U> &b_ldrImg);
};

#endif
//
// File trailer for ldrImg.h
//
// [EOF]
//
