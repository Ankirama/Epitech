package com.jweb.servlet.controller.admin;

import com.jweb.servlet.model.DBManager;
import com.jweb.servlet.model.ModelUser;
import com.jweb.servlet.model.beans.UserBean;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.sql.SQLException;
import java.util.ArrayList;

/**
 * Created by ankirama on 26/12/15.
 */
public class Accounts extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        if (Admin.isAuthorized(session)) {
            try {
                ArrayList<UserBean> users = (ArrayList<UserBean>) DBManager.executeQuery(new ModelUser(), "getUsers", null);
                request.setAttribute("users", users);
                this.getServletContext().getRequestDispatcher("/WEB-INF/jsp/admin/accounts.jsp").forward(request, response);
            } catch (SQLException e) {
                System.err.println(e.getMessage());
                request.setAttribute("message", "Unable to view accounts. Check logs.");
            }

        } else {
            response.sendRedirect("/home");
        }
    }
}
