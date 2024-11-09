// Detect & Remove Loop 
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    int visited;
};
Node *head = new Node;
Node *last = new Node;

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
    head->visited = 0;
    Node *last = head;
    for (int i = 1; i < n; i++)
    {
        Node *p = new Node;
        p->data = arr[i];
        p->next = NULL;
        p->visited = 0;
        last->next = p;
        last = p;
    }
}
void removeLoop(Node *p){
    p->next = NULL;
}
void detectLoop(Node *p)
{
    bool flag = false;
    while (p != NULL)
    {
        if (p->visited == 0)
        {
            p->visited = 1;
            p = p->next;
        }
        else
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        cout << "Loop Exists" << endl;
        removeLoop(p);
    }
    else
    {
        cout << "No Loop" << endl;
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
    detectLoop(head);
    cout << endl;
    last->next = head->next->next->next; display(head);
    detectLoop(head); display(head);
    return 0;
}