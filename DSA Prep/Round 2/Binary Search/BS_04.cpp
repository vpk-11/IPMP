// Floor and Ceil of element in Array
#include <iostream>
using namespace std;

// ceil is the smallest number greater than or equal to the given key present in the array
int ceilSearch(int arr[], int l, int h, int key)
{
    if (key <= arr[l]) // comparing to lower bound
    {
        return l;
    }
    if (key > arr[h]) // comparing to upper bound
    {
        return -1;
    }

    int mid = (l + h) / 2;
    if (key == arr[mid]) // Mid comparison
    {
        return mid;
    }
    else if (arr[mid] < key) // if key is greater than mid
    {
        if (mid + 1 < h && arr[mid + 1] >= key) // we check immediate successor
        {
            return mid + 1;
        }
        return ceilSearch(arr, mid + 1, h, key); // or we search the right sub array
    }
    else
    {
        if (arr[mid] > key) // if key is smaller
        {
            if (mid - 1 >= l && arr[mid - 1] < key) // we check if predecessor is smaller
            {
                return mid; // if yes we return mid
            }
            return ceilSearch(arr, l, mid - 1, key); // else we search the right subtree
        }
    }
    return -1;
}

// floor is the largest number lesser than or equal to the given key present in the array
int floorSearch(int arr[], int l, int h, int key)
{
    if (key < arr[l]) // comparing to lower bound
    {
        return -1;
    }
    if (key >= arr[h]) // comparing to upper bound
    {
        return h;
    }

    int mid = (l + h) / 2;
    if (key == arr[mid]) // Mid comparison
    {
        return mid;
    }
    else if (arr[mid] < key) // if key is greater than mid
    {
        if (mid + 1 < h && arr[mid + 1] > key) // we check immediate successor
        {
            return mid;
        }
        return floorSearch(arr, mid + 1, h, key); // or we search the right sub array
    }
    else
    {
        if (arr[mid] > key) // if key is smaller
        {
            if (mid - 1 >= l && arr[mid - 1] <= key) // we check if predecessor is smaller
            {
                return mid - 1; // if yes we return mid
            }
            return floorSearch(arr, l, mid - 1, key); // else we search the right subtree
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 4, 8, 10, 12, 16, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k;
    cout << "Enter Number u want to check: ";
    cin >> k;
    int index = ceilSearch(arr, 0, n - 1, k);
    if (index == -1)
    {
        cout << "Ceil doesn't exist" << endl;
    }
    else
    {
        cout << "Ceil =  " << arr[index] << endl;
    }
    index = floorSearch(arr, 0, n - 1, k);
    if (index == -1)
    {
        cout << "Floor doesn't exist" << endl;
    }
    else
    {
        cout << "Floor =  " << arr[index] << endl;
    }
    return 0;
}