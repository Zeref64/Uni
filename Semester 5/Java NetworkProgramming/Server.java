package Server_Client;

import java.io.IOException;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.sql.*;
import java.util.Scanner;

/*
    My thought process is to make a server object that contains the connection details and then
    create a method that executes the query I want
 */
public class Server {

    private String jdbcURL = "jdbc:mysql://localhost:3306/bank";
    private String username = "bill";       //This is the default object that has my account
    private String password = "tloz64";     //You  can change this or make another object using the constructor
    private Connection conn = null;
    private Statement st = null;
    private ResultSet rs = null;

    public Server() throws SQLException {
    }

    public Server(String jdbcURL, String username, String password) {
        this.jdbcURL = jdbcURL;
        this.username = username;
        this.password = password;
        this.conn = null;
        this.st = null;
        this.rs = null;
    }

/* Getters and Setters are not used,
    but I included them as comments

    public String getJdbcURL() {
        return jdbcURL;
    }
    public void setJdbcURL(String jdbcURL) {
        this.jdbcURL = jdbcURL;
    }
    public String getUsername() {
        return username;
    }
    public void setUsername(String username) {
        this.username = username;
    }
    public String getPassword() {
        return password;
    }
    public void setPassword(String password) {
        this.password = password;
    }
    public String getQuery() {
        return query;
    }
    public void setQuery(String query) {
        this.query = query;
    }
    public Connection getConn() {
        return conn;
    }
    public void setConn(Connection conn) {
        this.conn = conn;
    }
    public Statement getSt() {
        return st;
    }
    public void setSt(Statement st) {
        this.st = st;
    }
    public ResultSet getRs() {
        return rs;
    }
    public void setRs(ResultSet rs) {
        this.rs = rs;
    }

    The method below is setting up the connection with the Database and
    executes a query  */
    public void databaseConnectionInit(String sqlQuery) {

        try {
            Class.forName("com.mysql.cj.jdbc.Driver"); // Setting up the driver
            // If driver does not exist you have to include it.

            conn = DriverManager.getConnection(jdbcURL, username, password);    //Connecting to the Database

        } catch (ClassNotFoundException ex) {
            System.out.println("Driver class exception " + ex);
        } catch (SQLException ex) {
            System.out.println("Database Connection exception " + ex);
        }

        try {
            st = conn.createStatement();
            rs = st.executeQuery(sqlQuery);    //sending the query to mySQL and executing it.

        } catch (SQLException ex) {
            System.out.println("SQL Statement exception " + ex);
        }
    }


    public static void main(String[] args) throws SQLException {


        int port = 5000;
        ServerSocket serverSocket = null;
        Socket socket = null;
        Server serverObj = new Server(); //Default values "My account and database"
        //Server serverObj = new Server("Your JDBC URL","DB Username","DB Password");


        try {
            serverSocket = new ServerSocket(port);
            System.out.println("Server started on port " + port);   //Starting server

            while (true) {
                socket = serverSocket.accept();
                //Waiting for new client...

                System.out.println("A new client connected");
                PrintWriter writer = new PrintWriter(socket.getOutputStream(), true);
                Scanner reader = new Scanner(socket.getInputStream());

                //send welcome message
                writer.println("Welcome!!");

                String inLine;

                /*Im using a switch statement on both sides for the communication protocol based on
                the user input */
                do {
                    if (reader.hasNextLine()) {
                        inLine = reader.nextLine();
                        System.out.println("Client says: " + inLine);

                        //Sending data specified from the data that Client sent
                        switch (inLine) {
                            case "6":
                                //Here the server is waiting to receive the Account ID from Client
                                System.out.println("Waiting for client to send Data... ");
                                inLine = reader.nextLine();

                                System.out.println("Client requested information for Account ID: " + inLine);
                                // Executes the query
                                serverObj.databaseConnectionInit("SELECT * FROM Customer WHERE AccountID = " + inLine);
                                //Moves the cursor and sends the data
                                if (serverObj.rs.next()) {
                                    System.out.println("Sending information for Account ID '" + inLine + "' to Client...");
                                    writer.printf("|%4s| %-15s| %-15s| %-10s| %-15s| %5s |\n",
                                            serverObj.rs.getString(1), serverObj.rs.getString(2),
                                            serverObj.rs.getString(3), serverObj.rs.getString(4), serverObj.rs.getString(5),
                                            serverObj.rs.getString(6));
                                    break;
                                }else {
                                    System.out.println("Transaction Error - Account not found\n");
                                    writer.println("Transaction Error - Account not found\n");
                                    break;
                                }
                            case "7":
                                System.out.println("Client requested all users");
                                serverObj.databaseConnectionInit("SELECT * FROM Customer"); //Executes the query
                                //Sending all the data
                                while (serverObj.rs.next()) {
                                    writer.printf("|%4s| %-15s| %-15s| %-10s| %-15s| %5s |\n",
                                            serverObj.rs.getString(1), serverObj.rs.getString(2),
                                            serverObj.rs.getString(3), serverObj.rs.getString(4), serverObj.rs.getString(5),
                                            serverObj.rs.getString(6));
                                }
                                writer.println("\0"); //Sending a token in order for the client to know how many lines to read.

                                break;
                        }
                    } else {
                        break;
                    }
                } while (!"exit".equalsIgnoreCase(inLine));
                System.out.println("Client disconnected");
                //Releasing resources.
                socket.close();
                writer.close();
                reader.close();
            }
        } catch (IOException ex) {
            System.out.println("Could not start the Server on port: " + port);
        }
    }
}


