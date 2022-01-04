// Elements with Min Difference
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

void minDifference( int n,int arr[]){
    // Simple Method
    int difference = INT_MAX, index1 = 0, index2=1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((abs(arr[j] - arr[i]) < difference) && i!=j)
            {
                difference = abs(arr[j] - arr[i]);
                index1 = i; index2 = j;
            }
        }
    }
    cout<<"Min difference = "<<difference<<" between "<<arr[index1]<<" & "<<arr[index2]<<endl;
    sort(arr, arr+n);
    int min_diff = arr[n-1] - arr[0];
    index2 = 1; index1 = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - arr[i-1] < min_diff)
        {
            min_diff = arr[i] - arr[i-1];
            index1 = i-1;
            index2 = i;
        }
        
    }
    cout<<"Min difference = "<<min_diff<<" between "<<arr[index1]<<" & "<<arr[index2]<<endl;
    
}

int main()
{
    int arr[] = {2,3,10,6,4,8,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    
   minDifference(n,arr);

    return 0;
}