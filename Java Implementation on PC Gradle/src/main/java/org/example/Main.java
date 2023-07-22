package org.example;

import org.ejml.simple.SimpleMatrix;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

public class Main {

    static int width;
    static int length;
    public static void main(String[] args) {
//        // Specify the folder path
//        String folderPath = "../../MATLABImplementationOfImageTMO/HDRim/testFiles";
//
//        // Create a File object for the folder
//        File folder = new File(folderPath);
//
//        // Check if the folder exists
//        if (folder.exists() && folder.isDirectory()) {
//            // Get the list of files in the folder
//            File[] files = folder.listFiles();
//
//            // Iterate over the files and print their names
//            if (files != null) {
//                for (File file : files) {
//                    if (file.isFile()) {
//                        String fullFileName = file.getName();
//                        String[] fileName = fullFileName.split("\\.");
//                        System.out.println(fileName[0]);
//                        String path = "../../MATLABImplementationOfImageTMO/HDRim/" + fileName[0] + ".hdr";
//                        double[][][] LDRDoubleArray;
//                        LDRDoubleArray = DCATMO(getHDRDoubleArray(path));
//                        String outputFile = "../../MATLABImplementationOfImageTMO/LDRim/Java_"+ fileName[0] + ".png";
//                        System.out.println(outputFile);
//                        writeToPNG(LDRDoubleArray, outputFile);
//                    }
//                }
//            }
//        } else {
//            System.out.println("Invalid folder path!");
//        }
        String fileName = "moto2350x1322";
        String path = "../MATLABImplementationOfImageTMO/HDRim/" + fileName + ".hdr";
        double[][][] LDRDoubleArray;
//        for (int i = 0; i <= 11; i++){
//            long startTime = System.nanoTime();
//            LDRDoubleArray = DCATMO(getHDRDoubleArray(path));
//
//            String outputFile = "../MATLABImplementationOfImageTMO/LDRim/Java_"+ fileName + ".png";
////            System.out.println(fileName);
//            writeToPNG(LDRDoubleArray, outputFile);
//            long endTime = System.nanoTime();
//            long TimeTaken = endTime - startTime;
//            System.out.println(nanosecondsToSeconds(TimeTaken));
//        }
        long startTime = System.nanoTime();
//        testMatrix(getHDRDoubleArray(path));
        long endTime = System.nanoTime();
        long TimeTaken = endTime - startTime;
//        System.out.println(nanosecondsToSeconds(TimeTaken));

//        startTime = System.nanoTime();
//        testArray(getHDRDoubleArray(path));
//        endTime = System.nanoTime();
//        TimeTaken = endTime - startTime;
//        System.out.println(nanosecondsToSeconds(TimeTaken));


        double[][][] hdrImg = getHDRDoubleArray(path);
        SimpleMatrix hdrLumMatrix = new SimpleMatrix(
                new double[length][width]
        );
        SimpleMatrix hdrLumMatrix1 = new SimpleMatrix(
                new double[length][width]
        );
        double [][] hdrLumArray = new double[length][width];
        double [][] hdrLumArray1 = new double[length][width];
        for (int i = 0; i < hdrImg.length; i++)
            for (int j = 0; j < hdrImg[i].length; j++){
                hdrLumMatrix.set(i,j,0.2126 * hdrImg[i][j][0] + 0.7152 * hdrImg[i][j][1]+ 0.0722 * hdrImg[i][j][2]);
                hdrLumMatrix1.set(i,j,0.1 * hdrImg[i][j][0] + 0.7152 * hdrImg[i][j][1]+ 0.0722 * hdrImg[i][j][2]);
                hdrLumArray[i][j] = 0.2126 * hdrImg[i][j][0] + 0.7152 * hdrImg[i][j][1]+ 0.0722 * hdrImg[i][j][2];
                hdrLumArray1[i][j] = 0.1 * hdrImg[i][j][0] + 0.7152 * hdrImg[i][j][1]+ 0.0722 * hdrImg[i][j][2];
            }
        //Test Matrix element wise division
        System.out.println("Scalar Multiplication");
        startTime = System.nanoTime();
        hdrLumMatrix.scale(5);
        endTime = System.nanoTime();
        TimeTaken = endTime - startTime;
        System.out.println("Matrix: " +nanosecondsToSeconds(TimeTaken));


        double [][] hdrLumArrayResult = new double[length][width];
        startTime = System.nanoTime();
        for (int i = 0; i < hdrImg.length; i++)
            for (int j = 0; j < hdrImg[i].length; j++){
                hdrLumArrayResult[i][j] = hdrLumArray[i][j] * 5;
            }
        endTime = System.nanoTime();
        TimeTaken = endTime - startTime;
        System.out.println("Array: \t" + nanosecondsToSeconds(TimeTaken) + "\n");

        System.out.println("Scalar Division");
        startTime = System.nanoTime();
        hdrLumMatrix.divide(5);
        endTime = System.nanoTime();
        TimeTaken = endTime - startTime;
        System.out.println("Matrix: " +nanosecondsToSeconds(TimeTaken));


        hdrLumArrayResult = new double[length][width];
        startTime = System.nanoTime();
        for (int i = 0; i < hdrImg.length; i++)
            for (int j = 0; j < hdrImg[i].length; j++){
                hdrLumArrayResult[i][j] = hdrLumArray[i][j] / 5;
            }
        endTime = System.nanoTime();
        TimeTaken = endTime - startTime;
        System.out.println("Array: \t" + nanosecondsToSeconds(TimeTaken)+ "\n") ;

        System.out.println("Element-wise Division");
        startTime = System.nanoTime();
        hdrLumMatrix.elementDiv(hdrLumMatrix1);
        endTime = System.nanoTime();
        TimeTaken = endTime - startTime;
        System.out.println("Matrix: " +nanosecondsToSeconds(TimeTaken));


        hdrLumArrayResult = new double[length][width];
        startTime = System.nanoTime();
        for (int i = 0; i < hdrImg.length; i++)
            for (int j = 0; j < hdrImg[i].length; j++){
                hdrLumArrayResult[i][j] = hdrLumArray[i][j] / hdrLumArray1[i][j];
            }
        endTime = System.nanoTime();
        TimeTaken = endTime - startTime;
        System.out.println("Array: \t" + nanosecondsToSeconds(TimeTaken)+ "\n");

        System.out.println("Element-wise Power");
        startTime = System.nanoTime();
        hdrLumMatrix.elementPower(3);
        endTime = System.nanoTime();
        TimeTaken = endTime - startTime;
        System.out.println("Matrix: " +nanosecondsToSeconds(TimeTaken));


        hdrLumArrayResult = new double[length][width];
        startTime = System.nanoTime();
        for (int i = 0; i < hdrImg.length; i++)
            for (int j = 0; j < hdrImg[i].length; j++){
                hdrLumArrayResult[i][j] = Math.pow(hdrLumArray[i][j],3);
            }
        endTime = System.nanoTime();
        TimeTaken = endTime - startTime;
        System.out.println("Array: \t" + nanosecondsToSeconds(TimeTaken)+ "\n");

        System.out.println("Element-wise Multiplication");
        startTime = System.nanoTime();
        hdrLumMatrix.elementMult(hdrLumMatrix1);
        endTime = System.nanoTime();
        TimeTaken = endTime - startTime;
        System.out.println("Matrix: " +nanosecondsToSeconds(TimeTaken));


        hdrLumArrayResult = new double[length][width];
        startTime = System.nanoTime();
        for (int i = 0; i < hdrImg.length; i++)
            for (int j = 0; j < hdrImg[i].length; j++){
                hdrLumArrayResult[i][j] = hdrLumArray[i][j] * hdrLumArray1[i][j];
            }
        endTime = System.nanoTime();
        TimeTaken = endTime - startTime;
        System.out.println("Array: \t" + nanosecondsToSeconds(TimeTaken)+ "\n");

        System.out.println("Scalar Addition");
        startTime = System.nanoTime();
        hdrLumMatrix.plus(1);
        endTime = System.nanoTime();
        TimeTaken = endTime - startTime;
        System.out.println("Matrix: " +nanosecondsToSeconds(TimeTaken));


        hdrLumArrayResult = new double[length][width];
        startTime = System.nanoTime();
        for (int i = 0; i < hdrImg.length; i++)
            for (int j = 0; j < hdrImg[i].length; j++){
                hdrLumArrayResult[i][j] = hdrLumArray[i][j] + 1;
            }
        endTime = System.nanoTime();
        TimeTaken = endTime - startTime;
        System.out.println("Array: \t" + nanosecondsToSeconds(TimeTaken)+ "\n");

        System.out.println("Reshape");
        startTime = System.nanoTime();
        hdrLumMatrix.reshape(1,hdrLumMatrix.getNumElements());
        endTime = System.nanoTime();
        TimeTaken = endTime - startTime;
        System.out.println("Matrix: " +nanosecondsToSeconds(TimeTaken));

        hdrLumArrayResult = new double[length][width];
        double[] hdrLumArray1D = new double[length*width];
        int count = 0;
        startTime = System.nanoTime();
        for (int i = 0; i < hdrImg.length; i++)
            for (int j = 0; j < hdrImg[i].length; j++){
                hdrLumArray1D[count] = hdrLumArray[i][j];
                count +=1;
            }
        endTime = System.nanoTime();
        TimeTaken = endTime - startTime;
        System.out.println("Array: \t" + nanosecondsToSeconds(TimeTaken)+ "\n");
    }

    public static void testMatrix(double[][][] hdrImg){

        double hdrMaxValue = hdrImg[0][0][0];
        for (int i = 0; i < hdrImg.length; i++)
            for (int j = 0; j < hdrImg[i].length; j++)
                for (int k = 0; k < hdrImg[i][j].length; k++){
                    if (hdrImg[i][j][k] > hdrMaxValue)
                        hdrMaxValue = hdrImg[i][j][k];
                }

        SimpleMatrix hdrLumMatrix = new SimpleMatrix(
                new double[length][width]
        );

        SimpleMatrix hdrLum1Matrix;

        SimpleMatrix hdrPQMatrix = new SimpleMatrix(
                new double[length][width]
        );

        SimpleMatrix hdrPQMatrix1;
        SimpleMatrix hdrPQMatrix2;
        for (int i = 0; i < hdrImg.length; i++)
            for (int j = 0; j < hdrImg[i].length; j++){
                hdrLumMatrix.set(i,j,0.2126 * hdrImg[i][j][0] + 0.7152 * hdrImg[i][j][1]+ 0.0722 * hdrImg[i][j][2]);
            }
        hdrLum1Matrix = hdrLumMatrix.divide(hdrMaxValue);
        hdrPQMatrix1 = hdrLum1Matrix.elementPower((double) 1305 /8192).scale((double) 2413 /128).plus((double) 107 /128);
        hdrPQMatrix2 = hdrLum1Matrix.elementPower((double) 1305 /8192).scale((double) 2392 /128).plus(1);
        hdrPQMatrix = hdrPQMatrix1.elementDiv(hdrPQMatrix2).elementPower((double) 2523 /32);
    }

    public static void testArray(double[][][] hdrImg){
        double[][] hdrLum = new double[length][width];
        double[][] hdrLum1 = new double[length][width];
        double[][] hdrPQ = new double[length][width];


        double hdrMaxValue = hdrImg[0][0][0];
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
    }
    public static double nanosecondsToSeconds(long nanoseconds) {
        double seconds = nanoseconds / 1_000_000_000.0;
        return seconds;
    }
    public static void writeToPNG(double[][][] LDRDoubleArray, String path){

        // Create a 3D array representing the pixel values (RGB) of the image
        double [][][] pixelData = LDRDoubleArray;

        // Populate the pixelData array with the desired pixel values

        // Create a BufferedImage object with the specified width and height
        BufferedImage image = new BufferedImage(width, length, BufferedImage.TYPE_INT_RGB);

        // Set the pixel values of the image using the pixelData array
        // TODO: FIX orientation of image
        for (int y = 0; y < length; y++) {
            for (int x = 0; x < width; x++) {
                int red = (int) LDRDoubleArray[y][x][0];
                int green = (int) LDRDoubleArray[y][x][1];
                int blue = (int) LDRDoubleArray[y][x][2];
                int rgb = new Color(red, green, blue).getRGB();
                image.setRGB(x, y, rgb);
            }
        }


        // Save the image to a PNG file
        try {
            File output = new File(path);
//            System.out.println(output);
            ImageIO.write(image, "png", output);
            //System.out.println("Image saved successfully.");
        } catch (IOException e) {
            e.printStackTrace();
            // Handle the exception as appropriate for your application
        }
    }
    public static double[][][] DCATMO(double[][][] HDRDoubleArray){
        long startTime = System.nanoTime();
        double[][][] retArray = DCA_TMO.DCA_TMO_Processing(HDRDoubleArray, length, width);
        long endTime = System.nanoTime();
        long TimeTaken = endTime - startTime;
        //System.out.println(nanosecondsToSeconds(TimeTaken));
        return retArray;
    }
    static double[][][] getHDRDoubleArray(String path) {
        File file = new File(path); //for HDRtofloatarray
        HDRtoDoubleArray hdrtodoublearray = null;
        try {
            hdrtodoublearray = new HDRtoDoubleArray(file);
        } catch (IOException e) {
            e.printStackTrace();
        }
        width = hdrtodoublearray.getWidth();
        length = hdrtodoublearray.getHeight();
        return hdrtodoublearray.getPixelArray();
    }
}

