#include <iostream>
#include <algorithm>
using namespace std;

void display(int arr[], int n)
{
    for (int j = 0; j < n; j++)
    {
        cout << arr[j] << "  ";
    }
    cout << endl;
}

void ascending(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

void descending(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

void bubble(int arr[], int n)
{
    int counter = 1;
    while (counter < n)
    {
        for (int i = 0; i < n - counter; i++)
        {
            if (arr[i] < arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
        counter++;
    }
}

void imax(int arr[], int n)
{
    int mx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        mx = max(mx, arr[i]);
        cout << mx << endl;
    }
}

int sumsub(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            sum = sum + arr[j];
        }
    }
    return sum;
}

int main()
{
    int n, key, menu;
    cout << "Enter Number of Elements : ";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Element " << i << " : ";
        cin >> arr[i];
    }

    do
    {
        cout << endl
             << "1. Display" << endl
             << "2. Ascending" << endl
             << "3. Descending" << endl
             << "4. BubbleSort" << endl
             << "5. Sum till ith element" << endl
             << "6. Sum of all Subarrays" << endl
             << "0. Exit" << endl;
        cin >> menu;

        switch (menu)
        {
        case 1:
            display(arr, n);
            break;
        case 2:
            ascending(arr, n);
            display(arr, n);
            break;
        case 3:
            descending(arr, n);
            display(arr, n);
            break;
        case 4:
            bubble(arr, n);
            display(arr, n);
            break;
        case 5:
            imax(arr, n);
            break;
        case 6:
            cout << sumsub(arr, n) << endl;
            break;
        }
    } while (menu != 0);
}