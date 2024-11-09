// Delete List
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
Node *head = new Node;

void deleteList(Node *p)
{
    Node *curr, *next;
    curr = head;
    while (curr->next != NULL)
    {
        next = curr->next;
        free(curr);
        curr = next;
    }
    head = NULL;
}
void display(Node *p)
{
    if (p != NULL)
    {
        cout << p->data << " ";
        display(p->next);
    }
    else
    {
        cout << "NULL" << endl;
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

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    create(arr, n);
    cout << "List is: ";
    display(head);
    cout << endl;
    deleteList(head);
    cout << endl;
    display(head);
    cout << endl;
    return 0;
}