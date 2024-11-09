#include <iostream>
#include <string.h>
#include <cstring>
#include <vector>
using namespace std;

int minMoves(int target, int maxDoubles)
{
    int x = target;
    int moves = 0;
    while (x >= 1)
    {
        if (maxDoubles > 0 && x % 2 == 0 && x / 2 >= 1)
        {
            x /= 2;
            moves++;
            x--;
            moves++;
            maxDoubles--;
        }
        else
        {
            x--;
            moves++;
        }
    }
    return moves - 1;
}

int main()
{
    int target, maxDoubles;
    cin >> target >> maxDoubles;
    cout << minMoves(target, maxDoubles) << endl;
}