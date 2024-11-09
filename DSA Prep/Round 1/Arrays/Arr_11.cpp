#include <iostream>
using namespace std;
#include <iostream>
using namespace std;

void quadSum(int arr[], int n, int sum)
{
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                for (int l = 0; l < n; l++)
                {
                    if (((arr[i] + arr[j] + arr[k] + arr[l]) == sum) && (i != j) && (k != j) && (i != k) && (l != j) && (k != l) && (i != l))
                    {
                        cout << "Sum of " << arr[i] << ", " << arr[j] << ", " << arr[k] << " & " << arr[l] << " is = " << sum << endl;
                        cout << "Valid Quad exists" << endl;
                        flag = true;
                        break;
                    }
                    if (flag)
                    {
                        break;
                    }
                }
                if (flag)
                {
                    break;
                }
            }
            if (flag)
            {
                break;
            }
        }
        if (flag)
        {
            break;
        }
    }
    if (!flag)
    {
        cout << "No Valid Quad exists" << endl;
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
    quadSum(arr, n, sum);
}