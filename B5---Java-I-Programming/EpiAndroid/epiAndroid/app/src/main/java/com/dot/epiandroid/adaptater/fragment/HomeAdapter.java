package com.dot.epiandroid.adaptater.fragment;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.TextView;

import com.dot.epiandroid.R;
import com.google.gson.annotations.SerializedName;

import java.util.List;

/**
 * Created by doT on 30/01/2016.
 */
public class HomeAdapter extends BaseAdapter {
    private Context context;
    private List<String> list;

    public HomeAdapter(Context context, List<String> list){
        this.context = context;
        this.list = list;
    }

    @Override
    public int getCount() {
        return list.size();
    }

    @Override
    public String getItem(int position) {
        return list.get(position);
    }

    @Override
    public long getItemId(int position) {
        return position;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        if (convertView == null){
            LayoutInflater layoutInflater = (LayoutInflater) context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
            convertView = layoutInflater.inflate(R.layout.list_item_home, null);
        }

        ((TextView) convertView.findViewById(R.id.title)).setText(getItem(position));

        return convertView;
    }
}
