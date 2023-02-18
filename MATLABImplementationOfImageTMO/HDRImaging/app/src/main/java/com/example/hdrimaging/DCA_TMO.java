package com.example.hdrimaging;

import static java.lang.Math.max;
import static java.lang.Math.round;
import static java.util.Arrays.sort;

import java.util.Arrays;

public class DCA_TMO {

    public double[][][] DCA_TMO_Processing(double[][][] hdrImg)
    {
        double maxhdr;
        double minhdr;
        double[][][] ldrImg = {};
//      pre-processing
        double[] hdrOneD = Arrays.stream(hdrImg)
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
        double[][] hdrLum = 0.2126 * hdrImg(:,:,1) + 0.7152 * hdrImg(:,:,2) + 0.0722 * hdrImg(:,:,3);
//        hdrLum1 = hdrLum./max(hdrImg(:));
//        hdrPQ = ((107/128 + 2413/128*hdrLum1.^(1305/8192)) ./ (1 + 2392/128*hdrLum1.^(1305/8192))) .^ (2523/32);
//        [labels, ~, ~] = quantizeNL_float(hdrPQ, K, hdrLum);
        //TODO:
//        %% local enhancemant using DoG
//        sigmaC = 0.5;
//        sigmaS = 0.8;
//        window = 9;
//        gfilterC = fspecial('gaussian', window, sigmaC);
//        gfilterS = fspecial('gaussian', window, sigmaS);
//        DoGfilter = gfilterC - gfilterS;
//        hdrPQnor = 255 .* (hdrPQ - min(hdrPQ(:))) ./ (max(hdrPQ(:)) - min(hdrPQ(:))) + 1;
//        hdrPQnor = hdrPQnor .* 0.35 + labels .* 0.65;
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

    private double MaxQuart(double[] hdrImg, double percentile){

        if(percentile > 1.0)
            percentile = 1.0;

        if(percentile < 0.0)
            percentile = 0.0;

        double[] sizeVariables = size(hdrImg);
        double n = sizeVariables[0];
        double m = sizeVariables[1];

        sort(hdrImg);
        int index = (int) round(n * m * percentile);
        index = max(index,1);
        double ret = hdrImg[index];
        return ret;
    }

    private double[] size(double[] hdrImg){
        double n = hdrImg.length;
        double m = 1;
        double size[] = {n,m};
        return size;
    }
}
