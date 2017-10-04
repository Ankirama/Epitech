package com.dot.epiandroid.api.model;

import android.widget.Toast;

import com.dot.epiandroid.api.SessionManager;
import com.dot.epiandroid.presenter.activity.LoginPresenter;
import com.dot.epiandroid.view.activity.Login;

import retrofit.Callback;
import retrofit.Response;
import retrofit.Retrofit;

/**
 * Created by doT on 25/01/2016.
 */
public class LoginRequete implements Callback<Token> {
    private LoginPresenter login;

    public LoginRequete(LoginPresenter login) {
        this.login = login;
    }

    @Override
    public void onResponse(Response<Token> response, Retrofit retrofit) {
        if (response.code() == 200) {
            login.loginComplete(response.body());
        } else
            SessionManager.getInstance().ErrorCall(response.errorBody());
    }

    @Override
    public void onFailure(Throwable t) {
    }
}