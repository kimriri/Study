package com.example.androidaosp;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity2 extends AppCompatActivity {
    public int i = 0, j = 0;
    private static final String TAG = "AndroidAOSP";
    TextView tv;
    EditText ei;
    EditText ji;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);
        tv = findViewById(R.id.main_text_1);
        ei = findViewById(R.id.activity_main2_ei);
        ji = findViewById(R.id.activity_main2_ji);

        Button button = (Button)findViewById(R.id.activity_main2_sum);
        button.setOnClickListener(saveListener);
    }

    private View.OnClickListener saveListener = new View.OnClickListener(){
        public void onClick(View v) {
            try {
                i = Integer.parseInt(ei.getText().toString());
            }catch (NumberFormatException e) {
                i=0;
            }
            try {
                j= Integer.parseInt(ji.getText().toString());
            }catch  (NumberFormatException e) {
                j=0;
            }
            JNICallBackMethod m = new JNICallBackMethod(i,j);

            String s = " " + m.PrinttoString();

            Log.v(TAG,s);
            tv.setText(s);

        }
    };

}