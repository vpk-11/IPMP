// Alternate positive and negative numbers in Array
#include <iostream>
#include <vector>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void altPosNegNums(int arr[], int n)
{
    // If i dont care about the order
    /*
    // Array Partion
    // neg on left, pos on right
    int i = -1;
    for (int j = 0; j < n; j++)
    {
        if (arr[j] < 0)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    int pos = i + 1, neg = 0;
    // Alt Swap
    while (pos < n && neg < pos && arr[neg] < 0)
    {
        swap(&arr[neg], &arr[pos]);
        pos++;
        neg += 2;
    }
    */
    // if i care about the order
    vector<int> pos, neg;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
            pos.push_back(arr[i]);
        else
            neg.push_back(arr[i]);
    }

    int n1 = pos.size();
    int n2 = neg.size();
    int i = 0, j = 0, k = 0;

    while (k < n)
    {
        if (i < n1)
            arr[k++] = pos[i++];
        if (k < n)
        {
            if (j < n2)
                arr[k++] = neg[j++];
        }
    }
}

int main()
{
    int arr[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    altPosNegNums(arr, n);
    printf("%s\n", "Array after func:");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}