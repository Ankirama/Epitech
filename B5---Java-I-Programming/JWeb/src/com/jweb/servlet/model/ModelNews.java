package com.jweb.servlet.model;

import com.jweb.servlet.model.beans.NewsBean;

import java.sql.*;
import java.util.ArrayList;
import java.util.HashMap;

/**
 * Created by ankirama on 24/12/15.
 */
public class ModelNews extends AModele {
    private static final String INSERT_NEWS = "INSERT INTO news (illustration, title, content, author) VALUES(?, ?, ?, 'admin');";
    private static final String DELETE_NEWS_FROM_ID = "DELETE FROM news WHERE id=?;";
    private static final String UPDATE_NEWS_FROM_ID = "UPDATE news SET content=?, title=? WHERE id=?;";
    private static final String SELECT_ALL_NEWS = "SELECT * FROM news;";
    private static final String SELECT_FROM_ID = "SELECT * FROM news WHERE id=?;";

    public ModelNews() {super();}

    /**
     * Update a news
     * @param map map with all our values to update a news
     * @return {boolean}
     */
    public boolean updateNews(HashMap<String, String>map) {
        try (
                Connection connection = DriverManager.getConnection(this.m_urlDB);
                PreparedStatement statement = connection.prepareStatement(UPDATE_NEWS_FROM_ID);
        ) {
            statement.setString(1, map.get("content"));
            statement.setString(2, map.get("title"));
            statement.setInt(3, Integer.parseInt(map.get("id")));
            statement.executeUpdate();
            return true;
        } catch (SQLException e) {
            System.err.println(e.getMessage());
            return false;
        }
    }

    /**
     * Create a new news and return true if no problem, else fales
     * @param map map with all our values to create our news
     * @return {boolean}
     */
    public boolean createNews(HashMap<String, String>map) {
        try (
                Connection connection = DriverManager.getConnection(this.m_urlDB);
                PreparedStatement statement = connection.prepareStatement(INSERT_NEWS);
        ) {
            statement.setString(1, map.get("illustration"));
            statement.setString(2, map.get("title"));
            statement.setString(3, map.get("content"));
            statement.executeUpdate();
            return true;
        } catch (SQLException e) {
            System.err.println(e.getMessage());
            return false;
        }
    }

    /**
     * Get all news and return them in an arraylist<NewsBean>
     * @return {ArrayList<NewsBean>}
     * @throws SQLException
     */
    public ArrayList<NewsBean> getNews() throws SQLException {
        try (
                Connection connection = DriverManager.getConnection(this.m_urlDB);
                PreparedStatement statement = connection.prepareStatement(SELECT_ALL_NEWS);
        ) {
            ArrayList<NewsBean> allNews = new ArrayList<>();
            ResultSet rs = statement.executeQuery();
            while (rs.next()) {
                NewsBean news = new NewsBean();
                news.setId(rs.getInt("id"));
                news.setTitle(rs.getString("title"));
                news.setContent(rs.getString("content"));
                news.setIllustration(rs.getString("illustration"));
                news.setAuthor(rs.getString("author"));
                news.setDate(rs.getString("date_created"));
                allNews.add(news);
            }
            return allNews;
        } catch (SQLException e) {
            System.err.println(e.getMessage());
            throw new SQLException(e);
        }
    }

    /**
     * Get a specific news by its id and return a NewsBean
     * @param id news' id
     * @return {NewsBean}
     * @throws SQLException
     */
    public NewsBean getNewsById(Integer id) throws SQLException {
        try (
                Connection connection = DriverManager.getConnection(this.m_urlDB);
                PreparedStatement statement = connection.prepareStatement(SELECT_FROM_ID);
        ) {
            statement.setInt(1, id);
            ResultSet rs = statement.executeQuery();
            if (rs.next()) {
                NewsBean news = new NewsBean();
                news.setId(rs.getInt("id"));
                news.setTitle(rs.getString("title"));
                news.setContent(rs.getString("content"));
                news.setIllustration(rs.getString("illustration"));
                news.setAuthor(rs.getString("author"));
                news.setDate(rs.getString("date_created"));
                return news;
            } else {
                throw new SQLException("Unable to find our news.");
            }
        } catch (SQLException e) {
            System.err.println(e.getMessage());
            throw new SQLException(e);
        }
    }

    /**
     * Delete a news with its id
     * @param id news' id
     * @return {boolean}
     */
    public boolean deleteNewsById(Integer id) {
        try (
                Connection connection = DriverManager.getConnection(this.m_urlDB);
                PreparedStatement statement = connection.prepareStatement(DELETE_NEWS_FROM_ID);
        ) {
            statement.setInt(1, id);
            statement.executeUpdate();
            return true;
        } catch (SQLException e) {
            System.err.println(e.getMessage());
            return false;
        }
    }
}
