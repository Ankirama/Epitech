package com.jweb.servlet.model;

import com.jweb.servlet.model.beans.OpinionBean;

import java.sql.*;
import java.util.ArrayList;
import java.util.HashMap;

/**
 * Created by ankirama on 25/12/15.
 */
public class ModelOpinion extends AModele {
    private static final String INSERT_OPINION = "INSERT INTO opinion (note, comment, author, productid) VALUES(?, ?, ?, ?);";
    private static final String DELETE_OPINION_BY_ID = "DELETE FROM opinion WHERE id=?;";
    private static final String UPDATE_OPINION_BY_ID = "UPDATE opinion SET note=?, comment=? WHERE productid=?;";
    private static final String SELECT_OPINIONS_BY_PRODUCT = "SELECT * FROM opinion WHERE productid=?;";
    private static final String SELECT_OPINION_BY_ID = "SELECT * FROM opinion WHERE id=?;";

    public ModelOpinion() {super();}

    /**
     * Create new opinion
     * @param map
     * @return {boolean}
     */
    public boolean createOpinion(HashMap<String, String>map) {
        try (
                Connection connection = DriverManager.getConnection(this.m_urlDB);
                PreparedStatement statement = connection.prepareStatement(INSERT_OPINION);
        ) {
            statement.setInt(1, Integer.parseInt(map.get("note")));
            statement.setString(2, map.get("comment"));
            statement.setString(3, map.get("author"));
            statement.setInt(4, Integer.parseInt(map.get("productid")));
            statement.executeUpdate();
            return true;
        } catch (SQLException e) {
            System.err.println(e.getMessage());
            return false;
        }
    }

    /**
     * Delete an opinion with specific id
     * @param id
     * @return {boolean}
     */
    public boolean deleteOpinionById(Integer id) {
        try (
                Connection connection = DriverManager.getConnection(this.m_urlDB);
                PreparedStatement statement = connection.prepareStatement(DELETE_OPINION_BY_ID);
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
     * Update opinion's note / comment
     * @param map
     * @return {boolean}
     */
    public boolean updateOpinionById(HashMap<String, String>map) {
        try (
                Connection connection = DriverManager.getConnection(this.m_urlDB);
                PreparedStatement statement = connection.prepareStatement(UPDATE_OPINION_BY_ID);
        ) {
            statement.setInt(1, Integer.parseInt(map.get("note")));
            statement.setString(2, map.get("comment"));
            statement.setInt(3, Integer.parseInt(map.get("productid")));
            statement.executeUpdate();
            return true;
        } catch (SQLException e) {
            System.err.println(e.getMessage());
            return false;
        }
    }

    /**
     * get an opinion by its id
     * @param id
     * @return {OpinionBean}
     * @throws SQLException
     */
    public OpinionBean getOpinionById(Integer id) throws SQLException {
        try (
                Connection connection = DriverManager.getConnection(this.m_urlDB);
                PreparedStatement statement = connection.prepareStatement(SELECT_OPINION_BY_ID);
        ) {
            statement.setInt(1, id);
            ResultSet rs = statement.executeQuery();
            if (rs.next()) {
                OpinionBean opinion = new OpinionBean();
                opinion.setId(rs.getInt("id"));
                opinion.setComment(rs.getString("comment"));
                opinion.setNote(rs.getInt("note"));
                opinion.setProductid(rs.getInt("productid"));
                opinion.setAuthor(rs.getString("author"));
                return opinion;
            } else {
                throw new SQLException("Unable to find our news.");
            }
        } catch (SQLException e) {
            System.err.println(e.getMessage());
            throw new SQLException(e);
        }
    }

    /**
     * get opinions by their productid
     * @param productid
     * @return {ArrayList<OpinionBean>}
     * @throws SQLException
     */
    public ArrayList<OpinionBean> getOpinionsByProduct(Integer productid) throws SQLException {
        try (
                Connection connection = DriverManager.getConnection(this.m_urlDB);
                PreparedStatement statement = connection.prepareStatement(SELECT_OPINIONS_BY_PRODUCT);
        ) {
            statement.setInt(1, productid);
            ResultSet rs = statement.executeQuery();
            ArrayList<OpinionBean> opinions = new ArrayList<>();
            while (rs.next()) {
                OpinionBean opinion = new OpinionBean();
                opinion.setId(rs.getInt("id"));
                opinion.setComment(rs.getString("comment"));
                opinion.setNote(rs.getInt("note"));
                opinion.setProductid(rs.getInt("productid"));
                opinion.setAuthor(rs.getString("author"));
                opinions.add(opinion);
            }
            return opinions;
        } catch (SQLException e) {
            System.err.println(e.getMessage());
            throw new SQLException(e);
        }
    }
}
