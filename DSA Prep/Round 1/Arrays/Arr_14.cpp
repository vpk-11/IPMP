// Least Positive missing number
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int leastPosMissElem(int arr[], int n)
{
    if (n <= 1)
    {
        return 1;
    }
    bool present[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        present[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0 && arr[i] <= n)
        {
            present[arr[i]] = true;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (!present[i])
        {
            return i;
        }
    }
    return n + 1;
}

int main()
{
    int arr[] = {2, 3, 7, 6, 8, -1, -10, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "L P M N = " << leastPosMissElem(arr, n) << endl;
}