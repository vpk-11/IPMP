#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<int> v, int k){
    if(v.size() == 0){
        return false;
    }
    for (int i = 0; i < v.size(); i++)
    {
        if(k == v[i]){
            return true;
        }
    }
    return false;
}

vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
{
    vector<vector<int>> diff(2);
    for (int i = 0; i < nums1.size(); i++)
    {
        if(check(diff[0], nums1[i])){
            continue;
        }
        if(i > 0 && nums1[i-1] == nums1[i]){
            continue;
        }
        bool flag = false;
        for (int j = 0; j < nums2.size(); j++)
        {
            if (nums1[i] == nums2[j])
            {
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            diff[0].push_back(nums1[i]);
        }
    }
    for (int i = 0; i < nums2.size(); i++)
    {
        if(check(diff[1], nums2[i])){
            continue;
        }
        if(i > 0 && nums2[i-1] == nums2[i]){
            continue;
        }
        bool flag = false;
        for (int j = 0; j < nums1.size(); j++)
        {
            if (nums2[i] == nums1[j])
            {
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            diff[1].push_back(nums2[i]);
        }
    }
    return diff;
}

int main()
{
}