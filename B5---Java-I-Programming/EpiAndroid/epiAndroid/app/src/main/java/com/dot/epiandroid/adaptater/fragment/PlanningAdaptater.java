package com.dot.epiandroid.adaptater.fragment;

import android.app.Activity;
import android.content.ContentResolver;
import android.content.ContentUris;
import android.content.ContentValues;
import android.content.Context;
import android.content.Intent;
import android.database.Cursor;
import android.net.Uri;
import android.provider.CalendarContract;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.view.animation.TranslateAnimation;
import android.widget.BaseAdapter;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import com.dot.epiandroid.R;
import com.dot.epiandroid.adaptater.listener.PlanningButton;
import com.dot.epiandroid.api.model.Module;
import com.dot.epiandroid.api.model.Planning;
import com.dot.epiandroid.presenter.fragment.PlanningPresenter;

import org.w3c.dom.Text;

import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;
import java.util.List;
import java.util.TimeZone;

/**
 * Created by doT on 11/01/2016.
 */
public class PlanningAdaptater extends BaseAdapter {
    private Activity activity;
    private PlanningPresenter planningPresenter;
    private List<Planning> planning;
    private List<View> viewList;

    public PlanningAdaptater(Activity activity, List<Planning> list, PlanningPresenter planningPresenter) {
        this.activity = activity;
        this.planning = list;
        this.viewList = new ArrayList<>();
        this.planningPresenter = planningPresenter;
    }

    @Override
    public int getCount() {
        return this.planning.size();
    }

    @Override
    public Planning getItem(int position) {
        return this.planning.get(position);
    }

    @Override
    public long getItemId(int position) {
        return position;
    }

    @Override
    public View getView(final int position, View convertView, ViewGroup parent) {
        Planning tmp = getItem(position);
        if (convertView == null) {
            LayoutInflater infalInflater = (LayoutInflater) this.activity.getApplicationContext()
                    .getSystemService(Context.LAYOUT_INFLATER_SERVICE);
            convertView = infalInflater.inflate(R.layout.list_item_planning, null);
        }

        Button multpeButton = (Button) convertView.findViewById(R.id.subscribe);
        multpeButton.setOnClickListener(new PlanningButton(this.activity, tmp, multpeButton, planningPresenter));
        if (tmp.AllowRegister && tmp.ModuleRegistered && tmp.RegisterStudent) {
            multpeButton.setVisibility(View.VISIBLE);
            if (tmp.EventRegistered.equals("registered"))
                this.addToCalendar(tmp);
            multpeButton.setText((tmp.EventRegistered.equals("registered")) ? activity.getResources().getString(R.string.unsubscribe) : activity.getResources().getString(R.string.subscribe));
        } else if (tmp.AllowToken && tmp.EventRegistered.equals("registered") && tmp.RegisterStudent) {
            multpeButton.setVisibility(View.VISIBLE);
            multpeButton.setText(R.string.token);
        } else
            multpeButton.setVisibility(View.INVISIBLE);

        ((TextView) convertView.findViewById(R.id.start)).setText(tmp.Start);
        ((TextView) convertView.findViewById(R.id.end)).setText(tmp.End);
        ((TextView) convertView.findViewById(R.id.title)).setText(tmp.Title);

        convertView.setOnLongClickListener(this.planningPresenter.onItemLongClick(tmp));
        convertView.setOnClickListener(this.planningPresenter.onItemClick(tmp));

        return convertView;
    }

    private void addToCalendar(Planning planning) {
        ContentResolver contentResolver = this.activity.getContentResolver();

        Calendar start = Calendar.getInstance();
        start.set(Integer.valueOf(planning.Start.split("-")[0]),
                Integer.valueOf(planning.Start.split("-")[1]) - 1,
                Integer.valueOf(planning.Start.split("-")[2].split(" ")[0]),
                Integer.valueOf(planning.Start.split("-")[2].split(" ")[1].split(":")[0]),
                Integer.valueOf(planning.Start.split("-")[2].split(" ")[1].split(":")[1]),
                Integer.valueOf(planning.Start.split("-")[2].split(" ")[1].split(":")[2]));

        Calendar end = Calendar.getInstance();

        end.set(Integer.valueOf(planning.End.split("-")[0]),
                Integer.valueOf(planning.End.split("-")[1]) - 1,
                Integer.valueOf(planning.End.split("-")[2].split(" ")[0]),
                Integer.valueOf(planning.End.split("-")[2].split(" ")[1].split(":")[0]),
                Integer.valueOf(planning.End.split("-")[2].split(" ")[1].split(":")[1]),
                Integer.valueOf(planning.End.split("-")[2].split(" ")[1].split(":")[2]));

        String[] projection = new String[]{
                CalendarContract.Events.CALENDAR_ID,
                CalendarContract.Events.TITLE, CalendarContract.Events.DESCRIPTION,
                CalendarContract.Events.DTSTART, CalendarContract.Events.DTEND,
                CalendarContract.Events.ALL_DAY, CalendarContract.Events.EVENT_LOCATION};

        String selection = "(( " +
                CalendarContract.Events.TITLE + " == ? ) AND ( " +
                CalendarContract.Events.DTEND + " <= ? ))";

        String[] selectionArgs = new String[] {planning.Title, String.valueOf(end.getTimeInMillis())};

        Cursor cursor = this.activity.getBaseContext().getContentResolver().query(CalendarContract.Events.CONTENT_URI, projection, selection, selectionArgs, null);

        if (cursor.moveToFirst() && cursor.getString(1).equals(planning.Title)) {
            Toast.makeText(this.activity.getApplicationContext(), activity.getResources().getString(R.string.titlePlanning) +
                    cursor.getString(1) +
                    activity.getResources().getString(R.string.startPlanning) +
                    (new Date(cursor.getLong(3))).toString(), Toast.LENGTH_LONG).show();
        } else {
            ContentValues calEvent = new ContentValues();
            calEvent.put(CalendarContract.Events.CALENDAR_ID, 1);
            calEvent.put(CalendarContract.Events.TITLE, planning.Title);
            calEvent.put(CalendarContract.Events.DTSTART, start.getTimeInMillis());
            calEvent.put(CalendarContract.Events.DTEND, end.getTimeInMillis());
            calEvent.put(CalendarContract.Events.EVENT_TIMEZONE, TimeZone.getDefault().getDisplayName());
            Uri uri = contentResolver.insert(CalendarContract.Events.CONTENT_URI, calEvent);

            ContentValues values = new ContentValues();
            values.put(CalendarContract.Reminders.EVENT_ID, Long.parseLong(uri.getLastPathSegment()));
            values.put(CalendarContract.Reminders.METHOD, 1);
            values.put(CalendarContract.Reminders.MINUTES, 10);
            contentResolver.insert(CalendarContract.Reminders.CONTENT_URI, values);
        }
    }

    private void deleteEvent(int id) {
        if (id != 0) {
            Uri event = ContentUris.withAppendedId(CalendarContract.Events.CONTENT_URI, Integer.valueOf(id));
            int uri = this.activity.getContentResolver().delete(event, null, null);
        }
    }


    private int getEventId(String eventtitle) {
        int result = 0;
        String projection[] = {"_id", "title"};
        Cursor cursor = activity.getContentResolver().query(CalendarContract.Events.CONTENT_URI, null, null, null, null);

        if (cursor.moveToFirst()) {
            String calName;
            String calID;

            do {
                calName = cursor.getString(cursor.getColumnIndex(projection[1]));
                calID = cursor.getString(cursor.getColumnIndex(projection[0]));
                if (calName != null && calName.contains(eventtitle)) {
                    result = Integer.parseInt(calID);
                }
            } while (cursor.moveToNext());
            cursor.close();
        }
        return result;
    }
}
