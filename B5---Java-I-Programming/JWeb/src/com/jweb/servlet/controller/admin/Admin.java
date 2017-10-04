package com.jweb.servlet.controller.admin;

import com.jweb.servlet.model.beans.UserBean;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;

/**
 * Created by ankirama on 26/12/15.
 */
public class Admin extends HttpServlet {

    public static boolean isAuthorized(HttpSession session) {
        if (session.getAttribute("user") != null && ((UserBean) session.getAttribute("user")).getAdmin()) return true;
        else return false;
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        if (isAuthorized(session)) {
            this.getServletContext().getRequestDispatcher("/WEB-INF/jsp/admin/admin.jsp").forward(request, response);
        } else {
            response.sendRedirect("/home");
        }
    }
}
