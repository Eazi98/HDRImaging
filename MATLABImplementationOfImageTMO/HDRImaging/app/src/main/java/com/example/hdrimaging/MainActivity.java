package com.example.hdrimaging;

import static com.example.hdrimaging.DCA_TMO.DCA_TMO_Processing;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.app.ActivityManager;
import android.content.Context;
import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.Color;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.os.Environment;
import android.provider.Settings;
import android.util.Log;
import android.view.View;
import android.widget.ImageView;
import android.widget.ScrollView;
import android.widget.TextView;

import androidx.activity.result.ActivityResult;
import androidx.activity.result.ActivityResultCallback;
import androidx.activity.result.ActivityResultLauncher;
import androidx.activity.result.contract.ActivityResultContracts;
import androidx.appcompat.app.AppCompatActivity;

import com.example.hdrimaging.databinding.ActivityMainBinding;
import com.google.android.material.snackbar.Snackbar;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    private TextView fileLocationText;
    private ImageView imageHDR;
    private TextView ldrFilePath;
    private TextView timeTaken;
    private TextView timeTakenOverAll;
    int width;
    int length;

    static {
        System.loadLibrary("hdrimaging");
    }

    //public native double[][][] DCATMO(double[][][] HDRDoubleArray,int length, int width, int depth);
    public native void create3DArray(int length, int width, int depth);
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        com.example.hdrimaging.databinding.ActivityMainBinding binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());
        fileLocationText = binding.FileLocationText;
        imageHDR = binding.convertedImage;
        ldrFilePath = binding.LDRText;
        timeTaken = binding.TimeTakenText;
        timeTakenOverAll = binding.TimeTakenOverallText;
        if (Build.VERSION.SDK_INT >= 30) {
            if (!Environment.isExternalStorageManager()) {
                Intent getpermission = new Intent();
                getpermission.setAction(Settings.ACTION_MANAGE_ALL_FILES_ACCESS_PERMISSION);
                startActivity(getpermission);
            }
        }
        ActivityManager am = (ActivityManager) getSystemService(ACTIVITY_SERVICE);
        int memoryClass = am.getMemoryClass();
        Log.v("onCreate", "memoryClass:" + Integer.toString(memoryClass) + "MB");
        binding.ReadFileButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                openFileDialog(view);

            }
        });


    }
    public void openFileDialog(View view){

        Intent data = new Intent(Intent.ACTION_OPEN_DOCUMENT);
        data.setType("*/*");
        data = Intent.createChooser(data, "Choose a file");
        sActivityResultLauncher.launch(data);
        if (fileLocationText.getText() == ""){
            Snackbar.make(view, "Do not select files from recent!", Snackbar.LENGTH_LONG)
                    .setAction("Action", null).show();
        }
    }

    ActivityResultLauncher<Intent> sActivityResultLauncher = registerForActivityResult(
            new ActivityResultContracts.StartActivityForResult(),
            new ActivityResultCallback<ActivityResult>() {
                @SuppressLint("SetTextI18n")
                @Override
                public void onActivityResult(ActivityResult result) {
                    if (result.getResultCode() == Activity.RESULT_OK){
                        Intent data = result.getData();
                        assert data != null;
                        Uri uri = data.getData();
                        String path = getFileName(uri, getApplicationContext());
                        fileLocationText.setText(path);
//                        long startTime = System.nanoTime();
//                        //HDRDoubleArray = getHDRDoubleArray(path);
//                        double[][][] LDRDoubleArray = DCATMO(getHDRDoubleArray(path));
//
//                        createBitMap(LDRDoubleArray,path);
//
//                        long endTime = System.nanoTime();
//                        long TimeTaken = endTime - startTime;
//                        timeTakenOverAll.setText(String.valueOf("Time taken including read & write: \n" + nanosecondsToSeconds(TimeTaken)));

                        long startTime = System.nanoTime();
                        create3DArray(length, width, 3);
                        long endTime = System.nanoTime();
                        long TimeTaken = endTime - startTime;
                        timeTakenOverAll.setText(String.valueOf("Time C takes to create array: \n" + nanosecondsToSeconds(TimeTaken)));


//                        LDRDoubleArray = null;
                    }
                }
            }
    );

    public double[][][] DCATMO(double[][][] HDRDoubleArray){
        long startTime = System.nanoTime();
        double[][][] retArray = DCA_TMO_Processing(HDRDoubleArray, length, width);
        long endTime = System.nanoTime();
        long TimeTaken = endTime - startTime;
        timeTaken.setText(String.valueOf("Time taken for DCATMO to run: \n" + nanosecondsToSeconds(TimeTaken)));
        return retArray;
    }

    public static double nanosecondsToSeconds(long nanoseconds) {
        double seconds = nanoseconds / 1_000_000_000.0;
        return seconds;
    }

    String getFileName (Uri uri, Context context){
        String realPath = RealPathUtil.getRealPath(context, uri);
        return realPath;
    }

    double[][][] getHDRDoubleArray (String path){
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
    private void createBitMap(double[][][] ldrImg, String path){// your 2D array
        File folder = new File(path).getParentFile();
        String[] fileNameArray = path.split("/");
        String fileName = fileNameArray[fileNameArray.length-1];
        File directory = new File(folder + "/LDRim/");
        if (!directory.exists()) {
            directory.mkdirs();
        }

        // Create a Bitmap object from the 3D array
        int width = ldrImg[0].length;
        int height = ldrImg.length;
        Bitmap bitmap = Bitmap.createBitmap(width, height, Bitmap.Config.ARGB_8888);
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                int pixel = Color.rgb((int) ldrImg[y][x][0], (int) ldrImg[y][x][1], (int) ldrImg[y][x][2]);
                bitmap.setPixel(x, y, pixel);
            }
        }

        // Save the Bitmap object as a PNG file
        fileName = fileName + ".png";
        File file = new File(directory, fileName);
        try {
            file.createNewFile();
            FileOutputStream outputStream = new FileOutputStream(file);
            bitmap.compress(Bitmap.CompressFormat.PNG, 100, outputStream);
            outputStream.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        ldrFilePath.setText("File Path for LDR .PNG Image: \n" + file);
        imageHDR.setImageURI(Uri.parse(file.toString()));
    }

}