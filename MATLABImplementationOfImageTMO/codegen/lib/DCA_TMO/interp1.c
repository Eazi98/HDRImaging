/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * interp1.c
 *
 * Code generation for function 'interp1'
 *
 */

/* Include files */
#include "interp1.h"
#include "DCA_TMO_emxutil.h"
#include "DCA_TMO_types.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void interp1(const double varargin_1[55], const emxArray_real_T *varargin_3,
             emxArray_real_T *Vq)
{
  double x[55];
  double y[55];
  const double *varargin_3_data;
  double xtmp;
  double *Vq_data;
  int exitg1;
  int high_i;
  int k;
  int low_i;
  int low_ip1;
  int mid_i;
  int nxi;
  boolean_T b;
  boolean_T b1;
  varargin_3_data = varargin_3->data;
  for (low_i = 0; low_i < 55; low_i++) {
    x[low_i] = varargin_1[low_i];
    y[low_i] = 4.7222222222222223 * (double)low_i + 1.0;
  }
  low_i = Vq->size[0] * Vq->size[1];
  Vq->size[0] = varargin_3->size[0];
  Vq->size[1] = varargin_3->size[1];
  emxEnsureCapacity_real_T(Vq, low_i);
  Vq_data = Vq->data;
  nxi = varargin_3->size[0] * varargin_3->size[1];
  for (low_i = 0; low_i < nxi; low_i++) {
    Vq_data[low_i] = rtNaN;
  }
  b = (varargin_3->size[0] == 0);
  b1 = (varargin_3->size[1] == 0);
  if ((!b) && (!b1)) {
    k = 0;
    do {
      exitg1 = 0;
      if (k < 55) {
        if (rtIsNaN(varargin_1[k])) {
          exitg1 = 1;
        } else {
          k++;
        }
      } else {
        if (varargin_1[1] < varargin_1[0]) {
          for (nxi = 0; nxi < 27; nxi++) {
            xtmp = x[nxi];
            x[nxi] = x[54 - nxi];
            x[54 - nxi] = xtmp;
            xtmp = y[nxi];
            y[nxi] = y[54 - nxi];
            y[54 - nxi] = xtmp;
          }
        }
        nxi = varargin_3->size[0] * varargin_3->size[1];
        for (k = 0; k < nxi; k++) {
          if (rtIsNaN(varargin_3_data[k])) {
            Vq_data[k] = rtNaN;
          } else if ((!(varargin_3_data[k] > x[54])) &&
                     (!(varargin_3_data[k] < x[0]))) {
            low_i = 1;
            low_ip1 = 2;
            high_i = 55;
            while (high_i > low_ip1) {
              mid_i = (low_i + high_i) >> 1;
              if (varargin_3_data[k] >= x[mid_i - 1]) {
                low_i = mid_i;
                low_ip1 = mid_i + 1;
              } else {
                high_i = mid_i;
              }
            }
            xtmp = x[low_i - 1];
            xtmp = (varargin_3_data[k] - xtmp) / (x[low_i] - xtmp);
            if (xtmp == 0.0) {
              Vq_data[k] = y[low_i - 1];
            } else if (xtmp == 1.0) {
              Vq_data[k] = y[low_i];
            } else if (y[low_i - 1] == y[low_i]) {
              Vq_data[k] = y[low_i - 1];
            } else {
              Vq_data[k] = (1.0 - xtmp) * y[low_i - 1] + xtmp * y[low_i];
            }
          }
        }
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
}

/* End of code generation (interp1.c) */
