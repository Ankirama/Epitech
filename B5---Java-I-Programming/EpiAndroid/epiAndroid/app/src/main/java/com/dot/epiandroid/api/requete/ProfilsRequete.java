package com.dot.epiandroid.api.requete;

import android.util.Log;
import com.dot.epiandroid.api.SessionManager;
import com.dot.epiandroid.api.model.User;
import com.dot.epiandroid.presenter.fragment.profils.ProfilsPresenter;

import retrofit.Callback;
import retrofit.Response;
import retrofit.Retrofit;

/**
 * Created by doT on 13/01/2016.
 */
public class ProfilsRequete implements Callback<User> {
    private ProfilsPresenter profilsPresenter;

    public ProfilsRequete(ProfilsPresenter profilsPresenter){
        this.profilsPresenter = profilsPresenter;
    }

    @Override
    public void onResponse(Response<User> response, Retrofit retrofit) {
        if (response.body() != null) {
            this.profilsPresenter.setProfil(response.body());
        } else
            SessionManager.getInstance().ErrorCall(response.errorBody());
    }

    @Override
    public void onFailure(Throwable t) {
    }
}
