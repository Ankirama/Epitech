package com.dot.epiandroid.presenter.dialog;

import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ExpandableListView;
import android.widget.TextView;

import com.dot.epiandroid.R;
import com.dot.epiandroid.adaptater.dialog.ExpandableOneModule;
import com.dot.epiandroid.api.ApiService;
import com.dot.epiandroid.api.SessionManager;
import com.dot.epiandroid.api.model.Module;
import com.dot.epiandroid.api.requete.SubRequete;
import com.dot.epiandroid.api.requete.UnsubRequete;
import com.dot.epiandroid.presenter.fragment.ModulesPresenter;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

/**
 * Created by doT on 13/01/2016.
 */
public class OneModulePresenter extends AlertDialog.Builder {
    private EditText editText;
    private Context context;
    private Module module;
    private boolean subscribe = false;
    private Button button;
    private ModulesPresenter modulesPresenter;
    private List<String> header;
    private HashMap<String, List<HashMap<String, String>>> child;

    public OneModulePresenter(Context context, Module module, ModulesPresenter modulesPresenter) {
        super(context);
        this.context = context;
        this.module = module;
        this.modulesPresenter = modulesPresenter;

        LayoutInflater inflater = (LayoutInflater) context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
        View view = inflater.inflate(R.layout.dialog_one_module, null);
        setView(view);

        ((TextView) view.findViewById(R.id.title)).setText(this.module.Title);
        ((TextView) view.findViewById(R.id.description)).setText(this.module.Description);

        header = new ArrayList<>();
        child = new HashMap<>();
        this.setPositiveButton(R.string.okButton, this.positiveButton());

        setProfessorAssitant(context.getResources().getString(R.string.professor), module.Responsable);
        setProfessorAssitant(context.getResources().getString(R.string.assistant), module.Assistant);
        setActivity();

        ExpandableOneModule expandable = new ExpandableOneModule(this.context, header, child);
        ((ExpandableListView) view.findViewById(R.id.expandableListView2)).setAdapter(expandable);

        if (module.AllowRegister != null && module.AllowRegister.equals("1") && module.StudentRegistered.equals("0")) {
            this.subscribe = true;
            this.setNegativeButton(R.string.subscribe, this.cancelButton());
        } else if (module.AllowRegister != null && module.AllowRegister.equals("1")) {
            this.subscribe = false;
            this.setNegativeButton(R.string.unsubscribe, this.cancelButton());
        }
    }

    private DialogInterface.OnClickListener positiveButton(){
        return new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
                dialog.cancel();
            }
        };
    }

    private DialogInterface.OnClickListener cancelButton(){
        return new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
                if (subscribe){
                    ApiService.getApiService().subscribeModule(SessionManager.getInstance().getToken(), module.ScolarYear, module.CodeModule, module.CodeInstance)
                            .enqueue(new SubRequete.SubModuleRequete(context, null));
                } else
                    ApiService.getApiService().unsubscribeModule(SessionManager.getInstance().getToken(), module.ScolarYear, module.CodeModule, module.CodeInstance)
                            .enqueue(new UnsubRequete.UnsubModuleRequete(context, null));
            }
        };
    }

    @Override
    public AlertDialog.Builder setOnDismissListener(DialogInterface.OnDismissListener onDismissListener) {
        this.modulesPresenter.refresh();
        return super.setOnDismissListener(onDismissListener);
    }

    public void setProfessorAssitant(String type, List<Module.ResponsableModule> var){
        header.add(type);
        List<HashMap<String, String>> childList = new ArrayList<>();
        HashMap<String, String> childHash = new HashMap<>();
        for (Module.ResponsableModule responsable : var) {
            childHash.put("type", responsable.Type);
            childHash.put("login", responsable.Login);
            childHash.put("title", responsable.Title);
            childHash.put("picture", responsable.Picture);
            childList.add(childHash);
        }
        this.child.put(header.get(header.indexOf(type)), childList);
    }

    public void setActivity(){
        header.add("Activity");
        List<HashMap<String, String>> childList = new ArrayList<>();
        HashMap<String, String> childHash = new HashMap<>();
        if (module.Activity != null) {
            for (Module.Activity activity : this.module.Activity) {
                childHash.put("title", activity.Title);
                childHash.put("desc", activity.Description);
                childList.add(childHash);
            }
            this.child.put(header.get(2), childList);
        }
    }
}
