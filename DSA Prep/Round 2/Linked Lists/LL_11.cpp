// Intersection of 2 lists
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

Node *Intersection(Node *head1, Node *head2)
{
    map<int, int> map;
    while (head1)
    {
        map[head1->data]++;
        head1 = head1->next;
    }
    while (head2)
    {
        map[head2->data]++;
        head2 = head2->next;
    }
    Node *p = new Node(-1);
    Node *x = p;
    for (auto it : map)
    {
        if (it.second > 1)
        {
            Node *t = new Node(it.first);
            p->next = t;
            p = p->next;
        }
    }
    x = x->next;
    return x;
}

Node *Union(Node *head1, Node *head2)
{
    map<int, int> map;
    while (head1)
    {
        map[head1->data]++;
        head1 = head1->next;
    }
    while (head2)
    {
        map[head2->data]++;
        head2 = head2->next;
    }
    Node *p = new Node(-1);
    Node *x = p;
    for (auto it : map)
    {
        Node *t = new Node(it.first);
        p->next = t;
        p = p->next;
    }
    x = x->next;
    return x;
}

int main()
{
    int A[] = {3, 5, 7, 9, 11, 13, 15};
    int n = sizeof(A) / sizeof(A[0]);
    Node *head1;
    create(&head1, A, n);
    display(head1);
    int B[] = {6, 7, 8, 9, 10, 11, 12};
    n = sizeof(B) / sizeof(B[0]);
    Node *head2;
    create(&head2, B, n);
    display(head2);
    display(Union(head1, head2));
    display(Intersection(head1, head2));
    return 0;
}