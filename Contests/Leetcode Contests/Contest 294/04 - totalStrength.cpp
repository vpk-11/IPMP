// As the ruler of a kingdom, you have an army of wizards at your command.

// You are given a 0-indexed integer array strength, 
// where strength[i] denotes the strength of the ith wizard. 
// For a contiguous group of wizards (i.e. the wizards' strengths form a subarray of strength), 
// the total strength is defined as the product of the following two values:

// The strength of the weakest wizard in the group.
// The total of all the individual strengths of the wizards in the group.
// Return the sum of the total strengths of all contiguous groups of wizards. Since the answer may be very large, return it modulo 109 + 7.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int totalStrength(vector<int> &a)
{
    int n = a.size();
    const long long MOD = 1000000007;

    vector<long long> b(n + 1);
    for (int i = 0; i < n; ++i)
    {
        b[i + 1] = (b[i] + a[i]) % MOD;
    }

    struct Seg
    {
        long long val;
        long long count;
        long long sum;
    };

    vector<Seg> s;
    s.push_back({0, 0});

    long long result = 0;
    long long s1 = 0;
    long long s2 = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        Seg cur;
        cur.val = a[i];
        cur.count = 1;
        cur.sum = b[i + 1];
        while (s.back().val >= cur.val)
        {
            const auto &ss = s.back();
            s1 = (s1 - ss.val * ss.sum) % MOD;
            s2 = (s2 - ss.val * ss.count) % MOD;
            cur.sum += ss.sum;
            cur.count += ss.count;
            cur.sum %= MOD;
            s.pop_back();
        }
        s1 = (s1 + cur.val * cur.sum) % MOD;
        s2 = (s2 + cur.val * cur.count) % MOD;
        s.push_back(cur);
        result = (result + s1) % MOD;
        result = (result - s2 * b[i]) % MOD;
    }
    result %= MOD;
    result += MOD;
    result %= MOD;
    return (int)result;
}