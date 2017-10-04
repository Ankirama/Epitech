package com.dot.epiandroidwear.api;

import com.google.gson.annotations.SerializedName;

/**
 * Created by doT on 06/01/2016.
 */
public class Message {
    @SerializedName("title")
    public String Title;

    @SerializedName("user")
    public UserMessage User;

    public class UserMessage {
        @SerializedName("picture")
        public String Picture;

        @SerializedName("title")
        public String Title;

        @SerializedName("url")
        public String Url;

        public UserMessage(String picture, String title, String url){
            this.Picture = picture;
            this.Title = title;
            this.Url = url;
        }
    }

    @SerializedName("content")
    public String Content;

    @SerializedName("date")
    public String Date;

    public Message(String title, UserMessage userMessage, String content, String date){
        this.Title = title;
        this.User = userMessage;
        this.Content = content;
        this.Date = date;
    }
}
