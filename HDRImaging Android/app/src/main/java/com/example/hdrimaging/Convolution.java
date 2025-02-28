package com.example.hdrimaging;

import android.graphics.Color;

/**
 * Convolution is the code for applying the convolution operator.
 *
 * @author: Simon Horne
 */
public class Convolution extends Thread {

    /**
     * Default no-arg constructor.
     */
    public Convolution() {
    }

    /**
     * Takes an image (grey-levels) and a kernel and a position,
     * applies the convolution at that position and returns the
     * new pixel value.
     *
     * @param input The 2D double array representing the image.
     * @param x The x coordinate for the position of the convolution.
     * @param y The y coordinate for the position of the convolution.
     * @param k The 2D array representing the kernel.
     * @param kernelWidth The width of the kernel.
     * @param kernelHeight The height of the kernel.
     * @return The new pixel value after the convolution.
     */
    public static double singlePixelConvolution(double [][] input,
                                                int x, int y,
                                                double [][] k,
                                                int kernelWidth,
                                                int kernelHeight){
        double output = 0;
        for(int i=0;i<kernelWidth;++i){
            for(int j=0;j<kernelHeight;++j){
                output = output + (input[x+i][y+j] * k[i][j]);
            }
        }
        return output;
    }

    /**
     * Takes a 2D array of grey-levels and a kernel and applies the convolution
     * over the area of the image specified by width and height.
     *
     * @param input the 2D double array representing the image
     * @param width the width of the image
     * @param height the height of the image
     * @param kernel the 2D array representing the kernel
     * @param kernelWidth the width of the kernel
     * @param kernelHeight the height of the kernel
     * @return the 2D array representing the new image
     */
    public static double [][] convolution2D(double [][] input,
                                            int width, int height,
                                            double [][] kernel,
                                            int kernelWidth,
                                            int kernelHeight){
        int smallWidth = width - kernelWidth + 1;
        int smallHeight = height - kernelHeight + 1;
        double [][] output = new double [smallWidth][smallHeight];
        for(int i=0;i<smallWidth;++i){
            for(int j=0;j<smallHeight;++j){
                output[i][j]=0;
            }
        }
        for(int i=0;i<smallWidth;++i){
            for(int j=0;j<smallHeight;++j){
                output[i][j] = singlePixelConvolution(input,i,j,kernel,
                        kernelWidth,kernelHeight);
//if (i==32- kernelWidth + 1 && j==100- kernelHeight + 1) System.out.println("Convolve2D: "+output[i][j]);
            }
        }
        return output;
    }

    /**
     * Takes a 2D array of grey-levels and a kernel, applies the convolution
     * over the area of the image specified by width and height and returns
     * a part of the final image.
     * @param input the 2D double array representing the image
     * @param width the width of the image
     * @param height the height of the image
     * @param kernel the 2D array representing the kernel
     * @param kernelWidth the width of the kernel
     * @param kernelHeight the height of the kernel
     * @return the 2D array representing the new image
     */
    public static double [][] convolution2DPadded(double [][] input,
                                                  int width, int height,
                                                  double [][] kernel,
                                                  int kernelWidth,
                                                  int kernelHeight){
        int smallWidth = width - kernelWidth + 1;
        int smallHeight = height - kernelHeight + 1;
        int top = kernelHeight/2;
        int left = kernelWidth/2;
        double small [][] = new double [smallWidth][smallHeight];
        small = convolution2D(input,width,height,
                kernel,kernelWidth,kernelHeight);
        double large [][] = new double [width][height];
        for(int j=0;j<height;++j){
            for(int i=0;i<width;++i){
                large[i][j] = 0;
            }
        }
        for(int j=0;j<smallHeight;++j){
            for(int i=0;i<smallWidth;++i){
//if (i+left==32 && j+top==100) System.out.println("Convolve2DP: "+small[i][j]);
                large[i+left][j+top]=small[i][j];
            }
        }
        return large;
    }

    /**
     * Takes a 2D array of grey-levels and a kernel and applies the convolution
     * over the area of the image specified by width and height.
     *
     * @param input the 2D double array representing the image
     * @param width the width of the image
     * @param height the height of the image
     * @param kernel the 2D array representing the kernel
     * @param kernelWidth the width of the kernel
     * @param kernelHeight the height of the kernel
     * @return the 1D array representing the new image
     */
    public static double [] convolutionDoublePadded(double [][] input,
                                                    int width, int height,
                                                    double [][] kernel,
                                                    int kernelWidth,
                                                    int kernelHeight){
        double [][] result2D = new double [width][height];
        result2D = convolution2DPadded(input,width,height,
                kernel,kernelWidth,kernelHeight);
        double [] result = new double  [width * height];
        for(int j=0;j<height;++j){
            for(int i=0;i<width;++i){
                result[j*width +i]=result2D[i][j];
//if (i==32 && j==100) System.out.println("ConvolveDP: "+result[j*width +i]+" "+result2D[i][j]);
            }
        }
        return result;
    }

}