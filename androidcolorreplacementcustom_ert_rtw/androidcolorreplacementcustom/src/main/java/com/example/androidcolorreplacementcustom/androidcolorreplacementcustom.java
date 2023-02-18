package com.example.androidcolorreplacementcustom;

import android.Manifest;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.widget.Toast;
import android.util.Log;
import java.util.ArrayList;
import android.content.res.Configuration;
import androidx.core.app.ActivityCompat;
import androidx.fragment.app.Fragment;
import androidx.core.content.ContextCompat;
import android.view.LayoutInflater;
import androidx.annotation.NonNull;
import androidx.annotation.RequiresApi;
import com.example.androidcolorreplacementcustom.databinding.ActivityMainBinding;
import com.google.android.material.tabs.TabLayoutMediator;
import androidx.fragment.app.FragmentManager;
import androidx.navigation.NavController;
import androidx.navigation.Navigation;
import android.view.MenuItem;
import androidx.navigation.fragment.NavHostFragment;
import androidx.navigation.ui.NavigationUI;
import android.widget.LinearLayout;
import com.google.android.material.bottomnavigation.BottomNavigationView;
import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;
import org.opencv.android.BaseLoaderCallback;
import org.opencv.android.LoaderCallbackInterface;
import org.opencv.android.OpenCVLoader;
import org.opencv.android.CameraBridgeViewBase.CvCameraViewFrame;
import org.opencv.android.CameraBridgeViewBase.CvCameraViewListener2;
import org.opencv.core.Core;
import org.opencv.core.CvType;
import org.opencv.core.Mat;
import android.view.SurfaceView;
import android.view.View;
import android.widget.ImageButton;
import android.os.CountDownTimer;
import android.os.Build;
import androidx.core.content.res.ResourcesCompat;
import android.view.MotionEvent;
import android.view.Window;
import android.util.DisplayMetrics;
import android.graphics.Rect;
import android.view.View;

public class androidcolorreplacementcustom extends AppCompatActivity implements CvCameraViewListener2, OnFragmentInteractionListener {
    private InfoFragment infoFragment;
    private AppFragment appFragment;
     FragmentManager fm;
     Fragment current;
    private static final int MY_PERMISSIONS_REQUEST_CAMERA = 100;
    private boolean isCameraPermissionGranted = false;
    private boolean isCameraPermissionRequested = false;

    int x = -1;  //X Co-ordinate of touched position
    int y = -1;  //Y Co-ordinate of touched position
    int [] rgb_send = new int[3];
    // to store RGB of reference color last at touched location
    DisplayMetrics metrics;

 // properties specific for Camera block
   private CameraView mCameraView;
   private Camera2View mCamera2View;
   private int mDisplayWidth;
   private int mDisplayHeight;
   private Mat mCameraBufInput;
   private Mat mCameraBufOutput;
   private boolean  hasCamera2Support = true;

   private final BaseLoaderCallback mLoaderCallback = new BaseLoaderCallback(this) {
	    @Override
	    public void onManagerConnected(int status) {
	        switch (status) {
	            case LoaderCallbackInterface.SUCCESS:
	            	flashMessage("OpenCV loaded successfully");
	                if (hasCamera2Support) {
                          if (null != mCamera2View)
                               mCamera2View.enableView();
                          }else {
                          if (null != mCameraView)
                               mCameraView.enableView();
                         }
                   break;
	            default:
	                super.onManagerConnected(status);
                   break;
	        }
	    }
	};

   private boolean isCamera2Supported() {
      if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.LOLLIPOP) {
          return true;
      } else {
            return false;
      }
   }
    private void registerCamera() {
    if (hasCamera2Support) {
        mCamera2View = (Camera2View) findViewById(R.id.surface2_view);
        mCamera2View.setVisibility(SurfaceView.VISIBLE);
        mCameraView = (CameraView) findViewById(R.id.surface_view);
        mCameraView.setVisibility(SurfaceView.GONE);
        mCamera2View.setCvCameraViewListener(this);
    }else {
        mCameraView = (CameraView) findViewById(R.id.surface_view);
        mCameraView.setVisibility(SurfaceView.VISIBLE);
        mCamera2View = (Camera2View) findViewById(R.id.surface2_view);
        mCamera2View.setVisibility(SurfaceView.GONE);
        mCameraView.setCvCameraViewListener(this);
    }
    }

    private void resumeCamera() {
        if (!OpenCVLoader.initDebug()) {
            Log.d("resumeCamera", "Internal OpenCV library not found. Using OpenCV Manager for initialization");
        OpenCVLoader.initAsync(OpenCVLoader.OPENCV_VERSION_3_0_0, this, mLoaderCallback);
        } else {
            Log.d("resumeCamera", "OpenCV library found inside package. Using it!");
            mLoaderCallback.onManagerConnected(LoaderCallbackInterface.SUCCESS);
            if (hasCamera2Support) {
                 if (mCamera2View != null) {
                     mCamera2View.setCameraPermissionGranted();
                 }
            } else {
                  if (mCameraView != null) {
                      mCameraView.setCameraPermissionGranted();
                   }
             }
        }
    }

    private void pauseCamera() {
        if (hasCamera2Support) 
              if (mCamera2View != null) 
                  mCamera2View.disableView();
        else {
             if (mCameraView != null)
                  mCameraView.disableView();
        }
	 }

    public void onCameraViewStarted(int width, int height) {
        mCameraBufInput = new Mat(height, width, CvType.CV_8UC4);
        mCameraBufOutput = new Mat(height, width, CvType.CV_8UC4);
	 }

    public void onCameraViewStopped() {
    	mCameraBufInput.release();
    	mCameraBufOutput.release();
    }

    public Mat onCameraFrame(CvCameraViewFrame inputFrame) {
        mCameraBufInput = inputFrame.rgba();
        metrics = new DisplayMetrics();
        getWindowManager().getDefaultDisplay().getMetrics(metrics);
        if (x != -1 && y != -1) { // For Latest touched position
            //if true, touch detected
            if ((y < metrics.heightPixels) && (x < metrics.widthPixels))
            {
                int h_off, rel_h;
                int w_off, rel_w;
                /** calculation of offsets and scaling parameters
                 * for application window to original video frame */
                h_off = getTitleBarHeight() + getStatusBarHeight();
                rel_h = (metrics.heightPixels - h_off);
                rel_w = ((mCameraBufInput.width() * rel_h)
                        / mCameraBufInput.height());
                w_off = (metrics.widthPixels - rel_w) / 2;
                /**  Calculating  correspondence for touch position
                 *  to the pixel co-ordinates in the video frame */
                int posY = ((y - h_off) * mCameraBufInput.height())
                        / rel_h;
                int posX = ((x - w_off) * mCameraBufInput.width())
                        / rel_w;
                /* get the pixel info for calculated offset in the image */
                double []rgb = mCameraBufInput.get(posY , posX );
                if(rgb != null) {
                    rgb_send[0] = (int)rgb[0];
                    rgb_send[1] = (int)rgb[1];
                    rgb_send[2] = (int)rgb[2];
                }
            }
            x = -1;  /* Resetting x,y for the next touch event */
            y = -1;
        }
        return mCameraBufOutput;
    }

    public int initCamera(double sampleTime, int location, int width, int height) {
        try {
            if (hasCamera2Support)
                mCamera2View.check(location, width, height);
            else
                mCameraView.check(location, width, height);
                 return 1;
        } catch (CameraView.SetupException ex) {
                mCameraView.showAlert(ex.mDescription);
                return 0;
        } catch (Camera2View.SetupException ex) {
                 mCamera2View.showAlert(ex.mDescription);
                 return 0;
        }
    }
    public int initVideoDisplay(int width, int height) {
        mDisplayWidth = width;
        mDisplayHeight = height;
        return 1;
    }

    public long getCameraInputBuffer() {
       return (mCameraBufInput != null ? mCameraBufInput.getNativeObjAddr() : 0);
    }

	 public long getCameraOutputBuffer() {
		return (mCameraBufOutput != null ? mCameraBufOutput.getNativeObjAddr() : 0);
	}

    private boolean checkIfAllPermissionsGranted()
    {
        return true && isCameraPermissionGranted;
    }
    private void requestPermission() {
        String permissionRationale = "";
        // Here, thisClass is the current activity
        //request for camera
        if (ContextCompat.checkSelfPermission(thisClass,
                Manifest.permission.CAMERA)
                != PackageManager.PERMISSION_GRANTED) {

            // Permission is not granted. Should we show an explanation?
            if (ActivityCompat.shouldShowRequestPermissionRationale(thisClass,
                    Manifest.permission.CAMERA)) {
                permissionRationale += "Camera, ";
            } else {
                // No explanation needed; request the permission
                if (!isCameraPermissionRequested) {
                    isCameraPermissionRequested = true;
                    ActivityCompat.requestPermissions(thisClass,
                            new String[]{Manifest.permission.CAMERA},
                            MY_PERMISSIONS_REQUEST_CAMERA);
                    return;
                }
            }
        } else {
            // Permission has already been granted
            isCameraPermissionGranted = true;
        }
        if (!permissionRationale.isEmpty())
            if (infoFragment != null) {
                infoFragment.updateModelInfo(permissionRationale + "permission not granted. Model cannot start.");
            }
    }
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        com.example.androidcolorreplacementcustom.databinding.ActivityMainBinding activityMainBinding = ActivityMainBinding.inflate(LayoutInflater.from(this));
        setContentView(activityMainBinding.getRoot());
        fm = getSupportFragmentManager();
        Fragment navHostFragment = fm.findFragmentById(R.id.nav_host_fragment);
        navHostFragment = navHostFragment.getChildFragmentManager().getFragments().get(0);
        current =  navHostFragment;
        appFragment  = (AppFragment) navHostFragment;
        infoFragment  = new InfoFragment();
        fm.beginTransaction().add(R.id.nav_host_fragment, infoFragment, "2").hide(infoFragment).commit();
        fm.beginTransaction().add(R.id.nav_host_fragment, appFragment, "1").commit();
        BottomNavigationView navView = findViewById(R.id.nav_view);
        NavController navController = Navigation.findNavController(this, R.id.nav_host_fragment);
        NavigationUI.setupWithNavController(navView, navController);
        navView.setOnNavigationItemSelectedListener(new BottomNavigationView.OnNavigationItemSelectedListener() {
        @Override
                public boolean onNavigationItemSelected(@NonNull MenuItem menuItem) {
                        switch (menuItem.getItemId()) {                case R.id.navigation_app:
                fm.beginTransaction().hide(current).show(appFragment).commit();
                current = appFragment;
        return true;                case R.id.navigation_info:
                fm.beginTransaction().hide(current).show(infoFragment).commit();
                current = infoFragment;
        return true;                }
                return false;
                }
        });
hasCamera2Support = isCamera2Supported();
        thisClass = this;
     }

    private androidcolorreplacementcustom thisClass;
    private final Thread BgThread = new Thread() {
    @Override
    public void run() {
            String argv[] = new String[] {"MainActivity","androidcolorreplacementcustom"};
            naMain(argv, thisClass);
        }
    };

    public void flashMessage(final String inMessage) {
        runOnUiThread(new Runnable() {
              public void run() {
                    Toast.makeText(getBaseContext(), inMessage, Toast.LENGTH_SHORT).show();
              }
        });
    }

    public void terminateApp() {
        finish();
    }

    protected void onDestroy() {
         if (BgThread.isAlive())
             naOnAppStateChange(6);
         super.onDestroy();
         System.exit(0); //to kill all our threads.
    }

	@Override
    public void onAttachFragment(Fragment fragment) {
        super.onAttachFragment(fragment);
        if (fragment instanceof InfoFragment) {
            this.infoFragment = (InfoFragment) fragment;
            infoFragment.setFragmentInteractionListener(this);
        }
        if (fragment instanceof AppFragment) {
            ((AppFragment)fragment).setFragmentInteractionListener(this);
        }
        if (fragment instanceof CameraScopeFragment) {
            ((CameraScopeFragment)fragment).setFragmentInteractionListener(this);
        }
    }

	@Override
    public void onFragmentCreate(String name) {

    }

    @Override
    public void onFragmentStart(String name) {
        switch (name) {
            case "Info":
               break;
            case "App":
                break;
            default:
                break;
    }
    }

    @Override
    public void onFragmentResume(String name) {
        switch (name) {
            case "App":
                break;
           case "dot1":
              if (hasCamera2Support) {
                   if (mCamera2View == null) {
                       registerCamera();
                    }
               }else {
                    if (mCameraView == null) {
                         registerCamera();
                    }
               }
               if (checkIfAllPermissionsGranted()) {
                   resumeCamera();
	                System.loadLibrary("androidcolorreplacementcustom");
                   if (!BgThread.isAlive())
                       BgThread.start();
               }
               break;
            default:
                break;
        }
    }

    @Override
    public void onFragmentPause(String name) {
    }
    @Override
    protected void onResume() {
            requestPermission();
         super.onResume();
         if (BgThread.isAlive())
             naOnAppStateChange(3);
    }

    @Override
    protected void onPause() {
        if (BgThread.isAlive())
            naOnAppStateChange(4);
        super.onPause();
    }

    @Override
    public void onConfigurationChanged(Configuration newConfig) {
        super.onConfigurationChanged(newConfig);
        LinearLayout mylayout = thisClass.findViewById(R.id.layoutapp);
        if (newConfig.orientation == Configuration.ORIENTATION_LANDSCAPE) {
            mylayout.setOrientation(LinearLayout.HORIZONTAL);
        } else if (newConfig.orientation == Configuration.ORIENTATION_PORTRAIT){
            mylayout.setOrientation(LinearLayout.VERTICAL);
        }
    }

    @Override
    public void onRequestPermissionsResult(int requestCode,
                                           String permissions[], int[] grantResults) {
        switch (requestCode) {
            case MY_PERMISSIONS_REQUEST_CAMERA:
                // If request is cancelled, the result arrays are empty.
                if (grantResults.length > 0
                        && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
                    // permission was granted, yay! Do related task you need to do.
                    isCameraPermissionGranted = true;
                    resumeCamera();
                } else {
                    // permission denied, boo!
                    flashMessage("Camera usage Permission not granted");
                }
                isCameraPermissionRequested = false;
                break;

            // other case lines to check for other
            // permissions this app might request.
        }
        if (!checkIfAllPermissionsGranted() && !isCameraPermissionRequested) {
            requestPermission();
        }
    }
//    public int[] pickColorFromDeviceScreen()
//    {
//        int []rgb_send = {211,27,10};
//        /* R, G, B components of the color Red */
//        return rgb_send; //reference color for detection
//    }

    public int[] pickColorFromDeviceScreen()
    {
        Log.d("test",rgb_send[0]+","+rgb_send[1]+","+rgb_send[2]);
        /* Reference color from the video frame */
        return rgb_send;
    }
    /** Get Height of the Status Bar from the Layout for the device. */
    public int getStatusBarHeight() {
        Rect r = new Rect();
        Window w = getWindow();
        w.getDecorView().getWindowVisibleDisplayFrame(r);
        return r.top;
    }
    /** Get Height of the Title Bar from the app title name */
    public int getTitleBarHeight() {
        int viewTop =
                getWindow().findViewById(Window.ID_ANDROID_CONTENT).getTop();
        return (viewTop - getStatusBarHeight());
    }
    private native int naMain(String[] argv, androidcolorreplacementcustom pThis);
    private native void naOnAppStateChange(int state);
}
