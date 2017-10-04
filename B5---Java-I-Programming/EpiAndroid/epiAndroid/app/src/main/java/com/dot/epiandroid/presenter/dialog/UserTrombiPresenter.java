package com.dot.epiandroid.presenter.dialog;

import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.net.Uri;
import android.provider.ContactsContract;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

import com.dot.epiandroid.R;
import com.dot.epiandroid.api.model.User;

/**
 * Created by doT on 13/01/2016.
 */
public class UserTrombiPresenter extends AlertDialog.Builder {
    private Context context;
    private User user;

    public UserTrombiPresenter(Context context, User user) {
        super(context);
        this.user = user;
        this.context = context;

        LayoutInflater inflater = (LayoutInflater) context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
        View view = inflater.inflate(R.layout.user_trombi, null);
        setView(view);
        if (user.UserInfo.Telephone != null) {
            ((TextView) view.findViewById(R.id.phoneNumber)).setText(user.UserInfo.Telephone.Value);
            ((TextView) view.findViewById(R.id.phoneNumber)).setOnClickListener(callButton());
            ((TextView) view.findViewById(R.id.addContact)).setOnClickListener(addButton());
            ((TextView) view.findViewById(R.id.sendEmail)).setOnClickListener(sendEmail());
        } else
            ((TextView) view.findViewById(R.id.phoneNumber)).setVisibility(View.INVISIBLE);
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


    private DialogInterface.OnClickListener cancelButton(){
        return new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {

            }
        };
    }

    private View.OnClickListener callButton(){
        return new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(Intent.ACTION_CALL, Uri.parse("tel:" + user.UserInfo.Telephone.Value.replace(" ", "")));
                context.startActivity(intent);
            }
        };
    }

    private View.OnClickListener addButton(){
        return new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent contactIntent = new Intent(ContactsContract.Intents.SHOW_OR_CREATE_CONTACT,ContactsContract.Contacts.CONTENT_URI);
                contactIntent.setData(Uri.parse("tel:" + user.UserInfo.Telephone.Value.replace(" ", "")));
                contactIntent.putExtra(ContactsContract.Intents.Insert.PHONE, user.Title);
                context.startActivity(contactIntent);
            }
        };
    }

    private View.OnClickListener sendEmail(){
        return new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent i = new Intent(Intent.ACTION_SEND);
                i.setType("message/rfc822");
                i.putExtra(Intent.EXTRA_EMAIL  , new String[]{user.EmailIntern});
                i.putExtra(Intent.EXTRA_SUBJECT, R.string.objectEmail);
                i.putExtra(Intent.EXTRA_TEXT   , R.string.subjectEmail);
                try {
                    context.startActivity(Intent.createChooser(i, getContext().getResources().getString(R.string.sendEmailText)));
                } catch (android.content.ActivityNotFoundException ex) {
                }

            }
        };
    }
}
