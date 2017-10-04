package com.jweb.servlet.controller.admin;

import com.jweb.servlet.model.DBManager;
import com.jweb.servlet.model.ModelNews;
import com.jweb.servlet.model.beans.NewsBean;

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
public class News extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        if (Admin.isAuthorized(session)) {
            try {
                ArrayList<NewsBean> news = (ArrayList<NewsBean>) DBManager.executeQuery(new ModelNews(), "getNews", null);
                request.setAttribute("news", news);
                this.getServletContext().getRequestDispatcher("/WEB-INF/jsp/admin/news.jsp").forward(request, response);
            } catch (SQLException e) {
                System.err.println(e.getMessage());
                request.setAttribute("message", "Unable to views our news. Check your logs.");
                request.getRequestDispatcher("/admin").forward(request, response);
            }
        } else {
            response.sendRedirect("/home");
        }
    }
}
