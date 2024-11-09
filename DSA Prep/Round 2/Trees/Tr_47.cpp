// Does path have given sum
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

void printVector(vector<int> v)
{
    cout << "Path is: ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

bool pathWithGivenSum(Node *p, int sum, vector<int> v)
{
    if (p == NULL)
        return 0;

    bool ans = 0;
    v.push_back(p->data);
    int subSum = sum - p->data;

    if (subSum == 0 && p->lchild == NULL && p->rchild == NULL){
        printVector(v);
        return 1;
    }

    if (p->lchild)
        ans = ans || pathWithGivenSum(p->lchild, subSum, v);
    if (p->rchild)
        ans = ans || pathWithGivenSum(p->rchild, subSum, v);

    return ans;
}

int main()
{
    create(root);
    cout << "Preorder: ";
    Preorder(root);
    cout << endl;
    vector<int> v;
    int sum = 7;
    if (pathWithGivenSum(root, sum, v))
        cout << "There is a root-to-leaf path with sum " << sum << endl;
    else
        cout << "There is no root-to-leaf path with sum " << sum << endl;

    return 0;
}