package Frames;

import javax.swing.*;
import javax.swing.border.Border;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class ShowListFrame extends JFrame {

    private ArrayList<Ticket> ticketList;
    private ImageIcon titleImage;

    private AddTicketFrame newTicketFrame;
    private JFrame newListFrame;

    private JPanel mainPanel;
    private JPanel titlePanel;
    private JPanel infoPanel;
    private JPanel buttonPanel;
    private JPanel statisticsPanel;
    private JPanel innerStatisticsPanel;
    private JScrollPane scrollPanel;

    private JLabel titleLabel;
    private JLabel idLabel;
    private JLabel nameLabel;
    private JLabel dateLabel;
    private JLabel priceLabel;
    private JLabel bagsLabel;
    private JLabel routeLabel;
    private JLabel liquidsLabel;
    private JLabel weightLabel;
    private JLabel devicesLabel;
    private JLabel statisticsLabel;
    private JLabel totalTicketLabel;
    private JLabel totalCostLabel;
    private JLabel expensiveTicketLabel;
    private JLabel cheapTicketLabel;

    private JButton addTicketButton;
    private JButton refreshListButton;
    private JButton exitButton;

    private Border orangeBorder;
    private Border redBorder;
    private Border greenBorder;
    private Border blueBorder;

    private JList<Long> idList;
    private JList<String> dateList;
    private JList<String> nameList;
    private JList<Float> priceList;
    private JList<String> routeList;
    private JList<Integer> bagsList;
    private JList<Float> liquidList;
    private JList<Float> weightList;
    private JList<Integer> devicesList;

    private DefaultListModel<Long> defaultIdList;
    private DefaultListModel<String> defaultNameList;
    private DefaultListModel<String> defaultDateList;
    private DefaultListModel<Float> defaultPriceList;
    private DefaultListModel<Integer> defaultBagsList;
    private DefaultListModel<String> defaultRouteList;
    private DefaultListModel<Float> defaultLiquidList;
    private DefaultListModel<Float> defaultWeightList;
    private DefaultListModel<Integer> defaultDevicesList;


    public ShowListFrame(ArrayList<Ticket> menuTicketList, ImageIcon menuTitleImage) {

        this.ticketList = menuTicketList;       //I'm passing the pointer through the constructor so this list is the same list as the menuTicketList from MenuFrame.
        this.titleImage = menuTitleImage;        //Same thing here I prefer doing it this way rather than creating a new image icon every time.
        newListFrame = this;

        mainPanel = new JPanel();
        titlePanel = new JPanel();
        infoPanel = new JPanel();
        buttonPanel = new JPanel();
        statisticsPanel = new JPanel();
        innerStatisticsPanel = new JPanel();
        scrollPanel = new JScrollPane(infoPanel);

        addTicketButton = new JButton("Add");
        refreshListButton = new JButton("Refresh");
        exitButton = new JButton("Exit");

        orangeBorder = BorderFactory.createLineBorder(new Color(0xe59400));
        redBorder = BorderFactory.createLineBorder(new Color(0xba0000));
        greenBorder = BorderFactory.createLineBorder(new Color(0x07c900));
        blueBorder = BorderFactory.createLineBorder(new Color(0x006e98));

        titleLabel = new JLabel("Ticket List:");
        idLabel = new JLabel("ID: ");
        nameLabel = new JLabel("Name: ");
        dateLabel = new JLabel("Date: ");
        priceLabel = new JLabel("Cost: ");
        bagsLabel = new JLabel("Bags: ");
        routeLabel = new JLabel("Route: ");
        liquidsLabel = new JLabel("liquids: ");
        weightLabel = new JLabel("Weight: ");
        devicesLabel = new JLabel("Devices: ");
        statisticsLabel = new JLabel("Statistics: ");
        if (ticketList.isEmpty()) {
            totalTicketLabel = new JLabel("Ticket Counter: " + ticketList.size());
            totalCostLabel = new JLabel("Total Ticket cost: -");
            expensiveTicketLabel = new JLabel("Most Expensive Ticket: -");
            cheapTicketLabel = new JLabel("Most Affordable Ticket: -");
        } else {
            totalTicketLabel = new JLabel("Ticket Counter: " + ticketList.size());
            totalCostLabel = new JLabel("Total Ticket Price: " + getTotalCost());
            Ticket mostExpensiveTicket = ticketList.stream().max(Comparator.comparingDouble(Ticket::getPrice)).get();              //These lines are duplicate with the ones at the bottom because
            Ticket cheapestTicket = ticketList.stream().min(Comparator.comparingDouble(Ticket::getPrice)).get();                   //here it sets the text the 1st time the frame opens and the second ones are for the refresh button
            expensiveTicketLabel = new JLabel("Most Expensive Ticket ID: " + mostExpensiveTicket.getPrice() + " ID: " + mostExpensiveTicket.getTicketID());
            cheapTicketLabel = new JLabel("Most Affordable Ticket ID: " + cheapestTicket.getPrice() + " ID: " + cheapestTicket.getTicketID());           //Comments for this at the bottom of the code initializeStatisticsUI Function
        }


        defaultIdList = new DefaultListModel<>();
        defaultNameList = new DefaultListModel<>();
        defaultDateList = new DefaultListModel<>();
        defaultPriceList = new DefaultListModel<>();
        defaultBagsList = new DefaultListModel<>();            //Here im creating default List Models in order to add them into the JLists later
        defaultDevicesList = new DefaultListModel<>();
        defaultLiquidList = new DefaultListModel<>();
        defaultRouteList = new DefaultListModel<>();
        defaultWeightList = new DefaultListModel<>();

        idList = new JList<>(defaultIdList);
        dateList = new JList<>(defaultDateList);
        nameList = new JList<>(defaultNameList);
        priceList = new JList<>(defaultPriceList);          //These are the JLists based on the Default List Models
        routeList = new JList<>(defaultRouteList);
        bagsList = new JList<>(defaultBagsList);
        liquidList = new JList<>(defaultLiquidList);
        weightList = new JList<>(defaultWeightList);
        devicesList = new JList<>(defaultDevicesList);


    }

    public void createListFrame() {

        Collections.sort(ticketList);       //Using the .sort method with comparable to sort the objects by cost asc

        for (Ticket X : ticketList) {
            defaultIdList.addElement(X.getTicketID());
            defaultNameList.addElement(X.getClientName());
            defaultDateList.addElement(X.getIssueDate());
            defaultPriceList.addElement(X.getPrice());
            defaultRouteList.addElement(X.getRoute());            //With this for loop im filling the list with the components of the most recent Ticket-Object
            defaultBagsList.addElement(X.getNumOfBags());
            defaultLiquidList.addElement(X.getLiquidSubstances());
            defaultWeightList.addElement(X.getWeight());
            defaultDevicesList.addElement(X.getElectronicDevices());
        }


        //Panel settings
        mainPanel.setLayout(new GridLayout(2, 1));
        mainPanel.add(titlePanel);                                  //The frame is made of 5 Panels.
        mainPanel.add(scrollPanel);                                 // 1 mainPanel, 2 titlePanel, 3 infoPanel, 4 statisticsPanel, 5 innerStatisticsPanel.
                                                                    //And a scroll panel
        titlePanel.add(idLabel);                            //the main panel contains all the panels
        titlePanel.add(nameLabel);
        titlePanel.add(dateLabel);
        titlePanel.add(priceLabel);     //The title panel contains the JLabels that show the type
        titlePanel.add(routeLabel);
        titlePanel.add(bagsLabel);
        titlePanel.add(liquidsLabel);           //Aesthetics
        titlePanel.add(weightLabel);
        titlePanel.add(devicesLabel);
        titlePanel.setLayout(new GridLayout(1, 9));
        titlePanel.setBackground(Color.DARK_GRAY);

        infoPanel.add(idList);
        infoPanel.add(nameList);
        infoPanel.add(dateList);
        infoPanel.add(priceList);
        infoPanel.add(routeList);           //the info panel contains the list of the object attributes ex. idList contains every objects ID
        infoPanel.add(bagsList);
        infoPanel.add(liquidList);
        infoPanel.add(weightList);
        infoPanel.add(devicesList);
        infoPanel.setLayout(new GridLayout(1, 9));

        scrollPanel.setBackground(Color.DARK_GRAY);
        scrollPanel.setBorder(orangeBorder);

        innerStatisticsPanel.setLayout(new GridLayout(4, 1));
        innerStatisticsPanel.setBackground(Color.DARK_GRAY);
        innerStatisticsPanel.setBorder(blueBorder);
        innerStatisticsPanel.add(totalTicketLabel);
        innerStatisticsPanel.add(totalCostLabel);               //The inner statistics panel contains 4 labels that show the statistic info
        innerStatisticsPanel.add(expensiveTicketLabel);
        innerStatisticsPanel.add(cheapTicketLabel);


        statisticsPanel.setBackground(Color.DARK_GRAY);
        statisticsPanel.setLayout(new BorderLayout());
        statisticsPanel.add(statisticsLabel, BorderLayout.NORTH);           //and the statistics panel contains the innerStatistics panel and some more changes for aesthetic puposes.
        statisticsPanel.add(innerStatisticsPanel, BorderLayout.CENTER);

        buttonPanel.setLayout(new GridLayout(3, 1));
        buttonPanel.setBackground(Color.DARK_GRAY);

        buttonPanel.add(addTicketButton);
        buttonPanel.add(refreshListButton);
        buttonPanel.add(exitButton);


        //Label settings
        titleLabel.setForeground(Color.white);
        titleLabel.setFont(new Font("Arial", Font.BOLD, 15));
        titleLabel.setHorizontalAlignment(JLabel.CENTER);

        idLabel.setForeground(Color.white);
        idLabel.setFont(new Font("Arial", Font.BOLD, 13));
        idLabel.setHorizontalAlignment(JLabel.LEFT);
        idLabel.setVerticalAlignment(JLabel.BOTTOM);

        nameLabel.setForeground(Color.white);
        nameLabel.setFont(new Font("Arial", Font.BOLD, 13));
        nameLabel.setHorizontalAlignment(JLabel.LEFT);
        nameLabel.setVerticalAlignment(JLabel.BOTTOM);

        dateLabel.setForeground(Color.white);
        dateLabel.setFont(new Font("Arial", Font.BOLD, 13));
        dateLabel.setHorizontalAlignment(JLabel.LEFT);
        dateLabel.setVerticalAlignment(JLabel.BOTTOM);

        priceLabel.setForeground(Color.white);
        priceLabel.setFont(new Font("Arial", Font.BOLD, 13));
        priceLabel.setHorizontalAlignment(JLabel.LEFT);
        priceLabel.setVerticalAlignment(JLabel.BOTTOM);

        bagsLabel.setForeground(Color.white);
        bagsLabel.setFont(new Font("Arial", Font.BOLD, 13));
        bagsLabel.setHorizontalAlignment(JLabel.LEFT);
        bagsLabel.setVerticalAlignment(JLabel.BOTTOM);

        routeLabel.setForeground(Color.white);
        routeLabel.setFont(new Font("Arial", Font.BOLD, 13));
        routeLabel.setHorizontalAlignment(JLabel.LEFT);
        routeLabel.setVerticalAlignment(JLabel.BOTTOM);

        liquidsLabel.setForeground(Color.white);
        liquidsLabel.setFont(new Font("Arial", Font.BOLD, 13));
        liquidsLabel.setHorizontalAlignment(JLabel.LEFT);
        liquidsLabel.setVerticalAlignment(JLabel.BOTTOM);

        weightLabel.setForeground(Color.white);
        weightLabel.setFont(new Font("Arial", Font.BOLD, 13));
        weightLabel.setHorizontalAlignment(JLabel.LEFT);
        weightLabel.setVerticalAlignment(JLabel.BOTTOM);

        devicesLabel.setForeground(Color.white);
        devicesLabel.setFont(new Font("Arial", Font.BOLD, 13));
        devicesLabel.setHorizontalAlignment(JLabel.LEFT);
        devicesLabel.setVerticalAlignment(JLabel.BOTTOM);

        statisticsLabel.setForeground(Color.white);
        statisticsLabel.setFont(new Font("Arial", Font.BOLD, 15));
        statisticsLabel.setHorizontalAlignment(JLabel.CENTER);

        totalTicketLabel.setForeground(Color.white);
        totalTicketLabel.setFont(new Font("Arial", Font.BOLD, 13));
        totalTicketLabel.setHorizontalAlignment(JLabel.LEFT);

        totalCostLabel.setForeground(Color.white);
        totalCostLabel.setFont(new Font("Arial", Font.BOLD, 13));
        totalCostLabel.setHorizontalAlignment(JLabel.CENTER);

        expensiveTicketLabel.setForeground(Color.white);
        expensiveTicketLabel.setFont(new Font("Arial", Font.BOLD, 13));
        expensiveTicketLabel.setHorizontalAlignment(JLabel.CENTER);

        cheapTicketLabel.setForeground(Color.white);
        cheapTicketLabel.setFont(new Font("Arial", Font.BOLD, 13));
        cheapTicketLabel.setHorizontalAlignment(JLabel.CENTER);

        //List settings
        idList.setBackground(Color.DARK_GRAY);
        idList.setForeground(Color.white);
        idList.setFont(new Font("Arial", Font.PLAIN, 12));

        nameList.setBackground(Color.DARK_GRAY);
        nameList.setForeground(Color.white);
        nameList.setFont(new Font("Arial", Font.PLAIN, 12));

        dateList.setBackground(Color.DARK_GRAY);
        dateList.setForeground(Color.white);
        dateList.setFont(new Font("Arial", Font.PLAIN, 12));

        priceList.setBackground(Color.DARK_GRAY);
        priceList.setForeground(Color.white);
        priceList.setFont(new Font("Arial", Font.PLAIN, 12));

        routeList.setBackground(Color.DARK_GRAY);
        routeList.setForeground(Color.white);
        routeList.setFont(new Font("Arial", Font.PLAIN, 12));

        bagsList.setBackground(Color.DARK_GRAY);
        bagsList.setForeground(Color.white);
        bagsList.setFont(new Font("Arial", Font.PLAIN, 12));

        liquidList.setBackground(Color.DARK_GRAY);
        liquidList.setForeground(Color.white);
        liquidList.setFont(new Font("Arial", Font.PLAIN, 12));

        weightList.setBackground(Color.DARK_GRAY);
        weightList.setForeground(Color.white);
        weightList.setFont(new Font("Arial", Font.PLAIN, 12));

        devicesList.setBackground(Color.DARK_GRAY);
        devicesList.setForeground(Color.white);
        devicesList.setFont(new Font("Arial", Font.PLAIN, 12));

        //Button Settings
        addTicketButton.setVerticalAlignment(JButton.CENTER);
        addTicketButton.setBorder(greenBorder);
        addTicketButton.setBackground(Color.DARK_GRAY);
        addTicketButton.setForeground(Color.white);
        addTicketButton.setFont(new Font("Arial", Font.BOLD, 15));
        addTicketButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                newTicketFrame = new AddTicketFrame(ticketList, titleImage);
                newTicketFrame.createNewTicketFrame();
            }
        });

        refreshListButton.setVerticalAlignment(JButton.CENTER);
        refreshListButton.setBorder(orangeBorder);
        refreshListButton.setBackground(Color.DARK_GRAY);
        refreshListButton.setForeground(Color.white);
        refreshListButton.setFont(new Font("Arial", Font.BOLD, 16));
        refreshListButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                if (ticketList.isEmpty()) {

                    String[] options = new String[1];
                    options[0] = "Confirm";
                    int select = JOptionPane.showOptionDialog(newListFrame.getContentPane(), "You have not added any Tickets.", "Error", JOptionPane.YES_NO_OPTION, JOptionPane.INFORMATION_MESSAGE, null, options, null);
                    if (select == JOptionPane.YES_OPTION) {                             //This is just a normal JOptionPane that pops an error if the user tries to refresh the list while It's empty
                        newListFrame.setDefaultCloseOperation(DISPOSE_ON_CLOSE);
                    }
                } else {
                    initializeStatisticsUI();
                    defaultIdList.removeAllElements();
                    defaultNameList.removeAllElements();
                    defaultDateList.removeAllElements();
                    defaultPriceList.removeAllElements();           //Clearing all the list
                    defaultRouteList.removeAllElements();
                    defaultBagsList.removeAllElements();
                    defaultLiquidList.removeAllElements();
                    defaultWeightList.removeAllElements();
                    defaultDevicesList.removeAllElements();

                    Collections.sort(ticketList);       //Here im using the .sort method of Collections with comparable "see Ticket Class" to sort asc the tickets by cost
                    for (Ticket X : ticketList) {
                        defaultIdList.addElement(X.getTicketID());
                        defaultNameList.addElement(X.getClientName());
                        defaultDateList.addElement(X.getIssueDate());
                        defaultPriceList.addElement(X.getPrice());
                        defaultRouteList.addElement(X.getRoute());            //With this for loop im refreshing the list with the components of the most recent Ticket-Object
                        defaultBagsList.addElement(X.getNumOfBags());
                        defaultLiquidList.addElement(X.getLiquidSubstances());
                        defaultWeightList.addElement(X.getWeight());
                        defaultDevicesList.addElement(X.getElectronicDevices());
                    }
                }
            }
        });

        exitButton.setVerticalAlignment(JButton.CENTER);
        exitButton.setBorder(redBorder);
        exitButton.setBackground(Color.DARK_GRAY);
        exitButton.setForeground(Color.white);
        exitButton.setFont(new Font("Arial", Font.BOLD, 16));
        exitButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String[] options = new String[2];
                options[0] = "Yes";
                options[1] = "No";
                int select = JOptionPane.showOptionDialog(newListFrame.getContentPane(), "Go back to the main menu?", "Go Back?", 0, JOptionPane.INFORMATION_MESSAGE, null, options, null);
                if (select == JOptionPane.YES_OPTION) {
                    dispose();
                }
            }
        });

        //Frame
        this.setTitle("Ticket List");
        this.setSize(1250, 340);
        this.setResizable(false);
        this.setLocation(300, 130);
        this.add(titleLabel, BorderLayout.NORTH);
        this.add(mainPanel, BorderLayout.CENTER);
        this.add(buttonPanel, BorderLayout.EAST);
        this.add(statisticsPanel, BorderLayout.SOUTH);
        this.setIconImage(titleImage.getImage());
        this.getContentPane().setBackground(Color.darkGray);    //changing the background color.

        this.setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
        this.setVisible(true);

    }

    private float getTotalCost() {
        float totalCost = 0;
        for (Ticket X : ticketList)                 //Im using for loop to find the Total cost of all tickets.
            totalCost += X.getPrice();                 // "for all Tickets in ticket list total cost += ticket(X).getPrice" simplified
        return totalCost;
    }

    private void initializeStatisticsUI() {
        //Changing the text of the labels in order to refresh
        if (ticketList.isEmpty()) {
        }                                         //In order to protect the program from crashing I've inserted an if here so this function runs only when the ticketList is not empty.
        else {
            totalTicketLabel.setText("Ticket Counter: " + ticketList.size());
            totalCostLabel.setText("Total Ticket cost: " + getTotalCost());

            Ticket mostExpensiveTicket = ticketList.stream().max(Comparator.comparingDouble(Ticket::getPrice)).get();   //So here I take a ticket object and by using the ticketList method ".stream.max" im getting the
            Ticket cheapestTicket = ticketList.stream().min(Comparator.comparingDouble(Ticket::getPrice)).get();           // most Expensive Ticket  from the ticket Object
            //Same exact thing happens for the cheapestTicket
            expensiveTicketLabel.setText("Most Expensive Ticket: " + mostExpensiveTicket.getPrice() + " ID: " + mostExpensiveTicket.getTicketID());
            cheapTicketLabel.setText("Most Affordable Ticket:" + cheapestTicket.getPrice() + " ID: " + cheapestTicket.getTicketID());              //And then I'm updating my labels using the TicketObj getters.
        }
    }
}
