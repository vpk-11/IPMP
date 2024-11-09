// Find Max Root to leaf path sum
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
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

void printVector(vector<int> v)
{
    cout << "Given path is: ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void pathToLeaves(Node *p, vector<int> v, vector<vector<int> >&s)
{
    if (p == NULL)
    {
        return;
    }
    v.push_back(p->data);
    if (p->lchild == NULL && p->rchild == NULL)
    {
        s.push_back(v);
    }
    else
    {
        pathToLeaves(p->lchild, v, s);
        pathToLeaves(p->rchild, v, s);
    }
}

void hasMaxSum(Node *root)
{
    vector<vector<int> > s;
    vector<int> v;
    pathToLeaves(root, v, s);
    int max = INT_MIN;
    int path = -1;
    for (int i = 0; i < s.size(); i++)
    {
        int sum = 0;
        for (int j = 0; j < s[i].size(); j++)
        {
            sum += s[i][j];
        }
        if (sum > max)
        {
            max = sum;
            path = i;
        }
    }
    printVector(s[path]);
    cout << "Max sum is: " << max << endl;
}

int main()
{
    create(root);
    cout << "Preorder: ";
    Preorder(root);
    cout << endl;
    hasMaxSum(root);
    return 0;
}