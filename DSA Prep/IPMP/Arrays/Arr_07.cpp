#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
int main()
{
    int num;
    cout << "Enter Number length: ";
    cin >> num;
    int arr[num];
    for (int i = 0; i < num; i++)
        cin >> arr[i];
    int pivot;
    for (int i = num - 1; i >= 0; i--)
    {
        if (arr[i - 1] < arr[i])
        {
            pivot = i - 1;
            break;
        }
    }
    for (int i = num - 1; i > pivot; i--)
    {
        if (arr[i] > arr[pivot])
        {
            swap(&arr[i], &arr[pivot]);
            for (int j = pivot; j < num; j++){
                for (int k = pivot + 1; k < num - j - 1; k++){
                    if (arr[k] > arr[k + 1]){
                        swap(&arr[k], &arr[k + 1]);
                    }
                }
            }
            break;
        }
    }
    for (int i = 0; i < num; i++)
        cout << arr[i] << " ";

    return 0;
}