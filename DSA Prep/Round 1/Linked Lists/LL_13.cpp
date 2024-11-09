// Rotate by K nodes
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

void rotateByK(Node **head, int k)
{
    if ((*head) == NULL || (*head)->next == NULL)
    {
        return;
    }
    if (k > count(*head))
    {
        return;
    }
    Node *p = (*head);
    for (int i = 0; i < k - 1; i++)
    {
        p = p->next;
    }
    if (p->next)
    {
        Node *temp = p->next;
        p->next = NULL;
        Node *q = temp;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = (*head);
        (*head) = temp;
    }
}

int main()
{
    int A[] = {3, 5, 7, 9, 11, 13, 15};
    int n = sizeof(A) / sizeof(A[0]);
    Node *head;
    create(&head, A, n);
    rotateByK(&head, 4);
    display(head);
    return 0;
}