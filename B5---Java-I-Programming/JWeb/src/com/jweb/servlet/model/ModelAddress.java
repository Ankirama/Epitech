package com.jweb.servlet.model;

import com.jweb.servlet.model.beans.AddressBean;

import java.sql.*;
import java.util.ArrayList;
import java.util.HashMap;

/**
 * Created by ankirama on 15/12/15.
 */
public class ModelAddress extends AModele {
    private static final String DELETE_FROM_ID_USER = "DELETE FROM address WHERE userid=?;";
    private static final String INSERT_ADDRESS = "INSERT INTO address (name, first_name, last_name, address1, address2, city, country, userid) VALUES(?, ?, ?, ?, ?, ?, ?, ?);";
    private static final String DELETE_ADDRESS = "DELETE FROM address WHERE name=?;";
    private static final String SELECT_ADDRESSES_FROM_USER_ID = "SELECT * FROM address WHERE userid=?;";

    public ModelAddress() {
        super();
    }

    /**
     * Delete delete all address associated to a userid
     * @param id userid to find addresses
     * @return {boolean}
     */
    public boolean delAddressesFromID(Integer id) {
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
     * delete a specific address with its name
     * @param name address' name
     * @return {boolean}
     */
    public boolean delAddress(String name) {
        try (
                Connection connection = DriverManager.getConnection(this.m_urlDB);
                PreparedStatement statement = connection.prepareStatement(DELETE_ADDRESS);
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
     * return all addresses found from userid
     * @param userid used to find addresses from our user
     * @return {HashMap<String, AddressBean>}
     */
    public ArrayList<AddressBean> getAddresses(Integer userid) throws SQLException {
        try (
            Connection connection = DriverManager.getConnection(this.m_urlDB);
            PreparedStatement statement = connection.prepareStatement(SELECT_ADDRESSES_FROM_USER_ID);
        ) {
            ArrayList<AddressBean> addresses = new ArrayList<>();
            statement.setInt(1, userid);
            ResultSet rs = statement.executeQuery();
            while (rs.next()) {
                AddressBean address = new AddressBean();
                address.setId(rs.getInt("id"));
                address.setName(rs.getString("name"));
                address.setFirstName(rs.getString("first_name"));
                address.setLastName(rs.getString("last_name"));
                address.setAddress1(rs.getString("address1"));
                address.setAddress2(rs.getString("address2"));
                address.setCity(rs.getString("city"));
                address.setCountry(rs.getString("country"));
                address.setUserid(rs.getInt("userid"));
                addresses.add(address);
            }
            return addresses;
        } catch (SQLException e) {
            System.err.println(e.getMessage());
            throw new SQLException(e);
        }
    }

    /**
     * add an address in our table for a specific user
     * @param map values
     * @return {AddressBean}
     */
    public AddressBean createAddress(HashMap<String, String> map) throws SQLException {
        try (
                Connection connection = DriverManager.getConnection(this.m_urlDB);
                PreparedStatement statement = connection.prepareStatement(INSERT_ADDRESS);
        ) {
            statement.setString(1, map.get("name"));
            statement.setString(2, map.get("firstName"));
            statement.setString(3, map.get("lastName"));
            statement.setString(4, map.get("address1"));
            statement.setString(5, map.get("address2"));
            statement.setString(6, map.get("city"));
            statement.setString(7, map.get("country"));
            statement.setInt(8, Integer.parseInt(map.get("userid")));
            statement.executeUpdate();
            AddressBean address = new AddressBean();
            address.setId(statement.getGeneratedKeys().getInt(1));
            address.setName(map.get("name"));
            address.setFirstName(map.get("firstName"));
            address.setLastName(map.get("lastName"));
            address.setAddress1(map.get("address1"));
            address.setAddress2(map.get("address2"));
            address.setCity(map.get("city"));
            address.setCountry(map.get("country"));
            address.setUserid(Integer.parseInt(map.get("userid")));
            return address;
        } catch (SQLException e) {
            System.err.println(e.getMessage());
            throw new SQLException(e);
        }
    }
}
