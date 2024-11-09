// Inorder successor
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
    Node *next;
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

void Inorder(Node *p)
{
    stack<Node *> s;
    while (p != NULL || !s.empty())
    {
        if (p != NULL)
        {
            s.push(p);
            p = p->lchild;
        }
        else
        {
            p = s.top();
            s.pop();
            cout << p->data << " ";
            p = p->rchild;
        }
    }
}
void InorderSuccessor(Node *p){
     static Node *next = NULL;
 
    if (p)
    { 
        InorderSuccessor(p->rchild);
        
        p->next = next;
        next = p;

        InorderSuccessor(p->lchild);
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
    cout << endl;
    cout << "Inorder: ";
    Inorder(root);
    cout << endl;
    InorderSuccessor(root);
    Node *p = root;
    while(p->lchild){
        p = p->lchild;
    }
    while (p){
        printf("Next of %d is %d\n", p->data, (p->next ? p->next->data : -1));
        p = p->next;
    }
    return 0;
}