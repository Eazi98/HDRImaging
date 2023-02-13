/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'testSimulink'.
 *
 * Model version                  : 1.94
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Feb 13 21:51:36 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include <stdio.h>
#include <stdlib.h>
#include "testSimulink.h"
#include "testSimulink_private.h"
#include "rtwtypes.h"
#include "limits.h"
#include "androidinitialize.h"
#define UNUSED(x)                      x = x
#define NAMELEN                        16

/* Function prototype declaration*/
void exitFcn(int sig);
void *terminateTask(void *arg);
void *baseRateTask(void *arg);
void *subrateTask(void *arg);
volatile boolean_T stopRequested = false;
volatile boolean_T runModel = true;
sem_t stopSem;
sem_t baserateTaskSem;
pthread_t schedulerThread;
pthread_t baseRateThread;
void *threadJoinStatus;
int terminatingmodel = 0;
void *baseRateTask(void *arg)
{
  runModel = (rtmGetErrorStatus(testSimulink_M) == (NULL));
  while (runModel) {
    MW_sem_wait(&baserateTaskSem);
    testSimulink_step();

    /* Get model outputs here */
    stopRequested = !((rtmGetErrorStatus(testSimulink_M) == (NULL)));
  }

  runModel = 0;
  terminateTask(arg);
  MW_pthread_exit((void *)0);
  return NULL;
}

void exitFcn(int sig)
{
  UNUSED(sig);
  rtmSetErrorStatus(testSimulink_M, "stopping the model");
  runModel = 0;
}

void *terminateTask(void *arg)
{
  UNUSED(arg);
  terminatingmodel = 1;

  {
    runModel = 0;
  }

  my_android_terminate();

  /* Terminate model */
  testSimulink_terminate();
  MW_sem_post(&stopSem);
  return NULL;
}

jint JNICALL naMain(JNIEnv *pEnv, jobject pObj, jobjectArray pArgv, jobject
                    pMainActivity)
{
  int argc = 4;
  char *argv[4] = { "testSimulink", "-w", "-port", "17725" };

  my_android_init(pEnv, pObj, pArgv, pMainActivity);
  rtmSetErrorStatus(testSimulink_M, 0);

  /* Initialize model */
  testSimulink_initialize();

  /* Call RTOS Initialization function */
  myRTOSInit(0.1, 0);

  /* Wait for stop semaphore */
  MW_sem_wait(&stopSem);

#if (MW_NUMBER_TIMER_DRIVEN_TASKS > 0)

  {
    int i;
    for (i=0; i < MW_NUMBER_TIMER_DRIVEN_TASKS; i++) {
      CHECK_STATUS(MW_sem_destroy(&timerTaskSem[i]), 0, "MW_sem_destroy");
    }
  }

#endif

  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
