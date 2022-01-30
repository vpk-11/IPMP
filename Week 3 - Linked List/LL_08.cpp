// Middle of LL
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

void middleOfLL()
{
    Node *f_ptr, *s_ptr;
    f_ptr = head;
    s_ptr = head;
    while (f_ptr != NULL && s_ptr != NULL)
    {
        f_ptr = f_ptr->next->next;
        s_ptr = s_ptr->next;
    }
    cout<<"Middle of LL is: "<<s_ptr->data<<endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    create(arr, n);
    cout << "List is: ";
    display(head);
    cout << endl;
    middleOfLL();
    return 0;
}