// Add 2 Numbers represented by LL
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

void push(Node **head, int val)
{
    Node *temp = new Node;
    temp->data = val;
    if (*head == NULL)
    {
        (*head) = temp;
    }
    else
    {
        temp->next = (*head);
        (*head) = temp;
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

Node *sumOfLL(Node *a, Node *b)
{
    if (a == NULL)
    {
        return b;
    }
    if (b == NULL)
    {
        return a;
    }
    int l1 = count(a);
    int l2 = count(b);
    if (l1 > l2)
    {
        int d = l1 - l2;
        for (int i = 0; i < d; i++)
        {
            push(&b, 0);
        }
    }
    else if (l2 > l1)
    {
        int d = l2 - l1;
        for (int i = 0; i < d; i++)
        {
            push(&a, 0);
        }
    }
    stack<int> s1, s2, ans;
    Node *p = a, *q = b, *s;
    while (p && q)
    {
        s1.push(p->data);
        s2.push(q->data);
        p = p->next;
        q = q->next;
    }
    int sum = 0;
    int carry = 0;
    while (!s1.empty() && !s2.empty())
    {
        int x = s1.top();
        int y = s2.top();
        s1.pop();
        s2.pop();
        sum = (x + y + carry);
        carry = sum / 10;
        sum %= 10;
        ans.push(sum);
    }
    if (carry)
    {
        ans.push(carry);
    }
    Node *sLast;
    while (!ans.empty())
    {
        Node *temp = new Node;
        temp->data = ans.top();
        temp->next = NULL;
        if (s == NULL)
        {
            s = sLast = temp;
        }
        else
        {
            sLast->next = temp;
            sLast = sLast->next;
        }
        ans.pop();
    }
    return s;
}

int main()
{
    Node *a, *b, *sum;
    int A[] = {5, 6, 7};
    int n = sizeof(A) / sizeof(A[0]);
    create(&a, A, n);
    int B[] = {1,8};
    n = sizeof(B) / sizeof(B[0]);
    create(&b, B, n);
    display(a);
    display(b);
    sum = sumOfLL(a, b);
    display(sum);
    return 0;
}