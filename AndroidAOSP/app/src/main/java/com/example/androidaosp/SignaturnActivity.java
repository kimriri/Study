package com.example.androidaosp;

import android.os.Bundle;
import android.widget.TextView;
import androidx.appcompat.app.AppCompatActivity;

public class SignaturnActivity extends AppCompatActivity {
    static {
        System.loadLibrary("androidaosp");
    }
    @Override
    protected void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        TextView tv = findViewById(R.id.main_text);
        TextView tv1 = findViewById(R.id.main_text_sig_1);
        TextView tv2 = findViewById(R.id.main_text_sig_2);
        String input0 = fun_signaturn();
        tv.setText(input0);

        String input1 = fun_signaturn("JAVA에서 입력받은값 ");
        tv1.setText(input1);

        String input2 = fun_signaturn(12,12);
        tv2.setText(input2);
    }

    public  native String fun_signaturn();
    public  native String fun_signaturn(String s);
    public  native String fun_signaturn(int i, int j);

}
