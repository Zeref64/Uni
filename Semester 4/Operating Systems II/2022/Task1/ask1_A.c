/* Ονοματεπώνυμο: Κούμανης Βασίλειος
ΑΜ: 19390104
Άσκηση 1 ΛΣ ΙΙ */

#include <stdio.h>
#include <unistd.h>

int main () {
    /*By calling getpid() I'm getting the ID of this program. If I want to see whats the ID of the 'parent'
    of this program (which is the shell ID) I'm calling getppid() */
    printf ("Current shell ID = %i\n", getppid());
    printf ("Main process ID = %i\n", getpid());
    printf ("First fork\n"); 
    
    int pid1=fork();
    if (pid1 == -1)
        exit(1);
    /*Below this point every line of code is going to be executed twice one for each process
    because I want to see every process clearly I'm using an if statement so the code block inside the if statement is going to be 
    executed by only the child process which has pid = 0*/ 
    if (pid1 == 0) {
        //The lines below are going to be executed only by the child of pid1
        printf("\tpid1: This is the process %i with with parent id: %i\n", getpid(), getppid());
        printf("\tpid1:Second fork\n");
        int pid2 = fork();
        if (pid2 == -1)
            exit(1);
        /*Another child process is generated which means that the lines below this point are going to be executed twice
        the first time from the process pid2 and the second time from child process of pid2*/
        printf("\t\tpid1,2: This is the process %i with with parent id: %i\n",getpid(), getppid());
        return 2;
        }
    /*The code inside the else statement is going to be executed by only the main process*/ 
    else {
        printf("pid0:Third fork\n");
        int pid3 = fork();
        if (pid3 == -1)
            exit(1);
        /*The main process is creating yet another child which is the 'brother' of pid1
        The lines below are going to be executed twice, once from the main process and once from the pid3
        pid1 can't execute this code block because we are inside the else statement.*/
        printf("\tpid0,3: This is the process %i with with parent id: %i\n",getpid(), getppid());
        printf("\tpid0,3:Fourth fork\n");
        int pid4 = fork();
        if (pid4 == -1)
            exit(1);
        /*This time the fourth fork is called twice that means that pid0 generates a child and pid3 generates another child aswell
        the line below is going to be executed four times once from pid0, second from pid0's child, third from pid3 and lastly from pid3's child*/
        printf("\t\tpid0,3,0c,3c: This is the process %i with with parent id: %i\n",getpid(), getppid());
    }
    return 0;
}