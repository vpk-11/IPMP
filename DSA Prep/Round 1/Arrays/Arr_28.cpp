// Segregate Even and Odd
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void segregateEvenAndOdd(int arr[], int n)
{
    // Unstable Segregation
    /*
    int l = 0, r = n - 1;
    while (l <= r)
    {
        while (arr[l] % 2 == 0 && l < r)
        {
            l++;
        }
        while (arr[r] % 2 == 1 && l < r)
        {
            r--;
        }
        if (l < r)
        {
            swap(arr[l], arr[r]);
            l++;
            r--;
        }
    }
    */
    // Stable Seggregation
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            j++;
            swap(arr[i], arr[j]);
        }
    }
}

int main()
{
    int arr[] = {9,8,7,6,5,4,3,2,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i = 0;

    segregateEvenAndOdd(arr, n);

    cout << "Array after segregation ";
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}