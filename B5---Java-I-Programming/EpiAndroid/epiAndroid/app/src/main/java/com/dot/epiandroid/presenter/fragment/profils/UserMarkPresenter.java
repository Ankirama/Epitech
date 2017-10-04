package com.dot.epiandroid.presenter.fragment.profils;

import android.view.View;
import android.widget.AdapterView;

import com.dot.epiandroid.api.ApiService;
import com.dot.epiandroid.api.SessionManager;
import com.dot.epiandroid.api.model.UserMark;
import com.dot.epiandroid.api.model.UserProject;
import com.dot.epiandroid.api.requete.UserMarkRequete;
import com.dot.epiandroid.api.requete.UserProjectRequete;
import com.dot.epiandroid.view.fragment.profils.UserMarkFragment;
import com.dot.epiandroid.view.fragment.profils.UserProjectFragment;

import java.util.List;

/**
 * Created by doT on 18/01/2016.
 */
public class UserMarkPresenter implements AdapterView.OnItemClickListener {
    private UserMarkFragment userMarkFragment;

    public UserMarkPresenter(UserMarkFragment userMarkFragment){
        this.userMarkFragment = userMarkFragment;

        ApiService.getApiService().getMark(SessionManager.getInstance().getToken()).enqueue(new UserMarkRequete(this));
    }

    public void setUserMarks(List<UserMark.Mark> list){
        if (list != null)
            this.userMarkFragment.setUserMarks(list);
    }

    @Override
    public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
    }
}
