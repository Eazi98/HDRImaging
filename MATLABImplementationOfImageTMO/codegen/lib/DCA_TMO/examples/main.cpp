//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: main.cpp
//
// MATLAB Coder version            : 5.5
// C/C++ source code generated on  : 17-Jan-2023 23:47:54
//

/*************************************************************************/
/* This automatically generated example C++ main file shows how to call  */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

// Include Files
#include "main.h"
#include "ldrImg.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Declarations
static coder::array<real_T, 3U> argInit_UnboundedxUnboundedx3_real_T();

static real_T argInit_real_T();

// Function Definitions
//
// Arguments    : void
// Return Type  : coder::array<real_T, 3U>
//
static coder::array<real_T, 3U> argInit_UnboundedxUnboundedx3_real_T()
{
  coder::array<real_T, 3U> result;
  // Set the size of the array.
  // Change this size to the value that the application requires.
  result.set_size(2, 2, 3);
  // Loop over the array to initialize each element.
  for (int32_T idx0{0}; idx0 < result.size(0); idx0++) {
    for (int32_T idx1{0}; idx1 < result.size(1); idx1++) {
      for (int32_T idx2{0}; idx2 < 3; idx2++) {
        // Set the value of the array element.
        // Change this value to the value that the application requires.
        result[(idx0 + result.size(0) * idx1) +
               result.size(0) * result.size(1) * idx2] = argInit_real_T();
      }
    }
  }
  return result;
}

//
// Arguments    : void
// Return Type  : real_T
//
static real_T argInit_real_T()
{
  return 0.0;
}

//
// Arguments    : int32_T argc
//                char **argv
// Return Type  : int32_T
//
int32_T main(int32_T, char **)
{
  ldrImg *classInstance;
  classInstance = new ldrImg;
  // Invoke the entry-point functions.
  // You can call entry-point functions multiple times.
  main_DCA_TMO(classInstance);
  delete classInstance;
  return 0;
}

//
// Arguments    : ldrImg *instancePtr
// Return Type  : void
//
void main_DCA_TMO(ldrImg *instancePtr)
{
  coder::array<real_T, 3U> b_ldrImg;
  coder::array<real_T, 3U> hdrImg;
  // Initialize function 'DCA_TMO' input arguments.
  // Initialize function input argument 'hdrImg'.
  hdrImg = argInit_UnboundedxUnboundedx3_real_T();
  // Call the entry-point 'DCA_TMO'.
  instancePtr->DCA_TMO(hdrImg, b_ldrImg);
}

//
// File trailer for main.cpp
//
// [EOF]
//
