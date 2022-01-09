// Counting Sort
#include <iostream>
using namespace std;
#define N 50

void countSort(int arr[], int n)
{
    int count[N], b[n];
    for (int i = 0; i < N; i++)
        count[i] = 0;

    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    for (int i = 1; i < N; i++)
        count[i] = count[i] + count[i - 1];

    for (int i = n - 1; i >= 0; --i)
    {
        b[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }
    for (int i = 0; i < n; i++)
        arr[i] = b[i];

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int n;
    int arr[] = {2, 1, 1, 0, 2, 5, 4, 0, 2, 8, 7, 7, 9, 2, 0, 1, 9};
    int a[] = {6, 5, 4, 3, 2, 1, 0};
    n = sizeof(arr) / sizeof(arr[0]);
    countSort(arr, n);
    cout << endl;
    n = sizeof(a) / sizeof(a[0]);
    countSort(a, n);
}