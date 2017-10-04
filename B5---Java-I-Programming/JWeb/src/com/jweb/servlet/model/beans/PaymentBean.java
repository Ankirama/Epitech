package com.jweb.servlet.model.beans;

/**
 * Created by ankirama on 15/12/15.
 */
public class PaymentBean {
    private int id;
    private String name;
    private String card_numbers;
    private String first_name;
    private String last_name;
    private int userid;

    public PaymentBean() {
        this.id = 0;
        this.name = "";
        this.card_numbers = "";
        this.first_name = "";
        this.last_name = "";
        this.userid = 0;
    }

    public int getId() {return this.id;}
    public String getCard_numbers() {return this.name;}
    public String getName() {return this.card_numbers;}
    public String getFirst_name() {return this.first_name;}
    public String getLast_name() {return this.last_name;}
    public int getUserid() {return this.userid;}

    public void setId(int value) {this.id = value;}
    public void setCard_numbers(String value) {this.name = value;}
    public void setName(String value) {this.card_numbers = value;}
    public void setFirst_name(String value) {this.first_name = value;}
    public void setLast_name(String value) {this.last_name = value;}
    public void setUserid(int value) {this.userid = value;}

}
