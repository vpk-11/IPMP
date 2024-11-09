#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void rearrange(int arr[], int n)
{
    int i = -1;
    // utility code that pushes all the negative numbers to the front
    for (int j = 0; j < n; j++)
    {
        if (arr[j] < 0)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    int pos_point = i + 1, neg_point = 0;
    while (pos_point < n && neg_point < pos_point && arr[neg_point] < 0)
    {
        swap(&arr[neg_point], &arr[pos_point]);
        pos_point++;
        neg_point += 2; // every alternate negative number
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {1, 2, -3, 4, 5, 6, -7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    rearrange(arr, n);
    return 0;
}
