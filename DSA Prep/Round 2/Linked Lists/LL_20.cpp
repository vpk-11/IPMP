// Alternate Split (Banana Split)
#include <iostream>
#include <stack>
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
        cout << p->data << " -> ";
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

void bananaSplit(Node **head, Node **a, Node **b)
{
    if (*head == NULL)
    {
        return;
    }
    Node *p = (*head);
    Node *aLast;
    Node *bLast;
    if (p)
    {
        (*a) = aLast = p;
        p = p->next;
        aLast->next = NULL;
    }
    if (p)
    {
        (*b) = bLast = p;
        p = p->next;
        bLast->next = NULL;
    }
    else
    {
        return;
    }
    int count = 0;
    while (p)
    {
        if (count % 2 == 0)
        {
            aLast->next = p;
            aLast = aLast->next;
            p = p->next;
            aLast->next = NULL;
        }
        else
        {
            bLast->next = p;
            bLast = bLast->next;
            p = p->next;
            bLast->next = NULL;
        }
        count++;
    }
}

int main()
{
    int A[] = {0, 1, 2, 3, 4, 5};
    int n = sizeof(A) / sizeof(A[0]);
    Node *head;
    create(&head, A, n);
    display(head);
    Node *a, *b;
    bananaSplit(&head, &a, &b);
    display(a);
    display(b);
    return 0;
}