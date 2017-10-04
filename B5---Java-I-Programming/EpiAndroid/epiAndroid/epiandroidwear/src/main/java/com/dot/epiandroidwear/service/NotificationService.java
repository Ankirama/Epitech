package com.dot.epiandroidwear.service;

import android.app.Notification;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.Intent;
import android.graphics.BitmapFactory;
import android.support.wearable.view.BoxInsetLayout;
import android.util.Log;
import android.widget.TextView;

import com.dot.epiandroidwear.activity.NotificationActivity;
import com.dot.epiandroidwear.R;
import com.google.android.gms.common.ConnectionResult;
import com.google.android.gms.common.api.GoogleApiClient;
import com.google.android.gms.common.data.FreezableUtils;
import com.google.android.gms.wearable.Asset;
import com.google.android.gms.wearable.DataEvent;
import com.google.android.gms.wearable.DataEventBuffer;
import com.google.android.gms.wearable.DataMapItem;
import com.google.android.gms.wearable.Wearable;
import com.google.android.gms.wearable.WearableListenerService;

import java.text.SimpleDateFormat;
import java.util.List;
import java.util.Locale;
import java.util.concurrent.TimeUnit;

public class NotificationService extends WearableListenerService {

    private static final SimpleDateFormat AMBIENT_DATE_FORMAT =
            new SimpleDateFormat("HH:mm", Locale.US);

    private BoxInsetLayout mContainerView;
    private TextView mTextView;
    private TextView mClockView;

    private GoogleApiClient googleApiClient;

    @Override
    public void onCreate() {
        super.onCreate();
        googleApiClient = new GoogleApiClient.Builder(this)
                .addApi(Wearable.API)
                .build();
        googleApiClient.connect();
    }

    @Override
    public void onDataChanged(DataEventBuffer dataEvents) {

        final List<DataEvent> events = FreezableUtils.freezeIterable(dataEvents);
        dataEvents.close();

        if (!googleApiClient.isConnected()){
            ConnectionResult connectionResult = googleApiClient.blockingConnect(30, TimeUnit.SECONDS);
            if (!connectionResult.isSuccess()){
                Log.e("Wearable Service", "Service failed to connect to GoogleApiClient");
                return ;
            }
        }

        for (DataEvent event : events) {
            if (event.getType() == DataEvent.TYPE_CHANGED) {
                String path = event.getDataItem().getUri().getPath();
                //if (PATH.equals(path)) {
                    // Get the data out of the event
                    DataMapItem dataMapItem =
                            DataMapItem.fromDataItem(event.getDataItem());
                    final String title = dataMapItem.getDataMap().getString(NotificationActivity.EXTRA_TITLE);
                    Asset asset = dataMapItem.getDataMap().getAsset(NotificationActivity.EXTRA_IMAGE);

                    Intent notificationIntent =
                            new Intent(this, NotificationActivity.class);
                    notificationIntent.putExtra(
                            NotificationActivity.EXTRA_TITLE, title);
                    //notificationIntent.putExtra(
                            //NotificationActivity.EXTRA_IMAGE, asset);
                    PendingIntent notificationPendingIntent = PendingIntent.getActivity(
                            this,
                            0,
                            notificationIntent,
                            PendingIntent.FLAG_UPDATE_CURRENT);

                    Notification.Builder notificationBuilder =
                            new Notification.Builder(this)
                                    .setSmallIcon(R.mipmap.ic_launcher)
                                    .setLargeIcon(BitmapFactory.decodeResource(
                                            getResources(), R.mipmap.ic_launcher))
                                    .setOngoing(true)
                                    .setContentTitle(title)
                                    .extend(new Notification.WearableExtender()
                                            .setDisplayIntent(notificationPendingIntent));

                    // Build the notification and show it
                    NotificationManager notificationManager =
                            (NotificationManager)getSystemService(NOTIFICATION_SERVICE);
                    notificationManager.notify(
                            1, notificationBuilder.build());
                //} else {
                   // Log.d(TAG, "Unrecognized path: " + path);
                //}
            }
        }
        //super.onDataChanged(dataEvents);
    }
}
