// Problem Statement
// The bitwise AND of an array nums is the bitwise AND of all integers in nums.
// For example, for nums = [1, 5, 3], the bitwise AND is equal to 1 & 5 & 3 = 1.
// Also, for nums = [7], the bitwise AND is 7.
// You are given an array of positive integers candidates.
// Evaluate the bitwise AND of every combination of numbers of candidates.
// Each number in candidates may only be used once in each combination.
// Return the size of the largest combination of candidates with a bitwise AND greater than 0.

#include <iostream>
#include <vector>
using namespace std;

// int largestCombination(vector<int> &can)
// {
//     int i, j, n = can.size(), ans = 0, curr;
//     for (i = 0; i <= 30; i++)
//     {
//         curr = 0;
//         for (j = 0; j < n; j++)
//         {
//             if (can[j] & (1 << i))
//             {
//                 curr++;
//             }
//         }
//         ans = max(ans, curr);
//     }
//     return ans;
// }

int largestCombination(vector<int> &candidates)
{
    int n = candidates.size();
    int a[32] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            if (candidates[i] & (1 << j))
                a[j]++;
        }
    }
    int max_val = 0;
    for (int i = 0; i < 32; i++)
    {
        if (a[i] > max_val)
            max_val = a[i];
    }
    return max_val;
}

int main()
{
}