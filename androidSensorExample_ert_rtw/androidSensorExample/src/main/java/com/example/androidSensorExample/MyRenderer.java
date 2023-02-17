package com.example.androidSensorExample;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.opengl.GLES20;
import android.opengl.GLSurfaceView;
import android.opengl.Matrix;
import android.util.Log;

public class MyRenderer implements GLSurfaceView.Renderer {

    private final float[] mViewMatrix = new float[16];
    private final float[] mViewProjectionMatrix = new float[16];
    private final float[] mModelViewProjectionMatrix = new float[16];
    private final float[] mRotationMatrix = new float[16];

    private Membrane mMembrane;
    private float[]  mAngles = {0.0f, 0.0f, 0.0f};

    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {

        // gl is not used in 2.0; instead use GLES20 to clear color
        GLES20.glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

        GLES20.glEnable(GLES20.GL_DEPTH_TEST);
        
        mMembrane   = new Membrane();
    }

    @Override
    public void onDrawFrame(GL10 gl) {
        float[] scratch = new float[16];

        // Draw background color
        GLES20.glClear(GLES20.GL_COLOR_BUFFER_BIT | GLES20.GL_DEPTH_BUFFER_BIT);

        // Set the camera position (View matrix)
        Matrix.setLookAtM(mViewMatrix, 0, 
                                +3.0f, +3.0f,  3.0f,  //eye
                                0.0f,  0.0f,  0.0f,  //center 
                                0.0f,  0.0f,  1.0f   //up 
                         );

        // Calculate the projection and view transformation
        Matrix.multiplyMM(mModelViewProjectionMatrix, 0, mViewProjectionMatrix, 0, mViewMatrix, 0);

        // Create a rotation
        Matrix.setRotateM(mRotationMatrix, 0, mAngles[1], 0.0f, 0.0f, 1.0f);

        // Combine the rotation matrix with the projection and camera view
        // Note that the mModelViewProjectionMatrix factor *must be first* in order
        // for the matrix multiplication product to be correct.
        Matrix.multiplyMM(scratch, 0, mModelViewProjectionMatrix, 0, mRotationMatrix, 0);

        // Draw triangle
        mMembrane.draw(scratch);
    }


    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height) {
        // Adjust the viewport based on geometry changes,
        // such as screen rotation
        GLES20.glViewport(0, 0, width, height);

        float ratio = (float) width / height;

        // this projection matrix is applied to object coordinates
        // in the onDrawFrame() method
        Matrix.frustumM(mViewProjectionMatrix, 0, -ratio, ratio, -1, 1, 3, 7);
    }
    
    
    /* Utility class to compile shaders */
    public static int compileShader(int type, String shaderCode){

        // create a vertex shader type (GLES20.GL_VERTEX_SHADER)
        // or a fragment shader type (GLES20.GL_FRAGMENT_SHADER)
        int shader = GLES20.glCreateShader(type);

        // add the source code to the shader and compile it
        GLES20.glShaderSource(shader, shaderCode);
        GLES20.glCompileShader(shader);
        final int[] status = new int[1];
        GLES20.glGetShaderiv(shader, GLES20.GL_COMPILE_STATUS, status, 0);
        if (status[0] == 0) {
            GLES20.glDeleteShader(shader);
            Log.v("MyRenderer", "Compilation of shader failed"+"\n" + GLES20.glGetShaderInfoLog(shader));
            throw new RuntimeException("Compilation of shader failed");
        }

        return shader;
    }
    

    public static void checkGlError(String glOperation) {
        int error;
        while ((error = GLES20.glGetError()) != GLES20.GL_NO_ERROR) {
            Log.e("MyRenderer", glOperation + ": glError " + error);
            throw new RuntimeException(glOperation + ": glError " + error);
        }
    }

    /**
     * Returns the rotation angle of the triangle shape (mTriangle).
     *
     * @return - A float representing the rotation angle.
     */
    public float[] getAngles() {
        return mAngles;
    }

    /**
     * Sets the rotation angle of the triangle shape (mTriangle).
     */
    public void setAngles(float[] angles) {
        mAngles = angles;
    }

}
// LocalWords:  gl GLES viewport shaders shader
