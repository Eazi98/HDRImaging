/*
 * driver_android_toapp.c
 *
 * Driver code
 *
 * Copyright 2013-2019 The MathWorks, Inc.
 */
#include <jni.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <android/log.h>


extern JavaVM *cachedJvm;
extern jobject cachedActivityObj;
extern jclass cachedMainActivityCls;

void initToApp()
{
    JNIEnv *pEnv;
    (*cachedJvm)->AttachCurrentThread(cachedJvm, &pEnv, NULL);
}

void putToAppData(char const *funcName, int32_t numInputs, ...)
{
    jmethodID ToAppDataID;
    JNIEnv *pEnv;
    jarray arg[5];
    int i, dataType, inSize;
    void *inData;
    char format[20];
    
    strcpy(format, "(");
    (*cachedJvm)->AttachCurrentThread(cachedJvm, &pEnv, NULL);
    
    va_list vl;
    va_start(vl,numInputs);
    for (i=0;i<numInputs;i++)
    {
        inData=va_arg(vl,void*);
        dataType=va_arg(vl,int);
        inSize=va_arg(vl,int);
        switch (dataType)
        {
            case 1: /* uint8 */
            case 2: /* int8  */
                strcat(format, "[B");
                arg[i] = (*pEnv)->NewByteArray(pEnv, inSize);
                (*pEnv)->SetByteArrayRegion(pEnv, arg[i], 0, inSize, inData);
                break;
            case 3: /* uint16 */
            case 4: /* int16 */
                strcat(format, "[S");
                arg[i] = (*pEnv)->NewShortArray(pEnv, inSize);
                (*pEnv)->SetShortArrayRegion(pEnv, arg[i], 0, inSize, inData);
                break;
            case 5: /* uint32 */
            case 6: /* int32 */
                strcat(format, "[I");
                arg[i] = (*pEnv)->NewIntArray(pEnv, inSize);
                (*pEnv)->SetIntArrayRegion(pEnv, arg[i], 0, inSize, inData);
                break;
            case 7: /* float */
                strcat(format, "[F");
                arg[i] = (*pEnv)->NewFloatArray(pEnv, inSize);
                (*pEnv)->SetFloatArrayRegion(pEnv, arg[i], 0, inSize, inData);
                break;
            case 8: /* double */
                strcat(format, "[D");
                arg[i] = (*pEnv)->NewDoubleArray(pEnv, inSize);
                (*pEnv)->SetDoubleArrayRegion(pEnv, arg[i], 0, inSize, inData);
                break;
        }
        if ((*pEnv)->ExceptionCheck(pEnv))
        {
            __android_log_write(ANDROID_LOG_ERROR, "driver_android_toapp", "exception occurred on setting jarray.");
            (*pEnv)->ExceptionDescribe(pEnv);
            for (i=0;i<numInputs;i++)
            {
                (*pEnv)->DeleteLocalRef(pEnv, arg[i]);
            }
            (*pEnv)->ExceptionClear(pEnv);
            return;
        }
    }
    
    strcat(format, ")V");
    
    ToAppDataID = (*pEnv)->GetMethodID(pEnv, cachedMainActivityCls, funcName, format);
    if ((*pEnv)->ExceptionCheck(pEnv))
    {
        __android_log_write(ANDROID_LOG_ERROR, "driver_android_toapp", "Exception: occurred while executing GetMethodID.");
        (*pEnv)->ExceptionDescribe(pEnv);
        for (i=0;i<numInputs;i++)
        {
            (*pEnv)->DeleteLocalRef(pEnv, arg[i]);
        }
        (*pEnv)->ExceptionClear(pEnv);
        return;
    }
    
    if (ToAppDataID != NULL)
    {
        switch(numInputs)
        {
            case 1:
                (*pEnv)->CallVoidMethod(pEnv, cachedActivityObj, ToAppDataID, arg[0]);
                break;
            case 2:
                (*pEnv)->CallVoidMethod(pEnv, cachedActivityObj, ToAppDataID, arg[0], arg[1]);
                break;
            case 3:
                (*pEnv)->CallVoidMethod(pEnv, cachedActivityObj, ToAppDataID, arg[0], arg[1], arg[2]);
                break;
            case 4:
                (*pEnv)->CallVoidMethod(pEnv, cachedActivityObj, ToAppDataID, arg[0], arg[1], arg[2], arg[3]);
                break;
            case 5:
                (*pEnv)->CallVoidMethod(pEnv, cachedActivityObj, ToAppDataID, arg[0], arg[1], arg[2], arg[3], arg[4]);
                break;
        }
        
        if ((*pEnv)->ExceptionCheck(pEnv)) {
            __android_log_write(ANDROID_LOG_ERROR, "driver_android_toapp", "Exception: occurred while executing CallVoidMethod.");
            (*pEnv)->ExceptionDescribe(pEnv);
            (*pEnv)->ExceptionClear(pEnv);
        }
    }
    
    for (i=0;i<numInputs;i++)
    {
        (*pEnv)->DeleteLocalRef(pEnv, arg[i]);
    }
}

void terminateToApp()
{
}
