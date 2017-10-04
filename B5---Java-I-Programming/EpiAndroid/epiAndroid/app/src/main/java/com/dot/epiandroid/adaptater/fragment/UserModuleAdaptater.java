package com.dot.epiandroid.adaptater.fragment;

import android.content.Context;
import android.content.Intent;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.TextView;

import com.dot.epiandroid.R;
import com.dot.epiandroid.api.model.UserModule;

import java.util.List;

/**
 * Created by doT on 10/01/2016.
 */
public class UserModuleAdaptater extends BaseAdapter {
    private Context context;
    private List<UserModule.UserModules> list;

    public UserModuleAdaptater(Context context, List<UserModule.UserModules> list){
        this.context = context;
        this.list = list;
    }

    @Override
    public int getCount() {
        return this.list.size();
    }

    @Override
    public UserModule.UserModules getItem(int position) {
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
            convertView = infalInflater.inflate(R.layout.list_item_user_module, null);
        }

        UserModule.UserModules modules = getItem(position);
        if (modules != null) {
            ((TextView) convertView.findViewById(R.id.title)).setText(modules.Title);
            ((TextView) convertView.findViewById(R.id.grade)).setText(modules.Grade);
            ((TextView) convertView.findViewById(R.id.start)).setText(modules.DateIns.split(" ")[0]);
            ((TextView) convertView.findViewById(R.id.separateur)).setVisibility(View.INVISIBLE);
        }

        convertView.setOnClickListener(shareGrade(modules));

        return convertView;
    }

    public View.OnClickListener shareGrade(final UserModule.UserModules grade){
        return new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent shareIntent = new Intent(Intent.ACTION_SEND);
                shareIntent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
                shareIntent.setType("text/plain");
                shareIntent.putExtra(Intent.EXTRA_TEXT,  context.getResources().getString(R.string.gotA) +
                        grade.Grade +
                        context.getResources().getString(R.string.at) +
                        grade.Title);
                Intent new_intent = Intent.createChooser(shareIntent,  context.getResources().getString(R.string.shareTo));
                new_intent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
                context.startActivity(new_intent);
            }
        };
    }
}
