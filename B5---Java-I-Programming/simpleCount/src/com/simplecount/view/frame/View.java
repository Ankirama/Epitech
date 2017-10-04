package com.simplecount.view.frame;

import javax.swing.*;

import com.simplecount.view.panel.APanel;
import com.simplecount.view.panel.BasicPanel;

import java.util.ArrayList;

/**
 * @author ankirama
 *
 * View class to display our calculator
 */
public class View extends JFrame {
    private ArrayList<APanel> m_panels; /**< it will contain only 1 panel : useless */
    private APanel m_currentPanel; /**< it will be our only panel */

    /**
     * Constructor
     *
     * define our window + set our panel
     */
    public View() {
        this.setTitle("SimpleCount");
        this.setResizable(false);
        this.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        this.m_panels = new ArrayList<>();
        this.m_panels.add(new BasicPanel(this.getContentPane()));
        this.m_currentPanel = this.m_panels.get(0);
    }

    /**
     * getter for m_currentPanel
     * @return m_currentPanel
     */
    public APanel getPanel() {
        return this.m_currentPanel;
    }

    /**
     * @deprecated useless as fuck
     * @param index index to get our panel
     * @return our panel or null if wrong index
     */
    public APanel getPanel(int index) {
        if (index == 0) {
            return this.m_panels.get(index);
        } else {
            return null;
        }
    }

    /**
     * Set our main panel (currentPanel)
     * @param index we will set it with m_panels[index]
     */
    public void setCurrentPanel(int index) {
        if (index == 0)
        this.m_currentPanel = this.m_panels.get(index);
    }

    /**
     * pack + setVisible our frame
     */
    public void display() {
        this.pack();
        this.setVisible(true);
    }
}
