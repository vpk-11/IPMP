// Reverse Alternate K nodes
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node *altReverse(Node *head, int k)
{
    Node *curr = head;
    Node *next;
    Node *prev = NULL;
    int count = 0;

    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (head != NULL)
        head->next = curr;

    for (int i = 0; i < k - 1; i++)
        if (curr != NULL)
            curr = curr->next;

    if (curr != NULL)
        curr->next = altReverse(curr->next, k);

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
        push(&head, i);
    

    cout << "Given linked list \n";
    display(head);
    head = altReverse(head, 3);

    cout << "\nReversed Linked list \n";
    display(head);

    return 0;
}
