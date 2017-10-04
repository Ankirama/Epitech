package com.dot.epiandroid.presenter.fragment.profils;

import android.view.View;
import android.widget.AdapterView;

import com.dot.epiandroid.adaptater.fragment.UserProjectAdaptater;
import com.dot.epiandroid.api.ApiService;
import com.dot.epiandroid.api.SessionManager;
import com.dot.epiandroid.api.model.UserProject;
import com.dot.epiandroid.api.requete.UserProjectRequete;
import com.dot.epiandroid.presenter.dialog.ProjectPresenter;
import com.dot.epiandroid.view.fragment.profils.UserProjectFragment;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by doT on 18/01/2016.
 */
public class UserProjectPresenter implements AdapterView.OnItemClickListener {
    private UserProjectFragment userProjectFragment;

    public UserProjectPresenter(UserProjectFragment userProjectFragment){
        this.userProjectFragment = userProjectFragment;

        ApiService.getApiService().getProject(SessionManager.getInstance().getToken()).enqueue(new UserProjectRequete(this));
    }

    public void setUserProjects(List<UserProject> list){
        if (list != null){
            List<UserProject> listTmp = new ArrayList<>();
            for (UserProject user : list) {
                if (user.Project != null && !user.Project.equals("null"))
                    listTmp.add(user);
            }
            this.userProjectFragment.setUserProjects(listTmp);
        }
    }

    @Override
    public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
        ProjectPresenter projectPresenter = new ProjectPresenter(userProjectFragment.getActivity(), userProjectFragment.getAdapter().getItem(position));
        projectPresenter.show();
    }
}
