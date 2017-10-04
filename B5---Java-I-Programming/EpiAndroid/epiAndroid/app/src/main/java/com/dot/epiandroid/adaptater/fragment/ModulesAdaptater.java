package com.dot.epiandroid.adaptater.fragment;

import android.app.usage.UsageEvents;
import android.content.ContentResolver;
import android.content.ContentValues;
import android.content.Context;
import android.content.Intent;
import android.net.Uri;
import android.provider.CalendarContract;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.Button;
import android.widget.TextView;

import com.dot.epiandroid.R;
import com.dot.epiandroid.adaptater.listener.ModulesButton;
import com.dot.epiandroid.api.model.Module;

import java.util.Calendar;
import java.util.List;
import java.util.TimeZone;

/**
 * Created by doT on 14/01/2016.
 */
public class ModulesAdaptater extends BaseAdapter {
    private Context context;
    private List<Module> list;

    public ModulesAdaptater(Context context, List<Module> list){
        this.context = context;
        this.list = list;
    }

    @Override
    public int getCount() {
        return this.list.size();
    }

    @Override
    public Module getItem(int position) {
        return this.list.get(position);
    }

    @Override
    public long getItemId(int position) {
        return position;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        if (convertView == null) {
            LayoutInflater infalInflater = (LayoutInflater) this.context
                    .getSystemService(Context.LAYOUT_INFLATER_SERVICE);
            convertView = infalInflater.inflate(R.layout.list_item_modules, null);
        }

        Module tmp = getItem(position);
        if (tmp != null) {
            TextView registered = (TextView) convertView.findViewById(R.id.registered);
            if (tmp.Status.equals("notregistered")) {
                registered.setText(R.string.notRegistered);
            } else
                registered.setText(R.string.registered);
            ((TextView) convertView.findViewById(R.id.title)).setText(tmp.Title);
            ((TextView) convertView.findViewById(R.id.start)).setText(tmp.Begin);
            ((TextView) convertView.findViewById(R.id.end)).setText(tmp.End);
        }

        return convertView;
    }
}