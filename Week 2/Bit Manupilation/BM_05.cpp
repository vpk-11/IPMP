// Rotate bits
#include <iostream>
using namespace std;
#define INT_BITS 32
int main()
{
    int n, d;
    cin >> n >> d;
    cout <<"Left rotate by "<< d << " bits is: "<<((n << d) | (n >> (INT_BITS - d))) << endl;
    cout <<"Right rotate by "<< d << " bits is: "<<((n >> d) | (n << (INT_BITS - d))) << endl;
}