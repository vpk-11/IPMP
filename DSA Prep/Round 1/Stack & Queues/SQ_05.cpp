// Stack with middle element Ops
#include <iostream>
using namespace std;

class Stack
{
    struct Node
    {
        int data;
        Node *next;
        Node *prev;

        Node(int data)
        {
            this->data = data;
        }
    };
    Node *head = NULL;
    Node *mid = NULL;
    int size = 0;

public:
    void push(int data)
    {
        Node *temp = new Node(data);
        if (size == 0)
        {
            head = temp;
            mid = temp;
            size++;
            return;
        }
        head->next = temp;
        temp->prev = head;
        head = head->next;
        if (size % 2 == 1)
        {
            mid = mid->next;
        }
        size++;
    }

    void pop()
    {
        if (size != 0)
        {
            if (size == 1)
            {
                head = NULL;
                mid = NULL;
            }
            else
            {
                head = head->prev;
                head->next = NULL;
                if (size % 2 == 0)
                {
                    mid = mid->prev;
                }
            }
            size--;
        }
    }

    int findMiddle()
    {
        if (size == 0)
        {
            return -1;
        }
        return mid->data;
    }

    void deleteMiddle()
    {
        if (size != 0)
        {
            if (size == 1)
            {
                head = NULL;
                mid = NULL;
            }
            else if (size == 2)
            {
                head = head->prev;
                mid = mid->prev;
                head->next = NULL;
            }
            else
            {
                mid->next->prev = mid->prev;
                mid->prev->next = mid->next;
                if (size % 2 == 0)
                {
                    mid = mid->prev;
                }
                else
                {
                    mid = mid->next;
                }
            }
            size--;
        }
    }
};

int main()
{
    Stack s;
    s.push(11);
    s.push(22);
    s.push(33);
    cout <<"Middle Element: " <<s.findMiddle() << endl;
    s.push(44);
    s.push(55);
    cout <<"Middle Element: " <<s.findMiddle() << endl;
    s.pop();
    s.pop();
    s.pop();
    cout <<"Middle Element: " <<s.findMiddle() << endl;
    s.deleteMiddle();
    cout <<"Middle Element: " << s.findMiddle() << endl;
    return 0;
}