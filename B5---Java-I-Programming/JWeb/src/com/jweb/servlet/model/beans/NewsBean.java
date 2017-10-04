package com.jweb.servlet.model.beans;

/**
 * Created by ankirama on 24/12/15.
 */
public class NewsBean {
    private int id;
    private String title;
    private String content;
    private String date;
    private String author;
    private String illustration;

    public NewsBean() {
        id = 0;
        title = "";
        content = "";
        date = "";
        author = "";
        illustration = "";
    }

    public void setId(int value) {this.id = value;}
    public void setTitle(String value) {this.title = value;}
    public void setContent(String value) {this.content = value;}
    public void setDate(String value) {this.date = value;}
    public void setAuthor(String value) {this.author = value;}
    public void setIllustration(String value) {this.illustration = value;}

    public int getId() {return this.id;}
    public String getTitle() {return this.title;}
    public String getContent() {return this.content;}
    public String getDate() {return this.date;}
    public String getAuthor() {return this.author;}
    public String getIllustration() {return this.illustration;}
}
