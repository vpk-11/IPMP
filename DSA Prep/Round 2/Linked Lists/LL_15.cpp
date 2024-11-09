// kAltReverse alternate k nodes in Linked List
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

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

Node *kAltReverse(Node *head, int k)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *p = head, *q = NULL, *r = NULL;
    for(int i = 0; i < k && p; i++)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head->next = p;
    // FOR ALT PURPOSE
    // move k - 1 nodes in forward
    for (int i = 0; i < k - 1 && p; i++)
    {
        p = p->next;
    }
    if (p)
    {
        p->next = kAltReverse(p->next, k);
    }
    return q;
}

int main()
{
    int A[] = {3, 5, 7, 9, 11, 13, 15};
    int n = sizeof(A) / sizeof(A[0]);
    Node *head;
    create(&head, A, n);
    display(head);
    head = kAltReverse(head, 2);
    display(head);
    return 0;
}