// Merge nodes in between 0s
#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};
void create(int arr[], int n, ListNode **head)
{
    (*head)->val = arr[0];
    (*head)->next = NULL;
    ListNode *temp = *head;
    for (int i = 1; i < n; i++)
    {
        ListNode *p = new ListNode;
        p->val = arr[i];
        p->next = NULL;
        temp->next = p;
        temp = p;
    }
}
void display(ListNode *p)
{
    if (p != NULL)
    {
        cout << p->val << " ";
        display(p->next);
    }
}
ListNode *mergeNodes(ListNode *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    ListNode *p = new ListNode;
    while (head != NULL)
    {
        ListNode *temp = new ListNode;
        
    }
    return head;
}

int main()
{
    int arr[] = {0, 1, 0, 3, 0, 2, 2, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    ListNode *head = new ListNode;
    create(arr, n, &head);
    display(head);
    head = mergeNodes(head);
    display(head);
}
