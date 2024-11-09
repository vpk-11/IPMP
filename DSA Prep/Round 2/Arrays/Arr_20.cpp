// Find Duplicates in O(n) Time
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> duplicates(int arr[], int n)
{
    vector<int> v;
    if (n == 0 || n == 1)
    {
        return v;
    }
    map<int, int> hash;
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }
    for (auto it : hash)
    {
        if (it.second > 1)
        {
            v.push_back(it.first);
        }
    }
    return v;

    // Method 2
    vector<int> arry;
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            arry.push_back(arr[i]);
            if (arr[i] == arr[i + 2])
                arry.pop_back();
        }
    }
    if (arry.size() == 0)
    {
        arry.push_back(-1);
    }
    return arry;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 1, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> v = duplicates(arr, n);
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}