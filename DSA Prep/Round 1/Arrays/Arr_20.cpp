#include <iostream>
#include <map>
using namespace std;
void duplicates(int arr[], int n)
{
    map<int, int> map;
    for (int i = 0; i < n; i++)
        map[arr[i]]++;

    for (int i = 0; i < map.size() - 1; i++)
    {
        if (map[arr[i]] != 1)
        {
            cout << arr[i] << " ";
        }
    }
}
int main()
{

    int arr[] = {0, 4, 3, 2, 7, 8, 2, 3, 4, 1, 4, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Repeating Elements are ";
    duplicates(arr, n);
    cout << endl;
}