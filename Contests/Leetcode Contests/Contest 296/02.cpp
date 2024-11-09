#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int partitionArray(vector<int> &nums, int k)
{
    vector<vector<int> > v;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        vector<int> b;
        b.push_back(nums[i]);
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] - nums[j] <= k)
            {
                b.push_back(nums[j]);
                // nums.erase(nums.begin() + j);
            }
            else
            {
                break;
            }
        }
        // nums.erase(nums.begin() + i);
        for (auto it : b)
        {
            cout << it << " ";
        }
        cout << endl;
        v.push_back(b);
    }

    return v.size();
}

int main()
{
    // int arr[] = {3, 6, 1, 2, 5};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // vector<int> nums(arr, arr + n);
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     cout << nums[i] << " ";
    // }
    // cout << endl;
    // int k;
    // cin >> k;
    // cout << partitionArray(nums, k) << endl;
    vector <string> s;
    s.push_back("leafcode");
    s.push_back("leet");
    s.push_back("leeds");
    sort(s.begin(), s.end());
    for (auto it : s)
    {
        cout << it << " ";
    }
    
}