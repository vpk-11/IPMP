// Print Matrix Spirally
#include <iostream>
#include <vector>
using namespace std;
#define R 4
#define C 4
void printSpiral(int v[R][C], int M, int N)
{
    int i;
    int rs = 0, re = M - 1, cs = 0, ce = N - 1;
    while (rs < re && cs < ce)
    {
        // Down Ward Spiral
        // for(i = rs; i <= re; i++){
        //     cout << v[i][cs] << " ";
        // }
        // cs++;
        // for(i = cs; i <= ce; i++){
        //     cout << v[re][i] << " ";
        // }
        // re--;
        // for(i = re; i >= rs; i--){
        //     cout << v[i][ce] << " ";
        // }
        // ce--;
        // for(i = ce; i >= cs; i--){
        //     cout << v[rs][i] << " ";
        // }
        // rs++;

        for (i = cs; i <= ce; i++)
        {
            cout << v[rs][i] << " ";
        }
        rs++;
        for (i = rs; i <= re; i++)
        {
            cout << v[i][ce] << " ";
        }
        ce--;

        for (i = ce; i >= cs; i--)
        {
            cout << v[re][i] << " ";
        }
        re--;
        for (i = re; i >= rs; i--)
        {
            cout << v[i][cs] << " ";
        }
        cs++;
    }
    /*
        // To return a vector with all elements of matrix in spiral order
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        int count=0;
        int total=r*c;

        int sr=0;
        int er=m-1;
        int ec=n-1;
        int sc=0;

       while(total>count)
       {
            for(int i=sc; total>count && i<=ec;i++){
                ans.push_back(matrix[sr][i]);
                count++;
            }
            sr++;

            for(int i=sr; total>count && i<=er;i++)
            {
                ans.push_back(matrix[i][ec]);
                count++;
            }
            ec--;
            for(int i=ec; total>count && i>=sc;i--)
            {
                ans.push_back(matrix[er][i]);
                count++;
            }
            er--;
            for(int i=er; total>count && i>=sr;i--)
            {
                ans.push_back(matrix[i][sc]);
                count++;
            }
            sc++;
        }
        return ans;
    */
}

int main()
{
    int v[R][C] = {{1, 2, 3, 4},
                   {5, 6, 7, 8},
                   {9, 10, 11, 12},
                   {13, 14, 15, 16}};

    // Function Call
    printSpiral(v, R, C);
    return 0;
}