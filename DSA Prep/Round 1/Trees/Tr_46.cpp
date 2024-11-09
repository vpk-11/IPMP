// Print all root to leaf paths
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

void printVector(vector <int> v){
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void printPathToLeaves(Node *p, vector<int> v){
    if (p == NULL)
    {
        return;
    }
    v.push_back(p->data);
    if (p->lchild == NULL && p->rchild == NULL)
    {
        printVector(v);
    }
    else
    {
        printPathToLeaves(p->lchild, v);
        printPathToLeaves(p->rchild, v);
    }
}

int main()
{
    create(root);
    cout << "Preorder: ";
    Preorder(root);
    cout << endl;
    vector <int> v;
    printPathToLeaves(root, v);
    cout << endl;
    return 0;
}