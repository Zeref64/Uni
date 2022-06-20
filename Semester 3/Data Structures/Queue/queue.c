#include <stdio.h>
#include <stdlib.h>

struct student
{
	int am;
	char name[50];
	float grade;
	struct student *next;
};

struct student *head;
struct student *tail;

void init();
void show();
int enqueue(struct student d);
int dequeue(struct student *s);

main()
{
	struct student data;	
	int ch;
	init();
    do {
        printf("\nMenu ");
        printf("\n1.Enqueue ");
        printf("\n2.Dequeue");
        printf("\n3.Show contents ");
        printf("\n0.Exit ");
        printf("\nChoice: ");
        scanf("%d",&ch);

        switch (ch) {
        case 1:
            printf("Enter student data:");
            scanf ("%d %s %f",&data.am,data.name,&data.grade); //χρησημοποιο βοηθητικο struct data.
            if (enqueue(data))
                printf("Successfully pushed to stack.\n");
            else
                printf("No memory available, push failed.\n");
            break;
        case 2:
            if (dequeue(&data))
                printf("Popped: %d %s %.1f",data.am,data.name,data.grade);
            else
                printf("Empty stack, no data retrieved.\n");
            break;
			case 3:
            show();
            break;
			case 0:
            printf("Bye!\n");
            break;
        default: 
            printf("Try again.\n");
            break;
        } 
    } while (ch!=0);
    exit(0);
}

void init()
{
	head = NULL;
	tail = NULL;   
}

int enqueue(struct student d)
{
    int done=0;
    struct student *s;
	s =(struct student *) malloc (sizeof (struct student));
	if (s!=NULL){
		*s = d;
		s->next = NULL;
		if (tail == NULL)
			head = s;
		else
			tail->next = s;
		tail = s;
		done=1;
    }return done;
}

int dequeue(struct student *data)
{
    int done=0;
    struct student *temp;
    if (head != NULL){
	  	temp = head;
	  	*data = *head;
	  	head=head->next;
	  	free(temp);
	  	if (head == NULL)
	  		tail=NULL;
	  	done = 1;
	  }
    return done;
}

void show()
{
    printf("--- Top of Queue ---\n");
    
    struct student *i;
    i = head;
    while (i != NULL)
	{
		printf ("Student %d %s %.1f\n", i -> am , i -> name, i -> grade);
		i = i->next;
	}
	
    printf("\n---Bottom of Queue---\n");	
}
