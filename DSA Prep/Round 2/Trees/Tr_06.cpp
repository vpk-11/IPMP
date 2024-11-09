// Tree Traversals
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
    stack<Node *> s;
    while (p != NULL || !s.empty())
    {
        if (p != NULL)
        {
            cout << p->data << " ";
            s.push(p);
            p = p->lchild;
        }
        else
        {
            p = s.top();
            s.pop();
            p = p->rchild;
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

void PostOrder(Node *root)
{
    vector<int> ans;
    while (root != NULL)
    {
        if (root->rchild == NULL)
        {
            ans.push_back(root->data);
            root = root->lchild;
        }
        else
        {
            Node *prev = root->rchild;
            while (prev->lchild != NULL && prev->lchild != root)
            {
                prev = prev->lchild;
            }
            if (prev->lchild == NULL)
            {
                prev->lchild = root;
                ans.push_back(root->data);
                root = root->rchild;
            }
            else
            {
                prev->lchild = NULL;
                root = root->lchild;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto it : ans)
    {
        cout << it << " ";
    }
}

void LevelOrder(Node *p)
{
    queue<Node *> q;
    cout << p->data << " ";
    q.push(p);
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        if (p->lchild)
        {
            cout << p->lchild->data << " ";
            q.push(p->lchild);
        }
        if (p->rchild)
        {
            cout << p->rchild->data << " ";
            q.push(p->rchild);
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
    Preorder(root);
    cout << endl;
    Rec_Preorder(root);
    cout << endl;
    cout << "Inorder: ";
    Inorder(root);
    cout << endl;
    Rec_Inorder(root);
    cout << endl;
    cout << "Postorder: ";
    Rec_Postorder(root);
    cout << endl;
    cout << "Level Order: ";
    LevelOrder(root);
    cout << endl;

    return 0;
}