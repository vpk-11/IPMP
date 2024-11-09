// Min Value of BST
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *lchild;
    Node *rchild;
};
Node *root = NULL;

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
int MinValue(Node *p)
{
    if (p == NULL)
    {
        return -1;
    }
    while (p->lchild != NULL)
    {
        p = p->lchild;
    }
    return p->data;
    
}
int main()
{
    int arr[] = {4, 2, 7, 3, 6, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        Insert(arr[i]);
    }
    Inorder(root);
    cout<<endl;
    cout << "Min Value of BST is: " << MinValue(root) << endl;
}