#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
void Union(int arr1[],int arr2[], int m, int n){
    int p = m+n;    
}
int main(){
    
    int m, n;
    cin >> m >> n;

    int arr1[m], arr2[n];
    for (int i = 0; i < m; i++)
    {
        cin>>arr1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>arr2[i];
    }
    Union(arr1,arr2,m,n);
    return 0;
}