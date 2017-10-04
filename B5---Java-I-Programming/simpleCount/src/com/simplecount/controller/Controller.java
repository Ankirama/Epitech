package com.simplecount.controller;

import com.simplecount.model.Model;
import com.simplecount.view.frame.View;
import com.simplecount.view.panel.APanel;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

/**
 * @author ankirama
 * main class, used to allow model and view to communicate
 * it will contain our generic listener class, used to create our actionListener
 */
public class Controller {
    private Model   m_model; /**< our model class */
    private View    m_view; /**< our view class */

    /**
     * Constructor (default)
     * it will create a model / view, add listeners and display our view
     */
    public Controller() {
        m_model = new Model();
        m_view = new View();
        m_model.addObserver(m_view.getPanel(0));

        this.setScientistActionners(m_view.getPanel());
        m_view.display();
    }

    /**
     * Constructor
     * it will add listeners and display our view
     * @param model our model class
     * @param view our view class
     */
    public Controller(Model model, View view) {
        m_model = model;
        m_view = view;
        m_model.addObserver(m_view.getPanel(0));

        this.setScientistActionners(m_view.getPanel());
        m_view.display();
    }

    /**
     * it will set basics actionners like number, basic operations (+, -, ...)
     * @param panel panel we will set
     */
    private void setBasicActionners(APanel panel) {
        for (int i = 0; i < 10; ++i) {
            panel.createActionButton(Integer.toString(i), new GenericListener(this.m_model, "updateNumber", Integer.toString(i)));
        }
        panel.createActionButton("C", new GenericListener(this.m_model, "updateCleanAll"));
        panel.createActionButton("CE", new GenericListener(this.m_model, "updateCleanLine"));
        panel.createActionButton("lessormore", new GenericListener(this.m_model, "updateMinus"));
        panel.createActionButton(".", new GenericListener(this.m_model, "updateDot"));

        panel.createActionButton("+", new GenericListener(this.m_model, "updateOperator", "+"));
        panel.createActionButton("-", new GenericListener(this.m_model, "updateOperator", "-"));
        panel.createActionButton("*", new GenericListener(this.m_model, "updateOperator", "*"));
        panel.createActionButton("/", new GenericListener(this.m_model, "updateOperator", "/"));
        panel.createActionButton("%", new GenericListener(this.m_model, "updateOperator", "%"));
        panel.createActionButton("x^y", new GenericListener(this.m_model, "updateOperator", "^"));

        panel.createActionButton("=", new GenericListener(this.m_model, "updateEqual"));
    }

    /**
     * it will set scientific actionners like sqrt, ln etc etc
     * @param panel panel we will set
     */
    private void setScientistActionners(APanel panel) {
        this.setBasicActionners(panel);

        panel.createActionButton("log", new GenericListener(this.m_model, "updateOpenScope", "log"));
        panel.createActionButton("cos", new GenericListener(this.m_model, "updateOpenScope", "cos"));
        panel.createActionButton("sin", new GenericListener(this.m_model, "updateOpenScope", "sin"));
        panel.createActionButton("tan", new GenericListener(this.m_model, "updateOpenScope", "tan"));
        panel.createActionButton("ln", new GenericListener(this.m_model, "updateOpenScope", "ln"));
        panel.createActionButton("exp", new GenericListener(this.m_model, "updateOpenScope", "exp"));
        panel.createActionButton("(", new GenericListener(this.m_model, "updateOpenScope", "("));
        panel.createActionButton("sqrt", new GenericListener(this.m_model, "updateOpenScope", "sqrt"));

        panel.createActionButton(")", new GenericListener(this.m_model, "updateCloseScope"));
    }

    /**
     * @author ankirama
     *
     * It will allow us to create lister with a generic class
     * To use it, we're using reflexivity to create our class and invoke good method
     */
    class GenericListener implements ActionListener {
        private Method m_method; /**< method used to invoke our method and get a result */
        private Object m_target; /**< target to keep our object where we will check our method and use it */
        private Object arg; /**< arguments we will use in our method */

        /**
         * Constructor
         * It will store our variables like m_method etc etc
         * we will set our method too
         * @param target our object we will use to get method and invoke it
         * @param method our method we will try to find in our target
         */
        public GenericListener(Object target, String method) {
            Class targetClass = null;
            Class parameterTypes[] = null;

            this.m_target = target;
            this.arg = null;

            targetClass = this.m_target.getClass();
            parameterTypes = new Class[0];

            try {
                this.m_method = targetClass.getMethod(method, parameterTypes);
            } catch (NoSuchMethodException e) {
                System.err.println(e.getMessage());
            }
        }


        /**
         * Constructor
         * It will store our variables like m_method etc etc
         * we will set our method too
         * @param target our object we will use to get method and invoke it
         * @param method our method we will try to find in our target
         * @param arg our argument for our method
         */
        public GenericListener(Object target, String method, Object arg) {
            Class targetClass;
            Class parameterTypes[];

            this.m_target = target;
            this.arg = arg;

            targetClass = this.m_target.getClass();
            parameterTypes = this.createParameterTypes();

            try {
                this.m_method = targetClass.getMethod(method, parameterTypes);
            } catch (NoSuchMethodException e) {
                System.err.println(e.getMessage());
            }
        }

        /**
         * check args to convert in Class[]
         * @return Class[] created via this.arg.getClass() or Class[0]
         */
        private Class[] createParameterTypes() {
            Class parameterTypes[];

            if (this.arg == null) {
                parameterTypes = new Class[0];
            } else {
                parameterTypes = new Class[] { this.arg.getClass() };
            }
            return parameterTypes;
        }

        /**
         * check args to convert in Object[]
         * @return Object[] created via this.arg or Object[0]
         */
        private Object[] createArguments() {
            Object arguments[];

            if (this.arg == null) {
                arguments = new Object[0];
            } else {
                arguments = new Object[] { this.arg };
            }
            return arguments;
        }

        /**
         * our actionPerfomed function we override to define our generic listener
         * It will invoke our method to execute it
         * @param event our event from action, we will not use it
         */
        public void actionPerformed(ActionEvent event) {
            Object arguments[] = this.createArguments();

            try {
                this.m_method.invoke(this.m_target, arguments);
            } catch (InvocationTargetException | IllegalAccessException | IllegalArgumentException error) {
                System.err.println(error.getMessage());
            }
        }
    }
}
