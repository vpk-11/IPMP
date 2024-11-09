// Middle of List
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *head;

void create(Node **head, int A[], int n)
{
    (*head) = new Node;

    Node *temp;
    Node *last;

    (*head)->data = A[0];
    (*head)->next = NULL;
    last = (*head);

    for (int i = 1; i < n; i++)
    {
        temp = new Node;
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void display(Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " -> " << flush;
        p = p->next;
    }
    cout << endl;
}

int count(Node *p)
{
    int count = 0;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}

Node *middleOfList(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
        return head;

    Node *p, *q;
    p = q = head;

    while (q != NULL && q->next != NULL)
    {
        q = q->next->next;
        p = p->next;
    }
    return p;
}

int main()
{
    int A[] = {3, 5, 7, 10, 15};
    int n = sizeof(A) / sizeof(A[0]);
    Node *head;
    create(&head, A, n);
    display(head);
    cout << middleOfList(head)->data << endl;
    return 0;
}