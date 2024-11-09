// Reverse words of a string
// First Non Repeating Character
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define NO_OF_CHARS 256

void printWordsInReverse(string str)
{
    vector <string> words;
    string s = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            words.push_back(s);
            s = "";
        } else{
            s.push_back(str[i]);
        }
    }
    words.push_back(s);
    for (int i = words.size(); i >= 0; i--)
    {
        cout<<words[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    string str = "hello from the other side!!!";
    printWordsInReverse(str);
    return 0;
}