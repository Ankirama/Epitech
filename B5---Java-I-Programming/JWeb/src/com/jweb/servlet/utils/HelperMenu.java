package com.jweb.servlet.utils;

import com.jweb.servlet.model.DBManager;
import com.jweb.servlet.model.ModelCategory;
import com.jweb.servlet.model.beans.CategoryBean;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.sql.SQLException;
import java.util.ArrayList;

/**
 * Created by ankirama on 26/12/15.
 */
public class HelperMenu {
    /**
     * Helper method to get our categories in every servlets
     * @param request request from our servlets
     * @throws IOException
     */
    public static void setMenu(HttpServletRequest request) throws IOException {
        try {
            ArrayList<CategoryBean> categories = (ArrayList<CategoryBean>) DBManager.executeQuery(new ModelCategory(), "getCategories", null);
            request.setAttribute("categories", categories);
        } catch (SQLException e) {
            System.err.println(e.getMessage());
        }
    }
}
