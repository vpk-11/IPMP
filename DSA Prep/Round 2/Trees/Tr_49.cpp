// Print Ancestors of given node
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

bool printAncestors(Node *p, int target)
{
    if (p == NULL)
        return 0;
    if (p->data == target)
    {
        return true;
    }

    if (printAncestors(p->lchild, target) || printAncestors(p->rchild, target))
    {
        cout << p->data << " ";
        return true;
    }
    return false;
}

// void solve(Node *root, unordered_map<int, int> &parent)
// {
//     if (root == NULL)
//     {
//         return;
//     }

//     if (root->left)
//     {
//         parent[root->left->data] = root->data;
//         solve(root->left, parent);
//     }
//     if (root->right)
//     {
//         parent[root->right->data] = root->data;
//         solve(root->right, parent);
//     }
// }
// vector<int> Ancestors(struct Node *root, int target)
// {
//     unordered_map<int, int> parent;
//     parent[root->data] = -1;
//     solve(root, parent);

//     vector<int> ans;

//     while (parent[target] != -1)
//     {
//         ans.push_back(parent[target]);
//         target = parent[target];
//     }
//     return ans;
// }

int main()
{
    create(root);
    cout << "Preorder: ";
    Preorder(root);
    cout << endl;
    int target = 7;
    if (printAncestors(root, target))
        cout << "are the ancestor of " << target << endl;
    else
        cout << "No ancestors for " << target << endl;

    return 0;
}