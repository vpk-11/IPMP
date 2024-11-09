// Find Kth smallest number in BST
#include <iostream>
#include <vector>
using namespace std;

struct Node
{
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

Node *kthSmallest(Node *root, int &k)
{
    static int count = 0;
    if (root == NULL)
        return NULL;

    Node *left = kthSmallest(root->lchild, k);

    if (left != NULL)
        return left;

    count++;
    if (count == k)
        return root;

    return kthSmallest(root->rchild, k);
}

void inorder(Node *root, vector<int> &res)
{
    if (root == NULL)
        return;
    inorder(root->lchild, res);
    res.push_back(root->data);
    inorder(root->rchild, res);
}
int KthSmallestElement(Node *root, int K)
{
    // add code here.
    vector<int> res;
    inorder(root, res);
    if (K > res.size())
        return -1;
    return res[K - 1];
}

int main()
{
    Insert(10);
    Insert(5);
    Insert(20);
    Insert(8);
    Insert(30);
    Inorder(root);
    cout << endl;
    int k = 3;
    cout << kthSmallest(root, k)->data << endl;
    return 0;
}