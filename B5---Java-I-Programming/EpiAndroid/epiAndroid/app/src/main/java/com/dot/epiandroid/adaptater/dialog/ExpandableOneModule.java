package com.dot.epiandroid.adaptater.dialog;

import android.animation.ObjectAnimator;
import android.content.Context;
import android.graphics.Typeface;
import android.support.v4.app.INotificationSideChannel;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseExpandableListAdapter;
import android.widget.ExpandableListAdapter;
import android.widget.TextView;

import com.dot.epiandroid.R;

import java.util.HashMap;
import java.util.List;

/**
 * Created by doT on 30/01/2016.
 */
public class ExpandableOneModule extends BaseExpandableListAdapter{
    private Context context;
    private List<String> listHeader;
    private HashMap<String, List<HashMap<String, String>>> listChild;

    public ExpandableOneModule(Context context, List<String> header, HashMap<String, List<HashMap<String, String>>> child){
        this.context = context;
        this.listHeader = header;
        this.listChild = child;
    }

    @Override
    public int getGroupCount() {
        return listHeader.size();
    }

    @Override
    public int getChildrenCount(int groupPosition) {
        return listChild.get(listHeader.get(groupPosition)).size();
    }

    @Override
    public String getGroup(int groupPosition) {
        return listHeader.get(groupPosition);
    }

    @Override
    public HashMap<String, String> getChild(int groupPosition, int childPosition) {
        return this.listChild.get(getGroup(groupPosition)).get(childPosition);
    }

    @Override
    public long getGroupId(int groupPosition) {
        return groupPosition;
    }

    @Override
    public long getChildId(int groupPosition, int childPosition) {
        return childPosition;
    }

    @Override
    public boolean hasStableIds() {
        return false;
    }

    @Override
    public View getGroupView(int groupPosition, boolean isExpanded, View convertView, ViewGroup parent) {
        String headerTitle = getGroup(groupPosition);
        if (convertView == null) {
            LayoutInflater infalInflater = (LayoutInflater) this.context
                    .getSystemService(Context.LAYOUT_INFLATER_SERVICE);
            convertView = infalInflater.inflate(R.layout.list_group, null);
        }

        TextView lblListHeader = (TextView) convertView
                .findViewById(R.id.lblListHeader);
        lblListHeader.setTypeface(null, Typeface.BOLD);
        lblListHeader.setText(headerTitle);

        return convertView;
    }

    @Override
    public View getChildView(int groupPosition, int childPosition, boolean isLastChild, View convertView, ViewGroup parent) {
        final HashMap<String, String> childText = getChild(groupPosition, childPosition);

        LayoutInflater infalInflater = (LayoutInflater) this.context
                .getSystemService(Context.LAYOUT_INFLATER_SERVICE);
        if (getGroup(groupPosition).equals("Activity"))
            convertView = infalInflater.inflate(R.layout.list_expandable_activity, null);
        else
            convertView = infalInflater.inflate(R.layout.list_expandable_item, null);

        if (getGroup(groupPosition).equals("Activity")) {
            ((TextView) convertView.findViewById(R.id.title)).setText(childText.get("title"));
            ((TextView) convertView.findViewById(R.id.description)).setText(childText.get("desc"));
        } else {
            ((TextView) convertView.findViewById(R.id.title)).setText(childText.get("title"));
            ((TextView) convertView.findViewById(R.id.login)).setText(childText.get("login"));
        }

        return convertView;
    }

    @Override
    public boolean isChildSelectable(int groupPosition, int childPosition) {
        return true;
    }
}
