
// client.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char ** argv) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent * server;

    if(argc < 3) {
        fprintf(stderr, "usage %s hostname port\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) 
        error("ERROR: opening socket");

    server = gethostbyname(argv[1]);
    if(server == NULL) {
        fprintf(stderr, "ERROR: no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    printf("Trying to connect...\n");

    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR: connecting");

    printf("Connected!\n");
    int len, choice;
    char buffer[100];
    printf(">>> ");
    scanf("%d", &len);      
    sprintf(buffer, "%d", len);
    printf("buffer %s\n", buffer);
    send(sockfd, buffer, sizeof(buffer), 0);    //send len

    for (int i = 0; i < len; i++){
        int num = 0;
        printf(">>> ");
        scanf("%d", &num);          //send numbers (fill array)
        sprintf(buffer, "%d", num);
        send(sockfd, buffer, sizeof(buffer), 0);
    }

    for (;;) {
        printf("Menu\n\n");
        printf("1. Calculate the Average of Y Array.\n");
        printf("2. Calculate the Min & Max of Y Array.\n");
        printf("3. Calculate the product of ( a * Y[n] )\n");
        printf("4. Exit\n\n");  //menu
        printf(">>> ");
        scanf("%d",&choice);

        sprintf(buffer, "%d", choice);
        send(sockfd, buffer, sizeof(buffer), 0);    //send menu choice
        if (choice == 4) 
            break;
        else if (choice == 3) {
            int a;
            scanf("%d", &a);
            sprintf(buffer, "%d", a);
            send(sockfd, buffer, sizeof(buffer), 0);   
        }
        recv(sockfd, buffer, sizeof(buffer), 0);
        if (choice == 1)
            printf("Average: %s\n", buffer);
        else if (choice == 2)
            printf( "%s\n", buffer);
        else if (choice == 3){
            for (int i = 0; i < len; i++)
            {
                printf( "Result %d = %s\n",i, buffer);
                recv(sockfd, buffer, sizeof(buffer), 0);
            }
            
        }
        
    }
    close(sockfd);
    return 0;
}