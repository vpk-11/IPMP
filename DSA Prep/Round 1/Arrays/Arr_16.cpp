// Max Diff b/w 2 nums in array that appear after one another
#include <iostream>
using namespace std;

// Variation of this Problem
int findMaxDiff(int arr[], int n)
{
    // For finding max diff between the left smallest and right smallest of any element
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int r = 0;
        int l = 0;
        for (int j = i; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                r = arr[j];
                break;
            }
        }
        for (int j = i; j >= 0; j--)
        {
            if (arr[i] > arr[j])
            {
                l = arr[j];
                break;
            }
        }
        ans = max(ans, abs(l - r));
    }
    return ans;
}

int maxDiff(int arr[], int n)
{
    if (n <= 1)
    {
        return 0;
    }
    int maxiDiff = arr[1] - arr[0];

    int minElem = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - minElem > maxiDiff)
        {
            maxiDiff = arr[i] - minElem;
        }
        if (arr[i] < minElem)
        {
            minElem = arr[i];
        }
    }
    return maxiDiff;
}

int main()
{
    int arr[] = {1, 2, 90, 10, 110};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum difference is " << maxDiff(arr, n) << endl;
}