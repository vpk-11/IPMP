// Majority Element
#include <iostream>
#include <algorithm>
using namespace std;

int findMajorityElem(int arr[], int n)
{
    if (n == 1)
        return arr[0];

    int count = 1;
    sort(arr, arr + n);
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] == arr[i])
        {
            count++;
        }
        else
        {
            if (count > n / 2)
            {
                return arr[i - 1];
            }
            count = 1;
        }
    }
    return -1;
}

int findMajElem(int arr[], int n)
{
    int index = 0, count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[index] == arr[i])
        {
            count++;
        }
        else
        {
            count--;
        }
        if (count == 0)
        {
            index = i;
            count = 1;
        }
    }
    return arr[index];
}

bool isMajority(int arr[], int n, int x)
{
    int count = 0;
    for (int i = 0; i < n; i++)

        if (arr[i] == x)
            count++;

    if (count > n / 2)
        return 1;

    else
        return 0;
}

void printMajority(int arr[], int n)
{
    int x = findMajElem(arr, n);
    if (isMajority(arr, n, x))
    {
        cout << x << endl;
    }
    else
    {
        cout << "No Majority Element" << endl;
    }
}

int main()
{
    int arr[] = {2, 1, 2, 1, 2, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printMajority(arr, n);

    return 0;
}