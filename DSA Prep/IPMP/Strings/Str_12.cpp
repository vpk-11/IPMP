// Remove duplicate characters
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string removeChars(string str1, string str2)
{
    for (int i = 0; i < str2.size(); i++)
    {
        while (find(str1.begin(), str1.end(), str2[i]) != str1.end())
        {
            auto itr = find(str1.begin(), str1.end(), str2[i]);
            str1.erase(itr);
        }
    }
    return str1;
}
int main()
{
    string str1, str2;
    str1 = "hellofromtheotherside";
    str2 = "gaylucas";
    cout << removeChars(str1, str2) << endl;
    return 0;
}
