package Frames;

import javax.swing.*;
import javax.swing.border.Border;
import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;
import java.util.Collections;

public class MenuFrame extends JFrame {

    //variable declaration.

    private ArrayList<Ticket> menuTicketList;   //This is the main arrayList of Ticket objects

    private JFrame menuFrame;

    private AddTicketFrame newTicketWindow;
    private ShowListFrame listWindow;
    private AboutFrame aboutWindow;

    private JPanel buttonPanel;

    private ImageIcon menuTitleImage;

    private JButton newTicketButton;
    private JButton showListButton;
    private JButton aboutButton;
    private JButton exitButton;


    public MenuFrame() {
        // Components constructor.
        menuTicketList = new ArrayList<Ticket>();
        Collections.sort(menuTicketList);
        menuFrame = this; //Renaming the object into menuFrame for the compiler. "see line 120"

        buttonPanel = new JPanel();

        menuTitleImage = new ImageIcon("plane.png");

        newTicketButton = new JButton("Add");
        showListButton = new JButton("Ticket List");
        exitButton = new JButton("Exit");
        aboutButton = new JButton("About");
    }

    public void createMainMenu() {
                                                //Added a window listener for the top right buttons.
        this.addWindowListener(new WindowListener() {
            @Override
            public void windowOpened(WindowEvent e) {
            }

            @Override
            public void windowClosing(WindowEvent e) {
               // "X" button exits the program with code 0.
                System.exit(0);
            }

            @Override
            public void windowClosed(WindowEvent e) {
            }

            @Override
            public void windowIconified(WindowEvent e) {
            }

            @Override
            public void windowDeiconified(WindowEvent e) {
            }

            @Override
            public void windowActivated(WindowEvent e) {
            }

            @Override
            public void windowDeactivated(WindowEvent e) {
            }
        });

        //Button Pannel
        buttonPanel.setLayout(new BorderLayout());        //Switched to Border Layout
        buttonPanel.add(newTicketButton, BorderLayout.WEST);
        buttonPanel.add(showListButton, BorderLayout.SOUTH);
        buttonPanel.add(exitButton, BorderLayout.EAST);         //Adding all the buttons
        buttonPanel.add(aboutButton, BorderLayout.NORTH);
        buttonPanel.setBackground(Color.DARK_GRAY);

        newTicketButton.setBackground(new Color(0x07c900));
        newTicketButton.setFont(new Font("Arial", Font.BOLD, 13));
        showListButton.setBackground(new Color(0xe59400));
        showListButton.setFont(new Font("Arial", Font.BOLD, 15));      //button aesthetics
        aboutButton.setBackground(new Color(0x006e98));
        aboutButton.setFont(new Font("Arial", Font.BOLD, 15));
        exitButton.setBackground(new Color(0xba0000));
        exitButton.setFont(new Font("Arial", Font.BOLD, 13));

        newTicketButton.addActionListener(new ActionListener() {        //Action Listeners, one for each button
            @Override
            public void actionPerformed(ActionEvent e) {
                newTicketWindow = new AddTicketFrame(menuTicketList, menuTitleImage);    //Creates a new Add ticket frame object passing the 2 pointers
                newTicketWindow.createNewTicketFrame();
            }
        });                                // calls the method to create a new frame

        showListButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                listWindow = new ShowListFrame(menuTicketList, menuTitleImage);          //Same thing for the other window
                listWindow.createListFrame();
            }
        });

        aboutButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                aboutWindow = new AboutFrame();                                            //Same goes for the aboutFrame
                aboutWindow.createAboutFrame();
            }
        });

        exitButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String[] options = new String[2];
                options[0] = new String("Yes");  //This one makes a frame and asks the user for confirmation then terminates the program.
                options[1] = new String("No");
                int select = JOptionPane.showOptionDialog(menuFrame.getContentPane(), "Are you sure you want to quit?", "Quit", 0, JOptionPane.INFORMATION_MESSAGE, null, options, null);
                if (select == JOptionPane.YES_OPTION) {
                    System.exit(0);
                }
            }
        });

        //Frame settings.
        this.setTitle("AirTickets Pro");
        this.setLocation(500, 250);
        this.add(buttonPanel);
        this.setIconImage(menuTitleImage.getImage());               //changing the top-left logo of the frame.
        this.getContentPane().setBackground(Color.darkGray);    //changing the background color.
        this.setSize(310, 280);
        this.setResizable(false);
        this.setVisible(true);
    }
}
