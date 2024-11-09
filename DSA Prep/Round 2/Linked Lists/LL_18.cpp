// Segregate Even and Odd Nodes
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

void segregateEvenOdd(Node **head)
{
    Node *end = *head;
    Node *prev = NULL;
    Node *curr = *head;

    while (end->next != NULL)
        end = end->next;

    Node *last = end;

    while (curr->data % 2 != 0 && curr != end)
    {
        last->next = curr;
        curr = curr->next;
        last->next->next = NULL;
        last = last->next;
    }

    if (curr->data % 2 == 0)
    {
        *head = curr;
        while (curr != end)
        {
            if ((curr->data) % 2 == 0)
            {
                prev = curr;
                curr = curr->next;
            }
            else
            {
                prev->next = curr->next;
                curr->next = NULL;

                last->next = curr;
                last = last->next;

                curr = prev->next;
            }
        }
    }
    else
    {
        prev = curr;
    }

    if (last != end && (end->data) % 2 != 0)
    {
        prev->next = end->next;
        end->next = NULL;
        last->next = end;
    }
    return;
}

Node *segregateEvenOdd_Space(Node *head)
{
    Node *even = NULL, *odd = NULL, *p = NULL;
    p = head;
    // First Even Node
    while (p)
    {
        if (p->data % 2 == 0)
        {
            even = p;
            break;
        }
        p = p->next;
    }
    p = head;
    // First Odd Node
    while (p)
    {
        if (p->data % 2 == 1)
        {
            odd = p;
            break;
        }
        p = p->next;
    }
    // if no even or no odd return;
    if (even == NULL || odd == NULL)
    {
        return head;
    }
    Node *eHead = even, *oHead = odd;
    p = head;
    while (p)
    {
        if (p == even || p == odd)
        {
            p = p->next;
            continue;
        }
        if (p->data % 2 == 0)
        {
            even->next = p;
            even = p;
        }
        else
        {
            odd->next = p;
            odd = p;
        }
        p = p->next;
    }
    even->next = oHead;
    odd->next = NULL;
    return eHead;
}

int main()
{
    int A[] = {1, 1, 2, 0, 2, 0, 1};
    int n = sizeof(A) / sizeof(A[0]);
    Node *head;
    create(&head, A, n);
    display(head);
    head = segregateEvenOdd_Space(head);
    display(head);
    return 0;
}
