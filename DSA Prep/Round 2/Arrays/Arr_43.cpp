// Bitonic SubArray Length
#include <iostream>
using namespace std;

int bitonic(int arr[], int n)
{
    int inc[n];
    int dec[n];
    inc[0] = 1;
    dec[n - 1] = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] >= arr[i - 1])
        {
            inc[i] = inc[i - 1] + 1;
        }
        else
        {
            inc[i] = 1;
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] >= arr[i + 1])
        {
            dec[i] = dec[i + 1] + 1;
        }
        else
        {
            dec[i] = 1;
        }
    }
    int max = inc[0] + dec[0] - 1;
    for (int i = 1; i < n; i++)
    {
        if (inc[i] + dec[i] - 1 > max)
        {
            max = inc[i] + dec[i] - 1;
        }
    }
    return max;
}

int main()
{
    int arr[] = {12, 4, 78, 90, 45, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Length of max length Bitonic Subarray is " << bitonic(arr, n) << endl;
    return 0;
}