package com.jweb.servlet.model.beans;

/**
 * Created by ankirama on 25/12/15.
 */
public class OpinionBean {
    private int id;
    private int note;
    private String comment;
    private String author;
    private int productid;

    public OpinionBean() {
        id = 0;
        note = 0;
        comment = "";
        author = "";
        productid = 0;
    }

    public void setId(int value) {this.id = value;}
    public void setNote(int value) {this.note = value;}
    public void setComment(String value) {this.comment = value;}
    public void setAuthor(String value) {this.author = value;}
    public void setProductid(int value) {this.productid = value;}

    public int getId() {return this.id;}
    public int getNote() {return this.note;}
    public String getComment() {return this.comment;}
    public String getAuthor() {return this.author;}
    public int getProductid() {return this.productid;}
}
