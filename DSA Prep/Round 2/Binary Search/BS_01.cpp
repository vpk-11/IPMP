// Binary Search
#include <iostream>
using namespace std;

int binarySearch(int arr[], int l, int h, int key)
{
    int m;
    while (l <= h)
    {
        m = (l + h) / 2;
        if (arr[m] == key)
            return m;

        if (arr[m] < key)
            l = m + 1;
        else
            h = m - 1;
    }

    return -1;
}

int rBinarySearch(int arr[], int l, int h, int key)
{
    if (h < l)
        return -1;

    int mid = (l + h) / 2;
    if (key == arr[mid])
        return mid;

    if (key > arr[mid])
        return rBinarySearch(arr, (mid + 1), h, key);

    return rBinarySearch(arr, l, (mid - 1), key);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << binarySearch(arr, 0, n - 1, 3) << endl;
    cout << rBinarySearch(arr, 0, n - 1, 1) << endl;
}