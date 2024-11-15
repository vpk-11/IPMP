// Vertical Sum
#include <iostream>
#include <queue>
#include <stack>
#include <map>
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

void Rec_Preorder(Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        Rec_Preorder(p->lchild);
        Rec_Preorder(p->rchild);
    }
}

void verticalSumUtil(Node *node, int hd,
                     map<int, int> &Map)
{
    if (node == NULL)
        return;
    verticalSumUtil(node->lchild, hd - 1, Map);
    Map[hd] += node->data;
    verticalSumUtil(node->rchild, hd + 1, Map);
}

void verticalSum(Node *root)
{
    map<int, int> Map;
    map<int, int>::iterator it;
    verticalSumUtil(root, 0, Map);
    for (it = Map.begin(); it != Map.end(); ++it)
        cout << it->first << ": " << it->second << endl;
}

int main()
{
    create(root);
    cout << "Preorder: ";
    Rec_Preorder(root);
    cout << endl;
    verticalSum(root);

    return 0;
}