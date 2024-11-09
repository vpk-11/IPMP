#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int OddOccurrances(int arr[], int n)
{
    // Linear method O(n^2)
    /*
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++)
            if (arr[i] == arr[j])
                count++;
        if (count % 2 != 0)
            return arr[i];
    }
    return -1;
    */
    // Unordered Map method
    unordered_map <int, int> map;
    for (int i = 0; i < n; i++)
       map[arr[i]]++;
    
    for (int i = 0; i < map.size(); i++)
    {
        if (map[arr[i]]%2 != 0)
        {
            return arr[i];
        }
    }
    return -1;
}
int main(){
    int m;
    cin >> m;

    int arr[m];
    for (int i = 0; i < m; i++)
        cin>>arr[i];
    cout<<OddOccurrances(arr,m)<<endl;
    return 0;
}