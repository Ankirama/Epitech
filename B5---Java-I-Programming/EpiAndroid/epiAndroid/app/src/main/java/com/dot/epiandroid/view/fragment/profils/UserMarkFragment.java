package com.dot.epiandroid.view.fragment.profils;

import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ListView;

import com.dot.epiandroid.R;
import com.dot.epiandroid.adaptater.fragment.UserMarkAdaptater;
import com.dot.epiandroid.adaptater.fragment.UserProjectAdaptater;
import com.dot.epiandroid.api.model.UserMark;
import com.dot.epiandroid.api.model.UserProject;
import com.dot.epiandroid.presenter.fragment.profils.UserMarkPresenter;
import com.dot.epiandroid.presenter.fragment.profils.UserProjectPresenter;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by doT on 18/01/2016.
 */
public class UserMarkFragment extends Fragment {
    private List<UserMark.Mark> userMark;
    private UserMarkAdaptater userMarkAdaptater;
    private UserMarkPresenter userMarkPresenter;

    @Nullable
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View rootView = (View) inflater.inflate(R.layout.user_mark, container, false);

        this.userMarkPresenter = new UserMarkPresenter(this);

        this.userMark = new ArrayList<>();
        this.userMarkAdaptater = new UserMarkAdaptater(this.getActivity().getApplicationContext(), this.userMark);

        ListView listView = (ListView) rootView.findViewById(R.id.marks);
        listView.setAdapter(this.userMarkAdaptater);
        listView.setOnItemClickListener(this.userMarkPresenter);

        return rootView;
    }

    public void setUserMarks(List<UserMark.Mark> list){
        this.userMark.addAll(list);
        this.userMarkAdaptater.notifyDataSetChanged();
    }
}
