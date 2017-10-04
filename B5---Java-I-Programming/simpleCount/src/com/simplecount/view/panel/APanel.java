package com.simplecount.view.panel;

import com.simplecount.model.Model;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.Map;
import java.util.Observable;
import java.util.Observer;

/**
 * @author ankirama
 *
 * Abstract class to create A LOT OF PANEL (we only have one..)
 */
public abstract class APanel extends JPanel implements Observer {
    protected Container                m_container; /**< container from JFrame */
    protected Map<String, JButton>     m_buttons; /**< this map will contain all our buttons and a key to identify it */
    protected GridBagLayout            m_gridLayout; /**< This Grid allow us to set our buttons and use them */
    protected JTextArea                m_labelResult = new JTextArea(""); /**< It will contain the last result */
    protected JTextArea                m_labelCurrent = new JTextArea("0"); /**< It will contain the current expression and the result after equal button pressed"

    /**
     * create a button and add it in our map
     * @param key key like "buttonPlus", "sqrt", etc...
     * @param value like "+" value will be displayed on our button
     * @return new button created
     */
    protected JButton addButton(String key, String value) {
        JButton button = new JButton(value);
        this.m_buttons.put(key, button);
        return button;
    }

    /**
     * create a bagConstraints with size, position, insets to place a button
     * @param x x position
     * @param y y position
     * @param width size
     * @param height size
     * @param insets add space around our button
     * @return GridbagConstraints created
     */
    protected GridBagConstraints setPositionButton(int x, int y, int width, int height, Insets insets) {
        GridBagConstraints constraints = new GridBagConstraints();
        constraints.gridx = x;
        constraints.gridy = y;
        constraints.gridwidth = width;
        constraints.gridheight = height;
        constraints.fill = GridBagConstraints.BOTH;
        constraints.insets = insets;
        return constraints;
    }

    /**
     * associate an actionListener to a button
     * @param button buttonKey, we will try to find it
     * @param action we will add this actionListener
     * @return true if we added it, else false
     */
    public boolean createActionButton(String button, ActionListener action) {
        JButton tmp = this.m_buttons.get(button);

        if (tmp != null) {
            tmp.addActionListener(action);
            return true;
        } else {
            return false;
        }
    }

    /**
     * update function from Observer interface
     *
     * We will use some reflexivity to use our 2 methods (to get our string then we will display them)
     * @param obs Observable
     * @param obj object notified from our observable. It will be an instanceof Model
     */
    public void update(Observable obs, Object obj) {
        if (obs instanceof Model) {
            Class tmp = obj.getClass();
            try {
                Method m1 = tmp.getMethod("getAnswer", new Class[0]);
                Method m2 = tmp.getMethod("getCurrentExpression", new Class[0]);
                String s1 = (String)m1.invoke(obj, new Object[0]);
                s1 = s1 == null ? "" : s1;
                String s2 = (String)m2.invoke(obj, new Object[0]);
                s2 = s2 == null ? "" : s2;
                this.m_labelResult.setText(s1);
                this.m_labelCurrent.setText(s2);
            } catch (NoSuchMethodException | IllegalAccessException | InvocationTargetException e) {
                System.err.println("APanel: Error with update Observer");
            }
        }
    }

    /**
     * getter
     * @param button key to search our button
     * @return our button or null
     */
    public JButton getButton(String button) {
        return this.m_buttons.get(button);
    }

    /**
     * getter
     * @return m_labeResult
     */
    public JTextArea getTextArea() {
        return this.m_labelResult;
    }
}
