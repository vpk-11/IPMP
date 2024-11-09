// Rotate Array by d elements
#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void rotateArray(int arr[], int n, int d)
{
    d = d % n;
    int g_c_d = gcd(d, n);
    cout << g_c_d << endl;
    for (int i = 0; i < g_c_d; i++)
    {
        int temp = arr[i];
        int j = i;

        while (true)
        {
            int k = j + d;
            if (k >= n)
            {
                k = k - n;
            }
            
            if (k == i)
            {
                break;
            }
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    rotateArray(arr, n, 3);
    printArray(arr, n);
    return 0;
}