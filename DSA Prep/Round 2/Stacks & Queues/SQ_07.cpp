// Cpp Program to evaluate infix expression
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int precedence(char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }
    else if (op == '*' || op == '/')
    {
        return 2;
    }
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
    }
} 

int evaluate(string tokens)
{
    stack<int> values;
    stack<char> ops;

    for (int i = 0; i < tokens.length(); i++)
    {
        if (tokens[i] == ' ')
        {
            continue;
        }
        else if (tokens[i] == '(')
        {
            ops.push(tokens[i]);
        }
        else if (isdigit(tokens[i])) // Get digits
        {
            int x = 0;

            while (i < tokens.length() && isdigit(tokens[i]))
            {
                x = (x * 10) + (tokens[i] - '0');
                i++;
            }

            values.push(x);
            i--;
        }
        else if (tokens[i] == ')')
        {
            while (!ops.empty() && ops.top() != '(')
            {
                int val2 = values.top();
                values.pop();

                int val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));
            }
            if (!ops.empty())
            {
                ops.pop();
            }
        }
        else
        {
            while (!ops.empty() && precedence(ops.top()) >= precedence(tokens[i]))
            {
                int val2 = values.top();
                values.pop();

                int val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));
            }
            ops.push(tokens[i]);
        }
    }
    while (!ops.empty())
    {
        int val2 = values.top();
        values.pop();

        int val1 = values.top();
        values.pop();

        char op = ops.top();
        ops.pop();

        values.push(applyOp(val1, val2, op));
    }
    return values.top();
}

int main()
{
    cout << evaluate("10 + 2 * 6") << endl;
    cout << evaluate("100 * 2 + 12") << endl;
    cout << evaluate("100 * ( 2 + 12 )") << endl;
    cout << evaluate("100 * ( 2 + 12 ) / 14") << endl;
    return 0;
}
