// mergeSortedLists of 2 sorted lists
#include <iostream>
#include <climits>
#include <algorithm>
#include <stack>
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

    Node *temp;
    Node *last;
    last = (*head);

    for (int i = 1; i < n; i++)
    {
        temp = new Node(A[i]);
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

Node *mergeSortedLists(Node *p, Node *q)
{
    Node *r, *last;
    if (p->data < q->data)
    {
        r = last = p;
        p = p->next;
        last->next = NULL;
    }
    else
    {
        r = last = q;
        q = q->next;
        last->next = NULL;
    }
    while (p != NULL && q != NULL)
    {
        if (p->data < q->data)
        {
            last->next = p;
            p = p->next;
            last = last->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            q = q->next;
            last = last->next;
            last->next = NULL;
        }
    }
    if (p)
    {
        last->next = p;
    }
    else
    {
        last->next = q;
    }
    return r;
}

int main()
{
    int A[] = {3, 5, 7, 9, 11, 13, 15};
    int n = sizeof(A) / sizeof(A[0]);
    Node *head1;
    create(&head1, A, n);
    display(head1);
    int B[] = {2, 4, 6, 8, 10, 12, 14};
    n = sizeof(B) / sizeof(B[0]);
    Node *head2;
    create(&head2, B, n);
    display(head2);
    display(mergeSortedLists(head1, head2));
    return 0;
}