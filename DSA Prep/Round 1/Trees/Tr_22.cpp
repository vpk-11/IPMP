// Double of Binary Tree
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

Node *newNode(int data){
    Node *temp = new Node;
    temp->data = data;
    temp->lchild = temp->rchild = NULL;
    return temp;
}
void doubleTree(Node *p){
    if (p ==  NULL)
    {
        return;
    }
    doubleTree(p->lchild);
    doubleTree(p->rchild);

    Node *temp = newNode(p->data);
    temp->lchild = p->lchild;
    p->lchild = temp;
    
}
int main()
{
    create(root);
    cout << "Preorder: ";
    Preorder(root);
    cout << endl;
    doubleTree(root);
    Preorder(root);
    return 0;
}