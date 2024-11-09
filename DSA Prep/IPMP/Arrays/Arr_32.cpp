// Rotate image by 90 Degree
#include <iostream>
using namespace std;

void displayMatrix(int const *p, int row, int col)
{
    int r, c;
    cout << "\n";
    for (r = 0; r < row; r++)
    {
        for (c = 0; c < col; c++)
            cout << *(p + r * col + c) << "\t";
        cout << "\n";
    }

    cout << "\n";
}

void rotate(int *pSource, int *pDest, int row, int col)
{
    int r, c;
    for (r = 0; r < row; r++)
    {
        for (c = 0; c < col; c++)
        {
            *(pDest + c * row + (row - r - 1)) =
                *(pSource + r * col + c);
        }
    }
}

int main()
{

    int image[][4] = {{1, 2, 3, 4},
                      {5, 6, 7, 8},
                      {9, 10, 11, 12}};
    int *pSource;
    int *pDest;
    int m, n;

    m = 3;
    n = 4;
    pSource = (int *)image;
    pDest = (int *)malloc(sizeof(int) * m * n);

    displayMatrix(pSource, m, n);

    rotate(pSource, pDest, m, n);

    displayMatrix(pDest, n, m);

    free(pDest);

    return 0;
}
