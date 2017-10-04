package com.jweb.servlet.controller;

import com.jweb.servlet.model.DBManager;
import com.jweb.servlet.model.ModelOpinion;
import com.jweb.servlet.model.ModelProduct;
import com.jweb.servlet.model.beans.OpinionBean;
import com.jweb.servlet.model.beans.ProductBean;
import com.jweb.servlet.utils.HelperMenu;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.sql.SQLException;
import java.util.ArrayList;

/**
 * Created by ankirama on 26/12/15.
 */
public class Product extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        int id;

        HelperMenu.setMenu(request);
        if (request.getPathInfo() != null && request.getPathInfo().length() > 1) {
            try {
                id = Integer.parseInt(request.getPathInfo().substring(1));
                try {
                    ProductBean product = (ProductBean) DBManager.executeQuery(new ModelProduct(), "getProductById", id);
                    if (product.getActive()) {
                        ArrayList<OpinionBean> opinions = (ArrayList<OpinionBean>) DBManager.executeQuery(new ModelOpinion(), "getOpinionsByProduct", product.getId());
                        request.setAttribute("product", product);
                        request.setAttribute("opinions", opinions);
                        this.getServletContext().getRequestDispatcher("/WEB-INF/jsp/product.jsp").forward(request, response);
                    } else {
                        request.setAttribute("message", "Your product is no longer available.");
                        request.getRequestDispatcher("/products");
                    }
                } catch (SQLException e) {
                    System.err.println(e.getMessage());
                    response.sendRedirect("/products");
                }
            } catch (NumberFormatException e) {
                System.err.println(e.getMessage());
                response.sendRedirect("/products");
            }
        } else {
            response.sendRedirect("/products");
        }
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }
}
