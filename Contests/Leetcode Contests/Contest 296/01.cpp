#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minMaxGame(vector<int> &nums)
{
    if (nums.size() == 1)
    {
        return nums[0];
    }
    while (nums.size() > 1)
    {
        int n = nums.size();
        vector<int> newNums;
        for (int i = 0; i < n / 2; i++)
        {
            if (i % 2 == 0)
            {
                int m = min(nums[2 * i], nums[2 * i + 1]);
                cout << m << " ";
                newNums.push_back(m);
            }
            else
            {
                int m = max(nums[2 * i], nums[2 * i + 1]);
                cout << m << " ";
                newNums.push_back(m);
            }
        }
        cout << endl;
        nums = newNums;
        cout << nums.size() << endl;
    }
    return nums[0];
}

int main()
{
    int arr[] = {999, 939, 892, 175, 114, 464, 850, 107};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> nums(arr, arr + n);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    cout << minMaxGame(nums) << endl;
}