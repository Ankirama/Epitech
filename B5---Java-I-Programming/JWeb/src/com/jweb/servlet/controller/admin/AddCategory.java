package com.jweb.servlet.controller.admin;

import com.jweb.servlet.model.DBManager;
import com.jweb.servlet.model.ModelCategory;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.sql.SQLException;

/**
 * Created by ankirama on 26/12/15.
 */
public class AddCategory  extends HttpServlet {

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        if (Admin.isAuthorized(session)) {
            this.getServletContext().getRequestDispatcher("/WEB-INF/jsp/admin/addCategory.jsp").forward(request, response);
        } else {
            response.sendRedirect("/home");
        }
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String message = null;
        if (request.getParameter("category") != null) {
            try {
                if ((boolean) DBManager.executeQuery(new ModelCategory(), "createCategory", request.getParameter("category"))) {
                    message = "You category is now available.";
                } else {
                    message = "Unable to add the category.";
                }
            } catch (SQLException e) {
                System.err.println(e.getMessage());
                message = "Unable to add the category.";
            }
        } else {
            message = "You must fill the field.";
        }
        request.setAttribute("message", message);
        request.getRequestDispatcher("/WEB-INF/jsp/admin/addCategory.jsp").forward(request, response);
    }
}
