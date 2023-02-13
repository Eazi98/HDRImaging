/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ixfun.c
 *
 * Code generation for function 'ixfun'
 *
 */

/* Include files */
#include "ixfun.h"
#include "DCA_TMO_emxutil.h"
#include "DCA_TMO_rtwutil.h"
#include "DCA_TMO_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void b_binary_expand_op(emxArray_real_T *in1, const emxArray_real_T *in2,
                        const emxArray_real_T *in3, const emxArray_real_T *in4)
{
  emxArray_real_T *b_in2;
  const double *in2_data;
  const double *in3_data;
  double *b_in2_data;
  int aux_0_1;
  int aux_1_1;
  int i;
  int i1;
  int i2;
  int in3_idx_0;
  int in3_idx_1;
  int loop_ub;
  int stride_0_0;
  int stride_0_1;
  int stride_1_0;
  int stride_1_1;
  in3_data = in3->data;
  in2_data = in2->data;
  in3_idx_0 = in3->size[0];
  in3_idx_1 = in3->size[1];
  emxInit_real_T(&b_in2, 3);
  i = b_in2->size[0] * b_in2->size[1] * b_in2->size[2];
  if (in3_idx_0 == 1) {
    b_in2->size[0] = in2->size[0];
  } else {
    b_in2->size[0] = in3_idx_0;
  }
  if (in3_idx_1 == 1) {
    b_in2->size[1] = in2->size[1];
  } else {
    b_in2->size[1] = in3_idx_1;
  }
  b_in2->size[2] = 3;
  emxEnsureCapacity_real_T(b_in2, i);
  b_in2_data = b_in2->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_0_1 = (in2->size[1] != 1);
  stride_1_0 = (in3_idx_0 != 1);
  stride_1_1 = (in3_idx_1 != 1);
  if (in3_idx_1 == 1) {
    in3_idx_1 = in2->size[1];
  }
  for (i = 0; i < 3; i++) {
    aux_0_1 = 0;
    aux_1_1 = 0;
    for (i1 = 0; i1 < in3_idx_1; i1++) {
      if (in3_idx_0 == 1) {
        loop_ub = in2->size[0];
      } else {
        loop_ub = in3_idx_0;
      }
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_in2_data[(i2 + b_in2->size[0] * i1) +
                   b_in2->size[0] * b_in2->size[1] * i] =
            in2_data[(i2 * stride_0_0 + in2->size[0] * aux_0_1) +
                     in2->size[0] * in2->size[1] * i] /
            in3_data[i2 * stride_1_0 + in3_idx_0 * aux_1_1];
      }
      aux_1_1 += stride_1_1;
      aux_0_1 += stride_0_1;
    }
  }
  expand_power(b_in2, in4, in1);
  emxFree_real_T(&b_in2);
}

void expand_power(const emxArray_real_T *a, const emxArray_real_T *b,
                  emxArray_real_T *c)
{
  const double *a_data;
  const double *b_data;
  double *c_data;
  int b_k;
  int b_u1;
  int c_k;
  int i;
  int k;
  int u0;
  int u1;
  boolean_T b1;
  boolean_T b2;
  boolean_T b3;
  boolean_T b_b;
  b_data = b->data;
  a_data = a->data;
  i = c->size[0] * c->size[1] * c->size[2];
  u0 = a->size[0];
  u1 = b->size[0];
  if (u0 <= u1) {
    u1 = u0;
  }
  if (b->size[0] == 1) {
    c->size[0] = a->size[0];
  } else if (a->size[0] == 1) {
    c->size[0] = b->size[0];
  } else {
    c->size[0] = u1;
  }
  u0 = a->size[1];
  u1 = b->size[1];
  if (u0 <= u1) {
    u1 = u0;
  }
  if (b->size[1] == 1) {
    c->size[1] = a->size[1];
  } else if (a->size[1] == 1) {
    c->size[1] = b->size[1];
  } else {
    c->size[1] = u1;
  }
  c->size[2] = 3;
  emxEnsureCapacity_real_T(c, i);
  c_data = c->data;
  u0 = a->size[0];
  u1 = b->size[0];
  if (u0 <= u1) {
    u1 = u0;
  }
  u0 = a->size[1];
  b_u1 = b->size[1];
  if (u0 <= b_u1) {
    b_u1 = u0;
  }
  if (b->size[0] == 1) {
    u1 = a->size[0];
  } else if (a->size[0] == 1) {
    u1 = b->size[0];
  }
  if (b->size[1] == 1) {
    b_u1 = a->size[1];
  } else if (a->size[1] == 1) {
    b_u1 = b->size[1];
  }
  if ((u1 != 0) && (b_u1 != 0)) {
    b_b = (a->size[1] != 1);
    b1 = (b->size[1] != 1);
    b2 = (a->size[0] != 1);
    b3 = (b->size[0] != 1);
    for (k = 0; k < 3; k++) {
      i = c->size[1] - 1;
      for (b_k = 0; b_k <= i; b_k++) {
        b_u1 = b_b * b_k;
        u0 = b1 * b_k;
        u1 = c->size[0] - 1;
        for (c_k = 0; c_k <= u1; c_k++) {
          c_data[(c_k + c->size[0] * b_k) + c->size[0] * c->size[1] * k] =
              rt_powd_snf(a_data[(b2 * c_k + a->size[0] * b_u1) +
                                 a->size[0] * a->size[1] * k],
                          b_data[b3 * c_k + b->size[0] * u0]);
        }
      }
    }
  }
}

/* End of code generation (ixfun.c) */
