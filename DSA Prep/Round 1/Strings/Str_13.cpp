// Anagram
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

bool isAnagram(string str1, string str2)
{
    if (str1.length() != str2.length())
    {
        return false;
    }
    vector<int> count1 = getCharCountArray(str1);
    vector<int> count2 = getCharCountArray(str2);
    for (int i = 0; i < NO_OF_CHARS; i++)
    {
        if (count1[i] != count2[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string str1 = "tweet";
    string str2 = "test";
    if (isAnagram(str1, str2))
    {
        cout<<"Yaas!!"<<endl;
    } else{
        cout<<"No...."<<endl;
    }
    
    return 0;
}