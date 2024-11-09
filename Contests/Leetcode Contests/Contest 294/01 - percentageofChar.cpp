// Given a string and a char find the percentage of the char in the string
#include<iostream>
using namespace std;

int percentageOfChar(string s, char letter){
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == letter)
        {
            count++;
        }
    }
    return (100 * count)/s.length();
}

int main(){

}