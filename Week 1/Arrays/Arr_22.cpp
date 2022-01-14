#include <iostream>
using namespace std;

int main()
{
    int a[4][4] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}};

    // sprial order print logic
    int row_start = 0, row_end = 3, col_start = 0, col_end = 3; //  row_end = m-1 // col_end = n-1

    while ((row_start <= row_end) && (col_start <= col_end))
    {
        // For row start
        for (int col = col_start; col <= col_end; col++)
        {
            cout << a[row_start][col] << " ";
        }
        cout << endl;

        row_start++;

        // For Col end
        for (int row = row_start; row <= row_end; row++)
        {
            cout << a[row][col_end] << " ";
        }
        cout << endl;

        col_end--;

        // For row end
        for (int col = col_end; col >= col_start; col--)
        {
            cout << a[row_end][col] << " ";
        }
        cout << endl;

        row_end--;

        // For Col start
        for (int row = row_end; row >= row_start; row--)
        {
            cout << a[row][col_start] << " ";
        }
        cout << endl;

        col_start++;
    }
    return 0;
}