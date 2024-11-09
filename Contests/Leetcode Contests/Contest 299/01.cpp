// Check if matrix is X-matrix
#include <iostream>
using namespace std;

bool checkXMatrix(int grid[10][10], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!(i == j || i == n - j - 1) && grid[i][j] != 0)
            {
                return false;
            }
            if ((i == j || i == n - j - 1) && grid[i][j] == 0)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int mat[10][10] = {{0,0,0,0,1},{0,4,0,1,0},{0,0,5,0,0},{0,5,0,2,0},{4,0,0,0,2}};
    int n = 4;
    cout << checkXMatrix(mat, n) << endl;
}