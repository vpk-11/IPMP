// Find kth smallest element
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void kLargest(vector<int> &v, int N, int K)
{
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0; i < N; ++i)
    {
        pq.push(v[i]);

        if (pq.size() > K)
        {
            pq.pop();
        }
    }

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

void kSmalest(vector<int> &v, int N, int K)
{

    priority_queue<int> pq;
    for (int i = 0; i < N; ++i)
    {
        pq.push(v[i]);
        if (pq.size() > K)
        {
            pq.pop();
        }
    }
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}

int main()
{
    int arr[] = {11, 3, 2, 1, 15, 5, 4, 45, 88, 96, 50, 45};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v(arr, arr + n);
    int k = 3;
    cout << k << " largest elements are : ";
    kLargest(v, n, k);
    cout << k << " smallest elements are : ";
    kSmalest(v, n, k);
}
