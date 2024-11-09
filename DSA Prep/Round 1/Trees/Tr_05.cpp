// Check if trees are same
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
Node *root1 = new Node;
Node *root2 = new Node;

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

bool sameTrees(Node *root1, Node *root2)
{
    if ((root1 == NULL && root2) || (root2 == NULL && root1))
    {
        return false;
    }
    if (root1->data != root2->data)
    {
        return false;
    }
    queue<Node *> q1, q2;
    Node *p1, *p2;
    q1.push(root1);
    q2.push(root2);
    while (!q1.empty() && !q2.empty())
    {
        p1 = q1.front();
        p2 = q2.front();
        q1.pop();
        q2.pop();
        if (p1->lchild && p2->lchild)
        {
            if (p1->lchild->data != p2->lchild->data)
            {
                return false;
            }
            else
            {
                q1.push(p1->lchild);
                q2.push(p2->lchild);
            }
        }
        else
        {
            if ((p1->lchild && p2->lchild == NULL) || (p1->lchild == NULL && p2->lchild))
            {
                return false;
            }
        }
        if (p1->rchild && p2->rchild)
        {
            if (p1->rchild->data != p2->rchild->data)
            {
                return false;
            }
            else
            {
                q1.push(p1->rchild);
                q2.push(p2->rchild);
            }
        }
        else
        {
            if ((p1->rchild && p2->rchild == NULL) || (p1->rchild == NULL && p2->rchild))
            {
                return false;
            }
        }
    }
    if ((q1.empty() && !q2.empty()) || (!q1.empty() && q2.empty()))
    {
        return false;
    }
    return true;
}

int main()
{
    create(root1);
    cout << "Preorder: ";
    Preorder(root1);
    cout << endl;
    create(root2);
    cout << "Preorder: ";
    Preorder(root2);
    cout << endl;
    if (sameTrees(root1, root2))
    {
        cout<< "Same Trees Bruv" << endl;
    }
    else
    {
        cout << "Nah bruh" << endl;
    }
    return 0;   
}
