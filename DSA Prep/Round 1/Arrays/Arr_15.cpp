// Row with max number of 1s in a matrix
#include <iostream>
using namespace std;
#define R 4
#define C 4

int first(bool arr[], int low, int high)
{
    while (high >= low)
    {
        int mid = low + (high - low) / 2;

        if ((mid == 0 || arr[mid - 1] == 0) && arr[mid] == 1)
        {
            return mid;
        }
        else if (arr[mid] == 0)
        {
            low = mid + 1;
        }

        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int rowWithMax1s(bool mat[R][C])
{
    int maxIndex = 0, max = -1;
    int index;
    for (int i = 0; i < R; i++)
    {
        index = first(mat[i], 0, C - 1);
        if (index != -1 && C - index > max)
        {
            max = C - index;
            maxIndex = i;
        }
    }
    return maxIndex;
}

int main()
{
    bool mat[R][C] = {{0, 0, 0, 1},
                      {0, 1, 1, 1},
                      {1, 1, 1, 1},
                      {0, 0, 0, 0}};

    cout << "Index of row with maximum 1s is " << rowWithMax1s(mat) << endl;

    return 0;
}
