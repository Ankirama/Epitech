package com.jweb.servlet.model;

import com.jweb.servlet.model.beans.PaymentBean;

import java.sql.*;
import java.util.ArrayList;
import java.util.HashMap;

/**
 * Created by ankirama on 15/12/15.
 */
public class ModelPayment extends AModele {
    private static final String DELETE_FROM_ID_USER = "DELETE FROM payment WHERE userid=?;";
    private static final String INSERT_PAYMENT = "INSERT INTO payment (name, card_numbers, first_name, last_name, userid) VALUES(?, ?, ?, ?, ?);";
    private static final String DELETE_PAYMENT = "DELETE FROM payment WHERE name=?;";
    private static final String SELECT_PAYMENTS_FROM_USER_ID = "SELECT * FROM payment WHERE userid=?;";

    public ModelPayment() {
        super();
    }

    /**
     * Delete delete all address associated to a userid
     * @param id userid to find addresses
     * @return {boolean}
     */
    public boolean delPaymentsFromID(Integer id) {
        try (
                Connection connection = DriverManager.getConnection(this.m_urlDB);
                PreparedStatement statement = connection.prepareStatement(DELETE_FROM_ID_USER);
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
     * delete a specific payment with its name
     * @param name payment's name
     * @return {boolean}
     */
    public boolean delPayment(String name) {
        try (
                Connection connection = DriverManager.getConnection(this.m_urlDB);
                PreparedStatement statement = connection.prepareStatement(DELETE_PAYMENT);
        ) {
            statement.setString(1, name);
            statement.executeUpdate();
            return true;
        } catch (SQLException e) {
            System.err.println(e.getMessage());
            return false;
        }
    }

    /**
     * return all payments found from userid
     * @param userid used to find payments from our user
     * @return {HashMap<String, PaymentBean>}
     */
    public ArrayList<PaymentBean> getPayments(Integer userid) throws SQLException {
        try (
                Connection connection = DriverManager.getConnection(this.m_urlDB);
                PreparedStatement statement = connection.prepareStatement(SELECT_PAYMENTS_FROM_USER_ID);
        ) {
            ArrayList<PaymentBean> payments = new ArrayList<>();
            statement.setInt(1, userid);
            ResultSet rs = statement.executeQuery();
            while (rs.next()) {
                PaymentBean payment = new PaymentBean();
                payment.setId(rs.getInt("id"));
                payment.setName(rs.getString("name"));
                payment.setFirst_name(rs.getString("first_name"));
                payment.setLast_name(rs.getString("last_name"));
                payment.setCard_numbers(rs.getString("card_numbers"));
                payment.setUserid(rs.getInt("userid"));
                payments.add(payment);
            }
            return payments;
        } catch (SQLException e) {
            System.err.println(e.getMessage());
            throw new SQLException(e);
        }
    }

    /**
     * add a payment in our table for a specific user
     * @param map values
     * @return {PaymentBean}
     */
    public PaymentBean createPayment(HashMap<String, String> map) throws SQLException {
        try (
                Connection connection = DriverManager.getConnection(this.m_urlDB);
                PreparedStatement statement = connection.prepareStatement(INSERT_PAYMENT);
        ) {
            statement.setString(1, map.get("name"));
            statement.setString(2, map.get("cardNumbers"));
            statement.setString(3, map.get("firstName"));
            statement.setString(4, map.get("lastName"));
            statement.setInt(5, Integer.parseInt(map.get("userid")));
            statement.executeUpdate();
            PaymentBean payment = new PaymentBean();
            payment.setId(statement.getGeneratedKeys().getInt(1));
            payment.setName(map.get("name"));
            payment.setFirst_name(map.get("firstName"));
            payment.setLast_name(map.get("lastName"));
            payment.setCard_numbers(map.get("CardNumbers"));
            payment.setUserid(Integer.parseInt(map.get("userid")));
            return payment;
        } catch (SQLException e) {
            System.err.println(e.getMessage());
            throw new SQLException(e);
        }
    }
}
