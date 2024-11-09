// Sorted Subsequence of size 3
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>
using namespace std;

vector<int> sortedSubSeq(int arr[], int n)
{
    int max = n - 1, min = 0;
    int smaller[n];
    vector<int> v;
    smaller[0] = -1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] <= arr[min])
        {
            min = i;
            smaller[i] = -1;
        }
        else
        {
            smaller[i] = min;
        }
    }

    int greater[n];

    greater[n - 1] = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] >= arr[max])
        {
            max = i;
            greater[i] = -1;
        }
        else
        {
            greater[i] = max;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (smaller[i] != -1 && greater[i] != -1)
        {
            v.push_back(smaller[i]);
            v.push_back(i);
            v.push_back(greater[i]);
            return v;
        }
    }
    cout << "No such triplet found";
    return v;
}

int main()
{
    int arr[] = {12, 11, 10, 5, 6, 2, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v = sortedSubSeq(arr, n);
    for (auto it : v)
    {
        cout << it << " - " << arr[it] << endl;
    }
    return 0;
}
