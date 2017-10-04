package com.jweb.servlet.controller.account;

import com.jweb.servlet.model.DBManager;
import com.jweb.servlet.model.ModelNewsletter;
import com.jweb.servlet.model.ModelUser;
import com.jweb.servlet.model.beans.UserBean;
import com.jweb.servlet.utils.SendEmail;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.SQLException;
import java.util.HashMap;

/**
 * Created by ankirama on 14/12/15.
 */
public class Account extends HttpServlet {
    /**
     * doGet to display our page if we are logged and a basic user (not admin)
     * else redirect
     * @param request
     * @param response
     * @throws ServletException
     * @throws IOException
     */
    public void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        if (session.getAttribute("user") != null && !((UserBean) session.getAttribute("user")).getAdmin()) {
            this.getServletContext().getRequestDispatcher("/WEB-INF/jsp/account/account.jsp").forward(request, response);
        } else if (session.getAttribute("user") == null) {
          response.sendRedirect("/login");
        } else {
            response.sendRedirect("/home");
        }
    }

    /**
     * doPost to update user basic informations
     * @param request
     * @param response
     * @throws ServletException
     * @throws IOException
     */
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        PrintWriter out = response.getWriter();
        HttpSession session = request.getSession();
        String message = null;

        if (request.getParameter("firstName") != null &&
                request.getParameter("lastName") != null &&
                request.getParameter("username") != null) {
            HashMap<String, String> values = new HashMap<>();
            values.put("firstName", request.getParameter("firstName"));
            values.put("lastName", request.getParameter("lastName"));
            values.put("username", request.getParameter("username"));
            String actionNewsletter = request.getParameter("newsletter") == null ? "delEmail" : "addEmail";
            session.setAttribute("newsletterUser", request.getParameter("newsletter") != null);
            try {
                DBManager.executeQuery(new ModelNewsletter(), actionNewsletter, ((UserBean)session.getAttribute("user")).getEmail());
            } catch (SQLException e) {}
            try {
                if ((boolean) DBManager.executeQuery(new ModelUser(), "updateUser", values)) {
                    UserBean user = (UserBean)session.getAttribute("user");
                    user.setFirstName(request.getParameter("firstName"));
                    user.setLastName(request.getParameter("lastName"));
                    session.setAttribute("user", user);
                    message = "Account updated.";
                } else {
                    message = "Unable to update your account.";
                }
            } catch (SQLException e) {
                System.err.println(e.getMessage());
                message = "Unable to update your account.";
            }
            request.setAttribute("message", message);
            request.getRequestDispatcher("/WEB-INF/jsp/account/account.jsp").forward(request, response);
        } else {
            response.sendRedirect("/account");
        }
    }
}
