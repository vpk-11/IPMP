// Missing number from Range
#include <iostream>
using namespace std;

int missingNumber(int arr[], int n)
{
    long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int x = ((n + 2) * (n + 1)) / 2;
    if (sum == x)
    {
        return -1;
    }
    else
    {
        return x - sum;
    }
}

int main()
{
    int arr[] = {2, 3, 4, 1, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << missingNumber(arr, n) << endl;
    return 0;
}