package com.jweb.servlet.controller;

import com.jweb.servlet.model.DBManager;
import com.jweb.servlet.model.ModelAddress;
import com.jweb.servlet.model.ModelPayment;
import com.jweb.servlet.model.ModelProduct;
import com.jweb.servlet.model.beans.AddressBean;
import com.jweb.servlet.model.beans.PaymentBean;
import com.jweb.servlet.model.beans.ProductBean;
import com.jweb.servlet.model.beans.UserBean;
import com.jweb.servlet.utils.ProductCart;
import com.sun.tools.internal.xjc.reader.xmlschema.bindinfo.BIConversion;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

/**
 * Created by ankirama on 27/12/15.
 */
public class Cart extends HttpServlet{
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        UserBean user = null;
        if (session.getAttribute("user") != null) {
            user = (UserBean) session.getAttribute("user");
        } else {
            request.setAttribute("message", "You must be logged to go on your cart.");
            request.getRequestDispatcher("/home").forward(request, response);
            return;
        }
        if (session.getAttribute("products") != null) {
            ArrayList<ProductCart> productCarts = new ArrayList<>();
            HashMap<Integer, Integer> productsQuantity = (HashMap<Integer, Integer>)session.getAttribute("products");
            try {
                float total = 0;
                for (Map.Entry<Integer, Integer> entry : productsQuantity.entrySet()) {
                    ProductBean product = (ProductBean)DBManager.executeQuery(new ModelProduct(), "getProductById", entry.getKey());
                    ProductCart tmp = new ProductCart();
                    tmp.setId(entry.getKey());
                    tmp.setName(product.getName());
                    tmp.setPrice(product.getPrice());
                    tmp.setQuantity(entry.getValue());
                    tmp.setTotal(entry.getValue() * product.getPrice());
                    productCarts.add(tmp);
                    total += tmp.getTotal();
                }
                ArrayList<AddressBean> addresses = (ArrayList<AddressBean>)DBManager.executeQuery(new ModelAddress(), "getAddresses", user.getId());
                ArrayList<PaymentBean> payments = (ArrayList<PaymentBean>)DBManager.executeQuery(new ModelPayment(), "getPayments", user.getId());
                request.setAttribute("products", productCarts);
                request.setAttribute("addresses", addresses);
                request.setAttribute("payments", payments);
                request.setAttribute("totalPrice", total);
                request.getRequestDispatcher("/WEB-INF/jsp/cart.jsp").forward(request, response);
            } catch (SQLException e) {
                System.err.println(e.getMessage());
                request.setAttribute("message", "Unable to display products in the cart.");
                request.getRequestDispatcher("/home").forward(request, response);
            }
        } else {
            request.setAttribute("message", "Your cart is empty");
            request.getRequestDispatcher("/home").forward(request, response);
        }
    }
}
