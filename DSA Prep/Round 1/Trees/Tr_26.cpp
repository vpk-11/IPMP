// LCA in BST
// Inorder successor in BST
#include <iostream>
#include <queue>
#include <stack>

using namespace std;
class Node
{
public:
    int data;
    Node *lchild;
    Node *rchild;
};
Node *root = new Node;

void Insert(int key)
{
    Node *t = root;
    Node *p, *r;
    if (root == NULL)
    {
        p = new Node;
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    while (t != NULL)
    {
        r = t;
        if (key < t->data)
        {
            t = t->lchild;
        }
        else if (key > t->data)
        {
            t = t->rchild;
        }
        else
        {
            return;
        }
    }
    p = new Node;
    p->data = key;
    p->lchild = p->rchild = NULL;
    if (r->data > p->data)
    {
        r->lchild = p;
    }
    else
    {
        r->rchild = p;
    }
}

void Inorder(Node *p)
{
    if (p != NULL)
    {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
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
Node *MinValue(Node *p)
{
    Node *current = p;

    while (current->lchild != NULL)
    {
        current = current->lchild;
    }
    return current;
}
Node *LCA(Node *p, int n1, int n2)
{
    if (p == NULL)
    {
        return NULL;
    }
    if (p->data > n1 && p->data > n2)
    {
        return LCA(p->lchild, n1, n2);
    }
    if (p->data < n1 && p->data < n2)
    {
        return LCA(p->rchild, n1, n2);
    }
    return p;
}
int main()
{
    int arr[] = {50, 30, 70, 20, 60, 40, 80};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        Insert(arr[i]);
    }
    cout << "Inorder: ";
    Inorder(root);
    cout << endl;
    int n1, n2;
    cin >> n1 >> n2;
    Node *temp = LCA(root, n1, n2);
    cout << "The LCA of " << n1 << " & " << n2 << " is " << temp->data << endl;
    return 0;
}