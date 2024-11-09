// Find first non repeating char in string
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

char firstNonRepChar(string str)
{
    vector<int> count(256);
    for (int i = 0; i < str.length(); i++)
    {
        count[str[i]]++;
    }
    for (int i = 0; i < str.length(); i++)
    {
        if (count[str[i]] == 1)
        {
            return str[i];
        }
    }
    return '$';
}

int main()
{
    string s = "abb";
    cout << firstNonRepChar(s) << endl;
    return 0;
}
