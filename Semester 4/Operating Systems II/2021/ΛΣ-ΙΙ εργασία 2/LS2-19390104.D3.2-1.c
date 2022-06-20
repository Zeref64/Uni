#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

sem_t mutex1;
sem_t mutex2;			//Δημιουργώ 3 σημαφόρους 
sem_t mutex3;

void* one(void* arg)
	{
		for(int j=0;j<5;j++)
			{
		sem_wait(&mutex1);			// Καλεί τον mutex1 εκτυπώνει και ύστερα καλεί τον mutex2
		printf("<ONE>");
		sem_post(&mutex2);
		}
	return (void*)0;
	}

void* two(void* arg)
	{
		for(int j=0;j<5;j++)
			{
		sem_wait(&mutex2);			//Απο την προηγούμενη συνάρτηση κλήθηκε ο mutex2 και εμφανίζει two
		printf("<TWO>");
		sem_post(&mutex3);		//καλεί τον 3ο
		}
	return (void*)0;
	}

void* three(void* arg)
	{
		for(int j=0;j<5;j++)
			{
				sem_wait(&mutex3);
				printf("<THREE>");				
				sem_post(&mutex1);		//ξανακαλει τον πρώτο. Αυτό θα το κανει 5 φορές "Οσο είναι η for" 
			}
	return (void*)0;
	}


int main(int argc,char** argv)
	{
		sem_init(&mutex1,0,0);
		sem_init(&mutex2,0,0);
		sem_init(&mutex3,0,0);

		pthread_t t1;
		pthread_t t2;
		pthread_t t3;
		
		/*for(int j=0;j<5;j++)*/
			/*{*/
				pthread_create(&t1,NULL,one,NULL);
				pthread_create(&t2,NULL,two,NULL); 		
				pthread_create(&t3,NULL,three,NULL);

				sem_post(&mutex1);			//Καλώ τον πρώτο σημαφόρο για να ξεκινήσει η εκτέλεση. 

				pthread_join(t1,NULL);
				pthread_join(t2,NULL);			//Τερματίζω τα thread
				pthread_join(t3,NULL);
			/*}*/


	}
