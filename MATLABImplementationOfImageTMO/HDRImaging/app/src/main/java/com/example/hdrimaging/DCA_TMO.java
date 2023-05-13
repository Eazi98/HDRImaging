package com.example.hdrimaging;

import static java.lang.Math.atan;
import static java.lang.Math.exp;
import static java.lang.Math.floor;
import static java.util.Arrays.stream;

import java.util.Arrays;


public class DCA_TMO extends Thread{

    private static int length;
    private static int width;
    private static final double eps = Math.pow(2,-52);

    public static double[][][] DCA_TMO_Processing(double[][][] hdrImg, int length1, int width1)
    {
        length = length1;
        width = width1;
        double maxhdr;
        double minhdr;
        double hdrMaxValue;
        double[][][] ldrImg;

        //set parameters
        double K = 55;
//      pre-processing
        double[] hdrOneD = stream(hdrImg)
                .flatMap(Arrays::stream)
                .flatMapToDouble(Arrays::stream)
                .toArray();

        MaxQuart MaxQuart = new MaxQuart();
        maxhdr = MaxQuart.maxQuart(hdrOneD, 0.99);
        minhdr = MaxQuart.maxQuart(hdrOneD, 0.01);


        for (int i = 0; i < hdrImg.length; i++)
            for (int j = 0; j < hdrImg[i].length; j++)
                for (int k = 0; k < hdrImg[i][j].length; k++){
                    if (hdrImg[i][j][k] > maxhdr){
                        hdrImg[i][j][k] = maxhdr;
                    }else if(hdrImg[i][j][k] < minhdr){
                        hdrImg[i][j][k] = minhdr;
                    }
                }
        //tone map using clustering methods
        double[][] hdrLum = new double[length][width];
        double[][] hdrLum1 = new double[length][width];
        double[][] hdrPQ = new double[length][width];

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

        QuantizeNL_float QuantizeNL_float = new QuantizeNL_float(length, width);
        double[][] labels = QuantizeNL_float.quantizeNL_float(hdrPQ, K, hdrLum);
        // TODO: Check labels to see when values are off by less than 1

        //local enhancement using DoG
        double sigmaC = 0.5;
        double sigmaS = 0.8;
        double window = 9;

        //Correct from here
        double[][] gfilterC = fspecial(window, sigmaC);
        double[][] gfilterS = fspecial(window, sigmaS);
        double[][] DoGfilter = new double[(int) window][(int) window];
        for (int i = 0; i < DoGfilter.length; i++)
            for (int j = 0; j < DoGfilter[i].length; j++)
                DoGfilter[i][j] = (gfilterC[i][j] - gfilterS[i][j]);

        double[][] hdrPQnor = new double[length][width];

        double[] hdrPQMaxMin = findMaxAndMinOfArray(hdrPQ);
        double hdrPQMax = hdrPQMaxMin[0];
        double hdrPQMin = hdrPQMaxMin[1];

        for (int i = 0; i < hdrImg.length; i++)
            for (int j = 0; j < hdrImg[i].length; j++) {
                hdrPQnor[i][j] = 255 * (hdrPQ[i][j] - hdrPQMin) / (hdrPQMax - hdrPQMin) + 1;
            }

        for (int i = 0; i < hdrImg.length; i++)
            for (int j = 0; j < hdrImg[i].length; j++) {
                hdrPQnor[i][j] = hdrPQnor[i][j] * 0.35 + labels[i][j] * 0.65;
            }
        //Correct to here
        double[][] labels_DoG = new double[length][width];
        double[][] imfilterArray = imfilter(hdrPQnor, DoGfilter);
        for (int i = 0; i < labels_DoG.length; i++)
            for (int j = 0; j < labels_DoG[i].length; j++) {
                labels_DoG[i][j] = labels[i][j] + 3.0 * imfilterArray[i][j];
            }

        // color restoration
        double[][] s1;
        double minLabels_DoG = min2dArray(labels_DoG);
        double maxLabels_DoG = max2dArray(labels_DoG);

        s1 = array2dDivision(arrayMinusDouble(labels_DoG,minLabels_DoG),(maxLabels_DoG - minLabels_DoG));
//        s1 = (labels_DoG - min(labels_DoG(:))) ./ (max(labels_DoG(:)) - min(labels_DoG(:)));
        double[][] s;
        s = doubleMinus2dArray(1,atan2DArray(s1));
        s = min2dArrayOrScalar(s,0.5);
        double[][][] dividedArray = divide3dArray2dArray(hdrImg,hdrLum);
        double[][][] powArray = pow3d2d(dividedArray, s);
        double[][][] ldrImg_DoG = multiply3d2d(powArray, labels_DoG);
        double[] ldrImg_DoG1D = stream(ldrImg_DoG)
                .flatMap(Arrays::stream)
                .flatMapToDouble(Arrays::stream)
                .toArray();
        MaxQuart maxQuart = new MaxQuart();
        double maxx = maxQuart.maxQuart(ldrImg_DoG1D, 0.99);
        double minn = maxQuart.maxQuart(ldrImg_DoG1D, 0.01);
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

        dividedArray = divide3dDouble(minusedArray,(maxx - minn));
        ldrImg = multiply3dDouble(255,dividedArray);
        return ldrImg;
    }

    private static double[] findMaxAndMinOfArray(double[][] array){
        double max = array[0][0];
        double min = array[0][0];
        for (double[] doubles : array)
            for (double aDouble : doubles) {
                if (aDouble > max) {
                    max = aDouble;
                } else if (aDouble < min) {
                    min = aDouble;
                }
            }
        return new double[]{max,min};
    }

    private static double[][][] divide3dDouble(double[][][] array, double value) {
        double[][][] retArray = new double[array.length][array[0].length][array[0][0].length];
        for (int i = 0; i < array.length; i++)
            for (int j = 0; j < array[i].length; j++)
                for (int k = 0; k < array[i][j].length; k++)
                    retArray[i][j][k] = array[i][j][k] / value;
        return retArray;
    }

    private static double[][][] multiply3dDouble(int value, double[][][] array) {
        double[][][] retArray = new double[array.length][array[0].length][array[0][0].length];
        for (int i = 0; i < array.length; i++)
            for (int j = 0; j < array[i].length; j++)
                for (int k = 0; k < array[i][j].length; k++)
                    retArray[i][j][k] = array[i][j][k] * value;
        return retArray;
    }

    private static double[][][] array3dMinusDouble(double[][][] array, double minn) {
        double[][][] retArray = new double[array.length][array[0].length][array[0][0].length];
        for (int i = 0; i < array.length; i++)
            for (int j = 0; j < array[i].length; j++)
                for (int k = 0; k < array[i][j].length; k++)
                    retArray[i][j][k] = array[i][j][k] - minn;
        return retArray;
    }

    private static double[][][] multiply3d2d(double[][][] array, double[][] multiplyBy) {
        double[][][] retArray = new double[array.length][array[0].length][array[0][0].length];
        for (int i = 0; i < array.length; i++)
            for (int j = 0; j < array[i].length; j++)
                for (int k = 0; k < array[0][0].length; k++)
                    retArray[i][j][k] = array[i][j][k] * multiplyBy[i][j];
        return retArray;
    }

    private static double[][][] pow3d2d(double[][][] array, double[][] power) {
        double[][][] retArray = new double[array.length][array[0].length][array[0][0].length];
        for (int i = 0; i < array.length; i++)
            for (int j = 0; j < array[i].length; j++)
                for (int k = 0; k < array[0][0].length; k++)
                    retArray[i][j][k] = Math.pow(array[i][j][k],power[i][j]);
        return retArray;
    }

    private static double[][][] divide3dArray2dArray(double[][][] array, double[][] divideBy) {
        double[][][] retArray = new double[array.length][array[0].length][array[0][0].length];
            for (int i = 0; i < array.length; i++)
                for (int j = 0; j < array[i].length; j++)
                    for (int k = 0; k < array[0][0].length; k++)
                        retArray[i][j][k] = array[i][j][k]/divideBy[i][j];
        return retArray;
    }

    private static double[][] min2dArrayOrScalar(double[][] array, double value) {
        double[][] retArray = new double[array.length][array[0].length];
        for (int i = 0; i < array.length; i++)
            for (int j = 0; j < array[i].length; j++)
                if (array[i][j] < value)
                    retArray[i][j] = array[i][j];
                else{
                    retArray[i][j] = value;
                }
        return retArray;
    }

    private static double[][] atan2DArray(double[][] array) {
        double[][] retArray = new double[array.length][array[0].length];
        for (int i = 0; i < array.length; i++)
            for (int j = 0; j < array[i].length; j++)
                retArray[i][j] = atan(array[i][j]);
        return  retArray;
    }

    private static double[][] array2dDivision(double[][] array, double value) {
        double[][] retArray = new double[array.length][array[0].length];
        for (int i = 0; i < array.length; i++)
            for (int j = 0; j < array[i].length; j++)
                retArray[i][j] = array[i][j]/ value;
        return retArray;
    }

    private static double min2dArray(double[][] array){
        double arrayMin = array[0][0];
        for (double[] doubles : array)
            for (double aDouble : doubles) {
                if (aDouble < arrayMin) {
                    arrayMin = aDouble;
                }
            }
        return arrayMin;
    }
    private static double max2dArray(double[][] array){
        double arrayMax = array[0][0];
        for (double[] doubles : array)
            for (double aDouble : doubles) {
                if (aDouble > arrayMax) {
                    arrayMax = aDouble;
                }
            }
        return arrayMax;
    }
    private static double[][] imfilter(double[][] hdrPQnor, double[][] doGfilter) {
        double[] finalSize = {length, width};
        return filterDouble2DWithConv(hdrPQnor,doGfilter,finalSize);
    }

    private static double[][] filterDouble2DWithConv(double[][] a, double[][] h, double[] finalSize){
        int[] padSize = new int[] {4,4};
        double[][] retArray;
        h = rot90(h,2);
        //double[] imageSize = {length, width};
        double[] sizeh = new double[] {h.length,h.length};
        //double[] nonSymmetricPadShift = numMinusArray(1,mod(sizeh,2));
        a = padarray_algo(a,padSize);
        retArray = conv2(a,h);


        return retArray;
    }

    private static double[][] conv2(double[][] a, double[][] h) {
        double[][] retArray = new double[length][width];
        //https://towardsdatascience.com/intuitively-understanding-convolutions-for-deep-learning-1f6f42faee1
        //TODO:Check values
        //+ 8 to length and width to ensure that the returned array gives correct dimensions
        retArray = Convolution.convolution2D(a, length+8, width+8,h,h.length,h.length);
        //https://homepages.inf.ed.ac.uk/rbf/HIPR2/flatjavasrc/Convolution.java
        return retArray;
    }

    private static double[][] padarray_algo(double[][] a, int[] padSize) {
        double[] aSize = {length, width};
        int[][] aIdx = getPaddingIndices(aSize, padSize);
        double[][] b = RangeMatrix(a,aIdx);
        return b;
    }

    private static double[][] RangeMatrix(double[][] a, int[][] aIdx) {
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

    private static int[][] getPaddingIndices(double[] aSize, int[] padSize) {
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

    private static int[] ones(int p) {
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

    private static double[][] rot90(double[][] arr1, int times) {
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

    private static double[] min(double[] absMatrix) {
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

    private static double[][] arrayMinusDouble(double[][] rangeArray, double value) {
        double[][] retArray = new double[rangeArray.length][rangeArray[0].length];
        for (int i = 0; i < rangeArray.length; i++)
            for (int j = 0; j < rangeArray[i].length; j++)
                retArray[i][j] = rangeArray[i][j] - value;
        return retArray;
    }
    private static double[][] doubleMinus2dArray(double value, double[][] rangeArray) {
        double[][] retArray = new double[rangeArray.length][rangeArray[0].length];
        for (int i = 0; i < rangeArray.length; i++)
            for (int j = 0; j < rangeArray[i].length; j++)
                retArray[i][j] = value - rangeArray[i][j] ;
        return retArray;
    }

    private static double[] max(double[] array){
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
    private static double[][] fspecial(double window, double sigma){
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
}

