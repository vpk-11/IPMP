// Length Encoding
#include <iostream>
#include <string>
using namespace std;

string lengthEncoder(string str)
{
    int i = 0;
    int n = str.length();
    string dest;
    while (i < n)
    {
        int count = 1;
        dest.push_back(str[i]);
        while (i < n - 1 && str[i] == str[i + 1]) {
            count++;
            i++;
        }
        dest += to_string(count);
        i++;
    }
    return dest;
}

int main()
{
    string str = "wwwwaaadexxxxxx";
    cout << "Encoded string is : " << lengthEncoder(str) << endl;
}