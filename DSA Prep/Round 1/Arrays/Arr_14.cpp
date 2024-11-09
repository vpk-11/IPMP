#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin>>arr[i];
    
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";

    int pivot = 0;

    for (int i = 0; i < n; i++){
        if (arr[i]<=0 && arr[i+1]>0){
            pivot = i;
            break;
        }
    }
    int count = 1;
    for (int i = pivot; i < n; i++){
        if(count==arr[i]){
            count++;
        }else if(count<arr[i] && count > arr[i-1]){
            break;
        } else{
            continue;
        }
    }
    cout<<endl<<"Missing Number is "<<count<<endl;

    return 0;
}