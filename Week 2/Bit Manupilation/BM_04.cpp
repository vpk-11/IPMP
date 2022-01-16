// No of Bits to be flipped
#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int count = 0, ex = 1;
    int num = a ^ b;
    while (num)
    {
        count++;
        num = (num & (num - 1));
    }
    cout << count << "\n";
    return 0;
}

// the number of bits to be flipped will be the the number of set bits in the XOR op of a and b