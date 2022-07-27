#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BankAccount
{
    char name[20];
    char accountNumber[20];
    float balance;
} account;

void add(account acc[]);
void display(account acc[]);
void search(account acc[]);
void operation(account acc[]);

int main()
{
    account acc[20];
    int menu;
    printf("\n*****Manage Bank Account Data*****\n\n");
repeat:
    printf("\n\n--Press '1' to Display All Accounts--\n--Press '2' to ADD New Account--\n--Press '3' to SEARCH Account--\n--Press '4' to Credit/Debit--\n--Press '0' to EXIT--\n\n");
    scanf("%d", &menu);
    switch (menu)
    {
    case 1:
        display(acc);
        goto repeat;
    case 2:
        add(acc);
        goto repeat;
    case 3:
        search(acc);
        goto repeat;
    case 4:
        operation(acc);
        goto repeat;
    default:
        break;
    }
}

void add(account acc[20])
{
    FILE *fp;
    fp = fopen("bank.txt", "a");
    if (fp == NULL)
    {
        printf("Cannot Open File");
        exit(1);
    }
    int n;
    printf("\nHow Many Account to be Added\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter Account Holder Name\n[Press only 'Enter' to Exit] : ");
        fflush(stdin);
        gets(acc[i].name);
        if (strlen(acc[i].name) == 0)
            break;
        for (int j = 0; acc[i].name[j] != '\0'; j++)
        {
            if (acc[i].name[j] >= 97 && acc[i].name[j] <= 122)
                acc[i].name[j] = acc[i].name[j] - 32;
        }
        printf("Enter Account Number : ");
        fflush(stdin);
        gets(acc[i].accountNumber);
        printf("Enter Account Balance : ");
        scanf("%f", &acc[i].balance);

        fprintf(fp, "%s\n%s\n%.2f\n", acc[i].name, acc[i].accountNumber, acc[i].balance);
    }
    fclose(fp);
}

void display(account acc[20])
{
    FILE *fp;
    fp = fopen("bank.txt", "r");
    if (fp == NULL)
    {
        printf("Cannot Open File");
        exit(1);
    }
    char dName[20], dNumber[20];
    float dBal;
    while (fscanf(fp, "%s\n%s\n%f\n", dName, dNumber, &dBal) != EOF)
    {
        printf("\nAccount Holder Name ; %s", dName);
        printf("\nAccount Number : %s", dNumber);
        printf("\nAccount Balance : %.2f\n", dBal);
    }
    if (strlen(dName) == 0)
    {
        printf("List is Empty !");
    }
    fclose(fp);
}

void search(account acc[20])
{
    FILE *fp;
    fp = fopen("bank.txt", "r");
    if (fp == NULL)
    {
        printf("Cannot Open File");
        exit(1);
    }
    char sNumber[20], dName[20], dNumber[20];
    float dBal;
    printf("\nEnter Account Number to SEARCH : ");
    fflush(stdin);
    gets(sNumber);
    while (fscanf(fp, "%s\n%s\n%f\n", dName, dNumber, &dBal) != EOF)
    {
        if (strcmp(sNumber, dNumber) == 0)
        {
            printf("\nAccount Holder Name ; %s", dName);
            printf("\nAccount Number : %s", dNumber);
            printf("\nAccount Balance : %.2f\n", dBal);
        }
        else
        {
            printf("\nAccount Does Not Exist\n");
        }
    }
}

void operation(account acc[20])
{
    FILE *fp;
    fp = fopen("bank.txt", "rb+");
    if (fp == NULL)
    {
        printf("Cannot Open File");
        exit(1);
    }
    char sNumber[20];
    float oBal;
    int size;
    printf("\nEnter Account Number to Credit/Debit : ");
    fflush(stdin);
    gets(sNumber);
    while (fread(acc, sizeof(acc), 1, fp) == 1)
    {
        if (strcmp(sNumber, acc->name) == 0)
        {
            size = sizeof(oBal);
            fseek(fp, -size, 1);
            printf("\nAccount Found\n");
            printf("\nEnter new Balance");
            scanf("%f", acc->balance);
            fwrite(acc, sizeof(acc), 1, fp);
            break;
        }
    }
}