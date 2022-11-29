package com.example.hdrimaging;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.os.Environment;
import android.os.Handler;
import android.provider.Settings;
import android.text.method.ScrollingMovementMethod;
import android.view.View;
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
import java.io.IOException;
import java.io.InputStream;
import java.lang.reflect.Array;
import java.util.Arrays;

public class MainActivity extends AppCompatActivity {

    private TextView fileLocationText;
    private TextView arrayText;
    private HDRtofloatarray hdrtofloatarray;
    private Boolean hdrLoaded;
    private String pixelArrayText;
    private float[][][] pixelArray;
    ActivityResultLauncher<Intent> filePicker;
    Thread arrayThread = null;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        com.example.hdrimaging.databinding.ActivityMainBinding binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());
        fileLocationText = binding.FileLocationText;
        arrayText = binding.arrayText;
        arrayText.setMovementMethod(new ScrollingMovementMethod());
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
                openFileDialog(view);

            }
        });
    }

    ActivityResultLauncher<Intent> sActivityResultLauncher = registerForActivityResult(
            new ActivityResultContracts.StartActivityForResult(),
            new ActivityResultCallback<ActivityResult>() {
                @Override
                public void onActivityResult(ActivityResult result) {
                    if (result.getResultCode() == Activity.RESULT_OK){
                        Intent data = result.getData();
                        assert data != null;
                        Uri uri = data.getData();
                        String path = getFileName(uri, getApplicationContext());
                        fileLocationText.setText(path);
                        pixelArrayText = getHDRArray(path, getApplicationContext());
                        arrayText.setText(pixelArrayText);

                    }
                }
            }
    );

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

    String getFileName (Uri uri, Context context){
        String res = null;
        res = RealPathUtil.getRealPath(context,uri);
        return res;
    }

    String getHDRArray (String path, Context context){ //TODO: might need to put in threaded function
        File file = new File(path); //for HDRtofloatarray
        pixelArrayText = "";
        try {
            hdrtofloatarray = new HDRtofloatarray(file);
        } catch (IOException e) {
            e.printStackTrace();
        }
        pixelArray = hdrtofloatarray.getPixelArray();
        int width = hdrtofloatarray.getWidth();
        int length = hdrtofloatarray.getHeight();

        //For testing
        for (int i = length - 1; i >= 110; i--)
            for (int j = width - 1; j >= 169; j--)
                for (int k = 0; k < 3; k++)
                    pixelArrayText += pixelArray[i][j][k] + "\t";

        //Full array
//        for (int i= 0; i < pixelArray.length; i++)
//            for (int j=0; j < pixelArray[i].length; j++)
//                for (int k=0; k < pixelArray[i][j].length; k++)
//                    pixelArrayText += pixelArray[i][j][k] + "\t";

        //Full array
//        for (float[][] floats : pixelArray)
//            for (float[] aFloat : floats)
//                for (float v : aFloat) pixelArrayText += v + "\t";
        //TODO: Convert pixelArray to a readable string
        return pixelArrayText;
    }

}