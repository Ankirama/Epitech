package com.dot.epiandroid.api.requete;

import com.dot.epiandroid.api.SessionManager;
import com.dot.epiandroid.api.model.InformationStart;
import com.dot.epiandroid.presenter.fragment.HomePresenter;
import com.google.gson.annotations.SerializedName;

import retrofit.Callback;
import retrofit.Response;
import retrofit.Retrofit;

/**
 * Created by doT on 30/01/2016.
 */
public class HomeRequete implements Callback<InformationStart>{
    private HomePresenter homePresenter;

    public HomeRequete(HomePresenter homePresenter){
        this.homePresenter = homePresenter;
    }

    @Override
    public void onResponse(Response<InformationStart> response, Retrofit retrofit) {
        if (response.code() == 200){
            this.homePresenter.setList(response.body());
        } else
            SessionManager.getInstance().ErrorCall(response.errorBody());
    }

    @Override
    public void onFailure(Throwable t) {

    }
}
