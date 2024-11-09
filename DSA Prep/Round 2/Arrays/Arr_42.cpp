// Maximum Product Subarray
#include <iostream>
#include <algorithm>
using namespace std;

int min(int a, int b, int c)
{
    if (a < b)
    {
        if (c < a)
        {
            return c;
        }
        return a;
    }
    if (c < b)
    {
        return c;
    }
    return b;
}

int max(int a, int b, int c)
{
    if (a > b)
    {
        if (c > a)
        {
            return c;
        }
        return a;
    }
    if (c > b)
    {
        return c;
    }
    return b;
}

int maxSubarrayProduct(int arr[], int n)
{
    int maxNow = arr[0];
    int minNow = arr[0];
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
    {
        int temp = max(arr[i], arr[i] * maxNow, arr[i] * minNow);
        minNow = min(arr[i], arr[i] * maxNow, arr[i] * minNow);
        maxNow = temp;
        if (maxVal < maxNow)
        {
            maxVal = maxNow;
        }
    }
    return maxVal;
}

int main()
{
    int arr[] = {1, -2, -3, 0, 7, -8, -2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum Sub array product is " << maxSubarrayProduct(arr, n) << endl;
    return 0;
}