package com.dot.epiandroid.presenter;

import android.app.Activity;
import android.content.Context;
import android.support.design.widget.NavigationView;
import android.text.Html;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;

import com.dot.epiandroid.api.ApiService;
import com.dot.epiandroid.api.SessionManager;
import com.dot.epiandroid.api.model.Message;
import com.dot.epiandroid.api.requete.MessageRequete;
import com.dot.epiandroid.view.activity.MainActivity;

import java.util.ArrayList;
import java.util.List;

import retrofit.Callback;
import retrofit.Response;
import retrofit.Retrofit;

/**
 * Created by doT on 09/01/2016.
 */
public class MessagePresenter {
    private List<Message> list;
    private Menu menu;
    private Activity activity;

    public MessagePresenter(Menu menu, Activity activity){
        this.menu = menu;
        this.activity = activity;
        this.list = new ArrayList<>();
        this.getMessage(false);
    }

    public void addMessage(List<Message> messages){
        int i = 0;
        this.list.addAll(messages);
        for (Message message : messages) {
            this.menu.add(0, i, 0, Html.fromHtml(message.Title).toString());
            i++;
        }
    }

    public void getMessage(boolean isMainActivity){
        ApiService.getApiService().getMessages(SessionManager.getInstance().getToken()).enqueue(new MessageRequete(this, this.menu, isMainActivity));
    }

    public void setNotificationPresenter(Message message){
        NotificationPresenter notificationPresenter = new NotificationPresenter(activity, message);
        notificationPresenter.show();
    }

    public NavigationView.OnNavigationItemSelectedListener showNotification(){
        return new NavigationView.OnNavigationItemSelectedListener() {
            @Override
            public boolean onNavigationItemSelected(MenuItem menuItem) {
                NotificationPresenter notificationPresenter = new NotificationPresenter(activity, list.get(menuItem.getItemId()));
                notificationPresenter.show();
                ((MainActivity) activity).closeSlide(false);
                return false;
            }
        };
    }
}

