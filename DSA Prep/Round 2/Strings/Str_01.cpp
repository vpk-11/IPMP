// Print Reverse of String using recursion
#include <iostream>
#include <string>
using namespace std;

void printReverse(string s, int i, int n){
    if(i >= n){
        return;
    }
    printReverse(s, i + 1, n);
    cout << s[i] << " ";
}

int main(){
    string s = "abcdefg";
    printReverse(s, 0, s.length());
    cout << endl;
    return 0;
}