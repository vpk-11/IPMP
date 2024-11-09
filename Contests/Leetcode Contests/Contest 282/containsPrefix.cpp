#include <iostream>
#include <string>
using namespace std;

int prefixPos(string str, string prefix){
    // Find first occurrence of "geeks"
    size_t found = str.find(prefix);
    if (found != string::npos && found == 0){
        return 1;
    } else{
        return 0;
    }
}
int main(){
    if (prefixPos("geeks for geeks", "geeksa"))
    {
        cout<<"Prefix exists"<<endl;
    } else{
        cout<<"No"<<endl;
    }
    
}