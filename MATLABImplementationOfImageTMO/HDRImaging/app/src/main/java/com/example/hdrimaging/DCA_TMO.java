package com.example.hdrimaging;

import static java.lang.Double.min;
import static java.lang.Math.abs;
import static java.lang.Math.exp;
import static java.lang.Math.floor;
import static java.lang.Math.log10;
import static java.lang.Math.max;
import static java.lang.Math.round;
import static java.util.Arrays.*;
import static java.util.Arrays.sort;

import java.util.ArrayList;
import java.util.Arrays;

public class DCA_TMO {

    public double[][] hdrLum;
    public double[][] hdrPQ;
    public double[] edges;
    public double[] errors;
    public double[][][] DCA_TMO_Processing(double[][][] hdrImg, int length, int width)
    {
        //TODO: Figure out why hdrImg is not returning full array
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
        //TODO:
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
        //TODO:
//        %% local enhancemant using DoG
        double sigmaC = 0.5;
        double sigmaS = 0.8;
        double window = 9;

        double[][] gfilterC = fspecial(window, sigmaC);
        double[][] gfilterS = fspecial(window, sigmaS);
        double[][] DoGfilter = new double[(int) window][(int) window];
        for (int i = 0; i < DoGfilter.length; i++)
            for (int j = 0; j < DoGfilter[i].length; j++)
                DoGfilter[i][j] = gfilterC[i][j] - gfilterS[i][j];

        double[][] hdrPQnor = new double[length][width];
        double hdrPQMax = hdrPQnor[0][0];
        double hdrPQMin = hdrPQnor[0][0];
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


//        labels_DoG = labels + 3.0*imfilter(hdrPQnor, DoGfilter, 'replicate');
        //TODO:
//        %% color restoration
//        s1 = (labels_DoG - min(labels_DoG(:))) ./ (max(labels_DoG(:)) - min(labels_DoG(:)));
//        s = 1 - atan(s1);
//        s = min(s, 0.5);
//        ldrImg_DoG = (hdrImg ./ hdrLum).^s .* labels_DoG;
//        maxx = MaxQuart(ldrImg_DoG(:), 0.99);
//        minn = MaxQuart(ldrImg_DoG(:), 0.01);
//        if maxx<255
//        if max(ldrImg_DoG(:))<255
//        maxx = max(ldrImg_DoG(:));
//    else
//        maxx = 255;
//        end
//                end
//        if minn>0
//        if min(ldrImg_DoG(:))>0
//        minn = min(ldrImg_DoG(:));
//    else
//        minn = 0;
//        end
//                end
//        ldrImg_DoG(ldrImg_DoG>maxx) = maxx;
//        ldrImg_DoG(ldrImg_DoG<minn) = minn;
//        ldrImg = 255.* ((ldrImg_DoG - minn) ./ (maxx - minn));
        return ldrImg;
    }

    private double[][] quantizeNL_float(double[][] y, double nclust, double[][] lum) {

        double[][] lum0 = lum;

        int numelLum =numel(lum);

        double[] lum1D = reshape1D(lum, numelLum);
        sort(lum1D);

        double[] y1D = reshape1D(y, numel(y));
        sort(y1D);

        edges = new double[]{0, y1D.length};
        double[] errorsPow = new double[y1D.length];
        double meanOfY = mean(y1D);
        for (int i = 0; i < y1D.length; i++){
            errorsPow[i] = Math.pow((y1D[i]-meanOfY),2);
            }
        errors = sum(errorsPow);

        double[] s_data = cumsum(y1D);
        double[] ss_data = cumsum(pow(y1D));


        for (int i=1; i<nclust-1; i++)
        {
            double[] maxError = max(errors);
            double idx = maxError[1];
            double k = edges[(int)idx];
            double n = edges[(int)idx+1]-k;
            double sn = s_data[(int) (k+n-1)];
            if(k>=1)
                sn = sn - s_data[(int) k];
            double ssn = ss_data[(int) (k+n)-1];
            if(k>=1)
                ssn = ssn - ss_data[(int) k];
            double d = 2;
            double m = floor(n/d);
            while(true)
            {
                double sm = s_data[(int) (k+m)];
                if(k>=1)
                    sm = sm - s_data[(int) k];
                double ssm = ss_data[(int) (k+m)];
                if(k>=1)
                    ssm = ssm - ss_data[(int) k];
                double e1 = ssm - Math.pow(sm,2)/m;
                double e2 = ssn - ssm - Math.pow((sn - sm),2)/(n-m);
                d = 2 * d;
                if(abs(e1-e2) < 0.001 || d >= n) {
                    int indexStart = (int) (k + 1);
                    int indexEnd = (int) (k + m);
                    double[] lum1Range = RangeArray(y1D, indexStart, indexEnd);
                    double lum1 = median(lum1Range);
                    indexStart = (int) (k + m + 1);
                    indexEnd = (int) (k + n);
                    double[] lum2Range = RangeArray(y1D, indexStart, indexEnd);
                    double lum2 = median(lum2Range);
                    double delta1 = Math.pow(10, tvi(new double[]{log10(lum1)}));
                    double delta2 = Math.pow(10, tvi(new double[]{log10(lum2)}));
                    double value = delta1/(delta1+delta2) * (lum1D[(int) (k+n-1)] - lum1D[(int) (k+1-1)]) + lum1D[(int) (k+1-1)];
                    double[] absValue = doubleMinusArray(value, RangeArray(lum1D, (int) (k+1), (int) (k+n)));
                    double[] values = min(absMatrix(absValue));
                    double lum_loc = values[1];
                    m = lum_loc;
                    sm = s_data[(int) (k + m)];
                    if (k >= 1)
                        sm = sm - s_data[(int) k];
                    ssm = ss_data[(int) (k + m)];
                    if (k >= 1)
                        ssm = ssm - ss_data[(int) k];
                    e1 = Math.pow(ssm - sm, 2) / m;
                    e2 = ssn - ssm - Math.pow((sn - sm), 2) / (n - m);
//                  TODO:
//                    edges = [edges(1:idx),k+m,edges(idx+1:end)];
//                    errors = [errors(1:idx-1),e1,e2,errors(idx+1:end)];
//                  TODO:Resolve errors
                    edges = AppendEdges(RangeArray(edges,0, (int) idx),(int)(k+m),RangeArray(edges, (int) (idx+1), edges.length-1));
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
        //TODO:
//        mdata = zeros(1, nclust);
//        mdata(1) = min(lum0(:));
//        mdata(end) = max(lum0(:));
//        for i=2:nclust-1
//              if lum(edges(i))==lum(edges(i+1))
//             ind = (lum0==lum(edges(i)));
    //        mdata(i) = mean(lum0(ind))+eps*i;
//          else
//        ind = (lum0>lum(edges(i)) & lum0<=lum(edges(i+1)));
//        mdata(i) = mean(lum0(ind));
//        end
//                end
//
//        labels_mdata = linspace(1, 256, nclust);
//        labels = interp1(mdata, labels_mdata, lum0, 'linear');
        return hdrPQ;
    }

    private double[] AppendEdges(double[] rangeArray, double value, double[] rangeArray1) {
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
                threshold[idx.get(i)] = Math.pow((0.405 * intensity[idx.get(i)] + 1.6),2.18) - 2.86;
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
                threshold[idx.get(i)] = Math.pow((0.249 * intensity[idx.get(i)] + 0.65),2.7) - 0.72;
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
                threshold[i] = threshold[i] = - 0.95;
            }
        }
        return threshold[0];
    }

    private ArrayList<Integer> find(double[] intensity,double check1,double check2, double value1,double value2) {
        // 0 < , 1 >, 2 <=, 3 >=, 4 nulll
        ArrayList<Integer> indexes = new ArrayList<>();
        for (int i = 0; i < intensity.length; i++) {
            if (check1 == 1 && check2 == 4) {
                if (intensity[i] > value1) {
                    indexes.add(i);
                }
            }
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
        indexStart = indexStart-1;
        indexEnd = indexEnd -1;
        int range = indexEnd - indexStart;
        double[] rangeArray = new double[range];
        int j = indexStart;
        for (int i = 0; i < range; i++) {
            if (j < indexEnd) {
                rangeArray[i] = lum[j];
                j += 1;
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
        double p3 = 0.5;;    // std
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
        double eps = Math.pow(2,-52);
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
        double sum = 0;
        for (int i = 0; i < array.length; i++) {

            // find sum
            sum += array[i];

            // replace
            array[i] = sum;
        }
        return array;
    }
    private double[] pow(double[] array){
        for (int i = 0; i < array.length; i++){
            array[i] = Math.pow(array[i],2);
        }
        return array;
    }

    private double[] addition(double[] array1, double[] array2){
        for (int i = 0; i < array1.length; i++){
            array1[i] = array1[i] + array2[i];
        }
        return array1;
    }
    private double median(double[] array)
    {
        double m=0;
        int n = array.length;
        if(n%2==1)
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

