// Swap Kth Node from beggining to Kth Node from end;
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
void kkSwap(int k)
{
    int len = 0, i;
    Node *temp = head;

    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }

    if (len < k)
        return;

    if (2 * k - 1 == len)
        return;

    Node *kStart = head;
    Node *kStart_prev = NULL;
    for (int i = 1; i < k; i++)
    {
        kStart_prev = kStart;
        kStart = kStart->next;
    }
    Node *kEnd = head;
    Node *kEnd_prev = NULL;
    for (int i = 1; i < len - k + 1; i++)
    {
        kEnd_prev = kEnd;
        kEnd = kEnd->next;
    }
    if (kStart_prev)
        kStart_prev->next = kEnd;

    if (kEnd_prev)
        kEnd_prev->next = kStart;

    temp = kStart->next;
    kStart->next = kEnd->next;
    kEnd->next = temp;

    if (k == 1)
        head = kEnd;
    if (k == len)
        head = kStart;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    create(arr, n);
    cout << "List is: ";
    display(head);
    cout << endl;
    int k;
    cin >> k;
    kkSwap(k);
    display(head);
    cout << endl;
    return 0;
}