package com.jweb.servlet.controller;

import com.jweb.servlet.model.DBManager;
import com.jweb.servlet.model.ModelOpinion;
import com.jweb.servlet.model.ModelUser;
import com.jweb.servlet.utils.SendEmail;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.sql.SQLException;
import java.util.HashMap;

/**
 * Created by ankirama on 26/12/15.
 */
public class AddOpinion extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        if (request.getParameter("productid") == null) {
            response.sendRedirect("/home");
        } else {
            String path = "/product/" + request.getParameter("productid");
            if (request.getParameter("author") != null && request.getParameter("content") != null) {
                HashMap<String, String> values = new HashMap<>();
                values.put("productid", request.getParameter("productid"));
                values.put("note", "5");
                values.put("comment", request.getParameter("content"));
                values.put("author", request.getParameter("author"));
                try {
                    if ((boolean) DBManager.executeQuery(new ModelOpinion(), "createOpinion", values)) {
                        if (SendEmail.sendMailViaContact("New review on product id [" + request.getParameter("productid") + "]", "[" + request.getParameter("author") + "] posted a new review on your website.")) {
                            System.out.println("Email sent");
                        } else {
                            System.err.println("unable to send this email.");
                        }
                        System.out.println("Reviews added successfully.");
                    } else {
                        System.err.println("Unable to add your reviews.");
                    }
                } catch (SQLException e) {
                    System.err.print("Error: ");
                    System.err.println(e.getMessage());
                }
            } else {
                System.err.println("You must specify all values");
            }
            response.sendRedirect(path);
        }
    }
}
