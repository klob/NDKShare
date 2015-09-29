package com.diandi.klob.ndkshare;


import android.content.Context;
import android.util.Log;
import android.widget.Toast;

/**
 * *******************************************************************************
 * *********    Author : klob(kloblic@gmail.com) .
 * *********    Date : 2015-09-29  .
 * *********    Time : 15:17 .
 * *********    Version : 1.0
 * *********    Copyright © 2015, klob, All Rights Reserved
 * *******************************************************************************
 */
public class Engine {
    private final static String TAG="Engine ";
    static {
        System.loadLibrary("test");
    }
    private Context mContext;

    public Engine(Context context) {
        mContext = context;
    }

    public native void callJNIInt(int i);

    public native void callJNIString(String s);

    public native String md5(String ctx);


    public native void test3();

    public native void test4();


    public static void main(String []args)
    {

    }

    public void callbackInt(int i) {
        showMsg(i+"");
    }

    public void callbackString(String s) {
        showMsg(s + "");

    }

    public void showMsg(String msg)
    {
        Toast.makeText(mContext,msg,Toast.LENGTH_SHORT).show();
    }

}
