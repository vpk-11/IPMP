// Add all greater values in BST to each node
#include <iostream>
using namespace std;

struct Node
{
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

void modifyBSTUtil(Node *root, int *sum)
{
    if (root == NULL)
        return;

    modifyBSTUtil(root->rchild, sum);

    *sum = *sum + root->data;
    root->data = *sum;

    modifyBSTUtil(root->lchild, sum);
}

Node *minValue()
{
    Node *t = root;
    while (t->lchild)
    {
        t = t->lchild;
    }
    return t;
}

int main()
{
    Insert(10);
    Insert(5);
    Insert(20);
    Insert(8);
    Insert(30);
    Inorder(root);
    cout << endl;
    int sum = 0;
    modifyBSTUtil(root, &sum);
    Inorder(root);
    cout << endl;
    return 0;
}
