package com.dot.epiandroid.api.requete;

import android.util.Log;

import com.dot.epiandroid.api.SessionManager;
import com.dot.epiandroid.api.model.UserMark;
import com.dot.epiandroid.presenter.fragment.profils.UserMarkPresenter;

import java.util.List;

import retrofit.Callback;
import retrofit.Response;
import retrofit.Retrofit;

/**
 * Created by doT on 18/01/2016.
 */
public class UserMarkRequete implements Callback<UserMark> {
    private UserMarkPresenter userMarkPresenter;

    public UserMarkRequete(UserMarkPresenter userMarkPresenter){
        this.userMarkPresenter = userMarkPresenter;
    }

    @Override
    public void onResponse(Response<UserMark> response, Retrofit retrofit) {
        if (response.code() == 200)
            this.userMarkPresenter.setUserMarks(response.body().Mark);
        else
            SessionManager.getInstance().ErrorCall(response.errorBody());
    }

    @Override
    public void onFailure(Throwable t) {
    }
}
