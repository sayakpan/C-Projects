#include <stdio.h>

void zodiac(int date, int month);

int main()
{
    int month, date, year, repeater;
    printf("*********Enter Date of Birth to find Zodiac Sign*********\n\n");

    do
    {
        printf("Enter Day (DD):");
        scanf("%ld", &date);
        printf("Enter Month (MM):");
        scanf("%d", &month);
        printf("Enter Year (YYYY):");
        scanf("%d", &year);
        if ((year > 2022) || (year < 1950))
        {
            printf("\n!!!  Invalid Year Entered  !!!");
            goto repeat;
        }
        printf("\nThe Date of Birth you entered is - %d/%d/%d\n", date, month, year);
        zodiac(date, month); /*Calling Function*/
    repeat:
        printf("\n\nPress 'ANY' key to Repeat, Press 'e' to EXIT\n");
        fflush(stdin);
        repeater = getchar();
    } while (!((repeater == 'e') || (repeater == 'E')));
}

void zodiac(int date, int month) /*Defining Function*/
{
    if ((month == 1 && (date >= 20 && date <= 31)) || (month == 2 && (date >= 1 && date <= 17)))
    {
        printf("\nYour Zodiac sign is : AQUARIUS");
    }
    else if ((month == 2 && (date >= 18 && date <= 29)) || (month == 3 && (date >= 1 && date <= 19)))
    {
        printf("\nYour Zodiac sign is : PISCES");
    }
    else if ((month == 3 && (date >= 20 && date <= 31)) || (month == 4 && (date >= 1 && date <= 19)))
    {
        printf("\nYour Zodiac sign is : ARIES");
    }
    else if ((month == 4 && (date >= 20 && date <= 30)) || (month == 5 && (date >= 1 && date <= 20)))
    {
        printf("\nYour Zodiac sign is : TAURUS");
    }
    else if ((month == 5 && (date >= 21 && date <= 31)) || (month == 6 && (date >= 1 && date <= 20)))
    {
        printf("\nYour Zodiac sign is : GEMINI");
    }
    else if ((month == 6 && (date >= 21 && date <= 30)) || (month == 7 && (date >= 1 && date <= 22)))
    {
        printf("\nYour Zodiac sign is : CANCER");
    }
    else if ((month == 7 && (date >= 23 && date <= 31)) || (month == 8 && (date >= 1 && date <= 22)))
    {
        printf("\nYour Zodiac sign is : LEO");
    }
    else if ((month == 8 && (date >= 23 && date <= 31)) || (month == 9 && (date >= 1 && date <= 22)))
    {
        printf("\nYour Zodiac sign is : VIRGO");
    }
    else if ((month == 9 && (date >= 23 && date <= 30)) || (month == 10 && (date >= 1 && date <= 22)))
    {
        printf("\nYour Zodiac sign is : LIBRA");
    }
    else if ((month == 10 && (date >= 23 && date <= 31)) || (month == 11 && (date >= 1 && date <= 21)))
    {
        printf("\nYour Zodiac sign is : SCORPIO");
    }
    else if ((month == 11 && (date >= 22 && date <= 30)) || (month == 12 && (date >= 1 && date <= 21)))
    {
        printf("\nYour Zodiac sign is : SAGITTARIUS");
    }
    else if ((month == 12 && (date >= 21 && date <= 31)) || (month == 1 && (date >= 1 && date <= 19)))
    {
        printf("\nYour Zodiac sign is : CAPRICORN");
    }
    else
    {
        printf("\n!!!  Invalid Date Entered  !!!");
    }
}