package com.dot.epiandroid.api.requete;

import android.content.Context;
import android.widget.ImageView;

import com.dot.epiandroid.api.SessionManager;
import com.dot.epiandroid.api.model.Picture;
import com.squareup.picasso.Picasso;

import retrofit.Callback;
import retrofit.Response;
import retrofit.Retrofit;

/**
 * Created by doT on 13/01/2016.
 */
public class PictureRequete implements Callback<Picture> {
    private Context context;
    private ImageView imageView;

    public PictureRequete(Context context, ImageView imageView){
        this.context = context;
        this.imageView = imageView;
    }

    @Override
    public void onResponse(Response<Picture> response, Retrofit retrofit) {
        if (response.body() != null) {
            Picasso.with(context).load(response.body().Url).into(this.imageView);
        } else
            SessionManager.getInstance().ErrorCall(response.errorBody());
    }

    @Override
    public void onFailure(Throwable t) {

    }
}
