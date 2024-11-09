// Sum Triplet
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void tripletSum(int arr[], int n, int sum)
{
    vector<int> v;
    // Brute Force Method
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         for (int k = j + 1; k < n; k++)
    //         {
    //             if (sum == arr[i] + arr[j] + arr[k])
    //             {
    //                 v.push_back(i);
    //                 v.push_back(j);
    //                 v.push_back(k);
    //             }
    //         }
    //     }
    // }
    sort(arr, arr + n);
    for (int i = 0; i < n - 2; i++)
    {
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            if (arr[i] + arr[j] + arr[k] == sum)
            {
                cout << "Triplet with the given sum have values " << arr[i] << ", " << arr[j] 
                     << " & " << arr[k] << endl;
                break;
            }
            else if (arr[i] + arr[j] + arr[k] < sum)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }
}

int main()
{
    int arr[] = {12, 3, 4, 1, 6, 9, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 25;
    // vector<int> v = tripletSum(arr, n, sum);
    tripletSum(arr, n, sum);
    // cout << "Triplet with the given sum is at indices " << v[0] << ", " << v[1] << " & " << v[2] << " " << endl;
    // cout << "Triplet with the given sum have values " << arr[v[0]] << ", " << arr[v[1]] << " & " << arr[v[2]]
    //      << " " << endl;
    return 0;
}