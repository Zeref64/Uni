#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <netinet/in.h>

#include <string.h>

int main(int argc, char *argv[]) {
   int init_flag=1;
   for(;;)     // Αν δεν είναι η πρώτη φορά ελέγχω με init flag τότε ρωτάω τον χρήστη ναν θέλει να στείλει και άλλο μήνυμα.
      {
      char option;
      if(!init_flag)
         {
            printf("would you like to send another serquence (y/n)?");
            scanf(" %c",&option);
            if(option=='n')
               break;
         }
      else
         init_flag=0;

   int sockfd, portno, n;           //init τις μεταβλητές για την σύνδεση με τον server.
   struct sockaddr_in serv_addr;
   struct hostent *server;
   
   //Για να επικοινωνίσουμε θα πρέπει να έχουμε συμφωνίσει σε ενα segment size θα μπορουσαμε να κανουμε ενα αλλο connection αλλα για λογω παραδειγματος βαζω 64
   
   char buffer[256];
   int buffer_i[64];
   
   if (argc < 3) {
      fprintf(stderr,"usage %s hostname port\n", argv[0]);
      exit(0);
   }
                                 // Διαβάζω απο τις παραμέτρους του προγράμματος τον host και port.
   portno = atoi(argv[2]);
   
   /* Create a socket point */
   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   
   if (sockfd < 0) {
      perror("ERROR opening socket");
      exit(1);
   }
	
   server = gethostbyname(argv[1]);
   
   if (server == NULL) {
      fprintf(stderr,"ERROR, no such host\n");
      exit(0);
   }
   
   bzero((char *) &serv_addr, sizeof(serv_addr));
   serv_addr.sin_family = AF_INET;
   bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
   serv_addr.sin_port = htons(portno);


   /* Now connect to the server */
   if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
      perror("ERROR connecting");
      exit(1);
   }
   


   /* Now ask for a message from the user, this message     Ρωτάω πόσους αριθμούς θέλει να στείλει και διαβάζω τους σε βάζω buffer και τους "γράφω στο socket".
      * will be read by server
   */
   
   int num_count;          
   printf("How many numbers would you like to send (63 max)?");
   scanf(" %i",&num_count);

   for(int j=0;j<64;buffer_i[j++]=0);
   for(int j=0;j<63 && j<num_count;j++)
         {

         printf("Please enter the message: ");
         
         scanf(" %i",&buffer_i[j]);
         }
   buffer_i[63]=num_count;


   
   /* Send message to the server */
   printf("message is");
   for(int j=0;j<64;j++)
      printf("%i\n",buffer_i[j]);

   n = write(sockfd, (char*)buffer_i, 256);
   
   if (n < 0) {
      perror("ERROR writing to socket");
      exit(1);
   }
   
   /* Now read server response */
   bzero(buffer,256);
   n = read(sockfd, buffer, 255);
   
   if (n < 0) {
      perror("ERROR reading from socket");
      exit(1);
   }
	
   printf("%s\n",buffer);        // Διαβάζω την απάντηση του server. 
   }

   return 0;

}
