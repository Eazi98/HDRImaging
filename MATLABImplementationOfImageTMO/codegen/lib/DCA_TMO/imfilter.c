/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * imfilter.c
 *
 * Code generation for function 'imfilter'
 *
 */

/* Include files */
#include "imfilter.h"
#include "DCA_TMO_emxutil.h"
#include "DCA_TMO_types.h"
#include "rt_nonfinite.h"
#include "svd.h"
#include "libmwimfilter.h"
#include "libmwippfilter.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Declarations */
static void padImage(const emxArray_real_T *a_tmp, const double pad[2],
                     emxArray_real_T *a);

/* Function Definitions */
static void padImage(const emxArray_real_T *a_tmp, const double pad[2],
                     emxArray_real_T *a)
{
  emxArray_int32_T *idxA;
  emxArray_uint32_T *idxDir;
  emxArray_uint32_T *y;
  const double *a_tmp_data;
  double sizeA_idx_0;
  double sizeA_idx_1;
  double *a_data;
  int b_i;
  int i;
  int j;
  int loop_ub;
  int *idxA_data;
  unsigned int *idxDir_data;
  unsigned int *y_data;
  a_tmp_data = a_tmp->data;
  if ((a_tmp->size[0] == 0) || (a_tmp->size[1] == 0)) {
    sizeA_idx_0 = (double)a_tmp->size[0] + 2.0 * pad[0];
    sizeA_idx_1 = (double)a_tmp->size[1] + 2.0 * pad[1];
    i = a->size[0] * a->size[1];
    a->size[0] = (int)sizeA_idx_0;
    a->size[1] = (int)sizeA_idx_1;
    emxEnsureCapacity_real_T(a, i);
    a_data = a->data;
    loop_ub = (int)sizeA_idx_0 * (int)sizeA_idx_1;
    for (i = 0; i < loop_ub; i++) {
      a_data[i] = 0.0;
    }
  } else {
    emxInit_int32_T(&idxA, 2);
    i = idxA->size[0] * idxA->size[1];
    if ((unsigned int)a_tmp->size[0] + 8U < (unsigned int)a_tmp->size[1] + 8U) {
      idxA->size[0] = (int)((unsigned int)a_tmp->size[1] + 8U);
    } else {
      idxA->size[0] = (int)((unsigned int)a_tmp->size[0] + 8U);
    }
    idxA->size[1] = 2;
    emxEnsureCapacity_int32_T(idxA, i);
    idxA_data = idxA->data;
    emxInit_uint32_T(&y);
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = a_tmp->size[0];
    emxEnsureCapacity_uint32_T(y, i);
    y_data = y->data;
    loop_ub = a_tmp->size[0] - 1;
    for (i = 0; i <= loop_ub; i++) {
      y_data[i] = (unsigned int)i + 1U;
    }
    emxInit_uint32_T(&idxDir);
    i = idxDir->size[0] * idxDir->size[1];
    idxDir->size[0] = 1;
    idxDir->size[1] = y->size[1] + 8;
    emxEnsureCapacity_uint32_T(idxDir, i);
    idxDir_data = idxDir->data;
    idxDir_data[0] = 1U;
    idxDir_data[1] = 1U;
    idxDir_data[2] = 1U;
    idxDir_data[3] = 1U;
    loop_ub = y->size[1];
    for (i = 0; i < loop_ub; i++) {
      idxDir_data[i + 4] = y_data[i];
    }
    idxDir_data[y->size[1] + 4] = (unsigned int)a_tmp->size[0];
    idxDir_data[y->size[1] + 5] = (unsigned int)a_tmp->size[0];
    idxDir_data[y->size[1] + 6] = (unsigned int)a_tmp->size[0];
    idxDir_data[y->size[1] + 7] = (unsigned int)a_tmp->size[0];
    loop_ub = idxDir->size[1];
    for (i = 0; i < loop_ub; i++) {
      idxA_data[i] = (int)idxDir_data[i];
    }
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = a_tmp->size[1];
    emxEnsureCapacity_uint32_T(y, i);
    y_data = y->data;
    loop_ub = a_tmp->size[1] - 1;
    for (i = 0; i <= loop_ub; i++) {
      y_data[i] = (unsigned int)i + 1U;
    }
    i = idxDir->size[0] * idxDir->size[1];
    idxDir->size[0] = 1;
    idxDir->size[1] = y->size[1] + 8;
    emxEnsureCapacity_uint32_T(idxDir, i);
    idxDir_data = idxDir->data;
    idxDir_data[0] = 1U;
    idxDir_data[1] = 1U;
    idxDir_data[2] = 1U;
    idxDir_data[3] = 1U;
    loop_ub = y->size[1];
    for (i = 0; i < loop_ub; i++) {
      idxDir_data[i + 4] = y_data[i];
    }
    idxDir_data[y->size[1] + 4] = (unsigned int)a_tmp->size[1];
    idxDir_data[y->size[1] + 5] = (unsigned int)a_tmp->size[1];
    idxDir_data[y->size[1] + 6] = (unsigned int)a_tmp->size[1];
    idxDir_data[y->size[1] + 7] = (unsigned int)a_tmp->size[1];
    emxFree_uint32_T(&y);
    loop_ub = idxDir->size[1];
    for (i = 0; i < loop_ub; i++) {
      idxA_data[i + idxA->size[0]] = (int)idxDir_data[i];
    }
    emxFree_uint32_T(&idxDir);
    i = a->size[0] * a->size[1];
    a->size[0] = (int)((double)a_tmp->size[0] + 2.0 * pad[0]);
    loop_ub = (int)((double)a_tmp->size[1] + 2.0 * pad[1]);
    a->size[1] = (int)((double)a_tmp->size[1] + 2.0 * pad[1]);
    emxEnsureCapacity_real_T(a, i);
    a_data = a->data;
    i = a->size[0];
    for (j = 0; j < loop_ub; j++) {
      for (b_i = 0; b_i < i; b_i++) {
        a_data[b_i + a->size[0] * j] =
            a_tmp_data[(idxA_data[b_i] +
                        a_tmp->size[0] * (idxA_data[j + idxA->size[0]] - 1)) -
                       1];
      }
    }
    emxFree_int32_T(&idxA);
  }
}

void imfilter(emxArray_real_T *varargin_1)
{
  static const double b_x[81] = {
      -3.4536032619442708E-12, -8.1906882011251731E-10,
      -4.0717697696829158E-8,  -4.2428815204386648E-7,
      -9.2673052019452823E-7,  -4.2428815204386648E-7,
      -4.0717697696829158E-8,  -8.1906882011251731E-10,
      -3.4536032619442708E-12, -8.1906882011251731E-10,
      -1.9425327135208133E-7,  -9.65675069311889E-6,
      -0.00010062441064619439, -0.00021977728197372114,
      -0.00010062441064619439, -9.65675069311889E-6,
      -1.9425327135208133E-7,  -8.1906882011251731E-10,
      -4.0717697696829158E-8,  -9.65675069311889E-6,
      -0.00047998867375253048, -0.00497423370067001,
      -0.0107185279736246,     -0.00497423370067001,
      -0.00047998867375253048, -9.65675069311889E-6,
      -4.0717697696829158E-8,  -4.2428815204386648E-7,
      -0.00010062441064619439, -0.00497423370067001,
      -0.040793629460149305,   -0.030121274736625389,
      -0.040793629460149305,   -0.00497423370067001,
      -0.00010062441064619439, -4.2428815204386648E-7,
      -9.2673052019452823E-7,  -0.00021977728197372114,
      -0.0107185279736246,     -0.030121274736625389,
      0.370017121948906,       -0.030121274736625389,
      -0.0107185279736246,     -0.00021977728197372114,
      -9.2673052019452823E-7,  -4.2428815204386648E-7,
      -0.00010062441064619439, -0.00497423370067001,
      -0.040793629460149305,   -0.030121274736625389,
      -0.040793629460149305,   -0.00497423370067001,
      -0.00010062441064619439, -4.2428815204386648E-7,
      -4.0717697696829158E-8,  -9.65675069311889E-6,
      -0.00047998867375253048, -0.00497423370067001,
      -0.0107185279736246,     -0.00497423370067001,
      -0.00047998867375253048, -9.65675069311889E-6,
      -4.0717697696829158E-8,  -8.1906882011251731E-10,
      -1.9425327135208133E-7,  -9.65675069311889E-6,
      -0.00010062441064619439, -0.00021977728197372114,
      -0.00010062441064619439, -9.65675069311889E-6,
      -1.9425327135208133E-7,  -8.1906882011251731E-10,
      -3.4536032619442708E-12, -8.1906882011251731E-10,
      -4.0717697696829158E-8,  -4.2428815204386648E-7,
      -9.2673052019452823E-7,  -4.2428815204386648E-7,
      -4.0717697696829158E-8,  -8.1906882011251731E-10,
      -3.4536032619442708E-12};
  static const double h[81] = {-3.4536032619442708E-12, -8.1906882011251731E-10,
                               -4.0717697696829158E-8,  -4.2428815204386648E-7,
                               -9.2673052019452823E-7,  -4.2428815204386648E-7,
                               -4.0717697696829158E-8,  -8.1906882011251731E-10,
                               -3.4536032619442708E-12, -8.1906882011251731E-10,
                               -1.9425327135208133E-7,  -9.65675069311889E-6,
                               -0.00010062441064619439, -0.00021977728197372114,
                               -0.00010062441064619439, -9.65675069311889E-6,
                               -1.9425327135208133E-7,  -8.1906882011251731E-10,
                               -4.0717697696829158E-8,  -9.65675069311889E-6,
                               -0.00047998867375253048, -0.00497423370067001,
                               -0.0107185279736246,     -0.00497423370067001,
                               -0.00047998867375253048, -9.65675069311889E-6,
                               -4.0717697696829158E-8,  -4.2428815204386648E-7,
                               -0.00010062441064619439, -0.00497423370067001,
                               -0.040793629460149305,   -0.030121274736625389,
                               -0.040793629460149305,   -0.00497423370067001,
                               -0.00010062441064619439, -4.2428815204386648E-7,
                               -9.2673052019452823E-7,  -0.00021977728197372114,
                               -0.0107185279736246,     -0.030121274736625389,
                               0.370017121948906,       -0.030121274736625389,
                               -0.0107185279736246,     -0.00021977728197372114,
                               -9.2673052019452823E-7,  -4.2428815204386648E-7,
                               -0.00010062441064619439, -0.00497423370067001,
                               -0.040793629460149305,   -0.030121274736625389,
                               -0.040793629460149305,   -0.00497423370067001,
                               -0.00010062441064619439, -4.2428815204386648E-7,
                               -4.0717697696829158E-8,  -9.65675069311889E-6,
                               -0.00047998867375253048, -0.00497423370067001,
                               -0.0107185279736246,     -0.00497423370067001,
                               -0.00047998867375253048, -9.65675069311889E-6,
                               -4.0717697696829158E-8,  -8.1906882011251731E-10,
                               -1.9425327135208133E-7,  -9.65675069311889E-6,
                               -0.00010062441064619439, -0.00021977728197372114,
                               -0.00010062441064619439, -9.65675069311889E-6,
                               -1.9425327135208133E-7,  -8.1906882011251731E-10,
                               -3.4536032619442708E-12, -8.1906882011251731E-10,
                               -4.0717697696829158E-8,  -4.2428815204386648E-7,
                               -9.2673052019452823E-7,  -4.2428815204386648E-7,
                               -4.0717697696829158E-8,  -8.1906882011251731E-10,
                               -3.4536032619442708E-12};
  emxArray_real_T *a;
  double a__1[81];
  double a__2[81];
  double s[81];
  double b_s[9];
  double hcol[9];
  double nonzero_h_data[9];
  double connDimsT[2];
  double outSizeT[2];
  double out_size_row[2];
  double padSizeT[2];
  double startT[2];
  double d;
  double tol;
  double *a_data;
  double *varargin_1_data;
  int i;
  int idx;
  int k;
  signed char b_tmp_data[9];
  signed char tmp_data[9];
  boolean_T conn[81];
  boolean_T x[9];
  boolean_T exitg1;
  boolean_T tooBig;
  outSizeT[0] = varargin_1->size[0];
  startT[0] = 4.0;
  outSizeT[1] = varargin_1->size[1];
  startT[1] = 4.0;
  if ((varargin_1->size[0] != 0) && (varargin_1->size[1] != 0)) {
    svd(h, a__1, s, a__2);
    for (k = 0; k < 9; k++) {
      b_s[k] = s[k + 9 * k];
    }
    if (!rtIsNaN(b_s[0])) {
      idx = 1;
    } else {
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= 9)) {
        if (!rtIsNaN(b_s[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      tol = b_s[0];
    } else {
      tol = b_s[idx - 1];
      i = idx + 1;
      for (k = i; k < 10; k++) {
        d = b_s[k - 1];
        if (tol < d) {
          tol = d;
        }
      }
    }
    tol = 9.0 * tol * 2.2204460492503131E-16;
    for (i = 0; i < 9; i++) {
      x[i] = (b_s[i] > tol);
    }
    idx = x[0];
    for (k = 0; k < 8; k++) {
      idx += x[k + 1];
    }
    emxInit_real_T(&a, 2);
    if (idx == 1) {
      padImage(varargin_1, startT, a);
      a_data = a->data;
      svd(h, a__1, s, a__2);
      for (k = 0; k < 9; k++) {
        b_s[k] = s[k + 9 * k];
      }
      tol = sqrt(b_s[0]);
      out_size_row[0] = a->size[0];
      out_size_row[1] = varargin_1->size[1];
      k = 0;
      idx = 0;
      for (i = 0; i < 9; i++) {
        hcol[i] = a__1[i] * tol;
        d = a__2[i] * tol;
        b_s[i] = d;
        if (d != 0.0) {
          k++;
          tmp_data[idx] = (signed char)(i + 1);
          idx++;
        }
      }
      for (i = 0; i < k; i++) {
        nonzero_h_data[i] = b_s[tmp_data[i] - 1];
      }
      for (i = 0; i < 9; i++) {
        x[i] = (b_s[i] != 0.0);
      }
      tooBig = true;
      if ((a->size[0] <= 65500) || (!(out_size_row[1] > 65500.0))) {
        tooBig = false;
      }
      if (((double)k / 9.0 > 0.05) && (!tooBig)) {
        tooBig = true;
      } else {
        tooBig = false;
      }
      i = varargin_1->size[0] * varargin_1->size[1];
      varargin_1->size[0] = a->size[0];
      varargin_1->size[1] = (int)out_size_row[1];
      emxEnsureCapacity_real_T(varargin_1, i);
      varargin_1_data = varargin_1->data;
      if (tooBig) {
        padSizeT[0] = a->size[0];
        startT[0] = 1.0;
        padSizeT[1] = a->size[1];
        startT[1] = 9.0;
        ippfilter_real64(&a_data[0], &varargin_1_data[0], &out_size_row[0], 2.0,
                         &padSizeT[0], &b_s[0], &startT[0], false);
      } else {
        padSizeT[0] = a->size[0];
        connDimsT[0] = 1.0;
        startT[0] = 0.0;
        padSizeT[1] = a->size[1];
        connDimsT[1] = 9.0;
        startT[1] = 4.0;
        imfilter_real64(&a_data[0], &varargin_1_data[0], 2.0, &out_size_row[0],
                        2.0, &padSizeT[0], &nonzero_h_data[0], (double)k, &x[0],
                        2.0, &connDimsT[0], &startT[0], 2.0, true, false);
      }
      k = 0;
      idx = 0;
      for (i = 0; i < 9; i++) {
        if (hcol[i] != 0.0) {
          k++;
          b_tmp_data[idx] = (signed char)(i + 1);
          idx++;
        }
      }
      for (i = 0; i < k; i++) {
        nonzero_h_data[i] = hcol[b_tmp_data[i] - 1];
      }
      for (i = 0; i < 9; i++) {
        x[i] = (hcol[i] != 0.0);
      }
      tooBig = true;
      if ((outSizeT[0] <= 65500.0) || (!(outSizeT[1] > 65500.0))) {
        tooBig = false;
      }
      if (((double)k / 9.0 > 0.05) && (!tooBig)) {
        tooBig = true;
      } else {
        tooBig = false;
      }
      i = a->size[0] * a->size[1];
      a->size[0] = varargin_1->size[0];
      a->size[1] = varargin_1->size[1];
      emxEnsureCapacity_real_T(a, i);
      a_data = a->data;
      idx = varargin_1->size[0] * varargin_1->size[1];
      for (i = 0; i < idx; i++) {
        a_data[i] = varargin_1_data[i];
      }
      i = varargin_1->size[0] * varargin_1->size[1];
      varargin_1->size[0] = (int)outSizeT[0];
      varargin_1->size[1] = (int)outSizeT[1];
      emxEnsureCapacity_real_T(varargin_1, i);
      varargin_1_data = varargin_1->data;
      if (tooBig) {
        padSizeT[0] = a->size[0];
        startT[0] = 9.0;
        padSizeT[1] = a->size[1];
        startT[1] = 1.0;
        ippfilter_real64(&a_data[0], &varargin_1_data[0], &outSizeT[0], 2.0,
                         &padSizeT[0], &hcol[0], &startT[0], false);
      } else {
        padSizeT[0] = a->size[0];
        connDimsT[0] = 9.0;
        startT[0] = 4.0;
        padSizeT[1] = a->size[1];
        connDimsT[1] = 1.0;
        startT[1] = 0.0;
        imfilter_real64(&a_data[0], &varargin_1_data[0], 2.0, &outSizeT[0], 2.0,
                        &padSizeT[0], &nonzero_h_data[0], (double)k, &x[0], 2.0,
                        &connDimsT[0], &startT[0], 2.0, true, false);
      }
    } else {
      padImage(varargin_1, startT, a);
      a_data = a->data;
      tooBig = true;
      if ((outSizeT[0] <= 65500.0) || (!(outSizeT[1] > 65500.0))) {
        tooBig = false;
      }
      i = varargin_1->size[0] * varargin_1->size[1];
      varargin_1->size[0] = (int)outSizeT[0];
      varargin_1->size[1] = (int)outSizeT[1];
      emxEnsureCapacity_real_T(varargin_1, i);
      varargin_1_data = varargin_1->data;
      if (!tooBig) {
        padSizeT[0] = a->size[0];
        startT[0] = 9.0;
        padSizeT[1] = a->size[1];
        startT[1] = 9.0;
        ippfilter_real64(&a_data[0], &varargin_1_data[0], &outSizeT[0], 2.0,
                         &padSizeT[0], &h[0], &startT[0], false);
      } else {
        padSizeT[0] = a->size[0];
        padSizeT[1] = a->size[1];
        for (i = 0; i < 81; i++) {
          conn[i] = true;
        }
        connDimsT[0] = 9.0;
        connDimsT[1] = 9.0;
        imfilter_real64(&a_data[0], &varargin_1_data[0], 2.0, &outSizeT[0], 2.0,
                        &padSizeT[0], &b_x[0], 81.0, &conn[0], 2.0,
                        &connDimsT[0], &startT[0], 2.0, true, false);
      }
    }
    emxFree_real_T(&a);
  }
}

/* End of code generation (imfilter.c) */
