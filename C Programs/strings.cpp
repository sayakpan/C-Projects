#include <stdio.h>
#include <string.h>

void login(char user[20], char password[10], char firstName[20], char lastName[20]);
void create(char user[20], char password[10], char firstName[20], char lastName[20]);

int main()
{
    char user[20], password[20], firstName[20], lastName[20];
    int menu;
repeat:
    printf("\nPress '1' to Login\nPress '2' to Crate New Account\nPress '3' to Exit\n");
    scanf("%d", &menu);
    switch (menu)
    {
    case 1:
        login(user, password, firstName, lastName);
        goto repeat;
    case 2:
        create(user, password, firstName, lastName);
        goto repeat;
    case 3:
        break;
    }
    return 0;
}

void login(char user[20], char password[20], char firstName[20], char lastName[20])
{
    char checkUser[20], checkPassword[20];
    printf("\n********Login to Your Account********");
    printf("\nEnter User Id : ");
    fflush(stdin);
    gets(checkUser);
    printf("Enter Password : ");
    fflush(stdin);
    gets(checkPassword);
    if (strcmp(checkUser, user) == 0 && strcmp(checkPassword, password) == 0)
    {
        printf("\nWelcome, %s\n", firstName);
    }
    else
    {
        printf("\n!! User Name or Password is incorrect !!\n");
    }
}

void create(char user[20], char password[20], char firstName[20], char lastName[20])
{
    printf("\n********Create Your Account********");
    printf("\nEnter First Name : ");
    fflush(stdin);
    gets(firstName);
    printf("Enter Last Name : ");
    fflush(stdin);
    gets(lastName);
    char temp[20];
    strcpy(temp, firstName);
    strcpy(user, strcat(firstName, lastName));
    strcpy(firstName, temp);
    printf("Your UserName is : %s", user);
    printf("\nSet Password (Max 10) :");
    fflush(stdin);
    gets(password);
    printf("\nAccount Succesfully Created\n");
}