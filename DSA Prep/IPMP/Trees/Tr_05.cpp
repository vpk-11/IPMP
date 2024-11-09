// Identical Trees
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

class Node {
    public:
    int data;
    Node *lChild;
    Node *rChild;
};
Node *root1 = new Node();
Node *root2 = new Node();

void create(Node *root){
    Node *p = new Node();
    queue <Node *> q;
    int x;
    cout<<"Enter root value: ";
    cin>>x;
    if (x!=-1)
        root->data = x;
    
    root->lChild = root->rChild = NULL;
    q.push(root);
    while (!q.empty())
    {
        p = q.front(); q.pop();
        printf("Enter Left Child of %d: ",p->data);
        cin>>x;
        if (x!= -1)
        {
            Node *t = new Node;
            t->data = x;
            t->lChild = t->rChild = NULL;
            p->lChild = t;
            q.push(t);
        }
        printf("Enter Right Child of %d: ",p->data);
        cin>>x;
        if (x!= -1)
        {
            Node *t = new Node;
            t->data = x;
            t->lChild = t->rChild = NULL;
            p->rChild = t;
            q.push(t);
        }
    }
}
bool identityCheck(Node *p1, Node* p2){
    if (p1 == NULL || p2 == NULL)
        return false;
    
    queue <Node *> q1, q2;
    if (p1->data != p2->data)
        return false;
    
    q1.push(p1);
    q2.push(p2);
    while (!q1.empty() && !q2.empty())
    {
        p1 = q1.front(); q1.pop();
        p2 = q2.front(); q2.pop();
        if (p1->lChild && p2->lChild)
        {
            if (p1->lChild->data != p2->lChild->data)
                return false;
            q1.push(p1->lChild);
            q2.push(p2->lChild);
        } else
            return false;
        if (p1->rChild && p2->rChild)
        {
            if (p1->rChild->data != p2->rChild->data)
                return false;
            q1.push(p1->rChild);
            q2.push(p2->rChild);
        } else
            return false;
    }
    if (!q1.empty() || !q2.empty())
        if (q1.size() > q2.size() || q1.size() < q2.size())
            return false;
    
    return true;
}

void preOrder(Node *p){
    if (p)
    {
        cout<<p->data<<" ";
        preOrder(p->lChild);
        preOrder(p->rChild);
    }
}

int main(){
    create(root1);
    create(root2);
    preOrder(root1); cout<<endl;
    preOrder(root2); cout<<endl;
    if (identityCheck(root1, root2))
    {
        cout<<"Trees are Identical"<<endl;
    } else
        cout<<"Trees are not identical"<<endl;
    
}