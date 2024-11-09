#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T > 0)
    {
        int N;
        cin >> N;
        char str[N]; cin >> str;
        char s1[] = "chef";
        char s2[] = "code";
        char *ptrCode, *ptrChef;
        ptrChef = strstr(str, s1);
        if (ptrChef)
        {
            ptrCode = strstr(str, s2);
            if (ptrCode)
            {
                if (ptrCode < ptrChef)
                {
                    cout << "AC" << endl;
                }
                else
                {
                    cout << "WA" << endl;
                }
            }
            else
            {
                cout << "WA" << endl;
            }
        }
        else
        {
            cout << "WA" << endl;
        }
        T--;
    }
    return 0;
}