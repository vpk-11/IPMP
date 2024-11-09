// Segregate 0s & 1s
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void segregate0sAnd1s(int arr[], int n)
{
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            j++;
            swap(arr[i], arr[j]);
        }
    }
}

int main()
{
    int arr[] = { 0, 1, 0, 1, 1, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int i = 0;

    segregate0sAnd1s(arr, n);

    cout << "Array after segregation ";
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}