// Point where arr[i] = i
#include <iostream>
using namespace std;

int binarySearch(int arr[], int l, int h)
{
    if (h >= l)
    {
        int m = l + (h - l) / 2;
        if (m == arr[m])
        {
            return m;
        }
        int res = -1;
        if (m + 1 <= arr[h])
        {
            res = binarySearch(arr, (m + 1), h);
        }
        if (res != -1)
        {
            return res;
        }
        if (m - 1 >= arr[l])
        {
            return binarySearch(arr, l, (m - 1));
        }
    }
    return -1;
}

int main()
{
    int arr[] = {-10, -5, 0, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << binarySearch(arr, 0, n - 1) << endl;
}