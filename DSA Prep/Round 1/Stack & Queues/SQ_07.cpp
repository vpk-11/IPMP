// Expression Evaluation
#include <iostream>
#include <stack>
#include <ctype.h>
#include <cstring>
using namespace std;

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

int applyOp(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    case '%':
        return a % b;
    default:
        return 0;
    }
}

int evalExp(string str)
{
    stack<int> tokens;
    stack<char> ops;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            continue;
        }
        else if (str[i] == '(')
        {
            ops.push(str[i]);
            continue;
        }
        else if (isdigit(str[i]))
        {
            int val = 0;
            while (i < str.length() && isdigit(str[i]))
            {
                val = (val * 10) + (str[i] - '0');
                i++;
            }
            tokens.push(val);
            i--;
        }
        else if (str[i] == ')')
        {
            while (!ops.empty() && ops.top() != '(')
            {
                int val2 = tokens.top();
                tokens.pop();

                int val1 = tokens.top();
                tokens.pop();

                char op = ops.top();
                ops.pop();

                tokens.push(applyOp(val1, val2, op));
            }
            if (!ops.empty())
            {
                ops.pop();
            }
        }
        else
        {
            while (!ops.empty() && precedence(ops.top()) >= precedence(str[i]))
            {
                int val2 = tokens.top();
                tokens.pop();

                int val1 = tokens.top();
                tokens.pop();

                char op = ops.top();
                ops.pop();

                tokens.push(applyOp(val1, val2, op));
            }
            ops.push(str[i]);
        }
    }
    while (!ops.empty())
    {
        int val2 = tokens.top();
        tokens.pop();

        int val1 = tokens.top();
        tokens.pop();

        char op = ops.top();
        ops.pop();

        tokens.push(applyOp(val1, val2, op));
    }
    return tokens.top();
}

int main()
{
    string str = "10 + 9 / (2 + 4)";
    cout << str <<" = "<< evalExp(str)<<endl;
}