// Merge 2 Sorted arrays
#include <iostream>
#include <vector>
using namespace std;
#define NA -1

vector<int> sortedMerge(int a1[], int a2[], int m, int n)
{
    vector<int> v;
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (a1[i] == a2[j])
        {
            if(a1[i] != NA)
                v.push_back(a1[i]);
            i++;
            j++;
        }
        else if (a1[i] < a2[j])
        {
            if(a1[i] != NA)
                v.push_back(a1[i]);
            i++;
        }
        else
        {
            if(a2[j] != NA)
                v.push_back(a2[j]);
            j++;
        }
    }
    while (i < m)
    {
        if(a1[i] != NA)
            v.push_back(a1[i]);
        i++;
    }
    while (j < n)
    {
        if(a2[j] != NA)
            v.push_back(a2[j]);
        j++;
    }
    return v;
}

int main()
{
    int mPlusN[] = {2, 8, NA, NA, NA, 13, NA, 15, 20};
    int N[] = {5, 7, 9, 25};
    int m = sizeof(mPlusN)/sizeof(mPlusN[0]);
    int n = sizeof(N)/sizeof(N[0]);
    vector<int> v = sortedMerge(mPlusN, N, m, n);
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}