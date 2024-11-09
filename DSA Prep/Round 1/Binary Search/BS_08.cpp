// Max Elem in which it increases and then decreases
#include <iostream>
using namespace std;

int maxSearch(int arr[], int l, int r)
{
    while (l <= r)
    {
        int m = (l + r) / 2;

        if ((r == l + 1) && arr[l] >= arr[r]) // Case with 2 elems
            return arr[l];

        if ((r == l + 1) && arr[l] < arr[r]) // case with 2 elems
            return arr[r];

        if (arr[m] > arr[m + 1] && arr[m] > arr[m - 1]) // m is bigger than left and right
        {
            return arr[m];
        }
        else if (arr[m] > arr[m + 1] && arr[m] < arr[m - 1])
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return -1;

    // int start = 0;
    // int end = n;
    // int mid;
    // while (start <= end)
    // {
    //     mid = start + (end - start) / 2;
    //     if ((mid == 0 || arr[mid] > arr[mid - 1]) && (mid == n - 1 || arr[mid] > arr[mid + 1]))
    //         return arr[mid];
    //     if (mid - 1 > 0 && arr[mid] < arr[mid - 1])
    //         end = mid - 1;
    //     if (mid + 1 < n && arr[mid] < arr[mid + 1])
    //         start = mid + 1;
    // }
    // return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxSearch(arr, 0, n - 1) << endl;
}