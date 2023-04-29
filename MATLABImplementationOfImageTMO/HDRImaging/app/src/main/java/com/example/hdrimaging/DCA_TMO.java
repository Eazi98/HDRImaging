package com.example.hdrimaging;

import static java.lang.Math.abs;
import static java.lang.Math.atan;
import static java.lang.Math.exp;
import static java.lang.Math.floor;
import static java.lang.Math.log10;
import static java.lang.Math.max;
import static java.lang.Math.round;
import static java.util.Arrays.*;
import static java.util.Arrays.sort;


import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;


public class DCA_TMO extends Thread{

    public double[][] hdrLum;
    public double[][] hdrPQ;
    private int length;
    private int width;
    private static final double eps = Math.pow(2,-52);

    public double[][][] DCA_TMO_Processing(double[][][] hdrImg, int length1, int width1)
    {
        length = length1;
        width = width1;
        double maxhdr;
        double minhdr;
        double hdrMaxValue;
        double[][][] ldrImg = {};

        //set parameters
        double K = 55;
//      pre-processing
        double[] hdrOneD = stream(hdrImg)
                .flatMap(Arrays::stream)
                .flatMapToDouble(Arrays::stream)
                .toArray();

        maxhdr = MaxQuart(hdrOneD, 0.99);
        minhdr = MaxQuart(hdrOneD, 0.01);


        for (int i = 0; i < hdrImg.length; i++)
            for (int j = 0; j < hdrImg[i].length; j++)
                for (int k = 0; k < hdrImg[i][j].length; k++){
                    if (hdrImg[i][j][k] > maxhdr){
                        hdrImg[i][j][k] = maxhdr;
                    }else if(hdrImg[i][j][k] < minhdr){
                        hdrImg[i][j][k] = minhdr;
                    }
                }
//        tone map using clustering method
        hdrLum = new double[length][width];
        double[][] hdrLum1 = new double[length][width];
        hdrPQ = new double[length][width];

        //get max value for hdrLum1 = hdrLum./max(hdrImg(:));  max(hdrImg(:)) value
        hdrMaxValue = hdrImg[0][0][0];
        for (int i = 0; i < hdrImg.length; i++)
            for (int j = 0; j < hdrImg[i].length; j++)
                for (int k = 0; k < hdrImg[i][j].length; k++){
                    if (hdrImg[i][j][k] > hdrMaxValue)
                        hdrMaxValue = hdrImg[i][j][k];
                }

        for (int i = 0; i < hdrImg.length; i++)
            for (int j = 0; j < hdrImg[i].length; j++){
                hdrLum[i][j] = 0.2126 * hdrImg[i][j][0] + 0.7152 * hdrImg[i][j][1]+ 0.0722 * hdrImg[i][j][2];
                hdrLum1[i][j] = (hdrLum[i][j])/ hdrMaxValue;
                hdrPQ[i][j] = Math.pow((Math.pow(hdrLum1[i][j],((double)1305/(double)8192)) * ((double)2413/(double)128)+ ((double)107/(double)128)) / (Math.pow(hdrLum1[i][j],((double)1305 /(double)8192)) *((double)2392/(double)128)+ ((double)1)), ((double)2523/(double)32));
            }

        double[][] labels = quantizeNL_float(hdrPQ, K, hdrLum);
//        %% local enhancemant using DoG
        double sigmaC = 0.5;
        double sigmaS = 0.8;
        double window = 9;

        double[][] gfilterC = fspecial(window, sigmaC);
        double[][] gfilterS = fspecial(window, sigmaS);
        double[][] DoGfilter = new double[(int) window][(int) window];
        for (int i = 0; i < DoGfilter.length; i++)
            for (int j = 0; j < DoGfilter[i].length; j++)
                DoGfilter[i][j] = (gfilterC[i][j] - gfilterS[i][j]);

        double[][] hdrPQnor = new double[length][width];
        double hdrPQMax = hdrPQ[0][0];
        double hdrPQMin = hdrPQ[0][0];
        for (double[] doubles : hdrPQ)
            for (double aDouble : doubles) {
                if (aDouble > hdrPQMax) {
                    hdrPQMax = aDouble;
                } else if (aDouble < hdrPQMin) {
                    hdrPQMin = aDouble;
                }
            }
        for (int i = 0; i < hdrImg.length; i++)
            for (int j = 0; j < hdrImg[i].length; j++) {
                hdrPQnor[i][j] = 255 * (hdrPQ[i][j] - hdrPQMin) / (hdrPQMax - hdrPQMin) + 1;
            }

//        hdrPQnor = 255 .* (hdrPQ - min(hdrPQ(:))) ./ (max(hdrPQ(:)) - min(hdrPQ(:))) + 1;
        for (int i = 0; i < hdrImg.length; i++)
            for (int j = 0; j < hdrImg[i].length; j++) {
                hdrPQnor[i][j] = hdrPQnor[i][j] * 0.35 + labels[i][j] * 0.65;
            }

        double[][] labels_DoG = new double[length][width];
        double[][] imfilterArray = imfilter(hdrPQnor, DoGfilter);
        for (int i = 0; i < labels_DoG.length; i++)
            for (int j = 0; j < labels_DoG[i].length; j++) {
                labels_DoG[i][j] = labels[i][j] + 3.0 * imfilterArray[i][j];
            }

        // color restoration
        double[][] s1 = new double[length][width];
        double minLabels_DoG = min2dArray(labels_DoG);
        double maxLabels_DoG = max2dArray(labels_DoG);

        s1 = array2dDivision(arrayMinusDouble(labels_DoG,minLabels_DoG),(maxLabels_DoG - minLabels_DoG));
//        s1 = (labels_DoG - min(labels_DoG(:))) ./ (max(labels_DoG(:)) - min(labels_DoG(:)));
        double[][] s = new double[length][width];
        double[][] atanS1 = new double[length][width];
        s = doubleMinus2dArray(1,atan2DArray(s1));
        s = min2dArrayOrScalar(s,0.5);
        double[][][] dividedArray = divide3dArray2dArray(hdrImg,hdrLum);
        double[][][] powArray = pow3d2d(dividedArray, s);
        double[][][] ldrImg_DoG = multiply3d2d(powArray, labels_DoG);
        double[] ldrImg_DoG1D = stream(ldrImg_DoG)
                .flatMap(Arrays::stream)
                .flatMapToDouble(Arrays::stream)
                .toArray();
        double maxx = MaxQuart(ldrImg_DoG1D, 0.99);
        double minn = MaxQuart(ldrImg_DoG1D, 0.01);
        if (maxx <255)
            if (max(ldrImg_DoG1D)[0] < 255)
                maxx = max(ldrImg_DoG1D)[0];
            else
                maxx = 255;
        if ( minn > 0)
            if (min(ldrImg_DoG1D)[0] > 0)
                minn = min(ldrImg_DoG1D)[0];
            else
                minn = 0;

        for (int i = 0; i < ldrImg_DoG.length; i++)
            for (int j = 0; j < ldrImg_DoG[i].length; j++)
                for (int k = 0; k < hdrImg[i][j].length; k++){
                    if (ldrImg_DoG[i][j][k] > maxx){
                        ldrImg_DoG[i][j][k] = maxx;
                    }else if(ldrImg_DoG[i][j][k] < minn){
                        ldrImg_DoG[i][j][k] = minn;
                    }
                }
        double[][][]minusedArray = array3dMinusDouble(ldrImg_DoG,minn);
        double[][][] multipliedArray = multiply3dDouble(255,minusedArray);
        ldrImg = divide3dDouble(multipliedArray,(maxx - minn));
        return ldrImg;
    }

    private double[][][] divide3dDouble(double[][][] array, double value) {
        double[][][] retArray = new double[array.length][array[0].length][array[0][0].length];
        for (int i = 0; i < array.length; i++)
            for (int j = 0; j < array[i].length; j++)
                for (int k = 0; k < array[i][j].length; k++)
                    retArray[i][j][k] = array[i][j][k] / value;
        return retArray;
    }

    private double[][][] multiply3dDouble(int value, double[][][] array) {
        double[][][] retArray = new double[array.length][array[0].length][array[0][0].length];
        for (int i = 0; i < array.length; i++)
            for (int j = 0; j < array[i].length; j++)
                for (int k = 0; k < array[i][j].length; k++)
                    retArray[i][j][k] = array[i][j][k] * value;
        return retArray;
    }

    private double[][][] array3dMinusDouble(double[][][] array, double minn) {
        double[][][] retArray = new double[array.length][array[0].length][array[0][0].length];
        for (int i = 0; i < array.length; i++)
            for (int j = 0; j < array[i].length; j++)
                for (int k = 0; k < array[i][j].length; k++)
                    retArray[i][j][k] = array[i][j][k] - minn;
        return retArray;
    }

    private double[][][] multiply3d2d(double[][][] array, double[][] multiplyBy) {
        double[][][] retArray = new double[array.length][array[0].length][array[0][0].length];
        for (int i = 0; i < array.length; i++)
            for (int j = 0; j < array[i].length; j++)
                for (int k = 0; k < array[0][0].length; k++)
                    retArray[i][j][k] = array[i][j][k] * multiplyBy[i][j];
        return retArray;
    }

    private double[][][] pow3d2d(double[][][] array, double[][] power) {
        double[][][] retArray = new double[array.length][array[0].length][array[0][0].length];
        for (int i = 0; i < array.length; i++)
            for (int j = 0; j < array[i].length; j++)
                for (int k = 0; k < array[0][0].length; k++)
                    retArray[i][j][k] = Math.pow(array[i][j][k],power[i][j]);
        return retArray;
    }

    private double[][][] divide3dArray2dArray(double[][][] array, double[][] divideBy) {
        double[][][] retArray = new double[array.length][array[0].length][array[0][0].length];
            for (int i = 0; i < array.length; i++)
                for (int j = 0; j < array[i].length; j++)
                    for (int k = 0; k < array[0][0].length; k++)
                        retArray[i][j][k] = array[i][j][k]/divideBy[i][j];
        return retArray;
    }

    private double[][] min2dArrayOrScalar(double[][] array, double value) {
        double[][] retArray = new double[array.length][array[0].length];
        for (int i = 0; i < array.length; i++)
            for (int j = 0; j < array[i].length; j++)
                if (retArray[i][j] < value)
                    retArray[i][j] = retArray[i][j];
                else{
                    retArray[i][j] = value;
                }
        return retArray;
    }

    private double[][] atan2DArray(double[][] array) {
        double[][] retArray = new double[array.length][array[0].length];
        for (int i = 0; i < array.length; i++)
            for (int j = 0; j < array[i].length; j++)
                retArray[i][j] = atan(array[i][j]);
        return  retArray;
    }

    private double[][] array2dDivision(double[][] array, double value) {
        double[][] retArray = new double[array.length][array[0].length];
        for (int i = 0; i < array.length; i++)
            for (int j = 0; j < array[i].length; j++)
                retArray[i][j] = array[i][j]/ value;
        return retArray;
    }

    private double min2dArray(double[][] array){
        double arrayMin = array[0][0];
        for (double[] doubles : array)
            for (double aDouble : doubles) {
                if (aDouble < arrayMin) {
                    arrayMin = aDouble;
                }
            }
        return arrayMin;
    }
    private double max2dArray(double[][] array){
        double arrayMax = array[0][0];
        for (double[] doubles : array)
            for (double aDouble : doubles) {
                if (aDouble > arrayMax) {
                    arrayMax = aDouble;
                }
            }
        return arrayMax;
    }
    private double[][] imfilter(double[][] hdrPQnor, double[][] doGfilter) {
        double[] finalSize = {length, width};
        return filterDouble2DWithConv(hdrPQnor,doGfilter,finalSize);
    }

    private double[][] filterDouble2DWithConv(double[][] a, double[][] h, double[] finalSize){
        int[] padSize = new int[] {4,4};
        double[][] retArray =  new double[length][width];
        h = rot90(a,2);
        double[] imageSize = {length, width};
        double[] sizeh = new double[] {h.length,h.length};
        double[] nonSymmetricPadShift = numMinusArray(1,mod(sizeh,2));
        a = padarray_algo(a,padSize);
        retArray = conv2(a,h);


        return retArray;
    }

    private double[][] conv2(double[][] a, double[][] h) {
        double[][] retArray = new double[length][width];
        //https://towardsdatascience.com/intuitively-understanding-convolutions-for-deep-learning-1f6f42faee1
        //TODO:Check values
        retArray = Convolution.convolution2DPadded(a,length,width,h,h.length,h.length);
        //https://homepages.inf.ed.ac.uk/rbf/HIPR2/flatjavasrc/Convolution.java
        return retArray;
    }

    private double[][] padarray_algo(double[][] a, int[] padSize) {
        double[] aSize = {length, width};
        int[][] aIdx = getPaddingIndices(aSize, padSize);
        double[][] b = RangeMatrix(a,aIdx);
        return b;
    }

    private double[][] RangeMatrix(double[][] a, int[][] aIdx) {
        int lengthArray = aIdx.length;
        int widthArray = aIdx[0].length;
        double[][] retArray = new double[aIdx[0].length][aIdx[1].length];
        for (int i = 0; i < retArray.length-1; i++){
            for (int j = 0; j < retArray[i].length-1; j++){
                int lengthAxis = aIdx[0][i];
                int widthAxis = aIdx[1][j];
                retArray[i][j] = a[lengthAxis-1][widthAxis-1];
            }
        }
        return retArray;
    }

    private int[][] getPaddingIndices(double[] aSize, int[] padSize) {
        int numDims = padSize.length;
        int[][] idx = {new int[length+(padSize[0]*2)],new int[width+(padSize[0]*2)]};
        for (int k = 0; k< numDims; k++){
            double M = aSize[k];
            int p = padSize[k];
            int[] onesVector = ones(p);
            int loopRange = (int) (onesVector.length + M + onesVector.length);
            int count = 1;
            for (int j = 0; j< loopRange; j++){
                if (j < onesVector.length){
                    idx[k][j] = 1;
                }
                else if ((j >= onesVector.length) && (j <= (loopRange - onesVector.length-1)))
                {
                    idx[k][j] = count;
                    count += 1;
                }
                else if (j > (loopRange - onesVector.length-1))
                {
                    idx[k][j] = (int) M;
                }
            }

        }
        return idx;
    }

    private int[] ones(int p) {
        int[] retArray = new int[p];
        for (int i = 0; i< p; i++){
            retArray[i] = 1;
        }
        return retArray;
    }

    private double[] numMinusArray(int num, double[] mod) {
        double[] retArray = new double[mod.length];
        for (int i = 0; i< mod.length; i++){
            retArray[i] = num - mod[i];
        }
        return retArray;
    }

    private double[] mod(double[] doubles, int y) {
        double x1 = doubles[0];
        double x2 = doubles[1];
        double[] retArray = new double[doubles.length];
        for (int i= 0; i < doubles.length; i++)
            retArray[i] = doubles[i]- floor(doubles[i]/y)*y;

        return retArray;

    }

    private double[][] rot90(double[][] arr1, int times) {
        int d = arr1.length;
        double[][] arr2 = new double[d][d];

        for (int i = 0; i < d; i++)
            for (int j = 0; j < d; j++)
                arr2[d - 1 - j][i] = arr1[i][j];

        times -= 1;

        if (times > 0) {
            rot90(arr2, times);
        }
        return arr2;
    }

    private double[][] quantizeNL_float(double[][] y, double nclust, double[][] lum) {

        double[][] lum0 = lum;

        int numelLum =numel(lum);

        double[] lum1D = reshape1D(lum, numelLum);
        sort(lum1D);

        double[] y1D = reshape1D(y, numel(y));
        sort(y1D);

        double[] edges = new double[]{0, y1D.length};
        double[] errorsPow = new double[y1D.length];
        double meanOfY = mean(y1D);
        for (int i = 0; i < y1D.length; i++){
            errorsPow[i] = Math.pow((y1D[i]-meanOfY),2);
            }
        double[] errors = sum(errorsPow);

        sort(y1D);
        double[] s_data = cumsum(y1D);
        sort(y1D);
        double[] y1DPow = pow(y1D);
        double[] ss_data = cumsum(y1DPow);


        for (int i=0; i<nclust-1; i++)
        {
            double[] maxError = max(errors);
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
            while(true)
            {
                double sm = s_data[(int) (k+m)-1];
                if(k>=1)
                    sm = sm - s_data[(int) k-1];
                double ssm = ss_data[(int) (k+m)-1];
                if(k>=1)
                    ssm = ssm - ss_data[(int) k-1];
                double e1 = ssm - Math.pow(sm,2)/m;
                double e2 = ssn - ssm - Math.pow((sn - sm),2)/(n-m);
                d = 2 * d;
                if(abs(e1-e2) < 0.001 || d >= n) {

                    double[] lum1Range = RangeArray(lum1D, (int) (k+1-1), (int) (k + m-1));
                    double lum1 = median(lum1Range);
                    double lum1log = log10(lum1);
                    double tvilum1 = tvi(new double[]{lum1log});
                    double delta1 = Math.pow(10, tvilum1);

                    double[] lum2Range = RangeArray(lum1D, (int) (k + m +1-1), (int) (k + n-1));
                    double lum2 = median(lum2Range);
                    double lum2log = log10(lum2);
                    double tvilum2 = tvi(new double[]{lum2log});
                    double delta2 = Math.pow(10, tvilum2);
                    double value = delta1/(delta1+delta2) * (lum1D[(int) (k+n -1)] - lum1D[(int) (k)]) + lum1D[(int) (k)];
                    double[] absValue = doubleMinusArray(value, RangeArray(lum1D, (int) (k), (int) (k+n-1)));
                    double[] absMatrixValue = absMatrix(absValue);

                    double[] values = min(absMatrixValue);
                    double lum_loc = values[1];
                    m = lum_loc;
                    sm = s_data[(int) (k + m)];
                    if (k >= 1)
                        sm = sm - s_data[(int) k-1];
                    ssm = ss_data[(int) (k + m)];
                    if (k >= 1)
                        ssm = ssm - ss_data[(int) k-1];
                    e1 = ssm - Math.pow(sm, 2.0) / (m+1);
                    e2 = ssn - ssm - Math.pow((sn - sm), 2.0) / (n - (m+1));
                    edges = AppendEdges(RangeArray(edges,0, (int) idx),(int)(k+m+1),RangeArray(edges, (int) (idx+1), edges.length-1));
                    errors = AppendErrors(RangeArray(errors,0, (int) (idx-1)),e1,e2,RangeArray(errors, (int) (idx+1),errors.length-1));
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

        double[] mdata = new double[(int) nclust];
        double[] lum01d = reshape1D(lum0,numel(lum0));
        mdata[0] = min(lum01d)[0];
        mdata[mdata.length-1] = max(lum01d)[0];
        //TODO: Check mdata values
        double[][] ind = new double[length][width];
        for (int i=1; i<=nclust-1; i++) {
            if (lum1D[(int) edges[i]-1] == lum1D[(int) edges[i + 1]-1]) {
                ind = matrixBoolean(lum0, lum1D[(int) edges[i]]); //(lum0==lum[(int) edges[i]]);
                double[] lum0Ind = getIndexValuesToArray(lum0, ind);
                mdata[i] = mean(lum0Ind) + eps * i;
            } else {
                ind = matrixBoolean1(lum0, lum1D[(int) edges[i]-1], lum1D[(int) edges[i + 1]-1]);
                double[] lum0Ind = getIndexValuesToArray(lum0, ind);
                mdata[i] = mean(lum0Ind);
            }
        }
        double[] labels_mdata = linspace(1,256,(int)nclust);
        double[][] labels = interp1(mdata, labels_mdata, lum0); //Done in main

        return labels;
    }

    public double[][] interp1(double[] X, double[] V, double[][] Xq) {
        double[][] Vout = new double[length][width];
        sort(X);
        sort(V);
        for (int i = 0; i < Xq.length; i++) {
            Vout[i] = linearInterpolation(X,V,Xq[i]);
        }


        return Vout;
    }

    private double[][] to2dArray(double[] array1D) {
        double[][] retArray = new double[length][width];
        int pixelCounter = 0;
        for (int j = 0; j < length; j++) {
            for (int k = 0; k < width; k++) {
                retArray[j][k] = array1D[0];
                pixelCounter += 1;
            }
        }
        return retArray;
    }

    private static double[] linearInterpolation(double[] x, double[] y, double[] values) {
        double[] interpolatedValues = new double[values.length];

        for (int i = 0; i < values.length; i++) {
            // Find the index of the x value that is closest to the value to interpolate
            int j = 1;
            while (j < x.length - 1 && x[j] < values[i]) {
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

        return interpolatedValues;
    }

    public static double[] linspace(double min, double max, int points) {
        double[] retArray = new double[points];
        for (int i = 0; i < points; i++){
            retArray[i] = min + i * (max - min) / (points - 1);
        }
        return retArray;
    }

    //TODO: CHECK if this is correct
    private double[] getIndexValuesToArray(double[][] lum0, double[][] ind) {
        List<Double> retArray = new ArrayList<>();
        for (int i = 0; i < ind.length; i++)
            for (int j = 1; j < ind[i].length; j++)
                if (ind[i][j] == 1)
                    retArray.add(lum0[i][j]);
        return retArray.stream().mapToDouble(Double::doubleValue).toArray();
    }

    private double[][] matrixBoolean(double[][] array, double valueToCheck) {
        double[][] retArray = new double[length][width];
        for (int i = 0; i < array.length-1; i++) {
            for (int j = 1; j < array[i].length-1; j++) {
                if (array[i][j] == valueToCheck) {
                    retArray[i][j] = 1;
                }
            }

        }
        return retArray;
    }

    private double[][] matrixBoolean1(double[][] array, double valueToCheck1,double valueToCheck2) {
        double[][] retArray = new double[length][width];
        for (int i = 0; i < array.length-1; i++) {
            for (int j = 0; j < array[i].length-1; j++) {
                if (array[i][j] > valueToCheck1 && array[i][j] <= valueToCheck2) {
                    retArray[i][j] = 1;
                }
            }

        }
        return retArray;
    }

    private double[][] matrixBoolean2(double[][] array, double valueToCheck1,double valueToCheck2) {
        double[][] retArray = new double[length][width];
        for (int i = 0; i < array.length-1; i++) {
            for (int j = 0; j < array[i].length-1; j++) {
                if (array[i][j] < valueToCheck1 || array[i][j] > valueToCheck2) {
                    retArray[i][j] = 1;
                }
            }

        }
        return retArray;
    }
    private double[] AppendEdges(double[] rangeArray, double value, double[] rangeArray1) {
        int arraySize = rangeArray.length + 1 + rangeArray1.length;
//        double[] output = new double[arraySize];
//        for (int i = 0; i < output.length; i++)
//        {
//            if (i <= rangeArray.length)
//                output[i] = rangeArray[i];
//            if (i >rangeArray.length && i <= rangeArray.length+1)
//                output[i] = value;
//            if (i >rangeArray.length+1){
//                output[i] = value;
//            }
//
//        }
//        return output;
        double[] result = Arrays.copyOf(rangeArray,rangeArray.length+rangeArray1.length+1);
        result[rangeArray.length]=value;
        System.arraycopy(rangeArray1,0,result,rangeArray.length+1,rangeArray1.length);
        return result;
    }

    private double[] AppendErrors(double[] rangeArray, double e1, double e2, double[] rangeArray1) {
//        int arraySize = rangeArray.length + 1 + rangeArray1.length;
//        double[] output = new double[arraySize];
//        for (int i = 0; i < output.length; i++)
//        {
//            if (i <= rangeArray.length)
//                output[i] = rangeArray[i];
//            if (i >rangeArray.length && i <= rangeArray.length+1)
//                output[i] = value;
//            if (i >rangeArray.length+1)
//
//        }
        double[] result = Arrays.copyOf(rangeArray,rangeArray.length+rangeArray1.length+2);
        result[rangeArray.length]=e1;
        result[rangeArray.length+1]=e2;
        System.arraycopy(rangeArray1,0,result,rangeArray.length+2,rangeArray1.length);
        return result;
    }

    private double[] min(double[] absMatrix) {
        double min = absMatrix[0];
        double index = 0;
        for (int i = 0; i < absMatrix.length; i++)
        {
            if (min > absMatrix[i])
            {
                min = absMatrix[i];
                index = i;
            }
        }
        return new double[]{min, index};
    }

    private double[] absMatrix(double[] absValue) {
        for (int i = 0; i < absValue.length; i++)
            absValue[i] = abs(absValue[i]);
        return absValue;
    }

    private double[] doubleMinusArray(double value, double[] rangeArray) {
        for (int i = 0; i < rangeArray.length; i++)
            rangeArray[i] = value - rangeArray[i];
        return rangeArray;
    }

    private double[][] arrayMinusDouble(double[][] rangeArray, double value) {
        double[][] retArray = new double[rangeArray.length][rangeArray[0].length];
        for (int i = 0; i < rangeArray.length; i++)
            for (int j = 0; j < rangeArray[i].length; j++)
                retArray[i][j] = rangeArray[i][j] - value;
        return retArray;
    }
    private double[][] doubleMinus2dArray(double value,double[][] rangeArray) {
        double[][] retArray = new double[rangeArray.length][rangeArray[0].length];
        for (int i = 0; i < rangeArray.length; i++)
            for (int j = 0; j < rangeArray[i].length; j++)
                retArray[i][j] = value - rangeArray[i][j] ;
        return retArray;
    }

    private double tvi(double[] intensity) {
        double[] threshold= new double[intensity.length];
        ArrayList<Integer> idx = new ArrayList<>();
        idx = find(intensity, 0 ,4,-3.94,0);
        for (int i = 0; i < idx.size(); i++) {
            {
                threshold[idx.get(i)] = -2.86;
            }
        }
        idx = find(intensity,3,0,-3.94,-1.44);
        for (int i = 0; i < idx.size(); i++) {
            {
                double value =(0.405 * intensity[idx.get(i)] + 1.6);
                threshold[idx.get(i)] = Math.pow(value,2.18) - 2.86;
            }
        }

        idx = find(intensity,3,0,-1.44,-0.0184);
        for (int i = 0; i < idx.size(); i++) {
            {
                threshold[idx.get(i)] = intensity[idx.get(i)] - 0.395;
            }
        }

        idx = find(intensity, 3,0,-0.0184,1.9);
        for (int i = 0; i < idx.size(); i++) {
            {
                double value =0.249 * intensity[idx.get(i)] + 0.65;
                threshold[idx.get(i)] = Math.pow(value,2.7) - 0.72;
            }
        }

        idx = find(intensity,3,4, 1.9,0);
        for (int i = 0; i < idx.size(); i++) {
            {
                threshold[idx.get(i)] = intensity[idx.get(i)] - 1.255;
            }
        }


        for (int i = 0; i < threshold.length; i++) {
            {
                threshold[i] = threshold[i] - 0.95;
            }
        }
        return threshold[0];
    }
    private ArrayList<Integer> find(double[] intensity,double check1,double check2, double value1,double value2) {
        // 0 < , 1 >, 2 <=, 3 >=, 4 nulll
        ArrayList<Integer> indexes = new ArrayList<>();
        for (int i = 0; i < intensity.length; i++) {
            if (check1 == 0 && check2 == 4) {
                if (intensity[i] < value1) {
                    indexes.add(i);
                }
            }
            if (check1 == 3 && check2 == 0) {
                if (intensity[i] >= value1 && intensity[i] < value2) {
                    indexes.add(i);
                }
            }
            if (check1 == 3 && check2 == 4) {
                if (intensity[i] >= value1) {
                    indexes.add(i);
                }
            }
        }
        return indexes;
    }
    private double[] RangeArray(double[] lum, int indexStart, int indexEnd) {
        int range = indexEnd - indexStart;
        double[] rangeArray = new double[range+1];
        int j = indexStart;
        for (int i = 0; i <= range; i++) {
            if (j <= indexEnd) {
                rangeArray[i] = lum[j++];
            }
        }
        return rangeArray;
    }
    private double[] max(double[] array){
        double max = array[0];
        int index = 0;
        for (int i = 0; i < array.length; i++)
        {
            if (max < array[i])
            {
                max = array[i];
                index = i;
            }
        }
        return new double[]{max, index};
    }
    private double[][] fspecial(double window, double sigma){
        double[] p2 = {window,window};  // siz
        double p3 = sigma;;    // std
        double siz   = (p2[1]-1)/2;

        double x[][] = {
                {-4,-3,-2,-1,0,1,2,3,4},
                {-4,-3,-2,-1,0,1,2,3,4},
                {-4,-3,-2,-1,0,1,2,3,4},
                {-4,-3,-2,-1,0,1,2,3,4},
                {-4,-3,-2,-1,0,1,2,3,4},
                {-4,-3,-2,-1,0,1,2,3,4},
                {-4,-3,-2,-1,0,1,2,3,4},
                {-4,-3,-2,-1,0,1,2,3,4},
                {-4,-3,-2,-1,0,1,2,3,4},};
        double y[][] = {
                {-4 ,-4 ,-4 ,-4 ,-4 ,-4 ,-4 ,-4 ,-4 },
                {-3 ,-3 ,-3 ,-3 ,-3 ,-3 ,-3 ,-3 ,-3 },
                {-2 ,-2 ,-2 ,-2 ,-2 ,-2 ,-2 ,-2 ,-2 },
                {-1 ,-1 ,-1 ,-1 ,-1 ,-1 ,-1 ,-1 ,-1 },
                {0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  },
                {1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  ,1  },
                {2  ,2  ,2  ,2  ,2  ,2  ,2  ,2  ,2  },
                {3  ,3  ,3  ,3  ,3  ,3  ,3  ,3  ,3  },
                {4  ,4  ,4  ,4  ,4  ,4  ,4  ,4  ,4  },};
        double[][] arg = new double[(int) window][(int) window];
        for (int i = 0; i < x.length; i++)
            for (int j = 0; j < x[i].length; j++)
                arg[i][j] = -((x[i][j]*x[i][j]) + (y[i][j] *y[i][j]))/(2*p3*p3);
        double[][]h    = new double[(int) window][(int) window];
        for (int i = 0; i < arg.length; i++)
            for (int j = 0; j < arg[i].length; j++)
                h[i][j] = exp(arg[i][j]);

        double hMax = h[0][0];
        for (int i = 0; i < h.length; i++)
            for (int j = 0; j < h[i].length; j++)
                if (h[i][j] > hMax)
                    hMax = h[i][j];
        double sumh = 0;
        for (int i = 0; i < h.length; i++)
            for (int j = 0; j < h[i].length; j++) {
                if (h[i][j] < (eps * hMax))
                    h[i][j] = 0;
                sumh += h[i][j];
            }

        if (sumh != 0){
            for (int i = 0; i < h.length; i++)
                for (int j = 0; j < h[i].length; j++)
                    h[i][j] = (h[i][j]/sumh);
        }
        return h;
    }
    private double MaxQuart(double[] hdrImg, double percentile){

        if(percentile > 1.0)
            percentile = 1.0;

        if(percentile < 0.0)
            percentile = 0.0;

        double[] sizeVariables = size(hdrImg);
        double n = sizeVariables[0];
        double m = sizeVariables[1];

        sort(hdrImg);
        double index = round(n * m * percentile);
        double[] maxcheck = {index, 1};
        index = max(maxcheck)[0];
        double ret = hdrImg[(int) index];
        return ret;
    }
    private double[] size(double[] hdrImg){
        double n = hdrImg.length;
        double m = 1;
        double size[] = {n,m};
        return size;
    }
    private int numel(double[][] array){
        int num = 0;
        for (int i = 0; i < array.length; i++)
            for (int j = 0; j < array[i].length; j++) {
                num +=1;
            }
        return num;
    }
    private double[] reshape1D(double[][] array, int numberEle){
        double retArray[] = new double[numberEle];
        int index = 0;
        for (int i = 0; i < array.length; i++)
            for (int j = 0; j < array[i].length; j++) {
                retArray[index] = array[i][j];
                index +=1;
            }
        return retArray;
    }
    private double mean(double[] array) {
        double sum = sum(array)[0];
        return (double) sum / array.length;
    }
    private double[] sum(double[] array) {
        double sum = 0;
        for (double value : array) {
            sum += value;
        }
        return new double[] {sum};
    }
    private double[] cumsum(double[] array){
        double[] retArray = new double[array.length];
        double sum = 0;
        for (int i = 0; i < array.length; i++) {

            // find sum
            sum += array[i];

            // replace
            retArray[i] = sum;
        }
        return retArray;
    }
    private double[] pow(double[] array){
        double[] retArray = new double[array.length];
        for (int i = 0; i < array.length; i++){
            retArray[i] = array[i] * array[i];
        }
        return retArray;
    }
    private double[] addition(double[] array1, double[] array2){
        double[] retArray = new double[array1.length];
        for (int i = 0; i < array1.length; i++){
            retArray[i] = array1[i] + array2[i];
        }
        return retArray;
    }
    private double median(double[] array)
    {
        double m=0;
        int n = array.length;
        if (n<=1)
        {
            return array[0];
        }
        else if(n%2==1)
        {
            m=array[((n+1)/2)-1];

        }
        else
        {
            m=(array[n/2-1]+array[n/2])/2;
        }
        return m;

    }
}

