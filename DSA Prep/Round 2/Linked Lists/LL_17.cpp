// Sorted List of 0s, 1s, 2s
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

void Sort0s1s2s(Node **head)
{
    if (*head == NULL)
        return;
    Node *p = (*head);
    int arr[3] = {0, 0, 0};
    while (p)
    {
        arr[p->data]++;
        p = p->next;
    }
    p = (*head);
    for (int i = 0; i < arr[0]; i++)
    {
        p->data = 0;
        p = p->next;
    }
    for (int i = 0; i < arr[1]; i++)
    {
        p->data = 1;
        p = p->next;
    }
    for (int i = 0; i < arr[2]; i++)
    {
        p->data = 2;
        p = p->next;
    }
}

int main()
{
    int A[] = {1, 1, 2, 0, 2, 0, 1};
    int n = sizeof(A) / sizeof(A[0]);
    Node *head;
    create(&head, A, n);
    display(head);
    Sort0s1s2s(&head);
    display(head);
    return 0;
}