// no of Occurances of x in given array
#include <iostream>
using namespace std;

int countOccur(int arr[], int l, int h, int key)
{
    if (l <= h)
    {
        int mid = (l + h) / 2;
        if (key == arr[mid])
            return countOccur(arr, l, mid - 1, key) + countOccur(arr, mid + 1, h, key) + 1;

        if (key > arr[mid])
            return countOccur(arr, (mid + 1), h, key);

        return countOccur(arr, l, (mid - 1), key);
    }
    return 0;
}

int main()
{
    int arr[] = {1, 1, 2, 2, 2, 2, 3,};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << countOccur(arr, 0, n - 1, 2) <<  endl;
}