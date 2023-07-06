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
        String fileName = "mpi_office";
        String path = "../MATLABImplementationOfImageTMO/HDRim/" + fileName + ".hdr";
        double[][][] LDRDoubleArray;
        for (int i = 0; i <= 11; i++){
            long startTime = System.nanoTime();
            LDRDoubleArray = DCATMO(getHDRDoubleArray(path));

            String outputFile = "../MATLABImplementationOfImageTMO/LDRim/Java_"+ fileName + ".png";
//            System.out.println(fileName);
            writeToPNG(LDRDoubleArray, outputFile);
            long endTime = System.nanoTime();
            long TimeTaken = endTime - startTime;
            System.out.println(nanosecondsToSeconds(TimeTaken));
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

