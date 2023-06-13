package com.example.hdrimaging;

import static java.lang.Math.abs;
import static java.lang.Math.floor;
import static java.lang.Math.log10;
import static java.util.Arrays.sort;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class QuantizeNL_float {

    private final int length;
    private final int width;
    private static final double eps = Math.pow(2,-52);
    public QuantizeNL_float(int xlength, int xwidth){
        length = xlength;
        width = xwidth;
    }
    public double[][] quantizeNL_float(double[][] y, double nclust, double[][] lum) {

        double[][] lum0 = lum;

        int numelLum = numel(lum);

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
        errorsPow = null;
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
                    TVI tvi = new TVI();
                    double tvilum1 = tvi.tvi(new double[]{lum1log});
                    double delta1 = Math.pow(10, tvilum1);

                    double[] lum2Range = RangeArray(lum1D, (int) (k + m +1-1), (int) (k + n-1));
                    double lum2 = median(lum2Range);
                    double lum2log = log10(lum2);
                    double tvilum2 = tvi.tvi(new double[]{lum2log});
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
        double[][] ind;
        for (int i=1; i<=nclust-1; i++) {
            if (lum1D[(int) edges[i]-1] == lum1D[(int) edges[i + 1]-1]) {
                ind = matrixBoolean(lum0, lum1D[(int) edges[i]]); //(lum0==lum[(int) edges[i]]);
                double[] lum0Ind = getIndexValuesToArray(lum0, ind);
                mdata[i] = mean(lum0Ind) + eps * i;
            } else {
                ind = matrixBoolean1(lum0, lum1D[(int) edges[i]-1], lum1D[(int) edges[i + 1]-1]);
                double[] lum0Ind = getIndexValuesToArray(lum0, ind);
                sort(lum0Ind);
                mdata[i] = mean(lum0Ind);
            }
        }
        double[] labels_mdata = linspace(1,256,(int)nclust);
        double[][] labels = interp1(mdata, labels_mdata, lum0); //Done in main

        return labels;
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
        for (int j = 0; j < length; j++) {
            for (int k = 0; k < width; k++) {
                retArray[j][k] = array1D[0];
            }
        }
        return retArray;
    }

    private static double[] linearInterpolation(double[] x, double[] y, double[] values) {
        double[] interpolatedValues = new double[values.length];
        int n = x.length;
        for (int i = 0; i < values.length; i++) {
            // Find the index of the x value that is closest to the value to interpolate
            if (values[i] < x[0]) {
                interpolatedValues[i] = y[0];
            } else if (values[i] > x[n - 1]) {
                interpolatedValues[i] = y[n - 1];
            } else {
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

    private double[] AppendEdges(double[] rangeArray, double value, double[] rangeArray1) {
        double[] result = Arrays.copyOf(rangeArray,rangeArray.length+rangeArray1.length+1);
        result[rangeArray.length]=value;
        System.arraycopy(rangeArray1,0,result,rangeArray.length+1,rangeArray1.length);
        return result;
    }

    private double[] AppendErrors(double[] rangeArray, double e1, double e2, double[] rangeArray1) {
        double[] result = Arrays.copyOf(rangeArray,rangeArray.length+rangeArray1.length+2);
        result[rangeArray.length]=e1;
        result[rangeArray.length+1]=e2;
        System.arraycopy(rangeArray1,0,result,rangeArray.length+2,rangeArray1.length);
        return result;
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

    private int numel(double[][] array){
        int num = 0;
        for (int i = 0; i < array.length; i++)
            for (int j = 0; j < array[i].length; j++) {
                num +=1;
            }
        return num;
    }
    private double[] reshape1D(double[][] array, int numberEle){
//        double retArray[] = new double[numberEle];
//        int index = 0;
//        for (int i = 0; i < array.length; i++)
//            for (int j = 0; j < array[i].length; j++) {
//                retArray[index] = array[i][j];
//                index +=1;
//            }
        return Arrays.stream(array)
                .flatMapToDouble(Arrays::stream)
                .toArray();
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
