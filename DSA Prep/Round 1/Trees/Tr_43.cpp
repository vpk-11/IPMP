// Print Keys in range
#include <iostream>
#include <vector>
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

void printKeysWithinRange(Node *p, int k1, int k2){
    if(p){
        printKeysWithinRange(p->lchild, k1, k2);
        if(p->data >= k1 && p->data <= k2){
            cout << p->data << " ";
        }
        printKeysWithinRange(p->rchild, k1, k2);
    }
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
    printKeysWithinRange(root, 3,20);
    cout << endl;
    return 0;
}