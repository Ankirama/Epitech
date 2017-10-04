package com.dot.epiandroid.presenter.fragment.profils;

import android.util.Log;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;

import com.dot.epiandroid.R;
import com.dot.epiandroid.api.ApiService;
import com.dot.epiandroid.api.SessionManager;
import com.dot.epiandroid.api.model.*;
import com.dot.epiandroid.api.requete.PictureRequete;
import com.dot.epiandroid.api.requete.ProfilsRequete;
import com.dot.epiandroid.view.fragment.profils.ProfilFragment;
import com.dot.epiandroid.view.fragment.profils.UserMarkFragment;
import com.dot.epiandroid.view.fragment.profils.UserModuleFragment;
import com.dot.epiandroid.view.fragment.profils.UserProjectFragment;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

/**
 * Created by doT on 10/01/2016.
 */
public class ProfilsPresenter {
    private User user;
    private ProfilFragment profilFragment;

    public ProfilsPresenter(ProfilFragment profilFragment){
        this.profilFragment = profilFragment;

        if (SessionManager.getInstance().isLoggedIn())
            ApiService.getApiService().getUser(SessionManager.getInstance().getToken(), SessionManager.getInstance().getLogin()).enqueue(new ProfilsRequete(this));
    }

    public void setProfil(User user){
        this.user = user;
        this.profilFragment.setProfil(user);
        if (this.profilFragment.getMainProfil() != null)
            this.setHeaderMenu();
    }

    public void setHeaderMenu(){
        ImageView imageView = (ImageView) this.profilFragment.getMainProfil().findViewById(R.id.imageView);
        TextView name = (TextView) this.profilFragment.getMainProfil().findViewById(R.id.name);
        TextView promo = (TextView) this.profilFragment.getMainProfil().findViewById(R.id.promo);

        ApiService.getApiService().getPicture(SessionManager.getInstance().getToken(), SessionManager.getInstance().getLogin())
                .enqueue(new PictureRequete(this.profilFragment.getActivity().getApplicationContext(), imageView));
        if (user != null) {
            name.setText(user.FirstName.substring(0, 1).toUpperCase() + user.FirstName.substring(1) + " " +
                    user.LastName.substring(0, 1).toUpperCase() + user.LastName.substring(1));
            promo.setText(profilFragment.getActivity().getResources().getString(R.string.promo) + " " + String.valueOf(user.Promo));
        }
    }

    public View.OnClickListener moduleListener(){
        return new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                profilFragment.getActivity().getSupportFragmentManager()
                        .beginTransaction()
                        .setCustomAnimations(R.anim.slide_in, R.anim.slide_out)
                        .replace(R.id.frame_container, new UserModuleFragment())
                        .addToBackStack("fragment_module").commit();
            }
        };
    }

    public View.OnClickListener projectListener(){
        return new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                profilFragment.getActivity().getSupportFragmentManager()
                        .beginTransaction()
                        .setCustomAnimations(R.anim.slide_in, R.anim.slide_out)
                        .replace(R.id.frame_container, new UserProjectFragment())
                        .addToBackStack("project").commit();
            }
        };
    }

    public View.OnClickListener markListener(){
        return new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                profilFragment.getActivity().getSupportFragmentManager()
                        .beginTransaction()
                        .setCustomAnimations(R.anim.slide_in, R.anim.slide_out)
                        .replace(R.id.frame_container, new UserMarkFragment())
                        .addToBackStack("mark").commit();
            }
        };
    }
}
