package com.dot.epiandroid.adaptater.fragment;

import android.app.Activity;
import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.Button;
import android.widget.TextView;

import com.dot.epiandroid.R;
import com.dot.epiandroid.adaptater.listener.UserProjectButton;
import com.dot.epiandroid.api.model.UserModule;
import com.dot.epiandroid.api.model.UserProject;
import com.dot.epiandroid.presenter.dialog.ProjectPresenter;

import java.util.List;

/**
 * Created by doT on 10/01/2016.
 */
public class UserProjectAdaptater extends BaseAdapter {
    private Activity activity;
    private List<UserProject> list;

    public UserProjectAdaptater(Activity activity, List<UserProject> list){
        this.activity = activity;
        this.list = list;
    }

    @Override
    public int getCount() {
        return this.list.size();
    }

    @Override
    public UserProject getItem(int position) {
        return this.list.get(position);
    }

    @Override
    public long getItemId(int position) {
        return position;
    }

    @Override
    public View getView(final int position, View convertView, ViewGroup parent) {
        if (convertView == null) {
            LayoutInflater infalInflater = (LayoutInflater) this.activity
                    .getSystemService(Context.LAYOUT_INFLATER_SERVICE);
            convertView = infalInflater.inflate(R.layout.list_item_user_project, null);
        }

        UserProject project = getItem(position);
        if (project != null && project.Project != null && !project.Project.equals("null")) {
            ((TextView) convertView.findViewById(R.id.title)).setText(project.Project);
            ((TextView) convertView.findViewById(R.id.start)).setText(project.BeginActi.split(" ")[0]);
            ((TextView) convertView.findViewById(R.id.end)).setText(project.EndActi.split(" ")[0]);
        }

        convertView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                ProjectPresenter projectPresenter = new ProjectPresenter(activity, list.get(position));
                projectPresenter.show();
            }
        });

        Button multpeButton = (Button) convertView.findViewById(R.id.subscribe);
        multpeButton.setOnClickListener(new UserProjectButton(activity, project, multpeButton));
        if (project != null) {
            multpeButton.setVisibility(View.VISIBLE);
            multpeButton.setText((project.Registered.equals("1") ?  activity.getResources().getString(R.string.unsubscribe) :
                    activity.getResources().getString(R.string.subscribe)));
        } else
            multpeButton.setVisibility(View.INVISIBLE);

        return convertView;
    }
}
