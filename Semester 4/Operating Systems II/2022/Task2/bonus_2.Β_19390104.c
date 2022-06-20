/**
 * @file bonus_2.Β_19390104.c
 * @author Κούμανης Βασίλειος / 19390104
 * @brief Εργαστήριο ΛΣ 2 / Ασκηση 2 / Ερώτημα Β Bonus
 * @date 2022
 * 
 * * bash: clear && gcc -o bonus-2Bexecutable bonus_2.Β_19390104.c -lpthread
 */

#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock;// mutex which we are going to use avoid race condition.
// Declaration of thread condition variables
pthread_cond_t cond1;
pthread_cond_t cond2;
pthread_cond_t cond3;

void *print1(void*);
void *print2(void*);
void *print3(void*);
int number = 1; // Determines the thread that is going to run

int main()
{
        pthread_t  t1, t2, t3;
        int arg1 = 1, arg2 = 2, arg3 = 3;
    
        // Create 3 threads 
        pthread_create(&t1, NULL, print1, NULL);
        pthread_create(&t2, NULL, print2, NULL);
        pthread_create(&t3, NULL, print3, NULL);
    
		// main waiting threads
		pthread_join(t1,NULL);
		pthread_join(t2,NULL);
		pthread_join(t3,NULL);
}

void *print1(void *arg1){
    while(1){
        // if number!=1 wait pthread_cond_signal(&cond1) in print3
        pthread_mutex_lock(&lock);
        if(number!=1){
            pthread_cond_wait(&cond1,&lock);}
        pthread_mutex_unlock(&lock);

        printf("What A ");
        // signal print2 to continue
        number=2;
        pthread_cond_signal(&cond2);
    }
}
void *print2(void *arg2){
    while(1){
        // if number!=2 wait pthread_cond_signal(&cond2) in print1
        pthread_mutex_lock(&lock);
        if(number!=2){
            pthread_cond_wait(&cond2,&lock);}
        pthread_mutex_unlock(&lock);

        printf("Wonderful ");
        // signal print3 to continue
        number=3;
        pthread_cond_signal(&cond3);
    }
}
void *print3(void *arg3){
    while(1){
        // if number!=3 wait pthread_cond_signal(&cond3) in print2
        pthread_mutex_lock(&lock);
        if(number!=3){
            pthread_cond_wait(&cond3,&lock);}
        pthread_mutex_unlock(&lock);

        printf("World! ");
        //signal print1 to continue
        number=1;
        pthread_cond_signal(&cond1);
    }
}