// Check if Sum Tree or Not
#include <iostream>
#include <queue>

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

int sum(Node *p)
{
    if (p == NULL)
        return 0;

    return sum(p->lchild) + p->data +
           sum(p->rchild);
}

int isSumTree(struct Node *p)
{
    int ls, rs;
    if (p == NULL || (p->lchild == NULL && p->rchild == NULL))
    {
        return 1;
    }
    ls = sum(p->lchild);
    rs = sum(p->rchild);
    if ((p->data == ls + rs) && isSumTree(p->lchild) && isSumTree(p->rchild))
    {
        return 1;
    }
    return 0;
}

int main()
{
    create(root);
    cout << "Preorder: ";
    Preorder(root);
    cout << endl;
    if (isSumTree(root))
    {
        cout << "Suiiii" << endl;
    }
    else
    {
        cout << "Die Stargen" << endl;
    }
    return 0;
}