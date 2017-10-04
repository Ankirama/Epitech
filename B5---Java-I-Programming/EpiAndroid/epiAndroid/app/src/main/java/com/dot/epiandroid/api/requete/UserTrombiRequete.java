package com.dot.epiandroid.api.requete;

import android.app.Activity;

import com.dot.epiandroid.api.SessionManager;
import com.dot.epiandroid.api.model.User;
import com.dot.epiandroid.presenter.dialog.UserTrombiPresenter;
import com.google.gson.annotations.SerializedName;

import retrofit.Callback;
import retrofit.Response;
import retrofit.Retrofit;

/**
 * Created by doT on 19/01/2016.
 */
public class UserTrombiRequete implements Callback<User> {
    private Activity activity;

    public UserTrombiRequete(Activity activity){
        this.activity = activity;
    }

    @Override
    public void onResponse(Response<User> response, Retrofit retrofit) {
        if (response.code() == 200) {
            new UserTrombiPresenter(activity, response.body()).show();
        } else
            SessionManager.getInstance().ErrorCall(response.errorBody());
    }

    @Override
    public void onFailure(Throwable t) {

    }
}
