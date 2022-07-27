#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct linkedList
{
    char name[20];
    int roll;
    struct linkedList *link;
} NODE;

NODE *start;
void append();
void display();

int main()
{
    int menu;
    do
    {
        printf("\n1. APPEND\n2. DISPLAY\n0. EXIT\n>>> ");
        scanf("%d", &menu);
        switch (menu)
        {
        case 1:
            append();
            break;
        case 2:
            display();
            break;
        }
    } while (menu != 0);
}

void append()
{
    NODE *temp, *curr;
    temp = (NODE *)malloc(sizeof(NODE));
    printf("\nEnter Name : ");
    fflush(stdin);
    gets(temp->name);
    printf("Enter Roll : ");
    scanf("%d", &temp->roll);
    temp->link = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        curr = start;
        while (curr->link != NULL)
        {
            curr = curr->link;
        }
        curr->link = temp;
    }
}

void display()
{
    NODE *curr;
    curr = start;
    while (curr != NULL)
    {
        printf("\nName : %s", curr->name);
        printf("\nRoll No : %d", curr->roll);
        curr = curr->link;
    }
}