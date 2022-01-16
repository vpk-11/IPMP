// Position of only setBit
#include <iostream>
using namespace std;

int isPowerOfTwo(int n)
{
    return n && !(n & n - 1);
}

int main()
{
    int n;
    cin >> n;
    if (isPowerOfTwo(n))
    {
        int x = (n & ~(n - 1));
        int count = 0;
        while (x >= 1)
        {
            x >>= 1;
            count++;
        }
        cout << count << endl;
    } else{
        cout << "-1" << endl;
    }

    return 0;
}