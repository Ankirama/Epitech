package com.jweb.servlet.model;

import com.jweb.servlet.model.beans.ProductBean;

import javax.servlet.annotation.MultipartConfig;
import java.sql.*;
import java.util.ArrayList;
import java.util.HashMap;

/**
 * Created by ankirama on 25/12/15.
 */
public class ModelProduct extends AModele {
    private static final String INSERT_PRODUCT = "INSERT INTO product (name, price, description, illustration, categoryid) VALUES(?, ?, ?, ?, ?);";
    private static final String DELETE_PRODUCT_FROM_ID = "DELETE FROM product WHERE id=?;";
    private static final String DELETE_PRODUCTS_FROM_CATEGORY = "DELETE FROM product WHERE categoryid=?;";
    private static final String DELETE_PRODUCTS = "DELETE FROM product;";
    private static final String UPDATE_PRODUCT_FROM_ID = "UPDATE product SET name=?, price=?, description=?, illustration=?, categoryid=? WHERE id=?;";
    private static final String UPDATE_CATEGORY_PRODUCT_FROM_CATEGORY = "UPDATE product SET categoryid=? WHERE categoryid=?";
    private static final String UPDATE_CATEGORY_PRODUCT_TO_NULL_FROM_CATEGORY = "UPDATE product SET categoryid=NULL WHERE categoryid=?";
    private static final String UPDATE_PRODUCT_DISABLE_FROM_ID = "UPDATE product SET active=0 WHERE id=?;";
    private static final String UPDATE_PRODUCT_ENABLE_FROM_ID = "UPDATE product SET active=1 WHERE id=?;";
    private static final String SELECT_PRODUCT_FROM_ID = "SELECT * FROM product WHERE id=?;";
    private static final String SELECT_PRODUCTS_FROM_CATEGORY = "SELECT * FROM product WHERE categoryid=?;";
    private static final String SELECT_PRODUCTS = "SELECT * FROM product;";

    public ModelProduct() {super();}

    /**
     * Create a new product and return true
     * @param map all info to create our product
     * @return {boolean}
     */
    public boolean createProduct(HashMap<String, String> map) {
        try (
                Connection connection = DriverManager.getConnection(this.m_urlDB);
                PreparedStatement statement = connection.prepareStatement(INSERT_PRODUCT);
        ) {
            statement.setString(1, map.get("name"));
            statement.setFloat(2, Float.parseFloat(map.get("price")));
            statement.setString(3, map.get("description"));
            statement.setString(4, map.get("illustration"));
            statement.setInt(5, Integer.parseInt(map.get("categoryid")));
            statement.executeUpdate();
            return true;
        } catch (SQLException e) {
            System.err.println(e.getMessage());
            return false;
        }
    }

    /**
     * Disable a product by its id
     * @param id product's id
     * @return {boolean}
     */
    public boolean disableProductById(Integer id) {
        try (
                Connection connection = DriverManager.getConnection(this.m_urlDB);
                PreparedStatement statement = connection.prepareStatement(UPDATE_PRODUCT_DISABLE_FROM_ID);
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
     * Enable a product by its id
     * @param id product's id
     * @return {boolean}
     */
    public boolean enableProductById(Integer id) {
        try (
                Connection connection = DriverManager.getConnection(this.m_urlDB);
                PreparedStatement statement = connection.prepareStatement(UPDATE_PRODUCT_ENABLE_FROM_ID);
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
     * Delete a product by its id
     * @param id product's id
     * @return {boolean}
     */
    public boolean delProductById(Integer id) {
        try (
                Connection connection = DriverManager.getConnection(this.m_urlDB);
                PreparedStatement statement = connection.prepareStatement(DELETE_PRODUCT_FROM_ID);
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
     * Delete a product by its categoryid
     * @param categoryid product's categoryid
     * @return {boolean}
     */
    public boolean delProductByCategory(Integer categoryid) {
        try (
                Connection connection = DriverManager.getConnection(this.m_urlDB);
                PreparedStatement statement = connection.prepareStatement(DELETE_PRODUCTS_FROM_CATEGORY);
        ) {
            statement.setInt(1, categoryid);
            statement.executeUpdate();
            return true;
        } catch (SQLException e) {
            System.err.println(e.getMessage());
            return false;
        }
    }

    /**
     * Delete all products
     * @return {boolean}
     */
    public boolean delProducts() {
        try (
                Connection connection = DriverManager.getConnection(this.m_urlDB);
                PreparedStatement statement = connection.prepareStatement(DELETE_PRODUCTS);
        ) {
            statement.executeUpdate();
            return true;
        } catch (SQLException e) {
            System.err.println(e.getMessage());
            return false;
        }
    }

    /**
     * Update a product and find it by its id
     * @param map contains info to update and product's id
     * @return {boolean}
     */
    public boolean updateProductById(HashMap<String, String>map) {
        try (
                Connection connection = DriverManager.getConnection(this.m_urlDB);
                PreparedStatement statement = connection.prepareStatement(UPDATE_PRODUCT_FROM_ID);
        ) {
            statement.setString(1, map.get("name"));
            statement.setFloat(2, Float.parseFloat(map.get("price")));
            statement.setString(3, map.get("description"));
            statement.setString(4, map.get("illustration"));
            statement.setInt(5, Integer.parseInt(map.get("categoryid")));
            statement.setInt(6, Integer.parseInt(map.get("id")));
            statement.executeUpdate();
            return true;
        } catch (SQLException e) {
            System.err.println(e.getMessage());
            return false;
        }
    }

    /**
     * Update products and find it by its categoryid
     * @param map Contains oldid and newid
     * @return {boolean}
     */
    public boolean updateProductByCategoryId(HashMap<String, Integer>map) {
        try (
                Connection connection = DriverManager.getConnection(this.m_urlDB);
                PreparedStatement statement = connection.prepareStatement(UPDATE_CATEGORY_PRODUCT_FROM_CATEGORY);
        ) {
            statement.setInt(1, map.get("oldid"));
            statement.setInt(2, map.get("newid"));
            statement.executeUpdate();
            return true;
        } catch (SQLException e) {
            System.err.println(e.getMessage());
            return false;
        }
    }

    /**
     * Update products and find it by its categoryid
     * @param categoryid products' categoryid
     * @return {boolean}
     */
    public boolean updateProductAndRemoveCategoryid(Integer categoryid) {
        try (
                Connection connection = DriverManager.getConnection(this.m_urlDB);
                PreparedStatement statement = connection.prepareStatement(UPDATE_CATEGORY_PRODUCT_TO_NULL_FROM_CATEGORY);
        ) {
            statement.setInt(1, categoryid);
            statement.executeUpdate();
            return true;
        } catch (SQLException e) {
            System.err.println(e.getMessage());
            return false;
        }
    }

    /**
     * Get a product by its id
     * @param id product's id
     * @return {ProductBean}
     * @throws SQLException
     */
    public ProductBean getProductById(Integer id) throws SQLException {
        try (
                Connection connection = DriverManager.getConnection(this.m_urlDB);
                PreparedStatement statement = connection.prepareStatement(SELECT_PRODUCT_FROM_ID);
        ) {
            statement.setInt(1, id);
            ResultSet rs = statement.executeQuery();
            if (rs.next()) {
                ProductBean product = new ProductBean();
                product.setId(rs.getInt("id"));
                product.setDescription(rs.getString("description"));
                product.setName(rs.getString("name"));
                product.setPrice(rs.getFloat("price"));
                product.setIllustration(rs.getString("illustration"));
                product.setCategoryid(rs.getInt("categoryid"));
                product.setActive(rs.getInt("active") != 0);
                return product;
            }
            throw new SQLException("Unable to find our product.");
        } catch (SQLException e) {
            System.err.println(e.getMessage());
            throw new SQLException(e);
        }
    }

    /**
     * Get products by a categoryid
     * @param categoryid
     * @return {ArrayList<ProductBean>}
     * @throws SQLException
     */
    public ArrayList<ProductBean> getProductsByCategory(Integer categoryid) throws SQLException {
        try (
                Connection connection = DriverManager.getConnection(this.m_urlDB);
                PreparedStatement statement = connection.prepareStatement(SELECT_PRODUCTS_FROM_CATEGORY);
        ) {
            statement.setInt(1, categoryid);
            ResultSet rs = statement.executeQuery();
            ArrayList<ProductBean> products = new ArrayList<>();
            while (rs.next()) {
                ProductBean product = new ProductBean();
                product.setId(rs.getInt("id"));
                product.setDescription(rs.getString("description"));
                product.setName(rs.getString("name"));
                product.setPrice(rs.getFloat("price"));
                product.setCategoryid(rs.getInt("categoryid"));
                product.setIllustration(rs.getString("illustration"));
                product.setActive(rs.getInt("active") != 0);
                products.add(product);
            }
            return products;
        } catch (SQLException e) {
            System.err.println(e.getMessage());
            throw new SQLException(e);
        }
    }

    /**
     * get all products
     * @return {ArrayList<ProductBean>}
     * @throws SQLException
     */
    public ArrayList<ProductBean> getProducts() throws SQLException {
        try (
                Connection connection = DriverManager.getConnection(this.m_urlDB);
                PreparedStatement statement = connection.prepareStatement(SELECT_PRODUCTS);
        ) {
            ResultSet rs = statement.executeQuery();
            ArrayList<ProductBean> products = new ArrayList<>();
            while (rs.next()) {
                ProductBean product = new ProductBean();
                product.setId(rs.getInt("id"));
                product.setDescription(rs.getString("description"));
                product.setName(rs.getString("name"));
                product.setPrice(rs.getFloat("price"));
                product.setIllustration(rs.getString("illustration"));
                product.setCategoryid(rs.getInt("categoryid"));
                product.setActive(rs.getInt("active") != 0);
                products.add(product);
            }
            return products;
        } catch (SQLException e) {
            System.err.println(e.getMessage());
            throw new SQLException(e);
        }
    }
}
