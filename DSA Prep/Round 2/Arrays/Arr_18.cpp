// Sum Closest to 0
// Finding 2 numbers so that thier diff is minimum
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

pair<int, int> minAbsSum(int arr[], int n)
{
    pair<int, int> p;
    p.first = -1;
    p.second = -1;
    sort(arr, arr + n);
    int l = 0, r = n - 1;
    int minSum = INT_MAX;
    while (l < r)
    {
        int sum = arr[l] + arr[r];
        if (minSum > abs(sum))
        {
            minSum = abs(sum);
            p.first = arr[l];
            p.second = arr[r];
        }
        else if (abs(sum) == abs(minSum))
        {
            minSum = max(sum, minSum);
        }
        if (sum > 0)
            r--;
        else
            l++;
    }
    return p;
}

int main()
{
    int arr[] = {1, 60, -10, 70, -80, 85};
    int n = sizeof(arr) / sizeof(arr[0]);
    pair<int, int> p = minAbsSum(arr, n);
    cout << "Elements are " << p.first << " & " << p.second << endl;
}