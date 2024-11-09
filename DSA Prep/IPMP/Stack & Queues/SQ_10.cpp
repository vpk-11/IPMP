#include <iostream>
#include <stack>
using namespace std;

void printNGE(int arr[], int n) // Simple Method
{
    int next, i, j;
    for (i = 0; i < n; i++)
    {
        next = -1;
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                next = arr[j];
                break;
            }
        }
        cout << arr[i] << " --> " << next << endl;
    }
}
void printNGEStack(int arr[], int n)
{
    stack<int> s;
    s.push(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (s.empty())
        {
            s.push(arr[i]);
            continue;
        }
        else
        {
            while (!s.empty() && s.top() < arr[i])
            {
                cout << s.top() << " --> " << arr[i] << endl;
                s.pop();
            }
            s.push(arr[i]);
        }
    }
    while (!s.empty())
    {
        cout << s.top() << " --> " << -1 << endl;
        s.pop();
    }
}
// vector<long long> nextLargerElement(vector<long long> arr, int n)
// {
//     // Your code here
//     vector<long long> v(n, -1);
//     stack<int> s;

//     int i = 0;
//     while (i < n)
//     {
//         if (s.empty() || arr[i] <= arr[s.top()])
//         {
//             s.push(i);
//             i++;
//         }
//         else
//         {
//             v[s.top()] = arr[i];
//             s.pop();
//         }
//     }
//     return v;
// }
int main()
{
    int arr[] = {1, 13, 21, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printNGE(arr, n);
    printNGEStack(arr, n);
}