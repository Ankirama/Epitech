package com.dot.epiandroid.presenter;

import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.text.Html;
import android.text.InputType;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;

import com.dot.epiandroid.R;
import com.dot.epiandroid.api.ApiService;
import com.dot.epiandroid.api.SessionManager;
import com.dot.epiandroid.api.model.Message;
import com.dot.epiandroid.api.model.Planning;
import com.dot.epiandroid.api.requete.TokenRequete;
import com.squareup.picasso.Picasso;

/**
 * Created by doT on 25/01/2016.
 */
public class NotificationPresenter extends AlertDialog.Builder {
    private EditText editText;
    private Context context;
    private Message message;

    public NotificationPresenter(Context context, Message message) {
        super(context);
        this.context = context;
        this.message = message;
        LayoutInflater inflater = (LayoutInflater) context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
        View view = inflater.inflate(R.layout.dialog_notification, null);
        ((TextView) view.findViewById(R.id.title)).setText(Html.fromHtml(message.Title).toString());
        ((TextView) view.findViewById(R.id.content)).setText(Html.fromHtml(message.Content).toString());
        ((TextView) view.findViewById(R.id.date)).setText(message.Date);
        if (message.User != null) {
            ((TextView) view.findViewById(R.id.teacher_name)).setText(message.User.Title);
            Picasso.with(context).load(message.User.Picture).into((ImageView) view.findViewById(R.id.picture_teacher));
            ((LinearLayout) view.findViewById(R.id.teacher)).setVisibility(View.VISIBLE);
        }
        setView(view);
        this.setPositiveButton(R.string.okButton, this.positiveButton());
    }

    private DialogInterface.OnClickListener positiveButton(){
        return new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
                dialog.cancel();
            }
        };
    }
}
