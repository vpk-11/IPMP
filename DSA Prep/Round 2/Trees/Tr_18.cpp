// Count Leaves
#include <iostream>
#include <queue>

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

int size(Node *p)
{
    if (p)
        return size(p->lchild) + size(p->rchild) + 1;

    return 0;
}

int countLeaves(Node *p){
    if(p == NULL){
        return 0;
    }
    if(!p->lchild && !p->rchild){
        return 1;
    }
    return countLeaves(p->lchild) + countLeaves(p->rchild);
}

int main()
{
    create(root);
    cout<<"Preorder: ";
    Preorder(root);
    cout << endl;
    cout<<"Size of Tree: "<<size(root)<<endl;
    cout<<"No of Leaves in Tree: "<<countLeaves(root)<<endl;
}