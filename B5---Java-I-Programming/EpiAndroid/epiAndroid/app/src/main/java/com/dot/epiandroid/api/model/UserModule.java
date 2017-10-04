package com.dot.epiandroid.api.model;

import com.google.gson.annotations.SerializedName;

import java.util.List;

/**
 * Created by doT on 10/01/2016.
 */
public class UserModule {
    @SerializedName("modules")
    public List<UserModules> UserModules;

    public class UserModules{
        @SerializedName("title")
        public String Title;

        @SerializedName("grade")
        public String Grade;

        @SerializedName("cycle")
        public String Cycle;

        @SerializedName("codemodule")
        public String CodeModule;

        @SerializedName("codeinstance")
        public String CodeInstance;

        @SerializedName("scholaryear")
        public String SchoolYear;

        @SerializedName("semester")
        public String Semester;

        @SerializedName("date_ins")
        public String DateIns;

        @SerializedName("credits")
        public int Credit;
    }
}
