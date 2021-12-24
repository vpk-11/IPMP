/* C++ Program to check for majority element in a sorted array */
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

bool isMajority(int arr[], int n, int key)
{
    // Linear Search Method
    /*
    int i, last;
    last = (n % 2) ? (n / 2 + 1) : (n / 2);
    for (i = 0; i < last; i++)
    {
        if (arr[i] == key && arr[i + n / 2] == key)
            return true;
    }
    return false;
    */
    // Binary Search Method
    int i = BinarySearch(arr,0,n-1,key);
    if (i == -1)
        return false;
    if (((i + n / 2) <= (n - 1)) && arr[i + n / 2] == key)
            return true;
    else
        return false;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 4, 4, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 4;
    if (isMajority(arr, n, key))
        cout << key << " appears more than " << n / 2 << " times in arr" << endl;
    else
        cout << key << " does not appear more than " << n / 2 << " times in arr" << endl;

    return 0;
}