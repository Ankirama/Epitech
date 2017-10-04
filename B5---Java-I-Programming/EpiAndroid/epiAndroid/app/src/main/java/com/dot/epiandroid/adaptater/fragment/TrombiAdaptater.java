package com.dot.epiandroid.adaptater.fragment;

import android.app.Activity;
import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.TextView;

import com.dot.epiandroid.R;
import com.dot.epiandroid.api.model.Trombi;
import com.squareup.picasso.Picasso;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by doT on 11/01/2016.
 */
public class TrombiAdaptater extends BaseAdapter {
    private Activity activity;
    private List<Trombi.UserTrombi> list;
    private List<View> viewList;

    public TrombiAdaptater(Activity activity, List<Trombi.UserTrombi> list){
        this.activity = activity;
        this.list = list;
        this.viewList = new ArrayList<>();
    }

    @Override
    public int getCount() {
        return this.list.size();
    }

    @Override
    public Trombi.UserTrombi getItem(int position) {
        return this.list.get(position);
    }

    @Override
    public long getItemId(int position) {
        return position;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        Trombi.UserTrombi tmp = getItem(position);
        if (convertView == null) {
            LayoutInflater infalInflater = (LayoutInflater) this.activity.getApplicationContext()
                    .getSystemService(Context.LAYOUT_INFLATER_SERVICE);
            convertView = infalInflater.inflate(R.layout.list_item_trombi, null);
        }

        if (tmp != null) {
            Picasso.with(this.activity).load(tmp.Picture).into((ImageView) convertView.findViewById(R.id.image));
            ((TextView) convertView.findViewById(R.id.name)).setText(tmp.Title);
        }
        return convertView;
    }

    public List<Trombi.UserTrombi> getList(){
        return this.list;
    }
}
