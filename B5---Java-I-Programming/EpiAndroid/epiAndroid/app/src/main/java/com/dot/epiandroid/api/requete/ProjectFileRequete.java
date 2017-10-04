package com.dot.epiandroid.api.requete;

import android.content.Context;

import com.dot.epiandroid.api.SessionManager;
import com.dot.epiandroid.api.model.ProjectFile;
import com.dot.epiandroid.presenter.dialog.ProjectPresenter;
import com.google.gson.annotations.SerializedName;

import java.util.List;

import retrofit.Callback;
import retrofit.Response;
import retrofit.Retrofit;

/**
 * Created by doT on 30/01/2016.
 */
public class ProjectFileRequete implements Callback<List<ProjectFile>> {
    private ProjectPresenter projectPresenter;

    public ProjectFileRequete(Context context, ProjectPresenter projectPresenter){
        this.projectPresenter = projectPresenter;
    }

    @Override
    public void onResponse(Response<List<ProjectFile>> response, Retrofit retrofit) {
        if (response.code() == 200)
            this.projectPresenter.setList(response.body());
        else
            SessionManager.getInstance().ErrorCall(response.errorBody());
    }

    @Override
    public void onFailure(Throwable t) {

    }
}
