package com.scott.opengl;

import android.app.ActivityManager;
import android.content.Context;
import android.content.pm.ConfigurationInfo;
import android.opengl.GLSurfaceView;
import android.os.Build;
import android.os.Bundle;
import android.util.Log;
import android.view.MotionEvent;
import android.view.View;
import android.view.WindowManager;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

import com.scott.opengl.renders.AirHockeyRenderer;
import com.scott.opengl.renders.BaseRender;
import com.scott.opengl.renders.TriAngleRenderer;

public class MainActivity extends AppCompatActivity {
    private GLSurfaceView glSurfaceView;
    private boolean rendererSet = false;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        glSurfaceView = new GLSurfaceView(this);
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_TRANSLUCENT_STATUS);

        // Request an OpenGL ES 2.0 compatible context.
        glSurfaceView.setEGLContextClientVersion(3);

        // Assign our renderer.
        glSurfaceView.setRenderer(new BaseRender());
        rendererSet = true;


//        glSurfaceView.setOnTouchListener(new View.OnTouchListener() {
//            @Override
//            public boolean onTouch(View v, MotionEvent event) {
//                if (event != null) {
//                    // Convert touch coordinates into normalized device
//                    // coordinates, keeping in mind that Android's Y
//                    // coordinates are inverted.
//                    final float normalizedX =
//                            (event.getX() / (float) v.getWidth()) * 2 - 1;
//                    final float normalizedY =
//                            -((event.getY() / (float) v.getHeight()) * 2 - 1);
//
//                    if (event.getAction() == MotionEvent.ACTION_DOWN) {
//                        glSurfaceView.queueEvent(new Runnable() {
//                            @Override
//                            public void run() {
//                                Log.i("sun", "handleTouchPress");
//                                airHockeyRenderer.handleTouchPress(
//                                        normalizedX, normalizedY);
//                            }
//                        });
//                    } else if (event.getAction() == MotionEvent.ACTION_MOVE) {
//                        glSurfaceView.queueEvent(new Runnable() {
//                            @Override
//                            public void run() {
//                                Log.i("sun", "handleTouchDrag");
//                                airHockeyRenderer.handleTouchDrag(
//                                        normalizedX, normalizedY);
//                            }
//                        });
//                    }
//
//                    return true;
//                } else {
//                    return false;
//                }
//            }
//        });
        setContentView(glSurfaceView);

    }


    @Override
    protected void onPause() {
        super.onPause();
        if (rendererSet) {
            glSurfaceView.onPause();
        }
    }

    @Override
    protected void onResume() {
        super.onResume();
        if (rendererSet) {
            glSurfaceView.onResume();
        }
    }
}
