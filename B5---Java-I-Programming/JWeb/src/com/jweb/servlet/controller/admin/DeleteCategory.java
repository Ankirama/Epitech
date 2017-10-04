package com.jweb.servlet.controller.admin;

import com.jweb.servlet.model.DBManager;
import com.jweb.servlet.model.ModelCategory;
import com.jweb.servlet.model.ModelProduct;

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
public class DeleteCategory extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        if (Admin.isAuthorized(session)) {
            if (request.getPathInfo() != null && request.getPathInfo().length() > 1) {
                try {
                    int id = Integer.parseInt(request.getPathInfo().substring(1));
                    if ((boolean) DBManager.executeQuery(new ModelProduct(), "updateProductAndRemoveCategoryid", id) &&
                            (boolean) DBManager.executeQuery(new ModelCategory(), "deleteCategoryById", id)) {
                        request.setAttribute("message", "Your category has been removed and products updated.");
                    } else {
                        request.setAttribute("message", "Unable to remove this category.");
                    }
                } catch (NumberFormatException | SQLException e) {
                    System.err.println(e.getMessage());
                    request.setAttribute("message", "You must specify a valid id");
                }
            } else {
                request.setAttribute("message", "You must specify an id.");
            }
            request.getRequestDispatcher("/admin/categories").forward(request, response);
        } else {
            response.sendRedirect("/home");
        }
    }
}
