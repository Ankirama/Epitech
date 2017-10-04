package com.dot.epiandroid.api.model;

import com.google.gson.annotations.SerializedName;

import java.util.List;

/**
 * Created by doT on 18/01/2016.
 */
public class Trombi {
    @SerializedName("items")
    public List<UserTrombi> User;

    @SerializedName("total")
    public String Total;

    public class UserTrombi {
        @SerializedName("title")
        public String Title;

        @SerializedName("login")
        public String Login;

        @SerializedName("nom")
        public String Nom;

        @SerializedName("prenom")
        public String Prenom;

        @SerializedName("picture")
        public String Picture;

        @SerializedName("location")
        public String Location;
    }
}
