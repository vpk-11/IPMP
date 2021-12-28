// Cpp code for No of occurances in array
#include <iostream>
#include <algorithm>
using namespace std;

int BinarySearch(int arr[], int left, int right)
{
    if (right >= left)
    {
        int mid = (left + right) / 2;
        if (mid == arr[mid])
            return mid;
        int temp = -1;
        if (mid + 1 <= arr[right])
        {
            temp = BinarySearch(arr, (mid + 1), right);
        }
        if (temp != -1)
        {
            return temp;
        }
        if (mid - 1 >= arr[left])
        {
            return BinarySearch(arr, left, (mid - 1));
        }
    }
    return -1;
}
/*
int BinarySearch(int A[], int left, int right)
{
    int mid;

    while (left <= right)
    {
        mid = left + (right - left) / 2;

        if (A[mid] == mid)
            return mid;

        if ( mid + 1 < )
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}
*/
int fixedpoint(int arr[], int n)
{
    //Linear Search method
    for (int i = 0; i < n; i++)
        if (arr[i] == i)
            return i;

    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 3, 3, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Linear Search" << endl;
    int index = fixedpoint(arr, n);
    cout << "Fixed point is " << arr[index] << " at index " << index << endl;

    cout << "Binary Search" << endl;
    index = BinarySearch(arr, 0, n - 1);
    cout << "Fixed point is " << arr[index] << " at index " << index << endl;
}
