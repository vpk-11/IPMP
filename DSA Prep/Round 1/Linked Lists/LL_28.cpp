// Merge 2 Linked Lists at alternate positions
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

Node *mergeAlt(Node *p, Node *q)
{
    if (p == NULL)
    {
        return q;
    }
    if (q == NULL)
    {
        return p;
    }

    Node *head, *last;
    head = last = p;
    p = p->next;
    last->next = q;
    q = q->next;
    last = last->next;
    last->next = NULL;
    while (q && p)
    {
        last->next = p;
        p = p->next;
        last = last->next;
        last->next = q;
        q = q->next;
        last = last->next;
        last->next = NULL;
    }
    // if we want all nodes to be brought in
    // if (p)
    // {
    //     last->next = p;
    // }
    // if (q)
    // {
    //     last->next = q;
    // }

    return head;
}

int main()
{
    int A[] = {1, 2, 3};
    int n = sizeof(A) / sizeof(A[0]);
    Node *head1, *head2;
    create(&head1, A, n);
    display(head1);
    int B[] = {4, 5, 6, 7, 8};
    n = sizeof(B) / sizeof(B[0]);
    create(&head2, B, n);
    display(head1);
    Node *head = mergeAlt(head1, head2);
    display(head);
    return 0;
}
