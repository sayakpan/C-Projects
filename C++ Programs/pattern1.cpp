#include <iostream>
#include <unistd.h>
using namespace std;

int main()
{

    int row, col;
    cout << "Enter Row : ";
    cin >> row;
    // cout << "Enter Coloumn : ";
    // cin >> col;
    while (1)
    {
        for (int i = 1; i <= row; i++)
        {
            for (int j = 1; j <= (row * 2 - 1); j++)
            {
                if (j <= i || j >= (row * 2 - i))
                {
                    cout << "* ";
                    usleep(2500);
                }
                else
                    cout << "  ";
            }
            cout << endl;
        }
        for (int i = row; i >= 1; i--)
        {
            for (int j = (row * 2 - 1); j >= 1; j--)
            {
                if (j <= i || j >= (row * 2 - i))
                {
                    cout << "* ";
                    usleep(2500);
                }
                else
                    cout << "  ";
            }
            cout << endl;
        }

        for (int i = 1; i <= row - 2; i++)
        {
            cout << "  ";
        }
        cout << "AKASH" << endl;

        for (int i = 1; i <= row; i++)
        {
            for (int j = 1; j <= (row * 2 - 1); j++)
            {
                if (j <= i || j >= (row * 2 - i))
                {
                    cout << "* ";
                    usleep(2500);
                }
                else
                    cout << "  ";
            }
            cout << endl;
        }
        for (int i = row; i >= 1; i--)
        {
            for (int j = (row * 2 - 1); j >= 1; j--)
            {
                if (j <= i || j >= (row * 2 - i))
                {
                    cout << "* ";
                    usleep(2500);
                }
                else
                    cout << "  ";
            }
            cout << endl;
        }
        for (int i = 1; i <= row - 2; i++)
        {
            cout << "  ";
        }
        cout << "TITHI" << endl;
    }
    return 0;
}