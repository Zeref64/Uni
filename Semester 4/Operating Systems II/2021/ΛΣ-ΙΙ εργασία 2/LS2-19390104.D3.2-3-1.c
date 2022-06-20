#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>

   int sockfd, newsockfd, portno, clilen;
   char buffer[256];
   struct sockaddr_in serv_addr, cli_addr;
   int  n,pid;
   

void log_connection()      //καταγράφω τις συνδέσεις
   {
      FILE* file=fopen("./connection_log","rw+");
      if(file==NULL)
         fprintf(stderr,"ERROR OPENING LOG FILE\n");

      int tmp_count;
      fscanf(file,"%i",&tmp_count);
      fseek(file,0L,SEEK_SET);
      fprintf(file,"%i",tmp_count+1);
      fclose(file);
   }

void log_check_successful(void)        //Καταγράφω τους επιτυχεις ελέγχους.
   {
      FILE* file=fopen("./success_log","rw+");
      if(file==NULL)
         fprintf(stderr,"ERROR OPENING LOG FILE\n");

      int tmp_count;
      fscanf(file,"%i",&tmp_count);
      fseek(file,0L,SEEK_SET);
      fprintf(file,"%i",tmp_count+1);
      fclose(file);
   }

void worker()           //Αυτή είναι η κύρια συναρτηση που απαντάει στον client.

{
   
   /* If connection is established then start communicating */
   bzero(buffer,256);
   n = read( newsockfd,buffer,255 );         //Διαβάζω το μήνυμα του client οπου στην τελευταία θέση περιέχει το πλήθος των αριθμών.

   int* t=(int*)buffer;
   int num_count=t[63];
   
   if (n < 0) {
      perror("ERROR reading from socket");
      exit(1);
   }

   float sum=0;
   for(int j=0;j<num_count;j++)              //Υπολογισμός Μ.Ο.
      {
         sum+=t[j]; 
         printf("Here is the message: %i\n",t[j]);
      }

   float mo;
   mo=(num_count!=0?sum/num_count:0);

   

   if(mo>10)
   {
   
   /* Write a response to the client */
   n = write(newsockfd,"SEQUENCE OK!",18);
   log_check_successful();
   }

   else
   {
   
   /* Write a response to the client */
   n = write(newsockfd,"CHECK FAILED",18);
   }
 

   
   if (n < 0) {
      perror("ERROR writing to socket");
      exit(1);
   }
}

int main( int argc, char *argv[] ) {
   
/* First call to socket() function */        //Δημιουργώ το socket.
   FILE* file=fopen("./success_log","rw+");
      if(file==NULL)
         fprintf(stderr,"ERROR OPENING LOG FILE\n");

      int tmp_count = 0;
      fseek(file,0L,SEEK_SET);
      fprintf(file,"%i",tmp_count);
      fclose(file);

      FILE* file=fopen("./connection_log","rw+");
      if(file==NULL)
         fprintf(stderr,"ERROR OPENING LOG FILE\n");

      int tmp_count = 0;
      fseek(file,0L,SEEK_SET);
      fprintf(file,"%i",tmp_count);
      fclose(file);
   sockfd = socket(AF_INET, SOCK_STREAM, 0);      
   
   if (sockfd < 0) {
      perror("ERROR opening socket");
      exit(1);
   }
   
   /* Initialize socket structure */
   bzero((char *) &serv_addr, sizeof(serv_addr)); 
   portno = 8000;
   
   serv_addr.sin_family = AF_INET;
   serv_addr.sin_addr.s_addr = INADDR_ANY;        //socket init.
   serv_addr.sin_port = htons(portno);
   
   /* Now bind the host address using bind() call.*/
   if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
      perror("ERROR on binding");
      exit(1);
   }
      
   /* Now start listening for the clients, here process will
      * go in sleep mode and will wait for the incoming connection
   */

   
   listen(sockfd,5);          //Ακούω στο socket για μηνύματα.
   clilen = sizeof(cli_addr);
   for(;;)        //Κάνω accept το connection του client.
         {
   
   /* Accept actual connection from the client */
   newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
   if (newsockfd < 0) {
      perror("ERROR on accept");
      exit(1);
   }
   else
      log_connection();
	
        /* Create child process */
      pid = fork();                 //Κάνω fork για να επιτρέψω ταυτόχρονες συνδέσεις.

      if (pid < 0) {
         perror("ERROR on fork");
         exit(1);
      }

      if (pid == 0) {
         /* This is the client process */             //εκτελώ την worker για να κάνει τηην δουλειά μου.
         close(sockfd);          //Και τερματίζω το socket.
         worker();
         exit(0);
      }
      else {
         close(newsockfd);
      }





         }
      
   return 0;
}
