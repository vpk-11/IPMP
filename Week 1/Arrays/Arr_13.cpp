#include <iostream>
#include <vector>
using namespace std;

void findThreeNumbers(int arr[],int n){
    int smaller[n]; smaller[0] = -1;
    int larger[n]; larger[n-1] = -1;
    int min_Index = 0; int max_Index = n-1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]<=arr[min_Index])
        {
            min_Index = i;
            smaller[i] = -1;
        } else{
            smaller[i] = min_Index;
        }
    }
    for (int i = n-2; i >=0 ; i--)
    {
        if (arr[i]>=arr[max_Index])
        {
            max_Index = i;
            larger[i] = -1;
        } else{
            larger[i] = max_Index;
        }
    }
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (smaller[i]!= -1 && larger[i]!= -1)
        {
            cout<<"Indices are "<<smaller[i]<<" "<<i<<" "<<larger[i]<<endl;
            cout<<"Values are "<<arr[smaller[i]]<<" "<<arr[i]<<" "<<arr[larger[i]]<<endl; flag = true;
            break;
        } else{
            flag = false;
        }
    }
    if (!flag)
    {
        cout<<"No Triplet exists"<<endl;
    }
    
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    findThreeNumbers(arr,n);
    
    return 0;
}