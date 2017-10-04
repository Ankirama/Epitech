package com.dot.epiandroidwear.activity;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.widget.TextView;

import com.dot.epiandroidwear.R;
import com.dot.epiandroidwear.service.NotificationService;

/**
 * Created by doT on 27/01/2016.
 */
public class NotificationActivity extends Activity {
    public static final String EXTRA_TITLE = "title";
    public static final String EXTRA_IMAGE = "image";

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        ((TextView) findViewById(R.id.title)).setText("Html.fromHtml(message.Title).toString())");
        ((TextView) findViewById(R.id.content)).setText("Html.fromHtml(message.Content).toString())");
        ((TextView) findViewById(R.id.date)).setText("message.Date");
        //if (message.User != null) {
        //((TextView) view.findViewById(R.id.teacher_name)).setText(message.User.Title);
        //Picasso.with(this.getApplicationContext()).load(message.User.Picture).into((ImageView) view.findViewById(R.id.picture_teacher));
        //((LinearLayout) view.findViewById(R.id.teacher)).setVisibility(View.VISIBLE);
        //}
        startService(new Intent(this, NotificationService.class));
    }
}
