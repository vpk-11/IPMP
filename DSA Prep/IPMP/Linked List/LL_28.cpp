// Merge 2 LLs at alt positions
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void insert(Node *temp1, Node *temp2)
{
    Node *newNode = new Node();
    newNode->data = temp2->data;
    newNode->next = temp1->next;
    temp1->next = newNode;
}

void merge(Node **head1, Node **head2)
{
    Node *temp1 = *head1;
    Node *temp2 = *head2;
    while (temp1 != NULL && temp2 != NULL)
    {
        insert(temp1,temp2);
        temp2 = temp2->next;
        temp1 = temp1->next->next;
    }
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
    Node *head1 = NULL;
    Node *head2 = NULL;
    for (int i = 9; i > 0; i -= 3)
        push(&head1, i);

    for (int i = 15; i > 0; i -= 5)
        push(&head2, i);

    cout << "Given linked list \n";
    display(head1);
    cout << endl;
    display(head2);
    cout << endl;
    merge(&head1, &head2);
    cout << "Merged linked list \n";
    display(head1);
    cout << endl;

    return 0;
}
