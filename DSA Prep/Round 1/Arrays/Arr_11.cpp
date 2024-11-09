// Four Numbers that give the sum
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>
using namespace std;

void fourSum(int arr[], int n, int X)
{
    unordered_map<int, pair<int, int> > hash;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            pair<int, int> p;
            p.first = i;
            p.second = j;
            hash[arr[i] + arr[j]] = p;
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int sum = arr[i] + arr[j];
            if (hash.find(X - sum) != hash.end())
            {
                pair<int, int> p = hash[X - sum];
                if (p.first != i && p.first != j && p.second != i && p.second != j)
                {
                    cout << arr[i] << ", " << arr[j] << ", " << arr[p.first] << ", " << arr[p.second] << endl;
                    return;
                }
            }
        }
    }
}

int main()
{
    int arr[] = {12, 3, 4, 1, 6, 9, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 25;

    fourSum(arr, n, sum);
    return 0;
}