// Swap kth node from front and back
#include <iostream>
#include <climits>
#include <algorithm>
#include <map>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    };
};

void create(Node **head, int A[], int n)
{
    (*head) = new Node(A[0]);

    Node *temap;
    Node *last;
    last = (*head);

    for (int i = 1; i < n; i++)
    {
        temap = new Node(A[i]);
        last->next = temap;
        last = temap;
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

void kThSwap(Node **head, int k)
{
    int n = count(*head);

    if (n < k)
    {
        return;
    }

    if (2 * k - 1 == n)
    {
        return;
    }

    Node *x = *head;
    Node *x_prev = NULL;
    for (int i = 1; i < k; i++)
    {
        x_prev = x;
        x = x->next;
    }
    Node *y = *head;
    Node *y_prev = NULL;
    for (int i = 1; i < n - k + 1; i++)
    {
        y_prev = y;
        y = y->next;
    }

    if (x_prev)
    {
        x_prev->next = y;
    }
    if (y_prev)
    {
        y_prev->next = x;
    }

    Node *temp = x->next;
    x->next = y->next;
    y->next = temp;

    if (k == 1)
        *head = y;
    if (k == n)
        *head = x;
}

int main()
{
    int A[] = {3, 5, 7, 9, 11, 13, 15};
    int n = sizeof(A) / sizeof(A[0]);
    Node *head;
    create(&head, A, n);
    kThSwap(&head, 2);
    display(head);
    return 0;
}