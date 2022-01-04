#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int OnesCounter( int n,int arr[]){
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]==1)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int arr[4][4] = {{0, 1, 1, 1}, {0, 0, 1, 1}, {0, 0, 0, 1}, {1, 1, 1, 1}};
    int n; 
    n = sizeof(arr)/sizeof(arr[0]);
    int max= 0 , index = 0;
    for (int i = 0; i < n; i++)
    {
        int size = OnesCounter(n,arr[i]);
        if (max < size)
        {
            max = size;
            index = i;
        }
    }
    cout<<max<<endl;
    cout<<"Row Index = "<<index<<endl;
    return 0;
}