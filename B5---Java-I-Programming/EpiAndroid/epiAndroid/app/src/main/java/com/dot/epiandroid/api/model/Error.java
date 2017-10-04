package com.dot.epiandroid.api.model;

import com.google.gson.annotations.SerializedName;

/**
 * Created by doT on 06/01/2016.
 */
public class Error {
    @SerializedName("error")
    public ErrorBody errorBody;

    public class ErrorBody{
        @SerializedName("message")
        public String Message;

        @SerializedName("code")
        public int Code;
    }
}
