package com.jweb.servlet.model.beans;

import java.sql.ResultSet;
import java.sql.SQLException;

/**
 * Created by ankirama on 13/12/15.
 */
public class UserBean {
    private int     id;
    private String  username;
    private String  email;
    private String  firstName;
    private String  lastName;
    private boolean admin;
    private boolean active;

    public UserBean() {
        this.id = 0;
        this.username = "";
        this.email = "";
        this.firstName = "";
        this.lastName = "";
        this.admin = false;
        this.active = true;
    }

    public int getId() {return this.id;}
    public String getUsername() { return this.username;}
    public String getEmail() {return this.email;}
    public String getFirstName() {return this.firstName;}
    public String getLastName() {return this.lastName;}
    public boolean getAdmin() {return this.admin;}
    public boolean getActive() {return this.active;}

    public void setId(int id) {this.id = id;}
    public void setUsername(String username) {this.username = username;}
    public void setEmail(String email) {this.email = email;}
    public void setFirstName(String firstName) {this.firstName = firstName;}
    public void setLastName(String lastName) {this.lastName = lastName;}
    public void setAdmin(boolean admin) {this.admin = admin;}
    public void setActive(boolean active) {this.active = active;}
}
