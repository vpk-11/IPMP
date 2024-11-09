// Maximum subsequence sum such that no two elements are adjacent
#include <iostream>
#include <algorithm>
using namespace std;

int findMaxSum(int arr[], int N)
{
    if (N == 1)
    {
        return arr[0];
    }
    int dp[N][2];
    dp[0][0] = 0;
    dp[0][1] = arr[0];

    for (int i = 1; i < N; i++)
    {
        dp[i][1] = dp[i - 1][0] + arr[i];
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
    }
    return max(dp[N - 1][0], dp[N - 1][1]);
}

int main()
{
    int arr[] = {5, 5, 10, 100, 10, 5};
    int N = sizeof(arr) / sizeof(arr[0]);
    
    cout << findMaxSum(arr, N) << endl;
    return 0;
}
