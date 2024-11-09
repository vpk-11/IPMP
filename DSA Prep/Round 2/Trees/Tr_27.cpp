// InOrder Successor
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *lchild;
    Node *rchild;
    Node *next;
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
// Populates inOrder Succ for every node
void populateNext(Node *p)
{
    static Node *next_p = NULL;

    if (p)
    {
        populateNext(p->rchild);

        p->next = next_p;
        next_p = p;

        populateNext(p->lchild);
    }
}

Node *MinValue(Node *p)
{
    if (p == NULL)
    {
        return NULL;
    }
    Node *curr = p;
    while (curr->lchild != NULL)
    {
        curr = curr->lchild;
    }
    return curr;
}
Node *inOrderSuccessor(Node *root, Node *x)
{
    if (root == NULL || x == NULL)
    {
        return NULL;
    }
    if (x->rchild != NULL)
    {
        return MinValue(x->rchild);
    }
    Node *succ = NULL;
    while (root != NULL)
    {
        if (x->data > root->data)
        {
            root = root->rchild;
        }
        else if (x->data < root->data)
        {
            succ = root;
            root = root->lchild;
        }
        else
        {
            break;
        }
    }
    return succ;
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
    // populateNext(root);
    // Inorder(root);
    // cout << endl;
    cout << "InOrder Successor of " << root->rchild->rchild->data << " is "
         << inOrderSuccessor(root, root->rchild->rchild)->data << endl;
    return 0;
}