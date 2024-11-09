// Maximum Element in a subarray of size K
#include <iostream>
#include <stack>
#include <vector>
#include <climits>
using namespace std;

vector<int> maxElemInWindow(int arr[], int n, int k)
{
    vector<int> v;
    for (int i = 0; i < n - k + 1; i++)
    {
        stack<int> s;

        int max = INT_MIN;
        for (int j = 0; j < k; j++)
        {
            if (max < arr[i + j])
            {
                max = arr[i + j];
            }
        }
        v.push_back(max);
    }
    return v;
}

int main()
{
    int arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k;
    cin >> k;
    vector<int> v = maxElemInWindow(arr, n, k);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}