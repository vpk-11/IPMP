#include <iostream>
#include <queue>
using namespace std;
class Stack
{
    queue<int> q1, q2;
    int size;

public:
    Stack()
    {
        size = 0;
    }
    void push(int data)
    {
        size++;
        q2.push(data);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }
    int pop()
    {
        if (q1.empty())
        {
            return -1;
        }
        size--;
        int temp = q1.front();
        q1.pop();
        return temp;
    }
    int stackSize()
    {
        return size;
    }
    int top()
    {
        if (q1.empty())
        {
            return -1;
        }
        return q1.front();
    }
};

int main()
{
    Stack s;
    s.push(20);
    s.push(5);
    s.push(10);
    s.push(15);
    cout << "Stack size is: " << s.stackSize() << endl;
    cout << "1st Popped element is: " << s.pop() << endl;
    cout << "2nd Popped element is: " << s.pop() << endl;
    cout << "Stack size is: " << s.stackSize() << endl;
    return 0;
}