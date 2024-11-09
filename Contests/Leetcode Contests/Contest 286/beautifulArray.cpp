#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<int> v, int k)
{
    if (v.size() == 0)
    {
        return false;
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (k == v[i])
        {
            return true;
        }
    }
    return false;
}

int findDifference(vector<int> &nums)
{
    int count = 0;
    if(nums.size() == 0){
        return count;
    }
    if(nums.size() == 1){
        return 1;
    }
    vector<int>::iterator it;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i % 2 == 0)
        {
            if (nums[i] == nums[i + 1])
            {
                it = nums.begin() + i;
                nums.erase(it);
                count++;
            }
        }
    }
    if (nums.size() % 2 == 0)
    {
        return count;
    }
    else
    {
        return count + 1;
    }
}

int main()
{
}