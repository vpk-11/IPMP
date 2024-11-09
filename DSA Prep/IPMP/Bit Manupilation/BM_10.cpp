// Swap even and odd bits
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << "Result after operation: " << (n & (n - 1)) << endl;
    ;
}