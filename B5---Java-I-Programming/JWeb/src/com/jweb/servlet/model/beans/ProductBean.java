package com.jweb.servlet.model.beans;

/**
 * Created by ankirama on 25/12/15.
 */
public class ProductBean {
    private int id;
    private String name;
    private float price;
    private String description;
    private String illustration;
    private int categoryid;
    private boolean active;

    public ProductBean() {
        id = 0;
        name = "";
        price = 0;
        description = "";
        illustration = "";
        active = true;
    }

    public void setId(int value) {this.id = value;}
    public void setName(String value) {this.name = value;}
    public void setPrice(float value) {this.price = value;}
    public void setDescription(String value) {this.description = value;}
    public void setCategoryid(int value) {this.categoryid = value;}
    public void setIllustration(String value) {this.illustration = value;}
    public void setActive(boolean value) {this.active = value;}

    public int getId() {return this.id;}
    public String getName() {return this.name;}
    public float getPrice() {return this.price;}
    public String getDescription() {return this.description;}
    public int getCategoryid() {return this.categoryid;}
    public String getIllustration() {return this.illustration;}
    public boolean getActive() {return this.active;}
}
