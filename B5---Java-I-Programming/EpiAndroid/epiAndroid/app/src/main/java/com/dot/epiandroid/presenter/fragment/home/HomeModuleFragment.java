package com.dot.epiandroid.presenter.fragment.home;

import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ListView;

import com.dot.epiandroid.R;
import com.dot.epiandroid.adaptater.fragment.HomeAdapter;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by doT on 30/01/2016.
 */
public class HomeModuleFragment extends Fragment {
    private HomeAdapter homeAdapter;
    private List<String> list;

    @Override
    public void onCreate(@Nullable Bundle savedInstanceState) {
        list = new ArrayList<>();
        homeAdapter = new HomeAdapter(getActivity().getApplicationContext(), list);
        super.onCreate(savedInstanceState);
    }

    @Nullable
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View rootView = (View) inflater.inflate(R.layout.fragment_home_module, container, false);

        ((ListView) rootView.findViewById(R.id.list)).setAdapter(homeAdapter);

        return  rootView;
    }

    public void setList(List<String> list){
        this.list.addAll(list);
        homeAdapter.notifyDataSetChanged();
    }
}
