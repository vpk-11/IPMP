// Intersection of 2 sorted lists
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

Node *Intersection(Node *head1, Node *head2)
{
    Node *head = new Node(-1);
    Node *last = head;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data == head2->data)
        {
            last->next = head1;
            head1 = head1->next;
            head2 = head2->next;
            last = last->next;
            last->next = NULL;
        }
        else if (head1->data < head2->data)
        {
            head1 = head1->next;
        }
        else if (head1->data > head2->data)
        {
            head2 = head2->next;
        }
    }
    return head->next;
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
    display(Intersection(head1, head2));
    return 0;
}