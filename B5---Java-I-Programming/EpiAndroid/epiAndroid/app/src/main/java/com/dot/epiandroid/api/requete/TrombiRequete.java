package com.dot.epiandroid.api.requete;

import android.util.Log;

import com.dot.epiandroid.api.SessionManager;
import com.dot.epiandroid.api.model.Trombi;
import com.dot.epiandroid.presenter.fragment.TrombiPresenter;

import retrofit.Callback;
import retrofit.Response;
import retrofit.Retrofit;

/**
 * Created by doT on 18/01/2016.
 */
public class TrombiRequete implements Callback<Trombi> {
    private TrombiPresenter trombiPresenter;

    public TrombiRequete(TrombiPresenter trombiPresenter){
        this.trombiPresenter = trombiPresenter;
    }

    @Override
    public void onResponse(Response<Trombi> response, Retrofit retrofit) {
        if (response.code() == 200) {
            this.trombiPresenter.setTrombi(response.body().User);
        } else
            SessionManager.getInstance().ErrorCall(response.errorBody());
    }

    @Override
    public void onFailure(Throwable t) {

    }
}
