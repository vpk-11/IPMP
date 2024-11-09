// Sub Array with Sum = 0;
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

void subArrayZeroSum(int n, int arr[])
{
    // Simple Method
    int sum;
    int x = pow(2,n);
    vector <int> v[x];
    int l = 0;
    for (int i = 0; i < n ; i++)
    {
        for (int j = i ; j < n; j++)
        {
           for(int k = i ; k<=j; k++){
               v[l].push_back(arr[k]);
           } 
           cout<<endl;
        }
    }
}

int main()
{
    int arr[] = {4,2,-3,1,6};
    int n = sizeof(arr) / sizeof(arr[0]);

    subArrayZeroSum(n, arr);

    return 0;
}