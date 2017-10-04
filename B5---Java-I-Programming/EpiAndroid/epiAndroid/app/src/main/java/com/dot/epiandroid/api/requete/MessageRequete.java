package com.dot.epiandroid.api.requete;

import android.text.Html;
import android.view.Menu;

import com.dot.epiandroid.api.model.Message;
import com.dot.epiandroid.presenter.MessagePresenter;
import com.dot.epiandroid.view.activity.MainActivity;
import com.dot.epiandroid.view.service.MessageService;

import java.util.List;

import retrofit.Callback;
import retrofit.Response;
import retrofit.Retrofit;

/**
 * Created by doT on 20/01/2016.
 */
public class MessageRequete implements Callback<List<Message>> {
    private Menu menu;
    private boolean isDo = false;
    private MessagePresenter messagePresenter = null;
    private MessageService messageService = null;

    public MessageRequete(MessagePresenter messagePresenter, Menu menu, boolean isDo) {
        this.menu = menu;
        this.isDo = isDo;
        this.messagePresenter = messagePresenter;
    }

    public MessageRequete(MessageService messageService){
        this.isDo = false;
        this.messageService = messageService;
    }

    @Override
    public void onResponse(Response<List<Message>> response, Retrofit retrofit) {
        if (response.body() != null) {
            if (messagePresenter != null) {
                this.messagePresenter.addMessage(response.body());
                if (this.isDo)
                    this.messagePresenter.setNotificationPresenter(response.body().get(0));
            } else
                this.messageService.setNotification(response.body());
        }
    }

    @Override
    public void onFailure(Throwable t) {
    }
}