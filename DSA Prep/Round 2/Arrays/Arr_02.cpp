// Number occuring Odd number of times
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int numberWithOddOccur(int v[], int n)
{
    if (n == 0)
    {
        return -1;
    }
    unordered_map<int, int> hash;
    for (int i = 0; i < n; i++)
    {
        hash[v[i]]++;
    }
    for (auto it : hash)
    {
        if (it.second % 2 != 0)
        {
            return it.first;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {2, 3, 5, 4, 5, 2, 4, 3, 5, 2, 4, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << numberWithOddOccur(arr, n) << endl;

    return 0;
}