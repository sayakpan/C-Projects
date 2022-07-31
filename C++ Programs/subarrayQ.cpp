/*Longest Arithmetic Subarray*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = 2;
    int count = 2;
    int diff = arr[1] - arr[0];
    int currDiff = 0;
    int i = 2;
    while (i < n)
    {
        currDiff = arr[i] - arr[i - 1];
        if (diff == currDiff)
        {
            count++;
        }
        else
        {
            diff = currDiff;
            count = 2;
        }
        ans = max(ans, count);
        i++;
    }

    cout << endl
         << ans << endl;
    return 0;
}