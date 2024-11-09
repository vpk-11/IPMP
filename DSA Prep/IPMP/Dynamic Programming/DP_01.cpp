#include <iostream>
using namespace std;

#define MAX 50
int fibo[MAX];

void init()
{
    for (int i = 0; i < MAX; i++)
    {
        fibo[i] = -1;
    }
}

int fib(int n)
{
    if (fibo[n] == -1)
    {
        if (n <= 1)
        {
            fibo[n] = n;
        }
        else
        {
            fibo[n] = fib(n - 1) + fib(n - 2);
        }
    }
    return fibo[n];
}

int main()
{
    int n;
    init();
    cin >> n;
    cout << fib(n) << endl;
}