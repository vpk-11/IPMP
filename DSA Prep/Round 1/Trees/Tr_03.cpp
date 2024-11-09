// Diameter of Tree
#include <iostream>
#include <algorithm>
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

void Rec_Preorder(Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        Rec_Preorder(p->lchild);
        Rec_Preorder(p->rchild);
    }
}

int count(Node *p)
{
    if (p)
        return count(p->lchild) + count(p->rchild) + 1;

    return 0;
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
int diameter(Node *p){
    if(p==NULL)
        return 0;
    
    int lheight = height(p->lchild);
    int rheight = height(p->rchild);

    int lDia = diameter(p->lchild); 
    int rDia = diameter(p->rchild); 

    return max(lheight + rheight + 1,
            max(lDia, rDia));
}
int main()
{
    create(root);
    cout << "Preorder: ";
    Rec_Preorder(root);
    cout << endl;
    cout << "No of Nodes: " << count(root) << endl;
    cout << "Height = " << height(root) << endl;
    cout << "Diameter = " << diameter(root) << endl;

    return 0;
}