// Absolute value
#include <iostream>
using namespace std;
#define INT_BITS 32

unsigned int absValue(int n) // mask is n right shifted by INT_BITS - 1
{
    int mask = n >> (sizeof(int) * INT_BITS - 1);
    return ((n + mask) ^ mask);
}
// (n + mask) ^ mask is doing toggling operation and geting abs value

int main()
{
    int n = -6;
    cout << absValue(n) << endl;
    return 0;
}
