package com.dot.epiandroid.presenter.dialog;

import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.text.InputType;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.EditText;

import com.dot.epiandroid.R;
import com.dot.epiandroid.api.ApiService;
import com.dot.epiandroid.api.SessionManager;
import com.dot.epiandroid.api.model.Planning;
import com.dot.epiandroid.api.requete.TokenRequete;

/**
 * Created by doT on 13/01/2016.
 */
public class TokenPresenter extends AlertDialog.Builder {
    private EditText editText;
    private Context context;
    private Planning planning;

    public TokenPresenter(Context context, Planning planning) {
        super(context);
        this.context = context;
        this.planning = planning;
        LayoutInflater inflater = (LayoutInflater) context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
        View view = inflater.inflate(R.layout.dialog_token, null);
        editText = (EditText) view.findViewById(R.id.userInput);
        editText.setInputType(InputType.TYPE_CLASS_NUMBER);
        setView(view);
        this.setPositiveButton(R.string.okButton, this.positiveButton());
        this.setNegativeButton(R.string.cancelButton, this.cancelButton());
    }

    private DialogInterface.OnClickListener positiveButton(){
        return new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
                ApiService.getApiService().validateToken(SessionManager.getInstance().getToken(),
                        planning.ScolarYear, planning.CodeModule, planning.CodeInstance,
                        planning.CodeActi, planning.CodeEvent, editText.getText().toString()).enqueue(new TokenRequete(context));
            }
        };
    }


    private DialogInterface.OnClickListener cancelButton(){
        return new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
                dialog.cancel();
            }
        };
    }
}
