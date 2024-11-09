// Pivoted Binary Search
// Find element in O(logn) time in a pivoted array
#include <iostream>
using namespace std;

int binarySearch(int arr[], int l, int h, int key)
{
    while (l <= h)
    {
        int m = (l + h) / 2;
        if (arr[m] == key)
            return m;

        if (arr[m] < key)
            l = m + 1;
        else
            h = m - 1;
    }
    return -1;
}

int findPivot(int arr[], int l, int h)
{
    if (h == l)
    {
        return l;
    }
    int mid;
    while (l < h)
    {
        mid = (l + h) / 2;
        if (mid < h && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        if (mid > l && arr[mid] < arr[mid - 1])
        {
            return (mid - 1);
        }
        if (arr[l] >= arr[mid])
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}

int pivotedBinarySearch(int arr[], int l, int h, int key)
{
    int pivot = findPivot(arr, 0, h);

    if (pivot == -1)
    {
        return binarySearch(arr, 0, h, key);
    }

    if (arr[pivot] == key)
    {
        return pivot;
    }
    if (arr[0] <= key)
    {
        return binarySearch(arr, l, pivot - 1, key);
    }

    return binarySearch(arr, pivot + 1, h, key);
}

int pivotedSearch_IMP(int arr[], int l, int h, int key)
{
    int mid;
    while (l <= h)
    {
        mid = l + (h - l) / 2;

        if (arr[mid] == key)
            return mid;
        // left part is sorted
        if (arr[l] <= arr[mid])
        {
            if (key >= arr[l] && key < arr[mid])
                h = mid - 1;
            else
                l = mid + 1;
        }
        // right part is sorted
        else
        {
            if (key > arr[mid] && key <= arr[h])
                l = mid + 1;
            else
                h = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << pivotedBinarySearch(arr, 0, n - 1, 4) << endl;
}
