#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

int main(){
    
    int arr[] = {15,12,31,49,15,12,31,56};
    int n = sizeof(arr)/sizeof(arr[0]);
    //using unordered Map
    unordered_map <int, int> map;
    for (int i = 0; i < n; i++)
       map[arr[i]]++;
    
    for (int i = 0; i < map.size(); i++)
    {
        if (map[arr[i]]==1)
        {
            cout<<arr[i]<<endl;
        }
    }
    // Using Sorting
    sort(arr,arr+n);
    int i = 0;
    while (i < n)
    {
        if (arr[i]==arr[i+1])
        {
            i++;
        }else{
            cout<<arr[i]<<" ";
        }
        i++;
    }
    return 0;
}