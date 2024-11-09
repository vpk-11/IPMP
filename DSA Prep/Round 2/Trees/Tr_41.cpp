// Find Pair of Numbers in BST with given Sum
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

void inorder(Node *root, vector<int> &res)
{
    if (root == NULL)
        return;
    inorder(root->lchild, res);
    res.push_back(root->data);
    inorder(root->rchild, res);
}
pair <int, int> findPairWithGivenSum(Node *root, int sum)
{
    // add code here.
    vector<int> res;
    inorder(root, res);
    pair<int, int> p;
    int i = 0, j = res.size() - 1;
    while (i < j)
    {
        if (res[i] + res[j] == sum)
        {
            p.first = res[i];
            p.second = res[j];
            return p;
        }
        else if (res[i] + res[j] < sum)
        {
            i++;
        }
        else{
            j--;
        }
    }
    p.first = -1;
    p.second = -1;
    return p;
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
    int sum = 13;
    pair<int, int> p = findPairWithGivenSum(root, sum);
    cout << p.first << " " << p.second << endl;
    return 0;
}