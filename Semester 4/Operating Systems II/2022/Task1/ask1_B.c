/* Ονοματεπώνυμο: Κούμανης Βασίλειος
ΑΜ: 19390104
Άσκηση 1 ΛΣ ΙΙ */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>

int main(int argc, char **argv) {
    // Process 0
    /*This is the main process, this process ends last.
    printing the bash id and  printing his id*/
    printf ("Current shell ID = %i\n", getppid());
    printf ("P0 ID = %i\n", getpid()); 

    int process0 = fork();
    /*First process gets created here 'P1'*/
    if (process0 == -1)
        exit(1); //Checks if the process was created successfully
    if (process0 == 0) {
        // Process 1
        /*Process 1 prints his ID and parent and then then creates another process the 'grandchild of the main process'*/
        printf("\tP1: This is the process %i with with parent id: %i\n", getpid(), getppid());
        int process1 = fork(); //creating the new process 
        if (process1 == -1)
            exit(1);
        if (process1 == 0) {
            // Process 3
            /*P3 prints his stats and then sends a message with code 22 */
            printf("\t\tP3: This is the process %i with with parent id: %i\n", getpid(), getppid());
            //psignal (22, "hello from your child"); 
            /*About psignal: at first I wanted to set up communication using pipes but I could not make it work, then I tried
            using file descriptors 'dup2' and yet again it was not working so i left that psignal. */
            return 3;
        }
        // Process 1
        int status1;
        waitpid(process1, &status1, 0);
        /*Waits for process 3 to end then ends sending code 1 to the main process. */
        return 1; 
    }
    else { 
        // Process 0
        /*inside this else statement we are again into the main process.
        Main process waits the process P1, P3 to finish P1 can not end before P3 does because of the wait in P1*/
        int status;
        waitpid(process0, &status, 0);
        if ( WIFEXITED(status) ) {
            int exitStatusOf_0 = WEXITSTATUS(status);
            printf("P0: the exit value of P1 is: %d\n", exitStatusOf_0);
            /*Collects P1's status which is the number that P1 returned, in this case P1 returned 1 */ 
            fflush(stdout); //clearing stdout 
        }
        int process2 = fork ();
        /*Parent process creates a child  'brother of P1'*/
        if (process2 == -1)
            exit(1);
        if (process2 == 0) {
            // Process 2
            printf("\tP2: This is the process %i with with parent id: %i\n", getpid(), getppid());
            fflush(stdout);

            int process4 = fork();
            /* Inside P2 we create another process 'grandchild of main process P0' we do the same thing 3 times*/
            if (process4 == -1)
                exit(1);
            if (process4 == 0) {
                // Process 4
                printf("\t\tP4: This is the process %i with with parent id: %i\n", getpid(), getppid());
                fflush(stdout);
                return 4;
            }

            int process5 = fork();
            if (process5 == -1)
            exit(1);
            if (process5 == 0) {
                //Process 5
                printf("\t\tP5: This is the process %i with with parent id: %i\n", getpid(), getppid());
                fflush(stdout);
                return 5;
            }

            int process6 = fork();
            if (process6 == -1)
                exit(1);
            if (process6 == 0) {
                // Process 6
                printf("\t\tP6: This is the process %i with with parent id: %i\n", getpid(), getppid());
                fflush(stdout);
                return 6;
            }
            // Process 2
            /*Process 4,5,6 are children of P2 and grandchildren of P1
            the code below this point is for P2 to halt its execution until 2 or more of its child processes have terminated.
            the method I'm using is that im getting the status of every process and have a counter that gets incremented every time a 
            process ends succsessfully.*/
            int status4,status5,status6, counter=0;

            int endFlag4 = waitpid(process4, &status4, WUNTRACED);
            /*waitpid returns the id of the process that was waiting if the process gets terminated else it returns 0*/
            if ( WIFEXITED(status4) && (endFlag4 > 0) ) { 
                int statusCode = WEXITSTATUS(status4);
                if (statusCode == 4) {
                    printf("4 done\n");
                    counter++; //If everything works counter gets incremented.
                } else {
                    printf("Error in process 4: %d\n",statusCode);
                }
            }
            int endFlag5 = waitpid(process5, &status5, WUNTRACED);
            if ( WIFEXITED(status5) && (endFlag5 > 0) ) {
                int statusCode = WEXITSTATUS(status5);
                if (statusCode == 5) {
                    printf("5 done\n");
                    counter++;
                } else {
                    printf("Error in process 5: %d\n",statusCode);
                    
                }
            }
            int endFlag6 = waitpid(process6, &status6, WUNTRACED);
            if ( WIFEXITED(status6) && (endFlag6 > 0) ) {
                /*I tried using the flag WNOHANG but it did not for the most part*/
                int statusCode = WEXITSTATUS(status6);
                if (statusCode == 6) {
                    printf("6 done\n");
                    counter++;
                } else {
                    printf("Error in process 6: %d\n",statusCode);
                }
            }
            printf("Process that have sucessfully been terminated: %d\n",counter); 
            int statusall;
            int endflag;
            if (counter < 2 )
                while  (endflag= waitpid(-1, &statusall, WUNTRACED) != -1 || errno != ECHILD) {
                    /*this while condition just waits every child */
                    if ( WIFEXITED(statusall) )  {
                    int statusCode = WEXITSTATUS(statusall);
                    printf("Waiting for process: %d with code %d\n",endflag, statusCode);
                    }
                }
            else
                return 2;          
        }
        

        // Process 0
        while  (wait(NULL) != -1 || errno != ECHILD)
        /*before the main process gets terminated it waits for every process*/
            printf("Waiting for P2 to finish\n");
    }
    printf("Process 0 with id: %d and shell id: %d is about to end \nPrinting code to the screen:\n\n\n",getpid(), getppid());
    execl("/bin/cat", "cat", "ask1_B.c",NULL);
    /*main process executes the cat command using the execl command*/
    return 0;
}

/*Διεργασία Zombie: Είναι μια διεργασία παιδί που έχει εκτελέσει όλες της εντολές της αλλά δεν υπάρχει wait στην διεργασία γονέα
οπότε δεν διαγράφεται ποτέ απο το process table. 
Στο παρών πρόγραμμα, είναι πολύ πιθανό να δημιουργηθούν zombie διεργασίες και συγκεκριμένα
τα παιδιά των διεργασίων: P0, P1, P2 όσες διεργασίες δηλαδή έχουν κάλέσει fork.

Διεργασία orphan: Όταν μια διεργασία παιδί δεν έχει τελειώσει την εκτέλεση της αλλά για κάποιο λόγο η διεργασία γονέας τερματιστεί
τότε η διεργασία παιδί μετατρέπεται σε orphan process. Οταν λοιπόν έρθει η ώρα να τελειώσει το child αλλά δεν υπάρχει parent τότε 
το child δεν έχει που να επιστρεψει τιμή και μετατρέπεται σε zombie
Στο παρών πρόγραμμα, όλες οι διεργασίες εκτός απο την P0 θα μπορούσαν να γίνουν orphan αν πχ στελνόταν ένα kill signal
στο parent process.*/