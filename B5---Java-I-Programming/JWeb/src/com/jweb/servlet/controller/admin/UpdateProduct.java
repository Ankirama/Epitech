package com.jweb.servlet.controller.admin;

import com.jweb.servlet.controller.Product;
import com.jweb.servlet.model.DBManager;
import com.jweb.servlet.model.ModelCategory;
import com.jweb.servlet.model.ModelProduct;
import com.jweb.servlet.model.beans.CategoryBean;
import com.jweb.servlet.model.beans.ProductBean;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.HashMap;

/**
 * Created by ankirama on 27/12/15.
 */
public class UpdateProduct extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        if (Admin.isAuthorized(session)) {
            if (request.getPathInfo() == null || request.getPathInfo().length() < 1) {
                request.setAttribute("message", "You must specify a valid id to update your product.");
                request.getRequestDispatcher("/admin/products").forward(request, response);
            } else {
                try {
                    int id = Integer.parseInt(request.getPathInfo().substring(1));
                    ProductBean product = (ProductBean) DBManager.executeQuery(new ModelProduct(), "getProductById", id);
                    ArrayList<CategoryBean> categories = (ArrayList<CategoryBean>)DBManager.executeQuery(new ModelCategory(), "getCategories", null);
                    request.setAttribute("categories", categories);
                    request.setAttribute("product", product);
                    this.getServletContext().getRequestDispatcher("/WEB-INF/jsp/admin/updateProduct.jsp").forward(request, response);
                } catch (NumberFormatException | SQLException e) {
                    System.err.println(e.getMessage());
                    request.setAttribute("message", "You must specify a valid id.");
                }
            }
        } else {
            response.sendRedirect("/home");
        }
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        if (request.getParameter("name") != null && request.getParameter("categoryid") != null && request.getParameter("price") != null &&
                request.getParameter("description") != null && request.getParameter("illustration") != null && request.getParameter("productid") != null) {
            HashMap<String, String> values = new HashMap<>();
            values.put("name", request.getParameter("name"));
            values.put("description", request.getParameter("description"));
            values.put("price", request.getParameter("price"));
            values.put("categoryid", request.getParameter("categoryid"));
            values.put("illustration", request.getParameter("illustration"));
            values.put("id", request.getParameter("productid"));
            try {
                if ((boolean)DBManager.executeQuery(new ModelProduct(), "updateProductById", values)) {
                    System.out.println("Product updated.");
                } else {
                    System.out.println("Unable to update this product.");
                }
            } catch (SQLException e) {
                System.err.print("error: ");
                System.err.println(e.getMessage());
            }

        } else {
            System.err.println("You must fill all fields.");
        }
        response.sendRedirect("/admin/products");
    }
}
