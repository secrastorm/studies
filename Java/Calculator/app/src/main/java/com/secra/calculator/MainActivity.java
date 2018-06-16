package com.secra.calculator;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

import java.math.RoundingMode;
import java.text.DecimalFormat;
import java.util.HashMap;
import java.util.Map;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        final SquareButton btn0 = (SquareButton) findViewById(R.id.btn0);
        final SquareButton btn1 = (SquareButton) findViewById(R.id.btn1);
        final SquareButton btn2 = (SquareButton) findViewById(R.id.btn2);
        final SquareButton btn3 = (SquareButton) findViewById(R.id.btn3);
        final SquareButton btn4 = (SquareButton) findViewById(R.id.btn4);
        final SquareButton btn5 = (SquareButton) findViewById(R.id.btn5);
        final SquareButton btn6 = (SquareButton) findViewById(R.id.btn6);
        final SquareButton btn7 = (SquareButton) findViewById(R.id.btn7);
        final SquareButton btn8 = (SquareButton) findViewById(R.id.btn8);
        final SquareButton btn9 = (SquareButton) findViewById(R.id.btn9);
        final SquareButton btnDot = (SquareButton) findViewById(R.id.btnDot);
        final SquareButton btnAdd = (SquareButton) findViewById(R.id.btnAdd);
        final SquareButton btnSub = (SquareButton) findViewById(R.id.btnSub);
        final SquareButton btnMul = (SquareButton) findViewById(R.id.btnMul);
        final SquareButton btnDiv = (SquareButton) findViewById(R.id.btnDiv);
        final SquareButton btnPC = (SquareButton) findViewById(R.id.btnPC);
        final SquareButton btnExe = (SquareButton) findViewById(R.id.btnExe);
        final SquareButton btnPM = (SquareButton) findViewById(R.id.btnPM);
        final SquareButton btnAC = (SquareButton) findViewById(R.id.btnAC);
        final TextView txtView = (TextView) findViewById(R.id.txtView);

        final Map<String, String> calc = new HashMap<String, String>();
        calc.put("reset", "false");
        calc.put("decimal", "false");
        calc.put("num", "");
        calc.put("operation", "");

        final DecimalFormat df = new DecimalFormat("#.######");
        df.setRoundingMode(RoundingMode.DOWN);

        View.OnClickListener clickListener = new View.OnClickListener() {

            @Override
            public void onClick(View view) {
                String text = "";

                // 사칙연산자일 경우
                if (((SquareButton) view).getText().equals("＋") || ((SquareButton) view).getText().equals("－") || ((SquareButton) view).getText().equals("×") || ((SquareButton) view).getText().equals("÷")) {
                    if (!calc.get("num").equals("")) {  // 미리 입력된 숫자가 있다면 연산 결과를 보여준 후 계산
                        Calc();
                    }
                    calc.put("operation", (String) ((SquareButton) view).getText());
                    calc.put("num", (String) txtView.getText());
                    calc.put("reset", "true");
                } else if (((SquareButton) view).getText().equals("AC")) {  // AC버튼을 눌렀을 경우, 숫자가 있으면 숫자 초기화, 숫자가 없으면(0) 리셋
                    if (txtView.getText().equals("0")) {
                        calc.put("decimal", "false");
                        calc.put("num", "");
                        calc.put("operation", "");
                    } else {
                        calc.put("decimal", "false");
                        txtView.setText("0");
                    }
                } else if (((SquareButton) view).getText().equals("+/-")) {   // +/- 버튼을 눌렀을 경우 -1을 곱하여 부호를 변경
                        txtView.setText(df.format(Double.parseDouble((String) txtView.getText()) * -1) + "");
                } else if (((SquareButton) view).getText().equals(".")) { // . 버튼을 눌렀을 경우, decimal 모드 활성화 후 소수점을 붙임
                    if (calc.get("decimal").equals("false") && !calc.get("reset").equals("true")) {
                        calc.put("decimal", "true");
                        txtView.setText((String) txtView.getText() + ".");
                    }
                } else if (((SquareButton) view).getText().equals("%")) { // % 버튼을 눌렀을 경우, 퍼센트 계산을 위해 100으로 나눔
                    double pc_result = Double.parseDouble((String) txtView.getText()) * 0.01;
                    txtView.setText(df.format(pc_result) + "");
                } else if (((SquareButton) view).getText().equals("＝")) { // = 버튼을 눌렀을 경우 연산
                    Calc();
                } else {    // 나머지 경우, 숫자 입력으로 처리
                    if (calc.get("reset").equals("true")) {
                        calc.put("reset", "false");
                        calc.put("decimal", "false");
                        text = (String) ((SquareButton) view).getText();
                        txtView.setText(Integer.parseInt(text) + "");
                    } else {
                        text = (String) txtView.getText();
                        text += ((SquareButton) view).getText();
                        txtView.setText(df.format(Double.parseDouble(text)));
                    }
                }
            }

            private void Calc() {
                if (!calc.get("num").equals("")) {   // 저장된 숫자가 있을 때만 연산
                    double num1 = Double.parseDouble(calc.get("num"));
                    double num2 = Double.parseDouble((String) txtView.getText());
                    double result = 0;

                    if (calc.get("operation").equals("＋")) {
                        result = num1 + num2;
                    } else if (calc.get("operation").equals("－")) {
                        result = num1 - num2;
                    } else if (calc.get("operation").equals("×")) {
                        result = num1 * num2;
                    } else if (calc.get("operation").equals("÷")) {
                        if (num2 == 0) {    // 0으로 나눌 경우 에러 메시지
                            Toast.makeText(MainActivity.this, "Cant't divide 0", Toast.LENGTH_SHORT).show();
                            calc.put("reset", "true");
                            return;
                        } else {
                            result = num1 / num2;
                        }
                    } else {
                        return;
                    }

                    calc.put("reset", "true");
                    calc.put("num", "");
                    calc.put("operation", "");
                    txtView.setText(df.format(result) + "");
                }
            }
        };

        btn0.setOnClickListener(clickListener);
        btn1.setOnClickListener(clickListener);
        btn2.setOnClickListener(clickListener);
        btn3.setOnClickListener(clickListener);
        btn4.setOnClickListener(clickListener);
        btn5.setOnClickListener(clickListener);
        btn6.setOnClickListener(clickListener);
        btn7.setOnClickListener(clickListener);
        btn8.setOnClickListener(clickListener);
        btn9.setOnClickListener(clickListener);
        btnDot.setOnClickListener(clickListener);
        btnAdd.setOnClickListener(clickListener);
        btnSub.setOnClickListener(clickListener);
        btnMul.setOnClickListener(clickListener);
        btnDiv.setOnClickListener(clickListener);
        btnPC.setOnClickListener(clickListener);
        btnExe.setOnClickListener(clickListener);
        btnPM.setOnClickListener(clickListener);
        btnAC.setOnClickListener(clickListener);
    }
}
