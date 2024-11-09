// Merge Sort
#include <iostream>
using namespace std;

void merge(int A[], int l, int mid, int r)
{
    int B[r + 1];
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r)
    {
        if (A[i] < A[j])
        {
            B[k++] = A[i++];
        }
        else
        {
            B[k++] = A[j++];
        }
    }
    while (i <= mid)
    {
        B[k++] = A[i++];
    }
    while (j <= r)
    {
        B[k++] = A[j++];
    }
    for (int i = l; i <= r; i++)
    {
        A[i] = B[i];
    }
}

void mergeSort(int A[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(A, l, mid);
        mergeSort(A, mid + 1, r);
        merge(A, l, mid, r);
    }
}

int main()
{
}