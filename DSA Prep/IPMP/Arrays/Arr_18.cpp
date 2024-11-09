// Sum closest to 0
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

void MinSum(int n, int arr[])
{
    // Simple Method
    int sum = INT_MAX, index1 = 0, index2 = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((abs(arr[j] + arr[i]) < sum) && i != j)
            {
                sum = abs(arr[j] + arr[i]);
                index1 = i;
                index2 = j;
            }
        }
    }
    cout << "Min sum = " << arr[index1] + arr[index2] << " between " << arr[index1] << " & " << arr[index2] << endl;
    // O(nlogn) Method
    int l = 0, r = n - 1;
    sort(arr, arr + n);
    int min_sum;
    while (l < r)
    {
        if (abs(arr[l] + arr[r]) < abs(min_sum))
        {
            min_sum = abs(arr[l] + arr[r]);
            index1 = l;
            index2 = r;
        }
        if ((arr[l] + arr[r]) < 0)
            l++;
        if ((arr[l] + arr[r]) > 0)
            r--;
    }

    cout << "Min sum = " << arr[index1] + arr[index2] << " between " << arr[index1] << " & " << arr[index2] << endl;
}

int main()
{
    int arr[] = {1, 60, -10, 70, -80, 85};
    int n = sizeof(arr) / sizeof(arr[0]);

    MinSum(n, arr);

    return 0;
}