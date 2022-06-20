#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student 
{
    int am;
    char name[50];
    float grade;
    struct student *left;
    struct student *right;
};

struct student *createStudent();
void addInOrder(struct student *root_ptr, struct student *new_ptr);
void showInOrder(struct student *root_ptr);
float maxGrade(struct student *root_ptr);

int main() 
{
    int ch;
    struct student *temp,*root_ptr=NULL;
    float mGrade;

 do 
 {
    printf("\n--- Menu ");
    printf("\n--- 1.Add student in order ");
    printf("\n--- 2.Show students in order ");
    printf("\n--- 3.Show maximum grade ");
    printf("\n--- 0.Exit ");
    printf("\nChoice: ");
    scanf("%d",&ch);
 switch(ch) 
 {
 case 1:
    temp = createStudent();
    if (temp != NULL)
        if (root_ptr == NULL)
            root_ptr = temp;
        else
            addInOrder(root_ptr,temp);
    else
        printf("No memory available!\n");
 break;
 case 2:
    printf("Tree contents:\n");
    showInOrder(root_ptr);
 break;
 case 3:
    mGrade = maxGrade(root_ptr);
    if (mGrade == -1)
        printf("Empty tree\n");
    else
        printf("Max grade: %.1f\n",mGrade);
 break;
 case 0:
    printf("Bye!\n");
 break;
 default:
    printf("Try again.\n");
 break;
 }
 } 
 while (ch!=0);
 exit(0);
}

struct student *createStudent()
{
 struct student *s;
 s = (struct student *)malloc(sizeof(struct student));
 if (s != NULL)
 {
 printf("Student data\nAM:");
 scanf("%d",&s->am);
 printf ("Name:");
 scanf ("%s",s->name);
 printf ("Grade:");
 scanf ("%f",&s->grade);
 s->left = NULL;
 s->right = NULL;
}
 return s;
}


void addInOrder(struct student *root_ptr, struct student *new_ptr)
{
 if (new_ptr->am < root_ptr->am) /* Pros ta aristera */
    if (root_ptr->left == NULL) /* Den yparxei aristera paidi */
        root_ptr->left = new_ptr;
    else /* Yparxei aristera paidi */
        addInOrder(root_ptr->left,new_ptr);
 else /* Pros ta deksia */
    if (root_ptr -> right == NULL) /* Den yparxei de3ia paidi */
        root_ptr->right = new_ptr;
    else /* Yparxei de3ia paidi */
        addInOrder(root_ptr->right,new_ptr);
}


void showInOrder(struct student *root_ptr)
{
 if (root_ptr != NULL)
 {
    showInOrder(root_ptr->left);
    printf("%d %s %.1f\n", root_ptr->am, root_ptr->name, root_ptr->grade);
    showInOrder(root_ptr->right);
 }
}


float maxGrade(struct student *root_ptr)
{
 float result = -1, resultRight;
 if (root_ptr!=NULL)
 {
    result = maxGrade(root_ptr->left);
    if (result < root_ptr->grade)
        result = root_ptr->grade;
    resultRight= maxGrade(root_ptr->right);
    if (result < resultRight)
        result = resultRight;
}
return result;
}
