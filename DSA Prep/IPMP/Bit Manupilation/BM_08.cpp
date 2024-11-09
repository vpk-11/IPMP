// sum without Arithmetic ops
#include <iostream>
using namespace std;

int sum(int a, int b)
{
    while (b != 0) // Half Adder logic
    {
        int carry = a & b;
        a = a ^ b;      // XOR operation
        b = carry << 1; // Carry (&) Operation
    }
    return a;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << sum(a, b) << endl;
    return 0;
}
