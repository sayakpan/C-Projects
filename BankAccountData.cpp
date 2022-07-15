#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BankAccount
{
    char name[20];
    char accountNumber[20];
    float balance;
} account;

void add(account acc);
void display(account acc);
void search(account acc);
void operation(account acc);
void remove(account acc);
void reset(account acc);

int main()
{
    account acc;
    int menu;
    printf("\n***** Bank Account Data *****\n");
    do
    {
        printf("\n\n--Press '1' to 'DISPLAY ALL'--\n--Press '2' to 'ADD NEW ACCOUNT'--\n--Press '3' to 'SEARCH'--\n--Press '4' to 'CREDIT/DEBIT'--\n--Press '5' to 'REMOVE'--\n--Press '6' to 'RESET'--\n--Press '0' to 'EXIT'--\n\n>>> ");
        scanf("%d", &menu);
        switch (menu)
        {
        case 1:
            display(acc);
            break;
        case 2:
            add(acc);
            break;
        case 3:
            search(acc);
            break;
        case 4:
            operation(acc);
            break;
        case 5:
            remove(acc);
            break;
        case 6:
            reset(acc);
            break;
        }
    } while (menu != 0);
}

void add(account acc)
{
    FILE *fp;
    fp = fopen("bank.txt", "ab");
    if (fp == NULL)
    {
        printf("Cannot Open File");
        exit(1);
    }
    do
    {
        printf("\nEnter Account Holder Name\n[Press only 'Enter' to Exit] : ");
        fflush(stdin);
        gets(acc.name);
        if (strlen(acc.name) == 0)
        {
            printf("\n\'ENTER Key Pressed'\nAccounts Succesfully Added !");
            break;
        }
        for (int j = 0; acc.name[j] != '\0'; j++) /*Capitalising Name*/
        {
            if (acc.name[j] >= 97 && acc.name[j] <= 122)
                acc.name[j] = acc.name[j] - 32;
        }
        printf("Enter Account Number : ");
        fflush(stdin);
        gets(acc.accountNumber);
        printf("Enter Account Balance : ");
        scanf("%f", &acc.balance);
        fwrite(&acc, sizeof(acc), 1, fp); /*Write Data in Binary*/
    } while (1);
    fclose(fp);
}

void display(account acc)
{
    FILE *fp;
    fp = fopen("bank.txt", "rb");
    if (fp == NULL)
    {
        fp = fopen("bank.txt", "w");
    }
    long int check, check1; /*Checking if file is Empty*/
    fseek(fp, 0, SEEK_END);
    check = ftell(fp);
    rewind(fp);
    check1 = ftell(fp);
    if (check == check1)
    {
        printf("\n\tNo Account Found !!");
    }
    else
    {
        printf("\n--All Account Details--\n");
        while (fread(&acc, sizeof(acc), 1, fp) == 1) /*Read Data from Binary*/
        {
            printf("\nAccount Holder Name : %s", acc.name);
            printf("\nAccount Number : %s", acc.accountNumber);
            printf("\nAccount Balance : %.2f\n", acc.balance);
        }
        fclose(fp);
    }
}

void search(account acc)
{
    FILE *fp;
    fp = fopen("bank.txt", "rb");
    if (fp == NULL)
    {
        printf("Cannot Open File");
        exit(1);
    }
    char search[20];
    int flag = 0;
    printf("\nEnter Account Number to SEARCH : ");
    fflush(stdin);
    gets(search);
    while (fread(&acc, sizeof(acc), 1, fp) == 1)
    {
        if (strcmp(search, acc.accountNumber) == 0)
        {
            printf("\n--- Match Found ---\n");
            printf("\nAccount Holder Name : %s", acc.name);
            printf("\nAccount Number : %s", acc.accountNumber);
            printf("\nAccount Balance : %f\n", acc.balance);
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        printf("\nAccount Does Not Exists !!");
    fclose(fp);
}

void operation(account acc)
{
    FILE *fp;
    fp = fopen("bank.txt", "rb+");
    if (fp == NULL)
    {
        printf("Cannot Open File");
        exit(1);
    }
    char search[20];
    int flag = 0, menu;
    float amount;
    printf("\nEnter Account Number : ");
    fflush(stdin);
    gets(search);
    while (fread(&acc, sizeof(acc), 1, fp) == 1)
    {
        if (strcmp(search, acc.accountNumber) == 0)
        {
            flag = 1;
            printf("\n--- Account Details of Entered Account---\n");
            printf("\nAccount Holder Name : %s", acc.name);
            printf("\nAccount Number : %s", acc.accountNumber);
            printf("\nAccount Balance : %.2f\n", acc.balance);
            printf("\n\n--Enter '1' to CREDIT--\n--Enter '2' to DEBIT--\n>>> ");
            scanf("%d", &menu);
            switch (menu)
            {
            case 1:
                printf("\nAmount to be Credited : ");
                scanf("%f", &amount);
                acc.balance = acc.balance + amount;
                printf("Rs. %.2f Credited to %s", amount, acc.name);
                printf("\n\nCurrent Balance : %.2f", acc.balance);
                fseek(fp, -sizeof(acc.balance), SEEK_CUR);
                fwrite(&acc.balance, sizeof(acc.balance), 1, fp);
                break;

            case 2:
                printf("\nAmount to be Debited : ");
                scanf("%f", &amount);
                acc.balance = acc.balance - amount;
                printf("Rs. %.2f Debited from %s", amount, acc.name);
                printf("\n\nCurrent Balance : %.2f", acc.balance);
                fseek(fp, -sizeof(acc.balance), SEEK_CUR);
                fwrite(&acc.balance, sizeof(acc.balance), 1, fp);
                break;
            }
            break;
        }
        if (flag = 0)
            printf("\nAccount Does Not Exists !!");
    }
    fclose(fp);
}

void reset(account acc)
{
    FILE *fp;
    fp = fopen("bank.txt", "wb");
    if (fp == NULL)
    {
        printf("Cannot Open File");
        exit(1);
    }
    printf("\n<-- RESET DONE -->");
    fclose(fp);
}

void remove(account acc)
{
    FILE *fp;
    fp = fopen("bank.txt", "rb+");
    if (fp == NULL)
    {
        printf("Cannot Open File");
        exit(1);
    }
    FILE *ftemp;
    ftemp = fopen("temp.txt", "wb+");

    char search[20];
    char ch;
    int flag = 0;
    printf("\nEnter Account Number to REMOVE Account : ");
    fflush(stdin);
    gets(search);
    while (fread(&acc, sizeof(acc), 1, fp) == 1)
    {
        if (strcmp(search, acc.accountNumber) == 0)
        {
            printf("\n--- Delete ? ---\n");
            printf("\nAccount Holder Name : %s", acc.name);
            printf("\nAccount Number : %s", acc.accountNumber);
            printf("\nAccount Balance : %.2f\n", acc.balance);
            flag = 1;
            break;
        }
    }
    rewind(fp);
    if (flag == 1)
    {
        printf("\nAre You Sure ?\n[Press '1' to Confirm]\n[Press '0' to Exit]\n>>> ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            while (fread(&acc, sizeof(acc), 1, fp) == 1)
            {
                if (strcmp(search, acc.accountNumber) != 0)
                {
                    fwrite(&acc, sizeof(acc), 1, ftemp);
                }
            }

            fclose(fp);
            fclose(ftemp);

            // fp = fopen("bank.txt", "wb");
            // ftemp = fopen("temp.txt", "rb");
            // while (fread(&acc, sizeof(acc), 1, ftemp) == 1)
            // {
            //     fwrite(&acc, sizeof(acc), 1, fp);
            // }
            // fclose(fp);
            // fclose(ftemp);

            remove("bank.txt");
            rename("temp.txt", "bank.txt");
            printf("\nAccount Deleted");
        }
        else
            printf("\nDeletion Terminated By USER!!");
    }
    else
        printf("\nAccount Does Not Exists !!");
    fclose(fp);
    fclose(ftemp);
}
