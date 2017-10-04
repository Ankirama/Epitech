package com.dot.epiandroid.view.service;

import android.app.Notification;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.app.Service;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.graphics.BitmapFactory;
import android.os.Handler;
import android.os.IBinder;
import android.preference.PreferenceManager;
import android.support.annotation.Nullable;
import android.support.v4.app.NotificationCompat;
import android.support.v4.app.TaskStackBuilder;
import android.util.Log;
import android.widget.Toast;

import com.dot.epiandroid.R;
import com.dot.epiandroid.api.ApiService;
import com.dot.epiandroid.api.SessionManager;
import com.dot.epiandroid.api.model.Message;
import com.dot.epiandroid.api.requete.MessageRequete;
import com.dot.epiandroid.view.activity.MainActivity;

import java.util.List;
import java.util.Timer;
import java.util.TimerTask;

/**
 * Created by doT on 20/01/2016.
 */
public class MessageService extends Service {
    private static SharedPreferences pref;
    private static SharedPreferences.Editor editor;
    private static Timer timer = new Timer();
    private Context context;
    @Nullable
    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }

    @Override
    public void onCreate() {
        super.onCreate();
        this.context = this;
        this.pref = this.getSharedPreferences(SessionManager.PREF_NAME, 0);
        this.editor = pref.edit();
        startService();
    }

    private void startService(){
        timer.scheduleAtFixedRate(new CheckMessage(), 0, Integer.valueOf(PreferenceManager.getDefaultSharedPreferences(getApplicationContext()).getString("pref_notification_time_value", "900000")));
    }

    private class CheckMessage extends TimerTask {

        @Override
        public void run() {
            ApiService.getApiService().getMessages(pref.getString(SessionManager.KEY_TOKEN, "")).enqueue(new MessageRequete(MessageService.this));
        }
    }

    public void setNotification(List<Message> list){
        if (this.pref.getString(SessionManager.KEY_LAST_MESSAGE, null) == null ||
                !this.pref.getString(SessionManager.KEY_LAST_MESSAGE, null).equals(list.get(0).Date)){
            NotificationCompat.Builder mBuilder =
                    new NotificationCompat.Builder(this)
                            .setSmallIcon(R.mipmap.ic_launcher)
                            .setContentTitle(list.get(0).Title)
                            .setLargeIcon(BitmapFactory.decodeResource(getResources(), R.mipmap.ic_launcher))
                            .setAutoCancel(true);

            Intent resultIntent = new Intent(this, MainActivity.class)
                    .putExtra("notification", true);

            TaskStackBuilder stackBuilder = TaskStackBuilder.create(this);
            stackBuilder.addParentStack(MainActivity.class);
            stackBuilder.addNextIntent(resultIntent);
            PendingIntent resultPendingIntent =
                    stackBuilder.getPendingIntent(
                            0,
                            PendingIntent.FLAG_UPDATE_CURRENT
                    );

            mBuilder.setContentIntent(resultPendingIntent);
            NotificationManager mNotificationManager =
                    (NotificationManager) getSystemService(Context.NOTIFICATION_SERVICE);
            mNotificationManager.notify(1, mBuilder.build());
            editor.putString(SessionManager.KEY_LAST_MESSAGE, list.get(0).Date);
            editor.commit();
        }
    }
}
