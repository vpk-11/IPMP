// 2 Numbers occuring Odd number of times
#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> numberWithOddOccur(int arr[], int n)
{
    vector<int> v;
    map<int, int> hash;
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }
    for (auto it : hash)
    {
        if (it.second % 2 != 0)
        {
            v.push_back(it.first);
        }
    }
    return v;
}

int main()
{
    int arr[] = {2, 3, 7, 9, 11, 2, 3, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v = numberWithOddOccur(arr, n);
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}