#include <jni.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <opencl-c.h>


jobjectArray DCA_TMO(double ***hdrImg, jint length, jint width, jint depth);

void flatten3DArray(double ***arr3D, double *arr1D, int length, int width, int depth);

double * max(double array[2], int length);

double maxQuart(double *hdrImg, double percentile, int length);

int numel(double **lum, int length, int width);

double *reshape1D(double **lum, int length, int width, int numelLum);

double mean(double *pDouble, int length);

double * sum(double *pDouble, int length);

double * cumsum(double *pDouble, int length);

double * powArray(double *pDouble, int length);

double * RangeArray(double *pDouble, double d, double d1);

double median(double *pDouble, int i);

double tvi(double log);

int find(double intensity, double i, double i1, double d, double i2);

double *doubleMinusArray(double value, double *pDouble);

double *absMatrix(double *pDouble);

double *min(double *pDouble);

double *linspace(int i, int i1, int i2);

double **matrixBoolean1(double **pDouble, double d, double d1, int length, int width);

double **matrixBoolean(double **pDouble, double d, int length, int width);

double *getIndexValuesToArray(double **pDouble, double **pDouble1, int length, int width);

double *AppendErrors(double *pDouble, double e1, double e2, double *pDouble1);

double *AppendEdges(double *pDouble, int i, double *pDouble1);

double **QuantizeNL_float(double **pDouble, double k, double **pDouble1, int length, int width);

double **interp1(double pDouble[], double *pDouble1, double **pDouble2, int i, int i1);

int compare (const void * a, const void * b);


double *linearInterpolation(double *pDouble, double *pDouble1, double *pDouble2);

double **fspecial(int window, double c);

double *findMaxAndMinOfArray(double **pDouble, int length, int width);

double **imfilter(double ** pDouble, double ** pDouble1, int length, int width);

double **filterDouble2DWithConv(double **pDouble, double **pDouble1, int length, int width);

double **rot90(double **pDouble, int i);

double **padarray_algo(double **pDouble, int pInt[2], int i, int i1);

int **getPaddingIndices(double pDouble[2], int *pInt, int i, int i1);

int *ones(int p);

double **RangeMatrix(double **pDouble, int **pInt);

jobjectArray
Java_com_example_hdrimaging_MainActivity_DCATMO(JNIEnv *env, jobject thiz,
                                                  jobjectArray hdrdouble_array, jint lengthw,
                                                  jint widthw, jint depthw) {

    int length = (int) lengthw;
    int width = (int) widthw;
    int depth = (int) depthw;
    // Get the dimensions of the Java array
    jsize depthA = (*env)->GetArrayLength((JNIEnv *) *env, hdrdouble_array);
    jobjectArray subArray = (jobjectArray) (*env)->GetObjectArrayElement( (JNIEnv *) *env,hdrdouble_array, 0);
    jsize rows = (*env)->GetArrayLength((JNIEnv *) *env,subArray);
    jdoubleArray innerArray = (jdoubleArray) (*env)->GetObjectArrayElement((JNIEnv *) *env,subArray, 0);
    jsize cols = (*env)->GetArrayLength((JNIEnv *) *env,innerArray);

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
        subArray = (jobjectArray) (*env)->GetObjectArrayElement((JNIEnv *) *env,hdrdouble_array, i);
        for (jsize j = 0; j < rows; j++) {
            innerArray = (jdoubleArray) (*env)->GetObjectArrayElement((JNIEnv *) *env,subArray, j);
            jdouble* values = (*env)->GetDoubleArrayElements((JNIEnv *) *env,innerArray, NULL);
            for (jsize k = 0; k < cols; k++) {
                cArray[i][j][k] = values[k];
            }
            (*env)->ReleaseDoubleArrayElements((JNIEnv *) *env,innerArray, values, 0);
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
    double **hdrLum;
    double hdrLum1[length][width];
    double **hdrPQ;
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

    double** labels = QuantizeNL_float(hdrPQ, K, hdrLum, length, width);

    //local enhancement using DoG
    double sigmaC = 0.5;
    double sigmaS = 0.8;
    int window = 9;

    double ** gfilterC = fspecial(window, sigmaC);
    double ** gfilterS = fspecial(window, sigmaS);
    double DoGfilter[window][window];
    for (int i = 0; i < window; i++)
        for (int j = 0; j < window; j++)
            DoGfilter[i][j] = (gfilterC[i][j] - gfilterS[i][j]);

    double hdrPQnor[length][width];

    double * hdrPQMaxMin = findMaxAndMinOfArray(hdrPQ, length, width);
    double hdrPQMax = hdrPQMaxMin[0];
    double hdrPQMin = hdrPQMaxMin[1];

    for (int i = 0; i < length; i++)
        for (int j = 0; j < width; j++) {
            hdrPQnor[i][j] = 255 * (hdrPQ[i][j] - hdrPQMin) / (hdrPQMax - hdrPQMin) + 1;
        }

    for (int i = 0; i < length; i++)
        for (int j = 0; j < width; j++) {
            hdrPQnor[i][j] = hdrPQnor[i][j] * 0.35 + labels[i][j] * 0.65;
        }

    double labels_DoG[length][width] ;
    double ** imfilterArray = imfilter(hdrPQnor, DoGfilter, length, width);
    for (int i = 0; i < length; i++){
        for (int j = 0; j < width; j++) {
            labels_DoG[i][j] = labels[i][j] + 3.0 * imfilterArray[i][j];
        }
    }
    return 0;


}

double **imfilter(double ** hdrPQnor, double ** doGfilter, int length, int width) {
    return filterDouble2DWithConv(hdrPQnor,doGfilter, length, width);
}

double **filterDouble2DWithConv(double **a, double **h, int length, int width) {
    int padSize[2] = {4,4};
    double ** retArray;
    h = rot90(h,2);
    a = padarray_algo(a,padSize, length, width);
    retArray = conv2(a,h);


    return retArray;
}

double **padarray_algo(double **a, int padSize[2], int length, int width) {
    double aSize[2]= {length, width};
    int ** aIdx = getPaddingIndices(aSize, padSize, length, width);
    double ** b = RangeMatrix(a,aIdx);
    return b;
}

double **RangeMatrix(double **a, int **aIdx) {
    int aIdx0_length = sizeof(aIdx[0])/sizeof(aIdx[0][0]);
    double retArray[aIdx0_length][aIdx0_length];
    for (int i = 0; i < retArray.length-1; i++){
        for (int j = 0; j < retArray[i].length-1; j++){
            int lengthAxis = aIdx[0][i];
            int widthAxis = aIdx[1][j];
            retArray[i][j] = a[lengthAxis-1][widthAxis-1];
        }
    }
    return retArray;
}

int **getPaddingIndices(double *aSize, int padSize[2], int length, int width) {
    int numDims = sizeof(padSize)/ sizeof(padSize[0]);
    int **idx;
    idx[0] = malloc((length + (4 * 2)) * sizeof(int));
    idx[1] = malloc((width + (4 * 2)) * sizeof(int));
    for (int k = 0; k< numDims; k++){
        double M = aSize[k];
        int p = padSize[k];
        int * onesVector = ones(p);
        int ones_length = sizeof(onesVector)/sizeof(onesVector[0]);
        int loopRange = (int) (ones_length + M + ones_length);
        int count = 1;
        for (int j = 0; j< loopRange; j++){
            if (j < ones_length){
                idx[k][j] = 1;
            }
            else if ((j >= ones_length) && (j <= (loopRange - ones_length-1)))
            {
                idx[k][j] = count;
                count += 1;
            }
            else if (j > (loopRange - ones_length-1))
            {
                idx[k][j] = (int) M;
            }
        }
    }
    return idx;
}

int *ones(int p) {
    int *retArray;
    for (int i = 0; i< p; i++){
        retArray[i] = 1;
    }
    return retArray;
}

double **rot90(double **arr1, int times) {
    double ** arr2;

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            arr2[9 - 1 - j][i] = arr1[i][j];

    times -= 1;

    if (times > 0) {
        rot90(arr2, times);
    }
    return arr2;
}

double *findMaxAndMinOfArray(double **array, int length, int width) {
    double max = array[0][0];
    double min = array[0][0];
    double * ret;
    for (int i = 0; i < length; i++){
        for (int j = 0; j < width; j++) {
            if (array[i][j] > max) {
                ret[0] = array[i][j];
            } else if (array[i][j] < min) {
                ret[1] = array[i][j];
            }
        }
    }

    return ret;
}

double **fspecial(int window, double sigma) {
    double p2[2] = {window,window};  // siz
    double p3 = sigma;;    // std
    double siz   = (p2[1]-1)/2;

    double x[9][9] = {
            {-4,-3,-2,-1,0,1,2,3,4},
            {-4,-3,-2,-1,0,1,2,3,4},
            {-4,-3,-2,-1,0,1,2,3,4},
            {-4,-3,-2,-1,0,1,2,3,4},
            {-4,-3,-2,-1,0,1,2,3,4},
            {-4,-3,-2,-1,0,1,2,3,4},
            {-4,-3,-2,-1,0,1,2,3,4},
            {-4,-3,-2,-1,0,1,2,3,4},
            {-4,-3,-2,-1,0,1,2,3,4}};
    double y[9][9] = {
            {-4 ,-4 ,-4 ,-4 ,-4 ,-4 ,-4 ,-4 ,-4 },
            {-3 ,-3 ,-3 ,-3 ,-3 ,-3 ,-3 ,-3 ,-3 },
            {-2 ,-2 ,-2 ,-2 ,-2 ,-2 ,-2 ,-2 ,-2 },
            {-1 ,-1 ,-1 ,-1 ,-1 ,-1 ,-1 ,-1 ,-1 },
            {0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  },
            {1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  },
            {2  ,2  ,2  ,2  ,2  ,2  ,2  ,2  ,2  },
            {3  ,3  ,3  ,3  ,3  ,3  ,3  ,3  ,3  },
            {4  ,4  ,4  ,4  ,4  ,4  ,4  ,4  ,4  }};

    double arg[9][9] ;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            arg[i][j] = -((x[i][j]*x[i][j]) + (y[i][j] *y[i][j]))/(2*p3*p3);
    double ** h;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            h[i][j] = exp(arg[i][j]);

    double hMax = h[0][0];
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (h[i][j] > hMax)
                hMax = h[i][j];
    double sumh = 0;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++) {
            if (h[i][j] < ((pow((double)2, -52)) * hMax))
                h[i][j] = 0;
            sumh += h[i][j];
        }

    if (sumh != 0){
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                h[i][j] = (h[i][j]/sumh);
    }
    return h;
}

//Start of QuantizeNL_Float

double **QuantizeNL_float(double **y, double nclust, double **lum, int length, int width) {

    double** labels = (double**)malloc(length * sizeof(double*));

    int numelLum = numel(lum, length, width);

    double* lum1D;
    lum1D = reshape1D(lum, length, width, numelLum);
    size_t lum1D_n = sizeof(lum1D) / sizeof(lum1D[0]);
    qsort(lum1D, lum1D_n, sizeof(double), compare);

    double* y1D;
    y1D = reshape1D(y, length, width, numel(y, length, width));
    size_t y1D_n = sizeof(y1D) / sizeof(y1D[0]);
    qsort(y1D, y1D_n, sizeof(double), compare);

    int y1DLength = numel(y, length, width);
    double *edges = {0, y1DLength};
    double errorsPow[y1DLength];
    double meanOfY = mean(y1D, y1DLength);
    for (int i = 0; i < y1DLength; i++){
        errorsPow[i] = pow((y1D[i]-meanOfY),2);
    }
    double* errors = sum(errorsPow, y1DLength);

    double* s_data = cumsum(y1D, y1DLength);
    double* y1DPow = powArray(y1D, y1DLength);
    double* ss_data = cumsum(y1DPow, y1DLength);

    for (int i=0; i<nclust-1; i++)
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
                double lum1 = median(lum1Range, (int)(sizeof(lum1Range) / sizeof(lum1Range[0])));
                double lum1log = log10(lum1);
                double tvilum1 = tvi(lum1log);
                double delta1 = pow(10, tvilum1);

                double * lum2Range = RangeArray(lum1D, (k + m +1-1), (k + n-1));
                double lum2 = median(lum2Range,(int)(sizeof(lum2Range) / sizeof(lum2Range[0])));
                double lum2log = log10(lum2);
                double tvilum2 = tvi(lum2log);
                double delta2 = pow(10, tvilum2);
                double value = delta1/(delta1+delta2) * (lum1D[(int) (k+n -1)] - lum1D[(int) (k)]) + lum1D[(int) (k)];
                double * absValue = doubleMinusArray(value, RangeArray(lum1D, (int) (k), (int) (k+n-1)));
                double * absMatrixValue = absMatrix(absValue);

                double * values = min(absMatrixValue);
                double lum_loc = values[1];
                m = lum_loc;
                sm = s_data[(int) (k + m)];
                if (k >= 1)
                    sm = sm - s_data[(int) k-1];
                ssm = ss_data[(int) (k + m)];
                if (k >= 1)
                    ssm = ssm - ss_data[(int) k-1];
                e1 = ssm - pow(sm, 2.0) / (m+1);
                e2 = ssn - ssm - pow((sn - sm), 2.0) / (n - (m+1));
                edges = AppendEdges(RangeArray(edges,0, idx),(int)(k+m+1),RangeArray(edges,  (idx+1), sizeof(edges)/sizeof(edges[0]) - 1));
                errors = AppendErrors(RangeArray(errors,0, (int) (idx-1)),e1,e2,RangeArray(errors, (int) (idx+1),sizeof(errors)/sizeof(errors[0]) - 1));
                break;
            }
            else{
                if(e1 > e2)
                    m = m-floor(n/d);
                else if(e1 < e2)
                    m = m+floor(n/d);
            }
        }
    }

    double mdata[(int) nclust];
    double * lum01d = reshape1D(lum, length, width,numel(lum, length, width));
    mdata[0] = min(lum01d)[0];
    mdata[(int) nclust - 1] = max(lum01d,numel(lum, length, width))[0];
    double ** ind;
    for (int i=1; i<=nclust-1; i++) {
        if (lum1D[(int) edges[i]-1] == lum1D[(int) edges[i + 1]-1]) {
            ind = matrixBoolean(lum, lum1D[(int) edges[i]], length, width); //(lum0==lum[(int) edges[i]]);
            double * lum0Ind = getIndexValuesToArray(lum, ind, length, width);
            mdata[i] = mean(lum0Ind, sizeof (lum0Ind)) + pow((double)2,-52) * i;
        } else {
            ind = matrixBoolean1(lum, lum1D[(int) edges[i]-1], lum1D[(int) edges[i + 1]-1], length, width);
            double * lum0Ind = getIndexValuesToArray(lum, ind, length, width);

            mdata[i] = mean(lum0Ind, length*width);
        }
    }
    double * labels_mdata = linspace(1,256,(int)nclust);
    labels = (double **) interp1(mdata, labels_mdata, lum, length, width); //Done in main

    return labels;
}

double **interp1(double X[], double *V, double **Xq,int length,int width) {
    double **Vout;
    size_t X_n = sizeof(X) / sizeof(X[0]);
    qsort(X, X_n, sizeof(double), compare);
    size_t V_n = sizeof(V) / sizeof(V[0]);
    qsort(V, V_n, sizeof(double), compare);
    size_t Xq_length = sizeof(Xq) / sizeof(Xq[0]);

    for (int i = 0; i < Xq_length; i++) {
        Vout[i] = linearInterpolation(X,V,Xq[i]);
    }
    return Vout;
}

double *linearInterpolation(double *x, double *y, double *values) {
    int values_length = sizeof(values)/sizeof(values[0]);
    double interpolatedValues[values_length];
    int n = sizeof(x)/sizeof(x[0]);
    for (int i = 0; i < values_length; i++) {
        // Find the index of the x value that is closest to the value to interpolate
        if (values[i] < x[0]) {
            interpolatedValues[i] = y[0];
        } else if (values[i] > x[n - 1]) {
            interpolatedValues[i] = y[n - 1];
        } else {
            int j = 1;
            while (j < n - 1 && x[j] < values[i]) {
                j++;
            }
            // Perform linear interpolation using the two closest data points
            double x1 = x[j - 1];
            double y1 = y[j - 1];
            double x2 = x[j];
            double y2 = y[j];
            double slope = (y2 - y1) / (x2 - x1);
            double interpolatedValue = y1 + slope * (values[i] - x1);

            interpolatedValues[i] = interpolatedValue;
        }
    }
    return interpolatedValues;
}

double *min(double *absMatrix) {
    int length =  sizeof(absMatrix) / sizeof(absMatrix[0]);
    double min = absMatrix[0];
    double index = 0;
    for (int i = 0; i < length; i++)
    {
        if (min > absMatrix[i])
        {
            min = absMatrix[i];
            index = i;
        }
    }
    double ret[2] = {min, index};
    return ret;
}
double tvi(double intensity) {
    double threshold;
    int idx = find(intensity, 0 ,4,-3.94,0);
    if (idx == 1)
    {
        threshold = -2.86;
    }
    idx = find(intensity,3,0,-3.94,-1.44);
    if (idx == 1)
    {
        double value =(0.405 * intensity + 1.6);
        threshold = pow(value,2.18) - 2.86;
    }
    idx = find(intensity,3,0,-1.44,-0.0184);
    if (idx == 1)
    {
        threshold = intensity - 0.395;
    }
    idx = find(intensity, 3,0,-0.0184,1.9);
    if (idx == 1)
    {
        double value =0.249 * intensity + 0.65;
        threshold = pow(value,2.7) - 0.72;
    }
    idx = find(intensity,3,4, 1.9,0);
    if (idx == 1)
    {
        threshold = intensity - 1.255;
    }
    threshold = threshold - 0.95;
    return threshold;
}

int find(double intensity, double check1, double check2, double value1, double value2) {
    int indexes;
    for (int i = 0; i < 1; i++) {
        if (check1 == 0 && check2 == 4) {
            if (intensity < value1) {
                indexes = 1;
            }
        }
        if (check1 == 3 && check2 == 0) {
            if (intensity >= value1 && intensity < value2) {
                indexes = 1;
            }
        }
        if (check1 == 3 && check2 == 4) {
            if (intensity >= value1) {
                indexes = 1;
            }
        }
    }
    return indexes;
}
int compare (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}


double *linspace(int min, int max, int points) {
    double* retArray = (double*)malloc(points * sizeof(double));
    int i;
    for (i = 0; i < points; i++) {
        retArray[i] = min + i * (max - min) / (points - 1);
    }
    return retArray;
}

double *getIndexValuesToArray(double **lum0, double **ind, int rows, int cols) {
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
double **matrixBoolean(double** array, double valueToCheck, int length, int width) {
    double** retArray = (double**)malloc(length * sizeof(double*));
    int i, j;
    for (i = 0; i < length; i++) {
        retArray[i] = (double*)malloc(width * sizeof(double));
        for (j = 0; j < width; j++) {
            if (array[i][j] == valueToCheck) {
                retArray[i][j] = 1;
            } else {
                retArray[i][j] = 0;
            }
        }
    }
    return retArray;
}

double **matrixBoolean1(double** array, double valueToCheck1, double valueToCheck2, int rows, int cols) {
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

double *AppendEdges(double *rangeArray, int value, double *rangeArray1) {
    int length1 = sizeof(rangeArray)/ sizeof(rangeArray[0]);
    int length2 = sizeof(rangeArray1)/ sizeof(rangeArray1[0]);
    int resultLength = length1 + length2 + 1;
    double* result = (double*)malloc(resultLength * sizeof(double));
    memcpy(result, rangeArray, length1 * sizeof(double));
    result[length1] = value;
    memcpy(result + length1 + 1, rangeArray1, length2 * sizeof(double));
    return result;
}

double *AppendErrors(double *rangeArray, double e1, double e2, double *rangeArray1) {
    int length1 = sizeof(rangeArray)/ sizeof(rangeArray[0]);
    int length2 = sizeof(rangeArray1)/ sizeof(rangeArray1[0]);
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

double *absMatrix(double *absValue) {
    int length = sizeof(absValue) / sizeof(absValue[0]);
    for (int i = 0; i < length; i++) {
        absValue[i] = fabs(absValue[i]);
    }
    return absValue;
}

double *doubleMinusArray(double value, double *rangeArray) {
    int length =  sizeof(rangeArray) / sizeof(rangeArray[0]);
    for (int i = 0; i < length; i++) {
        rangeArray[i] = value - rangeArray[i];
    }
    return rangeArray;
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


double median(double * array, int length) {
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

double maxQuart(double *hdrImg, double percentile, int length) {
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

void flatten3DArray(double ***arr3D, double *arr1D, int length, int width, int depth) {
    int index = 0;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < depth; k++) {
                arr1D[index++] = arr3D[i][j][k];
            }
        }
    }
}