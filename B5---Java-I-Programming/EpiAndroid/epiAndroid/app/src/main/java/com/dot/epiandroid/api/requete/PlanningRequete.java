package com.dot.epiandroid.api.requete;

import com.dot.epiandroid.api.SessionManager;
import com.dot.epiandroid.api.model.Planning;
import com.dot.epiandroid.view.fragment.planning.PlanningFragment;

import java.util.List;

import retrofit.Callback;
import retrofit.Response;
import retrofit.Retrofit;

/**
 * Created by doT on 11/01/2016.
 */
public class PlanningRequete implements Callback<List<Planning>> {
    private PlanningFragment planningFragment;

    public PlanningRequete(PlanningFragment planningFragment){
        this.planningFragment = planningFragment;
    }

    @Override
    public void onResponse(Response<List<Planning>> response, Retrofit retrofit) {
        if (response.body() != null)
            this.planningFragment.setPlanning(response.body());
        else
            SessionManager.getInstance().ErrorCall(response.errorBody());
    }

    @Override
    public void onFailure(Throwable t) {
    }
}
