// Bubble Sort
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    bool flag; int temp;
    for (int i = 0; i < n; i++)
    {
        flag = false;
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = true;
            }
        }
        if(!flag){
            break;
        }
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    
    cout<<endl;
}