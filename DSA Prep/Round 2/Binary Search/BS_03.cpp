// Majority Element in Array
#include <iostream>
using namespace std;

int binarySearch(int arr[], int l, int h, int x)
{
    int mid;
    while (h >= l)
    {
        mid = (l + h) / 2;
        if ((mid == 0 || x > arr[mid - 1]) && (arr[mid] == x))
            return mid;

        else if (x > arr[mid])
            l = mid + 1;
        else
            h = mid - 1;
    }
    return -1;
}

bool isMajority(int arr[], int n, int x)
{
    int i = binarySearch(arr, 0, n - 1, x);
    if (i == -1)
    {
        return false;
    }
    if (((i + n / 2) <= n - 1) && (arr[i + n / 2] == x))
    {
        return true;
    }
    return false;
}

int main()
{
    int arr[] = {1, 1, 1, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << isMajority(arr, n, 1) << endl;
}