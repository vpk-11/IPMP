// Sort an Array of 0s, 1s and 2s
#include <iostream>
using namespace std;

void sort0s1s2s(int arr[], int n)
{
    int z = 0;
    int o = 0;
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            z++;
        }
        else if (arr[i] == 1)
        {
            o++;
        }
        else if (arr[i] == 2)
        {
            t++;
        }
    }
    int i = 0;
    while (z > 0)
    {
        arr[i++] = 0;
        z--;
    }
    while (o > 0)
    {
        arr[i++] = 1;
        o--;
    }
    while (t > 0)
    {
        arr[i++] = 2;
        t--;
    }
}

int main()
{
    int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int n = sizeof(arr) / sizeof(int);

    sort0s1s2s(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}