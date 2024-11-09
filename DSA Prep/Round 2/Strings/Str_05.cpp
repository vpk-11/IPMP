// Print Duplicates in String
#include<iostream>
#include <string>
#include <unordered_map>
using namespace std;

void printDuplicates(string s){
    unordered_map<char, int> hash;
    for(int i = 0; i < s.size(); i++){
        hash[s[i]]++;
    }
    for (auto it : hash)
    {
        if (it.second > 1)
        {
            cout << it.first << ", count = " << it.second << endl;
        }
    }
}

int main(){
    string str = "test string";
    printDuplicates(str);
    return 0;
}