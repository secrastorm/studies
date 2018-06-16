package com.secra.calculator;

import android.content.Context;
import android.icu.text.MeasureFormat;
import android.icu.util.Measure;
import android.util.AttributeSet;
import android.widget.Button;

public class SquareButton extends android.support.v7.widget.AppCompatButton {

    public SquareButton(Context context) {
        super(context);
    }

    public SquareButton(Context context, AttributeSet attrs) {
        super(context, attrs);
    }

    public SquareButton(Context context, AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
    }

    @Override
    public void onMeasure(int widthMeasureSpec, int heightMeasureSpec) {
        super.onMeasure(widthMeasureSpec, heightMeasureSpec);
        int width = MeasureSpec.getSize(widthMeasureSpec);
        int height = MeasureSpec.getSize(heightMeasureSpec);
        int size = width > height ? height : width;

        // 0 버튼 사이즈 조정
        if (getText().equals("0")) {
            setMeasuredDimension(size, size / 2);
            setTextSize((float) size / 16);
            setPadding(0, 0, size / 2, 0);
        } else {
            setMeasuredDimension(size, size);
            setTextSize((float) size / 8);
        }
    }
}
