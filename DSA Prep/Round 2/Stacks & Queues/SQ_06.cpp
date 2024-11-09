// Parenthesis matching
#include <iostream>
#include <stack>
#include <string>
#include <map>
using namespace std;

bool areBracketsBalanced(string str)
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
    string expr = "{()}[]";
 
    if (areBracketsBalanced(expr))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;
    return 0;
}