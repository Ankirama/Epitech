package com.dot.epiandroid.presenter.fragment;

import android.content.Intent;
import android.provider.CalendarContract;
import android.util.Log;
import android.view.View;
import android.widget.AdapterView;

import com.dot.epiandroid.R;
import com.dot.epiandroid.api.ApiService;
import com.dot.epiandroid.api.SessionManager;
import com.dot.epiandroid.api.model.Planning;
import com.dot.epiandroid.presenter.dialog.EventDialog;
import com.dot.epiandroid.view.fragment.planning.PlanningFragment;
import com.dot.epiandroid.api.requete.PlanningRequete;

import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

/**
 * Created by doT on 11/01/2016.
 */
public class PlanningPresenter {
    private SimpleDateFormat simpleDateFormat;
    private Calendar calendar;
    private int weekOfYear, year;
    private PlanningFragment planningFragment;

    public PlanningPresenter(PlanningFragment planningFragment){
        this.planningFragment = planningFragment;
        this.calendar = Calendar.getInstance();
        this.weekOfYear = calendar.get(Calendar.WEEK_OF_YEAR);
        this.year = calendar.get(Calendar.YEAR);
        this.simpleDateFormat = new SimpleDateFormat("yyyy-MM-dd");
        this.getDate();
    }

    public View.OnClickListener nextWeek(){
        return new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (weekOfYear == 52){
                    year += 1;
                    weekOfYear = 0;
                } else
                    weekOfYear += 1;
                getDate();
            }
        };
    }

    public View.OnClickListener previousWeek(){
        return new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (weekOfYear == 1){
                    year -= 1;
                    weekOfYear = 52;
                } else
                    weekOfYear -= 1;
                getDate();
            }
        };
    }

    public void getDate(){
        this.calendar.clear();
        this.calendar.set(Calendar.WEEK_OF_YEAR, this.weekOfYear);
        this.calendar.set(Calendar.YEAR, this.year);
        Date startDate = this.calendar.getTime();
        String startDateInStr = this.simpleDateFormat.format(startDate);

        this.calendar.add(Calendar.DATE, 6);
        Date enddate = this.calendar.getTime();
        String endDaString = this.simpleDateFormat.format(enddate);

        ApiService.getApiService().getPlanning(SessionManager.getInstance().getToken(),
                startDateInStr, endDaString).enqueue(new PlanningRequete(this.planningFragment));
    }

    public View.OnClickListener onItemClick(final Planning event) {
        return new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                EventDialog eventDialog = new EventDialog(planningFragment.getActivity(), event);
                eventDialog.show();
            }
        };
    }

    public View.OnLongClickListener onItemLongClick(final Planning event) {
        return new View.OnLongClickListener() {
            @Override
            public boolean onLongClick(View v) {
                if (event.EventRegistered.equals("registered")) {
                    Intent sendIntent = new Intent();
                    sendIntent.setAction(Intent.ACTION_SEND);
                    sendIntent.putExtra(Intent.EXTRA_TEXT, event.Title + " at " + event.Start);
                    sendIntent.setType("text/plain");
                    planningFragment.getActivity().startActivity(Intent.createChooser(sendIntent, planningFragment.getActivity().getResources().getString(R.string.shareTo)));
                    return true;
                }
                return false;
            }
        };
    }
}
