#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    
    int arr[] = {1,2,3,5,6,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);

    int sum = (n+2)*(n+1)/2 ;
    for (int i = 0; i < n; i++)
        sum -= arr[i];
    
    cout<<"Missing Value: "<< sum <<endl;
    
    return 0;
}