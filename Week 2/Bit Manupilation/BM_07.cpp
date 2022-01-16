// Turning of rightmost set bit 
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << "Result after operation: " << (n & (n - 1)) << endl;
}