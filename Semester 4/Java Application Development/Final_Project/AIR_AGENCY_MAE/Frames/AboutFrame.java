package Frames;

import javax.swing.*;
import javax.swing.border.Border;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class AboutFrame extends JFrame {

    //Components
    private ScreenshotFrame screenshotWindow;

    private ImageIcon uniLogoImage;
    private ImageIcon titleIcon;

    private Border aboutBorder;

    private JLabel aboutLabel;
    private JLabel textLabel;
    private JPanel aboutPanel;
    private JPanel buttonPanel;
    private JButton screenshotButton;

    public AboutFrame() {
        //Components
        aboutPanel = new JPanel();
        buttonPanel = new JPanel();
        aboutBorder = BorderFactory.createLineBorder(new Color(0x006e98));
        titleIcon = new ImageIcon("easterEgg.png");
        uniLogoImage = new ImageIcon("padaLogo.png");
        textLabel = new JLabel();
        aboutLabel = new JLabel("About me:");
        screenshotButton = new JButton("Screenshots");
    }

    public void createAboutFrame(){

        //Panel settings
        aboutPanel.setLayout(new BorderLayout());
        aboutPanel.add(aboutLabel,BorderLayout.NORTH);          //About panel is added in the Center of the frame.
        aboutPanel.add(textLabel,BorderLayout.CENTER);          //Now we add at the top of the center "NORTH" a label that has a logo and a Title
        aboutPanel.setBackground(Color.DARK_GRAY);              //Anf then below that "CENTER" I'm adding the textLabel that contains html text.
        aboutPanel.setBorder(aboutBorder);
        aboutPanel.setBounds(this.getBounds());

        buttonPanel.setLayout(new FlowLayout(FlowLayout.CENTER));
        buttonPanel.add(screenshotButton);                          //This panel is located at the bottom of the screen "SOUTH" and has 1 button at the CENTER
        buttonPanel.setBackground(Color.DARK_GRAY);

        //About Label settings
        aboutLabel.setIcon(uniLogoImage);
        aboutLabel.setHorizontalTextPosition(JLabel.CENTER);
        aboutLabel.setVerticalTextPosition(JLabel.BOTTOM);
        aboutLabel.setForeground(Color.white);
        aboutLabel.setFont(new Font("Arial",Font.PLAIN,20));
        aboutLabel.setVerticalAlignment(JLabel.TOP);
        aboutLabel.setHorizontalAlignment(JLabel.CENTER);
        aboutLabel.setBackground(Color.DARK_GRAY);

        //Button settings
        screenshotButton.setBackground(Color.DARK_GRAY);
        screenshotButton.setBorder(aboutBorder);
        screenshotButton.setBackground(Color.DARK_GRAY);
        screenshotButton.setForeground(Color.white);
        screenshotButton.setFont(new Font("Arial",Font.BOLD,17));
        screenshotButton.addActionListener(new ActionListener() {                //This Action listener creates a new ScreenshotFrame object
            @Override                                                             // then calls the method to create a new frame. It also passes an Icon as a pointer.
            public void actionPerformed(ActionEvent e) {
                screenshotWindow = new ScreenshotFrame(titleIcon);
                screenshotWindow.makeScreenshotFrame();
            }
        });

        //Text Label settings
        textLabel.setText("<html><b>Application name: </b>AirTickets Pro, <br><b>Developer name:</b> Κούμανης Βασίλειος, <br><b>AM:</b> 19390104, <br><b>Class :</b> ΜΑΕ 08, <br><b>Date of Completion:</b> 12/Jun/2021, <br><b>Desktop development screenshot:</b></html>");
        textLabel.setForeground(Color.white);
        textLabel.setHorizontalAlignment(JLabel.CENTER);                //I'm using html for the label text aesthetics.
        textLabel.setHorizontalTextPosition(JLabel.CENTER);
        textLabel.setFont(new Font("Arial",Font.PLAIN,15));
        textLabel.setVisible(true);

        //Frame
        this.setTitle("Credits");
        this.setIconImage(titleIcon.getImage());
        this.setSize(550,650);
        this.setResizable(false);
        this.setLocation(500, 130);
        this.add(aboutPanel,BorderLayout.CENTER);
        this.add(buttonPanel,BorderLayout.SOUTH);
        this.getContentPane().setBackground(Color.darkGray);    //changing the background color.

        this.setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
        this.setVisible(true);

    }
}
