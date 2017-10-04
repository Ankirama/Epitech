package com.dot.epiandroid.view.fragment.planning;

import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.ListView;

import com.dot.epiandroid.R;
import com.dot.epiandroid.adaptater.fragment.PlanningAdaptater;
import com.dot.epiandroid.api.model.Planning;
import com.dot.epiandroid.presenter.fragment.PlanningPresenter;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by doT on 10/01/2016.
 */
public class PlanningFragment extends Fragment {
    private ListView listPlanning;
    private List<Planning> list;
    private PlanningAdaptater planningAdaptater;
    private PlanningPresenter planningPresenter;

    @Nullable
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View rootView =  inflater.inflate(R.layout.fragment_planning, container, false);

        this.planningPresenter = new PlanningPresenter(this);

        this.list = new ArrayList<Planning>();

        this.planningAdaptater = new PlanningAdaptater(getActivity(), list, planningPresenter);

        ((Button) rootView.findViewById(R.id.previous)).setOnClickListener(this.planningPresenter.previousWeek());
        ((Button) rootView.findViewById(R.id.next)).setOnClickListener(this.planningPresenter.nextWeek());
        this.listPlanning = (ListView) rootView.findViewById(R.id.listPlanning);
        listPlanning.setAdapter(this.planningAdaptater);

        return rootView;
    }

    public void setPlanning(List<Planning> planning){
        this.list.clear();
        this.list.addAll(planning);
        this.planningAdaptater.notifyDataSetChanged();
    }

    public PlanningAdaptater getAdapter(){
        return this.planningAdaptater;
    }
}
