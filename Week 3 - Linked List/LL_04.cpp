// Check if Palindrome
#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
Node *head = new Node;
Node *head2 = new Node;

void display(Node *p)
{
    if (p != NULL)
    {
        cout << p->data << " ";
        display(p->next);
    }
}
void create(Node *head, int arr[], int n)
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

bool checkPalindrome(Node *head)
{
    Node *temp = head;
    stack<int> s;
    while (temp != NULL)
    {
        s.push(temp->data);
        temp = temp->next;
    }
    // while (s.size() > 0)
    // {
    //     cout<<s.top();
    //     s.pop();
    // }
    temp = head;
    while (temp != NULL)
    {
        if (temp->data != s.top())
        {
            return false;
        }
        s.pop();
        temp = temp->next;
    }
    return true;
}

int main()
{
    int arr[] = {1, 2, 3, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    create(head, arr, n);
    cout << "List is: ";
    display(head);
    cout << endl;
    if (checkPalindrome(head))
    {
        cout << "List is a Palindrome" << endl;
    }
    else
    {
        cout << "List is not a Palindrome" << endl;
    }
    return 0;
}