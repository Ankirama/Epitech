package com.jweb.servlet.controller.account;

import com.jweb.servlet.model.DBManager;
import com.jweb.servlet.model.ModelPayment;
import com.jweb.servlet.model.beans.PaymentBean;
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
 * Created by ankirama on 15/12/15.
 */
public class Payments extends HttpServlet {
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

        UserBean user = (UserBean)session.getAttribute("user");

        if (user != null && !user.getAdmin()) {
            try {
                ArrayList<PaymentBean> payments = (ArrayList<PaymentBean>) DBManager.executeQuery(new ModelPayment(), "getPayments", user.getId());
                request.setAttribute("payments", payments);
            } catch(SQLException e) {
                System.err.println(e.getMessage());
            }
            this.getServletContext().getRequestDispatcher("/WEB-INF/jsp/account/viewPayments.jsp").forward(request, response);
        } else if (user == null) {
            response.sendRedirect("/login");
        } else {
            response.sendRedirect("/home");
        }
    }
}
