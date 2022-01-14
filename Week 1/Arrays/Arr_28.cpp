// Sort 0s 1s 2s
#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort012(int arr[], int n)
{
    int low = 0;
    int high = n - 1;
    int mid = 0;

    while (mid <= high)
    {
        switch (arr[mid])
        {
        case 0:
            swap(&arr[low], &arr[mid]); 
            low++; mid++;
            break;

        case 1:
            mid++;
            break;

        case 2:
            swap(&arr[mid], &arr[high]); 
            high--;
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {0, 1, 2, 0, 0, 1, 1, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort012(arr,n);
}