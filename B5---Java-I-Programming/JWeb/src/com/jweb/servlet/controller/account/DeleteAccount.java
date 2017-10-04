package com.jweb.servlet.controller.account;

import com.jweb.servlet.model.DBManager;
import com.jweb.servlet.model.ModelAddress;
import com.jweb.servlet.model.ModelPayment;
import com.jweb.servlet.model.ModelUser;
import com.jweb.servlet.model.beans.UserBean;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.sql.SQLException;

/**
 * Created by ankirama on 15/12/15.
 */
public class DeleteAccount extends HttpServlet {
    private boolean deleteAccount(String username) {
        try {
            int userid = (int)DBManager.executeQuery(new ModelUser(), "getUseridFromUsername", username);
            if ((boolean) DBManager.executeQuery(new ModelUser(), "delUser", username)) {
                return true;
            } else {
                System.err.println("unable to find this account.");
            }
        } catch (SQLException e) {
            System.err.println(e.getMessage());
        }
        return false;
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        if (request.getPathInfo() != null && request.getPathInfo().length() > 1 && session.getAttribute("user") != null) {
            String token = request.getPathInfo().substring(1);
            UserBean user = (UserBean)session.getAttribute("user");
            if (!user.getAdmin() && token.equals(user.getUsername())) {
                session.removeAttribute("user");
                session.removeAttribute("newsletterUser");
                session.setAttribute("newsletter", false);
                this.deleteAccount(token);
                response.sendRedirect("/home");
            } else if (user.getAdmin()) {
                if (this.deleteAccount(token)) {
                    request.setAttribute("message", "This account has been removed.");
                } else {
                    request.setAttribute("message", "Unable to remove this account.");
                }
                request.getRequestDispatcher("/admin/accounts").forward(request, response);
            }
        } else {
            response.sendRedirect("/home");
        }
    }
}
