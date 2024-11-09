#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

void MaxDifference( int n,int arr[]){
    // Simple Method
    int difference = 0, index1 = 0, index2=1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((arr[j] - arr[i]) > difference)
            {
                difference = arr[j] - arr[i];
                index1 = i; index2 = j;
            }
        }
    }
    cout<<"Max difference = "<<difference<<" between "<<arr[index1]<<" & "<<arr[index2]<<endl;
    int min_element = arr[0], max_diff = arr[1] - arr[0];
    index2 = 1; index1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] - min_element > max_diff)
        {
            max_diff = arr[i] - min_element;
            index2 = i;
        }
        if (arr[i]<min_element)
        {
            min_element = arr[i];
            if (i < index2)
            {
               index1 = i;
            }
            
        }
    }
    cout<<"Max difference = "<<max_diff<<" between "<<arr[index1]<<" & "<<arr[index2]<<endl;
    
}

int main()
{
    int arr[] = {2,3,10,6,4,8,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    
   MaxDifference(n,arr);

    return 0;
}