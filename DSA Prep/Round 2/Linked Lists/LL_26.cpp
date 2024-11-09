// Delete M nodes after N nodes
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

void deleteMnodesAfterNnodes(Node **head, int M, int N)
{
    if (*head == NULL)
    {
        return;
    }
    Node *temp = *head;
    for (int i = 0; i < M - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return;
    }
    Node *prev = temp;
    temp = temp->next;

    int n = N;
    while (temp != NULL && n > 0)
    {
        prev->next = temp->next;
        delete temp;
        temp = prev->next;
        n--;
    }
    deleteMnodesAfterNnodes(&prev->next, M, N);
}

int main()
{
    int A[] = {3, 5, 7, 9, 11, 13, 15};
    int n = sizeof(A) / sizeof(A[0]);
    Node *head;
    create(&head, A, n);
    deleteMnodesAfterNnodes(&head, 2, 2);
    display(head);
    return 0;
}