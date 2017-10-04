package com.jweb.servlet.model;

import com.jweb.servlet.model.beans.CategoryBean;

import java.sql.*;
import java.util.ArrayList;
import java.util.HashMap;

/**
 * Created by ankirama on 25/12/15.
 */
public class ModelCategory extends AModele {
    private static final String INSERT_CATEGORY = "INSERT INTO category (name, slug) VALUES(?, ?);";
    private static final String DELETE_CATEGORY_FROM_ID = "DELETE FROM category WHERE id=?;";
    private static final String DELETE_CATEGORIES = "DELETE FROM category;";
    private static final String SELECT_CATEGORY_FROM_ID = "SELECT * FROM category WHERE id=?;";
    private static final String SELECT_CATEGORIES = "SELECT * FROM category;";
    private static final String SELECT_CATEGORY_FROM_SLUG = "SELECT * FROM category WHERE slug=?;";

    public ModelCategory() {super();}

    /**
     * Create a new category
     * @param name category's name
     * @return {boolean}
     */
    public boolean createCategory(String name) {
        try (
                Connection connection = DriverManager.getConnection(this.m_urlDB);
                PreparedStatement statement = connection.prepareStatement(INSERT_CATEGORY);
        ) {
            statement.setString(1, name);
            statement.setString(2, name.replace(' ', '_').toLowerCase());
            statement.executeUpdate();
            return true;
        } catch (SQLException e) {
            System.err.println(e.getMessage());
            return false;
        }
    }

    /**
     * Delete a category
     * @param id category's id
     * @return {boolean}
     */
    public boolean deleteCategoryById(Integer id) {
        try (
                Connection connection = DriverManager.getConnection(this.m_urlDB);
                PreparedStatement statement = connection.prepareStatement(DELETE_CATEGORY_FROM_ID);
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
     * Delete categories
     * @return {boolean}
     */
    public boolean deleteCategories() {
        try (
                Connection connection = DriverManager.getConnection(this.m_urlDB);
                PreparedStatement statement = connection.prepareStatement(DELETE_CATEGORIES);
        ) {
            statement.executeUpdate();
            return true;
        } catch (SQLException e) {
            System.err.println(e.getMessage());
            return false;
        }
    }

    /**
     * Get a category by its id
     * @param id category's id
     * @return {CategoryBean}
     * @throws SQLException
     */
    public CategoryBean getCategoryById(Integer id) throws SQLException{
        try (
                Connection connection = DriverManager.getConnection(this.m_urlDB);
                PreparedStatement statement = connection.prepareStatement(SELECT_CATEGORY_FROM_ID);
        ) {
            statement.setInt(1, id);
            ResultSet rs = statement.executeQuery();
            if (rs.next()) {
                CategoryBean category = new CategoryBean();
                category.setId(rs.getInt("id"));
                category.setName(rs.getString("name"));
                category.setSlug(rs.getString("slug"));
                return category;
            } else {
                throw new SQLException("unable to find your category");
            }
        } catch (SQLException e) {
            System.err.println(e.getMessage());
            throw new SQLException(e);
        }
    }

    /**
     * Get a category by its slug
     * @param slug category's slug
     * @return {CategoryBean}
     * @throws SQLException
     */
    public CategoryBean getCategoryBySlug(String slug) throws SQLException{
        try (
                Connection connection = DriverManager.getConnection(this.m_urlDB);
                PreparedStatement statement = connection.prepareStatement(SELECT_CATEGORY_FROM_SLUG);
        ) {
            statement.setString(1, slug);
            ResultSet rs = statement.executeQuery();
            if (rs.next()) {
                CategoryBean category = new CategoryBean();
                category.setId(rs.getInt("id"));
                category.setName(rs.getString("name"));
                category.setSlug(rs.getString("slug"));
                return category;
            } else {
                throw new SQLException("unable to find your category");
            }
        } catch (SQLException e) {
            System.err.println(e.getMessage());
            throw new SQLException(e);
        }
    }

    /**
     * Get all categories
     * @return {ArrayList<CategoryBean>}
     * @throws SQLException
     */
    public ArrayList<CategoryBean> getCategories() throws SQLException {
        try (
                Connection connection = DriverManager.getConnection(this.m_urlDB);
                PreparedStatement statement = connection.prepareStatement(SELECT_CATEGORIES);
        ) {
            ResultSet rs = statement.executeQuery();
            ArrayList<CategoryBean> categories = new ArrayList<>();
            while (rs.next()) {
                CategoryBean category = new CategoryBean();
                category.setId(rs.getInt("id"));
                category.setName(rs.getString("name"));
                category.setSlug(rs.getString("slug"));
                categories.add(category);
            }
            return categories;
        } catch (SQLException e) {
            System.err.println(e.getMessage());
            throw new SQLException(e);
        }
    }
}
