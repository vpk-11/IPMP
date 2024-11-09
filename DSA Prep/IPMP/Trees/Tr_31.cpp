// Complete Binary Tree
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
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

int height(Node *p)
{
    int x = 0, y = 0;
    if (p == NULL)
        return 0;

    x = height(p->lchild);
    y = height(p->rchild);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}
bool isComplete(Node *p)
{
    queue<Node *> q;
    //cout << p->data << " ";
    q.push(p);
    bool flag = true;
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        if (p->lchild)
        {
            //cout << p->lchild->data << " ";
            if(flag == false){
                return false;
            }
            q.push(p->lchild);
        } else{
            flag = false;
        }
        if (p->rchild)
        {
            if(flag == false){
                return false;
            }
            //cout << p->rchild->data << " ";
            q.push(p->rchild);
        } else{
            flag = false;
        }
    }
    return true;
}

int main()
{
    create(root);
    cout << "Preorder: ";
    Preorder(root);
    cout << endl;
    cout << "Height = " << height(root) << endl;
    if (isComplete(root))
    {
        cout << "Tree is a Complete Binary Tree" << endl;
    }
    else
    {
        cout << "Tree is not a Complete Binary Tree" << endl;
    }

    return 0;
}