package com.dot.epiandroid.view.fragment.profils;

import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ListView;

import com.dot.epiandroid.R;
import com.dot.epiandroid.adaptater.fragment.UserModuleAdaptater;
import com.dot.epiandroid.api.ApiService;
import com.dot.epiandroid.api.SessionManager;
import com.dot.epiandroid.api.model.UserModule;
import com.dot.epiandroid.presenter.fragment.profils.UserModulesPresenter;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by doT on 10/01/2016.
 */
public class UserModuleFragment extends Fragment implements AdapterView.OnItemClickListener{
    private ListView listView;
    private UserModuleAdaptater moduleAdaptater;
    private UserModulesPresenter modulesPresenter;
    private List<UserModule.UserModules> list;

    @Nullable
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View rootView = inflater.inflate(R.layout.fragment_module, container, false);
        list = new ArrayList<UserModule.UserModules>();
        listView = (ListView) rootView.findViewById(R.id.modules);
        listView.setOnItemClickListener(this);

        this.modulesPresenter = new UserModulesPresenter(this);
        ApiService.getApiService().getUserModule(SessionManager.getInstance().getToken()).enqueue(this.modulesPresenter);

        return rootView;
    }

    public void setModules(UserModule userModule) {
        if (userModule != null) {
            list.addAll(userModule.UserModules);
            moduleAdaptater = new UserModuleAdaptater(getActivity().getApplicationContext(), list);
            listView.setAdapter(moduleAdaptater);
            moduleAdaptater.notifyDataSetChanged();
        }
    }

    @Override
    public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
    }
}
