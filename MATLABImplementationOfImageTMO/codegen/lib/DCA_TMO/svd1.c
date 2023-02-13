/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * svd1.c
 *
 * Code generation for function 'svd1'
 *
 */

/* Include files */
#include "svd1.h"
#include "rt_nonfinite.h"
#include "xaxpy.h"
#include "xdotc.h"
#include "xnrm2.h"
#include "xrot.h"
#include "xrotg.h"
#include "xswap.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Definitions */
void b_svd(const double A[81], double U[81], double s[9], double V[81])
{
  double b_A[81];
  double e[9];
  double work[9];
  double b;
  double nrm;
  double rt;
  double scale;
  double sm;
  double snorm;
  double sqds;
  int ii;
  int jj;
  int k;
  int m;
  int q;
  int qjj;
  int qp1;
  int qp1jj;
  int qq;
  boolean_T apply_transform;
  boolean_T exitg1;
  memcpy(&b_A[0], &A[0], 81U * sizeof(double));
  memset(&s[0], 0, 9U * sizeof(double));
  memset(&e[0], 0, 9U * sizeof(double));
  memset(&work[0], 0, 9U * sizeof(double));
  memset(&U[0], 0, 81U * sizeof(double));
  memset(&V[0], 0, 81U * sizeof(double));
  for (q = 0; q < 8; q++) {
    qp1 = q + 2;
    qq = (q + 9 * q) + 1;
    apply_transform = false;
    nrm = xnrm2(9 - q, b_A, qq);
    if (nrm > 0.0) {
      apply_transform = true;
      if (b_A[qq - 1] < 0.0) {
        nrm = -nrm;
      }
      s[q] = nrm;
      if (fabs(nrm) >= 1.0020841800044864E-292) {
        nrm = 1.0 / nrm;
        qp1jj = (qq - q) + 8;
        for (k = qq; k <= qp1jj; k++) {
          b_A[k - 1] *= nrm;
        }
      } else {
        qp1jj = (qq - q) + 8;
        for (k = qq; k <= qp1jj; k++) {
          b_A[k - 1] /= s[q];
        }
      }
      b_A[qq - 1]++;
      s[q] = -s[q];
    } else {
      s[q] = 0.0;
    }
    for (jj = qp1; jj < 10; jj++) {
      qjj = q + 9 * (jj - 1);
      if (apply_transform) {
        xaxpy(9 - q, -(xdotc(9 - q, b_A, qq, b_A, qjj + 1) / b_A[q + 9 * q]),
              qq, b_A, qjj + 1);
      }
      e[jj - 1] = b_A[qjj];
    }
    for (ii = q + 1; ii < 10; ii++) {
      qjj = (ii + 9 * q) - 1;
      U[qjj] = b_A[qjj];
    }
    if (q + 1 <= 7) {
      nrm = b_xnrm2(8 - q, e, q + 2);
      if (nrm == 0.0) {
        e[q] = 0.0;
      } else {
        if (e[q + 1] < 0.0) {
          e[q] = -nrm;
        } else {
          e[q] = nrm;
        }
        nrm = e[q];
        if (fabs(e[q]) >= 1.0020841800044864E-292) {
          nrm = 1.0 / e[q];
          for (k = qp1; k < 10; k++) {
            e[k - 1] *= nrm;
          }
        } else {
          for (k = qp1; k < 10; k++) {
            e[k - 1] /= nrm;
          }
        }
        e[q + 1]++;
        e[q] = -e[q];
        for (ii = qp1; ii < 10; ii++) {
          work[ii - 1] = 0.0;
        }
        for (jj = qp1; jj < 10; jj++) {
          b_xaxpy(8 - q, e[jj - 1], b_A, (q + 9 * (jj - 1)) + 2, work, q + 2);
        }
        for (jj = qp1; jj < 10; jj++) {
          c_xaxpy(8 - q, -e[jj - 1] / e[q + 1], work, q + 2, b_A,
                  (q + 9 * (jj - 1)) + 2);
        }
      }
      for (ii = qp1; ii < 10; ii++) {
        V[(ii + 9 * q) - 1] = e[ii - 1];
      }
    }
  }
  m = 7;
  s[8] = b_A[80];
  e[7] = b_A[79];
  e[8] = 0.0;
  memset(&U[72], 0, 9U * sizeof(double));
  U[80] = 1.0;
  for (q = 7; q >= 0; q--) {
    qp1 = q + 2;
    qq = q + 9 * q;
    if (s[q] != 0.0) {
      for (jj = qp1; jj < 10; jj++) {
        qjj = (q + 9 * (jj - 1)) + 1;
        xaxpy(9 - q, -(xdotc(9 - q, U, qq + 1, U, qjj) / U[qq]), qq + 1, U,
              qjj);
      }
      for (ii = q + 1; ii < 10; ii++) {
        qjj = (ii + 9 * q) - 1;
        U[qjj] = -U[qjj];
      }
      U[qq]++;
      for (ii = 0; ii < q; ii++) {
        U[ii + 9 * q] = 0.0;
      }
    } else {
      memset(&U[q * 9], 0, 9U * sizeof(double));
      U[qq] = 1.0;
    }
  }
  for (q = 8; q >= 0; q--) {
    if ((q + 1 <= 7) && (e[q] != 0.0)) {
      qp1 = q + 2;
      qjj = (q + 9 * q) + 2;
      for (jj = qp1; jj < 10; jj++) {
        qp1jj = (q + 9 * (jj - 1)) + 2;
        xaxpy(8 - q, -(xdotc(8 - q, V, qjj, V, qp1jj) / V[qjj - 1]), qjj, V,
              qp1jj);
      }
    }
    memset(&V[q * 9], 0, 9U * sizeof(double));
    V[q + 9 * q] = 1.0;
  }
  qq = 0;
  snorm = 0.0;
  for (q = 0; q < 9; q++) {
    nrm = s[q];
    if (nrm != 0.0) {
      rt = fabs(nrm);
      nrm /= rt;
      s[q] = rt;
      if (q + 1 < 9) {
        e[q] /= nrm;
      }
      qjj = 9 * q;
      qp1jj = qjj + 9;
      for (k = qjj + 1; k <= qp1jj; k++) {
        U[k - 1] *= nrm;
      }
    }
    if (q + 1 < 9) {
      nrm = e[q];
      if (nrm != 0.0) {
        rt = fabs(nrm);
        nrm = rt / nrm;
        e[q] = rt;
        s[q + 1] *= nrm;
        qjj = 9 * (q + 1);
        qp1jj = qjj + 9;
        for (k = qjj + 1; k <= qp1jj; k++) {
          V[k - 1] *= nrm;
        }
      }
    }
    nrm = fabs(s[q]);
    rt = fabs(e[q]);
    if ((nrm >= rt) || rtIsNaN(rt)) {
      rt = nrm;
    }
    if ((!(snorm >= rt)) && (!rtIsNaN(rt))) {
      snorm = rt;
    }
  }
  while ((m + 2 > 0) && (qq < 75)) {
    jj = m + 1;
    ii = m + 1;
    exitg1 = false;
    while (!(exitg1 || (ii == 0))) {
      nrm = fabs(e[ii - 1]);
      if ((nrm <= 2.2204460492503131E-16 * (fabs(s[ii - 1]) + fabs(s[ii]))) ||
          (nrm <= 1.0020841800044864E-292) ||
          ((qq > 20) && (nrm <= 2.2204460492503131E-16 * snorm))) {
        e[ii - 1] = 0.0;
        exitg1 = true;
      } else {
        ii--;
      }
    }
    if (ii == m + 1) {
      qjj = 4;
    } else {
      qp1jj = m + 2;
      qjj = m + 2;
      exitg1 = false;
      while ((!exitg1) && (qjj >= ii)) {
        qp1jj = qjj;
        if (qjj == ii) {
          exitg1 = true;
        } else {
          nrm = 0.0;
          if (qjj < m + 2) {
            nrm = fabs(e[qjj - 1]);
          }
          if (qjj > ii + 1) {
            nrm += fabs(e[qjj - 2]);
          }
          rt = fabs(s[qjj - 1]);
          if ((rt <= 2.2204460492503131E-16 * nrm) ||
              (rt <= 1.0020841800044864E-292)) {
            s[qjj - 1] = 0.0;
            exitg1 = true;
          } else {
            qjj--;
          }
        }
      }
      if (qp1jj == ii) {
        qjj = 3;
      } else if (qp1jj == m + 2) {
        qjj = 1;
      } else {
        qjj = 2;
        ii = qp1jj;
      }
    }
    switch (qjj) {
    case 1:
      rt = e[m];
      e[m] = 0.0;
      for (k = jj; k >= ii + 1; k--) {
        xrotg(&s[k - 1], &rt, &sm, &sqds);
        if (k > ii + 1) {
          b = e[k - 2];
          rt = -sqds * b;
          e[k - 2] = b * sm;
        }
        xrot(V, 9 * (k - 1) + 1, 9 * (m + 1) + 1, sm, sqds);
      }
      break;
    case 2:
      rt = e[ii - 1];
      e[ii - 1] = 0.0;
      for (k = ii + 1; k <= m + 2; k++) {
        xrotg(&s[k - 1], &rt, &sm, &sqds);
        b = e[k - 1];
        rt = -sqds * b;
        e[k - 1] = b * sm;
        xrot(U, 9 * (k - 1) + 1, 9 * (ii - 1) + 1, sm, sqds);
      }
      break;
    case 3:
      nrm = s[m + 1];
      scale = fabs(nrm);
      rt = fabs(s[m]);
      if ((!(scale >= rt)) && (!rtIsNaN(rt))) {
        scale = rt;
      }
      rt = fabs(e[m]);
      if ((!(scale >= rt)) && (!rtIsNaN(rt))) {
        scale = rt;
      }
      rt = fabs(s[ii]);
      if ((!(scale >= rt)) && (!rtIsNaN(rt))) {
        scale = rt;
      }
      rt = fabs(e[ii]);
      if ((!(scale >= rt)) && (!rtIsNaN(rt))) {
        scale = rt;
      }
      sm = nrm / scale;
      nrm = s[m] / scale;
      rt = e[m] / scale;
      sqds = s[ii] / scale;
      b = ((nrm + sm) * (nrm - sm) + rt * rt) / 2.0;
      nrm = sm * rt;
      nrm *= nrm;
      if ((b != 0.0) || (nrm != 0.0)) {
        rt = sqrt(b * b + nrm);
        if (b < 0.0) {
          rt = -rt;
        }
        rt = nrm / (b + rt);
      } else {
        rt = 0.0;
      }
      rt += (sqds + sm) * (sqds - sm);
      nrm = sqds * (e[ii] / scale);
      for (k = ii + 1; k <= jj; k++) {
        xrotg(&rt, &nrm, &sm, &sqds);
        if (k > ii + 1) {
          e[k - 2] = rt;
        }
        nrm = e[k - 1];
        b = s[k - 1];
        e[k - 1] = sm * nrm - sqds * b;
        rt = sqds * s[k];
        s[k] *= sm;
        xrot(V, 9 * (k - 1) + 1, 9 * k + 1, sm, sqds);
        s[k - 1] = sm * b + sqds * nrm;
        xrotg(&s[k - 1], &rt, &sm, &sqds);
        rt = sm * e[k - 1] + sqds * s[k];
        s[k] = -sqds * e[k - 1] + sm * s[k];
        nrm = sqds * e[k];
        e[k] *= sm;
        xrot(U, 9 * (k - 1) + 1, 9 * k + 1, sm, sqds);
      }
      e[m] = rt;
      qq++;
      break;
    default:
      if (s[ii] < 0.0) {
        s[ii] = -s[ii];
        qjj = 9 * ii;
        qp1jj = qjj + 9;
        for (k = qjj + 1; k <= qp1jj; k++) {
          V[k - 1] = -V[k - 1];
        }
      }
      qp1 = ii + 1;
      while ((ii + 1 < 9) && (s[ii] < s[qp1])) {
        rt = s[ii];
        s[ii] = s[qp1];
        s[qp1] = rt;
        xswap(V, 9 * ii + 1, 9 * (ii + 1) + 1);
        xswap(U, 9 * ii + 1, 9 * (ii + 1) + 1);
        ii = qp1;
        qp1++;
      }
      qq = 0;
      m--;
      break;
    }
  }
}

/* End of code generation (svd1.c) */
