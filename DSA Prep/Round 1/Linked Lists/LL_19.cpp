// Sorted List of 0s, 1s, 2s
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

struct Node
{
    char data;
    Node *next;
};

void create(Node **head, string A, int n)
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

bool isVowel(char x)
{
    if ((x == 'a') || (x == 'e') || (x == 'i') || (x == 'o') || (x == 'u') ||
        (x == 'A') || (x == 'E') || (x == 'I') || (x == 'O') || (x == 'U'))
    {
        return true;
    }
    return false;
}

Node *segregateVowels(Node *head)
{
    Node *vow = NULL, *cons = NULL, *p = NULL;
    p = head;
    // First vow Node
    while (p)
    {
        if (isVowel(p->data))
        {
            vow = p;
            break;
        }
        p = p->next;
    }
    p = head;
    // First cons Node
    while (p)
    {
        if (!isVowel(p->data))
        {
            cons = p;
            break;
        }
        p = p->next;
    }
    // if no vow or no cons return;
    if (vow == NULL || cons == NULL)
    {
        return head;
    }
    Node *vHead = vow, *cHead = cons;
    p = head;
    while (p)
    {
        if (p == vow || p == cons)
        {
            p = p->next;
            continue;
        }
        if (isVowel(p->data))
        {
            vow->next = p;
            vow = p;
        }
        else
        {
            cons->next = p;
            cons = p;
        }
        p = p->next;
    }
    vow->next = NULL;
    cons->next = vHead;
    return cHead;
}

int main()
{
    string A = "abcdefghijkl";
    int n = A.length();
    Node *head;
    create(&head, A, n);
    display(head);
    head = segregateVowels(head);
    display(head);
    return 0;
}
