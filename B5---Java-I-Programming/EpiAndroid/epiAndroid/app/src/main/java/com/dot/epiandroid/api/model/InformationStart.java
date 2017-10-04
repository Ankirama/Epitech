package com.dot.epiandroid.api.model;

import com.google.gson.annotations.SerializedName;

import java.util.List;

/**
 * Created by doT on 06/01/2016.
 */
public class InformationStart {
    @SerializedName("infos")
    public Infos Infos;

    @SerializedName("board")
    public Board Board;

    public class Infos {
        @SerializedName("activity_login")
        public String Login;

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
    }

    public class Board {
        @SerializedName("notes")
        public List<Note> Notes;

        @SerializedName("projets")
        public List<Project> Projets;

        @SerializedName("modules")
        public List<Modules> Modules;

        @SerializedName("activities")
        public List<Activities> Activities;
    }

    public class Note {
        @SerializedName("title")
        public String Title;

        @SerializedName("title_link")
        public String TitleLink;

        @SerializedName("note")
        public String Note;

        @SerializedName("noteur")
        public String Noteur;
    }

    public class Project {
        @SerializedName("title")
        public String Title;
    }

    public class Modules {
        @SerializedName("title")
        public String Title;
    }

    public class Activities {
        @SerializedName("title")
        public String Title;
    }
}
