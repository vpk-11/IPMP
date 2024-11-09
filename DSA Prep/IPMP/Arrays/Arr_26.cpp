// Segr even and odd
#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void segEvenOdd(int arr[], int n)
{
    int left = 0, right = n - 1;
    while (left < right)
    {
        while (arr[left] % 2 == 0 && left < right)
            left++;
        
        while (arr[right] % 2 == 1 && left < right)
            right--;
        
        if (left < right)
        {
            swap(&arr[left], &arr[right]);
            left++; right--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {10, 21, 20, 11, 30, 40, 31, 41};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    segEvenOdd(arr, n);
}