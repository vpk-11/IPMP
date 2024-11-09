// Connect Levels of a Tree
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
class Node
{
public:
    int data;
    Node *lchild;
    Node *rchild;
    Node *nextRight;
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
    if (p)
    {
        cout << p->data << " ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

Node *getNextRight(Node *p)
{
    Node *temp = p->nextRight;
    while (temp != NULL)
    {
        if (temp->lchild != NULL)
        {
            return temp->lchild;
        }
        if (temp->rchild != NULL)
        {
            return temp->rchild;
        }
        temp = temp->nextRight;
    }

    return NULL;
}

void connectLevels(Node *p)
{
    if (p == NULL)
    {
        return;
    }
    p->nextRight = NULL;

    while (p != NULL)
    {
        Node *q = p;
        while (q != NULL)
        {
            if (q->lchild)
            {
                if (q->rchild)
                {
                    q->lchild->nextRight = q->rchild;
                }
                else
                {
                    q->lchild->nextRight = getNextRight(q);
                }
            }

            if (q->rchild)
            {
                q->rchild->nextRight = getNextRight(q);
            }
            q = q->nextRight;
        }

        if (p->lchild)
        {
            p = p->lchild;
        }
        else if (p->rchild)
        {
            p = p->rchild;
        }
        else
        {
            p = getNextRight(p);
        }
    }
}

int main()
{
    create(root);
    cout << "Preorder: ";
    Preorder(root);
    cout << endl;
    connectLevels(root);

    cout << "Following are populated nextRight pointers in the tree"
         << " (-1 is printed if there is no nextRight) \n";

    cout << "nextRight of " << root->data << " is "
         << (root->nextRight ? root->nextRight->data : -1) << endl;

    cout << "nextRight of " << root->lchild->data << " is "
         << (root->lchild->nextRight ? root->lchild->nextRight->data : -1) << endl;

    cout << "nextRight of " << root->rchild->data << " is "
         << (root->rchild->nextRight ? root->rchild->nextRight->data : -1) << endl;

    cout << "nextRight of " << root->lchild->lchild->data << " is "
         << (root->lchild->lchild->nextRight ? root->lchild->lchild->nextRight->data : -1) << endl;

    cout << "nextRight of " << root->rchild->rchild->data << " is "
         << (root->rchild->rchild->nextRight ? root->rchild->rchild->nextRight->data : -1) << endl;
    return 0;
}
