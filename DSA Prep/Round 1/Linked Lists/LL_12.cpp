// Delete Alternate Nodes
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

void deleteAlternate(Node **head)
{
    if ((*head) == NULL || (*head)->next == NULL)
    {
        return;
    }
    Node *p = (*head);
    Node *q;
    while (p != NULL)
    {
        q = p->next;
        if (q == NULL)
            return;

        p->next = q->next;

        delete q;
        p = p->next;
    }
}

int main()
{
    int A[] = {3, 5, 7, 9, 11, 13, 15};
    int n = sizeof(A) / sizeof(A[0]);
    Node *head;
    create(&head, A, n);
    deleteAlternate(&head);
    display(head);
    return 0;
}