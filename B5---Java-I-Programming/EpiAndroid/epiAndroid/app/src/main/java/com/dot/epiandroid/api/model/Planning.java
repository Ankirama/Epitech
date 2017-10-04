package com.dot.epiandroid.api.model;

import com.google.gson.annotations.SerializedName;

import java.util.List;

/**
 * Created by doT on 11/01/2016.
 */
public class Planning {
    @SerializedName("type_title")
    public String TypeTitle;

    @SerializedName("instance_location")
    public String Location;

    @SerializedName("titlemodule")
    public String TitleModule;

    @SerializedName("description")
    public String Description;

    @SerializedName("semester")
    public int Semester;

    @SerializedName("scolaryear")
    public String ScolarYear;

    @SerializedName("start")
    public String Start;

    @SerializedName("nb_hours")
    public String NbHours;

    @SerializedName("codemodule")
    public String CodeModule;

    @SerializedName("codeevent")
    public String CodeEvent;

    @SerializedName("codeinstance")
    public String CodeInstance;

    @SerializedName("total_students_registered")
    public int TotalStudentRegistered;

    @SerializedName("codeacti")
    public String CodeActi;

    @SerializedName("room")
    public Room Room;

    @SerializedName("prof_inst")
    public List<Professor> Professor;

    @SerializedName("acti_title")
    public String Title;

    @SerializedName("module_registered")
    public boolean ModuleRegistered;

    @SerializedName("allow_register")
    public boolean AllowRegister;

    @SerializedName("register_student")
    public boolean RegisterStudent;

    @SerializedName("event_registered")
    public String EventRegistered;

    @SerializedName("end")
    public String End;

    @SerializedName("allow_token")
    public boolean AllowToken;

    public class Professor {
        @SerializedName("type")
        public String User;

        @SerializedName("activity_login")
        public String Login;

        @SerializedName("title")
        public String Title;

        @SerializedName("Picture")
        public String Picture;
    }

    public class Room {
        @SerializedName("seats")
        public String Seats;

        @SerializedName("type")
        public String Type;

        @SerializedName("code")
        public String Code;
    }
}
