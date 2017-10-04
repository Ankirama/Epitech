package com.dot.epiandroid.adaptater.listener;

import android.app.Activity;
import android.view.View;
import android.widget.Button;

import com.dot.epiandroid.R;
import com.dot.epiandroid.api.ApiService;
import com.dot.epiandroid.api.SessionManager;
import com.dot.epiandroid.api.model.Planning;
import com.dot.epiandroid.api.requete.SubRequete;
import com.dot.epiandroid.api.requete.UnsubRequete;
import com.dot.epiandroid.presenter.dialog.TokenPresenter;
import com.dot.epiandroid.presenter.fragment.PlanningPresenter;

/**
 * Created by doT on 13/01/2016.
 */
public class PlanningButton implements View.OnClickListener {
    private Activity activity;
    private Button button;
    private Planning planning;
    private PlanningPresenter planningPresenter;

    public PlanningButton(Activity activity, Planning planning, Button button, PlanningPresenter planningPresenter) {
        this.button = button;
        this.activity = activity;
        this.planning = planning;
        this.planningPresenter = planningPresenter;
    }

    @Override
    public void onClick(View v) {
        if (this.button.getText().toString().equals( activity.getResources().getString(R.string.subscribe))){
            ApiService.getApiService().subscribeEvent(SessionManager.getInstance().getToken(),
                    this.planning.ScolarYear, this.planning.CodeModule, this.planning.CodeInstance,
                    this.planning.CodeActi, this.planning.CodeEvent).enqueue(new SubRequete.SubEventRequete(this.activity.getApplicationContext(),
                    this.button, planningPresenter));
        } else if (this.button.getText().toString().equals(activity.getResources().getString(R.string.unsubscribe))){
            ApiService.getApiService().unsubscribeEvent(SessionManager.getInstance().getToken(),
                    this.planning.ScolarYear, this.planning.CodeModule, this.planning.CodeInstance,
                    this.planning.CodeActi, this.planning.CodeEvent).enqueue(new UnsubRequete.UnsubEventRequete(this.activity.getApplicationContext(),
                    this.button, planningPresenter));
        } else if (this.button.getText().toString().equals( activity.getResources().getString(R.string.token))){
            TokenPresenter tokenPresenter = new TokenPresenter(activity, this.planning);
            tokenPresenter.show();
        }
    }
}
