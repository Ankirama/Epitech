package com.dot.epiandroid.view.fragment;

import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ListView;

import com.dot.epiandroid.R;
import com.dot.epiandroid.adaptater.fragment.ModulesAdaptater;
import com.dot.epiandroid.presenter.fragment.ModulesPresenter;

/**
 * Created by doT on 10/01/2016.
 */
public class ModulesFragment extends Fragment {
    private ListView listView;
    private ModulesPresenter modulesPresenter;

    @Nullable
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View rootView = inflater.inflate(R.layout.fragment_module, container, false);

        this.listView = (ListView) rootView.findViewById(R.id.modules);

        this.modulesPresenter = new ModulesPresenter(this);

        this.listView.setOnItemClickListener(this.modulesPresenter);

        return rootView;
    }

    public void setAdaptater(ModulesAdaptater modulesAdaptater){
        this.listView.setAdapter(modulesAdaptater);
    }
}
