// Lexicographic ranking of string
#include <iostream>
#include <string>
using namespace std;

int fact(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    return n * fact(n - 1);
}
// Function to calculate values smaller than arr[low] to it's right
int findSmallerInRight(string str, int low, int high)
{
    int countRight = 0, i;
    for (i = low + 1; i <= high; ++i)
    {
        if (str[i] < str[low])
        {
            ++countRight;
        }
    }
    return countRight;
}

int findRank(string str)
{
    int len = str.length();
    int mul = fact(len); 
    int rank = 1;
    int countRight;

    for (int i = 0; i < len; ++i)
    {
        mul /= (len - i);
        countRight = findSmallerInRight(str, i, len - 1);
        rank += countRight * mul;
    }
    return rank;
}

int main()
{
    string str = "cba";
    cout << "Lexicographical rank of " << str << " is " << findRank(str) << endl;
    return 0;
}
