package com.dot.epiandroid.api.requete;

import android.content.Context;
import android.util.Log;
import android.widget.Toast;

import com.dot.epiandroid.R;
import com.dot.epiandroid.api.SessionManager;

import retrofit.Callback;
import retrofit.Response;
import retrofit.Retrofit;

/**
 * Created by doT on 11/01/2016.
 */
public class TokenRequete implements Callback<String> {
    private Context context;

    public TokenRequete(Context context){
        this.context = context;
    }

    @Override
    public void onResponse(Response<String> response, Retrofit retrofit) {
        if (response.code() == 200){
            Toast.makeText(this.context, this.context.getString(R.string.token_validate), Toast.LENGTH_LONG).show();
        } else
            SessionManager.getInstance().ErrorCall(response.errorBody());
    }

    @Override
    public void onFailure(Throwable t) {
    }
}
