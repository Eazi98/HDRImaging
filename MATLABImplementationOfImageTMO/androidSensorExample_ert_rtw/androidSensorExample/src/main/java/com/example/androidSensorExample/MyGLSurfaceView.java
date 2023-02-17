package com.example.androidSensorExample;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.graphics.PixelFormat;
import android.util.AttributeSet;

public class MyGLSurfaceView extends GLSurfaceView {
    MyRenderer mRenderer;

    public MyGLSurfaceView(Context context) {
        super(context);
        init(context);
    }

    public MyGLSurfaceView(Context context, AttributeSet attrs) {
        super(context, attrs);
        init(context);
    }

    private void init(Context context) {
        setEGLContextClientVersion(2);
        //Use MyRenderer to draw on the surface
        mRenderer = new MyRenderer();
        setRenderer(mRenderer);
        setZOrderOnTop(true);
        setRenderMode(GLSurfaceView.RENDERMODE_WHEN_DIRTY);
    }
}	
