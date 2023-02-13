/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * svd.c
 *
 * Code generation for function 'svd'
 *
 */

/* Include files */
#include "svd.h"
#include "rt_nonfinite.h"
#include "svd1.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void svd(const double A[81], double U[81], double S[81], double V[81])
{
  double s[9];
  double d;
  int i;
  boolean_T p;
  p = true;
  for (i = 0; i < 81; i++) {
    if (p) {
      d = A[i];
      if (rtIsInf(d) || rtIsNaN(d)) {
        p = false;
      }
    } else {
      p = false;
    }
  }
  if (p) {
    b_svd(A, U, s, V);
  } else {
    for (i = 0; i < 81; i++) {
      U[i] = rtNaN;
    }
    for (i = 0; i < 9; i++) {
      s[i] = rtNaN;
    }
    for (i = 0; i < 81; i++) {
      V[i] = rtNaN;
    }
  }
  memset(&S[0], 0, 81U * sizeof(double));
  for (i = 0; i < 9; i++) {
    S[i + 9 * i] = s[i];
  }
}

/* End of code generation (svd.c) */
