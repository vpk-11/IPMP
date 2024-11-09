// Populate inOrder successor
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

void Rec_Preorder(Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        Rec_Preorder(p->lchild);
        Rec_Preorder(p->rchild);
    }
}
void Rec_Inorder(Node *p)
{
    if (p)
    {
        Rec_Inorder(p->lchild);
        cout << p->data << " ";
        Rec_Inorder(p->rchild);
    }
}

void populateNext(Node* p)
{
    static Node* next_p = NULL;
 
    if (p) {
        populateNext(p->rchild);

        p->next = next_p;
        next_p = p;
 
        populateNext(p->lchild);
    }
}

void Rec_Postorder(Node *p)
{
    if (p)
    {
        Rec_Postorder(p->lchild);
        Rec_Postorder(p->rchild);
        cout << p->data << " ";
    }
}

int main()
{
    create(root);
    cout << "Preorder: ";
    Rec_Preorder(root);
    cout << endl;
    cout << "Inorder: ";
    Rec_Inorder(root);
    cout << endl;
    populateNext(root);
    Node *p = root;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    return 0;
}