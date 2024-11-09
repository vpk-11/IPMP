#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximumTop(vector<int> &nums, int k)
{
    vector <int> v;
    for (int i = 0; i < k; i++)
    {
        if (nums.empty())
        {
            return -1;
        }
        v.push_back(nums.front());
        nums.erase(nums.begin());
    }
    
}

int main()
{
    int k = 1;
    int arr[] = {5,2,2,4,0,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> nums(arr, arr + n);
    cout << maximumTop(nums, k) <<endl;
}