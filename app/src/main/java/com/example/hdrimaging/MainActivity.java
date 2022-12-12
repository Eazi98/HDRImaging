package com.example.hdrimaging;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.content.Context;
import android.content.Intent;
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
import java.io.IOException;
import java.lang.reflect.Array;
import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    private TextView fileLocationText;
    private ImageView imageHDR;
    private TextView arrayText;
    private ScrollView scrollView;
    private HDRtofloatarray hdrtofloatarray;
    private ArrayList<Float> HDRArray;
    private ArrayList<Float> pixelArrayTextArray = new ArrayList<>();
    private int loadArray = 200;
    int arraySize;


    ActivityResultLauncher<Intent> filePicker;
    Thread arrayThread = null;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        com.example.hdrimaging.databinding.ActivityMainBinding binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());
        fileLocationText = binding.FileLocationText;
        imageHDR = binding.imageView;
        arrayText = binding.arrayText;
        scrollView = binding.scrollView;
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
//                ChooseFile();
                arrayText.setText(null);
                openFileDialog(view);

            }
        });

        binding.scrollView.setOnScrollChangeListener(new View.OnScrollChangeListener() {
            @Override
            public void onScrollChange(View view, int scrollX, int scrollY, int oldScrollX, int oldScrollY) {
                if (scrollView.getChildAt(0).getBottom() <= (scrollView.getHeight() + scrollView.getScrollY())) {
                    for (int i= 0; i < loadArray; i++){
                        arrayText.append(" "+ String.format("%.4f", HDRArray.get(0)));
                        HDRArray.remove(0);
                    }
                }
//                if (scrollY > oldScrollY + 100){
//
//                }

            }
        });
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
//                        try {
//                            Drawable drawable = showHDR(path);
//                            imageHDR.setImageDrawable(drawable);
//                        } catch (IOException e) {
//                            e.printStackTrace();
//                        }

                        HDRArray = getHDRArray(path, getApplicationContext());

                        arrayText.setText(String.format("%.4f",HDRArray.get(0)));
                        for (int i= 1; i < loadArray; i++){
                            arrayText.append(" "+ String.format("%.4f", HDRArray.get(0)));
                            HDRArray.remove(0);
                        }
                    }
                }
            }
    );

    public void openFileDialog(View view){
        Intent data = new Intent(Intent.ACTION_OPEN_DOCUMENT);
        data.setType("*/*");
        data = Intent.createChooser(data, "Choose a file");
        sActivityResultLauncher.launch(data);
        //arrayText.append(pixelArrayText);
        if (fileLocationText.getText() == ""){
            Snackbar.make(view, "Do not select files from recent!", Snackbar.LENGTH_LONG)
                    .setAction("Action", null).show();
        }
    }

    String getFileName (Uri uri, Context context){
        String res = null;
        res = RealPathUtil.getRealPath(context,uri);
        return res;
    }

    ArrayList<Float> getHDRArray (String path, Context context){ //TODO: might need to put in threaded function
        pixelArrayTextArray.clear();
        File file = new File(path); //for HDRtofloatarray
//        pixelArrayText = "";
        try {
            hdrtofloatarray = new HDRtofloatarray(file);
        } catch (IOException e) {
            e.printStackTrace();
        }
        float[][][] pixelArray = hdrtofloatarray.getPixelArray();
        int width = hdrtofloatarray.getWidth();
        int length = hdrtofloatarray.getHeight();

        //For testing
//        for (int i = length - 1; i >= 110; i--)
//            for (int j = width - 1; j >= 169; j--)
//                for (int k = 0; k < 3; k++)
//                    pixelArrayText += pixelArray[i][j][k] + "\t";

//        Full array
//        for (int i = 0; i < pixelArray.length; i++)
//            for (int j = 0; j < pixelArray[i].length; j++)
//                for (int k = 0; k < pixelArray[i][j].length; k++){
////                    pixelArrayText += pixelArray[i][j][k] + "\t";
//                    pixelArrayTextArray.add(pixelArray[i][j][k]);
//                }


        //Full array
        for (float[][] floats : pixelArray)
            for (float[] aFloat : floats)
                for (float v : aFloat) pixelArrayTextArray.add(v);
        //TODO: Convert pixelArray to a readable string
        return pixelArrayTextArray;
    }

//    Drawable showHDR(String path) throws IOException {
//        Drawable drawable = null;
//        File file = new File(path);
//        ImageDecoder.Source source = null;
//        if (android.os.Build.VERSION.SDK_INT >= android.os.Build.VERSION_CODES.P) {
//            source = ImageDecoder.createSource(file);
//        }
//        if (android.os.Build.VERSION.SDK_INT >= android.os.Build.VERSION_CODES.P) {
//            drawable = ImageDecoder.decodeDrawable(source, (decoder, info, src) -> {
//                decoder.setTargetColorSpace(ColorSpace.get(ColorSpace.Named.EXTENDED_SRGB));
//            });
//        }
//        return drawable;
//    }

}