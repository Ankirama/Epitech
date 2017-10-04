package com.dot.epiandroid.view.fragment;

import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.design.widget.TabLayout;
import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentManager;
import android.support.v4.app.FragmentStatePagerAdapter;
import android.support.v4.view.PagerAdapter;
import android.support.v4.view.ViewPager;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import com.dot.epiandroid.R;
import com.dot.epiandroid.api.model.InformationStart;
import com.dot.epiandroid.presenter.fragment.HomePresenter;
import com.dot.epiandroid.presenter.fragment.home.HomeModuleFragment;

import java.util.ArrayList;
import java.util.List;

import static com.dot.epiandroid.presenter.fragment.HomePresenter.*;

/**
 * Created by doT on 30/01/2016.
 */
public class HomeFragment extends Fragment {
    private ViewPager viewPager;
    private HomePresenter homePresenter;
    @Nullable
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View rootView = (View) inflater.inflate(R.layout.fragment_home, container, false);

        homePresenter = new HomePresenter(this, getChildFragmentManager());

        TabLayout tabLayout = (TabLayout) rootView.findViewById(R.id.tab);
        tabLayout.addTab(tabLayout.newTab().setText(R.string.activity));
        tabLayout.addTab(tabLayout.newTab().setText(R.string.marks));
        tabLayout.addTab(tabLayout.newTab().setText(R.string.projects));
        tabLayout.addTab(tabLayout.newTab().setText(R.string.modules));

        viewPager = (ViewPager) rootView.findViewById(R.id.viewpager);
        viewPager.setAdapter(homePresenter.getPageAdapter());
        viewPager.setOffscreenPageLimit(NUM_PAGE);
        tabLayout.setupWithViewPager(viewPager);

        return rootView;
    }
}
