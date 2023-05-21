#include <jni.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>



jobjectArray DCA_TMO(double ***hdrImg, jint length, jint width, jint depth);

void flatten3DArray(double ***arr3D, double *arr1D, jint length, jint width, jint depth);

double * max(double array[2], int length);

double maxQuart(double *hdrImg, double percentile, jint length);

int numel(double **lum, int length, int width);

double *reshape1D(double **lum, int length, int width, int numelLum);

double mean(double *pDouble, int length);

double * sum(double *pDouble, int length);

double * cumsum(double *pDouble, int length);

double * powArray(double *pDouble, int length);

double * RangeArray(double *pDouble, double d, double d1);

extern "C" jobjectArray
Java_com_example_hdrimaging_MainActivity_DCATMO(JNIEnv *env, jobject thiz,
                                                  jobjectArray hdrdouble_array, jint length,
                                                  jint width, jint depth) {

    // Get the dimensions of the Java array
    jsize depthA = (*env).GetArrayLength(hdrdouble_array);
    jobjectArray subArray = (jobjectArray) (*env).GetObjectArrayElement( hdrdouble_array, 0);
    jsize rows = (*env).GetArrayLength(subArray);
    jdoubleArray innerArray = (jdoubleArray) (*env).GetObjectArrayElement(subArray, 0);
    jsize cols = (*env).GetArrayLength(innerArray);

    // Allocate memory for the C array
    double*** cArray = (double***) malloc(depth * sizeof(double**));
    for (jsize i = 0; i < depth; i++) {
        cArray[i] = (double**) malloc(rows * sizeof(double*));
        for (jsize j = 0; j < rows; j++) {
            cArray[i][j] = (double*) malloc(cols * sizeof(double));
        }
    }

    // Retrieve elements from the Java array and assign them to the C array
    for (jsize i = 0; i < depth; i++) {
        subArray = (jobjectArray) (*env).GetObjectArrayElement(hdrdouble_array, i);
        for (jsize j = 0; j < rows; j++) {
            innerArray = (jdoubleArray) (*env).GetObjectArrayElement(subArray, j);
            jdouble* values = (*env).GetDoubleArrayElements(innerArray, NULL);
            for (jsize k = 0; k < cols; k++) {
                cArray[i][j][k] = values[k];
            }
            (*env).ReleaseDoubleArrayElements(innerArray, values, 0);
        }
    }


    return DCA_TMO(cArray, length, width, depth);
}

jobjectArray DCA_TMO(double*** hdrImg, jint length, jint width, jint depth) {

    // Set parameters
    double K = 55;
    // Pre-processing
    int totalElements = length * width * depth;
    double* hdrOneD = (double*)malloc(totalElements * sizeof(double));
    flatten3DArray(hdrImg, hdrOneD, length, width, depth);

    double maxhdr = maxQuart(hdrOneD, 0.99, length);
    double minhdr = maxQuart(hdrOneD, 0.01, length);

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < depth; k++) {
                if (hdrImg[i][j][k] > maxhdr) {
                    hdrImg[i][j][k] = maxhdr;
                } else if (hdrImg[i][j][k] < minhdr) {
                    hdrImg[i][j][k] = minhdr;
                }
            }
        }
    }

    //tone map using clustering methods
    double hdrLum[length][width];
    double hdrLum1[length][width];
    double hdrPQ[length][width];
    //get max value for hdrLum1 = hdrLum./max(hdrImg(:));  max(hdrImg(:)) value
    double hdrMaxValue = hdrImg[0][0][0];
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < depth; k++) {
                if (hdrImg[i][j][k] > hdrMaxValue) {
                    hdrMaxValue = hdrImg[i][j][k];
                }
            }
        }
    }

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            hdrLum[i][j] = 0.2126 * hdrImg[i][j][0] + 0.7152 * hdrImg[i][j][1] + 0.0722 * hdrImg[i][j][2];
            hdrLum1[i][j] = hdrLum[i][j] / hdrMaxValue;
            hdrPQ[i][j] = pow((pow(hdrLum1[i][j], (1305.0 / 8192.0)) * (2413.0 / 128.0) + (107.0 / 128.0)) /
                              (pow(hdrLum1[i][j], (1305.0 / 8192.0)) * (2392.0 / 128.0) + 1.0),
                              (2523.0 / 32.0));
        }
    }


    //Continue from here
    double** labels;
    labels = QuantizeNL_float(hdrPQ, K, hdrLum);
    return 0;


}


//Start of QuantizeNL_Float

double** QuantizeNL_float(double** y, double nclust, double** lum, int length, int width) {
    double** labels = (double**)malloc(length * sizeof(double*));
    int i, j;
    for (i = 0; i < length; i++) {
        labels[i] = (double*)malloc(width * sizeof(double));
        for (j = 0; j < width; j++) {
            // Perform quantization logic here
            // Use hdrPQ[i][j], K, and hdrLum[i][j] to calculate labels[i][j]
        }
    }

    int numelLum = numel(lum, length, width);

    double* lum1D;
    lum1D = reshape1D(lum, length, width, numelLum);
    size_t lum1D_n = sizeof(lum1D) / sizeof(lum1D[0]);
    int (*compare)(const void *, const void *);
    qsort(lum1D, lum1D_n, sizeof(double), compare);

    double* y1D;
    y1D = reshape1D(y, length, width, numel(y, length, width));
    size_t y1D_n = sizeof(y1D) / sizeof(y1D[0]);
    qsort(y1D, y1D_n, sizeof(double), compare);

    int y1DLength = numel(y, length, width);
    int edges[2] = {0, y1DLength};
    double errorsPow[y1DLength];
    double meanOfY = mean(y1D, y1DLength);
    for (int i = 0; i < y1DLength; i++){
        errorsPow[i] = pow((y1D[i]-meanOfY),2);
    }
    double* errors = sum(errorsPow, y1DLength);

    double* s_data = cumsum(y1D, y1DLength);
    double* y1DPow = powArray(y1D, y1DLength);
    double* ss_data = cumsum(y1DPow, y1DLength);

    for (i=0; i<nclust-1; i++)
    {
        double* maxError = max(errors, y1DLength);
        double idx = maxError[1];
        double k = edges[(int)idx];
        double n = edges[(int)idx+1]-(k);
        double sn = s_data[(int) (k+n)-1];
        if(k>=1)
            sn = sn - s_data[(int) k-1];
        double ssn = ss_data[(int) (k+n)-1];
        if(k>=1)
            ssn = ssn - ss_data[(int) k-1];
        double d = 2;
        double m = floor(n/d);
        while(1)
        {
            double sm = s_data[(int) (k+m)-1];
            if(k>=1)
                sm = sm - s_data[(int) k-1];
            double ssm = ss_data[(int) (k+m)-1];
            if(k>=1)
                ssm = ssm - ss_data[(int) k-1];
            double e1 = ssm - pow(sm,2)/m;
            double e2 = ssn - ssm - pow((sn - sm),2)/(n-m);
            d = 2 * d;
            if(fabs(e1-e2) < 0.001 || d >= n) {
                double * lum1Range = RangeArray(lum1D, (k+1-1), (k + m-1));
                double lum1 = median(lum1Range, /*add length here*/);
                double lum1log = log10(lum1);
                TVI tvi = new TVI();
                double tvilum1 = tvi.tvi(new double[]{lum1log});
                double delta1 = Math.pow(10, tvilum1);
            }
        }
    }

    return labels;
}

int compare(const void* a, const void* b) {
    double x = *(const double*)a;
    double y = *(const double*)b;

    if (x < y) {
        return -1;
    } else if (x > y) {
        return 1;
    }

    return 0;
}

double* linspace(double min, double max, int points) {
    double* retArray = (double*)malloc(points * sizeof(double));
    int i;
    for (i = 0; i < points; i++) {
        retArray[i] = min + i * (max - min) / (points - 1);
    }
    return retArray;
}

double* getIndexValuesToArray(double** lum0, double** ind, int rows, int cols) {
    double* retArray = NULL;
    int retSize = 0;

    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 1; j < cols; j++) {
            if (ind[i][j] == 1) {
                retSize++;
                retArray = (double*)realloc(retArray, retSize * sizeof(double));
                retArray[retSize - 1] = lum0[i][j];
            }
        }
    }

    return retArray;
}

double** matrixBoolean(double** array, double valueToCheck, int rows, int cols) {
    double** retArray = (double**)malloc(rows * sizeof(double*));
    int i, j;
    for (i = 0; i < rows; i++) {
        retArray[i] = (double*)malloc(cols * sizeof(double));
        for (j = 0; j < cols; j++) {
            if (array[i][j] == valueToCheck) {
                retArray[i][j] = 1;
            } else {
                retArray[i][j] = 0;
            }
        }
    }
    return retArray;
}

double** matrixBoolean1(double** array, double valueToCheck1, double valueToCheck2, int rows, int cols) {
    double** retArray = (double**)malloc(rows * sizeof(double*));
    int i, j;
    for (i = 0; i < rows; i++) {
        retArray[i] = (double*)malloc(cols * sizeof(double));
        for (j = 0; j < cols; j++) {
            if (array[i][j] > valueToCheck1 && array[i][j] <= valueToCheck2) {
                retArray[i][j] = 1;
            } else {
                retArray[i][j] = 0;
            }
        }
    }
    return retArray;
}

double* AppendEdges(double* rangeArray, double value, double* rangeArray1, int length1, int length2) {
    int resultLength = length1 + length2 + 1;
    double* result = (double*)malloc(resultLength * sizeof(double));
    memcpy(result, rangeArray, length1 * sizeof(double));
    result[length1] = value;
    memcpy(result + length1 + 1, rangeArray1, length2 * sizeof(double));
    return result;
}

double* AppendErrors(double* rangeArray, double e1, double e2, double* rangeArray1, int length1, int length2) {
    int resultLength = length1 + length2 + 2;
    double* result = (double*)malloc(resultLength * sizeof(double));
    memcpy(result, rangeArray, length1 * sizeof(double));
    result[length1] = e1;
    result[length1 + 1] = e2;
    memcpy(result + length1 + 2, rangeArray1, length2 * sizeof(double));
    return result;
}
double* RangeArray(double *lum, double indexStart, double indexEnd) {
    int range = indexEnd - indexStart;
    double* rangeArray = (double*)malloc((range + 1) * sizeof(double));
    int j = indexStart;
    for (int i = 0; i <= range; i++) {
        if (j <= indexEnd) {
            rangeArray[i] = lum[j++];
        }
    }
    return rangeArray;
}

void absMatrix(double* absValue, int length) {
    for (int i = 0; i < length; i++) {
        absValue[i] = fabs(absValue[i]);
    }
}

void doubleMinusArray(double value, double* rangeArray, int length) {
    for (int i = 0; i < length; i++) {
        rangeArray[i] = value - rangeArray[i];
    }
}

int numel(double **array, int length, int width) {
    int num = 0;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            num += 1;
        }
    }
    return num;
}
double *reshape1D(double **lum, int length, int width, int numelLum) {
    double* retArray = malloc(numelLum * sizeof(double));
    int index = 0;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            retArray[index] = lum[i][j];
            index += 1;
        }
    }
    return retArray;
}

double mean(double *array, int length) {
    double sum = 0;
    for (int i = 0; i < length; i++) {
        sum += array[i];
    }
    return sum / length;
}

double* sum(double *array, int length) {
    double sum = 0;
    for (int i = 0; i < length; i++) {
        sum += array[i];
    }

    double result[1] = {sum};
    return result;
}

double* cumsum(double *array, int length) {
    double* retArray = malloc(length * sizeof(double));
    double sum = 0;
    for (int i = 0; i < length; i++) {
        sum += array[i];
        retArray[i] = sum;
    }
    return retArray;
}

double *powArray(double *array, int length) {
    double* retArray = malloc(length * sizeof(double));
    for (int i = 0; i < length; i++) {
        retArray[i] = pow(array[i], 2);
    }
    return retArray;
}

double median(double* array, int length) {
    double m = 0;
    int n = length;

    if (n <= 1) {
        return array[0];
    }
    else if (n % 2 == 1) {
        m = array[((n + 1) / 2) - 1];
    }
    else {
        m = (array[n / 2 - 1] + array[n / 2]) / 2;
    }

    return m;
}

//End of QuantizeNL_Float

double maxQuart(double *hdrImg, double percentile, jint length) {
    if (percentile > 1.0)
        percentile = 1.0;

    if (percentile < 0.0)
        percentile = 0.0;

    double n = length;
    double m = 1;

    // Sort the hdrImg array
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (hdrImg[j] > hdrImg[j + 1]) {
                double temp = hdrImg[j];
                hdrImg[j] = hdrImg[j + 1];
                hdrImg[j + 1] = temp;
            }
        }
    }

    double index = round(n * m * percentile);
    double maxcheck[2] = {index, 1};
    index = max(maxcheck, 2)[0];
    double ret = hdrImg[(int)index];
    return ret;
}

double * max(double array[2], int length) {
    double max = array[0];
    int index = 0;
    for (int i = 0; i < length; i++) {
        if (max < array[i]) {
            max = array[i];
            index = i;
        }
    }
    static double result[2];
    result[0] = max;
    result[1] = index;
    return result;
}

void flatten3DArray(double ***arr3D, double *arr1D, jint length, jint width, jint depth) {
    int index = 0;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < depth; k++) {
                arr1D[index++] = arr3D[i][j][k];
            }
        }
    }
}