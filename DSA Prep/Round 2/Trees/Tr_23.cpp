// kth Node value at Nth level
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>

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

void KthNodeAtNthDistance(Node *root, int k, int n)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }
    queue<Node *> q;
    Node *p;
    q.push(root);
    int level = 0;
    while (!q.empty())
    {
        int count = q.size();
        level++;
        for (int i = 0; i < count; i++)
        {
            p = q.front();
            q.pop();
            if (i == k - 1 && level == n)
            {
                cout << p->data << " ";
                return;
            }
            if (p->lchild)
            {
                q.push(p->lchild);
            }
            if (p->rchild)
            {
                q.push(p->rchild);
            }
        }
    }
}

int main()
{
    create(root);
    cout << "Preorder: ";
    Preorder(root);
    cout << endl;
    int k;
    cout << "K Distance is: ";
    cin >> k;
    int n;
    cout << "Nth Level is: ";
    cin >> n;
    KthNodeAtNthDistance(root, k, n);
    return 0;
}
