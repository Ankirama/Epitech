package com.jweb.servlet.controller;

import com.jweb.servlet.model.DBManager;
import com.jweb.servlet.model.ModelCategory;
import com.jweb.servlet.model.ModelNewsletter;
import com.jweb.servlet.model.ModelProduct;
import com.jweb.servlet.model.beans.CategoryBean;
import com.jweb.servlet.model.beans.ProductBean;
import com.jweb.servlet.utils.HelperMenu;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.SQLException;
import java.util.ArrayList;

/**
 * Created by ankirama on 26/12/15.
 */
public class Products extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HelperMenu.setMenu(request);
        String slug = request.getPathInfo() == null || request.getPathInfo().length() == 1 ? null : request.getPathInfo().substring(1);
        ArrayList<ProductBean> products = null;
        if (slug != null) {
            try {
                CategoryBean category = (CategoryBean) DBManager.executeQuery(new ModelCategory(), "getCategoryBySlug", slug);
                products = (ArrayList<ProductBean>)DBManager.executeQuery(new ModelProduct(), "getProductsByCategory", category.getId());
                request.setAttribute("title", category.getName());
            } catch (SQLException e) {
                System.err.println(e.getMessage());
                response.sendRedirect("/products");
            }
        } else {
            try {
                products = (ArrayList<ProductBean>) DBManager.executeQuery(new ModelProduct(), "getProducts", null);
                request.setAttribute("title", "Products");
            } catch (SQLException e) {
                System.err.println(e.getMessage());
                throw new ServletException();
            }
        }
        request.setAttribute("products", products);
        this.getServletContext().getRequestDispatcher("/WEB-INF/jsp/products.jsp").forward(request, response);
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        String message = null;

        if (request.getParameter("email") != null) {
            try {
                if ((boolean) DBManager.executeQuery(new ModelNewsletter(), "addEmail", request.getParameter("email"))) {
                    message = "You will now receive our newsletter.";
                } else {
                    message = "You have already subscribed to our newsletter.";
                }
                session.setAttribute("newsletter", true);
            } catch (SQLException e) {
                System.err.println(e.getMessage());
                session.setAttribute("newsletter", false);
            }
            response.sendRedirect("/products");
        }
    }
}
