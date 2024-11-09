#include <iostream>
using namespace std;

int main()
{
    int N, S, R, Sa, T;
    cin >> T;
    while (T > 0)
    {
        cin >> N >> S >> R >> Sa;
        if (N >= S)
        {
            S = S + R;
        }
        else
        {
            N = N + R;
        }
        if (N >= S)
        {
            S = S + Sa;
        }
        else
        {
            N = N + Sa;
        }
        if (N >= S)
        {
            cout << "N" << endl;
        }
        else
        {
            cout << "S" << endl;
        }
        T--;
    }
    return 0;
}