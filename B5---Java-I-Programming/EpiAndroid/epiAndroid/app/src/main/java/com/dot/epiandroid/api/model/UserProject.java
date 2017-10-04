package com.dot.epiandroid.api.model;

import com.google.gson.annotations.SerializedName;

/**
 * Created by doT on 18/01/2016.
 */
public class UserProject {
    @SerializedName("codemodule")
    public String CodeModule;

    @SerializedName("project")
    public String Project;

    @SerializedName("end_acti")
    public String EndActi;

    @SerializedName("acti_title")
    public String ActiTitle;

    @SerializedName("title_module")
    public String TitleModule;

    @SerializedName("num")
    public String Num;

    @SerializedName("begin_acti")
    public String BeginActi;

    @SerializedName("scolaryear")
    public String ScolarYear;

    @SerializedName("code_location")
    public String CodeLocation;

    @SerializedName("codeacti")
    public String CodeActi;

    @SerializedName("registered")
    public String Registered;

    @SerializedName("codeinstance")
    public String CodeInstance;

    @SerializedName("type_acti")
    public String TypeActi;
}
