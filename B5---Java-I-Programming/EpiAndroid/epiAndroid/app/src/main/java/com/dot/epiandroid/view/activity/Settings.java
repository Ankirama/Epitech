package com.dot.epiandroid.view.activity;

import android.content.Intent;
import android.os.Bundle;
import android.os.PersistableBundle;
import android.preference.CheckBoxPreference;
import android.preference.Preference;
import android.preference.PreferenceActivity;
import android.preference.PreferenceFragment;

import com.dot.epiandroid.R;
import com.dot.epiandroid.api.model.Message;
import com.dot.epiandroid.view.service.MessageService;

/**
 * Created by doT on 25/01/2016.
 */
public class Settings extends PreferenceActivity {
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        addPreferencesFromResource(R.xml.preference_settings);

        ((CheckBoxPreference) getPreferenceManager().findPreference("pref_notif_activated")).setOnPreferenceChangeListener(new Preference.OnPreferenceChangeListener() {
            @Override
            public boolean onPreferenceChange(Preference preference, Object newValue) {
                if (newValue != null)
                    if (newValue.toString().equals("false")){
                        stopService(new Intent(Settings.this, MessageService.class));
                    } else {
                        startService(new Intent(Settings.this, MessageService.class));
                    }
                return true;
            }
        });
    }
}
