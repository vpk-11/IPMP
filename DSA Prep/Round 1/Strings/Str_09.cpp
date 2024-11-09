// Implement atoi function
#include <iostream>
using namespace std;

long long atoi(string str)
{
    int i;
    if (str[0] == '-')
        i = 1;
    else
        i = 0;

    while (i < str.length())
    {
        if (str[i] - '0' < 0 || str[i] - '0' > 9)
            return -1;
        i++;
    }

    if (str[0] == '-')
    {
        i = 1;
    }
    else
        i = 0;

    long long res = 0;

    while (i < str.length())
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }

    if (str[0] == '-')
        res = -res;
    return res;
}

int main()
{
    string str = "89789";
    long long val = atoi(str);
    cout << val << endl;
    return 0;
}