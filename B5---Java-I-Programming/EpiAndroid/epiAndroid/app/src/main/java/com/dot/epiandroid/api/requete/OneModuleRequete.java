package com.dot.epiandroid.api.requete;

import com.dot.epiandroid.api.SessionManager;
import com.dot.epiandroid.api.model.Module;
import com.dot.epiandroid.presenter.dialog.OneModulePresenter;
import com.dot.epiandroid.presenter.fragment.ModulesPresenter;
import com.dot.epiandroid.view.fragment.ModulesFragment;

import retrofit.Callback;
import retrofit.Response;
import retrofit.Retrofit;

/**
 * Created by doT on 16/01/2016.
 */
public class OneModuleRequete implements Callback<Module> {
    private ModulesFragment modulesFragment;
    private ModulesPresenter modulesPresenter;

    public OneModuleRequete(ModulesFragment modulesFragment, ModulesPresenter modulesPresenter){
        this.modulesFragment = modulesFragment;
        this.modulesPresenter = modulesPresenter;
    }

    @Override
    public void onResponse(Response<Module> response, Retrofit retrofit) {
        if (response.code() == 200) {
            OneModulePresenter oneModulePresenter = new OneModulePresenter(this.modulesFragment.getActivity(), response.body(), modulesPresenter);
            oneModulePresenter.show();
        } else
            SessionManager.getInstance().ErrorCall(response.errorBody());
    }

    @Override
    public void onFailure(Throwable t) {
    }
}
