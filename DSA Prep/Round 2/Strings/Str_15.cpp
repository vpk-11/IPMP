// Smallest Window of string containing another string
#include <iostream>
#include <string>
#include <climits>
using namespace std;

string findMWS(string txt, string pat)
{
    // If pat is bigger then no chance of pattern match
    if (txt.length() < pat.length())
    {
        return "";
    }
    int hash_pat[256];
    int hash_txt[256];
    for (int i = 0; i < 256; i++)
    {
        hash_pat[i] = 0;
        hash_txt[i] = 0;
    }

    for (int i = 0; i < pat.length(); i++)
        hash_pat[pat[i]]++;

    int start = 0, front = -1, min_len = INT_MAX;
    int count = 0; // Counter to keep track of window size

    for (int j = 0; j < txt.length(); j++)
    {
        // Hash the values of txt
        hash_txt[txt[j]]++;
        if (hash_txt[txt[j]] <= hash_pat[txt[j]])
        {
            count++;
        }
        // Window size is equal to size of pat
        // Utility part of program that gives us the start of the req window
        if (count == pat.length())
        {
            // if current char frequency is higher than req or if the char is not present in pat
            while (hash_txt[txt[start]] > hash_pat[txt[start]] || hash_pat[txt[start]] == 0)
            {
                if (hash_txt[txt[start]] > hash_pat[txt[start]])
                {
                    hash_txt[txt[start]]--;
                }
                start++;
            }
            // Getting smallest Window
            int len = j - start + 1;
            if (min_len > len)
            {
                min_len = len;
                front = start;
            }
        }
    }

    return (front == -1) ? "" : txt.substr(front, min_len);
}

int main()
{
    string txt = "this is a test string";
    string pat = "tist";

    string s = findMWS(txt, pat);
    if (s.length() > 0)
    {
        cout << "Smallest window is : " << s << endl;
    }
    else
        cout << "No such Window Exists" << endl;

    return 0;
}
