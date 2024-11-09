#include <iostream>
#include <climits>
using namespace std;
void method1(int arr[], int n)
{
    int start[n], end[n];
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            start[i] = 1;
        }
        else
        {
            start[i] = start[i - 1] * arr[i - 1];
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (i == (n - 1))
        {
            end[i] = 1;
        }
        else
        {
            end[i] = end[i + 1] * arr[i + 1];
        }
    }
    int b[n];
    for (int i = 0; i < n; i++)
    {
        b[i] = start[i] * end[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
}
void method2(int arr[], int n){
    int temp = 1;
    int b[n];
    for (int i = 0; i < n; i++)
    {
        b[i] = temp;
        temp *=arr[i]; 
    }
    temp = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        b[i] *= temp;
        temp*=arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
    
}
int main()
{
    int arr[] = {10, 3, 5, 6, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    method1(arr,n);
    cout << endl;
    method2(arr,n);
    return 0;
}