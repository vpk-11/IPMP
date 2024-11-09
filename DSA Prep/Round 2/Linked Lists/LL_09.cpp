// Intersection point of 2 lists
#include <iostream>
#include <climits>
#include <algorithm>
#include <stack>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *head;

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

Node *intersectionPoint(Node *head1, Node *head2)
{
    Node *p = head1;
    stack<Node *> s1, s2;
    while (p)
    {
        s1.push(p);
        p = p->next;
    }
    p = head2;
    while (p)
    {
        s2.push(p);
        p = p->next;
    }
    while (s1.top() == s2.top())
    {
        p = s1.top();
        s1.pop();
        s2.pop();
    }
    return p;
}

int main()
{
    int A[] = {3, 5, 7, 10, 15};
    int n = sizeof(A) / sizeof(A[0]);
    Node *head1;
    create(&head1, A, n);
    display(head1);
    int arr[] = {2, 4};
    n = sizeof(arr) / sizeof(arr[0]);
    Node *head2;
    create(&head2, arr, n);
    head2->next->next = head1->next->next;
    display(head2);
    cout << "Intersection Point is " << intersectionPoint(head1, head2)->data << endl;
    return 0;
}