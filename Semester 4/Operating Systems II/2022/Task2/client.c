/**
 * @file client.c
 * @author Κούμανης Βασίλειος / 19390104
 * @brief Εργαστήριο ΛΣ 2 / Ασκηση 2 / Ερώτημα C client κομμάτι
 * @date 2022
 * 
 * * bash: clear && gcc -o client client.c 
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SOCK_PATH "Fibonnaci_Socket"

int main(){
    int sock, done, n, i, tmp, t;
    struct sockaddr_un server;
    char str[50];
    /* Creating the Client socket. */
    if ((sock = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }
    /* Initializing server filepath. */
    server.sun_family = AF_UNIX;
    strcpy(server.sun_path, SOCK_PATH);
    /* Innitializing socket Connection. */
    if (connect(sock, (struct sockaddr *)&server, 
    sizeof(struct sockaddr_un)) == -1) {
        perror("connect");
        exit(1);
    }
    /* Starting message for Client that shows the instructions. */
    printf("Connection Established.\n");
    printf("Client has to give input of N values,\n");
    printf("the server will respond if the values given are\n");
    printf("are the first N numbers of the Fibonacci sequence.\n\n");
    
    done=0;
    do{
        /* Ask user to input the num of Values */
        printf("Input the number of values (N) >>> "); 
        scanf("%i",&n);
        /* Send user input to server. */
        send(sock, &n, sizeof(n), 0);
        /* Asks user to input N numbers. */
        for(i=0;i<n;i++){
            printf("Value [%i] -> ", i+1); 
            scanf("%i",&tmp);
            send(sock, &tmp, sizeof(tmp), 0);
        }
        /* Receive the response from the server. */
        t = recv(sock, str, 50, 0);
        str[t]='\0';
        printf("\nServer Response >> %s\n\n",str);
        /* Asks the user if he wants to repeat the process. */
        printf("\t[ Try again ? ] \n0 -> 'Yes'\tOther-> 'No'\n\nInput >>> ");
        scanf("%i",&done);
        send(sock, &done, sizeof(done), 0);
    }while(!done);
}