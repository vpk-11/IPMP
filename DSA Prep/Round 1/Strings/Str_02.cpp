// Permutations of a string
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void permute(string a, int l, int r) // Doesn't consider duplicate strings
{
    if (l == r)
        cout << a << endl;
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(a[l], a[i]);
            permute(a, l + 1, r);
            swap(a[l], a[i]);
        }
    }
}

int main()
{
    string s;

    cout << "Enter the string : ";
    cin >> s;
    int n = s.length();
    cout << "\nAll possible strings are : " << endl;
    permute(s, 0, n - 1);
    return 0;
}