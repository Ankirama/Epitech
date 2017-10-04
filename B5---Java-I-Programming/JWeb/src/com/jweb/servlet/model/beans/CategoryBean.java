package com.jweb.servlet.model.beans;

/**
 * Created by ankirama on 25/12/15.
 */
public class CategoryBean {
    private int id;
    private String name;
    private String slug;

    public CategoryBean() {
        id = 0;
        name = "";
        slug = "";
    }

    public void setId(int value) {this.id = value;}
    public void setName(String value) {this.name = value;}
    public void setSlug(String value) {this.slug = value;}

    public int getId() {return this.id;}
    public String getName() {return this.name;}
    public String getSlug() {return this.slug;}
}
