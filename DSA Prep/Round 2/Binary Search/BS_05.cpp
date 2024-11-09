// Find smallest unsorted subarray in array

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> printUnsorted(int arr[], int n)
{
    vector <int> v;
    int l = 0, h = n - 1, i;
    while (l < n - 1)
    {
        if (arr[l] > arr[l + 1])
            break;
        l++;
    }
    if (l == n - 1)
    {
        v.push_back(0);
        v.push_back(0);
        return v;
    }
    while (h > 1)
    {
        if (arr[h - 1] > arr[h])
            break;
        h--;
    }
    int low = arr[l], high = arr[l];
    for (i = l + 1; i <= h; i++)
    {
        low = min(arr[i], low);
        high = max(arr[i], high);
    }
    for (i = 0; i <= l - 1; i++)
    {
        if (arr[i] > low)
        {
            l = i;
            break;
        }
    }
    for (i = n - 1; i >= h + 1; i--)
    {
        if (arr[i] < high)
        {
            h = i;
            break;
        }
    }
    v.push_back(l);
    v.push_back(h);
    return v;
}

int main()
{
    int arr[] = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v = printUnsorted(arr, n);
    cout << "Indices are: " << v[0] << " and " << v[1] << endl;
    return 0;
}