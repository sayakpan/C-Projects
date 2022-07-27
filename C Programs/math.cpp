/* Program to solve the given system of equations

x1 - x2 + x3 = 1
-3x1 + 2x2 - 3 x3 = -6
2x1 - 5x2 + 4x3 = 5

We will use Gauss Elimination Method to solve it */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    int n, i, j, k;
    float a[10][10] = {0.0}, x[10] = {0.0};
    float pivot = 0.0;
    float factor = 0.0;
    float sum = 0.0;
    printf("Solution by Simple Gauss Elimination \n\n");

    printf("How many elements of the equations:");

    scanf("%d", &n);

    printf("%d\n", n);

    printf("\n\t Input Coefficients a[i, j+1], row-wise\n");

    /*Matrix Value Taken*/
    for (i = 1; i <= n; i++)
    {

        for (j = 1; j <= n + 1; j++)
        {
            printf("a[%d][%d] : ", i, j);
            scanf("%f", &a[i][j]);
        }
    }

    printf("\n\n");

    /*Matrix Original Value Displayed*/

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n + 1; j++)
        {

            printf("\t%10.0f", a[i][j]);
        }

        printf("\n");
    }

    /*Looping Started*/

    for (k = 1; k <= n - 1; k++)
    {
        printf("\nFor K=%d\n", k);
        if (a[k][k] == 0.0)
        {

            printf("error");
        }
        else
        {
            pivot = a[k][k];
            for (j = k; j <= n + 1; j++)
                a[k][j] = a[k][j] / pivot;

            for (i = k + 1; i <= n; i++)
            {
                factor = a[i][k];

                for (j = k; j <= n + 1; j++)
                {
                    a[i][j] = a[i][j] - factor * a[k][j];
                }
            }
        }

        printf("\n\ntest\n\n");
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n + 1; j++)
            {

                printf("\t%10.2f", a[i][j]);
            }

            printf("\n");
        }

        if (a[n][n] == 0)

            printf("error");

        else
        {

            x[n] = a[n][n + 1] / a[n][n];

            for (i = n - 1; i >= 1; i--)
            {

                sum = 0.0;

                for (j = i + 1; j <= n; j++)

                    sum = sum + a[i][j] * x[j];

                x[i] = (a[i][n + 1] - sum) / a[i][i];
            }
        }
    }
    for (i = 1; i <= n; i++)
    {

        printf("\n\tx[%1d]=%10.4f", i, x[i]);
    }
    return 0;
    exit(1);
}