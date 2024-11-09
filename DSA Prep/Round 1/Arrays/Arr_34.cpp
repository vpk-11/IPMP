// Max and Min using min no of comparisons
#include <iostream>
#include <climits>
using namespace std;

pair<int, int> minMax(int arr[], int n)
{
    pair<int, int> p;
    p.first = INT_MIN;
    p.second = INT_MAX;
    if (n == 0)
    {
        return p;
    }
    if (n == 1)
    {
        p.first = arr[0];
        p.second = arr[0];
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > p.first)
        {
            p.first = arr[i];
        }
        else if (arr[i] < p.second)
        {
            p.second = arr[i];
        }
    }
    return p;
}

int main()
{
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int n = sizeof(arr) / sizeof(arr[0]);

    pair<int, int> p = minMax(arr, n);
    
    cout << "Maximum element is " << p.first << endl;
    cout << "Minimum element is " << p.second << endl;
    
    return 0;
}