#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct list
{
    char name[20];
    int roll;
    char course[10];
    struct list *next;
} NODE;

NODE *start = NULL;

void add_Node();
void display();
void add_begin();

int main()
{
    int menu;
    do
    {
        printf("\n\n********Linked List Functions**********\n");
        printf("\n---Press <1> to Display");
        printf("\n---Press <2> to Add Node");
        printf("\n---Press <3> to Add Node at Begining");
        printf("\n---Press <0> to Exit\n>>> ");

        scanf("%d", &menu);
        switch (menu)
        {
        case 1:
            display();
            break;
        case 2:
            add_Node();
            break;
        case 3:
            add_begin();
            break;
        case 0:
            exit(1);
        }
    } while (menu != 0);
}

void display()
{
    NODE *curr;
    curr = start;
    if (curr == NULL)
        printf("\nList is Empty !");
    while (curr != NULL)
    {
        printf("\nName : %s", curr->name);
        printf("\nRoll : %d", curr->roll);
        printf("\nName : %s", curr->course);
        curr = curr->next;
    }
}

void add_Node()
{
    NODE *temp, *curr;
    do
    {
        temp = (NODE *)malloc(sizeof(NODE));
        printf("\n--List--\n");
        printf("\nEnter Name : ");
        fflush(stdin);
        gets(temp->name);
        if (strlen(temp->name) == 0)
        {
            printf("\n\nPressed 'ENTER' - Terminated");
            break;
        }
        printf("Enter Roll : ");
        scanf("%d", &temp->roll);
        printf("Enter Course : ");
        fflush(stdin);
        gets(temp->course);
        temp->next = NULL;
        if (start == NULL)
            start = temp;
        else
        {
            curr = start;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = temp;
        }
    } while (1);
}

void add_begin()
{
    NODE *temp, *curr;
    temp = (NODE *)malloc(sizeof(NODE));
    printf("\n--List--\n");
    do
    {
        printf("\nEnter Name : ");
        fflush(stdin);
        gets(temp->name);
        if (strlen(temp->name) == 0)
        {
            printf("\n\nPressed 'ENTER' - Terminated");
            break;
        }
        printf("Enter Roll : ");
        scanf("%d", &temp->roll);
        printf("Enter Course : ");
        fflush(stdin);
        gets(temp->course);
    } while (1);
}