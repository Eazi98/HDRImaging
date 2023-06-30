#include <jni.h>
#include <stdlib.h>
#include <time.h>

JNIEXPORT void JNICALL
Java_com_example_hdrimaging_MainActivity_create3DArray(JNIEnv *env, jobject thiz, jint length,
                                                       jint width, jint depth) {
    // Allocate memory for the 3D array
    double*** array3D = (double***)malloc(length * 1000000000 * sizeof(double**));
    for (int i = 0; i < length; i++) {
        array3D[i] = (double**)malloc(width  * 1000000000 * sizeof(double*));
        for (int j = 0; j < width; j++) {
            array3D[i][j] = (double*)malloc(depth * sizeof(double));
        }
    }

//    // Use the 3D array...
//
//    // Free the allocated memory
//    for (int i = 0; i < length; i++) {
//        for (int j = 0; j < width; j++) {
//            free(array3D[i][j]);
//        }
//        free(array3D[i]);
//    }
//    free(array3D);
}