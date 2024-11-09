#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findKeyIndices(vector<int> &nums, int key)
{
    vector<int> v;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == key)
        {
            v.push_back(i);
        }
    }
    return v;
}

vector<int> findKDistantIndices(vector<int> &nums, int key, int k)
{
    vector<int> index = findKeyIndices(nums, key);
    vector<int> v;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < index.size(); j++)
        {
            if (k >= abs(i - index[j]))
            {
                v.push_back(i);
                break;
            }
        }
    }
    return v;
}

int main()
{
    int key = 9, k = 1;
    int arr[] = {3, 4, 9, 1, 3, 9, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> nums(arr, arr + n);
    vector<int> v = findKDistantIndices(nums, key, k);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}