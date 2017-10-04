package com.jweb.servlet.controller;

import com.jweb.servlet.model.beans.AddressBean;
import com.jweb.servlet.model.beans.UserBean;
import com.jweb.servlet.utils.SendEmail;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;

/**
 * Created by ankirama on 27/12/15.
 */
public class Checkout extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        UserBean user = (UserBean)session.getAttribute("user");
        if (session.getAttribute("products") != null) {
            session.removeAttribute("products");
        }
        String content = "You bought for $" + request.getParameter("total") + ".\n";
        content += "You will receive your item to [" + request.getParameter("address") + "].\n";
        content += "You paid with your [" + request.getParameter("payment") + "] credit card.\nThank you.\n";
        if (SendEmail.sendMailValidation(user.getEmail(), "Thank you [" + user.getUsername() + "] for your purchase", content)) {
            System.out.println("email sent for purchase.");
        } else {
            System.err.println("Unable to send this email.");
        }
        response.sendRedirect("/home");
    }
}
