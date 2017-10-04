package com.jweb.servlet.controller.admin;

import com.jweb.servlet.model.DBManager;
import com.jweb.servlet.model.ModelCategory;
import com.jweb.servlet.model.ModelNews;
import com.jweb.servlet.model.ModelProduct;
import com.jweb.servlet.model.beans.CategoryBean;

import javax.servlet.ServletException;
import javax.servlet.annotation.MultipartConfig;
import javax.servlet.http.*;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.nio.file.Files;
import java.nio.file.StandardCopyOption;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;

/**
 * Created by ankirama on 26/12/15.
 */
@MultipartConfig
public class AddProduct extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();

        if (Admin.isAuthorized(session)) {
            try {
                ArrayList<CategoryBean> categories = (ArrayList<CategoryBean>)DBManager.executeQuery(new ModelCategory(), "getCategories", null);
                request.setAttribute("categories", categories);
                this.getServletContext().getRequestDispatcher("/WEB-INF/jsp/admin/addProduct.jsp").forward(request, response);
            } catch (SQLException e) {
                System.err.println(e.getMessage());
                request.setAttribute("message", "Unable to display the page to add a product.");
                request.getRequestDispatcher("/admin").forward(request, response);
            }
        } else {
            response.sendRedirect("/home");
        }
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        if (request.getParameter("name") != null && request.getPart("illustration") != null && request.getParameter("description") != null
                && request.getParameter("price") != null && request.getParameter("categoryid") != null) {
            HashMap<String, String> values = new HashMap<>();
            values.put("name", request.getParameter("name"));
            values.put("description", request.getParameter("description"));
            values.put("price", request.getParameter("price"));
            values.put("categoryid", request.getParameter("categoryid"));
            Part filePart = request.getPart("illustration");
            File file = File.createTempFile("illustration_product-", ".jpg", new File("/Users/ankirama/rendu/JWeb/data/uploads/"));
            try (InputStream filecontent = filePart.getInputStream()) {
                Files.copy(filecontent, file.toPath(), StandardCopyOption.REPLACE_EXISTING);
                values.put("illustration", "/images/" + file.getName());
                if ((boolean) DBManager.executeQuery(new ModelProduct(), "createProduct", values)) {
                    request.setAttribute("message", "Your product is now available.");
                } else {
                    request.setAttribute("message", "Unable to create your product.");

                }
            } catch (IOException | SQLException e) {
                System.err.println(e.getMessage());
                request.setAttribute("message", "Unable to create your product.");
            }
        } else {
            request.setAttribute("message", "you must fill all fields.");
        }
        try {
            ArrayList<CategoryBean> categories = (ArrayList<CategoryBean>)DBManager.executeQuery(new ModelCategory(), "getCategories", null);
            request.setAttribute("categories", categories);
        } catch (SQLException e) {
            System.err.println(e.getMessage());
        }
        this.getServletContext().getRequestDispatcher("/WEB-INF/jsp/admin/addProduct.jsp").forward(request, response);
    }
}
