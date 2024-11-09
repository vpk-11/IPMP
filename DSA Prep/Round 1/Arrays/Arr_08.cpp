#include <iostream>
using namespace std;

void sumPair(int arr[], int n, int sum)
{
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (((arr[i] + arr[j]) == sum)&& i!=j)
            {
                cout << "Sum of " << arr[i] << " & " << arr[j] << " is = " << sum<<endl;
                cout<<"Valid Pair exists"<<endl;
                flag = true;
                break;
            }
            if (flag)
            {
                break;
            }
        }
    }
    if (!flag)
    {
        cout<<"No Valid Pair exists"<<endl;
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
    sumPair(arr, n, sum);
}