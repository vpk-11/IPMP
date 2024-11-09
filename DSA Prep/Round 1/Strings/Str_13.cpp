// Check Anagram
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> countArray(string s)
{
    vector<int> v(256);
    for (int i = 0; i < 256; i++)
    {
        v[i] = 0;
    }
    for (int i = 0; i < s.size(); i++)
    {
        v[s[i]]++;
    }
    return v;
}

bool checkAnagram(string s1, string s2)
{
    if (s1.length() != s2.length())
    {
        return false;
    }
    vector<int> v1, v2;
    v1 = countArray(s1);
    v2 = countArray(s2);
    for (int i = 0; i < 256; i++)
    {
        if (v1[i] != v2[i])
        {
            return false;
        }
    }
    return true;
}

bool checkAnagramAlt(string s1, string s2)
{
    if (s1.length() != s2.length())
    {
        return false;
    }
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    if (s1 != s2)
    {
        return false;
    }
    return true;
}

int main()
{
    string str1 = "test";
    string str2 = "ttes";

    if (checkAnagram(str1, str2))
        cout << "The two strings are anagram of each other" << endl;
    else
        cout << "The two strings are not anagram of each other" << endl;

    return 0;
}