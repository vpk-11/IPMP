// Print Ancestors of given node
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <unordered_map>

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

vector<int> Ancestors(Node *root, int target)
{
    unordered_map<int, int> parent;
    parent[root->data] = -1;
    // solve(root, parent);
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();
        if (p->lchild)
        {
            parent[p->lchild->data] = p->data;
            q.push(p->lchild);
        }
        if (p->rchild)
        {
            parent[p->rchild->data] = p->data;
            q.push(p->rchild);
        }
    }
    vector<int> ans;
    while (parent[target] != -1)
    {
        ans.push_back(parent[target]);
        target = parent[target];
    }
    return ans;
}

int main()
{
    create(root);
    cout << "Preorder: ";
    Preorder(root);
    cout << endl;
    int target = 7;
    vector<int> v = Ancestors(root, target);
    cout << "Ancestors of " << target << " are: ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}