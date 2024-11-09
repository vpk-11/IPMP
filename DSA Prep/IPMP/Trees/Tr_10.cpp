// Level Order Traversal in Spiral Form
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

void printLevel(Node *p, int level, bool flag)
{
    if (p == NULL)
        return;
    if (level == 1)
        cout << p->data << " ";
         
    else if (level > 1)
    {
        if (flag)
        {
            printLevel(p->lchild,
                            level - 1, flag);
            printLevel(p->rchild,
                            level - 1, flag);
        }
        else
        {
            printLevel(p->rchild,
                            level - 1, flag);
            printLevel(p->lchild,
                            level - 1, flag);
        }
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

void Rec_LevelOrder(Node *p)
{
    int h = height(root);
    int i;
 
    bool flag = false;
    for(i = 1; i <= h; i++)
    {
        printLevel(p, i, flag);
        flag = !flag;
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

int main()
{
    create(root);
    cout << "Preorder: ";
    Preorder(root);
    cout << endl
         << "Level Order: ";
    Rec_LevelOrder(root);
    cout << endl;

    return 0;
}