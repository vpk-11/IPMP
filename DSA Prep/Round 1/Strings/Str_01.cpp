// Print Reverse of String using recursion
#include <iostream>
using namespace std;
void printRevString(string str, int i){
    if (i > str.size())
    {
        return;
    }
    printRevString(str, i+1);
    cout<<str[i];
    
}
int main(){
    string str = "Hello World";
    printRevString(str, 0);
    cout<<endl;
}