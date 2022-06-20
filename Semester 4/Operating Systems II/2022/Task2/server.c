/**
 * @file server.c
 * @author Κούμανης Βασίλειος / 19390104
 * @brief Εργαστήριο ΛΣ 2 / Ασκηση 2 / Ερώτημα C server κομμάτι
 * @date 2022
 * 
 * * bash: clear && gcc -o server server.c -lpthread
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define SOCK_PATH "Fibonnaci_Socket"

int corrSeq; /* Correct Fibonnaci sequence counter. */
pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
sem_t sem;


void* thrFunction(void *arg); /* Thread Function to calculate the Sequence */

int main(){
    int sock, sock2, t, i;
    struct sockaddr_un local, remote;
    pthread_t thread[100];
    
    /* Creating the Server socket. */
    if ((sock = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
            perror("socket");
            exit(1);
    }
    /* Setting the local filepath. */
    local.sun_family = AF_UNIX;
    strcpy(local.sun_path, SOCK_PATH);
    unlink(local.sun_path);
    /*Binding process of the socket and local*/
    if (bind(sock, (struct sockaddr *)&local, 
    sizeof(struct sockaddr_un)) == -1) {
        perror("bind");
        exit(1);
    }
    /* Awaiting for a Client connection. */
    if (listen(sock, 5) == -1) {
        perror("listen");
        exit(1);
    }
    /* Initiallizations of variables */
    i=0;
    corrSeq=0;
    sem_init(&sem,0,0);

    while(i <= 100){ /* Server holds up to 100 Clients */
        printf("Awaiting for connection...\n");
        t = sizeof(remote);
        /* Accepts the connection on 'sock' and returns the connection on 'sock2'. */
        if ((sock2 = accept(sock, (struct sockaddr *)&remote, &t)) == -1) {
            perror("accept");
            exit(1);
        }    
        printf("Connection [%d].\n", i);
        /* Creating a new thread for the new connection that calls the 'thrFunction' with 'sock2'
        as a parameter. */
        pthread_create(&thread[i++], NULL, (void*)&thrFunction, (void*)&sock2);
        sem_wait(&sem); /* Awaits for thread to finish copying 'sock2' */
        printf("Correct Sequences until now: [%d]\n\n", corrSeq);
    }
    
}

void* thrFunction(void *arg){
    int so = *(int*)arg; 
    sem_post(&sem); /* Copies 'sock2' into sem_post. */
    int done, n, i; 
    int fib0, fib1, fib2, fibCl, res; 
    char str[50];

    done = 0;
    do {
        recv(so, &n, sizeof(n), 0); /* Receives N from Client. */
        res=0; fib0=0; fib1=1; /* Initializing variables. */

        for(i=0;i<n;i++){ /* Fibonacci sequence algorithm. */
            fib2 = fib0 + fib1;
            fib0 = fib1; /* fib0 is current fibonacci number. */
            fib1 = fib2;
            /* Receive number from client. */
            recv(so, &fibCl, sizeof(fibCl), 0);
            /* Check if client gave correct Fibonnaci number. */
            if(fibCl != fib0) res = 1;
        }

        if(n<1) /* If user gave negative value or 0 for N. */
            strcpy(str,"Error. N must be greater than 0");
        else if(res==0){ /* If sequence was correct. */
            strcpy(str,"Sequence Correct");
            pthread_mutex_lock(&mut);
            corrSeq++;
            pthread_mutex_unlock(&mut);
        }
        else if(res==1) /* If sequence was false. */
            strcpy(str,"Sequence is False");
        else
            strcpy(str,"Error");
        send(so, str, 50, 0);
        /* Receive from client response if he wants to repeat. */
        recv(so, &done, sizeof(done), 0);
    } while (!done);

    close(so); /* Closing socket connection. */
    pthread_exit(NULL);
}