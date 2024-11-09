// Print Matrix Diagonally
#include <iostream>
#include <vector>
using namespace std;
#define M 6
#define N 5

void printDiagonally(int arr[M][N])
{
    int i = 0, j = 0;
    while (i < M && j < N)
    {
        int k = i, l = j;
        while (k >= 0 && l < N)
        {
            cout << arr[k--][l++] << " ";
        }
        cout << endl;
        if (i < M - 1)
        {
            i++;
        }
        else
        {
            j++;
        }
    }
}

void printMatrix(int matrix[M][N])
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            cout << matrix[i][j] << " ";

        cout << "\n";
    }
}

int main()
{
    int arr[M][N] = {{11, 12, 13, 14, 15},
                     {16, 17, 18, 19, 20},
                     {21, 22, 23, 24, 25},
                     {26, 27, 28, 29, 30},
                     {31, 32, 33, 34, 35},
                     {36, 37, 38, 39, 40}};
    cout << "Given matrix is " << endl;
    printMatrix(arr);

    cout << "\nDiagonal printing of matrix is " << endl;
    printDiagonally(arr);
    return 0;
    return 0;
}