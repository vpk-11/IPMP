// Level Order Traversal
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

void LevelOrder(Node *p)
{
    queue<Node *> q;
    cout << p->data << " ";
    q.push(p);
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        if (p->lchild)
        {
            cout << p->lchild->data << " ";
            q.push(p->lchild);
        }
        if (p->rchild)
        {
            cout << p->rchild->data << " ";
            q.push(p->rchild);
        }
    }
}

void Rec_Preorder(Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        Rec_Preorder(p->lchild);
        Rec_Preorder(p->rchild);
    }
}
void printLevel(Node *p, int level){
    if (level == 1)
    {
        cout<<p->data<<" ";
    } else{
        printLevel(p->lchild, level-1);
        printLevel(p->rchild, level-1);
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

void Rec_LevelOrder(Node *p){
    for (int i = 0; i < height(root); i++)
    {
        printLevel(p, i);
    }
}

int main()
{
    create(root);
    cout << "Preorder: ";
    Rec_Preorder(root);
    cout << endl;
    LevelOrder(root);
    cout << endl;

    return 0;
}