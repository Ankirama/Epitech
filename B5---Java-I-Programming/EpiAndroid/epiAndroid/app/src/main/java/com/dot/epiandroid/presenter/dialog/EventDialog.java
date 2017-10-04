package com.dot.epiandroid.presenter.dialog;

import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.text.InputType;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

import com.dot.epiandroid.R;
import com.dot.epiandroid.api.ApiService;
import com.dot.epiandroid.api.SessionManager;
import com.dot.epiandroid.api.model.Planning;
import com.dot.epiandroid.api.requete.TokenRequete;

/**
 * Created by doT on 30/01/2016.
 */
public class EventDialog extends AlertDialog.Builder {
    private EditText editText;
    private Context context;
    private Planning planning;

    public EventDialog(Context context, Planning planning) {
        super(context);
        this.context = context;
        this.planning = planning;
        LayoutInflater inflater = (LayoutInflater) context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
        View view = inflater.inflate(R.layout.dialog_event, null);

        ((TextView) view.findViewById(R.id.title)).setText(planning.Title);
        ((TextView) view.findViewById(R.id.type_title)).setText(planning.TypeTitle);
        ((TextView) view.findViewById(R.id.description)).setText(planning.Description);
        if (planning.Room != null) {
            ((TextView) view.findViewById(R.id.seats)).setText(planning.Room.Seats);
            ((TextView) view.findViewById(R.id.room)).setText(planning.Room.Type);
        }

        setView(view);
        this.setPositiveButton(R.string.okButton, this.positiveButton());
    }

    private DialogInterface.OnClickListener positiveButton(){
        return new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
                dialog.dismiss();
            }
        };
    }
}
