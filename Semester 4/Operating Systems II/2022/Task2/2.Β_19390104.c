/**
 * @file 2.Β_19390104.c
 * @author Κούμανης Βασίλειος / 19390104
 * @brief Εργαστήριο ΛΣ 2 / Ασκηση 2 / Ερώτημα Β
 * @date 2022
 * 
 * *bash: clear && gcc -o 2Bexecutable 2.Β_19390104.c -lpthread
 */

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t sem1;
sem_t sem2;
sem_t sem3;

void *thread1(void*);
void *thread2(void*);
void *thread3(void*);

int main() {
pthread_t t1, t2, t3;
/**
 * * Semaphore initialization
 * ? Sem1 starts at 1
 * ? Sem2 & Sem3 start at 0
 */
sem_init(&sem1, 0, 1);	
sem_init(&sem2, 0, 0);
sem_init(&sem3, 0, 0);

pthread_create(&t1, NULL, thread1, NULL);
pthread_create(&t2, NULL, thread2, NULL);
pthread_create(&t3, NULL, thread3, NULL);
pthread_join(t1, NULL);
pthread_join(t2, NULL);
pthread_join(t3, NULL);
}

void *thread1(void *arg) { // First print to be executed
	while(1){ // At beginning sem1 is 1
	sem_wait(&sem1); // Wait until sem1>0, then sem1--
	printf("What A ");
	sem_post(&sem2); // sem2++
	}
}

void *thread2(void *arg) { // Second print
	while(1){ // At beginning sem2 is 0
	sem_wait(&sem2); // Wait until sem2>0, then sem2--
	printf("Wonderful ");
	sem_post(&sem3); // sem3++
	}
}

void *thread3(void *arg) { // Third print
	while(1){ // At beginning sem3 is 0
	sem_wait(&sem3); // Wait until sem3 >0, then sem3--
	printf("World! ");
	sem_post(&sem1); // sem1++
	} //print1 executes next
}
