// Contiguous SubArray with given Sum
#include <iostream>
#include <vector>
using namespace std;

void subArraySum(int arr[], int n, int s)
{
    vector<int> v;
    long long sum = 0, i = 0, j = 0;
    while ((i < n) && (j <= n))
    {
        if (sum < s)
        {
            sum = sum + arr[j];
            j++;
        }
        else if (sum > s)
        {
            sum -= arr[i];
            i++;
        }
        else if (sum == s)
        {
            v.push_back(i + 1);
            v.push_back(j);
            break;
        }
    }
    v.push_back(-1);
    cout << "Indices are " << v[0] << " & " << v[1] << endl;
}

int main()
{
    int arr[] = {15, 2, 4, 8, 9, 5, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 23;
    subArraySum(arr, n, sum);
    return 0;
}
