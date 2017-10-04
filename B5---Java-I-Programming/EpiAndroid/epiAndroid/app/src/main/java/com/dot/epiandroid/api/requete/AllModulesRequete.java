package com.dot.epiandroid.api.requete;

import com.dot.epiandroid.api.SessionManager;
import com.dot.epiandroid.api.model.Modules;
import com.dot.epiandroid.presenter.fragment.ModulesPresenter;

import retrofit.Callback;
import retrofit.Response;
import retrofit.Retrofit;

/**
 * Created by doT on 14/01/2016.
 */
public class AllModulesRequete implements Callback<Modules> {
    private ModulesPresenter modulesPresenter;

    public AllModulesRequete(ModulesPresenter modulesPresenter){
        this.modulesPresenter = modulesPresenter;
    }

    @Override
    public void onResponse(Response<Modules> response, Retrofit retrofit) {
        if (response.code() == 200)
            this.modulesPresenter.setListModule(response.body());
        else
            SessionManager.getInstance().ErrorCall(response.errorBody());
    }

    @Override
    public void onFailure(Throwable t) {
    }
}
