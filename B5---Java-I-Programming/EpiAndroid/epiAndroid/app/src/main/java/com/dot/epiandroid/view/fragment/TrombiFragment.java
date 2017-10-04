package com.dot.epiandroid.view.fragment;

import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.ListView;
import android.widget.Spinner;

import com.dot.epiandroid.R;
import com.dot.epiandroid.adaptater.fragment.TrombiAdaptater;
import com.dot.epiandroid.api.model.Trombi;
import com.dot.epiandroid.presenter.fragment.TrombiPresenter;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by doT on 18/01/2016.
 */
public class TrombiFragment extends Fragment {
    private List<Trombi.UserTrombi> list;
    private Spinner course;
    private EditText location, schoolyear, promo;
    private TrombiAdaptater trombiAdaptater;
    private TrombiPresenter trombiPresenter;

    @Nullable
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View rootView = (View) inflater.inflate(R.layout.fragment_trombi, container, false);

        this.location = (EditText) rootView.findViewById(R.id.location);
        this.schoolyear = (EditText) rootView.findViewById(R.id.schoolYear);
        this.promo = (EditText) rootView.findViewById(R.id.promo);

        this.trombiPresenter = new TrombiPresenter(this);

        this.list = new ArrayList<>();
        this.trombiAdaptater = new TrombiAdaptater(this.getActivity(), list);

        ListView listView = (ListView) rootView.findViewById(R.id.trombi);
        listView.setOnItemClickListener(this.trombiPresenter);
        listView.setAdapter(this.trombiAdaptater);
        listView.setOnScrollListener(this.trombiPresenter.listBottom());

        ((LinearLayout) rootView.findViewById(R.id.search)).setOnClickListener(this.trombiPresenter.searchListener());
        this.course = (Spinner) rootView.findViewById(R.id.spinner);

        ArrayAdapter<CharSequence> arrayAdapter = ArrayAdapter.createFromResource(this.getActivity(), R.array.course, android.R.layout.simple_spinner_item);
        arrayAdapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);

        this.course.setAdapter(arrayAdapter);

        return rootView;
    }

    public void setTrombi(List<Trombi.UserTrombi> list){
        this.list.addAll(list);
        this.trombiAdaptater.notifyDataSetChanged();
    }

    public EditText getLocation(){
        return this.location;
    }

    public EditText getSchoolyear(){
        return this.schoolyear;
    }

    public String getCourse(){
        if(this.course != null) {
            String[] arrayAdapter = getActivity().getApplicationContext().getResources().getStringArray(R.array.course);
            return arrayAdapter[this.course.getSelectedItemPosition()];
        }
        return null;
    }

    public EditText getPromo(){
        return this.promo;
    }

    public TrombiAdaptater getAdapter(){
        return this.trombiAdaptater;
    }
}
