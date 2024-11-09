#include <iostream>
using namespace std;

int main()
{
    int mat[4][4] = {{10, 20, 30, 40},
                     {15, 25, 35, 45},
                     {27, 29, 37, 48},
                     {32, 33, 39, 50}};

    int x;
    cout << "Number to be searched: ";
    cin >> x;
    int i = 0, j = 0; bool flag = true;
    while ((i < 4 && j < 4) && flag)
    {
        if (x>mat[i][j])
        {
            if (x >= mat[i+1][j])
            {
                i++;
            }
            if (x>=mat[i][j+1])
            {
                j++;
            }
        } else if(x == mat[i][j]){
            printf("Element %d is present at (%d, %d)\n", x, i,j);
            flag = false;
        }
    }
    if(flag){
        cout<<"Not Found"<<endl;
    }
}