#include <jni.h>
#include <stdlib.h>
#include <time.h>

jobjectArray
Java_com_example_hdrimaging_MainActivity_DCATMO(JNIEnv *env, jobject thiz,
                                                  jobjectArray hdrdouble_array, jint length,
                                                  jint width, jint depth)
                                                  {

//    // Create a new 3D double array in Java
//    jclass doubleArrayClass = env->FindClass(env,"[D");
//    jobjectArray resultArray = env->NewObjectArray(length, doubleArrayClass, nullptr);
//
//    // Populate the resultArray with your computed values
//    for (int i = 0; i < length; i++) {
//        jobjectArray rowArray = env->NewObjectArray(width, doubleArrayClass, nullptr);
//        for (int j = 0; j < width; j++) {
//            jdoubleArray colArray = env->NewDoubleArray(depth);
//            env->SetDoubleArrayRegion(colArray, 0, depth, computedValues[i][j]);
//            env->SetObjectArrayElement(rowArray, j, colArray);
//            env->DeleteLocalRef(colArray);
//        }
//        env->SetObjectArrayElement(resultArray, i, rowArray);
//        env->DeleteLocalRef(rowArray);
//    }
//
//    return resultArray;
}