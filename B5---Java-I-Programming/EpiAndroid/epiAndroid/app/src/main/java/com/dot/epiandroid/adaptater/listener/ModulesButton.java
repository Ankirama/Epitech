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

/**
 * Created by doT on 13/01/2016.
 */
public class ModulesButton implements View.OnClickListener {
    private Activity activity;
    private Button button;
    private Planning planning;

    public ModulesButton(Activity activity, Planning planning, Button button) {
        this.button = button;
        this.activity = activity;
        this.planning = planning;
    }

    @Override
    public void onClick(View v) {
        if (this.button.getText().toString().equals( activity.getResources().getString(R.string.subscribe))){
            ApiService.getApiService().subscribeModule(SessionManager.getInstance().getToken(),
                    this.planning.ScolarYear, this.planning.CodeModule, this.planning.CodeInstance)
                    .enqueue(new SubRequete.SubModuleRequete(this.activity.getApplicationContext(), this.button));
        } else if (this.button.getText().toString().equals( activity.getResources().getString(R.string.unsubscribe))) {
            ApiService.getApiService().unsubscribeModule(SessionManager.getInstance().getToken(),
                    this.planning.ScolarYear, this.planning.CodeModule, this.planning.CodeInstance)
                    .enqueue(new UnsubRequete.UnsubModuleRequete(this.activity.getApplicationContext(), this.button));
        }
    }
}
