// Convert Binary Tree to one that holds Children Sum property
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;
struct Node
{
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

void increment(Node *p, int diff)
{
    if (p->lchild != NULL)
    {
        p->lchild->data = p->lchild->data + diff;
        increment(p->lchild, diff);
    }
    else if (p->rchild != NULL)
    {
        p->rchild->data = p->rchild->data + diff;
        increment(p->rchild, diff);
    }
}

void convertToSumTree(Node *p)
{
    if (p == NULL || (p->lchild == NULL && p->rchild == NULL))
    {
        return;
    }
    int left_data = 0, right_data = 0, diff;
    convertToSumTree(p->lchild);
    convertToSumTree(p->rchild);

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

int main()
{
    create(root);
    cout << "Preorder: ";
    Preorder(root);
    cout << endl;
    cout << "After Conversion" << endl;
    convertToSumTree(root);
    cout << "Preorder: ";
    Preorder(root);
    cout << endl;
    return 0;
}