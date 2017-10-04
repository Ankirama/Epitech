package com.jweb.servlet.controller;

import com.jweb.servlet.model.DBManager;
import com.jweb.servlet.model.ModelNews;
import com.jweb.servlet.model.beans.NewsBean;
import com.jweb.servlet.utils.HelperMenu;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.InterruptedIOException;
import java.sql.SQLException;
import java.util.ArrayList;

/**
 * Created by ankirama on 25/12/15.
 */
public class News extends HttpServlet {

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HelperMenu.setMenu(request);
        if (request.getParameter("modal") != null && request.getParameter("newsId") != null) {
            try {
                NewsBean news = (NewsBean) DBManager.executeQuery(new ModelNews(), "getNewsById", Integer.parseInt(request.getParameter("newsId")));
                request.setAttribute("news", news);
            } catch (SQLException e) {
                System.err.println(e.getMessage());
                this.getServletContext().getRequestDispatcher("/WEB-INF/jsp/news.jsp").forward(request, response);
            }
        } else {
            request.removeAttribute("news");
            try {
                ArrayList<NewsBean> news;
                news = (ArrayList<NewsBean>) DBManager.executeQuery(new ModelNews(), "getNews", null);
                request.setAttribute("news", news);
                this.getServletContext().getRequestDispatcher("/WEB-INF/jsp/news.jsp").forward(request, response);
            } catch (SQLException e) {
                System.err.println(e.getMessage());
                response.sendRedirect("/home");
            }
        }
    }
}
