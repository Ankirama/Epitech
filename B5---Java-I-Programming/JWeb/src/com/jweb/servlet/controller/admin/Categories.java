package com.jweb.servlet.controller.admin;

import com.jweb.servlet.model.DBManager;
import com.jweb.servlet.model.ModelCategory;
import com.jweb.servlet.model.beans.CategoryBean;

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
public class Categories extends HttpServlet {

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        String message = null;

        if (Admin.isAuthorized(session)) {
            try {
                ArrayList<CategoryBean> categories = (ArrayList<CategoryBean>) DBManager.executeQuery(new ModelCategory(), "getCategories", null);
                request.setAttribute("categories", categories);
                this.getServletContext().getRequestDispatcher("/WEB-INF/jsp/admin/categories.jsp").forward(request, response);
            } catch (SQLException e) {
                System.err.println(e.getMessage());
                request.setAttribute("message", "Unable to view categories. Check your logs.");
                this.getServletContext().getRequestDispatcher("/admin").forward(request, response);
            }
        } else {
            response.sendRedirect("/home");
        }
    }
}
