// Delete N nodes after M nodes of a LL
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
Node *head = new Node;

void deleteList(Node *source, int m, int n)
{
    Node *curr = source;
    Node *p;
    int count;
    while (curr)
    {
        for (count = 1; count < m && curr!= NULL; count++)
            curr = curr->next;
 
        if (curr == NULL)
            return;
 
        p = curr->next;
        for (count = 1; count<=n && p!= NULL; count++)
        {
            Node *temp = p;
            p = p->next;
            free(temp);
        }
        curr->next = p;
        curr = p;
    }
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
    int x,y;
    cin >> x >> y;
    deleteList(head, x, y);
    cout << endl;
    display(head);
    cout << endl;
    return 0;
}