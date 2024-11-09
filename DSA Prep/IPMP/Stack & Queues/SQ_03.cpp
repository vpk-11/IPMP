// Queue using Stack
#include <iostream>
#include <stack>
using namespace std;
class Queue
{
    stack<int> s1, s2;
    int size;

public:
    Queue()
    {
        size = 0;
    }
    void enQueue(int data)
    {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(data);
        size++;
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    int deQueue()
    {
        if (s1.empty())
        {
            return -1;
        }
        size--;
        int temp = s1.top();
        s1.pop();
        return temp;
    }
    int QueueSize()
    {
        return size;
    }
    int front()
    {
        if (s1.empty())
        {
            return -1;
        }
        return s1.top();
    }
};

int main()
{
    Queue q;
    q.enQueue(20);
    q.enQueue(5);
    q.enQueue(10);
    q.enQueue(15);
    cout << "Queue size is: " << q.QueueSize() << endl;
    cout << "1st Popped element is: " << q.deQueue() << endl;
    cout << "2nd Popped element is: " << q.deQueue() << endl;
    cout << "Queue size is: " << q.QueueSize() << endl;
    return 0;
}