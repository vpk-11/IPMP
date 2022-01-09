// Merge sort
#include <iostream>
using namespace std;

void merge(int arr[], int lb, int mid, int ub)
{
	int k;
	int n1 = mid - lb + 1;
	int n2 = ub - mid;

	int L[n1], R[n2];

	for (int i = 0; i < n1; i++)
		L[i] = arr[lb + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[mid + 1 + j];

	int i = 0;
	int j = 0;
	k = lb;

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int lb, int ub)
{
	if (lb < ub)
	{
		int mid = (lb + ub) / 2;
		mergeSort(arr, lb, ub);
		mergeSort(arr, mid + 1, ub);
		merge(arr, lb, mid, ub);
	}
}

int main()
{
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << "Given array is \n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	mergeSort(arr, 0, n - 1);

	cout << "\nSorted array is \n";

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	return 0;
}
