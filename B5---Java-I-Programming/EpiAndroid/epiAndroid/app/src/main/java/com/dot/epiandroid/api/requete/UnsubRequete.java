package com.dot.epiandroid.api.requete;

import android.content.Context;
import android.widget.Button;
import android.widget.Toast;

import com.dot.epiandroid.R;
import com.dot.epiandroid.api.SessionManager;
import com.dot.epiandroid.api.model.Planning;
import com.dot.epiandroid.api.model.SimpleUser;
import com.dot.epiandroid.api.model.UserProject;
import com.dot.epiandroid.api.model.UserProjectResponse;
import com.dot.epiandroid.presenter.fragment.PlanningPresenter;

import retrofit.Callback;
import retrofit.Response;
import retrofit.Retrofit;

/**
 * Created by doT on 25/01/2016.
 */
public class UnsubRequete {
    public static class UnsubEventRequete implements Callback<Planning> {
        private Button button;
        private Context context;
        private PlanningPresenter planningPresenter;

        public UnsubEventRequete(Context context, Button button, PlanningPresenter planningPresenter){
            this.button = button;
            this.context = context;
            this.planningPresenter = planningPresenter;
        }

        @Override
        public void onResponse(Response<Planning> response, Retrofit retrofit) {
            if (response.body() != null){
                this.button.setText(R.string.unsubscribe);
                Toast.makeText(this.context, R.string.actionDone, Toast.LENGTH_LONG).show();
                this.planningPresenter.getDate();
            } else
                SessionManager.getInstance().ErrorCall(response.errorBody());
        }

        @Override
        public void onFailure(Throwable t) {

        }
    }

    public static class UnsubModuleRequete implements Callback<SimpleUser> {
        private Context context;
        private Button button;

        public UnsubModuleRequete(Context context, Button button){
            this.context = context;
            this.button = button;
        }

        @Override
        public void onResponse(Response<SimpleUser> response, Retrofit retrofit) {
            if (response.code() == 200) {
                Toast.makeText(context, R.string.unsubText, Toast.LENGTH_LONG).show();
                if (button != null)
                    this.button.setText(R.string.subscribe);
            } else
                SessionManager.getInstance().ErrorCall(response.errorBody());
        }

        @Override
        public void onFailure(Throwable t) {
        }
    }

    public static class UnsubProjectRequete implements Callback<UserProject> {
        private Context context;
        private Button button;

        public UnsubProjectRequete(Context context, Button button){
            this.context = context;
            this.button = button;
        }

        @Override
        public void onResponse(Response<UserProject> response, Retrofit retrofit) {
            if (response.code() == 200) {
                Toast.makeText(context, R.string.unsubText, Toast.LENGTH_LONG).show();
                if (button != null)
                    this.button.setText(R.string.subscribe);
            } else
                SessionManager.getInstance().ErrorCall(response.errorBody());
        }

        @Override
        public void onFailure(Throwable t) {
        }
    }
}
