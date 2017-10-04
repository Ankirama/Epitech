package com.jweb.servlet.controller.admin;

import com.jweb.servlet.model.DBManager;
import com.jweb.servlet.model.ModelUser;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.sql.SQLException;

/**
 * Created by ankirama on 27/12/15.
 */
public class EnableAccount extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        if (Admin.isAuthorized(session)) {
            if (request.getPathInfo() != null && request.getPathInfo().length() > 1) {
                try {
                    int id = Integer.parseInt(request.getPathInfo().substring(1));
                    if ((boolean) DBManager.executeQuery(new ModelUser(), "enableUserById", id)) {
                        request.setAttribute("message", "Your account has been enabled.");
                    } else {
                        request.setAttribute("message", "Unable to enable this account.");
                    }
                } catch (NumberFormatException | SQLException e) {
                    System.err.println(e.getMessage());
                    request.setAttribute("message", "You must specify a valid id");
                }
            } else {
                request.setAttribute("message", "You must specify an id.");
            }
            request.getRequestDispatcher("/admin/accounts").forward(request, response);
        } else {
            response.sendRedirect("/home");
        }
    }
}
