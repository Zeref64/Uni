package Frames;

import javax.swing.*;
import javax.swing.border.Border;
import java.awt.*;

public class ScreenshotFrame extends JFrame {
    //Components
  private JPanel screenshotPanel;
  private ImageIcon titleImage;
 private ImageIcon runningScreenshot;
 private JLabel imageLabel;
 private Border blueBorder;

  public ScreenshotFrame(ImageIcon titleImagePtr) {
      //Constructor
      this.titleImage = titleImagePtr;
      screenshotPanel = new JPanel();
      runningScreenshot = new ImageIcon("runningScreenshot1.png");
      imageLabel = new JLabel();
      blueBorder = BorderFactory.createLineBorder(new Color(0x006e98));
    }

    public void makeScreenshotFrame() {

      //Label settings
        imageLabel.setIcon(runningScreenshot);
        imageLabel.setLayout(new FlowLayout(FlowLayout.CENTER));
        imageLabel.setBackground(Color.DARK_GRAY);
        imageLabel.setVisible(true);

       //Panel settings
        screenshotPanel.add(imageLabel);
        screenshotPanel.setLayout(new FlowLayout(FlowLayout.CENTER));
        screenshotPanel.setBackground(Color.DARK_GRAY);
        screenshotPanel.setBounds(this.getBounds());
        screenshotPanel.setVisible(true);
        screenshotPanel.setBorder(blueBorder);

        // Frame settings.
        this.setTitle("Development Screenshot ^^");
        this.setIconImage(titleImage.getImage());
        this.add(screenshotPanel);
        this.getContentPane().setBackground(Color.darkGray);    //changing the background color.
        this.pack();           // changes the window size depending on the components inside there is no need to add a layout.
        this.setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
        this.setVisible(true);
    }
}
