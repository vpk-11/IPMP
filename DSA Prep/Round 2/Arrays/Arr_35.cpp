// make the rows and columns of a binary matrix 1 if it contains a cell with 1
#include <iostream>
#include <vector>
using namespace std;
#define R 3
#define C 4

void matrixManip(bool mat[R][C])
{
    vector<int> row, col;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (mat[i][j] == 1)
            {
                row.push_back(i);
                col.push_back(j);
            }
        }
    }
    for (int i = 0; i < row.size(); i++)
    {
        for (int j = 0; j < C; j++)
        {
            mat[row[i]][j] = 1;
        }
    }
    for (int j = 0; j < col.size(); j++)
    {
        for (int i = 0; i < R; i++)
        {
            mat[i][col[j]] = 1;
        }
    }
}

void printMatrix(bool mat[R][C])
{
    int i, j;
    for (i = 0; i < R; i++)
    {
        for (j = 0; j < C; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    bool mat[R][C] = {{1, 0, 0, 1},
                      {0, 0, 1, 0},
                      {0, 0, 0, 0}};

    cout << "Input Matrix \n";
    printMatrix(mat);
    matrixManip(mat);
    printf("Matrix after modification \n");
    printMatrix(mat);
    return 0;
}