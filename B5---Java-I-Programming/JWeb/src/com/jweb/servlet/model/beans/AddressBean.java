package com.jweb.servlet.model.beans;

/**
 * Created by ankirama on 15/12/15.
 */
public class AddressBean {
    private int id;
    private String name;
    private String firstName;
    private String lastName;
    private String address1;
    private String address2;
    private String city;
    private String country;
    private int userid;

    public AddressBean() {
        this.id = 0;
        this.name = "";
        this.firstName = "";
        this.lastName = "";
        this.address1 = "";
        this.address2 = "";
        this.city = "";
        this.country = "";
        this.userid = 0;
    }

    public int getId() {return this.id;}
    public String getName() {return this.name;}
    public String getFirstName() {return this.firstName;}
    public String getLastName() {return this.lastName;}
    public String getAddress1() {return this.address1;}
    public String getAddress2() {return this.address2;}
    public String getCity() {return this.city;}
    public String getCountry() {return this.country;}
    public int getUserid() {return this.userid;}

    public void setId(int id) {this.id = id;}
    public void setName(String name) {this.name = name;}
    public void setFirstName(String name) {this.firstName = name;}
    public void setLastName(String name) {this.lastName = name;}
    public void setAddress1(String address1) {this.address1 = address1;}
    public void setAddress2(String address2) {this.address2 = address2;}
    public void setCity(String city) {this.city = city;}
    public void setCountry(String country) {this.country = country;}
    public void setUserid(int userid) {this.userid = userid;}
}
