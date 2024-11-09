// Check for Children sum property
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

bool isSumProperty(Node *p)
{
    if (p == NULL || p->lchild == NULL && p->rchild == NULL)
    {
        return true;
    }
    else
    {
        int sum = 0;
        if (p->lchild != NULL)
        {
            sum += p->lchild->data;
        }
        if (p->rchild != NULL)
        {
            sum += p->rchild->data;
        }

        if ((p->data == sum) && isSumProperty(p->lchild) && isSumProperty(p->rchild))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    create(root);
    cout << "Preorder: ";
    Preorder(root);
    cout << endl;
    if (isSumProperty(root))
    {
        cout << "Suiiii" << endl;
    }
    else
    {
        cout << "Die Stargen" << endl;
    }
    return 0;
}