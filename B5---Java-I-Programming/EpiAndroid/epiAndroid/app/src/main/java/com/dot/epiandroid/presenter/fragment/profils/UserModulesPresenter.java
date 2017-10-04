package com.dot.epiandroid.presenter.fragment.profils;

import android.widget.Toast;

import com.dot.epiandroid.api.model.*;
import com.dot.epiandroid.api.model.Error;
import com.dot.epiandroid.view.fragment.profils.UserModuleFragment;

import java.io.IOException;

import retrofit.Callback;
import retrofit.GsonConverterFactory;
import retrofit.Response;
import retrofit.Retrofit;

/**
 * Created by doT on 11/01/2016.
 */
public class UserModulesPresenter implements Callback<UserModule> {
    private UserModuleFragment modulesFragment;

    public UserModulesPresenter(UserModuleFragment modulesFragment){
        this.modulesFragment = modulesFragment;
    }

    @Override
    public void onResponse(Response<UserModule> response, Retrofit retrofit) {
        if (response.body() != null)
            this.modulesFragment.setModules(response.body());
        else {
            try {
                Error error = (Error) GsonConverterFactory.create().fromResponseBody(Error.class, Error.class.getAnnotations()).convert(response.errorBody());
                Toast.makeText(this.modulesFragment.getActivity().getApplicationContext(), error.errorBody.Message, Toast.LENGTH_LONG).show();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    @Override
    public void onFailure(Throwable t) {

    }
}
