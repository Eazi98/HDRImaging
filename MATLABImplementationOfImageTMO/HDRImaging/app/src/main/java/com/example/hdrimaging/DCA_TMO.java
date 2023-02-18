package com.example.hdrimaging;

public class DCA_TMO {

    public double[][][] DCA_TMO(double[][][] hdrImg)
    {
        double[][][] ldrImg = {};

        return ldrImg;
    }

    private float MaxQuart(double[] hdrImg, double percentile){

        if(percentile > 1.0)
            percentile = 1.0;

        if(percentile < 0.0)
            percentile = 0.0;

        [n, m] = size(matrix);

        matrix = sort(reshape(matrix, n * m, 1));
        index = round(n * m * percentile);
        index = max([index 1]);
        ret = matrix(index);

    }
}
