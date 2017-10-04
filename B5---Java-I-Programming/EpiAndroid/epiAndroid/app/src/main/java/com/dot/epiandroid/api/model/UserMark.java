package com.dot.epiandroid.api.model;

import com.google.gson.annotations.SerializedName;

import java.util.List;

/**
 * Created by doT on 18/01/2016.
 */
public class UserMark {
    @SerializedName("notes")
    public List<Mark> Mark;

    public class Mark {
        @SerializedName("scolaryear")
        public String ScolarYear;

        @SerializedName("codemodule")
        public String CodeModule;

        @SerializedName("titlemodule")
        public String TitleModule;

        @SerializedName("codeinstance")
        public String CodeInstance;

        @SerializedName("codeacti")
        public String CodeActi;

        @SerializedName("title")
        public String Title;

        @SerializedName("date")
        public String Date;

        @SerializedName("correcteur")
        public String Correcteur;

        @SerializedName("final_note")
        public String Mark;

        @SerializedName("comment")
        public String Comment;
    }
}
