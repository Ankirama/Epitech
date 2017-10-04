package com.dot.epiandroid.presenter.fragment;

import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentManager;
import android.support.v4.app.FragmentStatePagerAdapter;
import android.support.v4.view.PagerAdapter;
import android.util.Log;

import com.dot.epiandroid.R;
import com.dot.epiandroid.api.ApiService;
import com.dot.epiandroid.api.SessionManager;
import com.dot.epiandroid.api.model.InformationStart;
import com.dot.epiandroid.api.requete.HomeRequete;
import com.dot.epiandroid.presenter.fragment.home.HomeModuleFragment;
import com.dot.epiandroid.view.fragment.HomeFragment;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by doT on 30/01/2016.
 */
public class HomePresenter {
    public static int NUM_PAGE = 4;
    private HomeModuleFragment module, mark, project, activity;
    private HomeFragment homeFragment;
    private PageAdapter pagerAdapter;

    public HomePresenter(HomeFragment homeFragment, FragmentManager fragmentManager){
        this.homeFragment = homeFragment;

        module = new HomeModuleFragment();
        mark = new HomeModuleFragment();
        project = new HomeModuleFragment();
        activity = new HomeModuleFragment();

        pagerAdapter = new PageAdapter(fragmentManager);

        ApiService.getApiService().getInformationUser(SessionManager.getInstance().getToken()).enqueue(new HomeRequete(this));
    }

    public void setList(InformationStart informationStart){
        List<String> tmp = new ArrayList<>();
        if (informationStart.Board.Notes != null)
            for (InformationStart.Note note : informationStart.Board.Notes) {
                tmp.add(note.Title + "\t" + note.Note);
            };
        mark.setList(tmp);
        tmp.clear();
        if (informationStart.Board.Modules != null)
            for (InformationStart.Modules module : informationStart.Board.Modules) {
                tmp.add(module.Title);
            };
        module.setList(tmp);
        tmp.clear();
        if (informationStart.Board.Projets != null)
            for (InformationStart.Project project : informationStart.Board.Projets) {
                tmp.add(project.Title);
            };
        project.setList(tmp);
        tmp.clear();
        if (informationStart.Board.Activities != null)
            for (InformationStart.Activities activities : informationStart.Board.Activities) {
                tmp.add(activities.Title);
            }
        ;
        activity.setList(tmp);
    }

    public PageAdapter getPageAdapter(){
        return this.pagerAdapter;
    }

    public class PageAdapter extends FragmentStatePagerAdapter {
        public PageAdapter(FragmentManager fm) {
            super(fm);
        }

        @Override
        public Fragment getItem(int position) {
            Fragment fragment = null;
            switch (position){
                case 0:
                    fragment = module;
                    break;
                case 1:
                    fragment = activity;
                    break;
                case 2:
                    fragment = mark;
                    break;
                case 3:
                    fragment = project;
                    break;
            }
            return fragment;
        }

        @Override
        public int getCount() {
            return NUM_PAGE;
        }

        @Override
        public CharSequence getPageTitle(int position) {
            String title = "";
            switch (position){
                case 0:
                    title = homeFragment.getActivity().getApplicationContext().getResources().getString(R.string.modules);
                    break;
                case 1:
                    title = homeFragment.getActivity().getApplicationContext().getResources().getString(R.string.activity);
                    break;
                case 2:
                    title = homeFragment.getActivity().getApplicationContext().getResources().getString(R.string.marks);
                    break;
                case 3:
                    title = homeFragment.getActivity().getApplicationContext().getResources().getString(R.string.projects);
                    break;
            }
            return title;
        }
    }
}
