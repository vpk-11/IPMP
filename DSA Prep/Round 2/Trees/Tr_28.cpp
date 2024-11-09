// Least Common Ancestor in BST
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

Node *leastCommonAncestor(Node *p, int x, int y){
    if (p == NULL)
    {
        return NULL;
    }
    int a, b;
    if (x < y)
    {
        a = x;
        b = y;
    }else
    {
        a = y;
        b = x;
    }
    while (p)
    {
        if (p->data < b)
        {
            if (p->data >= a)
            {
                return p;
            }
            else
            {
                p = p->rchild;
            }
        }
        else if(p->data == b){
            return p;
        }
        else
        {
            p = p->lchild;
        }
    }
    return NULL;
}

int main()
{
    Insert(10);
    Insert(5);
    Insert(20);
    Insert(8);
    Insert(30);
    Insert(40);
    Inorder(root);
    cout << endl;
    return 0;
}