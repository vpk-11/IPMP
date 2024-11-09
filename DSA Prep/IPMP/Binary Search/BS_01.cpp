#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

// Standard Binary Search

int BinarySearch(int A[], int left, int right, int key)
{
	int mid;

	while( left <= right )
	{
		mid = left + (right-left)/2;

		if( A[mid] == key ) // first comparison
			return mid;

		if( A[mid] < key ) // second comparison
			left = mid + 1;
		else
			right = mid - 1;
	}

	return -1;
} 
/* Fewer Searches
// Invariant: A[left] <= key and A[right] > key
// Boundary: |right - left| = 1
// Input: A[left .... right-1]
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
*/

int main(){

    int arr[8];
    for (int i = 0;i < 8; i++)
    {
        cin>>arr[i];
    }
    cout << BinarySearch(arr,0,8-1,5)<< endl;

    return 0;
}