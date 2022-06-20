#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void helloThread(void *);

int main (int argc, char **argv) {
    pthread_t thread1;
    if ( pthread_create(&thread1, NULL, (void *)&helloThread, NULL) != 0 ) { //? Creates a new thread and checks for Errors
        printf("Error while creating thread1 \n");
        exit(1);
    }
    pthread_join(thread1, NULL); //? Main thread waits for thread1 to finish.

    printf("main: World \n"); //? After thread1 finishes main thread prints it's message.
    return 0;
}
void helloThread(void *none) {
    printf("Thread: Hello, the value of my ID is >> ' %d ' \n", pthread_self()); //? Thread uses pthread_self() to get it's ID.

}