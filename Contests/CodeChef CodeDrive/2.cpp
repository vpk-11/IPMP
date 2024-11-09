#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int A, b[T], counted = 0, key = 0, tempCounted = 0, tempKey = 0;
        cin >> A;
        while (A != 1)
        {
            if (A % 2 == 0)
            {
                key = 2;
                counted++;
                A /= 2;
                continue;
            }
            else
            {
                for (int j = 3; A != 1; j += 2)
                {
                    if (A % j == 0)
                    {
                        if (key == 0)
                        {
                            while (A % j == 0)
                            {
                                key = j;
                                counted++;
                                A /= j;
                            }
                        }
                        else if (j != tempKey)
                        {
                            tempCounted = 0;
                            while (A % j == 0)
                            {
                                tempKey = j;
                                tempCounted += 1;
                                A /= j;
                            }
                            if (tempCounted > counted)
                            {
                                key = j;
                                counted = tempCounted;
                            }
                        }
                    }
                }
            }
            if (key == 0)
            {
                key = A;
                A = 1;
            }
        }
        //b[i] = key;
        cout << key << endl;
    }
/*
    for (int i = 0; i < T; i++)
        cout << b[i] << endl;
    return 0;
    */
}