// Revers Words of String
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string reverseWords(string s)
{
    vector<string> v;
    string str;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            v.push_back(str);
            str = "";
        }
        else
        {
            str.push_back(s[i]);
        }
    }
    v.push_back(str);
    str = "";
    for (int i = v.size() - 1; i >= 1; i--)
    {
        str += v[i];
        str += " ";
    }
    str += v[0];
    return str;
}

int main()
{
    string s = "i like this program very much";
    string str = reverseWords(s);
    cout << str << endl;
    return 0;
}