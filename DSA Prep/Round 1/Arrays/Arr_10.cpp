#include <iostream>
using namespace std;

void tripletSum(int arr[], int n, int sum)
{
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (((arr[i] + arr[j] + arr[k]) == sum) && (i != j) && (k != j) && (i != k))
                {
                    cout << "Sum of " << arr[i] << ", " << arr[j] << " & " << arr[k] << " is = " << sum << endl;
                    cout << "Valid Triplet exists" << endl;
                    flag = true;
                    break;
                }
                if (flag)
                {
                    break;
                }
            }
        }
        if (flag)
        {
            break;
        }
    }
    if (!flag)
    {
        cout << "No Valid Triplet exists" << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int sum;
    cin >> sum;
    tripletSum(arr, n, sum);
}