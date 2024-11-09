// Recursive Reversed Display
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

void rev_Display(Node *p){
    if (p != NULL)
    {
        rev_Display(p->next);
        cout << p->data << " ";
    }
    return;
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

int main()
{
    int A[] = {3, 5, 7, 10, 15};
    int n = sizeof(A) / sizeof(A[0]);
    Node *head;
    create(&head, A, n);
    display(head);
    rev_Display(head);
    return 0;
}