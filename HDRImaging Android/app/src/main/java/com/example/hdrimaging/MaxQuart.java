package com.example.hdrimaging;

import static java.lang.Math.round;
import static java.util.Arrays.sort;

public class MaxQuart {
    public MaxQuart(){

    }
    public double maxQuart(double[] hdrImg, double percentile){

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
}
