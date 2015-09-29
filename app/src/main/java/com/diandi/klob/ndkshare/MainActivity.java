package com.diandi.klob.ndkshare;

import android.content.Intent;
import android.net.Uri;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {
    private Button intButton = null;
    private Button stringButton = null;
    private Button arrayButton = null;
    private Button md5Button;

    Engine mEngine;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mEngine=new Engine(this);
        findViewById(R.id.intbutton).setOnClickListener(this);
        findViewById(R.id.stringbutton).setOnClickListener(this);
        findViewById(R.id.md5button).setOnClickListener(this);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public void onClick(View v) {
        // TODO Auto-generated method stub
        switch (v.getId()) {
            case R.id.intbutton: {
                //调用JNI中的函数
                mEngine.callJNIInt(5);
                break;
            }
            case R.id.stringbutton: {
                //调用JNI中的函数
                mEngine.callJNIString("你好");
                break;
            }
            case R.id.md5button:
                showMsg("native 计算MD5:" +mEngine.md5("224634361436"));
                showMsg("JAVA 计算MD5:" +MD5.MD5("224634361436"));
                break;

            }
    }



    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            Uri uri = Uri.parse("https://github.com/klob");
            Intent intent = new Intent(Intent.ACTION_VIEW,uri);
            startActivity(intent);
            return true;
        }

        return super.onOptionsItemSelected(item);
    }

    public void showMsg(String msg)
    {
        Toast.makeText(this, msg, Toast.LENGTH_SHORT).show();
    }

}
