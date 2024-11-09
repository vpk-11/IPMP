// Bracket Balancing
#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

bool isBalanced(string str)
{
    stack<char> s;
    char k;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '{' || str[i] == '[' || str[i] == '(')
        {
            s.push(str[i]);
            continue;
        }
        if (s.empty())
        {
            return false;
        }
        if (str[i] == '}')
        {
            if (s.top() != '{')
            {
                return false;
            }
            else
            {
                s.pop();
            }
        }
        else if (str[i] == ']')
        {
            if (s.top() != '[')
            {
                return false;
            }
            else
            {
                s.pop();
            }
        }
        else
        {
            if (s.top() != '(')
            {
                return false;
            }
            else
            {
                s.pop();
            }
        }
    }
    if (s.empty())
    {
        return true;
    }
    return false;
}
int main()
{
    string str;
    cin >> str;
    if (isBalanced(str))
        cout << "Brackets are balanced"<<endl;
    else
        cout << "Brackets are not balanced"<<endl;
    return 0;
}