// Max Area Rectangle in histogram
#include <iostream>
#include <stack>
#include <climits>
using namespace std;

int getMaxArea(int hist[], int n)
{
    stack<int> s;

    int max_area = INT_MIN, tp, curr_area, i = 0;
    while (i < n)
    {
        if (s.empty() || hist[s.top()] <= hist[i])
        {
            s.push(i);
            i++;
        }
        else
        {
            tp = s.top();
            s.pop();
            if (s.empty())
            {
                curr_area = hist[tp] * i;
            }
            else
            {
                curr_area = hist[tp] * (i - s.top() - 1);
            }
            if (max_area < curr_area)
                max_area = curr_area;
        }
    }

    while (!s.empty())
    {
        tp = s.top();
        s.pop();
        if (s.empty())
        {
            curr_area = hist[tp] * i;
        }
        else
        {
            curr_area = hist[tp] * (i - s.top() - 1);
        }

        if (max_area < curr_area)
            max_area = curr_area;
    }

    return max_area;
}

int main()
{
    int hist[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(hist) / sizeof(hist[0]);
    cout << "Maximum area is " << getMaxArea(hist, n) << endl;
    return 0;
}
