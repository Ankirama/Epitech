package com.hellworldz.sondage209;

import android.support.v7.app.ActionBarActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;


public class MainActivity extends ActionBarActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public boolean tryParseFloat(String value)
    {
        try
        {
            Float.parseFloat(value);
            return true;
        } catch(NumberFormatException nfe)
        {
            return false;
        }
    }

    public String check_args(Float p, Float e, Float s) {
        if (p < e)
            return "Error : population inferior to echantillon !";
        else if (p <= 1 || e <= 1)
            return "Error : population and echantillon must be > 1 !";
        else if (s < 0)
            return "Error : sondage must be > 0 !";
        return null;
    }

    public void hideAll (View view) {
        findViewById(R.id.sondage).setVisibility(view.GONE);
        findViewById(R.id.sondageId).setVisibility(view.GONE);
        findViewById(R.id.population).setVisibility(view.GONE);
        findViewById(R.id.populationId).setVisibility(view.GONE);
        findViewById(R.id.echantillon).setVisibility(view.GONE);
        findViewById(R.id.echantillonId).setVisibility(view.GONE);
        findViewById(R.id.calculButton).setVisibility(view.GONE);
    }

    public float calc_var(float p, float e, float s) {
        float tmp = s / 100.0f;
        float var = tmp * (1f - tmp);
        return (var / e * (p - e) / (p - 1f));
    }

    public void print_result(float p, float e, float s, float variance, float amp_95, float amp_99) {
        String s1 = String.format("\n\n\n\ntaille de la population :\t %.0f\n", p);
        String s2 = String.format("taille de l'echantillon :\t %.0f\n", e);
        String s3 = String.format("resultat du sondage :\t \t %.2f\n", s);
        String s4 = String.format("variance estimee :\t \t %.6f\n", variance);
        String s5 = String.format("intervalle de confiance a 95%% : [%.2f%% ; %.2f%%]\n", s - amp_95, s + amp_95);
        String s6 = String.format("intervalle de confiance a 99%% : [%.2f%% ; %.2f%%]\n", s - amp_99, s + amp_99);
        TextView rT = (TextView) findViewById(R.id.resultText);
        rT.setText(s1 + s2 + s3 + s4 + s5 + s6);
    }

    public void run_calc(float p, float e, float s) {
        float variance = calc_var(p, e, s);
        float amp_95 = (float) (1.96 * Math.sqrt((double)variance) * 100.0);
        float amp_99 = (float) (2.58 * Math.sqrt((double)variance) * 100.0);
        print_result(p, e, s, variance, amp_95, amp_99);
    }

    public void onClick (View view) {
        EditText pT = (EditText) findViewById(R.id.population);
        EditText eT = (EditText) findViewById(R.id.echantillon);
        EditText sT = (EditText) findViewById(R.id.sondage);
        TextView rT = (TextView) findViewById(R.id.resultText);
        String err = null;
        Float p, e, s;
        p = 0f;
        e = 0f;
        s = 0f;

        if (tryParseFloat(pT.getText().toString())) {
            p = Float.parseFloat(pT.getText().toString());
        } else {
            err = "population must be an int";
        }
        if (tryParseFloat(eT.getText().toString())) {
            e = Float.parseFloat(eT.getText().toString());
        } else {
            err = "echantillon must be an int";
        }
        if (tryParseFloat(sT.getText().toString())) {
            s = Float.parseFloat(sT.getText().toString());
        } else {
            err = "sondage must be a float";
        }

        if (err == null)
            err = check_args(p, e, s);

        if (err != null) {
            Toast.makeText(this, err,
                    Toast.LENGTH_LONG).show();
        }
        else {
            hideAll(view);
            run_calc(p, e, s);
        }
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }
}
