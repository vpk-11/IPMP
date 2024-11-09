// You are given an array of n+2 elements.
// All elements of the array are in range 1 to n.
// And all elements occur once except two numbers which occur twice.
// Find the two repeating numbers.
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>
using namespace std;

vector<int> twoRepeated(int arr[], int N)
{
    // Your code here
    vector<int> count(N + 1, 0);
    vector<int> ans;
    for (int i = 0; i < N + 2; i++)
    {
        count[arr[i]] += 1;
        if (count[arr[i]] == 2)
        {
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

int main()
{
    int n = 10;
    int arr[n + 2];
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }
    arr[n] = 2;
    arr[n + 1] = 7;
    vector <int> v = twoRepeated(arr, n);
    for(auto it : v){
        cout << it << " ";
    }
    return 0;
}
