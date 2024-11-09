// Check if Binary Tree is BST
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

bool isBST(Node *p)
{
    if (p == NULL)
    {
        return true;
    }
    if (p->lchild !=NULL && p->lchild->data > p->data)
    {
        return false;
    }
    if (p->rchild !=NULL && p->rchild->data < p->data)
    {
        return false;
    }
    if (!isBST(p->lchild) || !isBST(p->rchild))
    {
        return false;
    }
    return true;
    
}
int main()
{
    create(root);
    cout << "Preorder: ";
    Preorder(root);
    cout << endl;
    if (isBST(root))
    {
        cout << "Given Tree is a BST" << endl;
    }
    else
    {
        cout << "Given Tree is not a BST" << endl;
    }
    return 0;
}