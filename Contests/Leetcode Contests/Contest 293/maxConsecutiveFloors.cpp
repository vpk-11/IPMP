// Problem Statement

// Alice manages a company and has rented some floors of a building as office space.
// Alice has decided some of these floors should be special floors, used for relaxation only.
// You are given two integers bottom and top,
// which denote that Alice has rented all the floors from bottom to top (inclusive).
// You are also given the integer array special,
// where special[i] denotes a special floor that Alice has designated for relaxation.
// Return the maximum number of consecutive floors without a special floor.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxConsecutiveFloors(int bottom, int top, vector<int> &special)
{
    int maxCount = 0;
    int count = 0;
    sort(special.begin(), special.end());
    count = special[0] - bottom;
    count = max(count, top - special[special.size() - 1]);
    for (int i = 0; i < special.size() - 1; i++)
    {
        int x = (special[i + 1] - special[i]) - 1;
        count = max(x, count);
    }
    return count;
}

int main()
{
    int T;
    cin >> T;
    while (T < 0)
    {
        vector<int> special;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            special.push_back(x);
        }
        int bottom, top;
        cin >> bottom >> top;
        cout << maxConsecutiveFloors(bottom, top, special) << endl;
        T--;
    }
}