package com.jweb.servlet.model;

import java.sql.*;

/**
 * Created by ankirama on 11/30/2015.
 */
public abstract class AModele {
    protected String            m_urlDB = "jdbc:sqlite:/Users/ankirama/rendu/JWeb/data/jweb.db";
    public AModele() {
        try {
            Class.forName("org.sqlite.JDBC");
        } catch (ClassNotFoundException e) {
            System.err.println(e.getMessage());
        }
    }
}
