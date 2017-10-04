package com.dot.epiandroid.presenter.dialog;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.net.Uri;
import android.os.Environment;
import android.text.InputType;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.AdapterView;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import com.dot.epiandroid.R;
import com.dot.epiandroid.adaptater.dialog.ProjectAdapter;
import com.dot.epiandroid.api.ApiService;
import com.dot.epiandroid.api.SessionManager;
import com.dot.epiandroid.api.model.Planning;
import com.dot.epiandroid.api.model.ProjectFile;
import com.dot.epiandroid.api.model.UserProject;
import com.dot.epiandroid.api.requete.ProjectFileRequete;
import com.dot.epiandroid.api.requete.TokenRequete;
import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.squareup.okhttp.ResponseBody;

import org.w3c.dom.Text;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import retrofit.Call;
import retrofit.Callback;
import retrofit.GsonConverterFactory;
import retrofit.Response;
import retrofit.Retrofit;
import retrofit.http.POST;
import retrofit.http.Url;

/**
 * Created by doT on 30/01/2016.
 */
public class ProjectPresenter extends AlertDialog.Builder implements AdapterView.OnItemClickListener {
    private String tmp;
    private EditText editText;
    private Activity activity;
    private ProjectAdapter projectAdapter;
    private List<ProjectFile> list;
    private UserProject userProject;

    public ProjectPresenter(Activity activity, UserProject userProject) {
        super(activity);
        this.activity = activity;
        this.userProject = userProject;
        LayoutInflater inflater = (LayoutInflater) activity.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
        View view = inflater.inflate(R.layout.dialog_project, null);

        ((TextView) view.findViewById(R.id.title)).setText(userProject.Project);
        ListView listView = (ListView) view.findViewById(R.id.file);
        list = new ArrayList<>();
        projectAdapter = new ProjectAdapter(activity, list);
        listView.setAdapter(projectAdapter);
        listView.setOnItemClickListener(this);
        setView(view);
        this.setPositiveButton(R.string.okButton, this.positiveButton());

        ApiService.getApiService().getFileProject(SessionManager.getInstance().getToken(),
                userProject.ScolarYear,
                userProject.CodeModule,
                userProject.CodeInstance,
                userProject.CodeActi).enqueue(new ProjectFileRequete(activity, this));
    }

    private DialogInterface.OnClickListener positiveButton(){
        return new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
                dialog.dismiss();
            }
        };
    }

    @Override
    public void onItemClick(AdapterView<?> parent, View view, final int position, long id) {
        Gson gson = new GsonBuilder()
                .setDateFormat("yyyy-MM-dd'T'HH:mm:ssZ")
                .create();

        Retrofit retrofit = new Retrofit.Builder()
                .baseUrl("https://intra.epitech.eu")
                .addConverterFactory(GsonConverterFactory.create(gson))
                .build();

        retrofit.create(FileDownload.class).downloadFile(list.get(position).Url).enqueue(new Callback<ResponseBody>() {
            @Override
            public void onResponse(Response<ResponseBody> response, Retrofit retrofit) {
                Toast.makeText(activity, list.get(position).Title + R.string.downloaded, Toast.LENGTH_LONG).show();
                if (list.get(position).Title.contains(".pdf")) {
                    Intent intent = new Intent(Intent.ACTION_VIEW);
                    intent.setDataAndType(Uri.fromFile(new File(Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_DOWNLOADS).getPath() + "/" + list.get(position).Title)), "application/pdf");
                    intent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
                    activity.startActivity(intent);
                }
            }

            @Override
            public void onFailure(Throwable t) {

            }
        });
    }

    public void setList(List<ProjectFile> list){
        this.list.addAll(list);
        this.projectAdapter.notifyDataSetChanged();
    }

    public interface FileDownload {
        @POST
        Call<ResponseBody> downloadFile(@Url String url);
    }
}
