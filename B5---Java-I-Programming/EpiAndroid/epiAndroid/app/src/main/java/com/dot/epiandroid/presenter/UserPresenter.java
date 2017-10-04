package com.dot.epiandroid.presenter;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.text.Html;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.ProgressBar;
import android.widget.SearchView;
import android.widget.TextView;

import com.dot.epiandroid.R;
import com.dot.epiandroid.api.SessionManager;
import com.dot.epiandroid.api.model.Message;
import com.dot.epiandroid.api.model.User;
import com.squareup.picasso.Picasso;

import java.util.concurrent.Callable;

import retrofit.Callback;
import retrofit.Response;
import retrofit.Retrofit;

/**
 * Created by doT on 25/01/2016.
 */
public class UserPresenter extends AlertDialog.Builder implements Callback<User> {
    private Activity activity;
    private User user;
    private View view;

    public UserPresenter(Activity activity) {
        super(activity);
        this.activity = activity;
        LayoutInflater inflater = (LayoutInflater) activity.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
        view = inflater.inflate(R.layout.dialog_user, null);
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

    @Override
    public void onResponse(Response<User> response, Retrofit retrofit) {
        if (response.code() == 200) {
            this.setProfil(response.body());
            this.show();
        } else
            SessionManager.getInstance().ErrorCall(response.errorBody());
    }

    @Override
    public void onFailure(Throwable t) {
    }

    public void setProfil(User user){
        if (user != null && user.FirstName != null) {
            ((TextView) view.findViewById(R.id.firstName)).setText(user.FirstName.substring(0, 1).toUpperCase() + user.FirstName.substring(1));
            ((TextView) view.findViewById(R.id.lastName)).setText(user.LastName.substring(0, 1).toUpperCase() + user.LastName.substring(1));
            ((TextView) view.findViewById(R.id.location)).setText(user.Location);
            ((TextView) view.findViewById(R.id.promo)).setText(String.valueOf(user.Promo));
            ((TextView) view.findViewById(R.id.schoolYear)).setText(String.valueOf(user.SchoolYear));
            ((TextView) view.findViewById(R.id.studentYear)).setText(String.valueOf(user.SchoolYear));
            ((TextView) view.findViewById(R.id.gpa)).setText(user.Gpa.get(0).Gpa);
            ((TextView) view.findViewById(R.id.semestre)).setText(String.valueOf(user.Semester));
            ((TextView) view.findViewById(R.id.logTime)).setText(((user.NsStat != null) ? String.valueOf(user.NsStat.Active) : "0"));

            ((TextView) view.findViewById(R.id.textGpa)).setText(R.string.gpa);
            ((TextView) view.findViewById(R.id.textSemester)).setText(R.string.semester);
            ((TextView) view.findViewById(R.id.textYear)).setText(R.string.studentYear);

            Picasso.with(activity).load(user.Picture).into(((ImageView) view.findViewById(R.id.imageProfil)));

            ((ProgressBar) view.findViewById(R.id.progressSemestre)).setProgress(user.Semester * 100);
            ((ProgressBar) view.findViewById(R.id.progressYear)).setProgress(user.SchoolYear * 100);
            ((ProgressBar) view.findViewById(R.id.progressGpa)).setProgress((int) Math.round(Double.valueOf(user.Gpa.get(0).Gpa) * 100));
        }
    }
}
