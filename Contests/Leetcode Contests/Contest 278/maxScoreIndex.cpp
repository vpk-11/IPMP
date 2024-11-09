// Multiply the found value by 2 and search again
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <unordered_map>
using namespace std;

vector<int> maxScoreIndex(vector<int> nums)
{
    vector<int> index;
    unordered_map<int, int> p;
    int mid = 0;
    int maxCount = 0;
    while (mid <= nums.size())
    {
        int Lcount = 0, Rcount = 0;
        for (int i = 0; i < mid; i++)
        {
            if (nums[i] == 0)
                Lcount++;
        }
        for (int i = mid; i < nums.size(); i++)
        {
            if (nums[i] == 1)
                Rcount++;
        }
        if (maxCount <= Lcount + Rcount)
        {
            maxCount = Lcount + Rcount;
            p[mid] = maxCount;
        }
        mid++;
    }
    for (int i = 0; i < p.size(); i++)
    {
        if (p[i] == maxCount)
            index.push_back(i);
    }
    return index;
}

int main()
{
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(0);
    vector<int> v = maxScoreIndex(nums);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
