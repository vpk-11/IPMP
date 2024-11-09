// Sorted Linked List to Tree
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
struct LNode
{
    int data;
    LNode *next;
};
struct Node
{
    int data;
    Node *lchild;
    Node *rchild;
    Node(int data)
    {
        this->data = data;
        this->lchild = NULL;
        this->rchild = NULL;
    }
};

void create(LNode **head, int A[], int n)
{
    (*head) = new LNode;

    LNode *temp;
    LNode *last;

    (*head)->data = A[0];
    (*head)->next = NULL;
    last = (*head);

    for (int i = 1; i < n; i++)
    {
        temp = new LNode;
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void Preorder(Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

Node *solve(vector<int> &v, int s, int e)
{
    if (s > e)
        return NULL;
    int mid = ceil((float)(s + e) / 2);
    Node *root = new Node(v[mid]);
    root->lchild = solve(v, s, mid - 1);
    root->rchild = solve(v, mid + 1, e);
    return root;
}
Node *sortedListToBST(LNode *head)
{
    vector<int> v;
    LNode *temp = head;
    if (!head)
        return NULL;
    while (temp != NULL)
    {
        v.push_back(temp->data);
        temp = temp->next;
    }
    int n = v.size() - 1;
    Node *root = solve(v, 0, n);
    return root;
}

int main()
{
    LNode *head = new LNode;
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    create(&head, arr, n);
    cout << "Preorder: ";
    Node *root = sortedListToBST(head);
    Preorder(root);
    return 0;
}