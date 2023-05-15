package com.example.hdrimaging;

import static com.example.hdrimaging.DCA_TMO.DCA_TMO_Processing;
import static java.lang.System.currentTimeMillis;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.Color;
import android.graphics.ColorSpace;
import android.graphics.ImageDecoder;
import android.graphics.drawable.Drawable;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.os.Environment;
import android.provider.Settings;
import android.text.method.ScrollingMovementMethod;
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
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.lang.reflect.Array;
import java.sql.Time;
import java.time.Duration;
import java.util.ArrayList;
import java.util.Date;
import java.util.concurrent.TimeoutException;

public class MainActivity extends AppCompatActivity {

    private TextView fileLocationText;
    private ImageView imageHDR;
    private ScrollView scrollViewHDR;
    private ScrollView scrollViewLDR;
    private TextView timeTaken;
    private HDRtoDoubleArray hdrtodoublearray;
    private ArrayList<Double> pixelArrayTextArray = new ArrayList<>();
    //double[][][] pixelArray;
    int width;
    int length;
    double[][][] HDRDoubleArray;
    double[][][] LDRDoubleArray;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        com.example.hdrimaging.databinding.ActivityMainBinding binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());
        fileLocationText = binding.FileLocationText;
        imageHDR = binding.convertedImage;
        scrollViewHDR = binding.scrollView;
        timeTaken = binding.TimeTakenText;
        if (Build.VERSION.SDK_INT >= 30) {
            if (!Environment.isExternalStorageManager()) {
                Intent getpermission = new Intent();
                getpermission.setAction(Settings.ACTION_MANAGE_ALL_FILES_ACCESS_PERMISSION);
                startActivity(getpermission);
            }
        }
        binding.ReadFileButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                openFileDialog(view);

            }
        });

//        binding.scrollView.setOnScrollChangeListener(new View.OnScrollChangeListener() {
//            @SuppressLint("DefaultLocale")
//            @Override
//            public void onScrollChange(View view, int scrollX, int scrollY, int oldScrollX, int oldScrollY) {
//                if (scrollViewHDR.getChildAt(0).getBottom() <= (scrollViewHDR.getHeight() + scrollViewHDR.getScrollY())) {
//                    for (int i= 0; i < loadArray; i++){
//                        HDRText.append(" "+ String.format("%.4f", HDRArray.get(0)));
//                        HDRArray.remove(0);
//                    }
//                }
//
//            }
//        });

//        binding.scrollView.setOnScrollChangeListener(new View.OnScrollChangeListener() {
//            @SuppressLint("DefaultLocale")
//            @Override
//            public void onScrollChange(View view, int scrollX, int scrollY, int oldScrollX, int oldScrollY) {
//                if (scrollViewLDR.getChildAt(0).getBottom() <= (scrollViewLDR.getHeight() + scrollViewLDR.getScrollY())) {
//                    for (int i= 0; i < loadArray; i++){
//                        LDRText.append(" "+ String.format("%.4f", LDRArray.get(0)));
//                        LDRArray.remove(0);
//                    }
//                }
//
//            }
//        });
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

                        HDRDoubleArray = getHDRDoubleArray(path);
                        LDRDoubleArray = DCATMO(HDRDoubleArray);

                        createBitMap(LDRDoubleArray,path);

                        HDRDoubleArray = null;
                        LDRDoubleArray = null;
                    }
                }
            }
    );

    public double[][][] DCATMO(double[][][] HDRDoubleArray){
        long startTime = System.nanoTime();
        double[][][] retArray = DCA_TMO_Processing(HDRDoubleArray, length, width);
        long endTime = System.nanoTime();
        long TimeTaken = endTime - startTime;
        timeTaken.setText(String.valueOf(nanosecondsToSeconds(TimeTaken)));
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
        pixelArrayTextArray.clear();
        File file = new File(path); //for HDRtofloatarray
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
        imageHDR.setImageURI(Uri.parse(file.toString()));
    }

}