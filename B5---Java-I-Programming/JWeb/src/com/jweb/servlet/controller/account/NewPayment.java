package com.jweb.servlet.controller.account;

import com.jweb.servlet.model.DBManager;
import com.jweb.servlet.model.ModelPayment;
import com.jweb.servlet.model.beans.UserBean;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.sql.SQLException;
import java.util.HashMap;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Created by ankirama on 15/12/15.
 */
public class NewPayment extends HttpServlet {
    private boolean checkParameters(HttpServletRequest request) {
        return checkParameter(request, "name") && checkParameter(request, "firstName") && checkParameter(request, "lastName") &&
                checkParameter(request, "cardNumbers");
    }

    private boolean checkParameter(HttpServletRequest request, String param) {
        return (request.getParameter(param) != null);
    }

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
            this.getServletContext().getRequestDispatcher("/WEB-INF/jsp/account/newPayment.jsp").forward(request, response);
        } else if (session.getAttribute("user") == null) {
            response.sendRedirect("/login");
        } else {
            response.sendRedirect("/home");
        }
    }

    /**
     * Check if our card numbers is valid (size + only numbers / space)
     * @param cardNumbers our card numbers string we will check
     * @return {boolean}
     */
    private boolean checkCardNumbers(String cardNumbers) {
        String tmp = cardNumbers.replace(" ", "");
        Pattern p = Pattern.compile("^[0-9]+$");
        Matcher m = p.matcher(tmp);
        return (m.matches() && tmp.length() == 16);
    }

    /**
     * doPost allow to add a new payment in our table
     * It could be good to check if these params exists
     * @param request
     * @param response
     * @throws ServletException
     * @throws IOException
     */
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        String message = null;
        if (this.checkParameters(request)) {
            if (checkCardNumbers(request.getParameter("cardNumbers"))) {
                HashMap<String, String> values = new HashMap<>();
                values.put("name", request.getParameter("name"));
                values.put("cardNumbers", request.getParameter("cardNumbers"));
                values.put("firstName", request.getParameter("firstName"));
                values.put("lastName", request.getParameter("lastName"));
                int tmp = ((UserBean) session.getAttribute("user")).getId();
                values.put("userid", Integer.toString(tmp));
                try {
                    if (DBManager.executeQuery(new ModelPayment(), "createPayment", values) != null) {
                        message = "Payment created.";
                    } else {
                        message = "Unable to add your payment.";
                    }
                } catch (SQLException e) {
                    System.err.println(e.getMessage());
                    message = "Unable to add your payment.";
                }
            } else {
                message = "You must specify a valid card numbers like 0123 4567 8901 2345";
            }
        } else {
            message = "You must specify all values.";
        }
        request.setAttribute("message", message);
        request.getRequestDispatcher("/WEB-INF/jsp/account/newPayment.jsp").forward(request, response);
    }
}
