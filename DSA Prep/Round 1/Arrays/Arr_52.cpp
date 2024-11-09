// Leader in Array
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> leaders(int a[], int n)
{
    vector<int> ans;
    stack<int> st;
    st.push(a[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] >= st.top())
        {
            st.push(a[i]);
        }
    }
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main()
{
    int arr[] = {16, 17, 4, 3, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v = leaders(arr, n);
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}