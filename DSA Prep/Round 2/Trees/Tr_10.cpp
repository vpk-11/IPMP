// Spiral Level Order Traversal
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

void LevelOrder(Node *p)
{
    queue<Node *> q;
    cout << p->data << " ";
    q.push(p);
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        if (p->lchild)
        {
            cout << p->lchild->data << " ";
            q.push(p->lchild);
        }
        if (p->rchild)
        {
            cout << p->rchild->data << " ";
            q.push(p->rchild);
        }
    }
}

void spiralLevelOrder(Node *p)
{
    stack<Node *> s1, s2;
    s1.push(p);

    while (!s1.empty() || !s2.empty())
    {
        while (!s1.empty())
        {
            p = s1.top();
            s1.pop();
            cout << p->data << " ";
            if (p->rchild)
            {
                s2.push(p->rchild);
            }

            if (p->lchild)
            {
                s2.push(p->lchild);
            }
        }
        while (!s2.empty())
        {
            p = s2.top();
            s2.pop();
            cout << p->data << " ";
            if (p->lchild)
            {
                s1.push(p->lchild);
            }
            if (p->rchild)
            {
                s1.push(p->rchild);
            }
        }
    }
}

void Rec_Preorder(Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        Rec_Preorder(p->lchild);
        Rec_Preorder(p->rchild);
    }
}

int main()
{
    create(root);
    cout << "Preorder: ";
    Rec_Preorder(root);
    cout << endl;
    cout << "Level Order: ";
    LevelOrder(root);
    cout << endl;
    cout << "Spiral Level Order: ";
    spiralLevelOrder(root);
    cout << endl;

    return 0;
}