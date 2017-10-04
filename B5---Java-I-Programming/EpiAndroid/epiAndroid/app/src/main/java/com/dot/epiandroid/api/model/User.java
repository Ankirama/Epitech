package com.dot.epiandroid.api.model;

import com.google.gson.annotations.SerializedName;

import java.util.List;

/**
 * Created by doT on 13/01/2016.
 */
public class User {
    @SerializedName("activity_login")
    public String Login;

    @SerializedName("title")
    public String Title;

    @SerializedName("lastname")
    public String LastName;

    @SerializedName("firstname")
    public String FirstName;

    @SerializedName("email")
    public String Email;

    @SerializedName("internal_email")
    public String EmailIntern;

    @SerializedName("location")
    public String Location;

    @SerializedName("netsoul")
    public String Netsoul;

    @SerializedName("studentyear")
    public int SchoolYear;

    @SerializedName("semester")
    public int Semester;

    @SerializedName("promo")
    public int Promo;

    @SerializedName("credit")
    public int Credit;

    @SerializedName("gpa")
    public List<GPA> Gpa;

    @SerializedName("userinfo")
    public UserInfo UserInfo;

    @SerializedName("nsstat")
    public NsStat NsStat;

    @SerializedName("course_code")
    public String CourseCode;

    @SerializedName("picture")
    public String Picture;

    public class UserInfo{
        @SerializedName("email")
        public InfosPerso Email;

        @SerializedName("job")
        public InfosPerso Job;

        @SerializedName("website")
        public InfosPerso Website;

        @SerializedName("poste")
        public InfosPerso Poste;

        @SerializedName("telephone")
        public InfosPerso Telephone;

        public class InfosPerso{
            @SerializedName("value")
            public String Value;

            @SerializedName("adm")
            public String Adm;

            @SerializedName("public")
            public boolean Visible;
        }
    }

    public class GPA {
        @SerializedName("gpa")
        public String Gpa;

        @SerializedName("cycle")
        public String Cycle;
    }

    public class NsStat {
        @SerializedName("active")
        public double Active;

        @SerializedName("idle")
        public double Idle;

        @SerializedName("out_active")
        public double OutActive;

        @SerializedName("out_idle")
        public double OutIdle;

        @SerializedName("nslog_norm")
        public int NsLogNorm;
    }
}
