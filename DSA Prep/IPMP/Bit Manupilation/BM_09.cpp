// Position of rightmost bit
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int x = (n & ~(n - 1));
    int count = 0;
    while (x >= 1)
    {
        x >>= 1;
        count++;
    }
    cout << count << endl;
}