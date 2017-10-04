package com.jweb.servlet.model;

import java.sql.*;
import java.util.ArrayList;
import java.util.HashMap;

/**
 * Created by ankirama on 14/12/15.
 */
public class ModelNewsletter extends AModele{
    private final String INSERT_EMAIL = "INSERT INTO newsletter (email) VALUES(?);";
    private final String SELECT_EMAIL = "SELECT id FROM newsletter WHERE email=?;";
    private final String DELETE_EMAIL = "DELETE FROM newsletter WHERE email=?;";
    private final String SELECT_EMAILS = "SELECT * FROM newsletter;";

    public ModelNewsletter() {
        super();
    }

    /**
     * Get emails in our db
     * @return {ArrayList<String>}
     * @throws SQLException
     */
    public ArrayList<String> getEmails() throws SQLException{
        try (
                Connection connection = DriverManager.getConnection(this.m_urlDB);
                PreparedStatement statement = connection.prepareStatement(SELECT_EMAILS);
        ) {
            ResultSet rs = statement.executeQuery();
            ArrayList<String> emails = new ArrayList<>();
            while (rs.next()) {
                String email = rs.getString("email");
                emails.add(email);
            }
            return emails;
        } catch (SQLException e) {
            System.err.println(e.getMessage());
            throw new SQLException(e);
        }
    }

    /**
     * Add email in our table
     * @param email email to add
     * @return {boolean}
     */
    public boolean addEmail(String email) {
        try (
                Connection connection = DriverManager.getConnection(this.m_urlDB);
                PreparedStatement statement = connection.prepareStatement(INSERT_EMAIL);
        ) {
            statement.setString(1, email);
            statement.executeUpdate();
            return true;
        } catch (SQLException e) {
            return false;
        }
    }

    /**
     * Remove an email in our table
     * @param email email to remove
     * @return {boolean}
     */
    public boolean delEmail(String email) {
        try (
                Connection connection = DriverManager.getConnection(this.m_urlDB);
                PreparedStatement statement = connection.prepareStatement(DELETE_EMAIL);
        ) {
            statement.setString(1, email);
            statement.executeUpdate();
            return true;
        } catch (SQLException e) {
            return false;
        }
    }

    public boolean selectEmail(String email) {
        try (
                Connection connection = DriverManager.getConnection(this.m_urlDB);
                PreparedStatement statement = connection.prepareStatement(SELECT_EMAIL);
        ) {
            statement.setString(1, email);
            return statement.executeQuery().next();
        } catch (SQLException e) {
            System.err.println(e.getMessage());
            return false;
        }
    }
}
