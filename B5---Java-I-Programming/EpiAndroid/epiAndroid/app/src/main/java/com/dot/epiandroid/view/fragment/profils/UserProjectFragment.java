package com.dot.epiandroid.view.fragment.profils;

import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ListView;

import com.dot.epiandroid.R;
import com.dot.epiandroid.adaptater.fragment.UserProjectAdaptater;
import com.dot.epiandroid.api.model.UserProject;
import com.dot.epiandroid.presenter.fragment.profils.UserProjectPresenter;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by doT on 18/01/2016.
 */
public class UserProjectFragment extends Fragment {
    private List<UserProject> userProjects;
    private UserProjectAdaptater userProjectAdaptater;
    private UserProjectPresenter userProjectPresenter;

    @Nullable
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View rootView = (View) inflater.inflate(R.layout.user_project, container, false);

        this.userProjectPresenter = new UserProjectPresenter(this);

        this.userProjects = new ArrayList<>();
        this.userProjectAdaptater = new UserProjectAdaptater(this.getActivity(), this.userProjects);

        ListView listView = (ListView) rootView.findViewById(R.id.projects);
        listView.setAdapter(this.userProjectAdaptater);
        listView.setOnItemClickListener(this.userProjectPresenter);

        return rootView;
    }

    public void setUserProjects(List<UserProject> list){
        this.userProjects.addAll(list);
        this.userProjectAdaptater.notifyDataSetChanged();
    }

    public UserProjectAdaptater getAdapter(){
        return this.userProjectAdaptater;
    }
}
