#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct product
{
    int code;
    char name[20];
    float price;
    int discount;
} product;

product write(product p[], int n);
product upper(product p[], int n);
product search(product p[], int n);
product read(product p[], int n);
void bill(product p[], int n);
void reset();

int main()
{
    product p[100];
    int n, menu;

    printf("\n******Store Product Information******\n");
repeat:
    printf("\n<<<<---MENU--->>>>\nPress '1' to Add Product\nPress '2' to See List\nPress '3' to Generate Bill\nPress '4' to Search\nPress '5' to Reset List\nPress 'Any' to Exit\n\n");
    scanf("%d", &menu);

    switch (menu)
    {
    case 1:
        write(p, n);
        goto repeat;
    case 2:
        read(p, n);
        goto repeat;
    case 3:
        bill(p, n);
        goto repeat;
    case 4:
        search(p, n);
        goto repeat;
    case 5:
        reset();
        goto repeat;
    default:
        break;
    }
}

product write(product p[], int n)
{
    printf("\nHow many Products to be added : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        p[i].code = i + 1;
        printf("\nProduct Code is - %d", p[i].code);
        printf("\n%d : Product Name : ", p[i].code);
        fflush(stdin);
        gets(p[i].name);
        printf("%d : Product Price (in Rupees): ", p[i].code);
        scanf("%f", &p[i].price);
        printf("%d : Product Discount %: ", p[i].code);
        scanf("%d", &p[i].discount);
    }
    upper(p, n);
}

product upper(product p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; p[i].name[j] != '\0'; j++)
        {
            if (p[i].name[j] >= 97 && p[i].name[j] <= 122)
            {
                p[i].name[j] = p[i].name[j] - 32;
            }
        }
    }
    FILE *fptr;
    fptr = fopen("structure.txt", "a");

    for (int i = 0; i < n; i++)
    {
        fprintf(fptr, "\nProduct Code : %d", p[i].code);
        fprintf(fptr, "\n%d : Product Name : %s", p[i].code, p[i].name);
        fprintf(fptr, "\n%d : Product Price : Rs. %.2f", p[i].code, p[i].price);
        fprintf(fptr, "\n%d : Product Discount : %d%%\n\n", p[i].code, p[i].discount);
    }
    fclose(fptr);
    return p[100];
}

product read(product p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n\nProduct Code : %d", p[i].code);
        printf("\n%d : Product Name : %s", p[i].code, p[i].name);
        printf("\n%d : Product Price : Rs. %.2f", p[i].code, p[i].price);
        printf("\n%d : Product Discount : %d%%\n", p[i].code, p[i].discount);
    }
}

product search(product p[], int n)
{
    char sName[20];
    int count = 0;
    printf("\nEnter Product name to Search : ");
    fflush(stdin);
    gets(sName);
    for (int k = 0; sName[k] != '\0'; k++)
    {
        if (sName[k] >= 97 && sName[k] <= 122)
        {
            sName[k] = sName[k] - 32;
        }
    }
    printf("\n---- SEARCH RESULT ----");
    for (int i = 0; i < n; i++)
    {
        if (strcmp(p[i].name, sName) == 0)
        {
            count = 1;
            printf("\n\nProduct Code : %d", p[i].code);
            printf("\n%d : Product Name : %s", p[i].code, p[i].name);
            printf("\n%d : Product Price : Rs. %.2f", p[i].code, p[i].price);
            printf("\n%d : Product Discount : %d%%\n", p[i].code, p[i].discount);
        }
    }
    if (count == 0)
        printf("\n!! Product is not in the List !!\n");
    return p[100];
}

void bill(product p[], int n)
{
    char sName[20];
    int qty, price, count = 0;
    float disc, buy;
    printf("\nEnter Product Name to Buy : ");
    fflush(stdin);
    gets(sName);

    for (int k = 0; sName[k] != '\0'; k++)
    {
        if (sName[k] >= 97 && sName[k] <= 122)
        {
            sName[k] = sName[k] - 32;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (strcmp(p[i].name, sName) == 0)
        {
            count = 1;
            printf("Enter Quantity : ");
            scanf("%d", &qty);
            printf("\n----- BILL GENERATED -----\n");
            printf("\nProduct Name : %s", p[i].name);
            printf("\nPrice of %s : Rs. %.2f", sName, p[i].price);
            printf("\nDiscount : %d%%\n", p[i].discount);
            price = p[i].price;
            disc = p[i].discount;
            buy = qty * (price - (price * disc / 100));
            printf("\nBuy Price After Discount : %.2f\n\n", buy);
        }
    }
    if (count == 0)
        printf("\nSorry, %s is Not Available Right Now.\n", sName);
}

void reset()
{
    FILE *fptr;
    fptr = fopen("structure.txt", "w");
    fclose(fptr);
    printf("\nList Reset Done !!\n");
}