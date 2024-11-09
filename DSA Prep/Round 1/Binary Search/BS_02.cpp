#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int BinarySearch(int A[], int left, int right, int key)
{
	int mid;

	while( right - left > 1 )
	{
		mid = left + (right-left)/2;

		if( A[mid] <= key )
			left = mid;
		else
			right = mid;
	}

	if( A[left] == key )
		return left;
	if( A[right] == key )
		return right;
	else
		return -1;
}

int findPivot(int arr[],int low, int high){
    if (high < low)
        return -1;
    if (high == low)
        return low;
 
    int mid = (low + high) / 2; 
    if (mid < high && arr[mid] > arr[mid + 1])
        return mid;
 
    if (mid > low && arr[mid] < arr[mid - 1])
        return (mid - 1);
 
    if (arr[low] >= arr[mid])
        return findPivot(arr, low, mid - 1);
 
    return findPivot(arr, mid + 1, high);
}


int pivotSearch(int arr[], int n, int key){
    int pivot = findPivot(arr,0,n-1);
    if(pivot == -1){
        return BinarySearch(arr, 0, n-1, key);
    }
    if(arr[pivot] == key){
        return pivot;
    }
    else if (arr[0]<= key){
        return BinarySearch(arr,0,pivot-1,key);
    } else {
        return BinarySearch(arr, pivot + 1, n-1, key);
    }
}

int main(){

    int arr[] = {3,4,5,6,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key;
    cin>>key;
    cout<<"Index of element in Pivoted array : "<<pivotSearch(arr,n,key)<<endl;
    return 0;
}