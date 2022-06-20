#include <stdio.h>
#include <pthread.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <semaphore.h>

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_barrier_t our_barrier;
int max_glob=0;
int* RETURN_ARRAY;
int N=0;

typedef struct store
	{
		int* array;
		int n;
	}store;



void* get_max_num(void* pass)
	{


		store* temp=(store*) pass;
		int res=*(temp->array);
		for(int j=0;j<temp->n;j++)
			{
				if(temp->array[j]>res)
					res=temp->array[j];
			}

		printf("reporting local sum %i\n",res);

		pthread_mutex_lock( &mutex1 );
		if(res>max_glob)
			max_glob=res;
		pthread_mutex_unlock( &mutex1 );

		pthread_barrier_wait(&our_barrier);

		pthread_mutex_lock(&mutex1);

		RETURN_ARRAY=realloc(RETURN_ARRAY,(N+1)*(temp->n)*sizeof(int));
		for(int j=0;j<temp->n;j++)
			{
			printf("number is %i\n",temp->array[j]);
			printf("dist is %i\n",abs(max_glob-temp->array[j]));
				RETURN_ARRAY[((N)*temp->n)+j]=abs(max_glob-temp->array[j]);
			}
		N++;

		pthread_mutex_unlock( &mutex1 );


	return NULL;
	};


int main(int argc,char** argv)
	{
		RETURN_ARRAY=(int*)malloc(1);
		int n;
		int NUM_THREADS;
		pthread_t* thread_id=(pthread_t*)malloc(1);
		printf("How many rows will your table have?:");					// Επειδή στην C o πίνακας είναι μονοδιάστατος τον κάνω γραμμικό.
		if(scanf(" %i",&n)!=1)
			{
				fprintf(stderr,"Error reading from stdin! Aborting!\n");
				exit(0);
			}
		n=n*n;
		printf("How many threads would you like to use?:");
		if(scanf(" %i",&NUM_THREADS)!=1)
			{
				fprintf(stderr,"Error reading from stdin! Aborting!\n");
				exit(0);
			}
		pthread_barrier_init(&our_barrier,NULL,NUM_THREADS);						//Φτιάχνω ένα barrier για όσα threads έχω για να ξέρω πως έχουν τελειώσει όλαα το 1ο μέρος τις εργασίας τους.
		thread_id=(pthread_t*) realloc(thread_id,(NUM_THREADS)*sizeof(pthread_t));
		int* NUM_ARRAY=(int*) malloc(n*sizeof(int));
		for(int j=0;j<n;j++)
			{
				printf("Please insert number:");
				if(scanf(" %i",&NUM_ARRAY[j])!=1)
					{
						fprintf(stderr,"Error reading from stdin! Aborting!\n");
						exit(0);
					}
			}
		
		max_glob=*NUM_ARRAY;
		
		int ARRAY_SIZE=n/NUM_THREADS;

		printf("numbers are %i\n",n);
		printf("threads are  %i\n",NUM_THREADS);
		printf("array size is %i\n",ARRAY_SIZE);
		int* ITERATOR=NUM_ARRAY;
		store tmp[NUM_THREADS];
		for(int j=0;j<NUM_THREADS;j++)
			{
				tmp[j].array=malloc(ARRAY_SIZE*sizeof(int));
				memcpy(tmp[j].array,ITERATOR,ARRAY_SIZE*sizeof(int));
				tmp[j].n=ARRAY_SIZE;
				printf("spawning thread no %i\n",j);
				pthread_create(&thread_id[j], NULL,get_max_num,&tmp[j]);		//Δημιουργώ το thread και καλώ την get_max_num.
				ITERATOR+=ARRAY_SIZE;
			}



		for(int j=0;j<NUM_THREADS;j++)
			pthread_join(thread_id[j],NULL);

		int t_row=sqrt(n);
		for(int j=0;j<t_row;j++)
			{
				for(int i=0;i<t_row;i++)
					printf("%i ",RETURN_ARRAY[i+j*(t_row)]);
				printf("\n");
			}

		printf("The overall max is %i\n",max_glob);

	return 0;
	}
