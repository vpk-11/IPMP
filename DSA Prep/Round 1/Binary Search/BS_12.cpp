// Min elem in sorted and rotated array
#include <iostream>
using namespace std;

int minSearch(int arr[], int n)
{
    int start = 0, end = n - 1;

    if (arr[start] <= arr[end])
        return start;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] < arr[mid - 1])
            return mid;

        else if (arr[mid] > arr[mid + 1])
            return mid + 1;

        else if (arr[start] <= arr[mid])
            start = mid + 1;

        else if (arr[mid] <= arr[end])
            end = mid - 1;
    }
    return -1;
}

int main()
{
    int arr[] = {335, 359, 383, 392, 422, 437, 448, 465, 468, 479, 492, 501, 539, 605, 668, 704, 706, 717, 719, 725, 727,
                 772, 812, 828, 870, 895, 896, 903, 913, 943, 962, 963, 996, 36, 146, 154, 170, 282, 293, 300, 323, 334};
    int n = sizeof(arr) / sizeof(arr[0]);
    int index = minSearch(arr, n);
    if (index != -1)
    {
        cout << "Min Elem is: " << arr[index] << endl;
    }
    return 0;
}