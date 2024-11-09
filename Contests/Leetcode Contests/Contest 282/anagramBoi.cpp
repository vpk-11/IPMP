#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define NO_OF_CHARS 256

vector<int> getCharCountArray(string str)
{
    vector<int> count(NO_OF_CHARS);
    for (int i = 0; i < str.length(); i++)
    {
        count[str[i]]++;
    }
    return count;
}
int findChar(string str, char c)
{
    int x = 0;
    size_t found = str.find(c);
    while (found != string::npos)
    {
        x+=1;
        found = str.find(c, found + 1);
    }
    return x;
}

int anagramBoi(string s, string t)
{
    // int count = 0;
    // string s1 = s;
    // string s2 = t;
    // for (int i = 0; i < s.size(); i++)
    // {
    //     int x = findChar(t, s[i]);
    //     count += x;
    // }
    // for (int i = 0; i < t.size(); i++)
    // {
    //     int x = findChar(t, s[i]);
    //     count += x;
    // }
    // return count;
    vector <int> count_s = getCharCountArray(s);
    vector <int> count_t = getCharCountArray(t);
}
int main()
{
    cout << anagramBoi("leetcode", "coats") << endl;
    cout << anagramBoi("cotxazilut", "nahrrmcchxwrieqqdwdpneitkxgnt") << endl;
}