package com.jweb.servlet.utils;

/**
 * Created by ankirama on 27/12/15.
 */
public class ProductCart {
    private int id;
    private float price;
    private float total;
    private String name;
    private int quantity;

    public ProductCart() {
        id = 0;
        price = 0;
        total = 0;
        name = "";
        quantity = 0;
    }

    public void setId(int id) {this.id = id;}
    public void setPrice(float id) {this.price = id;}
    public void setTotal(float id) {this.total = id;}
    public void setName(String id) {this.name = id;}
    public void setQuantity(int id) {this.quantity = id;}

    public int getId() {return this.id;}
    public float getPrice() {return this.price;}
    public float getTotal() {return this.total;}
    public String getName() {return this.name;}
    public int getQuantity() {return this.quantity;}

}
