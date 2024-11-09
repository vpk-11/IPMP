// Add nodes of greater value to Nodes in BST
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *lchild;
    Node *rchild;
};
Node *root = NULL;

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

void treeSum(Node *p, int* sum){
    if(p==NULL){
        return;
    }
    treeSum(p->rchild, sum);
    *sum+= p->data;
    p->data = *sum;
    treeSum(p->lchild, sum);
}
int main()
{
    int arr[] = {50, 30, 70, 20, 60, 40, 80};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        Insert(arr[i]);
    }
    Inorder(root);
    cout<<endl;
    int sum = 0;
    treeSum(root, &sum);
    Inorder(root);
    cout<<endl;
}