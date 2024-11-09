// Implement Queue usig stacks
#include <iostream>
#include <stack>
using namespace std;

class Queue
{
    stack<int> s1, s2;
    int curr_size;

public:
    Queue()
    {
        curr_size = 0;
    }

    void enqueue(int x)
    {
        curr_size++;
        s1.push(x);
    }

    void dequeue()
    {
        if (s2.empty())
        {
            if (s1.empty())
            {
                cout << "Queue Underflow" << endl;
                return;
            }
            else
            {
                while (!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
        }
        cout << "Dequeued " << s2.top() << endl;
        s2.pop();
        curr_size--;
    }

    int front()
    {
        if (s2.empty())
        {
            if (s1.empty())
            {
                return -1;
            }
            else
            {
                while (!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
        }
        return s2.top();
    }
    int size()
    {
        return curr_size;
    }
};

int main()
{
    Queue s;
    s.enqueue(1);
    s.enqueue(2);
    s.enqueue(4);
    cout << "current size: " << s.size() << endl;
    cout << s.front() << endl;
    s.dequeue();
    cout << s.front() << endl;
    s.dequeue();
    cout << s.front() << endl;
    cout << "current size: " << s.size() << endl;
    s.enqueue(5);
    s.enqueue(6);
    s.enqueue(7);
    cout << "current size: " << s.size() << endl;
    cout << s.front() << endl;
    s.dequeue();
    cout << s.front() << endl;
    s.dequeue();
    cout << s.front() << endl;
    cout << "current size: " << s.size() << endl;
    s.enqueue(8);
    s.enqueue(9);
    cout << "current size: " << s.size() << endl;
    cout << s.front() << endl;
    s.dequeue();
    cout << s.front() << endl;
    s.dequeue();
    cout << s.front() << endl;
    cout << "current size: " << s.size() << endl;
    return 0;
}
