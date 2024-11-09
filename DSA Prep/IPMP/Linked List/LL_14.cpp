// reverse List in grps of k size
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node *reverse(Node *head, int k)
{

    if (!head)
        return NULL;
    Node *current = head;
    Node *next = NULL;
    Node *prev = NULL;
    int count = 0;

    while (current != NULL && count < k)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    if (next != NULL)
        head->next = reverse(next, k);

    return prev;
}

void push(Node **head, int data)
{
    Node *newNode = new Node();

    newNode->data = data;

    newNode->next = *head;

    *head = newNode;
}

void display(Node *temp)
{
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *head = NULL;
    for (int i = 9; i > 0; i--)
    {
        push(&head,i);
    }
    
    cout << "Given linked list \n";
    display(head);
    head = reverse(head, 3);

    cout << "\nReversed Linked list \n";
    display(head);

    return 0;
}
