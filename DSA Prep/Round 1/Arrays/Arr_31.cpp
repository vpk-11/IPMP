// Min Max in Array
#include <iostream>
using namespace std;

struct numPair
{
    int min;
    int max;
};
numPair getMinMax(int arr[], int n)
{
    int min, max; int i;
    if (n % 2 == 0)
    {
        if (arr[0] > arr[1])
        {
            min = arr[1];
            max = arr[0];
        }
        else
        {
            min = arr[0];
            max = arr[1];
        }
        i=2;
    }
    else
    {
        min = max = arr[0];
        i = 1;
    }
    while(i<n-1)
    {
        if (arr[i] > arr[i + 1])
        {
            if (max < arr[i])
            {
                max = arr[i];
            }
            if (min > arr[i + 1])
            {
                min = arr[i + 1];
            }
        }
        else
        {
            if (max < arr[i + 1])
            {
                max = arr[i + 1];
            }
            if (min > arr[i])
            {
                min = arr[i];
            }
        }
        i+=2;
    }
    struct numPair minMax;
    minMax.min = min;
    minMax.max = max;
    return minMax;
}
int main()
{
    int min, max;
    int arr[] = {100, 330, 11, 445, 1, 3000};
    int n = sizeof(arr) / sizeof(arr[0]);
    if (arr[0] > arr[1])
    {
        min = arr[1];
        max = arr[0];
    }
    else
    {
        min = arr[0];
        max = arr[1];
    }
    for (int i = 2; i < n; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    cout << min << " " << max << endl;

    struct numPair numSet = getMinMax(arr, n);
    cout << numSet.min << " " << numSet.max << endl;
    return 0;
}
