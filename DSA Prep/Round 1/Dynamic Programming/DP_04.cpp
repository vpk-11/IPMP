// Min Jumps to reach the end
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

// Brute force method
int minJumps(int arr[], int n){
    if (n == 1)
    {
        return 0;
    }
    int res = INT_MAX;
    for (int i = n - 2; i >= 0; i--) {
        if (i + arr[i] >= n - 1) {
            int sub_res = minJumps(arr, i + 1);
            if (sub_res != INT_MAX)
                res = min(res, sub_res + 1);
        }
    }
    return res;
}
// DP method
int minJumpsDP(int arr[], int n)
{
    int jumps[n];
    int i, j;
 
    if (n == 0 || arr[0] == 0)
        return INT_MAX;
 
    jumps[0] = 0;
 
    for (i = 1; i < n; i++) {
        jumps[i] = INT_MAX;
        for (j = 0; j < i; j++) {
            if (i <= j + arr[j] && jumps[j] != INT_MAX) {
                jumps[i] = min(jumps[i], jumps[j] + 1);
                break;
            }
        }
    }
    return jumps[n - 1];
}

int main(){
    int arr[] = { 1, 3, 6, 3, 2, 3, 6, 8, 9, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum number of jumps to reach the end is " << minJumpsDP(arr, n)<<endl;

}