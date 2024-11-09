// Can Tree Be Folded
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>

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

void mirror(Node *p)
{
    if (p == NULL)
        return;
    else
    {
        Node *temp;

        mirror(p->lchild);
        mirror(p->rchild);

        temp = p->lchild;
        p->lchild = p->rchild;
        p->rchild = temp;
    }
}

bool isStructSame(Node *a, Node *b)
{
    if (a == NULL && b == NULL)
    {
        return true;
    }
    if (a != NULL && b != NULL && isStructSame(a->lchild, b->lchild) && isStructSame(a->rchild, b->rchild))
    {
        return true;
    }

    return false;
}

bool isFoldable(Node *p)
{
    if (p == NULL)
        return true;

    mirror(p->lchild);

    bool res = isStructSame(p->lchild, p->rchild);

    mirror(p->lchild);

    return res;
}

int main()
{
    create(root);
    cout << "Preorder: ";
    Preorder(root);
    cout << endl;
    if (isFoldable(root))
    {
        cout << "Suiiii" << endl;
    }
    else
    {
        cout << "Die Stargen" << endl;
    }
    return 0;
}