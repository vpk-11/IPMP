// Sum Tree
#include <iostream>
#include <queue>
#include <stack>

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

int sum(Node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    else
    {
        return p->data + sum(p->lchild) + sum(p->rchild);
    }
}
bool isSumTree(Node *p)
{
    if (p == NULL || (p->lchild == NULL && p->rchild == NULL))
    {
        return true;
    }
    int ls = sum(p->lchild);
    int rs = sum(p->rchild);

    if ((p->data = ls + rs) && isSumTree(p->lchild) && isSumTree(p->rchild))
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    create(root);
    cout << "Preorder: ";
    Preorder(root);
    cout << endl;
    if(isSumTree(root)){
        cout<<"Given Binary Tree is a Sum Tree"<<endl;
    }
    else{
        cout<<"Given Binary Tree is not a Sum Tree"<<endl;
    }

    return 0;
}