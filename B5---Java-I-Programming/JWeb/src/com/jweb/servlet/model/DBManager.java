package com.jweb.servlet.model;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.sql.SQLException;
import java.sql.SQLIntegrityConstraintViolationException;

/**
 * Created by ankirama on 12/12/15.
 */
public class DBManager {
    /**
     * Manager to execute any query from our DB (reflection)
     * @param target target object where the query will be execute
     * @param method method we will call to execute our query
     * @param arg arg needed for our query
     * @throws SQLException
     */
    public static Object executeQuery(Object target, String method, Object arg) throws SQLException {
        Class targetClass;
        Class parameterTypes[];
        Object arguments[];
        Method m;

        targetClass = target.getClass();

        parameterTypes = arg == null ? new Class[0] : new Class[] { arg.getClass() };
        arguments = arg == null ? new Object[0] : new Object[] { arg };

        try {
            m = targetClass.getMethod(method, parameterTypes);
        } catch (NoSuchMethodException e) {
            System.err.println(e.getMessage());
            throw new SQLException(e);
        }

        try {
            return m.invoke(target, arguments);
        } catch (InvocationTargetException | IllegalAccessException e) {
            if (e.getCause() instanceof SQLException) {
                throw new SQLIntegrityConstraintViolationException();
            } else {
                throw new SQLException();
            }
        }
    }
}
