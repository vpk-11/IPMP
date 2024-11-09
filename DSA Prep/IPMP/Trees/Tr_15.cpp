// Delete a Tree
// Size of Tree
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

int count(Node *p)
{
    if (p)
        return count(p->lchild) + count(p->rchild) + 1;

    return 0;
}
// Tree should be deleted in Post Order Traversal style
void deleteTree(Node *p){
    if(p==NULL){
        return;
    }
    deleteTree(p->lchild);
    deleteTree(p->rchild);
    cout<<"Deleted Node "<<p->data<<endl;
    delete p;
}

int main()
{
    create(root);
    cout << "Preorder: ";
    Preorder(root);
    cout << endl;
    cout << "No of Nodes: " << count(root) << endl;
    deleteTree(root);
    root = NULL;
    return 0;
}