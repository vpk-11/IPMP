// Min Cost Algorithm
#include <iostream>
#include <algorithm>
using namespace std;
#define M 5
#define N 5

int min(int x, int y, int z)
{
    if (x < y)
        return (x < z) ? x : z;
    else
        return (y < z) ? y : z;
}

int minCost(int cost[M][N], int m, int n)
{
    int i, w;
    int K[M + 1][N + 1];
    K[0][0] = cost[0][0];
    for (int i = 1; i < M; i++)
    {
        K[i][0] = K[i - 1][0] + cost[i][0];
    }
    for (int i = 1; i < M; i++)
    {
        K[0][i] = K[0][i - 1] + cost[0][i];
    }
    for (int i = 1; i < M; i++)
    {
        for (int j = 1; j < N; j++)
        {
            K[i][j] = min(K[i - 1][j - 1], K[i][j - 1], K[i - 1][j]) + cost[i][j];
        }
    }
    return K[m][n];
}

int main()
{
    int cost[M][N] = {{1, 2, 3}, {4, 8, 2}, {1, 5, 3}};
    cout << minCost(cost, 2, 2) << endl;
    return 0;
}