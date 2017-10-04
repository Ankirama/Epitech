package com.dot.epiandroid.view.activity;

import android.app.NotificationManager;
import android.app.PendingIntent;
import android.app.SearchManager;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.os.Message;
import android.preference.PreferenceManager;
import android.support.design.widget.NavigationView;
import android.support.v4.app.NotificationCompat;
import android.support.v4.app.TaskStackBuilder;
import android.support.v4.view.GravityCompat;
import android.support.v4.widget.DrawerLayout;
import android.support.v7.app.ActionBarDrawerToggle;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.SearchView;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.LinearLayout;

import com.dot.epiandroid.R;
import com.dot.epiandroid.api.ApiService;
import com.dot.epiandroid.api.SessionManager;
import com.dot.epiandroid.presenter.NotificationPresenter;
import com.dot.epiandroid.presenter.activity.MainActivityPresenter;
import com.dot.epiandroid.presenter.MessagePresenter;
import com.dot.epiandroid.presenter.dialog.TokenPresenter;
import com.dot.epiandroid.view.service.MessageService;

public class MainActivity extends AppCompatActivity {
    private MainActivityPresenter mainActivityPresenter;
    private MessagePresenter messagePresenter;

    @Override
protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        this.mainActivityPresenter = new MainActivityPresenter(this);

        SessionManager.getInstance().initSession(this);
        SessionManager.getInstance().checkLogin();

        if (savedInstanceState == null)
            this.mainActivityPresenter.displayView(R.id.header);

        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        DrawerLayout drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
        ActionBarDrawerToggle toggle = new ActionBarDrawerToggle(
                this, drawer, toolbar, R.string.navigation_drawer_open, R.string.navigation_drawer_close);
        drawer.setDrawerListener(toggle);
        toggle.syncState();

        LinearLayout header = (LinearLayout) findViewById(R.id.header);
        header.setOnClickListener(this.mainActivityPresenter.headerClick());

        NavigationView navigationViewLeft = (NavigationView) findViewById(R.id.slideleft);
        navigationViewLeft.setNavigationItemSelectedListener(this.mainActivityPresenter.slideLeft());

        NavigationView navigationViewRight = (NavigationView) findViewById(R.id.slideright);
        navigationViewRight.setNavigationItemSelectedListener(this.mainActivityPresenter.slideRight());

        if (SessionManager.getInstance().isLoggedIn()) {
            this.messagePresenter = new MessagePresenter(navigationViewRight.getMenu(), this);

            navigationViewRight.setNavigationItemSelectedListener(this.messagePresenter.showNotification());

            if (PreferenceManager.getDefaultSharedPreferences(this).getBoolean("pref_notif_activated", false))
                startService(new Intent(this, MessageService.class));
        }
    }

    @Override
    public void onBackPressed() {
        DrawerLayout drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
        if (drawer.isDrawerOpen(GravityCompat.START)) {
            drawer.closeDrawer(GravityCompat.START);
        } else if (getSupportFragmentManager().getBackStackEntryCount() > 1) {
            getSupportFragmentManager().beginTransaction().setCustomAnimations(R.anim.slide_in, R.anim.slide_out, R.anim.pop_enter, R.anim.pop_exit);
            getSupportFragmentManager().popBackStack();
        } else
            super.onBackPressed();
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.main, menu);

        SearchManager searchManager = (SearchManager) getSystemService(Context.SEARCH_SERVICE);
        SearchView searchView = (SearchView) menu.findItem(R.id.action_search).getActionView();
        searchView.setSearchableInfo(searchManager.getSearchableInfo(getComponentName()));
        searchView.setOnQueryTextListener(this.mainActivityPresenter.searchListener());

        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        switch (item.getItemId()){
            case R.id.slide_right_button:
                DrawerLayout drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
                drawer.openDrawer(GravityCompat.END);
                break;
        }
        return super.onOptionsItemSelected(item);
    }

    public void closeSlide(boolean slide){
        DrawerLayout drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
        drawer.closeDrawer((slide ? GravityCompat.START : GravityCompat.END));
    }

    @Override
    protected void onResume() {
        super.onResume();

        if (getIntent().getBooleanExtra("notification", false) == true){
            getIntent().removeExtra("notification");
            this.messagePresenter.getMessage(true);
        }
    }
}
