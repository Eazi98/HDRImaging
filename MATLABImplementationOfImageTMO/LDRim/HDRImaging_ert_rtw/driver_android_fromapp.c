/*
 * driver_android_fromapp.c
 *
 * Driver code
 *
 * Copyright 2013-2015 The MathWorks, Inc.
 */
#include <jni.h>
#include <stdlib.h>

extern JavaVM *cachedJvm;
extern jobject cachedActivityObj;
extern jclass cachedMainActivityCls;

void initFromApp()
{
    JNIEnv *pEnv;
    (*cachedJvm)->AttachCurrentThread(cachedJvm, &pEnv, NULL);
}

void getFromAppData(void *outData, char const *funcName, int dataType, int dataSize)
{
    
    JNIEnv *pEnv;
    jmethodID FromAppDataID;
    
    (*cachedJvm)->AttachCurrentThread(cachedJvm, &pEnv, NULL);
    char format[] = {"()[I"};
    switch (dataType)
    {
        case 1: /* uint8 */
        case 2: /* int8 */
            format[3] = 'B';
            break;
        case 3: /* uint16 */
        case 4: /* int16 */
            format[3] = 'S';
            break;
        case 5: /* uint32 */
        case 6: /* int32 */
            break;
        case 7: /* float */
            format[3] = 'F';
            break;
        case 8: /* double */
            format[3] = 'D';
            break;
    }
    FromAppDataID = (*pEnv)->GetMethodID(pEnv, cachedMainActivityCls, funcName, format);
    if (FromAppDataID != NULL)
    {
        jarray ret;
        
        ret = (*pEnv)->CallObjectMethod(pEnv, cachedActivityObj, FromAppDataID);
        switch (dataType)
        {
            case 1: /* uint8 */
            case 2: /* int8  */
                (*pEnv)->GetByteArrayRegion(pEnv, ret, 0, dataSize, (jbyte*)outData);
                if ((*pEnv)->ExceptionCheck(pEnv)) return;
                (*pEnv)->DeleteLocalRef(pEnv, ret);
                break;
            case 3: /* uint16 */
            case 4: /* int16 */
                (*pEnv)->GetShortArrayRegion(pEnv, ret, 0, dataSize, (jshort*)outData);
                if ((*pEnv)->ExceptionCheck(pEnv)) return;
                (*pEnv)->DeleteLocalRef(pEnv, ret);
                break;
            case 5: /* uint32 */
            case 6: /* int32  */
                (*pEnv)->GetIntArrayRegion(pEnv, ret, 0, dataSize, (jint*)outData);
                if ((*pEnv)->ExceptionCheck(pEnv)) return;
                (*pEnv)->DeleteLocalRef(pEnv, ret);
                break;
            case 7: /* float */
                (*pEnv)->GetFloatArrayRegion(pEnv, ret, 0, dataSize, (jfloat*)outData);
                if ((*pEnv)->ExceptionCheck(pEnv)) return;
                (*pEnv)->DeleteLocalRef(pEnv, ret);
                break;
            case 8: /* double */
                (*pEnv)->GetDoubleArrayRegion(pEnv, ret, 0, dataSize, (jdouble*)outData);
                if ((*pEnv)->ExceptionCheck(pEnv)) return;
                (*pEnv)->DeleteLocalRef(pEnv, ret);
                break;
        }        
    }
    else
    {
        if ((*pEnv)->ExceptionCheck(pEnv)) 
            (*pEnv)->ExceptionClear(pEnv);
    }

}

void terminateFromApp()
{
}