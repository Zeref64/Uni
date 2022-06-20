#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <mpi.h>

int main(int argc, char ** argv) {
    int processes_num;
    int my_rank;
    int arraysize;
    int i, j;
    int *input;
    int temp;
    int tag = 64;
    //int element1;
    //float *delta;
    int local_sum = 0;
    //int min, max, max_min = 0;
    float avg, var, local_var, endvar = 0;
    int num_of_elements;
    srand(time(NULL));

    MPI_Status status;

    MPI_Init( & argc, & argv);
    MPI_Comm_rank(MPI_COMM_WORLD, & my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, & processes_num);

    //TODO do while (MENU)
    if (my_rank == 0) { //Root process code
        float sum = 0;
        printf("Give vector length >>> \n");
        scanf("%i", & arraysize);
        temp = arraysize % processes_num; //Stores the result of n modulo size in temp
        if (temp != 0) { //Checks if the values are divisible
            printf("\nVector not divisible\n");
            MPI_Abort(MPI_COMM_WORLD, 1); //terminates the program with segmentation fault 1
        }
        num_of_elements = arraysize / processes_num; //The number of elements each process will calculate.
        printf("Each process will calculate <%i> Elements.\n\n", num_of_elements);
        input = (int *) malloc(arraysize * sizeof(int)); //Allocating array for root process '0'
        if (input == NULL)
            return 1; //checking malloc null pointer exeption
        printf("'Process %i' Array >>\n", my_rank);
        for (i = 0; i < arraysize; i++) {
            // printf ("Give value for number %i: \n",i+1);
            //scanf ("%i", &in);                                 'alternative input method'
            *(input + i) = rand() % 63 + 1; //pseudo-random numbers 1-64
            printf("Element [%i] -> %i\n",i, *(input + i));
        }
        printf("--- Array of [%d] elements completed. ---\n\n", arraysize);

        for (j = 1; j < processes_num; j++) { //This loop is the 'communicator'
            MPI_Send( &arraysize, 1, MPI_INT, j, tag, MPI_COMM_WORLD); //I'm sending the array-size 'n' so the processes can alocate an array.
            MPI_Send(input, arraysize, MPI_INT, j, tag, MPI_COMM_WORLD); //sending the array/data to all the processes 1 by 1.
            printf("Root %i: Sending data to Process '%i'. \n\n", my_rank, j);

            MPI_Recv( & local_sum, 1, MPI_INT, j, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE); //Recieves all the calculated data from all the process 1 by 1.
            printf("Root '%i': Recieved data from process '%i'. \n", my_rank, j);
            printf("Data received: local_sum  updated -> %i,\n\n", local_sum); //every process is updating the local_sum variable
        }
        sum += local_sum; //Adding local_sum to sum (root 0 variable). Finished gathering all data.
        printf("--- Data collected. ---\n\n");
        
        for (i = 0; i < num_of_elements; i++) { //Root process '0' is calculating his given number of elements.
            printf("Adding '%i' to Sum counter\n", *(input + i));
            sum += * (input + i); //Adding to sum.
        }
        printf("Sum Counter = %.3f\n", sum);
        printf("Dividing by %i..\n\n", arraysize);
        avg = sum / arraysize; // Doing the division and printing
        printf("/--- Result >>> Avg = %.3f ---/\n\n", avg);  

    } else { //Entering the non root process code (rank != 0)
        MPI_Recv( & arraysize, 1, MPI_INT, 0, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE); //Recieves the arraysize from root 
        input = (int * ) malloc(arraysize * sizeof(int)); //allocates an array of arraysize Int elements 
        if (input == NULL)
            return 1; // checking if malloc was successful.
        MPI_Recv(input, arraysize, MPI_INT, 0, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE); //Recieves the data from process 0 and saves it to the array.

        //for (j=0; j<arraysize; j++)
        //printf ("Process %i number %i = %i\n",my_rank, j+1, *(input + j));        //Prints the contents of the array
        num_of_elements = arraysize / processes_num; //calculates the number of elements that are going to be processed by this process.
        for (i = num_of_elements; i < num_of_elements * (my_rank + 1); i++) //This loop is used to calculate the given elements of this process and then sends them back to root.
            local_sum += * (input + i); //It starts from the given number of elements that this process is given to calcilate because root will calculate the previous elements.
        MPI_Send( & local_sum, 1, MPI_INT, 0, tag, MPI_COMM_WORLD); // and it goes up to the elements that this process is going to calculate so never 2 processes are going to calc the same elements

    }

    if (my_rank == 0) { //Starting a new if else statement for (b)
        for (j = 1; j < processes_num; j++) {   //Sending the avg to all the processes
            MPI_Send(&avg, 1, MPI_FLOAT, j, tag, MPI_COMM_WORLD);
            printf("Root %i: Sending data to process '%i'. \n\n", my_rank, j);

            MPI_Recv(&local_var, 1, MPI_FLOAT, j, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE); //receiving the processed data.
            printf("Data received: local_Var updated -> %.3f,\n\n", local_var);
        }

        printf("--- Data collected. ---\n\n");
        var += local_var;   //Adding to this variable

        for (i = 0; i < num_of_elements; i++) {
            printf("Adding '%.3f' to Var counter\n", pow((*(input + i) - avg), 2)); 
            var += pow((*(input + i) - avg), 2);    //Processing root's elements and adding them
        }
        printf("Var Counter = %.3f\n", var);
        printf("Dividing by %i..\n\n", arraysize);
        endvar = var / arraysize;   //doing the division and printing
        printf("/--- Result >>> Var = %.3f ---/\n\n",endvar);

        free(input);
    } else {
        MPI_Recv(&avg, 1, MPI_FLOAT, 0, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE); //receives avg from root
        for (i = num_of_elements; i < num_of_elements * (my_rank + 1); i++) //same for loop as above
            local_var += pow((*(input + i) - avg), 2);  //calculation of the given elements
        MPI_Send(&local_var, 1, MPI_FLOAT, 0, tag, MPI_COMM_WORLD); // sending the updated data
        
        free(input);
    }

/*                  // Scrapped code for 3rd task.
    if (my_rank == 0){
        delta = (float *) malloc(arraysize * sizeof(float));
        if (delta == NULL)
            return 1;
        min = *(input);
        max = *(input);
        for (i = 1; i < arraysize; i++){
            if (*(input + i) > max)
                max = *(input + i);
            else if (*(input + i) < min)
                min = *(input + i);
        }
        for (j = 0; j < processes_num; j++){
            MPI_Send(&min, 1, MPI_INT, j, tag, MPI_COMM_WORLD);
            MPI_Send(&max, 1, MPI_INT, j, tag, MPI_COMM_WORLD);

            MPI_Recv(delta, arraysize, MPI_FLOAT, 0, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }

        for (i = 0; i < arraysize; i++){

           //*(delta + i) = ( (*(input + i) - min) /  max_min * 100 );
           printf("Delta[%i]= %.3f\n",i, *(delta + i));
        }

        //free(input); //De-allocating memory for process 0.
        //free(delta);

    } else {
        MPI_Recv(&min, 1, MPI_INT, 0, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&max, 1, MPI_INT, 0, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        delta = (float *) malloc(arraysize * sizeof(float));

        max_min = max - min;
        for (i = num_of_elements; i < num_of_elements * (my_rank + 1); i++){
            element1 = *(input + i) - min;
            *(delta + i) = ((element1 / max_min) * 100);
           // printf("delta %i = %.3f\n",i,*(delta+i));
        }
        MPI_Send(delta, arraysize, MPI_FLOAT, 0, tag, MPI_COMM_WORLD);

        //free(input); //de-allocating memory for this process
    }*/
    MPI_Finalize();
    return 0;
}