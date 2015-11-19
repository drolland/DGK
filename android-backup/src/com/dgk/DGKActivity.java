package com.dgk;

import android.app.NativeActivity;
import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;


/*
public class DGKActivity extends Activity
{
    
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        System.loadLibrary("SDL2");
	System.loadLibrary("dgk");
    }
}



*/
public class DGKActivity extends NativeActivity
{
   
    static {
        //System.loadLibrary("main");
        //System.loadLibrary("pthread");
	System.loadLibrary("SDL2");
	System.loadLibrary("main");
    }
}
