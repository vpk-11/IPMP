// Given an array of bags with the number of rocks in it and another array which tells us the max capacity of each bag, 
// find the max number of full capacity bags to fill them with the additional rocks

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximumBags(vector<int> &c, vector<int> &r, int a)
{
    int max = 0;
    vector <int> diff;
    for (int i = 0; i < r.size(); i++)
    {
        diff.push_back(c[i] - r[i]);
    }
    sort(diff.begin(), diff.end());
    for (int i = 0; i < diff.size(); i++)
    {
        if (diff[i]<=a)
        {
            a-=diff[i];
            max++;
        }
    }
    return max;    
}

int main()
{
    int arr[] = {54,18,91,49,51,45,58,54,47,91,90,20,85,20,90,49,10,84,59,29,40,9,100,1,64,71,30,46,91};
    vector <int> c (arr, arr + sizeof(arr) / sizeof(arr[0]) );
    int brr[] = {14,13,16,44,8,20,51,15,46,76,51,20,77,13,14,35,6,34,34,13,3,8,1,1,61,5,2,15,18};
    vector<int> r (brr, brr + sizeof(brr) / sizeof(brr[0]));
    int a = 77;
    cout << maximumBags(c,r,a) << endl; 
}