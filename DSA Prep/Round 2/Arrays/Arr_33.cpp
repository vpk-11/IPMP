// Given an array [a1b2c3d4] convert to [abcd1234]
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void altText(char arr[], int n)
{
    vector<char> a, d;
    for (int i = 0; i < n && arr[i] != '\0'; i++)
    {
        if (isdigit(arr[i]))
        {
            d.push_back(arr[i]);
        }
        else
        {
            a.push_back(arr[i]);
        }
    }
    int i = 0, j = 0, k = 0;
    while (i < a.size())
    {
        arr[k++] = a[i++];
    }
    while (j < d.size())
    {
        arr[k++] = d[j++];
    }
}

int main()
{
    char arr[] = "e9f8g7h6";
    int n = sizeof(arr) / sizeof(arr[0]);
    altText(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}