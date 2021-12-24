#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int BinarySearch(int A[], int left, int right, int key)
{
	int mid;

	while( left <= right )
	{
		mid = left + (right-left)/2;

		if( A[mid] == key )
			return mid;

		if( A[mid] < key )
			left = mid + 1;
		else
			right = mid - 1;
	}

	return -1;
}

void floorAndCeiling(int arr[], int n, int key)
{
    int i;
    int floor, ceiling;
    for (i = 0; i < n; i++)
    {
        if(arr[i] == key){
            floor = key;
            ceiling = key;
        }
        if(arr[i]<key && arr[i+1]>key){
            ceiling = i+1; floor = i;
        }
            
    }
    cout<<"Floor = "<<arr[floor]<<" & Ceiling = "<<arr[ceiling]<<endl;
}
int main()
{
    int arr[] = {1, 2, 5, 6, 10, 12, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 4;
    floorAndCeiling(arr,n,key);
    return 0;
}