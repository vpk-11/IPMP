// Segregate Even and Odd Nodes
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
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
    last = head;
    for (int i = 1; i < n; i++)
    {
        Node *p = new Node;
        p->data = arr[i];
        p->next = NULL;
        last->next = p;
        last = p;
    }
}

void segregateEvenAndOdd()
{
    Node *tempHead = head, *tempLast = last;
    Node *curr = head, *prev = NULL;
    while (curr != NULL && curr->data % 2 != 0)
    { // Pushes all the odd numbers in the start before the first even to the end
        tempLast->next = curr;
        curr = curr->next;
        tempLast->next->next = NULL;
        tempLast = tempLast->next;
    }
    if (curr->data % 2 == 0)
    {
        head = curr;         // the first even node is the new head
        while (curr != last) // Pushes even numbers to the start of the list
        {
            if (curr->data % 2 == 0)
            {
                prev = curr;
                curr = curr->next;
            }
            else
            {
                prev->next = curr->next;
                curr->next = NULL;
                tempLast->next = curr;
                tempLast = curr;
                curr = prev->next;
            }
        }
    }
    else
        prev = curr;
    if (tempLast != last && last->data % 2 != 0)
    {
        prev->next = last->next;
        last->next = NULL;
        tempLast->next = last;
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
    segregateEvenAndOdd();
    display(head);
    cout << endl;
    return 0;
}