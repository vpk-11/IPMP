// Put all 0s in the end
#include <iostream>
using namespace std;

void pushZeroToEnd(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]!= 0)
        {
            arr[count] = arr[i];
            count++;
        }
    }
    while (count<n)
    {
        arr[count] = 0;
        count++;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {1,2,3,0,4,0,6,0,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    pushZeroToEnd(arr, n);
}