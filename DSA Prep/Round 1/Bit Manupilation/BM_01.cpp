// Power of 2
#include <iostream>
using namespace std;

int isPowerOfTwo(int n)
{
    return n && !(n & n-1);
}

int main()
{
    int num;
    cin>>num;
    if(isPowerOfTwo(num)){
        cout<<num<<" is a power of 2"<<endl;
    } else{
        cout<<num<<" isn't a power of 2"<<endl;
    }
    
    return 0;
}