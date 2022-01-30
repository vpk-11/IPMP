// Alternate Split of given LL
#include <iostream>
#include <cassert>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
Node *head = new Node;
Node *aHead = new Node;
Node *a = new Node;
Node *bHead = new Node;
Node *b = new Node;

void display(Node *p)
{
    if (p != NULL)
    {
        cout << p->data << " ";
        display(p->next);
    }
}
void create(int arr[], int n)
{
    head->data = arr[0];
    head->next = NULL;
    Node *temp = head;
    for (int i = 1; i < n; i++)
    {
        Node *p = new Node;
        p->data = arr[i];
        p->next = NULL;
        temp->next = p;
        temp = p;
    }
}

void AlternateSplit()
{
    if (head != NULL)
    {
        Node *curr = head->next;
        aHead = head;
        a = aHead;
        bHead = curr;
        b = bHead;
        curr = curr->next;
        while (curr != NULL)
        {
            a->next = curr;
            a = a->next;
            curr = curr->next;
            a->next = NULL;
            if (curr != NULL)
            {
                b->next = curr;
                b = b->next;
                curr = curr->next;
                b->next = NULL;
            }
        }
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    create(arr, n);
    cout << "List is: ";
    display(head);
    cout << endl;
    AlternateSplit();
    display(aHead);
    cout << endl;
    display(bHead);
    cout << endl;
    return 0;
}