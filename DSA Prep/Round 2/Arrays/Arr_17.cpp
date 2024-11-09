// Finding 2 numbers so that thier diff is minimum
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int minDiff(int arr[], int n)
{
    if (n <= 1)
    {
        return 0;
    }
    sort(arr, arr + n);
    int miniDiff = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - arr[i - 1] < miniDiff)
        {
            miniDiff = arr[i] - arr[i-1];
        }
    }
    return miniDiff;
}

int main()
{
    int arr[] = {1, 2, 90, 10, 110};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum difference is " << minDiff(arr, n) << endl;
}