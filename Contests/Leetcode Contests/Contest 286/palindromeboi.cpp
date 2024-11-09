#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int reverseNum(int n)
{
    int rem, rev = 0;
    while (n)
    {
        rem = n % 10;
        rev = rev * 10 + rem;
        n /= 10;
    }
    return rev;
}

bool isPalindrom(int num)
{
    return num == reverseNum(num);
}

int nthPalindrome(int n, int k)
{
    int num = (int)pow(10, k - 1);
    while (true)
    {
        if (isPalindrom(num))
        {
            n--;
        }
        if (!n)
        {
            break;
        }
        num++;
    }
    if(num){
        return num;
    } else{
        return -1;
    }
}

// int nthPalindrome(int n, int k)
// {
//     int temp = (k & 1) ? (k / 2) : (k / 2 - 1);
//     int palindrome = (int)pow(10, temp);
//     palindrome += n - 1;
//     int res = palindrome;
//     if (k & 1)
//     {
//         palindrome /= 10;
//     }

//     while (palindrome)
//     {
//         res = res*10 + palindrome%10;
//         palindrome /= 10;
//     }
//     if(res){
//         return res;
//     } else{
//         return -1;
//     }
// }

vector<long long> kthPalindrome(vector<int> &queries, int intLength)
{
    vector<long long> pali;
    for (auto it : queries)
    {
        pali.push_back(nthPalindrome(it, intLength));
    }
    return pali;
}

int main()
{
}