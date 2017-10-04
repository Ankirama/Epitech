package com.jweb.servlet.model;

import com.jweb.servlet.model.beans.UserBean;
import com.sun.tools.internal.xjc.reader.xmlschema.bindinfo.BIConversion;

import java.io.UnsupportedEncodingException;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.sql.*;
import java.util.ArrayList;
import java.util.HashMap;

/**
 * Created by ankirama on 12/1/2015.
 */
public class ModelUser extends AModele {
    private static final String INSERT_USER_WITHOUT_NAME = "INSERT INTO user (username, password, email, admin) VALUES(?, ?, ?, 0);";
    private static final String SELECT_USER_WITH_USERNAME = "SELECT * FROM user WHERE username=? AND password=?;";
    private static final String SELECT_USER_WITHOUT_PASSWORD = "SELECT * FROM user WHERE username=?;";
    private static final String DELETE_USER_WITH_USERNAME = "UPDATE user SET active=0 WHERE username=?;";
    private static final String UPDATE_ENABLE_ACCOUNT_WITH_ID = "UPDATE user SET active=1 WHERE id=?;";
    private static final String SELECT_USERS = "SELECT * FROM user;";
    private static final String SELECT_ADMIN_EMAIL = "SELECT * FROM user WHERE admin=1;";
    private static final String SELECT_USERS_NO_ADMIN = "SELECT * FROM user WHERE admin=0;";
    private static final String UPDATE_USER_WITHOUT_PASSWORD = "UPDATE user SET email=?, first_name=?, last_name=? WHERE username=?;";
    private static final String UPDATE_USER_WITHOUT_PASS_AND_EMAIL = "UPDATE user SET first_name=?, last_name=? WHERE username=?;";

    public ModelUser() {
        super();
    }

    /**
     * Hash our password to store it in our database
     * @param password current password to hash with md5 algo
     * @return password hashed or null if any error
     */
    private String hashPassword(String password) {
        try {
            byte[] bytesofMessage = password.getBytes("UTF-8");
            MessageDigest md = MessageDigest.getInstance("MD5");
            byte[] digest = md.digest(bytesofMessage);
            StringBuffer sb = new StringBuffer();
            for (byte b: digest) {
                sb.append(String.format("%02x", b & 0xff));
            }
            return sb.toString();
        } catch (NoSuchAlgorithmException | UnsupportedEncodingException e) {
            System.err.println(e);
            return null;
        }
    }

    /**
     * Insert user in DB and return true if no problem
     * @param map map with all information about our user
     * @return {boolean}
     * @throws SQLException
     */
    public UserBean createUser(HashMap<String, String>map) throws SQLException {
        try (
                Connection connection = DriverManager.getConnection(this.m_urlDB);
                PreparedStatement statement = connection.prepareStatement(INSERT_USER_WITHOUT_NAME);
        ) {
            String passwordHashed = this.hashPassword(map.get("password"));

            if (passwordHashed != null) {
                statement.setString(1, map.get("username"));
                statement.setString(2, passwordHashed);
                statement.setString(3, map.get("email"));
                statement.executeUpdate();
                UserBean user = new UserBean();
                user.setEmail(map.get("email"));
                user.setUsername(map.get("username"));
                user.setId(statement.getGeneratedKeys().getInt(1));
                return user;
            } else {
                throw new SQLException("Unable to find our user.");
            }
        } catch (SQLException e) {
            System.err.println(e.getMessage());
            throw new SQLException(e);
        }
    }

    /**
     * find a user in our db, if user found then return a new UserBean
     * @param map all information about our user
     * @return {UserBean}
     * @throws SQLException
     */
    public UserBean getUser(HashMap<String, String> map) throws SQLException {
        try (
                Connection connection = DriverManager.getConnection(this.m_urlDB);
                PreparedStatement statement = connection.prepareStatement(SELECT_USER_WITH_USERNAME);
        ) {
            HashMap<String, Object> result = new HashMap<>();
            statement.setString(1, map.get("username"));
            statement.setString(2, this.hashPassword(map.get("password")));
            ResultSet rs = statement.executeQuery();

            if (rs.next()) {
                UserBean user = new UserBean();
                user.setUsername(rs.getString("username"));
                user.setEmail(rs.getString("email"));
                user.setFirstName(rs.getString("first_name"));
                user.setLastName(rs.getString("last_name"));
                user.setAdmin(rs.getInt("admin") != 0);
                user.setActive(rs.getInt("active") != 0);
                user.setId(rs.getInt("id"));
                return user;
            } else {
                throw new SQLException("unable to find our user.");
            }
        } catch (SQLException e) {
            throw new SQLException(e);
        }
    }

    /**
     * Update information about our user. Return true if no problem
     * @param map information about our user
     * @return {boolean}
     */
    public boolean updateUser(HashMap<String, String> map) {
        try (
                Connection connection = DriverManager.getConnection(this.m_urlDB);
                PreparedStatement statement = connection.prepareStatement(UPDATE_USER_WITHOUT_PASS_AND_EMAIL);
        ) {
            statement.setString(1, map.get("firstName"));
            statement.setString(2, map.get("lastName"));
            statement.setString(3, map.get("username"));
            statement.executeUpdate();
            return true;
        } catch (SQLException e) {
            System.err.println(e.getMessage());
            return false;
        }
    }

    /**
     * Enable user's account
     * @param id
     * @return {boolean}
     */
    public boolean enableUserById(Integer id) {
        try (
                Connection connection = DriverManager.getConnection(this.m_urlDB);
                PreparedStatement statement = connection.prepareStatement(UPDATE_ENABLE_ACCOUNT_WITH_ID);
        ) {
            statement.setInt(1, id);
            statement.executeUpdate();
            return true;
        } catch (SQLException e) {
            System.err.println(e.getMessage());
            return false;
        }
    }

    /**
     * Return id from an entry
     * @param username account's username
     * @return {boolean}
     * @throws SQLException
     */
    public int getUseridFromUsername(String username) throws SQLException {
        try (
                Connection connection = DriverManager.getConnection(this.m_urlDB);
                PreparedStatement statement = connection.prepareStatement(SELECT_USER_WITHOUT_PASSWORD);
        ) {
            statement.setString(1, username);
            ResultSet rs = statement.executeQuery();
            if (rs.next()) {
                return rs.getInt("id");
            } else {
                throw new SQLException("Unable to find the username in our database.");
            }
        } catch (SQLException e) {
            System.err.println(e.getMessage());
            throw new SQLException(e);
        }
    }

    /**
     * delete a user in our table
     * @param username used to find in our table
     * return {boolean}
     * @throws SQLException
     */
    public boolean delUser(String username) {
        try (
                Connection connection = DriverManager.getConnection(this.m_urlDB);
                PreparedStatement statement = connection.prepareStatement(DELETE_USER_WITH_USERNAME);
        ) {
            statement.setString(1, username);
            statement.executeUpdate();
            return true;
        } catch (SQLException e) {
            System.err.println(e.getMessage());
            return false;
        }
    }

    /**
     * select all users no admin and return ArrayList<UserBean>
     * @return {ArrayList<UserBean>}
     * @throws SQLException
     */
    public ArrayList<UserBean> getUsers() throws SQLException {
        try (
                Connection connection = DriverManager.getConnection(this.m_urlDB);
                PreparedStatement statement = connection.prepareStatement(SELECT_USERS_NO_ADMIN);
        ) {
            ResultSet rs = statement.executeQuery();
            ArrayList<UserBean> users = new ArrayList<>();
            while (rs.next()) {
                UserBean user = new UserBean();
                user.setId(rs.getInt("id"));
                user.setUsername(rs.getString("username"));
                user.setFirstName(rs.getString("first_name"));
                user.setLastName(rs.getString("last_name"));
                user.setEmail(rs.getString("email"));
                user.setAdmin(rs.getInt("admin") != 0);
                user.setActive(rs.getInt("active") != 0);
                users.add(user);
            }
            return users;
        } catch (SQLException e) {
            throw new SQLException(e);
        }
    }

    /**
     * Get admin's email to notify admin
     * @return {String}
     */
    public String getEmailAdmin() throws SQLException {
        try (
                Connection connection = DriverManager.getConnection(this.m_urlDB);
                PreparedStatement statement = connection.prepareStatement(SELECT_ADMIN_EMAIL);
        ) {
            ResultSet rs = statement.executeQuery();
            if (rs.next()) {
                return rs.getString("email");
            } else {
                throw new SQLException("Unable to find the username in our database.");
            }
        } catch (SQLException e) {
            System.err.println(e.getMessage());
            throw new SQLException(e);
        }
    }
}
