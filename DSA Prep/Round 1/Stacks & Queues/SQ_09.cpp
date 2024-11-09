// Next Greater Element
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreaterElem(int arr[], int n)
{
    stack<int> s;
    vector<int> v(n);
    for (int i = n - 1; i >= 0; i--)
    {
        if (!s.empty())
        {
            while (!s.empty() && s.top() <= arr[i])
            {
                s.pop();
            }
        }
        v[i] = (s.empty()) ? -1 : s.top();
        s.push(arr[i]);
    }
    return v;
}

int main()
{
    int arr[] = {11, 13, 21, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v = nextGreaterElem(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " --> " << v[i] << endl;
    }
    return 0;
}