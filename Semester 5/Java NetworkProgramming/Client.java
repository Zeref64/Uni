package Server_Client;

import java.io.*;
import java.net.Socket;
import java.util.Scanner;

public class Client {

    public static void main(String[] args) {

        //Initializing connection
        Socket socket = null;
        String hostname ="127.0.0.1"; // Connecting on my PC
        int port = 5000;

        try {
            //Connecting to server...
            System.out.println("Connecting to Server at port 5000...");
            socket = new Socket(hostname,port);
            Scanner userInput = new Scanner(System.in);
            PrintWriter writer = new PrintWriter(socket.getOutputStream(), true);
            Scanner reader = new Scanner(socket.getInputStream());

            //Consume welcome message
            String welcome = reader.nextLine();
            System.out.println("System: Connection established\n");
            System.out.println("Server: " + welcome);

            String outLine;
            String inLine;

            //Action menu:
            //This loop will run until User types 'exit'.
            do {
                System.out.print("\nSystem: Enter the action you want to perform: ");
                System.out.print("\n'6' To show info about one entry.\n'7' To show all entries.\n'exit' to Terminate the connection.\n>>> ");
                outLine = userInput.nextLine();
                writer.println(outLine);//send the input to the server

                /*Im using a switch statement on both sides for the communication protocol based on
                the user input */
                switch (outLine) {
                    case "6":

                        /* If client selected option 6 then
                            Client enters the desired ID and sends it to the server
                            then proceeds to read the data from server
                        */
                        System.out.println("Enter the Account ID: ");
                        outLine = userInput.nextLine(); //Client user input
                        writer.println(outLine);    //Sending the data to server

                        inLine = reader.nextLine(); //read the response from Server
                        System.out.println(inLine);
                        break;
                    case "7":

                        /*If client selected option 7 then
                         Client reads lines until it reaches '\0' char */
                        System.out.println("Fetching all users from server..");
                        while (reader.hasNextLine()) {
                            inLine = reader.nextLine();//read the server's answer
                            if (!( inLine.equals("\0")))
                                System.out.println(inLine); //If data isn't '\0' keep reading
                            else
                                break;
                        }
                        break;
                }
            } while (!outLine.equalsIgnoreCase("exit"));

            //releasing resources
            socket.close();
            writer.close();
            reader.close();
            userInput.close();
            System.out.println("Connection Terminated");
        } catch (IOException ex) {
            System.out.println("Failed to connect");
        }
    }
}
