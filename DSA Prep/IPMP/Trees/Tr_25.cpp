// Inorder successor in BST
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

void Insert(int key)
{
    Node *t = root;
    Node *p, *r;
    if (root == NULL)
    {
        p = new Node;
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    while (t != NULL)
    {
        r = t;
        if (key < t->data)
        {
            t = t->lchild;
        }
        else if (key > t->data)
        {
            t = t->rchild;
        }
        else
        {
            return;
        }
    }
    p = new Node;
    p->data = key;
    p->lchild = p->rchild = NULL;
    if (r->data > p->data)
    {
        r->lchild = p;
    }
    else
    {
        r->rchild = p;
    }
}

void Inorder(Node *p)
{
    if (p != NULL)
    {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
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
Node *MinValue(Node *p)
{
    Node* current = p;
 
    while (current->lchild != NULL)
    {
        current = current->lchild;
    }
    return current;
}
Node *InorderSuccessor(Node *p, Node *temp)
{
    if(p == NULL || temp == NULL){
        return NULL;
    }
    if (temp->rchild != NULL)
        return MinValue(temp->rchild);

    Node *succ = NULL;

    while (p != NULL)
    {
        if (temp->data < p->data)
        {
            succ = p;
            p = p->lchild;
        }
        else if (temp->data > p->data)
        {
            p = p->rchild;
        }
        else
        {
            break;
        }
    }
    return succ;
}
int main()
{
    int arr[] = {50, 30, 70, 20, 60, 40, 80};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        Insert(arr[i]);
    }
    cout << "Inorder: ";
    Inorder(root);
    cout << endl;
    Node *temp = root->lchild->lchild;
    Node *succ = InorderSuccessor(root, temp);
    cout<<"Inorder Successor of "<<temp->data<<" is "<<succ->data;

    return 0;
}