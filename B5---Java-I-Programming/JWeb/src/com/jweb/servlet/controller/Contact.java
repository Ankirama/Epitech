package com.jweb.servlet.controller;

import com.jweb.servlet.utils.SendEmail;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.io.PrintWriter;

/**
 * Created by ankirama on 14/12/15.
 */
public class Contact extends HttpServlet {
    public void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.getServletContext().getRequestDispatcher("/WEB-INF/jsp/contact.jsp").forward(request, response);
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        PrintWriter out = response.getWriter();
        String message = null;

        if (request.getParameter("email") != null && request.getParameter("subject") != null &&
                request.getParameter("message") != null) {
            if (SendEmail.sendMailViaContact(request.getParameter("email"),
                    request.getParameter("subject"),
                    request.getParameter("message"))) {
                message = "Message sent to our staff.";
            } else {
                message = "Unable to send your message.";
            }
        } else {
            message = "Unable to send your message.";
        }
        request.setAttribute("message", message);
        request.getRequestDispatcher("/WEB-INF/jsp/contact.jsp").forward(request, response);
    }
}
