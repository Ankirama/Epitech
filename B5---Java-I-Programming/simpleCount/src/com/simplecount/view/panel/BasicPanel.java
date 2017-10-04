package com.simplecount.view.panel;

import javax.swing.*;
import javax.swing.border.LineBorder;
import java.awt.*;
import java.util.HashMap;
import java.util.Map;

/**
 * This Class is our simple view
 * It will contain our UI for our simple calculator
 *
 * @author ankirama
 * @see com.simplecount.view.panel.APanel
 */
public class BasicPanel extends APanel {

    /**
     * Constructor
     * it will set our variables like gridbaglayoun, add our container etc etc...
     * @param container
     */
    public BasicPanel(Container container) {
        this.m_labelCurrent.setEditable(false);
        this.m_labelResult.setEditable(false);
        this.m_container = container;
        this.m_gridLayout = new GridBagLayout();
        this.setLayout(this.m_gridLayout);
        this.setBackground(Color.WHITE);
        this.initButtons();
        this.m_container.add(this);
    }

    /**
     * Init buttons
     * Move it, define color, text, position etc...
     */
    private void initButtons() {
        this.m_buttons = new HashMap<>();

        //-------------- Label area ----------------//

        this.add(this.m_labelResult, this.setPositionButton(0, 0, 12, 1, new Insets(0, 15, 2, 15)));
        this.m_labelResult.setBackground(Color.WHITE);
        this.add(this.m_labelCurrent, this.setPositionButton(0, 1, 12, 2, new Insets(0, 15, 2, 15)));
        this.m_labelCurrent.setBorder(new LineBorder(new Color(230, 230, 230), 1));

        //------------------ end ----------------------//

        this.add(this.addButton("C", "C"), this.setPositionButton(0, 4, 2, 3, new Insets(2, 15, 2, 2)));
        this.add(this.addButton("CE", "CE"), this.setPositionButton(0, 7, 2, 3, new Insets(2, 15, 2, 2)));
        this.add(this.addButton("cos", "cos"), this.setPositionButton(0, 10, 2, 3, new Insets(2, 15, 2, 2)));
        this.add(this.addButton("sin", "sin"), this.setPositionButton(0, 13, 2, 3, new Insets(2, 15, 2, 2)));
        this.add(this.addButton("tan", "tan"), this.setPositionButton(0, 17, 2, 3, new Insets(2, 15, 2, 2)));

        this.add(this.addButton("log", "log"), this.setPositionButton(2, 4, 2, 3, new Insets(2, 2, 2, 2)));
        this.add(this.addButton("ln", "ln"), this.setPositionButton(2, 7, 2, 3, new Insets(2, 2, 2, 2)));
        this.add(this.addButton("exp", "exp"), this.setPositionButton(2, 10, 2, 3, new Insets(2, 2, 2, 2)));
        this.add(this.addButton("sqrt", "\u221A"), this.setPositionButton(2, 13, 2, 3, new Insets(2, 2, 2, 2)));
        this.add(this.addButton("x^y", "x^y"), this.setPositionButton(2, 17, 2, 3, new Insets(2, 2, 2, 2)));

        this.add(this.addButton("(", "("), this.setPositionButton(4, 4, 2, 3, new Insets(2, 2, 2, 2)));
        this.add(this.addButton("7", "7"), this.setPositionButton(4, 7, 2, 3, new Insets(2, 2, 2, 2)));
        this.add(this.addButton("4", "4"), this.setPositionButton(4, 10, 2, 3, new Insets(2, 2, 2, 2)));
        this.add(this.addButton("1", "1"), this.setPositionButton(4, 13, 2, 3, new Insets(2, 2, 2, 2)));
        this.add(this.addButton("0", "0"), this.setPositionButton(4, 17, 2, 3, new Insets(2, 2, 2, 2)));

        this.add(this.addButton(")", ")"), this.setPositionButton(6, 4, 2, 3, new Insets(2, 2, 2, 2)));
        this.add(this.addButton("8", "8"), this.setPositionButton(6, 7, 2, 3, new Insets(2, 2, 2, 2)));
        this.add(this.addButton("5", "5"), this.setPositionButton(6, 10, 2, 3, new Insets(2, 2, 2, 2)));
        this.add(this.addButton("2", "2"), this.setPositionButton(6, 13, 2, 3, new Insets(2, 2, 2, 2)));
        this.add(this.addButton(".", "."), this.setPositionButton(6, 17, 2, 3, new Insets(2, 2, 2, 2)));

        this.add(this.addButton("%", "\u2052"), this.setPositionButton(8, 4, 2, 3, new Insets(2, 2, 2, 2)));
        this.add(this.addButton("9", "9"), this.setPositionButton(8, 7, 2, 3, new Insets(2, 2, 2, 2)));
        this.add(this.addButton("6", "6"), this.setPositionButton(8, 10, 2, 3, new Insets(2, 2, 2, 2)));
        this.add(this.addButton("3", "3"), this.setPositionButton(8, 13, 2, 3, new Insets(2, 2, 2, 2)));
        this.add(this.addButton("=", "="), this.setPositionButton(8, 17, 2, 3, new Insets(2, 2, 2, 2)));

        this.add(this.addButton("lessormore", "\u00B1"), this.setPositionButton(10, 4, 2, 3, new Insets(2, 2, 2, 15)));
        this.add(this.addButton("/", "\u00F7"), this.setPositionButton(10, 7, 2, 3, new Insets(2, 2, 2, 15)));
        this.add(this.addButton("*", "\u00D7"), this.setPositionButton(10, 10, 2, 3, new Insets(2, 2, 2, 15)));
        this.add(this.addButton("-", "-"), this.setPositionButton(10, 13, 2, 3, new Insets(2, 2, 2, 15)));
        this.add(this.addButton("+", "\u002B"), this.setPositionButton(10, 17, 2, 3, new Insets(2, 2, 2, 15)));

        for (Map.Entry<String, JButton> entry: this.m_buttons.entrySet()) {
            entry.getValue().setBorderPainted(false);

            if ("0123456789.".contains(entry.getKey())) {
                entry.getValue().setBackground(new Color(230, 230, 230));
            } else {
                entry.getValue().setBackground(new Color(200, 200, 200));
            }
            entry.getValue().setOpaque(true);
            entry.getValue().setRolloverEnabled(true);
        }
        this.m_buttons.get("=").setBackground(new Color(58, 60, 235));
        this.m_buttons.get("=").setForeground(Color.white);
    }
}
