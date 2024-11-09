// Alternarte Even and Odd Nodes
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

void rearrange(Node **head)
{
    Node *even;
    Node *temp, *prev_temp;
    Node *i, *j, *k, *l, *ptr;

    temp = (*head)->next;
    prev_temp = *head;

    while (temp != NULL)
    {
        Node *x = temp->next;

        if (temp->data % 2 != 0)
        {
            prev_temp->next = x;
            temp->next = (*head);
            (*head) = temp;
        }
        else
        {
            prev_temp = temp;
        }
        temp = x;
    }

    temp = (*head)->next;
    prev_temp = (*head);

    while (temp != NULL && temp->data % 2 != 0)
    {
        prev_temp = temp;
        temp = temp->next;
    }

    even = temp;
    prev_temp->next = NULL;

    i = *head;
    j = even;

    while (j != NULL && i != NULL)
    {

        k = i->next;
        l = j->next;

        i->next = j;
        j->next = k;

        ptr = j;

        i = k;
        j = l;
    }

    if (i == NULL)
    {
        ptr->next = j;
    }
}

int main()
{
    int A[] = {10, 2, 1, 5, 3, 6, 7, 8};
    int n = sizeof(A) / sizeof(A[0]);
    Node *head;
    create(&head, A, n);
    display(head);
    rearrange(&head);
    display(head);
    return 0;
}
