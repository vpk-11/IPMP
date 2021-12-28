// Cpp code for No of occurances in array
#include <iostream>
#include <algorithm>
using namespace std;

int BinarySearch(int A[], int left, int right, int key)
{
    int mid;

    while (left <= right)
    {
        mid = left + (right - left) / 2;

        if (A[mid] == key)
            return mid;

        if (A[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

void frequency(int arr[], int n, int x)
{
    int res;
    //Linear Search method
    /*
    res = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            res++;
    */
    // Binary Search Method
    int index = BinarySearch(arr, 0, n - 1, x);

    int ind = BinarySearch(arr, 0, n - 1, x);
    if (!(ind == -1))
    {
        res = 1;
        int left = index - 1, right = index + 1;
        while (left >= 0 && arr[left] == x)
            res++, left--;

        while (right < n && arr[right] == x)
            res++, right++;

        cout << "Frequency of " << x << " is = " << res << endl;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 3, 3, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 3;
    frequency(arr, n, x);
}
