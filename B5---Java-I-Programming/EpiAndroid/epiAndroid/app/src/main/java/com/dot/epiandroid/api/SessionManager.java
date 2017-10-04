package com.dot.epiandroid.api;

/**
 * Created by doT on 02/12/2015.
 */
import java.io.IOException;
import java.util.HashMap;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.SharedPreferences.Editor;
import android.util.Log;
import android.widget.Toast;

import com.dot.epiandroid.R;
import com.dot.epiandroid.api.model.Error;
import com.dot.epiandroid.view.activity.Login;
import com.squareup.okhttp.ResponseBody;

import retrofit.GsonConverterFactory;

public class SessionManager {
    SharedPreferences pref;
    Editor editor;
    Context _context;
    int PRIVATE_MODE = 0;
    private static final SessionManager mInstance = new SessionManager();
    public static final String PREF_NAME = "epiandroid";
    private static final String IS_LOGIN = "IsLoggedIn";
    private static final String KEY_LOGIN = "key_login";
    public static final String KEY_TOKEN = "key_token";
    private static final String KEY_PICTURE = "key_picture";
    public static final String KEY_LAST_MESSAGE = "key_last";

    public static synchronized SessionManager getInstance(){
        return mInstance;
    }

    public void initSession(Context context){
        this._context = context;
        pref = _context.getSharedPreferences(PREF_NAME, PRIVATE_MODE);
        editor = pref.edit();
    }

    public void createLoginSession(String login, String token){
        editor.putBoolean(IS_LOGIN, true);
        editor.putString(KEY_LOGIN, login);
        editor.putString(KEY_TOKEN, token);
        editor.commit();
    }

    public boolean checkLogin(){
        if(!this.isLoggedIn()){
            Intent i = new Intent(_context, Login.class);
            i.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
            i.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
            _context.startActivity(i);
        }
        return false;
    }

    public HashMap<String, String> getUserDetails(){
        HashMap<String, String> user = new HashMap<String, String>();
        user.put(KEY_LOGIN, pref.getString(KEY_LOGIN, null));
        user.put(KEY_TOKEN, pref.getString(KEY_TOKEN, null));
        user.put(KEY_PICTURE, pref.getString(KEY_PICTURE, null));
        return user;
    }

    public void logoutUser(){
        editor.clear();
        editor.commit();
        editor.putBoolean(IS_LOGIN, false);
        editor.commit();
        Intent i = new Intent(_context, Login.class);
        i.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
        i.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
        _context.startActivity(i);
    }
    public boolean isLoggedIn(){
        return pref.getBoolean(IS_LOGIN, false);
    }

    public void setProfilPicture(String url) {
        editor.putString(KEY_PICTURE, url);
        editor.commit();
    }

    public String getToken(){ return this.pref.getString(KEY_TOKEN, ""); }

    public String getLogin(){ return this.pref.getString(KEY_LOGIN, "activity_login"); }

    public String getProflPicture(){ return this.pref.getString(KEY_PICTURE, "http://bsi.epitech.eu/wp-content/uploads/2013/05/epi.png"); }

    public void ErrorCall(ResponseBody responseBody){
        try {
            Error error = (Error) GsonConverterFactory.create().fromResponseBody(Error.class, Error.class.getAnnotations()).convert(responseBody);
            Toast.makeText(this._context, error.errorBody.Message, Toast.LENGTH_LONG).show();
            if (error.errorBody.Code == 403) {
                logoutUser();
                Toast.makeText(this._context, R.string.relog, Toast.LENGTH_LONG).show();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void setLastMessage(String lastMessage){
        editor.putString(KEY_LAST_MESSAGE, lastMessage);
        editor.commit();
    }

    public String getLastMessage(){
        return pref.getString(KEY_LAST_MESSAGE, null);
    }
}
