package com.dot.epiandroid.adaptater.listener;

import android.app.Activity;
import android.support.v4.app.ActionBarDrawerToggle;
import android.support.v4.widget.DrawerLayout;
import android.view.Gravity;
import android.view.MenuItem;
import android.view.View;

import com.dot.epiandroid.R;

/**
 * Created by doT on 09/01/2016.
 */
public class ActionBarListener extends ActionBarDrawerToggle {
    private DrawerLayout drawerLayout;
    private Activity mainActivity;

    public ActionBarListener(Activity activity, DrawerLayout drawerLayout,
                             int drawerImageRes, int openDrawerContentDescRes, int closeDrawerContentDescRes) {
        super(activity, drawerLayout, drawerImageRes, openDrawerContentDescRes, closeDrawerContentDescRes);
        this.drawerLayout = drawerLayout;
        this.mainActivity = activity;
    }

    public void onDrawerClosed(View view) {
        mainActivity.getActionBar().setTitle(mainActivity.getTitle());
        mainActivity.invalidateOptionsMenu();
    }

    public void onDrawerOpened(View drawerView) {
        mainActivity.getActionBar().setTitle(mainActivity.getTitle());
        mainActivity.invalidateOptionsMenu();
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        if (item != null){
            switch (item.getItemId()){
                case android.R.id.home:
                    if (this.drawerLayout.isDrawerOpen(Gravity.LEFT)) {
                        this.drawerLayout.closeDrawer(Gravity.LEFT);
                    } else {
                        if (this.drawerLayout.isDrawerOpen(Gravity.RIGHT))
                            this.drawerLayout.closeDrawer(Gravity.RIGHT);
                        this.drawerLayout.openDrawer(Gravity.LEFT);
                    }
                    break;
                case R.id.slide_right_button:
                    if (this.drawerLayout.isDrawerOpen(Gravity.RIGHT)) {
                        this.drawerLayout.closeDrawer(Gravity.RIGHT);
                    } else {
                        if (this.drawerLayout.isDrawerOpen(Gravity.LEFT))
                            this.drawerLayout.closeDrawer(Gravity.LEFT);
                        this.drawerLayout.openDrawer(Gravity.RIGHT);
                    }
                    break;
            }
        }
        return false;
    }
}
