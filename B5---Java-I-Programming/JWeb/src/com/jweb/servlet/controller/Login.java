package com.jweb.servlet.controller;

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
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.SQLIntegrityConstraintViolationException;
import java.util.Collection;
import java.util.Collections;
import java.util.Enumeration;
import java.util.HashMap;

/**
 * Created by ankirama on 12/1/2015.
 */
public class Login extends HttpServlet {
    private String m_message = null;
    /**
     * doGet to display our page if we are not logged
     * @param request
     * @param response
     * @throws ServletException
     * @throws IOException
     */
    public void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        if (session.getAttribute("user") == null)
            this.getServletContext().getRequestDispatcher("/WEB-INF/jsp/login.jsp").forward(request, response);
        else {
            response.sendRedirect("/home");
        }
    }

    /**
     * doPost to signup a new user
     * If any error alert message + redirection to /home or /login
     * @param request
     * @param session
     * @param out
     */
    public boolean doPostSignup(HttpServletRequest request, HttpSession session, PrintWriter out) {
        if (request.getParameter("signupUser") != null &&
                request.getParameter("signupPassword") != null &&
                request.getParameter("signupEmail") != null) {
            HashMap<String, String>values = new HashMap<>();
            values.put("username", request.getParameter("signupUser"));
            values.put("password", request.getParameter("signupPassword"));
            values.put("email", request.getParameter("signupEmail"));
            try {
                UserBean user = (UserBean)DBManager.executeQuery(new ModelUser(), "createUser", values);
                if (user != null) {
                    session.setAttribute("user", user);
                    SendEmail.sendMailValidation(user.getEmail(), "Account created.", "Thank you " + user.getUsername() + " for your registration on our website E-shopper.");
                    return true;
                } else {
                    System.out.println("createUser returned false");
                    m_message = "unable to create your account.";
                }
            } catch (SQLIntegrityConstraintViolationException e) {
                m_message = "your username or email is already used. You must specify another one.";
            } catch (SQLException e) {
                System.err.println(e.getMessage());
                m_message = "unable to create your account.";
            }
        } else {
            m_message = "You must specify a username, password and email to signup.";
        }
        return false;
    }

    /**
     * doPost to signin a user
     * If any error alert message + redirection to /home or /login
     * @param request
     * @param session
     * @param out
     */
    public boolean doPostSignin(HttpServletRequest request, HttpSession session, PrintWriter out){
        if (request.getParameter("signinUsername") != null && request.getParameter("signinPassword") != null) {
            HashMap<String, String>values = new HashMap<>();
            values.put("password", request.getParameter("signinPassword"));
            values.put("username", request.getParameter("signinUsername"));
            try {
                UserBean user = (UserBean)DBManager.executeQuery(new ModelUser(), "getUser", values);
                if (user != null && user.getActive()) {
                    session.setAttribute("user", user);
                    session.setAttribute("newsletterUser", (boolean)DBManager.executeQuery(new ModelNewsletter(), "selectEmail", user.getEmail()));
                    return true;
                } else {
                    m_message = "unable to find your account.";
                }
            } catch (SQLException e) {
                System.err.println(e.getMessage());
                m_message = "unable to signin your account.";
            }
        } else {
            m_message = "You must specify your email and your password to signin.";
        }
        return false;
    }

    /**
     * doPost to handle 2 post forms: signup and signin
     * @param request
     * @param response
     * @throws ServletException
     * @throws IOException
     */
    public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        PrintWriter out = response.getWriter();

        if (request.getParameter("signup") != null) {
            if (doPostSignup(request, session, out)) {
                response.sendRedirect("/home");
            } else {
                request.setAttribute("message", m_message);
                request.getRequestDispatcher("/WEB-INF/jsp/login.jsp").forward(request, response);
            }
        } else if (request.getParameter("signin") != null) {
            if (doPostSignin(request, session, out)) {
                response.sendRedirect("/home");
            } else {
                request.setAttribute("message", m_message);
                request.getRequestDispatcher("/WEB-INF/jsp/login.jsp").forward(request, response);
            }
        } else {
            response.sendRedirect("/login");
        }
    }
}
