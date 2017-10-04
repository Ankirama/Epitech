package com.jweb.servlet.controller;

import com.jweb.servlet.model.DBManager;
import com.jweb.servlet.model.beans.ProductBean;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.io.InterruptedIOException;
import java.sql.SQLException;
import java.util.HashMap;

/**
 * Created by ankirama on 27/12/15.
 */
public class AddToCart extends HttpServlet{
    //get -> add 1 quantity
    //post -> add X quantity

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        if (request.getPathInfo() != null && request.getPathInfo().length() > 1) {
            try {
                int id = Integer.parseInt(request.getPathInfo().substring(1));
                HashMap<Integer, Integer> products = session.getAttribute("products") != null ? (HashMap<Integer, Integer>)session.getAttribute("products") : new HashMap<Integer, Integer>();
                session.removeAttribute("products");
                if (products.get(id) != null) {
                    products.put(id, products.get(id) + 1);
                } else {
                    products.put(id, 1);
                }
                session.setAttribute("products", products);
            } catch (NumberFormatException e) {
                System.err.println(e.getMessage());
            }
        }
        response.sendRedirect("/home");
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        if (request.getParameter("quantity") != null && request.getParameter("productid") != null) {
            try {
                int id = Integer.parseInt(request.getParameter("productid"));
                HashMap<Integer, Integer> products = session.getAttribute("products") != null ? (HashMap<Integer, Integer>)session.getAttribute("products") : new HashMap<Integer, Integer>();
                session.removeAttribute("products");
                if (products.get(id) != null) {
                    products.put(id, products.get(id) + Integer.parseInt(request.getParameter("quantity")));
                } else {
                    products.put(id, Integer.parseInt(request.getParameter("quantity")));
                }
                session.setAttribute("products", products);
                System.out.println("Cart updated.");

            } catch (NumberFormatException e) {
                System.err.println(e.getMessage());
            }
            response.sendRedirect("/product/" + request.getParameter("productid"));
        } else {
            System.err.println("Unable to fin all fields.");
            response.sendRedirect("/home");
        }
    }
}
