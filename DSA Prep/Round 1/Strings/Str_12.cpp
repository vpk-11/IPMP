// Remove the chars of 1 string from the other
#include <iostream>
#include <string>
#include <map>
using namespace std;

string removeChars(string s1, string s2){
    map<char, int> hash;
    for (int i = 0; i < s2.size(); i++)
    {
        hash[s2[i]]++;
    }
    string res;
    int index = 0;
    while (index < s1.size())
    {
        if(hash[s1[index]] < 1){
            res.push_back(s1[index]);
        }
        index++;
    }
    return res;
}

int main(){
    string str1 = "geeksforgeeks";
    string str2 = "mask";
 
    cout << removeChars(str1, str2) << endl;
}