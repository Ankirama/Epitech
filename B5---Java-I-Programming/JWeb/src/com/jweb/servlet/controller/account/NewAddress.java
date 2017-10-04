package com.jweb.servlet.controller.account;

import com.jweb.servlet.model.DBManager;
import com.jweb.servlet.model.ModelAddress;
import com.jweb.servlet.model.beans.AddressBean;
import com.jweb.servlet.model.beans.UserBean;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.HashMap;

/**
 * Created by ankirama on 15/12/15.
 */
public class NewAddress extends HttpServlet {
    private boolean checkParameters(HttpServletRequest request) {
        return checkParameter(request, "name") && checkParameter(request, "firstName") && checkParameter(request, "lastName") &&
                checkParameter(request, "address1") && checkParameter(request, "address2") && checkParameter(request, "country") &&
                checkParameter(request, "city");
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
            this.getServletContext().getRequestDispatcher("/WEB-INF/jsp/account/newAddress.jsp").forward(request, response);
        } else if (session.getAttribute("user") == null) {
            response.sendRedirect("/login");
        } else {
            response.sendRedirect("/home");
        }
    }

    /**
     * doPost allow to add a new address in our table
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
            HashMap<String, String> values = new HashMap<>();
            values.put("name", request.getParameter("name"));
            values.put("firstName", request.getParameter("firstName"));
            values.put("lastName", request.getParameter("lastName"));
            values.put("address1", request.getParameter("address1"));
            values.put("address2", request.getParameter("address2"));
            values.put("country", request.getParameter("country"));
            values.put("city", request.getParameter("city"));
            int tmp = ((UserBean) session.getAttribute("user")).getId();
            values.put("userid", Integer.toString(tmp));
            try {
                if (DBManager.executeQuery(new ModelAddress(), "createAddress", values) != null) {
                    message = "Address created.";
                } else {
                    message = "Unable to add your address.";
                }
            } catch (SQLException e) {
                System.err.println(e.getMessage());
                message = "Unable to add your address.";
            }
        } else {
            message = "You must specify all values.";
        }
        request.setAttribute("message", message);
        request.getRequestDispatcher("/WEB-INF/jsp/account/newAddress.jsp").forward(request, response);
    }
}
