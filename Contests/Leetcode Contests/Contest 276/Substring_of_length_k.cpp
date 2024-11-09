#include <iostream>
#include <string.h>
#include <cstring>
#include <vector>
using namespace std;

string substring(string str, int count, int k, char fill)
{
    string s;
    if(count + k < str.length())
        s = str.substr(count, k);
    else{
        int x = str.length() - count;
        s = str.substr(count,x);
        while (x<k)
        {
            s.push_back(fill);
            x++;
        }
    }
    return s;
}
vector<string> divideString(string str, int k, char fill){
    vector<string> s;
    int count = 0;
    while (count < str.length())
    {
        s.push_back(substring(str, count, k, fill));
        count += k;
    }
    return s;
}
int main()
{
    string str = "abcdefghik";
    int k = 3;
    char fill = 'x';
    vector<string> s = divideString(str,k,fill);
    for (int i = 0; i < s.size(); i++)
    {
        cout<<s[i]<<endl;
    }
}