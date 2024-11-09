// Stock Span Problem
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> calculateSpan(int price[], int n)
{
    stack<int> s;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && price[s.top()] <= price[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            ans.push_back(i + 1);
        }
        else
        {
            ans.push_back(i - s.top());
        }
        s.push(i);
    }
    return ans;
}

void printArray(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

int main()
{
    int price[] = {10, 4, 5, 90, 120, 80};
    int n = sizeof(price) / sizeof(price[0]);
    int S[n];

    vector<int> v = calculateSpan(price, n);
    printArray(v);

    return 0;
}
