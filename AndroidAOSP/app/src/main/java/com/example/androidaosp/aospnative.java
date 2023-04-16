package com.example.androidaosp;

public class aospnative {

    static native String getLine(String prompt, int value);

    static {
        System.loadLibrary("androidaosp");
    }
}
