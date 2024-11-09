// pow(x,n) in logn time
#include <iostream>
using namespace std;

int power(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n % 2 == 0)
    {
        return power(x, n / 2) * power(x, n / 2);
    }
    return x * power(x, n / 2) * power(x, n / 2);
}

int main()
{
    cout << power(4, 2) << endl;
}