// Two Sum Problem
#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> twoSum(int arr[], int n, int sum)
{
    map<int, int> hash;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        if (hash[sum - arr[i]])
        {
            v.push_back(i);
            v.push_back(hash[sum - arr[i]]);
            return v;
        }
        else
        {
            hash[arr[i]] = i;
        }
    }
    v.push_back(-1);
    v.push_back(-1);
    return v;
}

int main()
{
    int arr[] = {0, -1, 2, -3, 1};
    int sum = -2;
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v = twoSum(arr, n, sum);
    cout << "The twoSum pair has indices : " << v[0] << " & " << v[1] << " with values " << arr[v[0]] << " & " << arr[v[1]] << endl;
    return 0;
}