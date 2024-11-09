// Min no of lines req to draw the line chart given the coordinates

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long area(vector<int> a, vector<int> b, vector<int> c)
{
    return (long long)(b[0] - a[0]) * (c[1] - a[1]) - (long long)(b[1] - a[1]) * (c[0] - a[0]);
}

int minimumLines(vector<vector<int>> &a)
{
    sort(a.begin(), a.end(), [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; }); // sorting based on x coordinates
    int n = a.size();
    int result = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        if (i == 0 || area(a[i - 1], a[i], a[i + 1]) != 0)
        {
            ++result;
        }
    }
    return result;
}