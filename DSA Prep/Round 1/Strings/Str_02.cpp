// Print All Permutation of String
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

void permute(string a, int l, int r, vector<string> &res)
{
    if (l == r)
        res.push_back(a);
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(a[l], a[i]);
            permute(a, l + 1, r, res);
            swap(a[l], a[i]);
        }
    }
}
vector <string> printPermute(string s){
    vector <string> res;
    if(s.length() == 0){
        return res;
    }
    if (s.length() == 1)
    {
        res.push_back(s);
        return res;
    }
    
    permute(s, 0, s.length() - 1, res);
    map<string, int> map;
    for (int i = 0; i < res.size(); i++)
    {
        map[res[i]]++;
    }
    vector<string> ans;
    for (auto it : map)
    {
        ans.push_back(it.first);
    }
    return ans;
    
}

int main()
{
    string s = "abb";
    vector<string> ans = printPermute(s);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}