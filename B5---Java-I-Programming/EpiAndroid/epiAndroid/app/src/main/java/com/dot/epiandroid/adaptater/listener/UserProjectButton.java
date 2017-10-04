package com.dot.epiandroid.adaptater.listener;

import android.app.Activity;
import android.content.Context;
import android.util.Log;
import android.view.View;
import android.widget.Button;

import com.dot.epiandroid.R;
import com.dot.epiandroid.api.ApiService;
import com.dot.epiandroid.api.SessionManager;
import com.dot.epiandroid.api.model.Planning;
import com.dot.epiandroid.api.model.UserProject;
import com.dot.epiandroid.api.requete.SubRequete;
import com.dot.epiandroid.api.requete.UnsubRequete;
import com.dot.epiandroid.presenter.dialog.TokenPresenter;
import com.dot.epiandroid.presenter.fragment.PlanningPresenter;

/**
 * Created by doT on 27/01/2016.
 */
public class UserProjectButton implements View.OnClickListener {
    private Context context;
    private Button button;
    private UserProject userProject;

    public UserProjectButton(Context context, UserProject userProject, Button button) {
        this.button = button;
        this.context = context;
        this.userProject = userProject;
    }

    @Override
    public void onClick(View v) {
        if (this.button.getText().toString().equals(context.getResources().getString(R.string.subscribe))){
            ApiService.getApiService().subscribeProject(SessionManager.getInstance().getToken(),
                    this.userProject.ScolarYear, this.userProject.CodeModule, this.userProject.CodeInstance,
                    this.userProject.CodeActi).enqueue(new SubRequete.SubProjectRequete(this.context, this.button));
        } else if (this.button.getText().toString().equals(context.getResources().getString(R.string.unsubscribe))){
            ApiService.getApiService().unsubscribeProject(SessionManager.getInstance().getToken(),
                    this.userProject.ScolarYear, this.userProject.CodeModule, this.userProject.CodeInstance,
                    this.userProject.CodeActi).enqueue(new UnsubRequete.UnsubProjectRequete(this.context, this.button));
        }
    }
}
