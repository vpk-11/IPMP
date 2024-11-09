// Children Sum Property
// /* C++ Program to convert an aribitary
// binary tree to a tree that hold
// children sum property */
#include <iostream>
#include <queue>
#include <stack>
#include <ctype.h>

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
bool isSumProp(Node *p)
{
    if (p == NULL || p->lchild == NULL && p->rchild == NULL)
    {
        return true;
    }
    else
    {
        int sum = 0;
        if (p->lchild != NULL)
        {
            sum += p->lchild->data;
        }
        if (p->rchild != NULL)
        {
            sum += p->rchild->data;
        }

        if ((p->data == sum) && isSumProp(p->lchild) && isSumProp(p->rchild))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

void increment(Node *p, int diff)
{
    if (p->lchild != NULL)
    {
        p->lchild->data += diff;
        increment(p->lchild, diff);
    }
    else if (p->rchild != NULL)
    {
        p->rchild->data += diff;
        increment(p->rchild, diff);
    }
}

void convertTree(Node *p)
{
    int left_data = 0, right_data = 0, diff;

    if (p == NULL || (p->lchild == NULL && p->rchild == NULL))
    {
        return;
    }
    else
    {
        convertTree(p->lchild);
        convertTree(p->rchild);

        if (p->lchild != NULL)
        {
            left_data = p->lchild->data;
        }

        if (p->rchild != NULL)
        {
            right_data = p->rchild->data;
        }
        diff = left_data + right_data - p->data;

        if (diff > 0)
        {
            p->data = p->data + diff;
        }
        if (diff < 0)
        {
            increment(p, -diff);
        }
    }
}

int main()
{
    create(root);
    cout << "Preorder: ";
    Preorder(root);
    cout << endl;
    convertTree(root);
    cout << "Preorder: ";
    Preorder(root);
    cout << endl;
    return 0;
}
