package com.dot.epiandroid.api.model;

import android.app.Activity;

import com.google.gson.annotations.SerializedName;

import java.util.List;

/**
 * Created by doT on 11/01/2016.
 */
public class Module {
    @SerializedName("title")
    public String Title;

    @SerializedName("grade")
    public String Grade;

    @SerializedName("cycle")
    public String Cycle;

    @SerializedName("codemodule")
    public String CodeModule;

    @SerializedName("code")
    public String Code;

    @SerializedName("codeinstance")
    public String CodeInstance;

    @SerializedName("date_ins")
    public String DateIns;

    @SerializedName("scolaryear")
    public String ScolarYear;

    @SerializedName("semester")
    public String Semester;

    @SerializedName("begin")
    public String Begin;

    @SerializedName("end_register")
    public String EndRegister;

    @SerializedName("end")
    public String End;

    @SerializedName("credits")
    public String Credit;

    @SerializedName("description")
    public String Description;

    @SerializedName("competence")
    public String Competence;

    @SerializedName("instance_location")
    public String InstanceLocation;

    @SerializedName("status")
    public String Status;

    @SerializedName("resp")
    public List<ResponsableModule> Responsable;

    @SerializedName("assistant")
    public List<ResponsableModule> Assistant;

    @SerializedName("activites")
    public List<Activity> Activity;

    @SerializedName("student_registered")
    public String StudentRegistered;

    @SerializedName("student")
    public String StudentGrade;

    @SerializedName("student_credits")
    public String StudentCredit;

    @SerializedName("allow_register")
    public String AllowRegister;

    public class ResponsableModule {
        @SerializedName("type")
        public String Type;

        @SerializedName("activity_login")
        public String Login;

        @SerializedName("title")
        public String Title;

        @SerializedName("picture")
        public String Picture;
    }

    public class Activity {
        @SerializedName("slug")
        public String Slug;

        @SerializedName("instance_location")
        public String Location;

        @SerializedName("title")
        public String Title;

        @SerializedName("description")
        public String Description;

        @SerializedName("type_title")
        public String Type;

        @SerializedName("project_title")
        public String ProjectTitle;

        @SerializedName("begin")
        public String Begin;

        @SerializedName("Start")
        public String Start;

        @SerializedName("end_register")
        public String EndRegister;

        @SerializedName("end")
        public String End;

        @SerializedName("deadline")
        public String DeadLine;
    }
}
