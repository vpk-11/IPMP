// Reverse bits
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// void simpleMethod(int n) // O(n)
// {
//     int ans = 0;
//     int ex = 1;
//     for (int i = 0; i < 8; i++)
//     {
//         if (ex & n)
//             ans = (ans | (1 << (7 - i)));

//         ex = ex << 1;
//     }
//     cout << ans << endl;
// }

void method2(int n)
{
    unsigned int count = sizeof(n) * 8 - 1;
    unsigned int rev_num = n;

    n >>= 1;
    while (n)
    {
        rev_num <<= 1;
        rev_num |= n & 1;
        n >>= 1;
        count--;
    }
    rev_num <<= count;
    printf("%u\n",rev_num);
}

int main()
{
    int n;
    cin >> n;
    // simpleMethod(n);
    cout<<endl;
    method2(n);
    return 0;
}