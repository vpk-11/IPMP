#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

void OddOccurrances(int arr[], int n)
{   
    // Unordered Map method
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++) {
        map[arr[i]]++;
    }
    for (auto x : map) {
        if (x.second % 2 != 0)
            cout << x.first << " ";
    }
    cout<<endl;
}
int main(){
    int arr[] = {15,12,31,49,15,12,31,31,56};
    int n = sizeof(arr)/sizeof(arr[0]);
    OddOccurrances(arr,n);
    return 0;
}