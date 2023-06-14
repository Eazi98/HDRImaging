import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.nio.file.Paths;
import java.util.Scanner;

public class Main {

    static int width;
    static int length;
    public static void main(String[] args) {
        String fileName = "moto720";
        String path = "../../MATLABImplementationOfImageTMO/HDRim/" + fileName + ".hdr";
        double[][][] LDRDoubleArray;
        LDRDoubleArray = DCATMO(getHDRDoubleArray(path));
        String outputFile = "../../MATLABImplementationOfImageTMO/LDRim/Java_"+ fileName + ".png";
        writeToPNG(LDRDoubleArray, outputFile);
    }

    public static void writeToPNG(double[][][] LDRDoubleArray, String path){

        // Create a 3D array representing the pixel values (RGB) of the image
        double [][][] pixelData = LDRDoubleArray;

        // Populate the pixelData array with the desired pixel values

        // Create a BufferedImage object with the specified width and height
        BufferedImage image = new BufferedImage(length, width, BufferedImage.TYPE_INT_RGB);

        // Set the pixel values of the image using the pixelData array
       // TODO: FIX orientation of image
        for (int x = 0; x < length; x++) {
            for (int y = 0; y < width; y++) {
                int rgb = (int)pixelData[x][y][0] << 16 | (int)pixelData[x][y][1] << 8 | (int)pixelData[x][y][2];
                image.setRGB(x, y, rgb);
            }
        }

        // Save the image to a PNG file
        try {
            File output = new File(path);
            ImageIO.write(image, "png", output);
            System.out.println("Image saved successfully.");
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

