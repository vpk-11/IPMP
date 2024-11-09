// Search in a row-wise and column-wise sorted matrix in Linear Time
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

pair<int, int> search(int v[4][4], int n, int key)
{
    int i = 0, j = n - 1;
    pair<int, int> p;
    p.first = -1;
    p.second = -1;
    if (key < v[0][0] || key > v[n - 1][n - 1])
    {
        return p;
    }

    while (i < n && j >= 0)
    {
        if (v[i][j] == key)
        {
            p.first = i;
            p.second = j;
            return p;
        }
        if (v[i][j] > key)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return p;
}

int main()
{
    int mat[4][4] = {{10, 20, 30, 40},
                     {15, 25, 35, 45},
                     {27, 29, 37, 48},
                     {32, 33, 39, 50}};
    pair<int, int> p = search(mat, 4, 500);
    if (p.first != -1)
    {
        cout << p.first << " " << p.second << " " << mat[p.first][p.second] << endl;
    }
    else
    {
        cout << "Nope" << endl;
    }

    return 0;
}