// Custom strcmp function
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int mod_strcmp(string str1, string str2)
{
    int i = 0;
    for (i = 0; (str1[i] && str2[i]); i++)
    {
        if (str1[i] == str2[i] || str1[i] == str2[i] + 32 || str1[i] + 32 == str2[i])
        {
            continue;
        }
        else
        {
            break;
        }
    }
    if (str1[i] < str2[i])
    {
        return -1;
    }
    else if (str1[i] > str2[i])
    {
        return 1;
    }
    return 0;
}

int main()
{
    cout << "ret: " << mod_strcmp("Geeks", "apple") << endl;
    cout << "ret: " << mod_strcmp("", "ABCD") << endl;
    cout << "ret: " << mod_strcmp("ABCD", "z") << endl;
    cout << "ret: " << mod_strcmp("ABCD", "abcdEghe") << endl;
    cout << "ret: " << mod_strcmp("GeeksForGeeks", "gEEksFORGeEKs") << endl;
    cout << "ret: " << mod_strcmp("GeeksForGeeks", "geeksForGeeks") << endl;
    return 0;
}