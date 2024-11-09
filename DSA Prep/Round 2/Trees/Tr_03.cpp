// Diameter of a Tree
#include <iostream>
#include <queue>
#include <algorithm>

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

int size(Node *p)
{
    if (p)
        return size(p->lchild) + size(p->rchild) + 1;

    return 0;
}

int height(Node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    int x = height(p->lchild);
    int y = height(p->rchild);

    return max(x, y) + 1;
}

int diameter(Node *p)
{
    if (p == NULL){
        return 0;
    }

    int lheight = height(p->lchild);
    int rheight = height(p->rchild);

    int ldiameter = diameter(p->lchild);
    int rdiameter = diameter(p->rchild);

    return max(lheight + rheight + 1, max(ldiameter, rdiameter));
}

int main()
{
    create(root);
    cout << "Preorder: ";
    Preorder(root);
    cout << endl;
    cout << "Diameter of Tree: " << diameter(root) << endl;
}