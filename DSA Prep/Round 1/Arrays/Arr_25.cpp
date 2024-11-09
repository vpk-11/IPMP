// Construct Product Array without division operator:
// each element = product of elements in arr[] except arr[i]
#include <iostream>
#include <vector>
using namespace std;

vector<int> productArray(int arr[], int n)
{
    vector<int> v;
    if (n == 0)
    {
        return v;
    }
    if (n == 1)
    {
        v.push_back(1);
        return v;
    }
    int left[n];
    int right[n];
    left[0] = 1;
    right[n - 1] = 1;
    for (int i = 1; i < n; i++)
    {
        left[i] = arr[i - 1] * left[i - 1];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = arr[i + 1] * right[i + 1];
    }
    for (int i = 0; i < n; i++)
    {
        v.push_back(left[i] * right[i]);
    }
    return v;
}

int main()
{
    int arr[] = {10, 3, 5, 6, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The product array is: \n";
    vector<int> v = productArray(arr, n);
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}