#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <mpi.h>
#include <string.h>

int main(int argc, char ** argv) {
    int processes_num;
    int my_rank;
    int arraysize;
    int i, j;
    int *input;
    int *new_array;
    int *new_array_chunk;
    int *recv_data;
    int temp;
    int nline;
    int* return_data;
    int* return_max;
    int* return_min;
    int* return_min_pos;
    srand(time(NULL));

    MPI_Init( &argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &processes_num);

    if (my_rank == 0) { 
        //Root process code
        printf("Give Matrix length >>> \n");
        scanf("%i", &arraysize);
        temp = arraysize % processes_num; //Stores the result of n modulo size in temp
        nline=arraysize/processes_num;
        if (temp != 0) { //Checks if the values are divisible
            fprintf(stderr,"\n not divisible\n");
            MPI_Abort(MPI_COMM_WORLD, 1); //terminates the program with segmentation fault 1
        }
        // Matrix initialization 
        input = (int*)malloc(((arraysize*arraysize)) * sizeof(int));
        for (i = 0; i < arraysize*(arraysize); i++) {
            if (input == NULL)
                return 1;
            input[i] =rand() %10; //random numbers 1-10
                    if (rand() % 2) {
                        input[i] = input[i] * (-1);
                    }
            }    

        //this is for testing purposes and evaluates to 'yes'
       /*int A[16]={15,2,3,4,2,123,2,3,1,2,123,2,1,2,3,123};*/
        /*input=A;*/

        printf("\nMatrix is:");
        for (i = 0; i < arraysize; i++) {
            printf("\n");
            for (j = 0; j < arraysize; j++)
                printf("%d ", input[i*arraysize+j]);
        }
        printf("\n");
    } 

    int root = 0;
    //broadcasting arraysize and nline values 
    MPI_Bcast(&arraysize, 1, MPI_INT, root, MPI_COMM_WORLD);
    MPI_Bcast(&nline, 1, MPI_INT, root, MPI_COMM_WORLD);


    //initializing proccess chunk
    recv_data= (int *)malloc(arraysize*arraysize*sizeof(int));
    bzero(recv_data,arraysize*arraysize);
    if (recv_data == NULL)
            return 1;

    //scattering matrix elements to processes 
    if(my_rank==root)
        {
            return_data=(int*)malloc(processes_num*sizeof(int));
        }
    MPI_Scatter(input, arraysize, MPI_INT , recv_data , arraysize , MPI_INT , root , MPI_COMM_WORLD);


    int* flag=malloc(sizeof(int));
    *flag=1;

    //caluclating if the matrix is strinclty diagonally dominant
	for(int j=0;j<nline;j++)
		{
			int sum=0;
			int diag=abs(recv_data[nline*my_rank+j]);
            //summarizing matrix values except diagonal
			for(int i=0;(i<arraysize);i++)
				{
					if(recv_data[i]==diag)
						continue;
					else
						sum+=abs(recv_data[i]);
				}
            //checking if diagonal is greater than the sum
            //and returning according flag
			if(diag>=sum)
                *flag=(1 && flag);
			else 
                {
                    *flag=0;
                    break;
                }
		}

    //gathering return values from processes into return_data array
    MPI_Gather(flag,1,MPI_INT,return_data,1,MPI_INT,root,MPI_COMM_WORLD);

    //printing final result
    int final_result=1;
    if(my_rank==root)
        {
            for(int k=0;k<processes_num;k++)
                {
                    final_result=(final_result && return_data[k]);
                }
            printf("\nTask A result is: %s\n",(final_result?"yes":"no"));
            /*printf("final_result %i",final_result);*/
            if(!final_result)
                {
                    printf("\nIncorrect Matrix!!!");
                }
        }
        MPI_Bcast(&final_result, 1, MPI_INT, root, MPI_COMM_WORLD);

        //if matrix is not diagonally dominant gracefully exiting
            if(!final_result)
                {
                    MPI_Finalize();
                    exit(1);
                }

        //if  matrix is diagonally dominant
            //compute the max of the diagonal elements
            int* max=malloc(sizeof(int));
            int u=0;
            do{
                    int diag=abs(recv_data[nline*my_rank+j]);
                    if(u==0)
                        *max=diag;
                    else
                        if(*max<diag)
                            *max=diag;
                    u++;
            }while(u<processes_num);

        if(my_rank==root)
            {
                return_max=(int*)malloc(processes_num*sizeof(int));
            }
        //gathering max value from  proccesses into return_max array
        MPI_Gather(max,1,MPI_INT,return_max,1,MPI_INT,root,MPI_COMM_WORLD);
        int final_max;
        //computing total max
        if(my_rank==root)
            {
            int t=0;
            do{
                    if(t==0)
                        final_max=return_max[t];
                    else
                        if(final_max<return_max[t])
                            final_max=return_max[t];
                    t++;
            }while(t<processes_num);
            //printing result
            printf("\nTask B result is: %i\n",(final_max));
            

            //initializing new array here because we want to be on root
            new_array = (int*)malloc((arraysize*arraysize) * sizeof(int));
            }
        //broadcasting final max value
        MPI_Bcast(&final_max, 1, MPI_INT, root, MPI_COMM_WORLD);
        //intializing new chunks for the new array
        new_array_chunk= (int *)malloc(arraysize*sizeof(int));

        //calulating new element values accoring to the given formula
        //and storing them in the new chunk
            for(int j=0;j<nline;j++)
                {
                    for(int i=0;(i<arraysize);i++)
                        {
                            if(i==(nline*my_rank+j))
                                new_array_chunk[i]=final_max;
                            else
                                new_array_chunk[i]=final_max-abs(recv_data[i]);
                        }
                }

       //gathering all new chunks into the new array 
        MPI_Gather(new_array_chunk,arraysize,MPI_INT,new_array,arraysize,MPI_INT,root,MPI_COMM_WORLD);
        if(my_rank==root)
            {
                //printing the result
                printf("\nTask C result is:");
                for (i = 0; i < arraysize; i++) {
                    printf("\n");
                    for (j = 0; j < arraysize; j++)
                        printf("%d ", new_array[i*arraysize+j]);
                }

                printf("\n");
        }

            int* min=malloc(sizeof(int));
            int h=0;
            int* pos=malloc(sizeof(int));
            *pos=0;
            int d=0;
            //calculating min value of proccess chunk and its position relative to the 
            //proccess's  chunk start
            do{
                for(int y=0;y<arraysize;y++)
                    {
                        if(d==0)
                            *min=new_array_chunk[y];
                        else
                            if(*min>new_array_chunk[y])
                                {
                                    *min=new_array_chunk[y];
                                    *pos=h*nline*arraysize+y;
                                }
                    d=1;
                    }
                    h++;
            }while(h<nline);


        //intializing memory for results from processes and the corresponding positions
        if(my_rank==root)
            {
                return_min=(int*)malloc(processes_num*sizeof(int));
                return_min_pos=(int*)malloc(processes_num*sizeof(int));
            }

        //gathering min values into return_min
        MPI_Gather(min,1,MPI_INT,return_min,1,MPI_INT,root,MPI_COMM_WORLD);
        //gathering positions into return_min_pos
        MPI_Gather(pos,1,MPI_INT,return_min_pos,1,MPI_INT,root,MPI_COMM_WORLD);

        //calculating total minimum
        if(my_rank==root)
            {
        int final_min;
        int proc_pos=0;
            int g=0;
            do{
                    if(g==0)
                        final_min=return_min[g];
                    else
                        if(final_min>return_min[g])
                            {
                                proc_pos=g;
                                final_min=return_min[g];
                            }
                    g++;
            }while(g<processes_num);

            printf("\nTask D result is:\n");
            //calculcating final absolute positions
            int final_pos=proc_pos*arraysize+return_min_pos[proc_pos];

            //printing results
            printf("final_min is:%i\n",final_min);
            printf("position is:%i\n",final_pos);

        }

    MPI_Finalize();
    return 0;
}
