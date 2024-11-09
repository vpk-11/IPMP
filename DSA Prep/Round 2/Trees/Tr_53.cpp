// Sorted Array to Balanced BST
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *lchild;
    Node *rchild;
    int height;
};

class AVL
{
public:
    Node *root;
    AVL() { root = NULL; }
    int NodeHeight(Node *p);
    int BalanceFactor(Node *p);
    Node *LLRotation(Node *p);
    Node *RRRotation(Node *p);
    Node *LRRotation(Node *p);
    Node *RLRotation(Node *p);
    Node *InPre(Node *p);
    Node *InSucc(Node *p);

    // Insert
    Node *rInsert(Node *p, int key);

    // Traversal
    void Inorder(Node *p);
    void Inorder() { Inorder(root); }
    Node *getRoot() { return root; }

    // Delete
    Node *Delete(Node *p, int key);
};

int AVL::NodeHeight(Node *p)
{
    int hl;
    int hr;

    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;

    return hl > hr ? hl + 1 : hr + 1;
}

int AVL::BalanceFactor(Node *p)
{
    int hl;
    int hr;

    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;

    return hl - hr;
}

Node *AVL::LLRotation(Node *p)
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if (root == p)
    {
        root = pl;
    }
    return pl;
}

Node *AVL::RRRotation(Node *p)
{
    Node *pr = p->rchild;
    Node *prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    if (root == p)
    {
        root = pr;
    }
    return pr;
}

Node *AVL::LRRotation(Node *p)
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    if (p == root)
    {
        root = plr;
    }
    return plr;
}

Node *AVL::RLRotation(Node *p)
{
    Node *pr = p->rchild;
    Node *prl = pr->lchild;

    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;

    prl->rchild = pr;
    prl->lchild = p;

    // Update height
    pr->height = NodeHeight(pr);
    p->height = NodeHeight(p);
    prl->height = NodeHeight(prl);

    // Update root
    if (root == p)
    {
        root = prl;
    }
    return prl;
}

Node *AVL::InPre(Node *p)
{
    while (p && p->rchild != NULL)
    {
        p = p->rchild;
    }
    return p;
}

Node *AVL::InSucc(Node *p)
{
    while (p && p->lchild != NULL)
    {
        p = p->lchild;
    }
    return p;
}

Node *AVL::rInsert(Node *p, int key)
{
    Node *t;
    if (p == NULL)
    {
        t = new Node;
        t->data = key;
        t->lchild = NULL;
        t->rchild = NULL;
        t->height = 1; // Starting height from 1 onwards instead of 0
        return t;
    }
    if (key < p->data)
    {
        p->lchild = rInsert(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = rInsert(p->rchild, key);
    }

    // Update height
    p->height = NodeHeight(p);
    // Balance Factor and Rotation
    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
    {
        return LLRotation(p);
    }
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
    {
        return LRRotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
    {
        return RRRotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
    {
        return RLRotation(p);
    }

    return p;
}

void AVL::Inorder(Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        cout << p->data << " " << flush;
        Inorder(p->rchild);
    }
}

// If we only need the preOrder

// void solve(vector<int> &nums, int start, int end, vector<int> &ans)
// {
//     if (start > end)
//     {
//         return;
//     }
//     int mid = (start + end) / 2;
//     ans.push_back(nums[mid]);
//     solve(nums, start, mid - 1, ans);
//     solve(nums, mid + 1, end, ans);
// }
// vector<int> sortedArrayToBST(vector<int> &nums)
// {
//     // Code here
//     vector<int> ans;
//     solve(nums, 0, nums.size() - 1, ans);
//     return ans;
// }

int main()
{
    AVL tree;

    int A[] = {10, 20, 30, 40, 50, 60, 70};
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
    {
        tree.root = tree.rInsert(tree.root, A[i]);
    }

    tree.Inorder();
    cout << endl;

    return 0;
}