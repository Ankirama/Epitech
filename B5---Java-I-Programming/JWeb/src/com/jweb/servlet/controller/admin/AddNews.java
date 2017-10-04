package com.jweb.servlet.controller.admin;

import com.jweb.servlet.model.DBManager;
import com.jweb.servlet.model.ModelNews;
import com.jweb.servlet.model.ModelNewsletter;
import com.jweb.servlet.utils.SendEmail;

import javax.servlet.ServletException;
import javax.servlet.annotation.MultipartConfig;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.nio.file.Files;
import java.nio.file.StandardCopyOption;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.HashMap;

/**
 * Created by ankirama on 26/12/15.
 */
@MultipartConfig() //recognize and support multipart/form-data
public class AddNews extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        if (Admin.isAuthorized(session)) {
            this.getServletContext().getRequestDispatcher("/WEB-INF/jsp/admin/addNews.jsp").forward(request, response);
        } else {
            response.sendRedirect("/home");
        }
    }

    private boolean sendEmailToSubscribers(String message) {
        try {
            ArrayList<String> emails = (ArrayList<String>)DBManager.executeQuery(new ModelNewsletter(), "getEmails", null);
             return SendEmail.sendNewsToUsers(emails, "Newsletter from E-Shopper", message);
        } catch (SQLException e) {
            System.err.println(e.getMessage());
            return false;
        }
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        if (request.getParameter("title") != null && request.getPart("illustration") != null && request.getParameter("message") != null) {
            HashMap<String, String> values = new HashMap<>();
            values.put("title", request.getParameter("title"));
            values.put("content", request.getParameter("message"));
            Part filePart = request.getPart("illustration");
            File file = File.createTempFile("illustration_news-", ".jpg", new File("/Users/ankirama/rendu/JWeb/data/uploads/"));
            try (InputStream filecontent = filePart.getInputStream()) {
                Files.copy(filecontent, file.toPath(), StandardCopyOption.REPLACE_EXISTING);
                values.put("illustration", "/images/" + file.getName());
                if ((boolean) DBManager.executeQuery(new ModelNews(), "createNews", values)) {
                    if (sendEmailToSubscribers("You can find our new news: " + values.get("title"))) {
                        request.setAttribute("message", "Your news is now available.");
                    } else {
                        request.setAttribute("message", "News created but we couldn't send the email.");
                    }
                } else {
                    request.setAttribute("message", "Unable to create your news.");
                }
            } catch (IOException | SQLException e) {
                System.err.println(e.getMessage());
                request.setAttribute("message", "Unable to create your news.");
            }
        } else {
            request.setAttribute("message", "you must fill all fields.");
        }
        request.getRequestDispatcher("/WEB-INF/jsp/admin/addNews.jsp").forward(request, response);
    }
}
