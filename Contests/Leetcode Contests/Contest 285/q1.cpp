#include <iostream>
#include <vector>
using namespace std;

int countHillValley(vector<int> &nums)
{
    int count = 0;
    for (int i = 1; i < nums.size() - 1; i++)
    {
        int j = i - 1, k = i + 1;
        if(nums[i] == nums[i-1])
        {
            continue;
        }
        while (j > 0)
        {
            if (nums[j] != nums[i])
            {
                break;
            }
            j--;
        }
        while (k < nums.size() - 1)
        {
            if (nums[k] != nums[i])
            {
                break;
            }
            k++;
        }
        if (nums[i] > nums[j] && nums[i] > nums[k])
        {
            count++;
        }
        else if (nums[i] < nums[j] && nums[i] < nums[k])
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int arr[] = {2,4,1,1,6,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> nums(arr, arr + n);

    cout << countHillValley(nums) << endl;
}