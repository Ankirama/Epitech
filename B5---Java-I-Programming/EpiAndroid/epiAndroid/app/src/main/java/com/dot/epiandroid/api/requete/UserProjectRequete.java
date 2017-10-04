package com.dot.epiandroid.api.requete;

import com.dot.epiandroid.api.SessionManager;
import com.dot.epiandroid.api.model.UserProject;
import com.dot.epiandroid.presenter.fragment.profils.UserProjectPresenter;
import com.google.gson.annotations.SerializedName;

import java.util.List;

import retrofit.Callback;
import retrofit.Response;
import retrofit.Retrofit;

/**
 * Created by doT on 18/01/2016.
 */
public class UserProjectRequete implements Callback<List<UserProject>> {
    private UserProjectPresenter userProjectPresenter;

    public UserProjectRequete(UserProjectPresenter userProjectPresenter){
        this.userProjectPresenter = userProjectPresenter;
    }

    @Override
    public void onResponse(Response<List<UserProject>> response, Retrofit retrofit) {
        if (response.code() == 200)
            this.userProjectPresenter.setUserProjects(response.body());
        else
            SessionManager.getInstance().ErrorCall(response.errorBody());
    }

    @Override
    public void onFailure(Throwable t) {

    }
}
