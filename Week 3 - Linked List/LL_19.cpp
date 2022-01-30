// Move vowels to end of List
#include <iostream>
using namespace std;

class Node
{
public:
    char data;
    Node *next;
};
Node *head = new Node;
Node *last = new Node;

void display(Node *p)
{
    if (p != NULL)
    {
        cout << p->data << " ";
        display(p->next);
    }
}
void create(char arr[], int n)
{
    head->data = arr[0];
    head->next = NULL;
    last = head;
    for (int i = 1; i < n; i++)
    {
        Node *p = new Node;
        p->data = arr[i];
        p->next = NULL;
        last->next = p;
        last = p;
    }
}

bool isVowel(char ch)
{
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
        ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        return true;
    else
        return false;
}

void moveVowelsToEnd()
{
    Node *curr = head;
    while (curr != NULL)
    {
        if (isVowel(curr->data))
        {
            last->next = curr;
            curr = curr->next;
            last->next->next = NULL;
            last = last->next;
        }
        else
        {
            curr = curr->next;
        }
    }
}

int main()
{
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f', 'i', 'h', 'o'};
    int n = sizeof(arr) / sizeof(arr[0]);
    create(arr, n);
    cout << "List is: ";
    display(head);
    cout << endl;
    moveVowelsToEnd();
    display(head);
    cout << endl;
    return 0;
}
