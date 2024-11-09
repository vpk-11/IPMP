// First Non Repeating Character
#include <iostream>
#include <vector>
#include <string>
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

int firstNonRepeating(string str)
{
    vector<int> count = getCharCountArray(str);
    int index = -1, i;
    for (int i = 0; i < str.length(); i++)
    {
        if (count[str[i]] == 1)
        {
            index = i;
            break;
        }
    }
    return index;
}

int main()
{
    string str = "hello from the other side!!!";
    int index = firstNonRepeating(str);
    if (index == -1)
    {
        if (str.length() == 0)
        {
            cout << "String is empty" << endl;
        }
        else
        {
            cout << "No such character found" << endl;
        }
    }
    else
    {
        cout << "First non-repeating character is " << str[index] << endl;
    }
    return 0;
}