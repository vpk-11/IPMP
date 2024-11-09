// Check if List is Palindrome
#include <iostream>
#include <stack>
#include <climits>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void create(Node **head, int A[], int n)
{
    (*head) = new Node;

    Node *temp;
    Node *last;

    (*head)->data = A[0];
    (*head)->next = NULL;
    last = (*head);

    for (int i = 1; i < n; i++)
    {
        temp = new Node;
        temp->data = A[i];
        temp->next = NULL;
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

bool checkPalindrome(Node *head){
    stack <Node*> st;
    Node *p = head;
    Node *t = head;
    while (p)
    {
        st.push(p);
        p = p->next;
    }
    while (!st.empty() && t)
    {
        if (t->data != st.top()->data)
        {
            return false;
        }
        t = t->next;
        st.pop();
    }
    return true;
}

int main()
{
    int A[] = {3, 5, 7, 10, 15};
    int n = sizeof(A) / sizeof(A[0]);
    Node *head;
    create(&head, A, n);
    display(head);
    if (checkPalindrome(head))
    {
        cout << "List is Palindrome" << endl;
    }
    else
    {
        cout << "List isn't Palindrome" << endl;
    }

    return 0;
}