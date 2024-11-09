// check if leaves are at same level or not
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>

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
    if (p)
    {
        cout << p->data << " ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

bool checkLeafLevels(Node *root)
{
    if (root == NULL)
    {
        return false;
    }
    queue<Node *> q;
    Node *p;
    q.push(root);
    int result = INT_MAX;
    int level = 0;
    while (!q.empty())
    {
        int count = q.size();
        level++;
        while (count > 0)
        {
            p = q.front();
            q.pop();
            if (p->lchild)
            {
                if (!p->lchild->lchild && !p->lchild->rchild)
                {
                    if (result == INT_MAX)
                    {
                        result = level;
                    }
                    else if (result != level)
                    {
                        return false;
                    }
                }
                q.push(p->lchild);
            }
            if (p->rchild)
            {
                if (!p->rchild->lchild && !p->rchild->rchild)
                {
                    if (result == INT_MAX)
                    {
                        result = level;
                    }

                    else if (result != level)
                    {
                        return false;
                    }
                }
                q.push(p->rchild);
            }
            count--;
        }
    }
    return true;
}

int main()
{
    create(root);
    cout << "Preorder: ";
    Preorder(root);
    cout << endl;
    if (checkLeafLevels(root))
    {
        cout << "Diee Stargen" << endl;
    }
    else
    {
        cout << "Suiii" << endl;
    }
    return 0;
}
