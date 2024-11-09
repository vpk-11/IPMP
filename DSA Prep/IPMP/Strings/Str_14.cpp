//
#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;

bool duplicates(string str, int i, int j)
{
    vector<bool> v(26);
    for (int k = i; k <= j; k++)
    {
        if (v[str[k] - 'A'] == true)
        {
            return false;
        }
        v[str[k] - 'A'] = true;
    }
    return true;
}
int maxUniqueSubstring(string str)
{
    int ans = INT_MIN;
    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        for (int j = i; j < len; j++)
        {
            if (duplicates(str, i, j))
            {
                ans = max(ans, j - i + 1);
            }
        }
    }
    return ans;
}

int main()
{
    string str = "GEEKSFORGEEKS";
    cout << maxUniqueSubstring(str) << endl;
    return 0;
}