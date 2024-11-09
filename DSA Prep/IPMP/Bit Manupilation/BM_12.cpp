// Nimble Swap
#include <iostream>
using namespace std;

int main(){
    int x;
    cin>>x;
    unsigned int y = ((x >> 4) & 0x0f) | ((x << 4) & 0xf0);
    cout<<y<<endl;
    return 0;
}