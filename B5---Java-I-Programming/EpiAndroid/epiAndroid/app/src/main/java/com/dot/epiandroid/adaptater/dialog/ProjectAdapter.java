package com.dot.epiandroid.adaptater.dialog;

import android.content.Context;
import android.text.Layout;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.TextView;

import com.dot.epiandroid.R;
import com.dot.epiandroid.api.model.ProjectFile;

import org.w3c.dom.Text;

import java.util.List;

/**
 * Created by doT on 30/01/2016.
 */
public class ProjectAdapter extends BaseAdapter {
    private Context context;
    private List<ProjectFile> list;

    public ProjectAdapter(Context context, List<ProjectFile> list){
        this.context = context;
        this.list = list;
    }

    @Override
    public int getCount() {
        return list.size();
    }

    @Override
    public ProjectFile getItem(int position) {
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
            convertView = (View) layoutInflater.inflate(R.layout.list_item_project, null);
        }

        ((TextView) convertView.findViewById(R.id.title)).setText(getItem(position).Title);

        return convertView;
    }
}
