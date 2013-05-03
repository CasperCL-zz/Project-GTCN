package com.view;

import java.awt.Dimension;
import java.awt.Toolkit;
import javax.swing.ImageIcon;
import javax.swing.JFrame;

/**
 * This class is used to optimize the look and feel of the Menu's. You can use
 * this class to set a JFrame in the middle of the screen.
 *
 * @version 2.7
 * @author Casper
 */
public class Menu extends JFrame {

    // The screen height
    private final int screenHeight = getHeightScreen();
    // The screen width 
    private final int screenWidth = getWidthScreen();

    /**
     * This method is an old method to set the JFrame in the middle of the
     * screen. You need to create another method in the class that calls this
     * method.
     *
     * @param appHeight the height if the application
     * @param appWidth the width if the application
     * @return an array of integers with the bounds of the JFrame. Respectively
     * x, y, w, h.
     */
    public int[] getBounds(int appHeight, int appWidth) {

        int xPosition = (int) ((screenWidth * 0.5) - (appWidth * 0.5));
        int yPosition = (int) ((screenHeight * 0.5) - (appHeight * 0.5));
        int[] bounds = {xPosition, yPosition, appWidth, appHeight};
        return bounds;
    }

    /**
     * This method sets the JFrame in the middle of the screen without use of
     * any other code aside from this. This is the successor of the getBounds
     * method and simplies the use.
     *
     */
    public void setScreen() {
        int localHeight = getHeightScreen();
        int localWidth = getWidthScreen();
        int appHeight = getHeight();
        int appWidth = getWidth();
        if (appHeight == 0 && appWidth == 0) {
            System.err.println("The JFrame that you are trying to set is either the wrong one or does not have a preferred size."
                    + "\nAborting setting screen");
            return;
        }

        int settingWidth = (int) ((localWidth * 0.5) - (appWidth * 0.5));
        int settingHeight = (int) ((localHeight * 0.5) - (appHeight * 0.5));

        setBounds(settingWidth, settingHeight, appWidth, appHeight);
    }

    /**
     * This method sets the JFrame in the middle of the screen with the
     * application wrapped around the background. This is the successor of the
     * getBounds method and simplies the use.
     *
     * @param JFrame object that is the Graphical User Interface.
     */
    public void setScreen(ImageIcon icon) {
        int localHeight = getHeightScreen();
        int localWidth = getWidthScreen();
        int appHeight = icon.getIconHeight();
        int appWidth = icon.getIconWidth();
        if (appHeight == 0 && appWidth == 0) {
            System.err.println("The JFrame that you are trying to set is either the wrong one or does not have a preferred size."
                    + "\nAborting setting screen");
            return;
        }

        int settingWidth = (int) ((localWidth * 0.5) - (appWidth * 0.5));
        int settingHeight = (int) ((localHeight * 0.5) - (appHeight * 0.5));

        setBounds(settingWidth, settingHeight, appWidth, appHeight);
    }

    /**
     * Retreives the Height of the user's screen.
     *
     * @return screens height
     */
    public int getHeightScreen() {
        Toolkit toolkit = Toolkit.getDefaultToolkit();

        // Get the current screen size
        Dimension screenDim = toolkit.getScreenSize();
        int height = (int) screenDim.getHeight();
        return height;
    }

    /*
     * *Retreives the Width of the user's screen.
     *
     * @return screens width
     */
    public int getWidthScreen() {
        Toolkit toolkit = Toolkit.getDefaultToolkit();
        Dimension screenDim = toolkit.getScreenSize();

        // Get the current screen size
        int width = (int) screenDim.getWidth();
        return width;
    }
}
