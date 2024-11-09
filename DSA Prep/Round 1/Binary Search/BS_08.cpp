// Cpp code for Max Point in array
#include <iostream>
#include <algorithm>
using namespace std;

int BinarySearch(int arr[], int left, int right)
{
    if (right >= left)
    {
        int mid = (left + right) / 2;
        if (arr[mid] >= arr[mid-1] && arr[mid] >= arr[mid+1])
            return mid;
        if (arr[mid] >= arr[mid-1] && arr[mid] <= arr[mid+1])
        {
            return BinarySearch(arr, (mid + 1), right);
        }
        if (arr[mid] <= arr[mid-1] && arr[mid] >= arr[mid+1])
        {
            return BinarySearch(arr, left, (mid - 1));
        }
    }
    return -1;
}

int MaxPoint(int arr[], int n)
{
    //Linear Search method
    int max = arr[0];
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        if(arr[i] > arr[i+1])
            break;
    }
    return i;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 3, 2, 1};
    int index;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Linear Search" << endl;
    index = MaxPoint(arr,n);
    cout << "Max point is " << arr[index] << " at index " << index << endl;

    cout << "Binary Search" << endl;
    index = BinarySearch(arr,0,n-1);
    cout << "Max point is " << arr[index] << " at index " << index << endl;
}
