// Isomorphic Trees
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
Node *root1 = new Node;
Node *root2 = new Node;

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

bool isIsomorphic(Node *n1, Node *n2)
{
    if (n1 == NULL && n2 == NULL)
        return true;

    if (n1 == NULL ^ n2 == NULL)
        return false;

    if (n1->data != n2->data)
        return false;

    return (isIsomorphic(n1->lchild, n2->lchild) && isIsomorphic(n1->rchild, n2->rchild)) ||
           (isIsomorphic(n1->lchild, n2->rchild) && isIsomorphic(n1->rchild, n2->lchild));
}

int main()
{
    create(root1);
    cout << "Preorder: ";
    Preorder(root1);
    cout << endl;
    create(root2);
    cout << "Preorder: ";
    Preorder(root2);
    cout << endl;
    if (isIsomorphic(root1, root2))
    {
        cout << "Suiiii" << endl;
    }
    else
    {
        cout << "Die Stargen" << endl;
    }
    return 0;
}