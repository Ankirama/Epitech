package com.dot.epiandroid.view.fragment.profils;

import android.animation.ObjectAnimator;
import android.os.Bundle;
import android.support.design.widget.NavigationView;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.animation.DecelerateInterpolator;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.ProgressBar;
import android.widget.TextView;
import com.dot.epiandroid.R;
import com.dot.epiandroid.api.model.User;
import com.dot.epiandroid.presenter.fragment.profils.ProfilsPresenter;
import com.squareup.picasso.Picasso;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by doT on 02/12/2015.
 */
public class ProfilFragment extends Fragment {
    private NavigationView navigationView = null;
    private User user = null;
    private ProfilsPresenter profilsPresenter;
    private ProgressBar progressSemestre, progressYear, progressGpa;
    private ImageView imageProfil;
    private TextView firstName, lastName, logTime, promo, location, studentYear, schoolYear, semester, gpa, textSemester, textGpa, textYear;
    private List<View> list;

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View rootView = inflater.inflate(R.layout.fragment_profil, container, false);

        this.profilsPresenter = new ProfilsPresenter(this);

        list = new ArrayList<View>();
        list.add(this.imageProfil = (ImageView) rootView.findViewById(R.id.imageProfil));
        list.add(this.firstName = (TextView) rootView.findViewById(R.id.firstName));
        list.add(this.lastName = (TextView) rootView.findViewById(R.id.lastName));
        list.add(this.promo = (TextView) rootView.findViewById(R.id.promo));
        list.add(this.location = (TextView) rootView.findViewById(R.id.location));
        list.add(this.studentYear = (TextView) rootView.findViewById(R.id.studentYear));
        list.add(this.logTime = (TextView) rootView.findViewById(R.id.logTime));
        list.add(this.gpa = (TextView) rootView.findViewById(R.id.gpa));
        list.add(this.semester = (TextView) rootView.findViewById(R.id.semestre));
        list.add(this.schoolYear = (TextView) rootView.findViewById(R.id.schoolYear));
        list.add(this.progressSemestre = (ProgressBar) rootView.findViewById(R.id.progressSemestre));
        list.add(this.progressYear = (ProgressBar) rootView.findViewById(R.id.progressYear));
        list.add(this.progressGpa = (ProgressBar) rootView.findViewById(R.id.progressGpa));
        list.add(this.textGpa = (TextView) rootView.findViewById(R.id.textGpa));
        list.add(this.textSemester = (TextView) rootView.findViewById(R.id.textSemester));
        list.add(this.textYear = (TextView) rootView.findViewById(R.id.textYear));

        ((Button) rootView.findViewById(R.id.modules)).setOnClickListener(this.profilsPresenter.moduleListener());
        ((Button) rootView.findViewById(R.id.marks)).setOnClickListener(this.profilsPresenter.markListener());
        ((Button) rootView.findViewById(R.id.projects)).setOnClickListener(this.profilsPresenter.projectListener());

        return rootView;
    }

    private ObjectAnimator setAnimation(ProgressBar progressBar, int start, int end){
        ObjectAnimator animation = ObjectAnimator.ofInt(progressBar, "progress", start, end);
        animation.setDuration(3000);
        animation.setInterpolator(new DecelerateInterpolator());
        return animation;
    }

    public void setProfil(User informationStart){
        this.user = informationStart;
        this.firstName.setText(informationStart.FirstName.substring(0, 1).toUpperCase() + informationStart.FirstName.substring(1));
        this.lastName.setText(informationStart.LastName.substring(0, 1).toUpperCase() + informationStart.LastName.substring(1));
        this.location.setText(informationStart.Location);
        this.promo.setText(String.valueOf(informationStart.Promo));
        this.studentYear.setText(String.valueOf(informationStart.SchoolYear));
        this.schoolYear.setText(String.valueOf(informationStart.SchoolYear));
        this.gpa.setText(informationStart.Gpa.get(0).Gpa);
        this.semester.setText(String.valueOf(informationStart.Semester));
        this.logTime.setText(((informationStart.NsStat != null) ? String.valueOf(informationStart.NsStat.Active) : "0"));

        this.textGpa.setText(R.string.gpa);
        this.textSemester.setText(R.string.semester);
        this.textYear.setText(R.string.studentYear);

        Picasso.with(getActivity().getApplicationContext()).load(informationStart.Picture).into(this.imageProfil);

        this.setAnimation(progressSemestre, 0, informationStart.Semester * 100).start();
        this.setAnimation(progressYear, 0, informationStart.SchoolYear * 100).start();
        this.setAnimation(progressGpa, 0, (int) Math.round(Double.valueOf(informationStart.Gpa.get(0).Gpa) * 100)).start();
    }

    public void setMainProfil(NavigationView navigationView){
        this.navigationView = navigationView;
    }

    public NavigationView getMainProfil(){
        return this.navigationView;
    }
}
