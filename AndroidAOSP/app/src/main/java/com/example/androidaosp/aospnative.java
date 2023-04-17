package com.example.androidaosp;

public class aospnative {
    static {
        System.loadLibrary("androidaosp");
    }
    static native String getLine(String prompt, int value);

}
