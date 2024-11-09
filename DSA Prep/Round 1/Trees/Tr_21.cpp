// Print Left View
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

void PreOrder(Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        PreOrder(p->lchild);
        PreOrder(p->rchild);
    }
}

void printLeftView(Node *root)
{
    // if (root == NULL)
    // {
    //     return;
    // }
    // cout << root->data << " ";
    // if (root->lchild)
    // {
    //     // cout << root->data << " ";
    //     printLeftView(root->lchild);
    // }
    // else if (root->rchild)
    // {
    //     // cout << root->data << " ";
    //     printLeftView(root->rchild);
    // }

    vector<int> v;

    if (root == NULL)
        return;

    queue<Node *> q;
    Node *curr = root;
    q.push(curr);

    while (!q.empty())
    {
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            curr = q.front();
            q.pop();
            if (i == 0)
            {
                v.push_back(curr->data);
            }
            if (curr->lchild != NULL)
                q.push(curr->lchild);
            if (curr->rchild != NULL)
                q.push(curr->rchild);
        }
    }
    for (auto i : v)
    {
        cout << i << " ";
    }
}

int main()
{
    create(root);
    cout << "Preorder: ";
    PreOrder(root);
    cout << endl;
    printLeftView(root);
    return 0;
}