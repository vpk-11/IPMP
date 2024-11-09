// Detect & Remove Loop
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

void removeLoop(Node *lNode, Node **head)
{
    Node *p, *q;
    p = q = lNode;
    int k = 0;
    while (p->next !=q)
    {
        p = p->next;
        k++;
    }
    q = p = (*head);
    for (int i = 0; i < k; i++)
    {
        p = p->next;
    }
    while (p->next != q)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
}

bool isLooped(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return false;
    }
    Node *p, *q;
    p = q = head;
    do
    {
        p = p->next;
        q = q->next;
        q = (q != NULL) ? (q->next) : q;
    } while (p && q && p != q);
    if (p == q)
    {
        removeLoop(p, &head);
        return true;
    }
    return false;
}

int main()
{
    int A[] = {20, 40, 15, 10};
    int n = sizeof(A) / sizeof(A[0]);
    Node *head;
    create(&head, A, n);
    display(head);
    head->next->next->next->next = head;
    if (isLooped(head))
    {
        cout << "Yaas Queen" << endl;
    }
    else
    {
        cout << "Nope King" << endl;
    }
    return 0;
}