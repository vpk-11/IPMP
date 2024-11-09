// Multiply the found value by 2 and search again
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int BinarySearch(vector<int> arr, int l, int r, int key)
{
    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (arr[m] == key)
            return m;

        if (arr[m] < key)
            l = m + 1;

        else
            r = m - 1;
    }

    return -1;
}

int findFinalValue(vector<int> nums, int original)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int key = original;
    int x = 0;
    while (x != -1)
    {
        x = BinarySearch(nums, 0, n-1, key);
        key = key * 2;
    }

    return key/2;
}

int main()
{
    vector<int> nums;
    nums.push_back(5);
    nums.push_back(3);
    nums.push_back(6);
    nums.push_back(1);
    nums.push_back(12);
    cout << "Original = " << findFinalValue(nums, 3) << endl;
}
