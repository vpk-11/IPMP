// Rotate by k nodes
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
Node *head = new Node;

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
void rotateByKNodes(int k)
{
    if (k == 0)
        return;

    Node *curr = head;

    int count = 1;
    while (count < k && curr != NULL)
    {
        curr = curr->next;
        count++;
    }

    if (curr == NULL)
        return;

    Node *temp = curr;

    while (curr->next != NULL)
        curr = curr->next;

    curr->next = head;
    head = temp->next;
    temp->next = NULL;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    create(arr, n);
    cout << "List is: ";
    display(head);
    cout << endl;
    rotateByKNodes(4);
    display(head);
    cout << endl;
    return 0;
}