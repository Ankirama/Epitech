package com.dot.epiandroid.presenter.fragment;

import android.util.Log;
import android.view.View;
import android.widget.AbsListView;
import android.widget.AdapterView;
import android.widget.EditText;

import com.dot.epiandroid.api.ApiService;
import com.dot.epiandroid.api.SessionManager;
import com.dot.epiandroid.api.model.Trombi;
import com.dot.epiandroid.api.requete.TrombiRequete;
import com.dot.epiandroid.api.requete.UserTrombiRequete;
import com.dot.epiandroid.presenter.dialog.UserTrombiPresenter;
import com.dot.epiandroid.view.fragment.TrombiFragment;

import java.util.List;

/**
 * Created by doT on 18/01/2016.
 */
public class TrombiPresenter implements AdapterView.OnItemClickListener {
    private TrombiFragment trombiFragment;

    public TrombiPresenter(TrombiFragment trombiFragment){
        this.trombiFragment = trombiFragment;
    }

    @Override
    public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
        ApiService.getApiService().getUser(SessionManager.getInstance().getToken(), this.trombiFragment.getAdapter().getItem(position).Login)
                .enqueue(new UserTrombiRequete(this.trombiFragment.getActivity()));
    }

    public void setTrombi(List<Trombi.UserTrombi> list){
        if (list != null) {
            this.trombiFragment.setTrombi(list);
        }
    }

    public View.OnClickListener searchListener(){
        return new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (v != null) {
                    trombiFragment.getAdapter().getList().clear();
                    trombiFragment.getAdapter().notifyDataSetChanged();
                }
                ApiService.getApiService().getTrombi(SessionManager.getInstance().getToken(),
                        (trombiFragment.getSchoolyear().getText() == null) ? "2015" : trombiFragment.getSchoolyear().getText().toString(),
                        (trombiFragment.getLocation().getText() == null) ? "FR/PAR" : trombiFragment.getLocation().getText().toString(),
                        trombiFragment.getCourse(),
                        (trombiFragment.getPromo().getText() == null) ? "tek3" : trombiFragment.getPromo().getText().toString(),
                        String.valueOf(trombiFragment.getAdapter().getList().size()))
                        .enqueue(new TrombiRequete(TrombiPresenter.this));
            }
        };
    }

    public AbsListView.OnScrollListener listBottom(){
        return new AbsListView.OnScrollListener() {
            @Override
            public void onScrollStateChanged(AbsListView view, int scrollState) {

            }

            @Override
            public void onScroll(AbsListView view, int firstVisibleItem, int visibleItemCount, int totalItemCount) {
                if(trombiFragment.getAdapter().getList().size() != 0 && (firstVisibleItem + visibleItemCount) == totalItemCount) {
                    searchListener().onClick(null);
                }
            }
        };
    }
}
