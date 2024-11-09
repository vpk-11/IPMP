// Boundary Traversal
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

void create(Node *root)
{
    queue<Node *> q;
    Node *p, *t;
    int x;
    cout << "Enter Root Value ";
    cin >> x;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.push(root);
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        printf("Enter Left Child of %d: ", p->data);
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.push(t);
        }
        printf("Enter Right Child of %d: ", p->data);
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.push(t);
        }
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
void printLeaves(Node *p)
{
    if (p == NULL)
    {
        return;
    }
    printLeaves(p->lchild);
    if (p->lchild == NULL && p->rchild == NULL)
    {
        cout << p->data << " ";
    }
    printLeaves(p->rchild);
}
void printBoundaryLeft(Node *p)
{
    if (p == NULL)
    {
        return;
    }
    if (p->lchild)
    {
        cout << p->data << " ";
        printBoundaryLeft(p->lchild);
    }
    else if (p->rchild)
    {
        cout << p->data << " ";
        printBoundaryLeft(p->rchild);
    }
}
void printBoundaryRight(Node *p)
{
    if (p == NULL)
    {
        return;
    }
    if (p->lchild)
    {
        printBoundaryRight(p->rchild);
        cout << p->data << " ";
    }
    else if (p->rchild)
    {
        printBoundaryRight(p->lchild);
        cout << p->data << " ";
    }
}
void printBoundary(Node *p)
{
    cout << p->data << " ";
    if (root->lchild || root->rchild)
    {
        printBoundaryLeft(p->lchild);
        printLeaves(p);
        printBoundaryRight(p->rchild);
    }
}

int main()
{
    create(root);
    cout << "Preorder: ";
    Preorder(root);
    cout << endl;
    printBoundary(root);
    return 0;
}