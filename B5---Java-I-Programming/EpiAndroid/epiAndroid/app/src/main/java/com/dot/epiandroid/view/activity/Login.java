package com.dot.epiandroid.view.activity;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.widget.EditText;

import com.dot.epiandroid.R;
import com.dot.epiandroid.presenter.activity.LoginPresenter;

/**
 * Created by doT on 02/12/2015.
 */
public class Login extends Activity {
    private LoginPresenter loginPresenter;
    private EditText login, password;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        setContentView(R.layout.activity_login);
        super.onCreate(savedInstanceState);

        login = (EditText) findViewById(R.id.login);
        password = (EditText) findViewById(R.id.password);

        loginPresenter = new LoginPresenter(this);

        this.findViewById(R.id.login_button).setOnClickListener(this.loginPresenter.loginButton());
    }

    @Override
    public void onBackPressed(){
        return;
    }

    public void loginComplete(){
        Intent i = new Intent(Login.this, MainActivity.class);
        startActivity(i);
        finish();
    }

    public String getUserName(){
        return login.getText().toString();
    }

    public String getPassword(){
        return password.getText().toString();
    }
}
