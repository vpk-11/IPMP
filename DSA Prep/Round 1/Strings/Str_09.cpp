// Atoi Function
#include <iostream>
#include <string>
using namespace std;

int ATOI(string str)
{
    int ans = 0;
    int sign = 1, i = 0;
    if (str[0] == '-')
    {
        sign = -1;
        i = 1;
    }

    while ( i < str.length() && str[i] >= '0' && str[i] <= '9')
    {
        if (str[i] == ' ')
        {
            continue;
        }
        ans *= 10;
        ans += str[i] - '0';
        i++;
    }
    return sign * ans;
}

int main()
{
    string str = "-12345";
    cout << "After Atoi it is : " << ATOI(str) << endl;
}