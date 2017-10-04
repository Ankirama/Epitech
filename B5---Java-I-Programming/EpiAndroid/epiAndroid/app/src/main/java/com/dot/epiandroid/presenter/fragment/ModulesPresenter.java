package com.dot.epiandroid.presenter.fragment;

import android.view.View;
import android.widget.AdapterView;

import com.dot.epiandroid.adaptater.fragment.ModulesAdaptater;
import com.dot.epiandroid.api.ApiService;
import com.dot.epiandroid.api.SessionManager;
import com.dot.epiandroid.api.model.Module;
import com.dot.epiandroid.api.model.Modules;
import com.dot.epiandroid.api.model.User;
import com.dot.epiandroid.api.requete.AllModulesRequete;
import com.dot.epiandroid.api.requete.OneModuleRequete;
import com.dot.epiandroid.view.fragment.ModulesFragment;

import java.util.ArrayList;
import java.util.List;

import retrofit.Callback;
import retrofit.Response;
import retrofit.Retrofit;

/**
 * Created by doT on 14/01/2016.
 */
public class ModulesPresenter implements AdapterView.OnItemClickListener {
    private List<Module> list;
    private ModulesFragment modulesFragment;
    private ModulesAdaptater moduleAdaptater;

    public ModulesPresenter(ModulesFragment modulesFragment){
        this.modulesFragment = modulesFragment;

        this.list = new ArrayList<>();
        this.moduleAdaptater = new ModulesAdaptater(this.modulesFragment.getActivity().getApplicationContext(), list);
        this.modulesFragment.setAdaptater(moduleAdaptater);

        this.refresh();
    }

    public void setListModule(Modules modules){
        this.list.addAll(modules.Modules);
        this.moduleAdaptater.notifyDataSetChanged();
    }

    @Override
    public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
        ApiService.getApiService().getModule(SessionManager.getInstance().getToken(),
                moduleAdaptater.getItem(position).ScolarYear,
                moduleAdaptater.getItem(position).Code,
                moduleAdaptater.getItem(position).CodeInstance).enqueue(new OneModuleRequete(this.modulesFragment, this));
    }

    public void refresh(){
        ApiService.getApiService().getUser(SessionManager.getInstance().getToken(), SessionManager.getInstance().getLogin()).enqueue(new Callback<User>() {
            @Override
            public void onResponse(Response<User> response, Retrofit retrofit) {
                if (response.code() == 200)
                    ApiService.getApiService().getAllModules(SessionManager.getInstance().getToken(), String.valueOf(response.body().SchoolYear),
                            response.body().Location, response.body().CourseCode).enqueue(new AllModulesRequete(ModulesPresenter.this));
                else
                    SessionManager.getInstance().ErrorCall(response.errorBody());
            }

            @Override
            public void onFailure(Throwable t) {
            }
        });
    }
}
