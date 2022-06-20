package Frames;


public class Ticket implements Comparable<Ticket> {

    private long ticketID;
    private String issueDate;
    private String clientName;
    private String route;
    private Float price;
    private int numOfBags;
    private float liquidSubstances;
    private float weight;
    private int electronicDevices;

    // Constructors
    public Ticket() {
    }     //Default

    public Ticket(long ticketID, String clientName, String issueDate, Float price, int numOfBags, String route, float liquidSubstances, float weight, int electronicDevices) {
        this.ticketID = ticketID;
        this.issueDate = issueDate;
        this.clientName = clientName;
        this.route = route;
        this.price = price;                                 //This is the constructor I use to create a ticket object
        this.numOfBags = numOfBags;
        this.liquidSubstances = liquidSubstances;
        this.weight = weight;
        this.electronicDevices = electronicDevices;
    }


    public long getTicketID() {
        return ticketID;
    }

    public void setTicketID(long ticketID) {
        this.ticketID = ticketID;
    }

    public String getClientName() {
        return clientName;
    }

    public void setClientName(String clientName) {
        this.clientName = clientName;
    }

    public String getIssueDate() {
        return issueDate;
    }

    public void setIssueDate(String issueDate) {
        this.issueDate = issueDate;
    }

    public Float getPrice() {
        return price;
    }

    public void setPrice(Float price) {
        this.price = price;
    }

    public int getNumOfBags() {
        return numOfBags;
    }

    public void setNumOfBags(int numOfBags) {
        this.numOfBags = numOfBags;
    }

    public String getRoute() {
        return route;
    }

    public void setRoute(String route) {
        this.route = route;
    }

    public float getLiquidSubstances() {
        return liquidSubstances;
    }

    public void setLiquidSubstances(float liquidSubstances) {
        this.liquidSubstances = liquidSubstances;
    }

    public float getWeight() {
        return weight;
    }

    public void setWeight(float weight) {
        this.weight = weight;
    }

    public int getElectronicDevices() {
        return electronicDevices;
    }                   //Getters & Setters

    public void setElectronicDevices(int electronicDevices) {
        this.electronicDevices = electronicDevices;
    }

    @Override
    public int compareTo(Ticket another) {
        return this.price.compareTo(another.price);     //This is a comparable. I'm using that to sort the ticketList.
    }
}