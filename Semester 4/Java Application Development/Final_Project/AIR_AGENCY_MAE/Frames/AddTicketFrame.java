package Frames;

import javax.swing.*;
import javax.swing.border.Border;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.io.FileOutputStream;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;



public class AddTicketFrame extends JFrame {

    private ArrayList<Ticket> ticketList;
    private ImageIcon titleImage;
    private Ticket airTicket;

    private JButton saveButton;
    private JButton backButton;
    private JPanel buttonPanel;
    private JPanel textPanel;
    private Border border1;

    private JTextField idTextField;
    private JTextField dateTextField;
    private JTextField nameTextField;
    private JTextField costTextField;
    private JTextField routeTextField;
    private JTextField bagsTextField;
    private JTextField liquidsTextField;
    private JTextField weightTextField;
    private JTextField devicesTextField;

    private JLabel titleLabel;
    private JLabel idLabel;
    private JLabel dateLabel;
    private JLabel costTextLabel;
    private JLabel nameLabel;
    private JLabel routeLabel;
    private JLabel bagsLabel;
    private JLabel liquidsLabel;
    private JLabel weightLabel;
    private JLabel devicesLabel;

    public AddTicketFrame(ArrayList<Ticket> menuTicketList, ImageIcon menuTitleImage) {
        //Constructor

        this.ticketList = menuTicketList;
        this.titleImage = menuTitleImage;

        textPanel = new JPanel();
        buttonPanel = new JPanel();

        border1 = BorderFactory.createLineBorder(new Color(0x07c900));

        saveButton = new JButton("Save");
        backButton = new JButton("Back");

        idTextField = new JTextField();
        dateTextField = new JTextField();
        costTextField = new JTextField();
        nameTextField = new JTextField();
        routeTextField = new JTextField();
        bagsTextField = new JTextField();
        liquidsTextField = new JTextField();
        weightTextField = new JTextField();
        devicesTextField = new JTextField();

        titleLabel = new JLabel("Enter your Ticket information below: ");
        idLabel = new JLabel("ID: ");
        dateLabel = new JLabel("Date: ");
        nameLabel = new JLabel("Name: ");
        costTextLabel = new JLabel("Cost: ");
        routeLabel = new JLabel("Route: ");
        bagsLabel = new JLabel("Number of Bags: ");
        liquidsLabel = new JLabel("Liquids (ml): ");
        weightLabel = new JLabel("Weight (Kg): ");
        devicesLabel = new JLabel("Number of electronic devices: ");
    }

    
    public void createNewTicketFrame() {            //This is the method that creates the AddTicket Frame

        //All Panel settings
        textPanel.add(idLabel);
        textPanel.add(idTextField);
        textPanel.add(nameLabel);
        textPanel.add(nameTextField);
        textPanel.add(costTextLabel);
        textPanel.add(costTextField);
        textPanel.add(dateLabel);
        textPanel.add(dateTextField);
        textPanel.add(bagsLabel);
        textPanel.add(bagsTextField);          // I used the Grid Layout for the AddTicketFrame
        textPanel.add(routeLabel);              //in order to add all the components side by side.
        textPanel.add(routeTextField);
        textPanel.add(liquidsLabel);
        textPanel.add(liquidsTextField);
        textPanel.add(weightLabel);
        textPanel.add(weightTextField);
        textPanel.add(devicesLabel);                //This panel is located at the center of the frame "line 264"
        textPanel.add(devicesTextField);
        textPanel.setLayout(new GridLayout(5, 5));
        textPanel.setBackground(Color.DARK_GRAY);
        textPanel.setBounds(this.getBounds());
        textPanel.setBorder(border1);

        buttonPanel.add(saveButton);
        buttonPanel.add(backButton);
        buttonPanel.setLayout(new FlowLayout(FlowLayout.CENTER));       //This panel is located at the bottom of the frame "line 265"
        buttonPanel.setBackground(Color.DARK_GRAY);

        //All Label settings

        titleLabel.setBackground(Color.DARK_GRAY);
        titleLabel.setForeground(Color.white);
        titleLabel.setFont(new Font("Arial", Font.PLAIN, 14));
        titleLabel.setVisible(true);

        idLabel.setBackground(Color.DARK_GRAY);
        idLabel.setForeground(Color.white);
        idLabel.setFont(new Font("Arial", Font.PLAIN, 14));
        idLabel.setVisible(true);

        costTextLabel.setBackground(Color.DARK_GRAY);
        costTextLabel.setForeground(Color.white);
        costTextLabel.setFont(new Font("Arial", Font.PLAIN, 14));
        costTextLabel.setVisible(true);

        dateLabel.setBackground(Color.DARK_GRAY);
        dateLabel.setForeground(Color.white);
        dateLabel.setFont(new Font("Arial", Font.PLAIN, 14));
        dateLabel.setVisible(true);

        nameLabel.setBackground(Color.DARK_GRAY);
        nameLabel.setForeground(Color.white);
        nameLabel.setFont(new Font("Arial", Font.PLAIN, 14));
        nameLabel.setVisible(true);

        routeLabel.setBackground(Color.DARK_GRAY);
        routeLabel.setForeground(Color.white);
        routeLabel.setFont(new Font("Arial", Font.PLAIN, 14));
        routeLabel.setVisible(true);

        bagsLabel.setBackground(Color.DARK_GRAY);
        bagsLabel.setForeground(Color.white);
        bagsLabel.setFont(new Font("Arial", Font.PLAIN, 14));
        bagsLabel.setVisible(true);

        liquidsLabel.setBackground(Color.DARK_GRAY);
        liquidsLabel.setForeground(Color.white);
        liquidsLabel.setFont(new Font("Arial", Font.PLAIN, 14));
        liquidsLabel.setVisible(true);

        weightLabel.setBackground(Color.DARK_GRAY);
        weightLabel.setForeground(Color.white);
        weightLabel.setFont(new Font("Arial", Font.PLAIN, 13));
        weightLabel.setVisible(true);

        devicesLabel.setBackground(Color.DARK_GRAY);
        devicesLabel.setForeground(Color.white);
        devicesLabel.setFont(new Font("Arial", Font.PLAIN, 12));
        devicesLabel.setVisible(true);

        //Text Fields
        idTextField.setBackground(new Color(0x5e5e5e));
        idTextField.setForeground(Color.white);
        numberValidation(idTextField);

        nameTextField.setBackground(new Color(0x5e5e5e));
        nameTextField.setForeground(Color.white);

        costTextField.setBackground(new Color(0x5e5e5e));
        costTextField.setForeground(Color.white);
        floatNumberValidation(costTextField);

        dateTextField.setBackground(new Color(0x5e5e5e));
        dateTextField.setForeground(Color.white);

        bagsTextField.setBackground(new Color(0x5e5e5e));
        bagsTextField.setForeground(Color.white);
        numberValidation(bagsTextField);

        routeTextField.setBackground(new Color(0x5e5e5e));
        routeTextField.setForeground(Color.white);

        liquidsTextField.setBackground(new Color(0x5e5e5e));
        liquidsTextField.setForeground(Color.white);
        floatNumberValidation(liquidsTextField);

        weightTextField.setBackground(new Color(0x5e5e5e));
        weightTextField.setForeground(Color.white);
        floatNumberValidation(weightTextField);

        devicesTextField.setBackground(new Color(0x5e5e5e));
        devicesTextField.setForeground(Color.white);
        numberValidation(devicesTextField);

        //Button Action Listeners / Settings

        saveButton.setBorder(border1);
        saveButton.setBackground(Color.DARK_GRAY);
        saveButton.setForeground(Color.white);
        saveButton.setFont(new Font("Arial", Font.BOLD, 17));   //This action listener checks if any field is empty then proceeds to
        saveButton.addActionListener(new ActionListener() {             //save the ticket to the file then creates a new ticket object, saves it
            @Override
            // to an ArrayList and lastly it informs the user with a popup window.
            public void actionPerformed(ActionEvent e) {
                //Saving
                if (nullCheck(idTextField, nameTextField, costTextField, dateTextField, routeTextField, bagsTextField, liquidsTextField, weightTextField, devicesTextField) == true) {
                    String[] options = new String[1];
                    options[0] = "Confirm";
                    int select = JOptionPane.showOptionDialog(null, "Ticket saved successfully", "Note", 0, JOptionPane.INFORMATION_MESSAGE, null, options, null);
                    if (select == JOptionPane.YES_OPTION) {
                        dispose(); //Closes the ticket window and returns to the main menu
                    }
                    try {
                        saveToFile("ticketSaveFile.txt", idTextField, nameTextField, dateTextField, costTextField, bagsTextField, routeTextField, liquidsTextField, weightTextField, devicesTextField);
                        createNewTicket(ticketList, idTextField, nameTextField, dateTextField, costTextField, bagsTextField, routeTextField, liquidsTextField, weightTextField, devicesTextField);

                    } catch (Exception exception) {
                        exception.printStackTrace();
                    }

                } else
                    JOptionPane.showMessageDialog(null, "Please complete all the fields.", "Error", JOptionPane.WARNING_MESSAGE);
            }
        });        //Action Listener that saves the Ticket info into a file and in the ticket list.

        backButton.setBorder(border1);
        backButton.setBackground(Color.DARK_GRAY);
        backButton.setForeground(Color.white);
        backButton.setFont(new Font("Arial", Font.BOLD, 17));
        backButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String[] options = new String[2];
                options[0] = "Yes";
                options[1] = "No";
                int select = JOptionPane.showOptionDialog(null, "Go back to the main menu?", "Go Back?", 0, JOptionPane.INFORMATION_MESSAGE, null, options, null);
                if (select == JOptionPane.YES_OPTION) {
                    dispose();
                }
            }
        });     //Action listener that asks the user for permission to go back to the main window.

        // Frame
        this.setTitle("Add a new Ticket");
        this.setIconImage(titleImage.getImage());
        this.setSize(680, 310);
        this.setLocation(500, 130);
        this.setLayout(new BorderLayout());
        this.getContentPane().setBackground(Color.darkGray);    //changing the background color.
        this.add(textPanel, BorderLayout.CENTER);
        this.add(buttonPanel, BorderLayout.SOUTH);
        this.add(titleLabel, BorderLayout.NORTH);        //I did not add a panel for a single label because I was satisfied with the placement
        this.setResizable(false);
        this.setVisible(true);
        this.setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);

    }

    public boolean nullCheck(JTextField idTextField, JTextField nameTextField, JTextField costTextField, JTextField dateTextField, JTextField routeTextField, JTextField bagsTextField, JTextField liquidsTextField, JTextField weightTextField, JTextField devicesTextField) {
        if (idTextField.getText().equals("") || nameTextField.getText().equals("") || costTextField.getText().equals("") || dateTextField.getText().equals("") || routeTextField.getText().equals("") || bagsTextField.getText().equals("") || liquidsTextField.getText().equals("") || weightTextField.getText().equals("") || dateTextField.getText().equals("")) {
            return false;
        } else return true;
    }

    public void numberValidation(JTextField txtField)       //Checks if user typed number
    {
        txtField.addKeyListener(new KeyAdapter() {
            public void keyTyped(KeyEvent keyPress) {           //This function creates a key listener for a JTextField and
                char character = keyPress.getKeyChar();         //Checks if the datatype is numeric or backspace or delete if not then it pops an error message.
                if (!(Character.isDigit(character) || (character == KeyEvent.VK_BACK_SPACE) || (character == KeyEvent.VK_DELETE) || (character == KeyEvent.VK_ENTER))) {
                    keyPress.consume();
                    JOptionPane.showMessageDialog(null, "Only numbers are allowed!", "Error", JOptionPane.WARNING_MESSAGE);
                }
            }
        });
    }

    public void floatNumberValidation(JTextField txtField)          //Checks if user typed number including floats "ex. 3.14"
    {
        txtField.addKeyListener(new KeyAdapter() {
            public void keyTyped(KeyEvent keyPress) {           //This function creates a key listener for a JTextField and
                char character = keyPress.getKeyChar();         //Checks if the datatype is numeric or backspace or enter or delete or ". for float" if not then it pops an error message.
                if (!(Character.isDigit(character) || (character == KeyEvent.VK_BACK_SPACE) || (character == KeyEvent.VK_DELETE) || (character == KeyEvent.VK_ENTER) || (character == KeyEvent.VK_PERIOD))) {
                    keyPress.consume();
                    JOptionPane.showMessageDialog(null, "Only float numbers are allowed!", "Error", JOptionPane.WARNING_MESSAGE);
                }
            }
        });
    }

    void saveToFile(String ticketSaveFile, JTextField idTextField, JTextField nameTextField, JTextField dateTextField, JTextField costTextField, JTextField bagsTextField, JTextField routeTextField, JTextField liquidsTextField, JTextField weightTextField, JTextField devicesTextField)
            throws Exception {
        FileOutputStream outStream = new FileOutputStream(ticketSaveFile, true);

        outStream.write(idTextField.getText().getBytes());
        outStream.write("/".getBytes(StandardCharsets.UTF_8));
        outStream.write(nameTextField.getText().getBytes());
        outStream.write("/".getBytes(StandardCharsets.UTF_8));
        outStream.write(dateTextField.getText().getBytes());            //Im using a function in order to save all the JTextField contents into a file
        outStream.write("/".getBytes(StandardCharsets.UTF_8));
        outStream.write(costTextField.getText().getBytes());            //Saving ticket contents in ticketSaveFile.txt
        outStream.write("/".getBytes(StandardCharsets.UTF_8));          //  Separator character is "/"
        outStream.write(bagsTextField.getText().getBytes());
        outStream.write("/".getBytes(StandardCharsets.UTF_8));
        outStream.write(routeTextField.getText().getBytes());
        outStream.write("/".getBytes(StandardCharsets.UTF_8));
        outStream.write(liquidsTextField.getText().getBytes());
        outStream.write("/".getBytes(StandardCharsets.UTF_8));
        outStream.write(weightTextField.getText().getBytes());
        outStream.write("/".getBytes(StandardCharsets.UTF_8));
        outStream.write(devicesTextField.getText().getBytes());
        outStream.write("\n".getBytes(StandardCharsets.UTF_8));
    }                                                                   // νν This function takes the contents of the TextAreas and adds them on the ticketList νν

    public void createNewTicket(ArrayList<Ticket> ticketList, JTextField idTextField, JTextField nameTextField, JTextField dateTextField, JTextField priceTextField, JTextField bagsTextField, JTextField routeTextField, JTextField liquidTextField, JTextField weightTextField, JTextField devicestextField) {
        airTicket = new Ticket(Long.parseLong(idTextField.getText()), nameTextField.getText(), dateTextField.getText(), Float.parseFloat(priceTextField.getText()), Integer.parseInt(bagsTextField.getText()), routeTextField.getText(), Float.parseFloat(liquidTextField.getText()), Float.parseFloat(weightTextField.getText()), Integer.parseInt(devicestextField.getText()));
        ticketList.add(airTicket);      //I'm creating a new Ticket obj then I add the obj into the ticketList which is connected to the main menu's ticketList.
    }

}
