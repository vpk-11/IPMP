// Problem Statement
// You are given a 0-indexed string array words, where words[i] consists of lowercase English letters.
// In one operation, select any index i such that 0 < i < words.length and words[i - 1] and words[i]
// are anagrams, and delete words[i] from words.
// Keep performing this operation as long as you can select an index that satisfies the conditions.
// Return words after performing all operations.
// It can be shown that selecting the indices for each operation in any arbitrary order will
// lead to the same result.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or
// phrase using all the original letters exactly once. For example, "dacb" is an anagram of "abdc".

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;
#define NO_OF_CHARS 256

vector<int> getCharCountArray(string str)
{
    vector<int> count(NO_OF_CHARS);
    for (int i = 0; i < str.length(); i++)
    {
        count[str[i]]++;
    }
    return count;
}

bool checkAnagram(string s1, string s2)
{
    vector<int> c1 = getCharCountArray(s1);
    vector<int> c2 = getCharCountArray(s2);
    for (int i = 0; i < NO_OF_CHARS; i++)
    {
        if (c1[i] != c2[i])
        {
            return false;
        }
    }
    return true;
}

vector<string> removeAnagrams(vector<string> &words)
{
    vector<string>::iterator it;
    bool flag = true;
    while (flag)
    {
        flag = false;
        for (int i = 0; i < words.size() - 1; i++)
        {
            if (checkAnagram(words[i], words[i + 1]))
            {
                it = words.begin() + i + 1;
                words.erase(it);
                flag = true;
            }
        }
        if (!flag)
        {
            break;
        }
    }
    return words;
}

// Better solution taking less time
vector<string> removeAnagramsEff(vector<string> &a)
{
    vector<string> b = a;
    for (int i = 0; i < a.size(); ++i)
    {
        sort(b[i].begin(), b[i].end());
    }
    vector<string> ret;
    for (int i = 0, j = 0; i < a.size(); i = j)
    {
        while (j < a.size() && b[i] == b[j])
        {
            ++j;
        }
        ret.push_back(a[i]);
    }
    return ret;
}

int main()
{
    int T;
    cin >> T;
    while (T < 0)
    {
        vector<string> words;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            string x;
            cin >> x;
            words.push_back(x);
        }
        words = removeAnagrams(words);
        for (auto it : words)
        {
            cout << it << " ";
        }
        cout << endl;
        T--;
    }
}