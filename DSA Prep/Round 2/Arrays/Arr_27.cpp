// Sort Array Based on Frequency
#include <iostream>
#include <vector>
using namespace std;

vector<int> sortByFrequency(int arr[], int n)
{
    
}

int main()
{
    int arr[] = {2, 5, 2, 6, -1, 9999999, 5, 8, 8, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> v = sortByFrequency(arr, n);

    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}