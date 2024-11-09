// Sort 0s, 1s
#include <iostream>
using namespace std;

int main()
{
    int arr[] = {0, 1, 0, 1, 0, 0, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int count0 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            count0++;
        }
    }
    for (int i = 0; i < count0; i++)
    {
        arr[i] = 0;
    }
    for (int i = count0; i < n; i++)
    {
        arr[i] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}