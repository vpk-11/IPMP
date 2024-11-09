// Given sorted Array of just 0s and 1s of Infinite length find trasition index
#include <iostream>
using namespace std;

int findTransition(int arr[], int n)
{
    int start = 0, end = 1, mid = 0;
    if (arr[start] == 0 && arr[end] == 1)
    {
        return start;
    }
    while (arr[end] != 1)
    {
        start = end;
        end = end << 1;
    }
    while (arr[start + 1] != 1)
    {
        mid = (start + end) / 2;
        if (arr[mid] == 0)
            start = mid;
        else
            end = mid;
    }
    return start;
}

int main()
{
}