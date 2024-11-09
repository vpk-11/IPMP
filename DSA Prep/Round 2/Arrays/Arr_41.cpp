// Max Subarray sum
#include <iostream>
#include <climits>
using namespace std;

pair<int, pair<int, int> > maxSubArraySum(int arr[], int n)
{
    int maxSum = INT_MIN, sum = 0, start = 0, end = 0, s = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (maxSum < sum)
        {
            maxSum = sum;
            start = s;
            end = i;
        }
        if (sum < 0)
        {
            sum = 0;
            s = i + 1;
        }
    }
    pair<int, int> index;
    pair<int, pair<int, int> > p;
    p.first = maxSum;
    index.first = start;
    index.second = end;
    p.second = index;
    return p;
}

int main()
{

    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a) / sizeof(a[0]);
    pair<int, pair<int, int> > p = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << p.first << endl;
    cout << "Starting index " << p.second.first << " & Ending index " << p.second.second << endl;
    return 0;
}