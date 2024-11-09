#include <iostream>
#include <stdlib.h>
using namespace std;

class twoStack
{
    int *arr;
    int size;
    int top1, top2;

public:
    twoStack(int n)
    {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = size;
    }

    void push1(int x)
    {
        if (top1 < top2 - 1)
        {
            top1++;
            arr[top1] = x;
        }
        else
        {
            cout << "Stack 1 Overflow";
        }
    }

    void push2(int x)
    {
        if (top1 < top2 - 1)
        {
            top2--;
            arr[top2] = x;
        }
        else
        {
            cout << "Stack 2 Overflow";
        }
    }

    void pop1()
    {
        if (top1 >= 0)
        {
            int x = arr[top1];
            top1--;
            cout << "Popped element from stack1 is " << x << endl;
        }
        else
        {
            cout << "Stack 1 UnderFlow";
        }
    }

    void pop2()
    {
        if (top2 < size)
        {
            int x = arr[top2];
            top2++;
            cout << "Popped element from stack1 is " << x << endl;
        }
        else
        {
            cout << "Stack 2 UnderFlow";
        }
    }
};

int main()
{
    twoStack s(5);
    s.push1(5);
    s.push2(10);
    s.push2(15);
    s.push1(11);
    s.push2(7);
    s.pop1();
    s.push2(40);
    s.pop2();
    return 0;
}
