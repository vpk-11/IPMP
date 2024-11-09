// Problem Statement

// Given an empty set of intervals, implement a data structure that can:

// Add an interval to the set of intervals.
// Count the number of integers that are present in at least one interval.
// Implement the CountIntervals class:

// CountIntervals() Initializes the object with an empty set of intervals.
// void add(int left, int right) Adds the interval [left, right] to the set of intervals.
// int count() Returns the number of integers that are present in at least one interval.
// Note that an interval [left, right] denotes all the integers x where left <= x <= right.

#include <iostream>
#include <map>
#include <vector>
using namespace std;

class CountIntervals
{
public:
    CountIntervals()
    {
    }

    void add(int left, int right)
    {
        if (intervals.empty())
        {
            ans += right - left + 1;
            intervals[left] = right;
            return;
        }
        vector<int> remove;
        auto it = intervals.lower_bound(left);
        if (it != intervals.begin())
        {
            it--;
            if (it->second >= left)
            {
                ans -= (it->second - it->first + 1);
                remove.push_back(it->first);
                left = min(left, it->first);
                right = max(right, it->second);
            }
            it++;
        }
        while (it != intervals.end())
        {
            if (it->first <= right && it->second >= left)
            {
                ans -= (it->second - it->first + 1);
                remove.push_back(it->first);
                left = min(left, it->first);
                right = max(right, it->second);
            }
            else
            {
                break;
            }
            it++;
        }
        ans += (right - left + 1);
        for (int x : remove)
        {
            intervals.erase(x);
        }
        intervals[left] = right;
    }

    int count()
    {
        return ans;
    }

private:
    map<int, int> intervals;
    int ans = 0;
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */

int main()
{
}