package com.dot.epiandroid.adaptater.fragment;

import android.content.Context;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.TextView;

import com.dot.epiandroid.R;
import com.dot.epiandroid.api.model.UserMark;
import com.dot.epiandroid.api.model.UserProject;

import java.util.List;

/**
 * Created by doT on 10/01/2016.
 */
public class UserMarkAdaptater extends BaseAdapter {
    private Context context;
    private List<UserMark.Mark> list;

    public UserMarkAdaptater(Context context, List<UserMark.Mark> list){
        this.context = context;
        this.list = list;
    }

    @Override
    public int getCount() {
        return this.list.size();
    }

    @Override
    public UserMark.Mark getItem(int position) {
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
            convertView = infalInflater.inflate(R.layout.list_item_user_mark, null);
        }

        UserMark.Mark mark = getItem(position);
        if (mark != null) {
            ((TextView) convertView.findViewById(R.id.title)).setText(mark.Title);
            ((TextView) convertView.findViewById(R.id.mark)).setText(mark.Mark);
        }
        return convertView;
    }
}
