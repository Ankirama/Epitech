package com.dot.epiandroid.presenter.activity;

import android.util.Log;
import android.view.View;
import android.widget.Toast;

import com.dot.epiandroid.api.ApiService;
import com.dot.epiandroid.api.model.*;
import com.dot.epiandroid.view.activity.Login;
import com.dot.epiandroid.api.SessionManager;

import retrofit.Callback;
import retrofit.Response;
import retrofit.Retrofit;

/**
 * Created by doT on 06/01/2016.
 */
public class LoginPresenter {
    private String usernameUser;
    private Login login;

    public LoginPresenter(Login login){
        this.login = login;
    }

    public void loginComplete(Token token){
        SessionManager.getInstance().createLoginSession(this.usernameUser, token.token);
        login.loginComplete();
    }

    public View.OnClickListener loginButton(){
        return new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                usernameUser = login.getUserName();
                ApiService.getApiService().getToken(login.getUserName(), login.getPassword()).enqueue(new LoginRequete(LoginPresenter.this));
            }
        };
    }
}
