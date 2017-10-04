package com.dot.epiandroid.presenter.activity;

import android.content.Intent;
import android.support.design.widget.NavigationView;
import android.support.v4.app.Fragment;
import android.support.v7.widget.SearchView;
import android.util.Log;
import android.view.MenuItem;
import android.view.View;

import com.dot.epiandroid.BuildConfig;
import com.dot.epiandroid.R;
import com.dot.epiandroid.api.ApiService;
import com.dot.epiandroid.api.SessionManager;
import com.dot.epiandroid.presenter.UserPresenter;
import com.dot.epiandroid.presenter.dialog.TokenPresenter;
import com.dot.epiandroid.view.activity.MainActivity;
import com.dot.epiandroid.view.activity.Settings;
import com.dot.epiandroid.view.fragment.HomeFragment;
import com.dot.epiandroid.view.fragment.ModulesFragment;
import com.dot.epiandroid.view.fragment.TrombiFragment;
import com.dot.epiandroid.view.fragment.planning.PlanningFragment;
import com.dot.epiandroid.view.fragment.profils.ProfilFragment;

/**
 * Created by doT on 06/01/2016.
 */
public class MainActivityPresenter {
    private ProfilFragment profilFragment;
    private MainActivity mainActivity;

    public MainActivityPresenter(MainActivity mainActivity){
        this.mainActivity = mainActivity;
    }

    public void displayView(int id){
        Fragment fragment = null;
        switch (id){
            case R.id.header:
                if (profilFragment == null) {
                    profilFragment = new ProfilFragment();
                    profilFragment.setMainProfil((NavigationView) this.mainActivity.findViewById(R.id.slideleft));
                }
                changeFragment(profilFragment);
                break;
            case R.id.nav_planning:
                fragment = new PlanningFragment();
                break;
            case R.id.nav_acceuil:
                fragment = new HomeFragment();
                break;
            case R.id.nav_module:
                fragment = new ModulesFragment();
                break;
            case R.id.nav_trombi:
                fragment = new TrombiFragment();
                break;
            case R.id.nav_settings:
                this.mainActivity.startActivity(new Intent(this.mainActivity, Settings.class));
                break;
            case R.id.nav_logout:
                SessionManager.getInstance().logoutUser();
                break;
        }
        if (fragment != null)
            changeFragment(fragment);
    }

    public void changeFragment(Fragment fragment){
        if (fragment != null) {
            this.mainActivity.getSupportFragmentManager().beginTransaction().setCustomAnimations(R.anim.slide_in, R.anim.slide_out).replace(R.id.frame_container, fragment).addToBackStack("main").commit();
        }
    }

    public NavigationView.OnNavigationItemSelectedListener slideLeft(){
        return new NavigationView.OnNavigationItemSelectedListener() {
            @Override
            public boolean onNavigationItemSelected(MenuItem menuItem) {
                displayView(menuItem.getItemId());
                mainActivity.closeSlide(true);
                return true;
            }
        };
    }

    public NavigationView.OnNavigationItemSelectedListener slideRight(){
        return new NavigationView.OnNavigationItemSelectedListener() {
            @Override
            public boolean onNavigationItemSelected(MenuItem menuItem) {
                mainActivity.closeSlide(false);
                return true;
            }
        };
    }

    public View.OnClickListener headerClick(){
        return new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                displayView(R.id.header);
                mainActivity.closeSlide(true);
            }
        };
    }

    public SearchView.OnQueryTextListener searchListener(){
        return new SearchView.OnQueryTextListener() {
            @Override
            public boolean onQueryTextSubmit(String query) {
                ApiService.getApiService().getUser(SessionManager.getInstance().getToken(), query).enqueue(new UserPresenter(mainActivity));
                return false;
            }

            @Override
            public boolean onQueryTextChange(String newText) {
                return false;
            }
        };
    }
}
