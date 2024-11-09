// Triplet of nodes that gives certain sum
#include <iostream>
#include <stack>
#include <climits>
#include <algorithm>
#include <vector>
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
        cout << p->data << " -> ";
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

vector<int> tripletSum(Node *a, Node *bHead, Node *cHead, int sum)
{
    vector<int> v;
    if (!a || !bHead || !cHead)
    {
        return v;
    }
    while (a)
    {
        Node *b = bHead;
        Node *c = cHead;
        while (b && c)
        {
            int ans = a->data + b->data + c->data;
            if (ans == sum)
            {
                v.push_back(a->data);
                v.push_back(b->data);
                v.push_back(c->data);
                return v;
            }
            if (ans < sum)
            {
                b = b->next;
            }
            else if (ans > sum)
            {
                c = c->next;
            }
        }
        a = a->next;
    }
    return v;
}

int main()
{
    Node *a, *b, *c;
    int sum = 25;
    int A[] = {10, 15, 5, 20};
    int n = sizeof(A) / sizeof(A[0]);
    create(&a, A, n);
    int B[] = {2, 4, 9, 10};
    n = sizeof(B) / sizeof(B[0]);
    create(&b, B, n);
    int C[] = {8, 4, 2, 1};
    n = sizeof(C) / sizeof(C[0]);
    create(&c, C, n);
    display(a);
    display(b);
    display(c);
    vector<int> v = tripletSum(a, b, c, sum);
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}