// Move Even Indexed Char in string to end of String
#include <iostream>
#include <string>
using namespace std;

string moveEvenToBack(string s)
{
    string odd, even;
    for (int i = 0; i < s.size(); i++)
    {
        if (i % 2 == 0)
        {
            odd.push_back(s[i]);
        }
        else
        {
            even.push_back(s[i]);
        }
    }
    odd += even;
    return odd;
}

int main()
{
    char str[] = "a1b2c3d4e5f6g7";
    string s = moveEvenToBack(str);
    cout << str << endl
         << s << endl;
    return 0;
}